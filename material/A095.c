// A095 · A string começa onde o ponteiro aponta

#include <stdio.h>

int main(void) {
    char endereco[] = "Rua das Flores, 120 - Centro"; // vetor: dá para mudar

    // procura a vírgula andando com um ponteiro
    char *virgula = endereco;
    while (*virgula != '\0' && *virgula != ',') {
        virgula++;
    }

    // para o printf, a string vai do endereço recebido até o primeiro '\0'
    printf("Inteiro:     %s\n", endereco);
    printf("Da vírgula:  %s\n", virgula);
    printf("Depois dela: %s\n", virgula + 2); // pula a vírgula e o espaço

    // um '\0' no meio corta a string: o resto continua na memória
    if (*virgula == ',') {
        *virgula = '\0';
    }
    printf("Só a rua:    %s\n", endereco);
    printf("O resto:     %s\n", virgula + 2); // a parte de trás segue lá

    // com const char * apontando para um literal, isso não seria permitido:
    // const char *fixo = "Rua A, 10"; fixo[5] = '\0'; não compila
    return 0;
}
// Saída:
// Inteiro:     Rua das Flores, 120 - Centro
// Da vírgula:  , 120 - Centro
// Depois dela: 120 - Centro
// Só a rua:    Rua das Flores
// O resto:     120 - Centro
