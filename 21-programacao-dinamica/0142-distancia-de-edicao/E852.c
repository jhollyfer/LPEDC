// 0142 · Distância de edição
// Exercício E852 · ★★★
//
// Programas de comparar textos e de bioinformática mostram o ALINHAMENTO
// das duas sequências, uma em cima da outra, com um traço onde falta letra
// e uma marca embaixo dizendo o que aconteceu em cada coluna:
//
//   = letras iguais     T troca     R remove (de cima)     I insere (de baixo)
//
// Escreva void alinha(const char *a, const char *b), que monta a tabela da
// distância de edição, faz a volta e mostra a distância e as três linhas do
// alinhamento, com um espaço antes de cada caractere. Teste com SABADO ->
// SALDO e ESTRELA -> ESTERIL.
//
//   Saída esperada:
//   SABADO -> SALDO: distância 2
//    S A B A D O
//    S A - L D O
//    = = R T = =
//   ESTRELA -> ESTERIL: distância 3
//    E S T - R E L A
//    E S T E R I L -
//    = = = I = T = R
//
// Dicas:
// 1. A volta é a do texto, mas cada passo grava uma coluna em três vetores
//    (cima, baixo e marca). Na remoção, embaixo vai '-'; na inserção, em
//    cima vai '-'.
// 2. As colunas saem de trás para a frente: mostre os vetores do índice
//    k - 1 até 0.
// 3. Teste os vizinhos na ordem do texto (igual, troca, remove, insere): com
//    outra ordem, um alinhamento diferente, com a mesma distância, pode
//    aparecer.
// 4. Resposta esperada: a saída acima.
//
// Escreva sua resposta abaixo:

#include <stdio.h>
#include <string.h>

int main(void) {

    return 0;
}
