// 0026 · Do-while
// Exercício E154 · ★★☆
//
// O totem do cinema oferece 3 sessões e deveria repetir a pergunta enquanto a
// opção fosse inválida. Mas, rodando com
//
//   printf '7\n2\n' | ~/LPEDC/rodar 03-repeticoes/0026-do-while/E154.c
//
// ele aceita o 7 de primeira. O código com o erro está logo abaixo. Ache o
// erro, explique por que ele nunca repete e conserte.
//
// Dicas:
// 1. Existe algum número que é, ao mesmo tempo, menor que 1 e maior que 3?
// 2. Releia a lei de De Morgan (assunto 0018): o contrário de
//    "opcao >= 1 && opcao <= 3" é...
// 3. Resposta esperada: a condição "opcao < 1 && opcao > 3" é sempre falsa,
//    então o laço nunca repete. O certo é "opcao < 1 || opcao > 3". Com 7 e
//    2, o totem pergunta duas vezes e mostra "Sessão 2 escolhida.".
//
// Escreva sua resposta abaixo (conserte o código):

#include <stdio.h>

int main(void) {
    int opcao;

    do {
        printf("Sessão (1, 2 ou 3): ");
        if (scanf("%d", &opcao) != 1) {
            return 1;
        }
    } while (opcao < 1 && opcao > 3);

    printf("Sessão %d escolhida.\n", opcao);
    return 0;
}
