// Lista · Módulo 09 · Arquivos e linha de comando
// Exercício P0924 · ★★★ · Os produtos entre R$ 10 e R$ 20
//
// O arquivo binário do mercadinho tem 10 produtos ORDENADOS por preço (em
// centavos, para não ter erro de arredondamento):
//
//   299 Agua, 450 Pao, 699 Leite, 899 Biscoito, 1050 Cafe, 1290 Queijo,
//   1599 Mel, 1890 Manteiga, 2100 Sabao, 3490 Azeite
//
// Para listar os que custam de R$ 10,00 a R$ 20,00 sem ler o arquivo todo,
// faça uma busca binária que acha a POSIÇÃO do primeiro produto com preço
// >= 1000 e, de lá, leia em sequência enquanto o preço for <= 2000. Escreva
//
//   long primeiro_maior_igual(FILE *arq, long n, int alvo, int *leituras)
//
// que devolve a primeira posição com preço >= alvo (ou n, se não houver) e
// conta os fread da busca. Grave o arquivo em /tmp/p0924_precos.bin no
// próprio programa e apague-o no fim.
//
//   Saída esperada:
//   Busca: 4 leituras, primeiro na posição 4
//   R$ 10.50 Cafe
//   R$ 12.90 Queijo
//   R$ 15.99 Mel
//   R$ 18.90 Manteiga
//   4 produtos na faixa
//
// Dicas:
// 1. Use o intervalo meio aberto [ini, fim) com ini = 0 e fim = n. Se o
//    preço do meio é >= alvo, a resposta está em [ini, meio]: fim = meio.
//    Senão, ini = meio + 1. Pare quando ini == fim; a resposta é ini.
// 2. Essa busca nunca para "porque achou": ela sempre estreita até sobrar
//    uma posição, por isso funciona até se nenhum produto custar 1000 exato.
// 3. Resposta esperada: a saída acima (meios lidos: 5, 2, 4 e 3).
//
// Escreva sua resposta abaixo:

#include <stdio.h>

typedef struct {
    int preco; // em centavos
    char nome[20];
} Produto;

int main(void) {

    return 0;
}
