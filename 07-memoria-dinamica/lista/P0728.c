// Lista · Módulo 07 · Memória dinâmica
// Exercício P0728 · ★★★ · As palavras mais usadas do discurso
//
// Conte as palavras de um discurso de formatura e mostre as 3 mais usadas.
// Não se sabe quantas palavras distintas virão, então guarde-as em dois
// vetores dinâmicos que crescem JUNTOS (dobrando): char **palavras (cada uma
// uma cópia no heap, em minúsculas) e int *cont. Palavras com menos de 3
// letras não contam ("de", "a", "o"...). No empate, vale a que apareceu
// primeiro. Mostre também quantas distintas foram guardadas e a capacidade
// final:
//
//   const char *discurso = "Hoje a turma celebra. A turma estudou, a turma "
//       "errou, a turma aprendeu. Hoje celebramos o estudo e o futuro; "
//       "o futuro da turma comeca hoje!";
//
//   Saída esperada:
//   10 palavras distintas (capacidade 16)
//   1º turma (5)
//   2º hoje (3)
//   3º futuro (2)
//
// Dicas:
// 1. Monte cada palavra num buffer local char p[32] (isalpha e tolower,
//    como no P0524); ao fechar, se tiver 3 letras ou mais, processe.
// 2. Processar: procure com strcmp; achou, cont[k]++; não achou, garanta
//    espaço nos DOIS vetores (dois realloc com ponteiros novos, e só troque
//    depois que os dois derem certo) e guarde uma cópia com malloc.
// 3. Para as 3 maiores, faça 3 passadas: em cada uma, pegue o maior cont
//    que ainda não foi escolhido (marque num vetor bool, ou use um calloc).
// 4. Libere cada palavra, o vetor de palavras e o de contagens.
// 5. Resposta esperada: a saída acima.
//
// Escreva sua resposta abaixo:

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

int main(void) {
    const char *discurso = "Hoje a turma celebra. A turma estudou, a turma "
        "errou, a turma aprendeu. Hoje celebramos o estudo e o futuro; "
        "o futuro da turma comeca hoje!";
    (void) discurso; // apague esta linha quando escrever

    return 0;
}
