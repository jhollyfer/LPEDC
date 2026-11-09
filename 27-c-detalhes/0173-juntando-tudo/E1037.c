// 0173 · Juntando tudo: o controle de acesso
// Exercício E1037 · ★★★
//
// Quando alguém pede um conjunto de permissões, o coworking oferece o
// papel mais barato que cobre o pedido. Escreva:
//
//   int menor_papel(unsigned pedido)
//
// que devolve o primeiro papel (VISITANTE, MEMBRO, ADMIN, nessa ordem) cujo
// pacote base tem TODAS as permissões do pedido, ou -1 se nenhum tem. E,
// para cada pedido, mostre também o que falta ao visitante (o que o pedido
// tem e o pacote do visitante não tem), como texto E R I G C.
//
// Teste com os pedidos ENTRAR, REUNIAO | IMPRIMIR, GARAGEM e 1u << 5 (uma
// sexta permissão, que nenhum papel dá).
//
//   Saída esperada:
//   pedido E----: visitante (falta ao visitante: -----)
//   pedido -RI--: membro (falta ao visitante: -RI--)
//   pedido ---G-: admin (falta ao visitante: ---G-)
//   pedido -----: nenhum (falta ao visitante: -----)
//
// Dicas:
// 1. Percorra p de 0 a QTD_PAPEIS - 1 e teste (base[p] & pedido) == pedido.
// 2. Falta = pedido & ~base[VISITANTE].
// 3. Repare na última linha: o bit 5 não aparece no texto de 5 letras, mas
//    ainda impede todos os papéis. Só os 5 bits de baixo viram texto.
// 4. Resposta esperada: a saída acima.
//
// Escreva sua resposta abaixo:

#include <stdio.h>

typedef enum { VISITANTE, MEMBRO, ADMIN, QTD_PAPEIS } Papel;

#define ENTRAR   (1u << 0) // E
#define REUNIAO  (1u << 1) // R
#define IMPRIMIR (1u << 2) // I
#define GARAGEM  (1u << 3) // G
#define CONFIG   (1u << 4) // C
#define QTD_PERMS 5

const unsigned base[QTD_PAPEIS] = {
    ENTRAR,
    ENTRAR | REUNIAO | IMPRIMIR,
    ENTRAR | REUNIAO | IMPRIMIR | GARAGEM | CONFIG,
};

int main(void) {

    return 0;
}
