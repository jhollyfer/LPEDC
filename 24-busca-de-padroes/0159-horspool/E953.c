// 0159 · Horspool
// Exercício E953 · ★★★
//
// Ache o bug. Este Horspool funciona para "pao", mas quando o padrão tem
// acento o sanitizer reclama de "index -61 out of bounds for type
// 'int [256]'" e depois o AddressSanitizer para o programa (é de propósito).
// Rode, leia a mensagem, conserte as DUAS linhas com o mesmo problema e rode
// de novo.
//
//   Saída esperada (depois de consertar):
//   pao: 2
//   feijão: 2
//   açaí: 2
//
// Dicas:
// 1. Em UTF-8, o 'ã' são dois bytes, 0xC3 e 0xA3. Num char com sinal (o
//    padrão no gcc para x86), 0xC3 vale -61.
// 2. "int c = padrao[j];" copia o -61 para o int. salto[-61] escreve antes
//    do começo do vetor, em memória de outra variável.
// 3. Converta para unsigned char antes de virar índice. O mesmo vale para
//    a letra do texto usada no salto. (Se você escrever salto[padrao[j]]
//    direto, o gcc avisa: "array subscript has type 'char'".)
// 4. Resposta esperada: a saída acima, sem erro do sanitizer.
//
// Escreva sua resposta abaixo (conserte o código):

#include <stdio.h>
#include <string.h>

int horspool(const char *texto, const char *padrao) {
    int n = (int) strlen(texto);
    int m = (int) strlen(padrao);
    int salto[256];
    int total = 0;
    for (int c = 0; c < 256; c++) {
        salto[c] = m;
    }
    for (int j = 0; j < m - 1; j++) {
        int c = padrao[j];
        salto[c] = m - 1 - j;
    }
    int i = 0;
    while (i <= n - m) {
        int j = m - 1;
        while (j >= 0 && texto[i + j] == padrao[j]) {
            j--;
        }
        if (j < 0) {
            total++;
        }
        int ultima = texto[i + m - 1];
        i += salto[ultima];
    }
    return total;
}

int main(void) {
    printf("pao: %d\n", horspool("o pao de queijo e o pao doce", "pao"));
    printf("feijão: %d\n", horspool("feijão, arroz e mais feijão", "feijão"));
    printf("açaí: %d\n", horspool("açaí com granola ou açaí puro?", "açaí"));
    return 0;
}
