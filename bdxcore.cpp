#include <stdio.h>

#include "dxgi1_6.h"
#include "d3d12.h"
#include "DirectXMath.h"

#include "wrl/client.h"

using namespace Microsoft::WRL;

void bdx_open() {
    using namespace DirectX;

    printf("[BDX] Opening library\n");
    XMMATRIX res = XMMatrixIdentity();
    XMMATRIX transform = XMMatrixTranslation(1.f, 1.f, 1.f);
    res = XMMatrixMultiply(res, transform);

    HRESULT hr;
    ComPtr<IDXGIFactory7> factory;
    hr = CreateDXGIFactory2(DXGI_CREATE_FACTORY_DEBUG, IID_PPV_ARGS(&factory));
    printf("[BDX] Create DXGI Factory result = %ld\n", hr);

    ComPtr<IDXGIAdapter1> adapter;
    hr = factory->EnumAdapters1(0, &adapter);
    printf("[BDX] Getting first adapter = %ld\n", hr);

    DXGI_ADAPTER_DESC1 desc;
    hr = adapter->GetDesc1(&desc);
    printf("[BDX] Getting description = (%ld) %ls\n", hr, desc.Description);

    ComPtr<ID3D12Debug> debug;
    hr = D3D12GetDebugInterface(IID_PPV_ARGS(&debug));
    printf("[BDX] Getting debug interface = (%ld)\n", hr);
    if (debug.Get()) {
        printf("[BDX] Starting debug layers\n");
        debug->EnableDebugLayer();
    }
}

void bdx_close() {
    printf("[BDX] Closing library\n");
}
