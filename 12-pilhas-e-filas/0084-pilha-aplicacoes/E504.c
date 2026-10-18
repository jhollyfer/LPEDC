// 0084 · Pilha na prática: parênteses e notação pós-fixa
// Exercício E504 · ★★★
//
// Faça uma calculadora pós-fixa de verdade: ela lê expressões, uma por linha
// (com fgets), até o fim da entrada (Ctrl+D no terminal), aceita números com
// vários dígitos e, em vez de quebrar, explica o erro:
//
// - "falta operando": operador sem dois números na pilha;
// - "divisão por zero";
// - "sobrou número na pilha": terminou com mais de um número;
// - "símbolo inválido 'x'": qualquer coisa que não seja dígito, espaço ou
// + - * /;
// - linha vazia: ignore.
//
//   Teste: printf '10 2 8 * + 3 -\n4 0 /\n5 +\n1 2 3 +\n2 x +\n' | rodar E504.c
//   = 23
//   erro: divisão por zero
//   erro: falta operando
//   erro: sobrou número na pilha
//   erro: símbolo inválido 'x'
//
// Dicas:
// 1. Uma função int avalia(const char *linha, int *resultado) que devolve um
//    código (0 = ok, 1, 2, 3, 4 para cada erro) deixa o main simples.
// 2. Crie a pilha dentro de avalia e libere em TODOS os caminhos de saída.
// 3. Junte os dígitos como no A168. O '\n' do fgets conta como espaço.
// 4. Resposta esperada: as cinco linhas acima.
//
// Escreva sua resposta abaixo:

#include <stdio.h>
#include <string.h>
#include "pilha.h"

int main(void) {

    return 0;
}
