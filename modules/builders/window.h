/**
 * @file Window.h
 * @brief Declaração da função para construir e registrar uma janela do Windows.
 */

#ifndef WINDOW_H
#define WINDOW_H
#include <windows.h>

/**
 * @brief Cria e registra uma classe de janela e, em seguida, cria a janela.
 * @details Esta função encapsula os passos de registrar uma WNDCLASSW e chamar CreateWindowExW,
 * retornando o handle para a janela criada.
 *
 * @param style O estilo da classe da janela (ex: CS_OWNDC). Não confundir com o estilo da janela.
 * @param CLASS_NAME O nome da classe da janela a ser registrada.
 * @param title O texto que aparecerá na barra de título da janela.
 * @param window_style O estilo principal da janela (ex: WS_OVERLAPPEDWINDOW).
 * @param x A coordenada x inicial da janela.
 * @param y A coordenada y inicial da janela.
 * @param width A largura da janela em pixels.
 * @param height A altura da janela em pixels.
 * @param parent O handle para a janela pai ou proprietária. NULL se não houver.
 * @param menu O handle para um menu, ou NULL se nenhum menu de classe for usado.
 * @param instance O handle para a instância do módulo associado à janela.
 * @param param Um ponteiro para um valor a ser passado para a janela através da estrutura CREATESTRUCT.
 * @return Retorna o handle (HWND) para a nova janela se for bem-sucedido. Retorna NULL em caso de falha.
 * @note A função assume que o modo Unicode está sendo usado (LPCWSTR).
 */

HWND WindowBuilder(int style, LPCWSTR className, LPCWSTR title, int window_style, int x, int y, int width, int height, HWND parent, HMENU menu, HINSTANCE instance, LPVOID param);

#endif