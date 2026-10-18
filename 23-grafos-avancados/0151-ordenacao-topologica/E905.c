// 0151 · Ordenação topológica
// Exercício E905 · ★★★
//
// Ache o bug. Este programa monta, com a DFS, a ordem para configurar um
// servidor novo (seta a -> b: a etapa a vem antes de b). Rode e confira a
// saída contra as regras: a aplicação aparece logo depois do sistema, antes
// do banco, do usuário do banco e do certificado, que ela espera.
//
//   Saída que aparece:
//   sistema aplicação banco usuário firewall certificado
//
//   Saída esperada:
//   sistema firewall certificado banco usuário aplicação
//
// O programa compila e roda sem erro. Conserte a lógica (bastam duas
// mudanças pequenas) para que ele mostre a saída esperada.
//
// Dicas:
// 1. Em que momento cada etapa entra no vetor ordem[]: quando a chamada
//    dfs(u) começa ou quando ela termina? Qual das duas garante que tudo o
//    que vem depois de u já foi tratado?
// 2. A ordem em que as chamadas TERMINAM é a pós-ordem. Com setas "a antes
//    de b", a resposta é a pós-ordem lida de trás para frente.
// 3. Resposta esperada: mova "ordem[n++] = u;" para o fim de dfs (depois do
//    laço) e imprima o vetor de n - 1 até 0. A pós-ordem é aplicação,
//    usuário, banco, certificado, firewall, sistema.
//
// Escreva sua resposta abaixo (conserte o código):

#include <stdbool.h>
#include <stdio.h>

#define V 6

const char *etapas[V] = {"sistema", "aplicação", "banco", "usuário", "firewall", "certificado"};
int antes[V][V];
bool visitado[V];
int ordem[V], n = 0;

void dfs(int u) {
    visitado[u] = true;
    ordem[n++] = u;
    for (int v = 0; v < V; v++)
        if (antes[u][v] && !visitado[v]) dfs(v);
}

int main(void) {
    int regras[][2] = {{0, 1}, {0, 2}, {2, 3}, {3, 1}, {0, 4}, {4, 5}, {5, 1}};
    for (int k = 0; k < 7; k++) antes[regras[k][0]][regras[k][1]] = 1;

    for (int u = 0; u < V; u++)
        if (!visitado[u]) dfs(u);

    for (int i = 0; i < n; i++) printf("%s%s", i > 0 ? " " : "", etapas[ordem[i]]);
    printf("\n");
    return 0;
}
