// Lista · Módulo 18 · Ordenação além da comparação e seleção
// Exercício P1822 · ★★★ · Radix MSD: os municípios em ordem alfabética
//
// O radix LSD precisa de chaves do mesmo tamanho. O radix MSD (do dígito
// MAIS significativo) não: ele separa as strings pela primeira letra com um
// counting sort e, dentro de cada grupo, resolve RECURSIVAMENTE pela segunda
// letra, e assim por diante. Uma string que já acabou (o '\0' na posição d)
// vai para o grupo 0 e fica antes de todas as que continuam: é por isso que
// "manaus" vem antes de "manausmoderna".
//
// Escreva msd(v, ini, fim, d), que ordena os ponteiros v[ini..fim] olhando a
// posição d (grupos de 0 a 256, com o caractere + 1 e 0 para o fim da string),
// com um vetor auxiliar de ponteiros. Ordene os 15 municípios do esqueleto,
// conte as chamadas recursivas, mostre os grupos do primeiro nível (a letra e
// quantos nomes) e o vetor final, e confira com strcmp que ficou em ordem.
//
//   Saída esperada:
//   Primeiro nível: b(2) c(3) h(1) i(2) m(4) p(1) t(2)
//   barcelos borba careiro coari codajas humaita iranduba itacoatiara manacapuru manaus manicore maues parintins tabatinga tefe
//   Chamadas: 10 | em ordem pelo strcmp: sim
//
// Dicas:
// 1. Grupo da string s na posição d: (unsigned char)s[d] + 1 se s[d] != '\0',
//    senão 0. São 257 grupos; C tem 258 posições para guardar os inícios.
// 2. Depois do counting sort da posição d, chame msd para cada grupo de 1 até
//    256 com mais de um elemento, com d + 1. O grupo 0 já está pronto: são
//    strings iguais.
// 3. Só chame strlen se precisar: s[d] já diz se a string acabou, desde que
//    d nunca passe do fim (e não passa, porque o grupo 0 não desce).
// 4. Resposta esperada: o primeiro nível tem b(2) c(3) h(1) i(2) m(4) p(1)
//    t(2); a ordem final vai de barcelos a tefe; strcmp confirma.
//
// Escreva sua resposta abaixo:

#include <stdio.h>
#include <string.h>

#define N 15

int main(void) {
    const char *mun[N] = {"manaus", "parintins", "itacoatiara", "manacapuru", "coari",
                          "tefe", "tabatinga", "maues", "humaita", "iranduba",
                          "manicore", "barcelos", "borba", "codajas", "careiro"};

    for (int i = 0; i < N; i++) printf("%s\n", mun[i]);
    return 0;
}
