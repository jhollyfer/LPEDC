// A025 · Dentro, fora e "só um dos dois"

#include <stdbool.h>
#include <stdio.h>

int main(void) {
    int hora = 22;

    // dentro da faixa: um E de duas comparações
    bool comercial = hora >= 8 && hora < 18;
    // fora da faixa: um OU. É o NÃO do de cima, aberto por De Morgan:
    // !(hora >= 8 && hora < 18) vira hora < 8 || hora >= 18
    bool fora = hora < 8 || hora >= 18;
    printf("Horário comercial? %d\n", comercial);
    printf("Fora do horário?   %d\n", fora);

    // o C não tem um "OU exclusivo" lógico, mas com bool o != faz o papel:
    // verdade quando exatamente um dos dois é verdade
    bool cupom = true;
    bool primeira_compra = true;
    bool um_desconto_so = cupom != primeira_compra;
    bool algum_desconto = cupom || primeira_compra;
    printf("Algum desconto?    %d\n", algum_desconto);
    printf("Só um desconto?    %d\n", um_desconto_so);
    return 0;
}
// Saída:
// Horário comercial? 0
// Fora do horário?   1
// Algum desconto?    1
// Só um desconto?    0
