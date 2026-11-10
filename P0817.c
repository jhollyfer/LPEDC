// Lista · Módulo 08 · Tipos compostos
// Exercício P0817 · ★★☆ · Conserte a promoção da vitrine
//
// O programa abaixo deveria dar 15% de desconto em todos os produtos da
// vitrine e mostrar o total. Ele tem DOIS erros de propósito: um faz a
// promoção não chegar nos produtos (o programa roda e mostra o preço
// antigo); o outro o AddressSanitizer acusa quando roda. O gcc não avisa de
// nenhum. Conserte os dois. O programa deve mostrar:
//
//   Saída esperada:
//   Rede de dormir     R$ 102.00
//   Cuia pintada       R$  29.75
//   Colar de sementes  R$  40.80
//   Farinha 1 kg       R$  11.90
//   Total              R$ 184.45
//
// Dicas:
// 1. Produto p = v[i]; cria uma CÓPIA da struct. Mexer em p não mexe em
//    v[i]. Use um ponteiro: Produto *p = &v[i]; e p->preco.
// 2. p <= v + n passa uma casa do fim: v + n é o endereço logo depois do
//    último produto.
// 3. Resposta esperada: a saída acima.
//
// Escreva sua resposta abaixo:

#include <stdio.h>

typedef struct {
    char nome[20];
    double preco;
} Produto;

void promocao(Produto *v, int n) {
    for (int i = 0; i < n; i++) {
        Produto p = v[i];
        p.preco *= 0.85;
    }
}

double total(const Produto *v, int n) {
    double soma = 0;
    for (const Produto *p = v; p <= v + n; p++) {
        soma += p->preco;
    }
    return soma;
}

int main(void) {
    Produto vitrine[4] = {{"Rede de dormir", 120.00}, {"Cuia pintada", 35.00},
                          {"Colar de sementes", 48.00}, {"Farinha 1 kg", 14.00}};

    promocao(vitrine, 4);
    for (int i = 0; i < 4; i++) {
        printf("%-18s R$ %6.2f\n", vitrine[i].nome, vitrine[i].preco);
    }
    printf("%-18s R$ %6.2f\n", "Total", total(vitrine, 4));
    return 0;
}
