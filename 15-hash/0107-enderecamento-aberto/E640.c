// 0107 · Endereçamento aberto
// Exercício E640 · ★★☆
//
// Uma tabela com endereçamento aberto enche. Escreva "int insere(int tab[],
// int chave)" para uma tabela de 5 posições (-1 = livre, h = k % 5,
// sondagem linear) que devolve a posição usada ou -1 se a tabela estiver
// cheia, sem nunca entrar em laço infinito. Insira 12, 7, 3, 9, 15 e 20 e
// mostre a posição e o fator de carga depois de cada inserção.
//
//   Saída esperada:
//   12 -> 2 (carga 0.20)
//   7 -> 3 (carga 0.40)
//   3 -> 4 (carga 0.60)
//   9 -> 0 (carga 0.80)
//   15 -> 1 (carga 1.00)
//   20: tabela cheia!
//
// Dicas:
// 1. Um "while (tab[i] != -1)" sozinho roda para sempre numa tabela cheia.
// 2. Limite as tentativas: um for de no máximo 5 passos. Se nenhum passo
//    achou vaga livre, devolva -1.
// 3. Resposta esperada: a saída acima. Repare que o 9 e o 15 só entram
//    dando a volta no fim do vetor.
//
// Escreva sua resposta abaixo:

#include <stdio.h>

int main(void) {

    return 0;
}
