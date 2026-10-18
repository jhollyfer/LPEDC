// 0164 · Listas autoajustáveis
// Exercício E980 · ★☆☆
//
// O controle remoto guarda os canais num vetor e procura do começo para o
// fim. Escreva acessa(v, n, canal), que procura o canal, leva ele para a
// posição 0 (os que estavam antes andam uma casa para trás) e devolve
// quantas comparações fez. No main, acesse os canais 9, 4, 9, 13 e 9 e
// mostre o vetor depois de cada acesso.
//
//   Saída esperada:
//   canal  9 (custo 5): 9 2 4 5 7 11 13
//   canal  4 (custo 3): 4 9 2 5 7 11 13
//   canal  9 (custo 2): 9 4 2 5 7 11 13
//   canal 13 (custo 7): 13 9 4 2 5 7 11
//   canal  9 (custo 2): 9 13 4 2 5 7 11
//
// Dicas:
// 1. Ache a posição i do canal. Guarde v[i] numa variável, faça
//    v[j] = v[j - 1] com j de i até 1 e coloque o guardado em v[0].
// 2. O custo é i + 1. Pode supor que o canal existe.
// 3. Resposta esperada: a saída acima (use %2d para o número do canal).
//
// Escreva sua resposta abaixo:

#include <stdio.h>

int main(void) {
    int canais[] = {2, 4, 5, 7, 9, 11, 13};
    int n = 7;
    (void)canais; // apague estas duas linhas
    (void)n;

    return 0;
}
