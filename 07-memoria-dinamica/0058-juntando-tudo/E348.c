// 0058 · Juntando tudo
// Exercício E348 · ★★★
//
// Escreva a função
//
//   char **dividir(const char *texto, char separador, int *qtd);
//
// que quebra o texto em pedaços pelo separador e devolve um vetor NOVO de
// strings NOVAS, cada uma do tamanho exato.
// A quantidade volta por *qtd. Teste com a lista do mercado
// "arroz;feijao;cafe;oleo de soja" e com ";;", que tem 3 pedaços vazios.
//
//   Saída esperada:
//   4 itens: [arroz] [feijao] [cafe] [oleo de soja]
//   3 itens: [] [] []
//
// Dicas:
// 1. Primeira passada: conte os separadores. São separadores + 1 pedaços.
// 2. Segunda passada: para cada pedaço, ache o início e o tamanho, faça o
//    malloc(tamanho + 1), copie os chars e ponha o '\0'. Pedaço vazio é um
//    bloco de 1 byte só com o '\0'.
// 3. Resposta esperada: a saída acima. Escreva também liberar_pedacos(v, n)
//    e chame para os dois resultados. Se um malloc falhar no meio, libere o
//    que já foi feito e devolva NULL.
//
// Escreva sua resposta abaixo:

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {

    return 0;
}
