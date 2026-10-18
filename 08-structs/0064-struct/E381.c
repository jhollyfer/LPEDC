// 0064 · Struct
// Exercício E381 · ★★☆
//
// Um terreno retangular é descrito por dois cantos: o inferior esquerdo
// (2, 1) e o superior direito (10, 6), em metros. Crie uma struct ponto
// (x e y, double) e uma struct retangulo com dois campos struct ponto. Escreva
// funções que recebem o retângulo e devolvem a área e o perímetro, e uma que
// diz se um ponto (uma árvore, por exemplo) está dentro do terreno.
//
//   Saída esperada:
//   Largura: 8.0 m, altura: 5.0 m
//   Área: 40.0 m2
//   Perímetro: 26.0 m
//   Árvore em (4.0, 3.0): dentro
//   Árvore em (11.0, 2.0): fora
//
// Dicas:
// 1. Uma função recebe uma struct como qualquer outro parâmetro:
//    double area(struct retangulo r). Ela recebe uma cópia.
// 2. Acesso encadeado: r.inf_esq.x, r.sup_dir.y.
// 3. Dentro: x entre os dois x E y entre os dois y (use bool, de stdbool.h).
// 4. Resposta esperada: a saída acima.
//
// Escreva sua resposta abaixo:

#include <stdbool.h>
#include <stdio.h>

int main(void) {

    return 0;
}
