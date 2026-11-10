// 0173 · Juntando tudo: o controle de acesso
// Exercício E1035 · ★★☆
//
// Escreva duas funções sobre as permissões:
//
//   unsigned revogar(unsigned p, unsigned m)  // p sem os bits de m
//   bool tem_todas(unsigned p, unsigned m)    // p tem TODOS os bits de m?
//
// No main, comece com p = ENTRAR | REUNIAO | IMPRIMIR, revogue IMPRIMIR,
// mostre p e teste REUNIAO | IMPRIMIR e depois ENTRAR | REUNIAO.
//
//   Saída esperada:
//   depois de revogar: 3
//   tem R e I? nao
//   tem E e R? sim
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
