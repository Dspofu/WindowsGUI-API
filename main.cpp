#include <windows.h>

LRESULT CALLBACK Actions(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
  switch (uMsg) {
    case WM_DESTROY:
      PostQuitMessage(0);
      return 0;
    case WM_PAINT: {
      PAINTSTRUCT ps;
      HDC hdc = BeginPaint(hwnd, &ps);
      // Aqui você pode adicionar código para desenhar na janela
      EndPaint(hwnd, &ps);
      return 0;
    }
    default:
      return DefWindowProc(hwnd, uMsg, wParam, lParam);
  }
}

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR pCmdLine, int nCmdShow) {
  const char title[] = "Create Window";

  WNDCLASSA wc = {};
  wc.lpfnWndProc = Actions;
  wc.hInstance = hInstance;
  wc.lpszClassName = title;

  RegisterClassA(&wc);

  HWND hwnd = CreateWindowExA(0, title, "Janela", WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, NULL, NULL, hInstance, NULL);

  if (hwnd == NULL) return 0;

  ShowWindow(hwnd, nCmdShow);

  HWND hwndButton = CreateWindowExA(
    0, "BUTTON", "Click Me",
    WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON,
    10, 10, 100, 30,
    hwnd, (HMENU)1, hInstance, NULL
  );

  MSG msg = {};
  while (GetMessage(&msg, NULL, 0, 0)) {
    TranslateMessage(&msg);
    DispatchMessage(&msg);
  }

  return 0;
}