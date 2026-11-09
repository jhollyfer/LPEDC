// Lista · Módulo 05 · Vetores, matrizes e strings
// Exercício P0518 · ★★☆ · O telefone digitado de qualquer jeito
//
// O cadastro da farmácia lê o celular com fgets, e cada pessoa digita de um
// jeito: "92 99123-4567", "(92)991234567", "92.99123.4567". Escreva um
// programa que lê UMA linha com fgets num char linha[40], guarda só os
// dígitos numa outra string e:
// - se sobrarem exatamente 11 dígitos, mostra "Celular: (92) 99123-4567";
// - senão, mostra "Inválido: 9 dígitos" (com a quantidade que veio).
//
//   Exemplo de execução 1:
//   (92)991234567
//   Celular: (92) 99123-4567
//
//   (a primeira linha é a que você digita; só a segunda é do programa)
//
//   Exemplo de execução 2:
//   9912-3456
//   Inválido: 8 dígitos
//
// Dicas:
// 1. if (fgets(linha, sizeof linha, stdin) == NULL) return 1; protege contra
//    entrada vazia. O '\n' do fim nem atrapalha: ele não é dígito.
// 2. Monte digitos[] com isdigit, um k que avança e digitos[k] = '\0' no fim.
// 3. Para formatar, mostre os caracteres por posição: %c%c para o DDD, depois
//    5 dígitos, traço e os 4 últimos. Um laço de i a j ajuda.
// 4. Teste com printf '(92)991234567\n' | ./rodar ... e com 9912-3456.
// 5. Resposta esperada: as duas execuções acima.
//
// Escreva sua resposta abaixo:

#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(void) {

    return 0;
}
