// Lista · Módulo 24 · Busca de padrões em texto
// Exercício P2408 · ★☆☆ · O filtro do grupo da família
//
// O grupo da família tem um filtro: cada palavra proibida vira asteriscos,
// letra por letra, na própria mensagem. Escreva do zero
// int censura(char *texto, const char *palavra), uma força bruta que troca
// cada ocorrência por '*' e devolve quantas achou. Rode para "droga",
// "saco" e "chato", uma depois da outra, e mostre a mensagem final.
//
//   Saída esperada:
//   droga: 2
//   saco: 1
//   chato: 0
//   que *****, perdi o onibus de novo, ***** de chuva, que ****
//
// Dicas:
// 1. A mensagem precisa estar num vetor (char msg[] = "..."), não num
//    ponteiro para literal: literal não pode ser alterado.
// 2. Ao achar em i, troque texto[i] até texto[i + m - 1] por '*'.
// 3. Resposta esperada: droga 2, saco 1, chato 0.
//
// Escreva sua resposta abaixo:

#include <stdio.h>
#include <string.h>

int main(void) {
    char msg[] = "que droga, perdi o onibus de novo, droga de chuva, que saco";
    printf("%s\n", msg);
    return 0;
}
