// 0075 · Juntando tudo
// Exercício E447 · ★★☆
//
// Arquivo com cabeçalho. O arquivo /tmp/agenda.bin começa com um int que diz
// quantos contatos ele tem, seguido dos contatos (registros de tamanho
// fixo):
//
//   [ quantidade ][ contato 0 ][ contato 1 ][ contato 2 ] ...
//
// As funções criar e listar estão prontas. Complete adicionar: abra com
// "rb+", leia a quantidade, vá até a posição do novo contato, grave-o, some
// 1 na quantidade e regrave o cabeçalho no começo do arquivo. Devolva 1 se
// deu certo e 0 se não.
//
//   Saída esperada:
//   3 contatos (arquivo de 76 bytes)
//   0. Marta       (11) 98888-1234
//   1. Joel        (21) 97777-4321
//   2. Iara        (31) 96666-0000
//
// Dicas:
// 1. O contato i começa em sizeof(int) + i * sizeof(Contato).
// 2. Para regravar o cabeçalho: rewind(arq) e fwrite(&quantidade, ...).
// 3. sizeof(Contato) = 16 + 8 = 24 bytes; 4 + 3 * 24 = 76.
// 4. Resposta esperada: a saída acima.
//
// Escreva sua resposta abaixo (complete onde está o TODO):

#include <stdio.h>
#include <string.h>

typedef struct {
    char nome[8];
    char telefone[16];
} Contato;

const char *CAMINHO = "/tmp/agenda.bin";

int criar(void) {
    FILE *arq = fopen(CAMINHO, "wb");
    if (arq == NULL) {
        perror(CAMINHO);
        return 0;
    }
    int zero = 0;
    fwrite(&zero, sizeof zero, 1, arq); // agenda vazia: só o cabeçalho
    fclose(arq);
    return 1;
}

int adicionar(const char *nome, const char *telefone) {
    Contato c = {{0}, {0}};
    strncpy(c.nome, nome, sizeof c.nome - 1);
    strncpy(c.telefone, telefone, sizeof c.telefone - 1);

    // TODO: abrir com "rb+", ler a quantidade, fseek até a vaga,
    //       gravar c, atualizar o cabeçalho, fechar
    return 0;
}

void listar(void) {
    FILE *arq = fopen(CAMINHO, "rb");
    if (arq == NULL) {
        perror(CAMINHO);
        return;
    }
    int quantidade;
    if (fread(&quantidade, sizeof quantidade, 1, arq) != 1) {
        fclose(arq);
        return;
    }
    fseek(arq, 0, SEEK_END);
    printf("%d contatos (arquivo de %ld bytes)\n", quantidade, ftell(arq));
    fseek(arq, sizeof(int), SEEK_SET);
    Contato c;
    for (int i = 0; i < quantidade && fread(&c, sizeof c, 1, arq) == 1; i++) {
        printf("%d. %-11s %s\n", i, c.nome, c.telefone);
    }
    fclose(arq);
}

int main(void) {
    if (!criar()) {
        return 1;
    }
    adicionar("Marta", "(11) 98888-1234");
    adicionar("Joel", "(21) 97777-4321");
    adicionar("Iara", "(31) 96666-0000");
    listar();
    remove(CAMINHO);
    return 0;
}
