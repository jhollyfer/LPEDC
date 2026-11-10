// 0180 · Pigeonhole e chave composta
// Exercício E1079 · ★★★
//
// A secretaria quer a lista dos inscritos do vestibular por CIDADE (código
// 1, 2 ou 3) e, dentro de cada cidade, por NOTA, da menor para a maior.
// Escreva ordena_por_cidade e ordena_por_nota, duas inserções (que são
// estáveis) sobre Inscrito, e chame-as na ordem que dá o resultado certo
// (a chave principal fica por último). Inscritos (nome, cidade, nota):
// Ana 1 62, Teo 2 70, Nina 3 91, Rui 1 80, Bia 2 48, Lia 1 62, Caio 3 55,
// Ivo 2 70, Joao 1 55. Mostre uma linha por cidade.
//
//   Saída esperada:
//   1:Joao(55) 1:Ana(62) 1:Lia(62) 1:Rui(80)
//   2:Bia(48) 2:Teo(70) 2:Ivo(70)
//   3:Caio(55) 3:Nina(91)
//
// Escreva sua resposta abaixo:

#include <stdio.h>

typedef struct {
    char nome[8];
    int cidade, nota;
} Inscrito;

int main(void) {

    return 0;
}
