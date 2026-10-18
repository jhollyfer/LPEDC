// 0015 · if/else e o = no lugar do ==
// Exercício E089 · ★★★
//
// Na entrada do estacionamento, o totem confere se há vaga e, se houver,
// se o motorista é mensalista (entra direto) ou não (retira o ticket). O
// programa abaixo tem o = no lugar do == em DOIS if aninhados (quebrado de
// propósito). Rode com 12 0: ele chama um avulso de mensalista e ainda zera
// as vagas. Conserte os dois testes escrevendo a constante à esquerda
// (0 == vagas), para que um = esquecido vire erro de compilação.
//
//   Vagas livres e mensalista (1 = sim, 0 = não): 12 0
//   Retire o ticket. Cancela aberta.
//   Vagas livres: 12
//
// Dicas:
// 1. vagas = 0 guarda 0 e testa 0 (sempre falso); mensalista = 1 guarda 1
//    e testa 1 (sempre verdade).
// 2. Teste a sua versão trocando um == por = de propósito: com a constante
//    à esquerda, o gcc recusa ("lvalue required"). Depois desfaça.
// 3. Resposta esperada: if (0 == vagas) e if (1 == mensalista). Testes:
//    12 0 → ticket e "Vagas livres: 12"; 12 1 → "Bem-vindo, mensalista.
//    Cancela aberta." e 12; 0 1 → "Lotado." e "Vagas livres: 0".
//
// Escreva sua resposta abaixo (conserte o código):

#include <stdio.h>

int main(void) {
    int vagas, mensalista;
    printf("Vagas livres e mensalista (1 = sim, 0 = não): ");
    if (scanf("%d %d", &vagas, &mensalista) != 2) {
        printf("Entrada inválida\n");
        return 1;
    }

    if (vagas = 0) {
        printf("Lotado.\n");
    } else {
        if (mensalista = 1) {
            printf("Bem-vindo, mensalista. Cancela aberta.\n");
        } else {
            printf("Retire o ticket. Cancela aberta.\n");
        }
    }
    printf("Vagas livres: %d\n", vagas);
    return 0;
}
