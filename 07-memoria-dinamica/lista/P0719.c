// Lista · Módulo 07 · Memória dinâmica
// Exercício P0719 · ★★☆ · União e interseção do tamanho exato
//
// Dois grupos de WhatsApp de um condomínio têm os números dos apartamentos de
// quem participa, em ordem crescente:
//
//   int a[6] = {101, 103, 202, 204, 301, 402};
//   int b[5] = {103, 104, 204, 302, 402};
//
// Escreva int *uniao(const int *a, int na, const int *b, int nb, int *n) e
// int *intersecao(...) com a mesma assinatura. Cada uma reserva o pior caso
// (na + nb para a união; o menor dos dois para a interseção), preenche
// andando nos dois vetores ao mesmo tempo e, no fim, ENCOLHE o bloco com
// realloc para o tamanho exato. Mostre os resultados e o tamanho de cada um:
//
//   Saída esperada:
//   Nos dois grupos ou em um (8): 101 103 104 202 204 301 302 402
//   Nos dois grupos (3): 103 204 402
//
// Dicas:
// 1. Dois índices, i em a e j em b. Na união: se a[i] < b[j], pega a[i] e
//    avança i; se b[j] < a[i], pega b[j]; se forem iguais, pega um só e
//    avança os dois. No fim, copia o que sobrou de cada lado.
// 2. Na interseção, só os iguais entram.
// 3. Ao encolher, um realloc para 0 bytes pode devolver NULL: se *n for 0,
//    devolva o bloco como está. Se o realloc falhar, o bloco grande ainda
//    serve.
// 4. Resposta esperada: a saída acima.
//
// Escreva sua resposta abaixo:

#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int a[6] = {101, 103, 202, 204, 301, 402};
    int b[5] = {103, 104, 204, 302, 402};
    (void) a, (void) b; // apague esta linha quando escrever

    return 0;
}
