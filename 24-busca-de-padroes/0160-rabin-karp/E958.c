// 0160 · Rabin-Karp
// Exercício E958 · ★★☆
//
// O professor desconfia de cópia. Escreva um detector simples: calcule o hash
// de todas as janelas de 8 letras do texto original e guarde num vetor; depois
// role uma janela de 8 pelo texto suspeito e, quando o hash dela estiver no
// vetor (e as letras conferirem), marque as 8 letras como copiadas. No fim,
// mostre o suspeito com as letras copiadas em MAIÚSCULAS e a porcentagem:
//
//   original: "o projeto mede a agua da chuva com sensores baratos"
//   suspeito: "nosso trabalho mede a agua da chuva com um balde"
//
//   Saída esperada:
//   nosso trabalhO MEDE A AGUA DA CHUVA COM um balde
//   27 de 48 letras em trechos copiados (56%)
//
// Dicas:
// 1. Uma função int hashes(const char *s, long long h[]) que enche h com o
//    hash rolante de cada janela e devolve quantas são (n - 8 + 1). Use
//    BASE 256 e Q 1000003, em long long.
// 2. Para cada janela i do suspeito, procure o hash dela no vetor do
//    original (um laço simples basta aqui) e confira as letras antes de
//    marcar.
// 3. Guarde as marcas num vetor int copiada[] e só converta para maiúscula
//    no fim, com toupper((unsigned char) c).
// 4. Resposta esperada: a saída acima. O 'o' de "trabalho" também é marcado:
//    a janela "o mede a" existe no original ("projeto mede a").
//
// Escreva sua resposta abaixo:

#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(void) {

    return 0;
}
