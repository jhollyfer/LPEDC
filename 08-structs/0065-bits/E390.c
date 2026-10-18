// 0065 · Bits, máscaras e flags
// Exercício E390 · ★★★
//
// O despertador do celular guarda os dias da semana num byte: bit 0 é
// domingo, bit 1 segunda, ..., bit 6 sábado. O alarme toca nos dias úteis e
// a academia é segunda, quarta e sexta. Monte as duas máscaras e, só com
// operadores de bits, mostre:
//
//   Saída esperada:
//   alarme: seg ter qua qui sex (5 dias)
//   academia: seg qua sex (3 dias)
//   alarme sem academia: ter qui (2 dias)
//   sem alarme: dom sáb (2 dias)
//   academia em dia sem alarme? não
//
// Dicas:
// 1. Defina constantes com 1u << n: SEG = 1u << 1, ..., e monte
//    alarme = SEG | TER | QUA | QUI | SEX (vale 0x3E = 62).
// 2. "alarme sem academia" é alarme & ~academia.
// 3. "sem alarme" é ~alarme, mas o ~ liga também os bits 7 a 31: apague com
//    a máscara 0x7F (os 7 dias).
// 4. Uma função void listar(const char *rotulo, unsigned dias) percorre os 7
//    bits, mostra o nome e conta.
// 5. Resposta esperada: a saída acima. A última pergunta é
//    (academia & ~alarme) != 0.
//
// Escreva sua resposta abaixo:

#include <stdio.h>

int main(void) {

    return 0;
}
