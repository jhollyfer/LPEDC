// Lista · Módulo 06 · Ponteiros
// Exercício P0615 · ★★☆ · Troque o prato do cardápio
//
// O cardápio do dia é um vetor de ponteiros para string:
//
//   const char *cardapio[5] = {"Tacacá", "Pato no tucupi", "Tambaqui assado",
//                              "Vatapá", "Maniçoba"};
//
// Escreva const char **achar(const char **itens, int n, const char *prato),
// que devolve o ENDEREÇO da gaveta do vetor onde está o prato (ou NULL). Com
// esse endereço, o main troca o prato sem saber o índice: *gaveta = "novo".
// Escreva também void mostrar(const char **itens, int n). Troque "Vatapá" por
// "Caldeirada", tente trocar "Feijoada" e mostre o cardápio:
//
//   Saída esperada:
//   Vatapá trocado por Caldeirada (gaveta 3)
//   Feijoada não está no cardápio
//   1. Tacacá
//   2. Pato no tucupi
//   3. Tambaqui assado
//   4. Caldeirada
//   5. Maniçoba
//
// Dicas:
// 1. No achar, compare com strcmp(itens[i], prato) == 0 e devolva &itens[i]
//    (ou itens + i, que é a mesma coisa).
// 2. O retorno é const char **: um ponteiro para uma gaveta que guarda um
//    const char *. *gaveta é o ponteiro da gaveta; **gaveta seria a primeira
//    letra do prato.
// 3. Antes de usar o retorno, teste se é NULL.
// 4. Resposta esperada: a saída acima.
//
// Escreva sua resposta abaixo:

#include <stdio.h>
#include <string.h>

int main(void) {
    const char *cardapio[5] = {"Tacacá", "Pato no tucupi", "Tambaqui assado",
                               "Vatapá", "Maniçoba"};
    (void) cardapio; // apague esta linha quando escrever

    return 0;
}
