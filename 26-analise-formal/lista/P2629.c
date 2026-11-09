// Lista · Módulo 26 · Notação assintótica, somatórios e espaço
// Exercício P2629 · ★★★ · Distância de edição em duas linhas
//
// A distância de edição (assunto 0142) entre "paralelepipedo" e
// "paralelogramo" se calcula com uma tabela de (m + 1) × (k + 1) inteiros.
// Mas cada linha só depende da anterior. Escreva duas versões:
// - tabela: a matriz inteira com malloc;
// - linhas: só dois vetores de k + 1 inteiros, trocando os papéis a cada
//   linha.
// Mostre a distância e os bytes de cada uma, e repita para duas palavras
// de 2000 letras geradas no programa (a[i] = 'a' + i % 7, b[i] = 'a' + i % 5):
//
//   Saída esperada:
//   curtas: tabela 6 (840 bytes), linhas 6 (112 bytes)
//   longas: tabela 912 (16016004 bytes), linhas 912 (16008 bytes)
//
// Dicas:
// 1. d[i][j] = min(d[i-1][j] + 1, d[i][j-1] + 1, d[i-1][j-1] + (a[i-1] !=
//    b[j-1])).
// 2. Na versão de linhas, ant e atual são dois ponteiros; no fim de cada i,
//    troque-os.
// 3. Tempo Θ(mk) nas duas; espaço Θ(mk) contra Θ(k). Com 2000 letras: 16 MB
//    contra 16 KB.
// 4. Resposta esperada: a saída acima.
//
// Escreva sua resposta abaixo:

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {

    return 0;
}
