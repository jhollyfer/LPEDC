// 0036 · Juntando tudo: o caixa da lanchonete
// Exercício E216 · ★★★
//
// O entregador sai da esquina (0, 0) e vai até (colunas, linhas) numa cidade em
// grade, andando só para a direita ou para baixo. Quantos caminhos diferentes
// existem? Para chegar a (c, l), o último passo veio de (c - 1, l) ou de
// (c, l - 1); quem está na borda (c == 0 ou l == 0) tem um caminho só.
//
// Escreva "long long caminhos(int c, int l)", recursiva, que também conta as
// próprias chamadas numa global. Mostre para 2 x 2, 3 x 3, 5 x 5 e 12 x 12.
//
//   Saída esperada:
//   2 x 2: 6 caminhos (11 chamadas)
//   3 x 3: 20 caminhos (39 chamadas)
//   5 x 5: 252 caminhos (503 chamadas)
//   12 x 12: 2704156 caminhos (5408311 chamadas)
//
// Responda num comentário: por que o número de chamadas é quase o dobro do
// resultado? O que se repete, como no Fibonacci?
//
// Dicas:
// 1. Caso base: if (c == 0 || l == 0) return 1;
// 2. Cada chamada que não é borda gera duas. As folhas da árvore de chamadas
//    são as bordas, e cada folha devolve 1: o resultado é o número de folhas.
// 3. Resposta esperada: a saída acima. Uma árvore em que todo nó interno tem
//    dois filhos tem (folhas - 1) nós internos, então chamadas = 2 * caminhos
//    - 1. As mesmas esquinas são recalculadas muitas vezes; guardar as
//    respostas numa tabela (memoização) resolve, e isso pede vetores, o
//    assunto do próximo módulo.
//
// Escreva sua resposta abaixo:

#include <stdio.h>

int main(void) {

    return 0;
}
