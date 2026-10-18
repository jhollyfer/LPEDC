// A072 · A mesma função volta para lugares diferentes

#include <stdio.h>

void recuo(int nivel) {
    for (int i = 0; i < nivel; i++) {
        printf("  ");
    }
}

void validar_cartao(int nivel) {
    recuo(nivel);
    printf("validar_cartao (topo da pilha)\n");
}

void pagar(int nivel) {
    recuo(nivel);
    printf("entra pagar\n");
    validar_cartao(nivel + 1); // volta para cá...
    recuo(nivel);
    printf("sai pagar\n");
}

void cadastrar(int nivel) {
    recuo(nivel);
    printf("entra cadastrar\n");
    validar_cartao(nivel + 1); // ...e, desta vez, para cá
    recuo(nivel);
    printf("sai cadastrar\n");
}

int main(void) {
    printf("main\n");
    cadastrar(1);
    pagar(1);
    printf("main termina\n");
    return 0;
}
// Saída:
// main
//   entra cadastrar
//     validar_cartao (topo da pilha)
//   sai cadastrar
//   entra pagar
//     validar_cartao (topo da pilha)
//   sai pagar
// main termina
