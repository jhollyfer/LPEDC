// 0036 · Juntando tudo: o caixa da lanchonete
// Exercício E216 · ★★★
//
// O entregador sai da esquina (0, 0) e vai até (colunas, linhas) numa cidade em
// grade, andando só para a direita ou para baixo. Quantos caminhos diferentes
// existem? Para chegar a (c, l), o último passo veio de (c - 1, l) ou de
// (c, l - 1); quem está na borda (c == 0 ou l == 0) tem um caminho só.
//
// Escreva "long long caminhos(int c, int l)", recursiva, que também conta as
// próprias chamadas numa global. Para medir o desperdício, use uma segunda
// global que conta quantas vezes a mesma esquina (1, 1) é calculada. Escreva
// também "void mostrar(int n)", que zera as globais, resolve n x n e mostra a
// linha, com "confere" quando chamadas == 2 * caminhos - 1 (e "não confere"
// se não). Mostre para 2 x 2, 3 x 3, 5 x 5 e 12 x 12.
//
//   Saída esperada:
//   2 x 2: 6 caminhos, 11 chamadas (confere), esquina (1, 1): 2 vezes
//   3 x 3: 20 caminhos, 39 chamadas (confere), esquina (1, 1): 6 vezes
//   5 x 5: 252 caminhos, 503 chamadas (confere), esquina (1, 1): 70 vezes
//   12 x 12: 2704156 caminhos, 5408311 chamadas (confere), esquina (1, 1): 705432 vezes
//
// Dicas:
// 1. Caso base: if (c == 0 || l == 0) return 1; antes dele, conte a chamada
//    e, se c == 1 && l == 1, conte a esquina.
// 2. Cada chamada que não é borda gera duas. As folhas da árvore de chamadas
//    são as bordas, e cada folha devolve 1: o resultado é o número de folhas.
//    Uma árvore em que todo nó interno tem dois filhos tem (folhas - 1) nós
//    internos, então chamadas = 2 * caminhos - 1.
// 3. Resposta esperada: a saída acima. A esquina (1, 1) é recalculada por
//    cada caminho que passa por ela, como fib(2) dentro do fib(6). Guardar as
//    respostas numa tabela (memoização) resolve, e isso pede vetores, o
//    assunto do próximo módulo.
//
// Escreva sua resposta abaixo:

#include <stdio.h>

int main(void) {

    return 0;
}
