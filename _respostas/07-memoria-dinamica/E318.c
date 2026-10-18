// 0053 · Pilha e heap
// Exercício E318 · ★★★
//
// O problema: montar_senha devolvia o endereço de um vetor local, que morre
// no return. O gcc avisa e devolve NULL no lugar (por isso aparecia
// "(null)"). Agora quem chama empresta o vetor, que mora no frame de main.

#include <stdio.h>

void montar_senha(int numero, char senha[]) {
    senha[0] = 'A';
    senha[1] = (char)('0' + numero / 100);
    senha[2] = (char)('0' + numero / 10 % 10);
    senha[3] = (char)('0' + numero % 10);
    senha[4] = '\0';
}

int main(void) {
    char senha[8];
    montar_senha(42, senha);
    printf("Senha: %s\n", senha);
    montar_senha(107, senha);
    printf("Senha: %s\n", senha);
    return 0;
}
// Saída:
// Senha: A032
// Senha: A097
