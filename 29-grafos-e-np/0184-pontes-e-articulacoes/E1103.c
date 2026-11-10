// 0184 · Pontes e articulações
// Exercício E1103 · ★★★
//
// A rede de energia do E1102 tem oito subestações: Usina, Norte, Sul,
// Leste, Oeste, Porto, Vila e Serra (0 a 7). As linhas:
//
//   Usina-Norte, Usina-Sul, Norte-Sul, Norte-Leste, Norte-Oeste,
//   Leste-Oeste, Sul-Porto, Porto-Vila, Porto-Serra
//
// Escreva a DFS com tin e low (raiz na Usina, vizinhos em ordem de índice,
// ignorando só o pai) que mostra as linhas críticas (pontes). Cada ponte é
// mostrada ao voltar da recursão, no formato "Linha crítica: u - v".
// Linhas dentro de um triângulo têm caminho alternativo e não aparecem.
//
//   Saída esperada:
//   Linha crítica: Porto - Vila
//   Linha crítica: Porto - Serra
//   Linha crítica: Sul - Porto
//
// Escreva sua resposta abaixo:

#include <stdio.h>

#define V 8

const char *subestacoes[V] = {"Usina", "Norte", "Sul", "Leste", "Oeste", "Porto", "Vila", "Serra"};
int linha[V][V];
int tin[V], low[V], relogio = 0;

int main(void) {

    return 0;
}
