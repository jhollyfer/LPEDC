// Lista · Módulo 29 · Grafos: ciclos e cortes; problemas difíceis
// Exercício P2912 · ★★☆ · Trajeto euleriano dirigido
//
// Um barco de passeio faz trechos de rio que só podem ser navegados no
// sentido da correnteza. Portos 0 a 4, trechos dirigidos:
//
//   0->1, 1->2, 2->0, 0->3, 3->1, 1->4
//
// O barco quer navegar todos os trechos uma vez cada, sem precisar voltar
// ao início. Escreva o programa que mostra saída - entrada de cada porto,
// escolhe o início (o porto com saída - entrada = 1; se todos forem 0, o
// porto 0) e roda o Hierholzer dirigido a partir dele.
//
//   Saída esperada:
//   Porto 0: saída - entrada = 1
//   Porto 1: saída - entrada = 0
//   Porto 2: saída - entrada = 0
//   Porto 3: saída - entrada = 0
//   Porto 4: saída - entrada = -1
//   Trajeto: 0 1 2 0 3 1 4
//
// Dicas:
// 1. Trajeto euleriano dirigido (com o grafo conexo): no máximo um porto com
//    saída - entrada = 1 (início), um com -1 (fim), o resto com 0.
// 2. O Hierholzer é o do texto, apagando só trecho[u][v] e escolhendo o
//    destino de menor índice.
// 3. Resposta esperada: a saída acima. O trajeto termina no porto 4, o único
//    com entrada - saída = 1.
//
// Escreva sua resposta abaixo:

#include <stdio.h>

int main(void) {

    return 0;
}
