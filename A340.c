// A340 · A ordem que o padrão não promete

#include <stdio.h>

int passo = 0; // marca a ordem em que as funções rodam

int pedir_pao(void) {
    printf("  pão chegou em %d\n", ++passo);
    return 7; // R$ 7
}

int pedir_cafe(void) {
    printf("  café chegou em %d\n", ++passo);
    return 5; // R$ 5
}

int main(void) {
    // a soma é sempre 12; QUEM roda primeiro, o padrão não diz
    printf("conta junta:\n");
    int conta = pedir_pao() + pedir_cafe();
    printf("  conta = %d\n", conta);

    // quando a ordem importa, separe em instruções: o ; fixa a ordem
    passo = 0;
    printf("conta em passos:\n");
    int pao = pedir_pao();
    int cafe = pedir_cafe();
    printf("  conta = %d\n", pao + cafe);

    // pré e pós-incremento, cada um sozinho na sua instrução
    int senha = 41;
    int chamada = senha++; // usa 41, depois senha vira 42
    printf("chamou %d, próxima senha %d\n", chamada, senha);
    chamada = ++senha;     // senha vira 43, depois usa 43
    printf("chamou %d, próxima senha %d\n", chamada, senha);

    // sizeof não avalia a expressão: o ++ abaixo NÃO acontece
    int n = 10;
    size_t bytes = sizeof(n++);
    printf("sizeof(n++) = %zu, n continua %d\n", bytes, n);
    return 0;
}
// Saída (a ordem da "conta junta" é a do gcc deste PC; outro compilador
// pode chamar o café primeiro):
// conta junta:
//   pão chegou em 1
//   café chegou em 2
//   conta = 12
// conta em passos:
//   pão chegou em 1
//   café chegou em 2
//   conta = 12
// chamou 41, próxima senha 42
// chamou 43, próxima senha 43
// sizeof(n++) = 4, n continua 10
