// 0036 · Juntando tudo: o caixa da lanchonete
// Exercício E215 · ★★★
//
// Generalize o binário recursivo (E190) para qualquer base de 2 a 16. Escreva:
//
//   char digito(int valor)          0..9 viram '0'..'9'; 10..15 viram 'A'..'F'
//   void em_base(int n, int base)   recursiva, imprime n na base
//   void mostrar(int n, int base)   imprime "n na base b: ..." e pula linha;
//                                   recusa base fora de 2..16
//
//   Saída esperada:
//   255 na base 16: FF
//   255 na base 2: 11111111
//   2026 na base 8: 3752
//   2026 na base 16: 7EA
//   46655 na base 6: 555555
//   10 na base 20: base inválida
//
// Dicas:
// 1. char é número: '0' + 7 é '7', e 'A' + (valor - 10) dá as letras.
// 2. em_base: se n < base, imprima digito(n); senão em_base(n / base, base) e
//    depois digito(n % base). Imprimir com %c.
// 3. Resposta esperada: a saída acima. Confira o 7EA: 7 * 256 + 14 * 16 + 10
//    = 2026.
//
// Escreva sua resposta abaixo:

#include <stdio.h>

int main(void) {

    return 0;
}
