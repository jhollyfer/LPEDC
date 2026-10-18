// 0145 · Rubro-negra esquerdista (LLRB)
// Exercício E870 · ★★★
//
// Escreva do zero (sem o rubronegra.h, que guarda int) uma rubro-negra
// esquerdista de NOMES para a lista de convidados de uma festa. Compare com
// strcmp; nome repetido é ignorado. Insira, nesta ordem:
//
//   Marcos Ana Teresa Bruno Lia Zeca Carla Otavio Duda Ana
//
// Mostre a lista em ordem, a pré-ordem com * nos vermelhos, a altura, a
// altura preta e o resultado de duas buscas.
//
//   Saída esperada:
//   Em ordem: Ana Bruno Carla Duda Lia Marcos Otavio Teresa Zeca
//   Pré-ordem: Marcos Duda Bruno* Ana Carla Lia Teresa Otavio Zeca
//   Altura 3, altura preta 3
//   Lia: na lista | Rafa: fora
//
// Dicas:
// 1. Struct com char nome[20], bool vermelho, esq e dir. As rotações e a
//    inversão de cores não olham a chave: copie a lógica do texto.
// 2. Na inserção, guarde int cmp = strcmp(nome, h->nome) e decida pelo sinal.
//    Para copiar o nome para o nó, use snprintf(n->nome, sizeof n->nome,
//    "%s", nome).
// 3. Resposta esperada: a saída acima. Não esqueça de pintar a raiz de preto
//    depois de cada inserção e de liberar tudo no fim.
//
// Escreva sua resposta abaixo:

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {

    return 0;
}
