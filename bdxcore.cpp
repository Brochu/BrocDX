#include "brocdx.h"
#include "bdxwin.h"

#include <stdio.h>

#include "dxgi1_6.h"
#include "d3d12.h"
#include "DirectXMath.h"

#include "wrl/client.h"

using namespace Microsoft::WRL;

#define HRCHECK(hr)                                                       \
if (hr != S_OK) {                                                         \
    printf("[ERROR] HRESULT = 0x%lX at %s:%i\n", hr, __FILE__, __LINE__); \
}

#define HRASSERT(hr)                         \
if (hr != S_OK) {                            \
    printf("[ERROR] HRESULT = 0x%lX\n", hr); \
    assert(false);                           \
}

#define HRSUCCESS(hr) (hr == S_OK)

void show_adapter_info(ComPtr<IDXGIAdapter4> adapter) {
    DXGI_ADAPTER_DESC3 d3;
    if (HRSUCCESS(adapter->GetDesc3(&d3))) {
        printf("[BDX] Selected adapter info {\n");
        printf("\tId: %i;%i;%i;%i\n", d3.VendorId, d3.DeviceId, d3.SubSysId, d3.Revision);
        printf("\tName: %ls\n", d3.Description);
        printf("\tDedicated Video Memory: %lld\n", d3.DedicatedVideoMemory);
        printf("\tDedicated System Memory: %lld\n", d3.DedicatedSystemMemory);
        printf("\tShared System Memory: %lld\n", d3.SharedSystemMemory);
        printf("}\n\n");
    }

    //TODO: Query feature levels for DxR, Work Graphs
}

// private globals
ComPtr<ID3D12Device> device;
ComPtr<ID3D12CommandQueue> queue;
//TODO: Look into handling async compute / multiple command queue / multiple frames in flight

void bdx_start() {
    using namespace DirectX;

    printf("[BDX] Opening library\n");
    XMMATRIX res = XMMatrixIdentity();
    XMMATRIX transform = XMMatrixTranslation(1.f, 1.f, 1.f);
    res = XMMatrixMultiply(res, transform);

    printf("[BDX] Create Win32 window (hwnd = 0x%p)\n", hwnd);
    bdx_init_window();

    ComPtr<ID3D12Debug> debug;
    HRCHECK(D3D12GetDebugInterface(IID_PPV_ARGS(&debug)));
    //TODO: Only enable debug layers for debug builds
    if (debug.Get()) {
        debug->EnableDebugLayer();
    }

    ComPtr<IDXGIFactory7> factory;
    ComPtr<IDXGIAdapter4> adapter;
    HRASSERT(CreateDXGIFactory2(DXGI_CREATE_FACTORY_DEBUG, IID_PPV_ARGS(&factory)));
    HRCHECK(factory->EnumAdapterByGpuPreference(0, DXGI_GPU_PREFERENCE_HIGH_PERFORMANCE, IID_PPV_ARGS(&adapter)));

    show_adapter_info(adapter);
    HRASSERT(D3D12CreateDevice(adapter.Get(), D3D_FEATURE_LEVEL_12_1, IID_PPV_ARGS(&device)));

    factory.Reset();
    adapter.Reset();

    D3D12_COMMAND_QUEUE_DESC qdesc;
    memset(&qdesc, 0, sizeof(qdesc));
    qdesc.Flags = D3D12_COMMAND_QUEUE_FLAG_NONE;
    qdesc.Type = D3D12_COMMAND_LIST_TYPE_DIRECT;
    HRASSERT(device->CreateCommandQueue(&qdesc, IID_PPV_ARGS(&queue)));

    printf("[BDX] Got device(%p), queue(%p)\n", device.Get(), queue.Get());
    //TODO: Next steps, find how to handle window (raw windows / SDL2?)
}

void bdx_stop() {
    printf("[BDX] Closing library\n");
    queue.Reset();
    device.Reset();

    bdx_close_window();
}
