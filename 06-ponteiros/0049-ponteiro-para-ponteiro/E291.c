// 0049 · Ponteiro para ponteiro
// Exercício E291 · ★★☆
//
// A loja recebe mensagens como "Pedido numero 4521 confirmado". Escreva
//
//   void pula_ate_digito(const char **s)
//
// que avança o ponteiro DE QUEM CHAMOU até o primeiro dígito do texto (ou
// até o '\0', se não houver dígito). No main:
//
//   const char *msg = "Pedido numero 4521 confirmado";
//   pula_ate_digito(&msg);
//   printf("%s\n", msg);
//
//   Saída esperada:
//   4521 confirmado
//
// Teste também com "Sem numero": deve sair uma linha vazia.
//
// Dicas:
// 1. Dentro da função, *s é o ponteiro do main e **s é o caractere para
//    onde ele aponta.
// 2. while (**s != '\0' && !isdigit((unsigned char)**s)) { (*s)++; }
//    Os parênteses em (*s)++ são obrigatórios.
// 3. Resposta esperada: "4521 confirmado" e uma linha vazia.
//
// Escreva sua resposta abaixo:

#include <stdio.h>
#include <ctype.h>

int main(void) {

    return 0;
}
