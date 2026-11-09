// Lista · Módulo 10 · Pensar como cientista da computação
// Exercício P1027 · ★★★ · O topo da trilha em O(log n)
//
// O GPS da trilha registrou as altitudes, em metros, a cada quilômetro. Um
// PICO é um ponto que não é menor que os vizinhos (as pontas só têm um
// vizinho). Todo vetor tem pelo menos um pico, e dá para achar um sem olhar
// o vetor inteiro. Escreva:
//
//   int pico_sequencial(const int v[], int n, int *comp)
//     anda até o primeiro i com v[i] >= v[i + 1] (ou até o fim);
//   int pico_binario(const int v[], int n, int *comp)
//     com ini = 0 e fim = n - 1, enquanto ini < fim: olhe meio e meio + 1.
//     Se v[meio] < v[meio + 1], há um pico à direita: ini = meio + 1. Senão,
//     há um à esquerda (o meio incluído): fim = meio.
//
// Ponha no começo de cada volta do binário um assert com o invariante:
// (ini == 0 ou v[ini - 1] < v[ini]) e (fim == n - 1 ou v[fim] >= v[fim + 1]).
// Conte 1 comparação por volta em cada versão. Teste com a trilha
// 120, 340, 560, 610, 580, 430, 470, 520, 300, 150 e com a rampa 100, 200,
// ..., 1600 (16 pontos).
//
//   Saída esperada:
//   Trilha: pico na posição 3 (610 m), binária 3, sequencial 4
//   Rampa: pico na posição 15 (1600 m), binária 4, sequencial 15
//
// Dicas:
// 1. Por que existe pico em [ini, fim]: o invariante diz que se "sobe" ao
//    entrar no intervalo e "desce" (ou fica igual) ao sair dele. Andando lá
//    dentro, em algum ponto a subida tem que parar.
// 2. Quando ini == fim, o invariante diz que v[ini] não é menor que nenhum
//    vizinho: é um pico.
// 3. As duas podem achar picos DIFERENTES (a trilha tem dois: 610 e 520).
//    Aqui, por acaso, acharam o mesmo.
// 4. Resposta esperada: a saída acima.
//
// Escreva sua resposta abaixo:

#include <assert.h>
#include <stdio.h>

int main(void) {

    return 0;
}
