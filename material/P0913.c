// Lista · Módulo 09 · Arquivos e linha de comando
// Exercício P0913 · ★★☆ · Busca binária no cadastro do cursinho
//
// O arquivo de alunos está ORDENADO por matrícula, então dá para achar um
// aluno lendo poucos registros: olhe o do meio com fseek e fread e descarte
// a metade que não pode ter a matrícula. Escreva
//
//   int busca(FILE *arq, int n, int matricula, Aluno *achado, int *leituras)
//
// que devolve 1 se achou (e copia o aluno para *achado) ou 0 se não achou,
// e conta em *leituras quantos fread fez. O main grava os 8 alunos e
// procura 2041, 2007 e 2050. O n (quantos registros) deve ser calculado
// pelo tamanho do arquivo, não escrito à mão.
//
//   Saída esperada:
//   8 alunos no arquivo
//   2041: Kaio (2 leituras)
//   2007: Bruna (2 leituras)
//   2050: não encontrada (4 leituras)
//
// Dicas:
// 1. n = ftell depois de fseek(arq, 0, SEEK_END), dividido por sizeof(Aluno).
// 2. Com ini = 0 e fim = n - 1: meio = (ini + fim) / 2, fseek para
//    meio * sizeof(Aluno), fread, compare. Menor: ini = meio + 1; maior:
//    fim = meio - 1. Pare quando ini > fim.
// 3. Resposta esperada: a saída acima. Com 8 registros, nenhuma busca passa
//    de 4 leituras (piso de log2 8, mais 1).
//
// Escreva sua resposta abaixo:

#include <stdio.h>

typedef struct {
    int matricula;
    char nome[16];
} Aluno;

int main(void) {
    const char *caminho = "/tmp/p0913_alunos.bin";
    Aluno turma[8] = {
        {2003, "Ana"}, {2007, "Bruna"}, {2015, "Caue"}, {2022, "Duda"},
        {2030, "Enzo"}, {2041, "Kaio"}, {2048, "Lara"}, {2056, "Malu"},
    };

    FILE *arq = fopen(caminho, "wb+");
    if (arq == NULL) {
        perror(caminho);
        return 1;
    }
    fwrite(turma, sizeof(Aluno), 8, arq);

    // complete aqui: calcule n, faça as três buscas e mostre o resultado

    fclose(arq);
    remove(caminho);
    return 0;
}
