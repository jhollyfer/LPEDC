// Lista · Módulo 25 · Estruturas especiais
// Exercício P2508 · ★☆☆ · Os mais pedidos da lanchonete
//
// O cardápio digital da lanchonete se reorganiza pela CONTAGEM: cada item
// guarda quantas vezes foi pedido e o vetor fica em ordem decrescente de
// pedidos. Escreva do zero pede(v, nome): acha o item, soma 1 e o faz
// subir, trocando com o da frente, enquanto tiver MAIS pedidos que ele (no
// empate, quem já estava na frente fica). Mostre o cardápio depois de cada
// pedido.
//
//   Cardápio inicial: misto coxinha pastel tapioca suco (todos com 0)
//   Pedidos: suco pastel suco coxinha pastel suco tapioca pastel pastel
//
//   Saída esperada:
//   suco     -> suco(1) misto(0) coxinha(0) pastel(0) tapioca(0)
//   pastel   -> suco(1) pastel(1) misto(0) coxinha(0) tapioca(0)
//   suco     -> suco(2) pastel(1) misto(0) coxinha(0) tapioca(0)
//   coxinha  -> suco(2) pastel(1) coxinha(1) misto(0) tapioca(0)
//   pastel   -> suco(2) pastel(2) coxinha(1) misto(0) tapioca(0)
//   suco     -> suco(3) pastel(2) coxinha(1) misto(0) tapioca(0)
//   tapioca  -> suco(3) pastel(2) coxinha(1) tapioca(1) misto(0)
//   pastel   -> suco(3) pastel(3) coxinha(1) tapioca(1) misto(0)
//   pastel   -> pastel(4) suco(3) coxinha(1) tapioca(1) misto(0)
//
// Dicas:
// 1. typedef struct { const char *nome; int pedidos; } Item;
// 2. A subida é um passo do insertion sort: troque v[i] com v[i - 1] e
//    faça i-- enquanto i > 0 e v[i].pedidos > v[i - 1].pedidos.
// 3. Resposta esperada: o pastel só passa o suco no último pedido (4 a 3).
//
// Escreva sua resposta abaixo:

#include <stdio.h>
#include <string.h>

int main(void) {

    return 0;
}
