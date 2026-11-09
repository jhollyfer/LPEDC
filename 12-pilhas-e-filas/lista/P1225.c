// Lista · Módulo 12 · Pilhas e filas
// Exercício P1225 · ★★★ · Os lagos da várzea (preenchimento com pilha)
//
// Na foto de satélite da várzea, '~' é água e '.' é terra. Um LAGO é um
// grupo de casas de água ligadas por cima, baixo, esquerda ou direita.
// Quantos lagos há, e de que tamanho? Varra o mapa linha por linha; ao achar
// uma água ainda não visitada, "pinte" o lago inteiro com uma PILHA
// explícita de posições (sem recursão), contando as casas.
//
//   ~~..~...
//   ~...~~..
//   ..~.....
//   .~~~..~~
//   ......~.
//   ~~....~.
//
// Escreva o programa com uma pilha de structs Pos {linha, coluna} sobre
// vetor (48 posições bastam) e uma matriz bool de visitadas. Mostre cada
// lago na ordem em que foi achado e o maior.
//
//   Saída esperada:
//   Lago 1: 3 casas (começa em 0,0)
//   Lago 2: 3 casas (começa em 0,4)
//   Lago 3: 4 casas (começa em 2,2)
//   Lago 4: 4 casas (começa em 3,6)
//   Lago 5: 2 casas (começa em 5,0)
//   Maior: 4 casas
//
// Dicas:
// 1. Ao achar o começo: marque visitada, empilhe. Enquanto a pilha não
//    esvaziar: desempilhe, conte 1 e, para cada vizinho de água ainda não
//    visitado, marque e empilhe.
// 2. Marque como visitada NA HORA DE EMPILHAR, não ao desempilhar: assim
//    nenhuma casa entra duas vezes na pilha, e 48 posições sempre bastam.
// 3. Essa é a busca em profundidade; trocando a pilha por uma fila vira
//    busca em largura, e o número de lagos é o mesmo.
// 4. Resposta esperada: a saída acima.
//
// Escreva sua resposta abaixo:

#include <stdbool.h>
#include <stdio.h>

#define L 6
#define C 8

typedef struct {
    int l, c;
} Pos;

int main(void) {

    return 0;
}
