#include "window.h"

HWND WindowBuilder(int style, LPCWSTR CLASS_NAME, LPCWSTR title, int window_style, int x, int y, int width, int height, HWND parent, HMENU menu, HINSTANCE instance, LPVOID param) {
  return CreateWindowExW(
    style, // Optional window styles
    CLASS_NAME, // Window class
    title, // Window title
    window_style,  // Window style
    x, y, width, height,
    parent, // Parent window
    menu, // Menu
    instance, // Instance handle
    param // Additional application data
  );
}