// 0150 · Componentes e ciclos
// Exercício E896 · ★☆☆
//
// Um gerenciador de pacotes só instala um programa se não houver dependência
// circular. Complete a função visita(u), a DFS com três cores: ela devolve
// true se, a partir de u, achar uma seta que chega num vértice CINZA. A
// função tem_ciclo já pinta todo mundo de BRANCO e chama visita para cada
// vértice ainda branco. Repare que na versão 1 o pacote util é alcançado por
// três caminhos diferentes, e isso NÃO é ciclo.
//
//   Saída esperada:
//   Versão 1: pode instalar
//   Versão 2: dependência circular
//
// Dicas:
// 1. Primeira linha: cor[u] = CINZA. Última, antes de devolver false:
//    cor[u] = PRETO.
// 2. Para cada v com depende[u][v]: se cor[v] é CINZA, achou; se é BRANCO,
//    chame visita(v) e, se ela devolver true, devolva true também. Se é
//    PRETO, ignore.
// 3. Resposta esperada: a saída acima. Na versão 2, a DFS acha o ciclo
//    rede -> log -> util -> rede.
//
// Escreva sua resposta abaixo (complete visita):

#include <stdbool.h>
#include <stdio.h>

#define V 6
enum { BRANCO, CINZA, PRETO };

const char *pacotes[V] = {"app", "rede", "json", "log", "cripto", "util"};
int depende[V][V]; // depende[a][b] = 1: a precisa de b instalado antes
int cor[V];

bool visita(int u) {
    (void)u; // apague esta linha e escreva a DFS com três cores

    return false;
}

bool tem_ciclo(void) {
    for (int u = 0; u < V; u++) cor[u] = BRANCO;
    for (int u = 0; u < V; u++)
        if (cor[u] == BRANCO && visita(u)) return true;
    return false;
}

int main(void) {
    int versao1[][2] = {{0, 1}, {0, 2}, {1, 4}, {1, 3}, {2, 5}, {3, 5}, {4, 5}};
    for (int k = 0; k < 7; k++) depende[versao1[k][0]][versao1[k][1]] = 1;
    printf("Versão 1: %s\n", tem_ciclo() ? "dependência circular" : "pode instalar");

    depende[5][1] = 1; // a versão 2 fez o util depender da rede
    printf("Versão 2: %s\n", tem_ciclo() ? "dependência circular" : "pode instalar");
    return 0;
}
