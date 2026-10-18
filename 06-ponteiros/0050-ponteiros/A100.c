// A100 · Gasolina ou etanol?

#include <stdio.h>

int main(void) {
    float gasolina = 5.89f, etanol = 4.29f;
    float *escolha = &gasolina; // começa apontando para a gasolina

    // regra dos 70%: se o etanol custa até 70% da gasolina, compensa
    if (etanol / gasolina <= 0.7f) {
        escolha = &etanol;      // o ponteiro muda de alvo; as variáveis, não
    }
    printf("Escolhido: R$ %.2f o litro\n", *escolha);
    printf("Com R$ 100 dá %.1f litros\n", 100.0f / *escolha);

    etanol = 3.99f;            // baixou: 3.99 / 5.89 = 0.68, agora compensa
    if (etanol / gasolina <= 0.7f) {
        escolha = &etanol;
    }
    printf("Escolhido: R$ %.2f o litro\n", *escolha);

    // o ponteiro tem o tamanho de um endereço; *escolha, o tamanho de um float
    printf("sizeof escolha = %zu, sizeof *escolha = %zu\n", sizeof escolha, sizeof *escolha);
    return 0;
}
// Saída:
// Escolhido: R$ 5.89 o litro
// Com R$ 100 dá 17.0 litros
// Escolhido: R$ 3.99 o litro
// sizeof escolha = 8, sizeof *escolha = 4
