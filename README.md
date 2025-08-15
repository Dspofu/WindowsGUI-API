# C++ UI

> Praticas de UI com C++ usando [`<windows.h>`](https://learn.microsoft.com/en-us/windows/win32/apiindex/windows-api-list#user-interface) **/** [`WindowsAPI`](https://learn.microsoft.com/en-us/windows/win32/apiindex/api-index-portal)

- [**Microsoft Guide**](https://learn.microsoft.com/en-us/windows/win32/learnwin32/your-first-windows-program)
- [**Documentation PDF**](https://learn.microsoft.com/pdf?url=https%3A%2F%2Flearn.microsoft.com%2Fen-us%2Fwindows%2Fwin32%2Flearnwin32%2Ftoc.json)
- [**Win32 API**](https://learn.microsoft.com/en-us/windows/win32/apiindex/windows-api-list)
- [QT](https://www.qt.io/offline-installers)

#

<details>
<summary style="font-size: 16px">Example Code</summary>

```cpp
#ifndef UNICODE
#define UNICODE
#endif 

#include <windows.h>

LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

int WINAPI wWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PWSTR pCmdLine, int nCmdShow) {
  const wchar_t CLASS_NAME[]  = L"Sample Window Class";
  WNDCLASS wc = { };

  wc.lpfnWndProc = WindowProc;
  wc.hInstance = hInstance;
  wc.lpszClassName = CLASS_NAME;

  RegisterClass(&wc);

  HWND hwnd = CreateWindowEx(0, CLASS_NAME, L"Learn to Program Windows", WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, NULL, NULL, hInstance, NULL);

  if (hwnd == NULL) return 0;
  ShowWindow(hwnd, nCmdShow);
  MSG msg = { };
  while (GetMessage(&msg, NULL, 0, 0) > 0) {
    TranslateMessage(&msg);
    DispatchMessage(&msg);
  }

  return 0;
}

LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
  switch (uMsg) {
    case WM_DESTROY:
      PostQuitMessage(0);
      return 0;

    case WM_PAINT: {
      PAINTSTRUCT ps;
      HDC hdc = BeginPaint(hwnd, &ps);
      FillRect(hdc, &ps.rcPaint, (HBRUSH) (COLOR_WINDOW+1));
      EndPaint(hwnd, &ps);
    }
    return 0;
  }
  return DefWindowProc(hwnd, uMsg, wParam, lParam);
}
```

### Build

```batch
g++ -static main.cpp modules/builders/window.cpp -o main -lgdi32
```

</details>


### Repositorio para estudos
#### Objetivos Tela:
> Concluidos [0/6]<br>
[ ] - Janela que não possa ser redimensionada<br>
[ ] - Criar botões para configurações<br>
[ ] - Gerar nova janela para a aba configurações<br>
[ ] - Campos de login e senha<br>
[ ] - Validador de credencial, user: "best" senha: "0000"<br>
[ ] - Editar a janela/passar a pagina para a tela de conectado

# 

#### Botões:
> Concluidos [0/3]<br>
[ ] - "`Login`" deve executar condição para validar e exibir um Error(PopUp) ou Aprovar(Repintar Tela)<br>
[ ] - "`Configurações`" conter ações em botões para alterar "`tema`" e tornar "`redimensionavel`" a tela<br>
[ ] - "`LogOut`" encerramento da sessão e repintar para tela de login