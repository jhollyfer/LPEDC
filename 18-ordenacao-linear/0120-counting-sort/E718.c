// 0120 · Counting sort
// Exercício E718 · ★★☆
//
// Duas palavras são ANAGRAMAS quando usam as mesmas letras, nas mesmas
// quantidades: "porta" e "tropa". Um jeito de conferir: ordene as letras de
// cada uma e compare. Escreva void ordena_letras(char s[]), um counting sort
// das letras da própria string, com um contador para cada valor possível de
// char (256), e use no programa abaixo.
//
//   Saída esperada:
//   alegria -> aaegilr | regalia -> aaegilr: anagramas
//   porta -> aoprt | tropa -> aoprt: anagramas
//   mesa -> aems | seta -> aest: não são anagramas
//   carro -> acorr | corra -> acorr: anagramas
//
// Dicas:
// 1. int c[256] = {0}; e c[(unsigned char) s[i]]++ até achar o '\0'.
// 2. Por que o cast? O char pode ter sinal: uma letra acentuada em UTF-8
//    vira um byte negativo, e c[-61] escreve antes do vetor.
// 3. Depois, reescreva a string: cada x de 0 a 255, c[x] vezes. O '\0' do
//    fim fica onde estava, porque o tamanho não muda.
// 4. Resposta esperada: a saída acima.
//
// Escreva sua resposta abaixo:

#include <stdio.h>
#include <string.h>

// escreva ordena_letras aqui

void testa(const char *a, const char *b) {
    char x[32], y[32];
    strcpy(x, a);
    strcpy(y, b);
    // chame ordena_letras(x) e ordena_letras(y) aqui
    printf("%s -> %s | %s -> %s: %s\n", a, x, b, y,
           strcmp(x, y) == 0 ? "anagramas" : "não são anagramas");
}

int main(void) {
    testa("alegria", "regalia");
    testa("porta", "tropa");
    testa("mesa", "seta");
    testa("carro", "corra");
    return 0;
}
