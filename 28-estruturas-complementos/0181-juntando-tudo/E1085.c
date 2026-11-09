// 0181 · Juntando tudo
// Exercício E1085 · ★★★
//
// A fila de espera da clínica ganhou prioridade: idosos (60 anos ou mais)
// passam na frente dos outros, mas, entre os idosos, vale a ordem de
// chegada (e entre os demais também). Escreva, com uma lista dupla circular
// com sentinela escrita por você (struct com nome, idade, ant e prox),
// entra(fila, nome, idade): o idoso entra logo DEPOIS do último idoso da
// fila (ou logo depois da sentinela, se não houver nenhum); os demais
// entram no fim. Sem nenhum caso especial para fila vazia. Chegam, nesta
// ordem: Ana 35, Beto 70, Caio 22, Dora 65, Enzo 81, Fabi 40. Mostre a fila
// depois de cada chegada e libere tudo no fim.
//
//   Saída esperada:
//   Ana
//   Beto* Ana
//   Beto* Ana Caio
//   Beto* Dora* Ana Caio
//   Beto* Dora* Enzo* Ana Caio
//   Beto* Dora* Enzo* Ana Caio Fabi
//
// Dicas:
// 1. Para o idoso, comece em p = &fila->nil e avance enquanto p->prox não
//    for a sentinela e p->prox for idoso. Insira depois de p.
// 2. Para os demais, insira depois de fila->nil.ant (o último).
// 3. Resposta esperada: a saída acima (o * marca os idosos).
//
// Escreva sua resposta abaixo:

#include <stdio.h>
#include <stdlib.h>

int main(void) {

    return 0;
}
