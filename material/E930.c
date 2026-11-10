// 0155 · Floyd-Warshall: todos os pares
// Exercício E930 · ★★★
//
// Cinco bairros (índices 0 a 4: Centro, Porto, Vila, Alto e Feira) têm estas
// ruas de mão única, em minutos:
//
//   Centro -> Vila 2   Vila -> Porto 3   Centro -> Porto 6   Porto -> Alto 4
//   Alto -> Centro 5   Vila -> Feira 7   Feira -> Alto 1     Porto -> Feira 2
//
// Calcule a tabela com o Floyd-Warshall. Depois a prefeitura abre a rua Feira
// -> Vila, de 1 minuto. Refazer o Floyd custa O(V³): escreva nova_rua(d, a, b,
// w), que atualiza a tabela em O(V²). Qualquer caminho que melhora com a rua
// nova passa por ela uma vez só: "de i até a", mais w, mais "de b até j".
// Confira o resultado contra um Floyd completo refeito do zero, mostrando a
// tabela (nome com %-7s e cada número com %4d).
//
//   Saída esperada:
//   Centro    0   5   2   8   7
//   Porto     8   0   3   3   2
//   Vila     11   3   0   6   5
//   Alto      5  10   7   0  12
//   Feira     6   4   1   1   0
//   Confere com o Floyd completo: sim
//
// Escreva sua resposta abaixo:

#include <stdbool.h>
#include <stdio.h>

#define INFINITO 1000000000

int main(void) {

    return 0;
}
