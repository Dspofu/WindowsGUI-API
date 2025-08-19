#include "input.h"

void inputBuilder(LPCWSTR className, LPCWSTR text, int style, int x, int y, int width, int height, HWND parent, HMENU id, HINSTANCE instance, LPVOID param) {
  CreateWindowW(
    className,
    text,
    style,
    x, y, width, height,
    parent,
    (HMENU)id,
    instance,
    param
  );
}