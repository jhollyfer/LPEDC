// A129 · Os ingredientes da pizza

#include <stdio.h>

// cada ingrediente é um bit: 1u << n liga só o bit n
#define QUEIJO    (1u << 0)
#define TOMATE    (1u << 1)
#define CEBOLA    (1u << 2)
#define CALABRESA (1u << 3)
#define AZEITONA  (1u << 4)

void mostrar(const char *nome, unsigned p) {
    const char *ingredientes[] = {"queijo", "tomate", "cebola", "calabresa", "azeitona"};
    printf("%-12s", nome);
    for (int b = 0; b < 5; b++) {
        if (p & (1u << b)) {
            printf(" %s", ingredientes[b]);
        }
    }
    printf("\n");
}

int main(void) {
    unsigned calabresa = QUEIJO | CALABRESA | CEBOLA | AZEITONA;
    unsigned marguerita = QUEIJO | TOMATE;
    mostrar("calabresa", calabresa);
    mostrar("marguerita", marguerita);

    unsigned meu = calabresa & ~(CEBOLA | AZEITONA); // tira dois de uma vez
    mostrar("a minha", meu);

    mostrar("em comum", calabresa & marguerita);   // E: o que as duas têm
    mostrar("meio a meio", calabresa | marguerita); // OU: tudo junto

    unsigned alergia = CEBOLA | TOMATE;
    // "tem ALGUM" e "tem TODOS" são testes diferentes
    printf("marguerita tem algum de cebola/tomate? %s\n",
           (marguerita & alergia) != 0 ? "sim" : "não");
    printf("marguerita tem todos? %s\n",
           (marguerita & alergia) == alergia ? "sim" : "não");
    return 0;
}
// Saída:
// calabresa    queijo cebola calabresa azeitona
// marguerita   queijo tomate
// a minha      queijo calabresa
// em comum     queijo
// meio a meio  queijo tomate cebola calabresa azeitona
// marguerita tem algum de cebola/tomate? sim
// marguerita tem todos? não
