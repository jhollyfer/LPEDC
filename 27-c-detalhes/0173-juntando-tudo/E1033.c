// 0173 · Juntando tudo: o controle de acesso
// Exercício E1033 · ★☆☆
//
// Escreva as três operações básicas sobre as permissões de uma pessoa:
//
//   void conceder(unsigned *p, unsigned m)  // liga os bits de m
//   void revogar(unsigned *p, unsigned m)   // desliga os bits de m
//   bool tem(unsigned p, unsigned m)        // p tem TODOS os bits de m?
//
// Comece com p = ENTRAR, conceda REUNIAO | IMPRIMIR, revogue IMPRIMIR e
// teste REUNIAO e depois REUNIAO | IMPRIMIR, mostrando p a cada passo.
//
//   Saída esperada:
//   inicio: 1
//   conceder R|I: 7
//   revogar I: 3
//   tem R? sim
//   tem R|I? nao
//
// Escreva sua resposta abaixo:

#include <stdbool.h>
#include <stdio.h>

#define ENTRAR   (1u << 0) // E
#define REUNIAO  (1u << 1) // R
#define IMPRIMIR (1u << 2) // I
#define GARAGEM  (1u << 3) // G
#define CONFIG   (1u << 4) // C
#define QTD_PERMS 5

int main(void) {

    return 0;
}
