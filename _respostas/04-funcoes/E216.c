// 0036 · A pilha de chamadas
// Exercício E216 · ★★★

#include <stdio.h>

int altura = 0;
int maior_altura = 0;

void entrar(void) {
    altura++;
    if (altura > maior_altura) {
        maior_altura = altura;
    }
}

void sair(void) {
    altura--;
}

void cupom(void) {
    entrar();
    sair();
}

void antifraude(void) {
    entrar();
    sair();
}

void pagamento(void) {
    entrar();
    antifraude();
    sair();
}

void checkout(void) {
    entrar();
    cupom();
    pagamento();
    sair();
}

void frete(void) {
    entrar();
    sair();
}

int main(void) {
    entrar();
    checkout();
    frete();
    printf("Maior altura: %d\n", maior_altura);
    printf("Altura agora: %d\n", altura);
    sair();
    return 0;
}
