// A039 · Dividindo pizzas sem usar a divisão

#include <stdio.h>

int main(void) {
    // 47 fatias para 5 amigos: quantas cada um come e quantas sobram?
    int fatias = 47;
    int amigos = 5;
    int sobra = fatias;
    int rodadas = 0;          // cada rodada dá 1 fatia para cada amigo

    while (sobra >= amigos) { // ainda dá uma rodada completa?
        sobra = sobra - amigos;
        rodadas++;
    }
    printf("%d fatias para %d amigos: %d para cada, sobram %d\n",
           fatias, amigos, rodadas, sobra);
    printf("Conferindo com / e %%: %d e %d\n", fatias / amigos, fatias % amigos);

    // caso de borda: menos fatias que amigos. A pergunta já começa falsa
    fatias = 3;
    sobra = fatias;
    rodadas = 0;
    while (sobra >= amigos) { // 3 >= 5? Não: o corpo roda ZERO vezes
        sobra = sobra - amigos;
        rodadas++;
    }
    printf("%d fatias para %d amigos: %d para cada, sobram %d\n",
           fatias, amigos, rodadas, sobra);
    return 0;
}
// Saída:
// 47 fatias para 5 amigos: 9 para cada, sobram 2
// Conferindo com / e %: 9 e 2
// 3 fatias para 5 amigos: 0 para cada, sobram 3
