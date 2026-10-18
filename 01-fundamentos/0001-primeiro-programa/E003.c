// 0001 · O primeiro programa
// Exercício E003 · ★★☆
//
// Este programa tem QUATRO erros e não compila de propósito. Rode com o
// rodar, leia a primeira mensagem, conserte, rode de novo e repita até
// funcionar. Para cada erro, anote o que o gcc disse e qual estação
// reclamou: compilador ou ligador.
//
//   Saída esperada (depois de consertar):
//   Farmácia aberta 24h
//   Plantão: (11) 5555-0199
//
// Dicas:
// 1. Comece pelo topo: um comentário que não fecha engole todo o resto.
// 2. Olhe com atenção as maiúsculas e os nomes das funções. E os ;.
// 3. Resposta esperada: (1) o /* da primeira linha nunca fecha
//    ("unterminated comment"): feche com */; (2) Int com I maiúsculo não é
//    tipo ("unknown type name 'Int'"): use int; (3) falta ; depois do
//    primeiro printf ("expected ';'"). Esses três são do compilador. (4)
//    print não existe: o compilador só avisa "implicit declaration of
//    function 'print'", e quem para é o ligador, com "undefined reference
//    to 'print'": use printf.
//
// Escreva sua resposta abaixo (conserte o código):

/* Aviso da farmácia
#include <stdio.h>

Int main(void) {
    printf("Farmácia aberta 24h\n")
    print("Plantão: (11) 5555-0199\n");
    return 0;
}
