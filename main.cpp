#include <windows.h>
#include "modules/builders/window.h"
#include "modules/builders/input.h"

// ID's para os controles
#define ID_EDIT_NAME 101
#define ID_EDIT_PASSWORD 102
#define ID_BUTTON_EXIT 103

LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
  switch (uMsg) {
    case WM_CREATE:
      // Criar campo de texto para o nome
      inputBuilder("EDIT", "", WS_CHILD | WS_VISIBLE | WS_BORDER | ES_LEFT, 50, 50, 200, 25, hwnd, (HMENU)ID_EDIT_NAME, NULL, NULL);
      // Criar campo de texto para a senha
      inputBuilder("EDIT", "", WS_CHILD | WS_VISIBLE | WS_BORDER | ES_LEFT | ES_PASSWORD, 50, 90, 200, 25, hwnd, (HMENU)ID_EDIT_PASSWORD, NULL, NULL);
      // Criar botão de saída
      inputBuilder("BUTTON", "Sair", WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON, 100, 140, 100, 30, hwnd, (HMENU)ID_BUTTON_EXIT, NULL, NULL);
      break;
    case WM_COMMAND:
      if (LOWORD(wParam) == ID_BUTTON_EXIT)
        PostQuitMessage(0);
      break;
    case WM_DESTROY:
      PostQuitMessage(0);
      break;
    default:
      return DefWindowProcW(hwnd, uMsg, wParam, lParam);
  }
  return 0;
}

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {
  const wchar_t CLASS_NAME[] = L"SampleWindowClass";
  WNDCLASSW wc = {};

  wc.lpfnWndProc = WindowProc;
  wc.hInstance = hInstance;
  wc.lpszClassName = CLASS_NAME;

  RegisterClassW(&wc);

  HWND window = WindowBuilder(0, CLASS_NAME, L"Interface Gráfica", WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, 300, 250, NULL, NULL, hInstance, NULL);

  if (window == NULL) return 0;
  ShowWindow(window, nCmdShow);

  // Loop de mensagens
  MSG msg = {};
  while (GetMessage(&msg, NULL, 0, 0)) {
    TranslateMessage(&msg);
    DispatchMessage(&msg);
  }

  return 0;
}