// 0066 · Juntando tudo: o cardápio
// Exercício E391 · ★☆☆
//
// O mercado imprime etiquetas para a prateleira. Crie:
//
//   - um enum Setor { HORTIFRUTI, LATICINIOS, PADARIA };
//   - flags PROMO (bit 0), ORGANICO (bit 1) e REFRIGERADO (bit 2);
//   - um typedef struct Produto com nome, setor, preço e flags;
//   - void etiqueta(const Produto *p), que mostra uma linha por produto.
//
// Use os três produtos abaixo.
//
//   Saída esperada:
//   Banana prata (hortifrúti) R$ 6.99/kg [orgânico]
//   Iogurte natural (laticínios) R$ 4.50/kg [promo] [refrigerado]
//   Pão francês (padaria) R$ 16.90/kg
//
// Dicas:
// 1. #define PROMO (1u << 0), e assim por diante.
// 2. Um vetor const char *setores[] = {"hortifrúti", ...} indexado pelo enum
//    traduz o setor.
// 3. Para cada flag: if (p->flags & PROMO) printf(" [promo]");
// 4. Resposta esperada: a saída acima.
//
// Escreva sua resposta abaixo:

#include <stdio.h>

int main(void) {

    return 0;
}
