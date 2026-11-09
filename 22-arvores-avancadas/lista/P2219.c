// Lista · Módulo 22 · Árvores e conjuntos avançados
// Exercício P2219 · ★★☆ · A agenda de ramais consistente
//
// Na central telefônica da universidade, o aluno digita o ramal e a
// ligação completa assim que os dígitos formam um ramal cadastrado. Por
// isso a lista só é CONSISTENTE se nenhum ramal é prefixo de outro (se 911
// e 91125 existem, ninguém consegue ligar para o 91125). É a mesma regra do
// código livre de prefixo do Huffman. Escreva do zero uma trie de dígitos
// (10 filhos) que, ao inserir cada ramal, detecta o problema nos dois
// sentidos: o novo passa por um nó que já é fim de ramal, ou termina num
// nó que já tem filhos. Teste as duas listas.
//
//   Lista 1: 4012 4078 5231 40 7766
//   Lista 2: 3021 3304 4471 6650 4479
//
//   Saída esperada:
//   Lista 1: inconsistente (conflito ao inserir 40)
//   Lista 2: consistente
//
// Dicas:
// 1. insere devolve 0 se achou conflito: ao descer, se o nó atual é fim,
//    conflito; ao terminar, se o nó tem algum filho, conflito.
// 2. Libere a trie de cada lista antes de testar a próxima.
// 3. Resposta esperada: a lista 1 é inconsistente (40 é prefixo de 4012 e
//    4078; o conflito aparece ao inserir o 40) e a lista 2 é consistente.
//
// Escreva sua resposta abaixo:

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

int main(void) {

    return 0;
}
