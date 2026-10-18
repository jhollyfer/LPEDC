// 0072 · Arquivos texto
// Exercício E430 · ★★☆
//
// Complete o programa. A parte que cria o arquivo /tmp/turma.txt já está
// pronta: cada linha tem o nome do aluno e duas notas. Falta a leitura: use
// fscanf num laço que pare quando a linha não vier completa, calcule a média
// de cada um e mostre a situação (aprovado com média >= 7.0). No fim, mostre
// a média da turma.
//
//   Saída esperada:
//   Bruna    média 8.25  aprovada(o)
//   Diego    média 5.50  reprovada(o)
//   Lia      média 7.00  aprovada(o)
//   Média da turma: 6.92
//
// Dicas:
// 1. fscanf(arq, "%19s %lf %lf", nome, &n1, &n2) devolve 3 quando leu a
//    linha inteira. Use "== 3" como condição do while.
// 2. Para a média da turma, acumule as médias e conte os alunos.
// 3. Resposta esperada: Bruna 8.25, Diego 5.50, Lia 7.00, turma 6.92
//    (20.75 / 3 = 6.9166...).
//
// Escreva sua resposta abaixo (complete onde está o TODO):

#include <stdio.h>

int main(void) {
    const char *caminho = "/tmp/turma.txt";

    FILE *arq = fopen(caminho, "w");
    if (arq == NULL) {
        perror(caminho);
        return 1;
    }
    fprintf(arq, "Bruna 9.0 7.5\n");
    fprintf(arq, "Diego 4.0 7.0\n");
    fprintf(arq, "Lia 6.5 7.5\n");
    fclose(arq);

    arq = fopen(caminho, "r");
    if (arq == NULL) {
        perror(caminho);
        return 1;
    }

    // TODO: ler cada linha com fscanf, mostrar média e situação,
    //       e no fim a média da turma

    fclose(arq);
    remove(caminho);
    return 0;
}
