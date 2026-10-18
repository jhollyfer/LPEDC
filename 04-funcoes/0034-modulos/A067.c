// A067 · O .h incluído duas vezes e o protótipo que converte

#include <stdio.h>

#include "conversao.h"
#include "conversao.h" // de propósito: o include guard faz esta virar nada

int main(void) {
    int trecho = 42;      // int
    int orcamento = 2700; // int

    // o protótipo do .h diz que os parâmetros são double:
    // o compilador converte 42 em 42.0 antes de chamar
    printf("Maratona: %d km = %.1f milhas\n", trecho, km_para_milhas(trecho));
    printf("Orçamento: R$ %d = US$ %.2f\n", orcamento,
           reais_para_dolares(orcamento, 5.40));

    // a função do módulo vira peça de uma conta maior
    double ida_e_volta = 2 * km_para_milhas(trecho);
    printf("Ida e volta: %.1f milhas\n", ida_e_volta);
    printf("Conversões feitas: %d\n", conversoes_feitas());
    return 0;
}
// Para ver o guard trabalhando: gcc -E A067.c | grep -c km_para_milhas
// dá 3: o protótipo aparece uma vez só, mais as duas linhas do main.
// Saída:
// Maratona: 42 km = 26.1 milhas
// Orçamento: R$ 2700 = US$ 500.00
// Ida e volta: 52.2 milhas
// Conversões feitas: 3
