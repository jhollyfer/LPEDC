// A080 · Modo depuração com #ifdef

#include <stdio.h>

#define DEPURAR // apague esta linha e os [debug] somem do programa

#ifdef DEPURAR
#define LOG(msg) printf("[debug] %s, linha %d: %s\n", __func__, __LINE__, msg)
#else
#define LOG(msg) // vira nada
#endif

#define MOSTRAR(expr) printf(#expr " = %d\n", (expr)) // # vira texto

int parcelas(int total, int valor_parcela) {
    LOG("calculando");
    return (total + valor_parcela - 1) / valor_parcela; // arredonda para cima
}

int main(void) {
    LOG("começou");
    MOSTRAR(parcelas(1000, 300));
    MOSTRAR(7 * 6);
    return 0;
}
// Saída:
// [debug] main, linha 21: começou
// [debug] parcelas, linha 16: calculando
// parcelas(1000, 300) = 4
// 7 * 6 = 42
