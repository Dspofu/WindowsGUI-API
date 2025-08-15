#ifndef WINDOW_H
#define WINDOW_H
#include <windows.h>

HWND WindowBuilder(int style, LPCWSTR CLASS_NAME, LPCWSTR title, int window_style, int x, int y, int width, int height, HWND hWndParent, HMENU hMenu, HINSTANCE hInstance, LPVOID lpParam);

#endif