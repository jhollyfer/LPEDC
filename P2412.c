// Lista · Módulo 24 · Busca de padrões em texto
// Exercício P2412 · ★★☆ · Os alarmes falsos do Rabin-Karp
//
// Escreva do zero int busca(t, p, q, mostrar): o Rabin-Karp com base 256 e
// módulo q, que conta as ocorrências e os FALSOS POSITIVOS (hash igual,
// letras diferentes) e, quando mostrar é 1, mostra cada falso positivo com
// a posição e a janela. Procure "roma" na frase do main com q = 11, 101 e
// 1009.
//
//   Saída esperada:
//     falso positivo em  3: "ato "
//     falso positivo em  9: "eu a"
//     falso positivo em 16: "upa "
//     falso positivo em 27: "de r"
//     falso positivo em 37: "a ra"
//   q =   11: 1 ocorrência(s), 5 falso(s) positivo(s)
//     falso positivo em 37: "a ra"
//   q =  101: 1 ocorrência(s), 1 falso(s) positivo(s)
//   q = 1009: 1 ocorrência(s), 0 falso(s) positivo(s)
//
// Dicas:
// 1. Use (unsigned char) em cada letra e o "+ q" ao tirar a letra da
//    esquerda, para o resto não ficar negativo.
// 2. Com q = 11 só existem 11 hashes possíveis: uma janela qualquer bate
//    com o padrão por acaso cerca de 1 vez em 11.
// 3. Resposta esperada: 5 falsos positivos com q = 11, 1 com q = 101
//    ("a ra", na posição 37) e nenhum com q = 1009.
//
// Escreva sua resposta abaixo:

#include <stdio.h>
#include <string.h>

int main(void) {
    const char *frase = "o rato roeu a roupa do rei de roma e a rainha riu";
    printf("%s\n", frase);
    return 0;
}
