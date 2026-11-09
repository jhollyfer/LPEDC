// Lista · Módulo 27 · Detalhes de C que caem em prova
// Exercício P2717 · ★★☆ · Boletim em arquivo binário
//
// Com typedef struct { char nome[16]; float nota; } Aluno;, grave os 4
// alunos abaixo de uma vez no arquivo p2717_boletim.bin com fwrite. Feche,
// abra de novo, leia registro por registro com fread e mostre só os
// aprovados (nota >= 7). No fim, apague o arquivo.
//
//   Ana 8.5    Bruno 6.0    Caio 7.0    Duda 4.5
//
//   Saída esperada:
//   gravados 4 registros (80 bytes)
//   aprovado: Ana (8.5)
//   aprovado: Caio (7.0)
//
// Dicas:
// 1. Modo "wb" para gravar e "rb" para ler: o arquivo guarda os bytes da
//    struct, como estão na memória.
// 2. fwrite(v, sizeof v[0], 4, f) devolve quantos registros gravou.
// 3. while (fread(&a, sizeof a, 1, f) == 1) lê um por vez.
// 4. sizeof(Aluno) = 16 + 4 = 20 bytes.
// 5. Resposta esperada: a saída acima.
//
// Escreva sua resposta abaixo:

#include <stdio.h>

int main(void) {

    return 0;
}
