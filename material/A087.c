// A087 · O valor muda, a gaveta não

#include <stdio.h>

int main(void) {
    double saldo = 250.00; // saldo da conta, antes dos Pix do dia

    printf("saldo = %7.2f, mora em %p\n", saldo, (void *)&saldo);

    saldo -= 89.90; // Pix para a conta de luz
    printf("saldo = %7.2f, mora em %p\n", saldo, (void *)&saldo);

    saldo += 1200.00; // salário caiu
    printf("saldo = %7.2f, mora em %p\n", saldo, (void *)&saldo);

    // atribuir troca o conteúdo da gaveta; o endereço fica o mesmo até o fim
    // do programa
    double reserva = saldo; // cópia do valor: outra gaveta, mesmo conteúdo
    printf("reserva = %7.2f, mora em %p\n", reserva, (void *)&reserva);
    // endereços também se comparam com ==
    printf("mesmo valor? %d  mesma gaveta? %d\n", reserva == saldo,
           &reserva == &saldo);
    return 0;
}
// Saída (os endereços mudam a cada execução, mas se repetem dentro dela):
// saldo =  250.00, mora em 0x7f8a1c500020
// saldo =  160.10, mora em 0x7f8a1c500020
// saldo = 1360.10, mora em 0x7f8a1c500020
// reserva = 1360.10, mora em 0x7f8a1c500040
// mesmo valor? 1  mesma gaveta? 0
