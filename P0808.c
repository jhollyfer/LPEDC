// Lista · Módulo 08 · Tipos compostos
// Exercício P0808 · ★☆☆ · Conserte o cadastro do sócio
//
// O clube quer dar 20% de desconto na mensalidade dos sócios com mais de 10
// anos de casa. O programa abaixo tem DOIS erros de propósito: o gcc avisa de
// um (leia o warning); o outro é de lógica: o desconto é calculado, mas não
// chega no sócio. Conserte os dois. O programa deve mostrar:
//
//   Saída esperada:
//   Seu Lourival  23 anos: R$ 120.00
//   Kelly          4 anos: R$ 150.00
//   Dona Ivete    11 anos: R$ 96.00
//
// Dicas:
// 1. %d é para int; para double, %.2f. Um formato errado mostra lixo.
// 2. A função recebe uma CÓPIA da struct: mudar a cópia não muda o sócio do
//    main. Passe o endereço (Socio *) e use ->.
// 3. Resposta esperada: a saída acima.
//
// Escreva sua resposta abaixo:

#include <stdio.h>

typedef struct {
    char nome[20];
    int anos;
    double mensalidade;
} Socio;

void aplicar_desconto(Socio s) {
    if (s.anos > 10) {
        s.mensalidade *= 0.80;
    }
}

int main(void) {
    Socio socios[3] = {{"Seu Lourival", 23, 150.0}, {"Kelly", 4, 150.0},
                       {"Dona Ivete", 11, 120.0}};

    for (int i = 0; i < 3; i++) {
        aplicar_desconto(socios[i]);
        printf("%-13s %2d anos: R$ %d\n", socios[i].nome, socios[i].anos,
               socios[i].mensalidade);
    }
    return 0;
}
