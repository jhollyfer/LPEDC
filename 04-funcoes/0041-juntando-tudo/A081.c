// A081 · O caixa da lanchonete

#include <math.h>
#include <stdio.h>

#include "cardapio.h"

#define TAXA_SERVICO 10 // por cento

// lê um código de 0 a 4; insiste até vir um válido
int ler_codigo(void) {
    int codigo;
    int lidos;
    do {
        printf("Código (0 fecha): ");
        lidos = scanf("%d", &codigo);
        if (lidos != 1) {
            return 0; // entrada acabou ou não é número: fecha a conta
        }
    } while (codigo < 0 || codigo > 4);
    return codigo;
}

// a nota seguinte, da maior para a menor (em centavos)
int proxima_nota(int nota) {
    switch (nota) {
    case 10000: return 5000;
    case 5000: return 2000;
    case 2000: return 1000;
    case 1000: return 500;
    case 500: return 200;
    case 200: return 100;
    case 100: return 50;
    case 50: return 25;
    case 25: return 10;
    case 10: return 5;
    default: return 1;
    }
}

// recursão: dá uma nota e resolve o troco que sobrou
void dar_troco(int centavos, int nota) {
    if (centavos == 0) {
        return; // caso base: troco completo
    }
    if (centavos >= nota) {
        printf("  %d.%02d\n", nota / 100, nota % 100);
        dar_troco(centavos - nota, nota);
    } else {
        dar_troco(centavos, proxima_nota(nota));
    }
}

int main(void) {
    int total = 0;

    mostrar_cardapio();
    for (int codigo = ler_codigo(); codigo != 0; codigo = ler_codigo()) {
        total += preco_centavos(codigo);
        mostrar_item(codigo);
        printf(" adicionado\n");
    }

    int servico = total * TAXA_SERVICO / 100;
    int conta = total + servico;
    printf("%d itens, conta com serviço: R$ %d.%02d\n",
           itens_vendidos(), conta / 100, conta % 100);

    double pago;
    printf("Valor pago: ");
    if (scanf("%lf", &pago) != 1) {
        return 0;
    }
    int troco = (int)lround(pago * 100) - conta;
    if (troco < 0) {
        printf("Faltam R$ %d.%02d\n", -troco / 100, -troco % 100);
        return 0;
    }
    printf("Troco: R$ %d.%02d\n", troco / 100, troco % 100);
    dar_troco(troco, 10000);
    return 0;
}
// Exemplo de uso (o que você digita vem depois dos dois-pontos):
// 1 X-salada   R$ 18.50
// 2 Batata     R$ 12.00
// 3 Suco       R$  7.90
// 4 Açaí       R$ 15.00
// Código (0 fecha): 1
// X-salada adicionado
// Código (0 fecha): 2
// Batata adicionado
// Código (0 fecha): 3
// Suco adicionado
// Código (0 fecha): 9
// Código (0 fecha): 0
// 3 itens, conta com serviço: R$ 42.24
// Valor pago: 50
// Troco: R$ 7.76
//   5.00
//   2.00
//   0.50
//   0.25
//   0.01
// Para testar sem digitar: printf '1\n2\n3\n9\n0\n50\n' | ~/LPEDC/rodar 04-funcoes/0041-juntando-tudo/A081.c
