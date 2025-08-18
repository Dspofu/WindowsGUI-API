#include <windows.h>

// IDs para os controles
#define ID_EDIT_NAME 101
#define ID_EDIT_PASSWORD 102
#define ID_BUTTON_EXIT 103

LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
  switch (uMsg) {
  case WM_CREATE:
  {
    // Criar campo de texto para o nome
    CreateWindow(
        "EDIT", "",
        WS_CHILD | WS_VISIBLE | WS_BORDER | ES_LEFT,
        50, 50, 200, 25,
        hwnd, (HMENU)ID_EDIT_NAME, NULL, NULL);

    // Criar campo de texto para a senha
    CreateWindow(
        "EDIT", "",
        WS_CHILD | WS_VISIBLE | WS_BORDER | ES_LEFT | ES_PASSWORD,
        50, 90, 200, 25,
        hwnd, (HMENU)ID_EDIT_PASSWORD, NULL, NULL);

    // Criar botão de saída
    CreateWindow(
        "BUTTON", "Sair",
        WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
        100, 140, 100, 30,
        hwnd, (HMENU)ID_BUTTON_EXIT, NULL, NULL);
    break;
  }
  case WM_COMMAND: {
    if (LOWORD(wParam) == ID_BUTTON_EXIT) {
      PostQuitMessage(0);
    }
    break;
  }
  case WM_DESTROY: {
    PostQuitMessage(0);
    break;
  }
  default:
    return DefWindowProc(hwnd, uMsg, wParam, lParam);
  }
  return 0;
}

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {
  const char CLASS_NAME[] = "SampleWindowClass";

  WNDCLASS wc = {};

  wc.lpfnWndProc = WindowProc;
  wc.hInstance = hInstance;
  wc.lpszClassName = CLASS_NAME;

  RegisterClass(&wc);

  HWND hwnd = CreateWindowExW(
      0,                   // Optional window styles
      CLASS_NAME,          // Window class
      "Interface Gráfica", // Window text
      WS_OVERLAPPEDWINDOW, // Window style

      // Tamanho e posição da janela
      CW_USEDEFAULT, CW_USEDEFAULT, 300, 250,

      NULL,      // Parent window
      NULL,      // Menu
      hInstance, // Instance handle
      NULL       // Additional application data
  );

  if (hwnd == NULL) return 0;

  ShowWindow(hwnd, nCmdShow);

  // Loop de mensagens
  MSG msg = {};
  while (GetMessage(&msg, NULL, 0, 0)) {
    TranslateMessage(&msg);
    DispatchMessage(&msg);
  }
  return 0;
}