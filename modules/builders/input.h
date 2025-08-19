/**
 * @file Input.h
 * @brief Declaração da função para criar elementos de entrada da API do Windows.
 */

#ifndef INPUT_H
#define INPUT_H
#include <windows.h>

/**
 * @brief Cria uma caixa de edição (EDIT control) padrão em uma posição fixa.
 * * @warning Esta função atualmente ignora todos os seus parâmetros. Ela sempre
 * criará um controle do tipo "EDIT" nas coordenadas (50, 50) com tamanho (200, 25)
 * dentro da janela pai fornecida.
 *
 * @param type (Ignorado) O tipo de controle.
 * @param text (Ignorado) O texto inicial do controle.
 * @param style (Ignorado) O estilo do controle.
 * @param x (Ignorado) A coordenada x.
 * @param y (Ignorado) A coordenada y.
 * @param width (Ignorado) A largura do controle.
 * @param height (Ignorado) A altura do controle.
 * @param parent O handle (HWND) para a janela pai que conterá o controle.
 * @param id O identificador do controle (HMENU).
 * @param instance (Ignorado) O handle de instância.
 * @param param (Ignorado) Parâmetros de criação.
 */
void inputBuilder(LPCWSTR className, LPCWSTR text, int style, int x, int y, int width, int height, HWND parent, HMENU id, HINSTANCE instance, LPVOID param);

#endif