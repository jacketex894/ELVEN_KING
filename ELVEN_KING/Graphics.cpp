#include "Data\System\Graphics.h"

Graphics::Graphics()
{
    this->factory = NULL;
    this->randerTarget = NULL;
}

Graphics::~Graphics()
{
    if(this->factory) this->factory->Release();
    if (this->randerTarget) this->randerTarget->Release();
}

bool Graphics::initialize(HWND hwnd)
{
    HRESULT res = D2D1CreateFactory(D2D1_FACTORY_TYPE_SINGLE_THREADED, &this->factory);
    if (res != S_OK) return false;

    res = factory->CreateHwndRenderTarget(
          D2D1::RenderTargetProperties(),
          D2D1::HwndRenderTargetProperties(hwnd, D2D1::SizeU(SCREEN_WIDTH, SCREEN_HEIGHT)),
          &this->randerTarget);
    
    if (res != S_OK) return false;

    return true;
}

void Graphics::update()
{
    ID2D1SolidColorBrush *brush = NULL;
    this->randerTarget->BeginDraw();
    this->randerTarget->CreateSolidColorBrush(D2D1::ColorF(0, 0, 0, 1), &brush);
    //this->randerTarget->DrawEllipse(D2D1::Ellipse(D2D1::Point2F(100, 100), 50, 50), brush, 3.0f);
    this->randerTarget->EndDraw();
    brush->Release();
}

void Graphics::clearScreen()
{
    this->randerTarget->Clear(D2D1::ColorF(1, 1, 1));
}