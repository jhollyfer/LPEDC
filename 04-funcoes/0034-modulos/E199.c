// 0034 · Módulos: .h, .c e compilação separada
// Exercício E199 · ★☆☆
//
// Monte o módulo "frete" num arquivo só, com cada peça no bloco certo. Os
// três blocos já estão marcados no esqueleto: "// frete.h" (o que o módulo
// oferece), "// main.c" (quem usa) e "// frete.c" (como ele faz).
//
//   no frete.h:  o include guard (#ifndef FRETE_H / #define FRETE_H / #endif),
//                #define FRETE_GRATIS_ACIMA 200.0 e o protótipo
//                double calcular_frete(double valor_compra, double peso_kg,
//                                      int distancia_km);
//   no frete.c:  static double taxa_por_km(int distancia_km), que devolve
//                0.20 por km, e o corpo de calcular_frete
//   no main.c:   o main
//
// O frete é grátis quando a compra chega a FRETE_GRATIS_ACIMA; senão, é
// R$ 10.00 + R$ 1.50 por kg + a taxa por km. Calcule três pedidos.
//
//   Saída esperada:
//   Pedido 1 (R$ 150.00, 2.0 kg, 30 km): frete R$ 19.00
//   Pedido 2 (R$ 250.00, 5.0 kg, 100 km): frete R$ 0.00
//   Pedido 3 (R$ 80.00, 1.0 kg, 12 km): frete R$ 13.90
//
// Dicas:
// 1. O .h diz O QUE o módulo oferece; o .c diz COMO. A taxa_por_km é
//    static: quem usa o módulo nem sabe que ela existe.
// 2. Para não repetir o printf três vezes, escreva no main.c uma função
//    void mostrar_pedido(int numero, double valor, double peso, int km).
// 3. Resposta esperada: 10 + 3 + 6 = 19.00; 250 >= 200, frete grátis;
//    10 + 1.50 + 2.40 = 13.90.
//
// Escreva sua resposta abaixo:

#include <stdio.h>

// frete.h


// main.c
int main(void) {

    return 0;
}

// frete.c
