#include "window.h"

HWND WindowBuilder(int style, LPCWSTR CLASS_NAME, LPCWSTR title, int window_style, int x, int y, int width, int height, HWND hWndParent, HMENU hMenu, HINSTANCE hInstance, LPVOID lpParam) {
  return CreateWindowExW(
    style,                    // Optional window styles
    CLASS_NAME,           // Window class
    title, // Window text
    window_style,  // Window style

    // Tamanho e posição da janela
    x, y, width, height,

    hWndParent,      // Parent window
    hMenu,      // Menu
    hInstance, // Instance handle
    lpParam       // Additional application data
  );
}