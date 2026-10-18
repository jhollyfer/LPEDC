// 0116 · DFS: busca em profundidade
// Exercício E696 · ★★★
//
// Num escape room, as portas só abrem num sentido (grafo dirigido). A função
// existe_caminho deveria dizer se dá para sair de uma sala e chegar em outra.
// O programa tem DOIS erros de propósito e responde "não" para tudo. Rode,
// ache os dois e conserte. Atenção: depois de consertar o primeiro, a
// resposta do meio continua errada.
//
//   Saída esperada depois do conserto:
//   Sala 0 -> Sala 4: sim
//   Sala 3 -> Sala 4: sim
//   Sala 4 -> Sala 0: não
//
// Dicas:
// 1. Quando a chamada recursiva acha o destino, ela devolve true. Quem
//    recebe esse true?
// 2. A segunda pergunta começa com o vetor visitado como a primeira deixou.
//    As salas 1 e 2 já estão marcadas.
// 3. Resposta esperada: (1) o valor da chamada recursiva é jogado fora; o
//    certo é "if (existe_caminho(v, destino)) return true;". (2) visitado[]
//    não é zerado entre as perguntas; zere antes de cada consulta. Consertado,
//    mostra a saída acima.
//
// Escreva sua resposta abaixo (conserte o código):

#include <stdbool.h>
#include <stdio.h>

#define V 5

int porta[V][V] = {
    {0, 1, 0, 1, 0}, // 0 -> 1, 0 -> 3
    {0, 0, 1, 0, 0}, // 1 -> 2
    {0, 0, 0, 0, 1}, // 2 -> 4
    {0, 1, 0, 0, 0}, // 3 -> 1
    {0, 0, 0, 0, 0}, // da 4 não sai nada
};
bool visitado[V];

bool existe_caminho(int u, int destino) {
    if (u == destino) return true;
    visitado[u] = true;
    for (int v = 0; v < V; v++)
        if (porta[u][v] && !visitado[v]) existe_caminho(v, destino);
    return false;
}

int main(void) {
    int perguntas[][2] = {{0, 4}, {3, 4}, {4, 0}};
    for (int k = 0; k < 3; k++) {
        int de = perguntas[k][0], para = perguntas[k][1];
        printf("Sala %d -> Sala %d: %s\n", de, para, existe_caminho(de, para) ? "sim" : "não");
    }
    return 0;
}
