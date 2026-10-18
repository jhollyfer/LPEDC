// 0046 · Strings
// Exercício E275 · ★★★
//
// O programa abaixo monta o endereço "Rio de Janeiro - RJ" e confere a
// cidade. Ele tem TRÊS erros de propósito. Dois o compilador avisa (leia os
// warnings!). O terceiro não gera aviso nenhum: só o sanitizer pega, e só
// depois que você conserta os outros dois. Ache, explique e conserte.
//
//   Saída esperada depois do conserto:
//   Rio de Janeiro - RJ
//   Cidade conferida.
//
// Dicas:
// 1. Quantos bytes "RJ" precisa? E quantos o vetor uf tem?
// 2. Quantos bytes "Rio de Janeiro - RJ" precisa? Cabe em local[10]?
// 3. O que o == compara quando os dois lados são strings?
// 4. Resposta esperada: char uf[2] = "RJ" não tem lugar para o '\0' (o C
//    aceita sem avisar, e o %s lê além do vetor): use uf[3] ou uf[];
//    local[10] não cabe os 20 bytes do endereço (estouro no strcat, que o
//    gcc percebe com -Wstringop-overflow): use local[30]; cidade == "Rio" compara endereços, não texto (o gcc avisa):
//    use strcmp(cidade, "Rio") == 0.
//
// Escreva sua resposta abaixo (conserte o código):

#include <stdio.h>
#include <string.h>

int main(void) {
    char uf[2] = "RJ";
    char cidade[] = "Rio";
    char local[10];

    strcpy(local, cidade);
    strcat(local, " de Janeiro - ");
    strcat(local, uf);
    printf("%s\n", local);

    if (cidade == "Rio") {
        printf("Cidade conferida.\n");
    }
    return 0;
}
