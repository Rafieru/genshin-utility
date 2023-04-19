#pragma once

namespace hooks {
  void initialize();
}

namespace hooks::present {
  inline ID3D11Device* device;
  inline ID3D11DeviceContext* context;
  inline ID3D11RenderTargetView* render_target;

  inline std::once_flag flag;
  inline bool initalize_render_target = true;

  using function_type = long(__stdcall*)(IDXGISwapChain*, unsigned int, unsigned int);
  inline function_type original;

  long __stdcall hook(IDXGISwapChain* swap_chain, unsigned int sync_interval, unsigned int flags);
}

namespace hooks::resize_buffers {
  using function_type = long(__stdcall*)(IDXGISwapChain*, unsigned int, unsigned int, unsigned int, DXGI_FORMAT, unsigned int);
  inline function_type original;

  long __stdcall hook(IDXGISwapChain* swap_chain, unsigned int buffer_count, unsigned int width, unsigned int height, DXGI_FORMAT format, unsigned int flags);
}

namespace hooks::wndproc {
  inline HWND window;

  using function_type = long long(__stdcall*)(HWND, unsigned int, unsigned long long, long long);
  inline function_type original;

  long long __stdcall hook(HWND window, unsigned int message, unsigned long long wparam, long long lparam);
}

namespace hooks::set_field_of_view {
  using function_type = void(*)(void*, float);
  inline function_type original;

  void hook(void* _this, float value);
}

namespace hooks::quit {
  using function_type = void(*)();
  inline function_type original;

  void hook();
}