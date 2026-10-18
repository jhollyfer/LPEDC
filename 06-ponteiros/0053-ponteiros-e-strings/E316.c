// 0053 · Ponteiros e strings
// Exercício E316 · ★★☆
//
// O programa da portaria tem TRÊS erros de propósito. Ele deveria mostrar:
//
//   Ola, visitante!
//   Bloco: B
//   Mesmo morador
//
// Rode com o rodar, leia o relatório e conserte. Explique cada erro.
//
// Dicas:
// 1. Onde mora o texto "ola, visitante!"? Dá para escrever lá?
// 2. Um ponteiro que nunca recebeu endereço não é lugar para strcpy.
// 3. == entre duas strings compara o quê?
// 4. Resposta esperada: (1) saudacao aponta para um literal (só leitura):
//    declare char saudacao[] = "ola, visitante!"; (2) bloco é um ponteiro
//    sem alvo: use char bloco[2]; (3) morador == "ana" compara endereços:
//    use strcmp(morador, "ana") == 0.
//
// Escreva sua resposta abaixo (conserte o código):

#include <stdio.h>
#include <string.h>

int main(void) {
    char *saudacao = "ola, visitante!";
    char *bloco;
    char morador[10] = "ana";

    saudacao[0] = 'O';
    printf("%s\n", saudacao);

    strcpy(bloco, "B");
    printf("Bloco: %s\n", bloco);

    if (morador == "ana") {
        printf("Mesmo morador\n");
    }
    return 0;
}
