// 0173 · Juntando tudo: o controle de acesso
// Exercício E1034 · ★☆☆
//
// Escreva as duas conversões entre as permissões e o texto do relatório,
// na ordem E R I G C (bit 0 a bit 4), com '-' para a que falta:
//
//   void para_texto(unsigned p, char s[QTD_PERMS + 1])  // 21 -> "E-I-C"
//   unsigned de_texto(const char *s)                     // "ER-G-" -> 11
//
//   Saída esperada:
//   E-I-C
//   ER-G- = 11
//
// Dicas:
// 1. Guarde as letras numa string "ERIGC": a letra do bit b é letras[b].
// 2. Em de_texto, qualquer caractere diferente de '-' na posição b liga o
//    bit b: p |= 1u << b.
// 3. Não esqueça o '\0' em s[QTD_PERMS].
// 4. Resposta esperada: a saída acima.
//
// Escreva sua resposta abaixo:

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
