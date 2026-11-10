// Lista · Módulo 15 · Tabelas hash
// Exercício P1511 · ★★☆ · A lápide que segura a busca
//
// Os escaninhos da biblioteca usam endereçamento aberto com m = 7, sondagem
// linear e h(k) = k % 7. VAZIO = -1 e LAPIDE = -2 (a marca DELETED do
// Cormen). Escreva:
//
//   int busca(const int t[], int k)     passa reto pela lápide, para no VAZIO
//   void insere(int t[], int k)         ocupa o primeiro VAZIO ou LAPIDE
//   void remove_chave(int t[], int k, int marca)   troca k por marca
//   void mostra(const char *rotulo, const int t[])  _ vazio, X lápide
//
// Monte DUAS tabelas iguais com 10, 17, 24, 5, 12. Remova o 17 de uma
// marcando VAZIO e da outra marcando LAPIDE, procure o 24 nas duas e, na
// tabela com lápide, insira o 31. Os rótulos têm 11 colunas ("início:    ",
// "sem lápide:", ...) e mostra imprime cada posição com um espaço antes.
//
//   Saída esperada:
//   início:     12 _ _ 10 17 24 5
//   sem lápide: 12 _ _ 10 _ 24 5
//   com lápide: 12 _ _ 10 X 24 5
//   busca 24 sem lápide: -1
//   busca 24 com lápide: 5
//   entra o 31: 12 _ _ 10 31 24 5
//
// Dicas:
// 1. O 10, o 17 e o 24 têm h = 3: o 24 só chegou à posição 5 passando pela
//    4. Se a 4 vira VAZIO, a busca pelo 24 para ali e desiste.
// 2. A lápide não é igual a chave nenhuma (as chaves são positivas), então
//    a busca nem precisa tratá-la à parte: só o VAZIO encerra.
// 3. O 31 também tem h = 3 e reaproveita a lápide da posição 4.
// 4. Resposta esperada: a saída acima.
//
// Escreva sua resposta abaixo:

#include <stdio.h>

#define M 7
#define VAZIO -1
#define LAPIDE -2

int main(void) {

    return 0;
}
