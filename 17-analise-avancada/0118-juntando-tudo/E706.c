// 0118 · Juntando tudo
// Exercício E706 · ★★☆
//
// Às vezes você recebe uma função pronta e quer saber a classe dela sem
// fazer a análise. Dá para descobrir no experimento: dobre n e veja por
// quanto o custo é multiplicado. Complete classe(f, &razao): ela calcula
// razao = f(128) / f(64) (cada mistério devolve quantos passos deu) e
// devolve o nome da classe pela razão:
//
//   abaixo de 2,15  -> Θ(n)
//   abaixo de 3     -> Θ(n log n)
//   abaixo de 6     -> Θ(n²)
//   a partir de 6   -> Θ(n³)
//
//   Saída esperada:
//   misterio_a: dobrou n, custo x4.03 -> Θ(n²)
//   misterio_b: dobrou n, custo x2.01 -> Θ(n)
//   misterio_c: dobrou n, custo x2.33 -> Θ(n log n)
//   misterio_d: dobrou n, custo x7.88 -> Θ(n³)
//
// Depois de rodar, confira cada resposta lendo o código: qual é a
// recorrência do misterio_b? Por que o misterio_d dá n³ se o laço de dentro
// anda de 2 em 2?
//
// Dicas:
// 1. Chame f como uma função comum: f(128). O cast (double) evita a
//    divisão inteira.
// 2. Para n log n, dobrar n dá 2 · log(2n) / log n: com n = 64, 2 · 7 / 6 =
//    2,33. Por isso o limite do Θ(n) é 2,15, e não 2,5.
// 3. Resposta esperada: a saída acima. O misterio_b é T(n) = 2 T(n/2) + 1
//    (caso 1 do teorema mestre, Θ(n)); o passo 2 do misterio_d só divide
//    o custo por uma constante.
//
// Escreva sua resposta abaixo (complete classe):

#include <stdio.h>

// as quatro caixas-pretas: cada uma devolve quantos passos deu
long misterio_a(long n) {
    long passos = 0;
    for (long i = 0; i < n; i++) {
        for (long j = i + 1; j < n; j++) {
            passos++;
        }
    }
    return passos;
}

long misterio_b(long n) {
    if (n <= 1) {
        return 1;
    }
    return misterio_b(n / 2) + misterio_b(n - n / 2) + 1;
}

long misterio_c(long n) {
    long passos = 0;
    for (long i = 0; i < n; i++) {
        for (long j = 1; j < n; j *= 2) {
            passos++;
        }
    }
    return passos;
}

long misterio_d(long n) {
    long passos = 0;
    for (long i = 0; i < n; i++) {
        for (long j = 0; j < n; j++) {
            for (long k = j; k < n; k += 2) {
                passos++;
            }
        }
    }
    return passos;
}

// devolve o nome da classe e guarda em *razao o quanto o custo cresceu
const char *classe(long (*f)(long), double *razao) {
    (void)f;      // apague estas duas linhas e escreva a função
    *razao = 0;
    return "?";
}

int main(void) {
    const char *nomes[] = {"misterio_a", "misterio_b", "misterio_c", "misterio_d"};
    long (*funcoes[])(long) = {misterio_a, misterio_b, misterio_c, misterio_d};
    for (int i = 0; i < 4; i++) {
        double r;
        const char *c = classe(funcoes[i], &r);
        printf("%s: dobrou n, custo x%.2f -> %s\n", nomes[i], r, c);
    }
    return 0;
}
