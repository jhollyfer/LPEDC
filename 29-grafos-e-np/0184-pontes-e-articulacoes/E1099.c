// 0184 · Pontes e articulações
// Exercício E1099 · ★☆☆
//
// As rodovias em volta de Manaus ligam seis cidades: Manaus, Iranduba,
// Manacapuru, Novo Airão, Rio Preto da Eva e Itacoatiara (0 a 5):
//
//   Manaus-Iranduba, Iranduba-Manacapuru, Manacapuru-Manaus,
//   Manacapuru-Novo Airão, Manaus-Rio Preto da Eva,
//   Rio Preto da Eva-Itacoatiara
//
// Escreva do zero a versão força bruta (como o A368): para achar as
// pontes, tire cada rodovia, conte os componentes e devolva a rodovia; para
// achar as articulações, "desligue" cada cidade e conte os componentes das
// outras.
//
//   Saída esperada:
//   Pontes:
//     Manacapuru - Novo Airão
//     Manaus - Rio Preto da Eva
//     Rio Preto da Eva - Itacoatiara
//   Articulações:
//     Manaus
//     Manacapuru
//     Rio Preto da Eva
//
// Dicas:
// 1. Escreva int componentes(int fora): uma DFS por recomeço, pulando o
//    vértice fora (use -1 para não pular nenhum).
// 2. Uma rodovia é ponte se, sem ela, componentes(-1) aumenta. Uma cidade
//    é articulação se componentes(cidade) é maior que o da rede inteira.
// 3. Resposta esperada: a saída acima. Iranduba não é articulação: o
//    triângulo com Manaus e Manacapuru dá outro caminho.
//
// Escreva sua resposta abaixo:

#include <stdbool.h>
#include <stdio.h>

int main(void) {

    return 0;
}
