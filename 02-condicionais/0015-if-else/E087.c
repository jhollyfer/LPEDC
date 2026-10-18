// 0015 · if/else e o = no lugar do ==
// Exercício E087 · ★★☆
//
// O caixa eletrônico bloqueia o cartão na 3ª senha errada. Mas este programa
// bloqueia logo na primeira! Rode com 1, leia o aviso do compilador e repare
// nos DOIS estragos que o erro causa (a mensagem e a última linha).
// Conserte e rode de novo com 1 e com 3.
//
// Dicas:
// 1. Compare o "Tentativas registradas" com o número que você digitou.
// 2. Quantos sinais de igual tem a condição do if?
// 3. Resposta esperada: "tentativas = 3" guarda 3 na variável (estrago 1)
//    e o if testa esse 3, que é sempre verdade (estrago 2). Com ==, a
//    entrada 1 mostra "Senha errada. Restam 2 tentativa(s)." e
//    "Tentativas registradas: 1"; a entrada 3 mostra "Cartão bloqueado.".
//
// Escreva sua resposta abaixo (conserte o código):

#include <stdio.h>

int main(void) {
    int tentativas;
    printf("Senhas erradas até agora: ");
    if (scanf("%d", &tentativas) != 1) {
        printf("Entrada inválida\n");
        return 1;
    }

    if (tentativas = 3) {
        printf("Cartão bloqueado.\n");
    } else {
        printf("Senha errada. Restam %d tentativa(s).\n", 3 - tentativas);
    }
    printf("Tentativas registradas: %d\n", tentativas);
    return 0;
}
