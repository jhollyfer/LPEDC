// Lista · Módulo 09 · Arquivos e linha de comando
// Exercício P0903 · ★☆☆ · O livro-caixa que esquece vendas
//
// A padaria anota as vendas num arquivo texto. De manhã o programa grava
// 12, 30 e 8 reais; à tarde ele ACRESCENTA 25 e 15; no fim do dia ele lê
// tudo e soma. O programa abaixo compila sem aviso, mas tem DOIS erros de
// propósito e mostra só "Total do dia: R$ 0". Conserte para a saída ficar:
//
//   Saída esperada:
//   Venda: 12
//   Venda: 30
//   Venda: 8
//   Venda: 25
//   Venda: 15
//   Total do dia: R$ 90
//
// Dicas:
// 1. Que modo de abertura zera o arquivo? E qual escreve depois do fim?
// 2. O fprintf não vai direto para o disco: ele enche um buffer na memória,
//    que só é despejado no fclose (ou quando enche). Se você abre o arquivo
//    de novo para ler sem fechar o da escrita, a leitura não enxerga nada.
// 3. Resposta esperada: na tarde, troque "w" por "a" e acrescente
//    fclose(arq) depois dos dois fprintf. A saída fica igual à de cima.
//
// Escreva sua resposta abaixo (conserte o código):

#include <stdio.h>

int main(void) {
    const char *caminho = "/tmp/p0903_caixa.txt";

    // manhã
    FILE *arq = fopen(caminho, "w");
    if (arq == NULL) {
        perror(caminho);
        return 1;
    }
    fprintf(arq, "12\n30\n8\n");
    fclose(arq);

    // tarde
    arq = fopen(caminho, "w");
    if (arq == NULL) {
        perror(caminho);
        return 1;
    }
    fprintf(arq, "25\n");
    fprintf(arq, "15\n");

    // fim do dia
    FILE *leitura = fopen(caminho, "r");
    if (leitura == NULL) {
        perror(caminho);
        fclose(arq);
        return 1;
    }
    int venda, total = 0;
    while (fscanf(leitura, "%d", &venda) == 1) {
        printf("Venda: %d\n", venda);
        total += venda;
    }
    fclose(leitura);
    fclose(arq);
    remove(caminho);

    printf("Total do dia: R$ %d\n", total);
    return 0;
}
