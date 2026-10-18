// 0047 · Lendo strings
// Exercício E277 · ★☆☆
//
// Leia o nome da cidade onde a pessoa mora com fgets (o nome pode ter
// espaços), tire o '\n' com strcspn e mostre a frase abaixo. Se o fgets
// devolver NULL, mostre "Nada foi digitado." e termine com return 1.
//
//   Exemplo de execução:
//   Cidade: Porto Alegre
//   Você mora em Porto Alegre (12 caracteres).
//
// Dicas:
// 1. char cidade[50]; fgets(cidade, sizeof(cidade), stdin)
// 2. cidade[strcspn(cidade, "\n")] = '\0';
// 3. Teste sem tirar o '\n': o ponto final pula para a linha de baixo e o
//    strlen conta 13. É o sinal de que o '\n' ficou lá.
// 4. Resposta esperada: a execução acima.
//
// Escreva sua resposta abaixo:

#include <stdio.h>
#include <string.h>

int main(void) {

    return 0;
}
