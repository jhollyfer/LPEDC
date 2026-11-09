// 0182 · Caminhos e ciclos
// Exercício E1090 · ★★☆
//
// O caminhão do gás roda num centro só de ruas de mão única. Os pontos são
// Depósito, Mercado, Praça, Hospital e Escola (0 a 4), e as ruas:
//
//   Depósito->Mercado, Mercado->Praça, Praça->Depósito,
//   Praça->Hospital, Hospital->Escola, Escola->Praça
//
// Escreva o programa: a função balanceado() mostra cada ponto em que o
// grau de entrada é diferente do de saída e devolve true se não houver
// nenhum; a função circuito(inicio) roda o Hierholzer DIRIGIDO e mostra o
// circuito. Depois, simule uma obra que inverte a rua Hospital->Escola
// (vira Escola->Hospital) e rode de novo.
//
//   Saída esperada:
//   Antes da obra:
//   Circuito: Depósito Mercado Praça Hospital Escola Praça Depósito
//   Depois da obra:
//   Hospital: entram 2, saem 0
//   Escola: entram 0, saem 2
//   Sem circuito
//
// Dicas:
// 1. No dirigido, a condição de Euler (com o grafo conexo) é: entrada igual
//    a saída em todo vértice. Saída de u é a linha u; entrada, a coluna u.
// 2. O Hierholzer é o do texto, mas apaga só mao[u][v]: a volta v -> u não
//    existe. Remonte a matriz antes da obra, porque o circuito apaga tudo.
// 3. Resposta esperada: a saída acima.
//
// Escreva sua resposta abaixo:

#include <stdbool.h>
#include <stdio.h>

int main(void) {

    return 0;
}
