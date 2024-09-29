#include <stdio.h>

#include "dxgi1_6.h"
#include "DirectXMath.h"
#include "wrl/client.h"

using namespace Microsoft::WRL;

void bdx_open() {
    using namespace DirectX;

    printf("[LIB] Opening library\n");
    XMMATRIX res = XMMatrixIdentity();
    XMMATRIX transform = XMMatrixTranslation(1.f, 1.f, 1.f);
    res = XMMatrixMultiply(res, transform);

    ComPtr<IDXGIFactory7> factory;
    HRESULT hr = CreateDXGIFactory2(0, IID_PPV_ARGS(&factory));
    printf("[LIB] Create DXGI Factory result = %ld\n", hr);

}

void bdx_close() {
    printf("[LIB] Closing library\n");
}
