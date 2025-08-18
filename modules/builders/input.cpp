#include "input.h"

void inputBuilder(const char *type, const char *, int style, int x, int y, int width, int height, HWND parent, HMENU id, HINSTANCE instance, LPVOID param) {
  CreateWindowW(
    L"EDIT",
    L"",
    WS_CHILD | WS_VISIBLE | WS_BORDER | ES_LEFT,
    50, 50, 200, 25,
    parent,
    (HMENU)id,
    NULL,
    NULL
  );
}