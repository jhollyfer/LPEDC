// Lista · Módulo 25 · Estruturas especiais
// Exercício P2509 · ★☆☆ · A agenda que sobe um degrau
//
// A agenda do telefone fixo é uma lista encadeada simples e usa a
// TRANSPOSIÇÃO: o contato achado troca de lugar com o que estava logo
// antes dele. Escreva do zero:
// - poe_no_fim(nome), para montar a agenda inicial;
// - liga(nome), que procura do começo, troca o achado com o anterior
// (pode trocar só os nomes, sem mexer nos ponteiros) e devolve o custo;
// - mostra(), e no fim libere todos os nós.
//
//   Agenda inicial: Mãe Chefe Pizzaria Dentista Vizinho
//   Ligações: Vizinho Vizinho Pizzaria Vizinho Vizinho
//
//   Saída esperada:
//   Vizinho   custo 5: Mãe Chefe Pizzaria Vizinho Dentista
//   Vizinho   custo 4: Mãe Chefe Vizinho Pizzaria Dentista
//   Pizzaria  custo 4: Mãe Chefe Pizzaria Vizinho Dentista
//   Vizinho   custo 4: Mãe Chefe Vizinho Pizzaria Dentista
//   Vizinho   custo 3: Mãe Vizinho Chefe Pizzaria Dentista
//   Custo total: 20
//
// Dicas:
// 1. Guarde o nó anterior enquanto anda. Se o achado é o primeiro, não há
//    troca.
// 2. Repare na Pizzaria: uma ligação para ela desfez o degrau que o
//    Vizinho tinha subido. A transposição anda devagar e "briga" assim.
// 3. Resposta esperada: custo total 20; no fim, Mãe Vizinho Chefe
//    Pizzaria Dentista.
//
// Escreva sua resposta abaixo:

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {

    return 0;
}
