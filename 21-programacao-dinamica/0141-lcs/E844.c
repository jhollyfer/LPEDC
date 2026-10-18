// 0141 · Maior subsequência comum (LCS)
// Exercício E844 · ★★☆
//
// Charada de palavras: qual é a MENOR sequência de letras (não precisa
// existir no dicionário) que contém BANANA e também CABANA como
// subsequências? É a menor supersequência comum, e ela sai da tabela da
// LCS: as letras da LCS aparecem uma vez só, e todas as outras letras das
// duas palavras entram também. Por isso o tamanho é m + n - LCS.
//
// Monte a tabela da LCS, construa a supersequência numa volta pela tabela
// e confira o resultado com uma função
//
//   int eh_subsequencia(const char *p, const char *t)
//
// que diz se p é subsequência de t.
//
//   Saída esperada:
//   LCS: 4 letras
//   Supersequência: CABANANA (8 letras)
//   BANANA está nela? sim
//   CABANA está nela? sim
//
// Dicas:
// 1. A volta é a da LCS, mas TODO passo grava uma letra em sup[--k]: na
//    diagonal, a letra comum; subindo, a[i - 1]; indo para a esquerda,
//    b[j - 1]. Comece com k = m + n - c[m][n] e sup[k] = '\0'.
// 2. Quando i ou j chega a 0, ainda sobra o começo da outra palavra: copie
//    o que sobrou com mais dois while.
// 3. eh_subsequencia: ande em t e avance em p só quando a letra bate; no
//    fim, p tem que ter chegado ao '\0'.
// 4. Use o mesmo desempate do texto (>= sobe), senão a supersequência pode
//    sair diferente (com as mesmas 8 letras).
// 5. Resposta esperada: a saída acima.
//
// Escreva sua resposta abaixo:

#include <stdio.h>
#include <string.h>

int main(void) {

    return 0;
}
