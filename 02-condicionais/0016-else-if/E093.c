// 0016 · else if, if aninhado e o else pendurado
// Exercício E093 · ★★☆
//
// O assistente do celular lê duas respostas: você vai sair (1 ou 0)? Vai
// chover (1 ou 0)? Quem vai sair e vê chuva deve ler "Leve o guarda-chuva.";
// quem NÃO vai sair deve ler "Fique em casa e descanse."; todo mundo lê
// "Bom dia!" no fim. O recuo do programa abaixo promete isso, mas o else
// pendurado tem outro dono (o código está quebrado de propósito e o gcc
// avisa). Rode com 0 1, 1 0 e 1 1, veja a saída errada e conserte com
// chaves.
//
//   Vai sair? Vai chover? 0 1
//   Fique em casa e descanse.
//   Bom dia!
//
// Dicas:
// 1. Sem chaves, o else pertence ao if mais próximo que ainda não tem else:
//    o if (chuva).
// 2. Ponha chaves em volta do if de dentro (e, de quebra, em todos os
//    blocos).
// 3. Resposta esperada, depois do conserto: 0 1 → "Fique em casa e
//    descanse." e "Bom dia!"; 1 0 → só "Bom dia!"; 1 1 → "Leve o
//    guarda-chuva." e "Bom dia!". Antes do conserto, 0 1 mostrava só
//    "Bom dia!" e 1 0 mandava ficar em casa.
//
// Escreva sua resposta abaixo (conserte o código):

#include <stdio.h>

int main(void) {
    int vai_sair, chuva;
    printf("Vai sair? Vai chover? ");
    if (scanf("%d %d", &vai_sair, &chuva) != 2) {
        printf("Entrada inválida\n");
        return 1;
    }

    if (vai_sair)
        if (chuva)
            printf("Leve o guarda-chuva.\n");
    else
        printf("Fique em casa e descanse.\n");
    printf("Bom dia!\n");
    return 0;
}
