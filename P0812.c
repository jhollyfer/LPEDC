// Lista · Módulo 08 · Tipos compostos
// Exercício P0812 · ★★☆ · Ordenar os ponteiros, não as fichas
//
// As fichas dos pacientes são grandes (cada uma tem um histórico de 200
// caracteres), e mover uma ficha inteira a cada troca do qsort custa caro.
// Crie as fichas no heap e um vetor de PONTEIROS para elas, e ordene os
// ponteiros pela idade (do mais velho para o mais novo). As fichas não saem
// do lugar:
//
//   typedef struct { char nome[20]; int idade; char historico[200]; } Ficha;
//
// Escreva Ficha *nova_ficha(const char *nome, int idade, const char *hist),
// que aloca e preenche uma ficha (antes do strcpy, confira com strlen se o
// texto cabe no campo; se não couber, devolva NULL). Crie as 4 fichas abaixo,
// ordene e
// mostre; mostre também quantos bytes cada troca move no qsort de ponteiros e
// quantos moveria no de fichas. Libere tudo:
//
//   Raimundo 58 "hipertensão"    Jéssica 31 "asma"
//   Benedito 74 "diabetes tipo 2"    Karina 45 "nenhum"
//
//   Saída esperada:
//   1. 74 anos: Benedito (diabetes tipo 2)
//   2. 58 anos: Raimundo (hipertensão)
//   3. 45 anos: Karina (nenhum)
//   4. 31 anos: Jéssica (asma)
//   A ficha do Raimundo continua no mesmo endereço, agora na posição 2
//   Bytes por troca: 8 (ponteiro) contra 224 (ficha)
//
// Dicas:
// 1. Ficha *f = malloc(sizeof *f); e preencha f->nome, f->idade,
//    f->historico.
// 2. O vetor é Ficha *fichas[4]. Cada elemento é um ponteiro: o qsort recebe
//    sizeof fichas[0] (8 bytes) e a comparação recebe um Ficha ** disfarçado:
//    const Ficha *a = *(Ficha * const *) pa;
// 3. Para provar que a ficha não se moveu, guarde o endereço de fichas[0]
//    (o Raimundo) antes do qsort e, depois, procure em que posição do vetor
//    esse mesmo endereço foi parar.
// 4. Resposta esperada: a saída acima (os bytes por troca: 8 e 224).
//
// Escreva sua resposta abaixo:

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char nome[20];
    int idade;
    char historico[200];
} Ficha;

int main(void) {

    return 0;
}
