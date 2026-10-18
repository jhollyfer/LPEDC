// 0013 · Lógicos: E, OU, NÃO
// Exercício E077 · ★★★
//
// O app do banco mostra se o gasto médio por dia passou de R$ 100. Com uma
// conta nova, sem nenhum dia registrado, o programa abaixo quebra: o
// sanitizer acusa "division by zero". Rode com 900 0 e veja o erro. Depois:
// (a) conserte a linha do gasto_alto usando o curto-circuito do &&, sem if;
// (b) complete a linha do alerta, que deve ser verdade quando não há dias
// registrados OU quando o gasto é alto. Ela também não pode dividir por zero.
//
//   Gasto total e dias: 900 6
//   Gasto alto? 1
//   Alerta? 1
//
// Dicas:
// 1. No &&, se o lado esquerdo é falso, o direito nem é calculado. Ponha a
//    pergunta que protege (dias != 0) na frente da divisão.
// 2. No ||, se o lado esquerdo é verdade, o direito é pulado: comece com
//    dias == 0.
// 3. Resposta esperada: gasto_alto = dias != 0 && gasto / dias > 100;
//    alerta = dias == 0 || gasto / dias > 100. Testes: 900 6 → 1 e 1;
//    900 0 → 0 e 1 (sem erro); 300 5 → 0 e 0.
//
// Escreva sua resposta abaixo (conserte e complete o código):

#include <stdbool.h>
#include <stdio.h>

int main(void) {
    int gasto = 0, dias = 0;
    printf("Gasto total e dias: ");
    scanf("%d %d", &gasto, &dias);

    bool gasto_alto = gasto / dias > 100 && dias != 0;
    bool alerta = false; // complete: sem dias OU gasto alto

    printf("Gasto alto? %d\n", gasto_alto);
    printf("Alerta? %d\n", alerta);
    return 0;
}
