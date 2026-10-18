// 0068 · Arquivos binários
// Exercício E407 · ★★★
//
// Este programa deveria salvar as 5 leituras de um medidor de água e lê-las
// de volta. Ele compila sem aviso e roda sem erro do sanitizer, mas mostra:
//
//   Leituras: 112 98 0 0 0
//
// em vez de "Leituras: 112 98 105 120 101". Tem DOIS problemas:
//
// a) um que faz o arquivo ficar com menos bytes do que devia;
// b) um que esconde o problema em vez de avisar.
//
// Ache e conserte os dois.
//
// Dicas:
// 1. Dentro de salvar, v é um int *, não um vetor. Quanto vale sizeof(v)?
// 2. Quantos bytes o arquivo tem depois de salvar? E quantos itens o fread
//    devolveu?
// 3. Resposta esperada: a) sizeof(v) é o tamanho do PONTEIRO (8 bytes), então
//    só 2 ints foram gravados. O certo é fwrite(v, sizeof(int), n, arq) (ou
//    sizeof *v). b) O main ignora o retorno do fread, que foi 2, e mostra os
//    zeros da inicialização como se fossem leituras. Confira se fread
//    devolveu 5 e avise se não.
//
// Escreva sua resposta abaixo (conserte o código):

#include <stdio.h>

void salvar(const char *caminho, int *v, int n) {
    FILE *arq = fopen(caminho, "wb");
    if (arq == NULL) {
        perror(caminho);
        return;
    }
    (void) n;
    fwrite(v, sizeof(v), 1, arq); // grava "o vetor"
    fclose(arq);
}

int main(void) {
    const char *caminho = "/tmp/agua.bin";
    int leituras[5] = {112, 98, 105, 120, 101};
    int lidas[5] = {0};

    salvar(caminho, leituras, 5);

    FILE *arq = fopen(caminho, "rb");
    if (arq == NULL) {
        perror(caminho);
        return 1;
    }
    fread(lidas, sizeof(int), 5, arq);
    fclose(arq);
    remove(caminho);

    printf("Leituras:");
    for (int i = 0; i < 5; i++) {
        printf(" %d", lidas[i]);
    }
    printf("\n");
    return 0;
}
