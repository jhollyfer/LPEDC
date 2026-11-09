// Lista · Módulo 25 · Estruturas especiais
// Exercício P2507 · ★☆☆ · Os emojis usados por último
//
// O teclado do celular mostra os emojis numa fileira de 6 e procura da
// esquerda para a direita. Depois de cada uso, o emoji vai para a frente
// (mover para a frente) e os que estavam antes dele andam uma casa. Escreva
// do zero usa(v, emoji), que faz isso num vetor de strings e devolve o
// custo (quantos foram comparados). Faça a sequência do dia e mostre o
// custo e a fileira depois de cada uso, e o custo total.
//
//   Fileira inicial: risada coracao joinha palmas fogo choro
//   Usos: fogo fogo joinha fogo choro joinha fogo
//
//   Saída esperada:
//   fogo    custo 5: fogo risada coracao joinha palmas choro
//   fogo    custo 1: fogo risada coracao joinha palmas choro
//   joinha  custo 4: joinha fogo risada coracao palmas choro
//   fogo    custo 2: fogo joinha risada coracao palmas choro
//   choro   custo 6: choro fogo joinha risada coracao palmas
//   joinha  custo 3: joinha choro fogo risada coracao palmas
//   fogo    custo 3: fogo joinha choro risada coracao palmas
//   Custo total: 24
//
// Dicas:
// 1. O vetor é de ponteiros (const char *v[]): mover é trocar ponteiros,
//    nenhuma letra é copiada.
// 2. Para abrir espaço na frente, ande de i até 1: v[k] = v[k - 1].
// 3. Resposta esperada: custo total 24; o segundo "fogo" custa 1.
//
// Escreva sua resposta abaixo:

#include <stdio.h>
#include <string.h>

int main(void) {

    return 0;
}
