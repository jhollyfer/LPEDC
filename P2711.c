// Lista · Módulo 27 · Detalhes de C que caem em prova
// Exercício P2711 · ★★☆ · O estoque que não fica negativo
//
// Com typedef struct { char nome[20]; unsigned qtd; double preco; } Produto;,
// escreva:
//
//   bool vender(Produto *p, unsigned q)  // recusa se não houver q unidades
//   double valor_estoque(const Produto v[], int n)
//
// Como qtd é unsigned, uma venda maior que o estoque daria a volta para um
// número enorme: vender tem que conferir ANTES de subtrair. Estoque inicial:
// café (10 a R$ 18.00), açúcar (4 a R$ 5.50), leite (12 a R$ 6.00). Venda 3
// cafés, 5 açúcares e 12 leites.
//
//   Saída esperada:
//   vender 3 café: ok
//   vender 5 açúcar: recusada (só 4)
//   vender 12 leite: ok
//   café: 7, açúcar: 4, leite: 0
//   valor em estoque: R$ 148.00
//
// Dicas:
// 1. if (q > p->qtd) return false; e só depois p->qtd -= q.
// 2. O valor é a soma de qtd * preco: 7 * 18 + 4 * 5.5 + 0 * 6.
// 3. Resposta esperada: a saída acima.
//
// Escreva sua resposta abaixo:

#include <stdbool.h>
#include <stdio.h>

int main(void) {

    return 0;
}
