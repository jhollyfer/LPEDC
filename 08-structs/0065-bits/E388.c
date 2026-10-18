// 0065 · Bits, máscaras e flags
// Exercício E388 · ★★☆
//
// As notificações do app ficam em flags: EMAIL (1), SMS (2) e PUSH (4). O
// usuário tinha email e push ligados e desligou o push. Mas a tela mostra o
// SMS ligado e, depois, nada desliga. O gcc até dá uma pista (um aviso). Rode,
// ache os três erros, conserte e rode de novo.
//
//   Saída esperada (depois de consertado):
//   email: ligado | sms: desligado | push: ligado
//   email: ligado | sms: desligado | push: desligado
//
// Dicas:
// 1. Leia o aviso "suggest parentheses": o == é avaliado antes do &.
// 2. && responde "os dois são diferentes de zero?"; para testar um bit, é &.
// 3. Para desligar um bit, faça E com o inverso da máscara.
// 4. Resposta esperada: (f & EMAIL) == 0 com parênteses; f & SMS em vez de
//    f && SMS; f &= ~PUSH em vez de f &= PUSH.
//
// Escreva sua resposta abaixo (conserte o código):

#include <stdio.h>

#define EMAIL 1u
#define SMS   2u
#define PUSH  4u

void mostrar(unsigned f) {
    printf("email: %s | ", f & EMAIL == 0 ? "desligado" : "ligado");
    printf("sms: %s | ", f && SMS ? "ligado" : "desligado");
    printf("push: %s\n", (f & PUSH) ? "ligado" : "desligado");
}

int main(void) {
    unsigned f = EMAIL | PUSH;
    mostrar(f);

    f &= PUSH; // desliga o push
    mostrar(f);
    return 0;
}
