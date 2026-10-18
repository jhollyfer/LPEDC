// 0094 · Busca sequencial
// Exercício E560 · ★☆☆
//
// A portaria de uma festa confere o nome na lista de convidados. O programa
// abaixo está quase pronto: falta só o miolo do laço que procura o nome.
// Complete o trecho marcado para que, ao achar, ele guarde o índice em pos e
// pare o laço.
//
//   Saída esperada:
//   Lista: Ana Bruno Carla Diego Elisa
//   Carla: pode entrar (posição 2)
//   Fábio: não está na lista
//
// Dicas:
// 1. Strings no C não se comparam com ==: isso compara endereços, não letras.
// 2. Use strcmp(convidados[i], nome), que devolve 0 quando são iguais.
// 3. Depois de pos = i, um break encerra o laço.
// 4. Resposta esperada: if (strcmp(convidados[i], nome) == 0) { pos = i;
//    break; }
//
// Escreva sua resposta abaixo (complete o código):

#include <stdio.h>
#include <string.h>

int main(void) {
    const char *convidados[] = {"Ana", "Bruno", "Carla", "Diego", "Elisa"};
    int n = 5;
    const char *procurados[] = {"Carla", "Fábio"};

    printf("Lista:");
    for (int i = 0; i < n; i++) {
        printf(" %s", convidados[i]);
    }
    printf("\n");

    for (int k = 0; k < 2; k++) {
        const char *nome = procurados[k];
        int pos = -1;
        for (int i = 0; i < n; i++) {
            // complete aqui: se convidados[i] for igual a nome,
            // guarde i em pos e saia do laço
        }
        if (pos >= 0) {
            printf("%s: pode entrar (posição %d)\n", nome, pos);
        } else {
            printf("%s: não está na lista\n", nome);
        }
    }
    return 0;
}
