// A005 · O mesmo byte lido de dois jeitos

#include <stdio.h>
#include <stdint.h>

int main(void) {
    // o freezer marca -10 °C e guarda a temperatura num byte com sinal
    int8_t freezer = -10;
    printf("Freezer: %d °C\n", freezer);

    // o painel recebe os MESMOS 8 bits, mas lê como byte sem sinal
    uint8_t byte_no_cabo = freezer;
    printf("No cabo: 0x%X, que sem sinal vale %d\n", byte_no_cabo, byte_no_cabo);

    // a faixa de cada um: 256 combinações nos dois, deslocadas
    printf("int8_t:  %d a %d\n", INT8_MIN, INT8_MAX);
    printf("uint8_t: 0 a %d\n", UINT8_MAX);

    // -10 e 246 completam juntos 256 (2 elevado a 8)
    printf("%d + %d = %d\n", byte_no_cabo, 10, byte_no_cabo + 10);
    return 0;
}
// Saída:
// Freezer: -10 °C
// No cabo: 0xF6, que sem sinal vale 246
// int8_t:  -128 a 127
// uint8_t: 0 a 255
// 246 + 10 = 256
//
// Os bits são 1111 0110 nos dois casos. O tipo decide se o bit de cima
// vale +128 (sem sinal: 246) ou -128 (com sinal: -128 + 118 = -10).
