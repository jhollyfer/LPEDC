// 0159 · Horspool
// Exercício E954 · ★★★
//
// Uma variação esperta: o algoritmo de Sunday (1990). Em vez da letra sob a
// ÚLTIMA casa da janela, ele olha a letra logo DEPOIS da janela, t[i + m],
// que vai entrar de qualquer jeito no próximo alinhamento. A tabela muda:
// tudo começa com m + 1 e, para j de 0 até m - 1 (agora a última entra),
// salto[p[j]] = m - j. A comparação pode ser em qualquer ordem; use da
// esquerda para a direita. Escreva int sunday(t, p, &achados), que devolve
// os alinhamentos, e compare com a horspool pronta no cardápio abaixo:
//
//   "PASTEL DE CARNE, PASTEL DE PIZZA E PASTEL DE QUEIJO"
//
//   Saída esperada:
//   QUEIJO: Horspool  9 alinhamentos, Sunday  8 (achou 1 e 1)
//   PASTEL: Horspool  9 alinhamentos, Sunday  8 (achou 3 e 3)
//   FRANGO: Horspool  9 alinhamentos, Sunday  8 (achou 0 e 0)
//
// Dicas:
// 1. Uma letra fora do padrão deixa pular m + 1: o padrão passa inteiro por
//    cima dela.
// 2. E quando i = n - m? Então t[i + m] é o '\0' do fim da string, que existe
//    e pode ser lido: ele não está no padrão, o salto é m + 1 e o laço acaba.
//    Sem esse '\0' (um texto lido para um vetor sem terminador), seria
//    leitura fora do vetor.
// 3. Use printf("%-6s: ...") para alinhar os nomes.
// 4. Resposta esperada: a saída acima.
//
// Escreva sua resposta abaixo (acrescente a sunday e mude o main):

#include <stdio.h>
#include <string.h>

#define ALFABETO 256

int horspool(const char *t, const char *p, int *achados) {
    int n = (int) strlen(t);
    int m = (int) strlen(p);
    int salto[ALFABETO];
    for (int c = 0; c < ALFABETO; c++) {
        salto[c] = m;
    }
    for (int j = 0; j < m - 1; j++) {
        salto[(unsigned char) p[j]] = m - 1 - j;
    }
    int i = 0, alinhamentos = 0;
    *achados = 0;
    while (i <= n - m) {
        alinhamentos++;
        int j = m - 1;
        while (j >= 0 && t[i + j] == p[j]) {
            j--;
        }
        if (j < 0) {
            (*achados)++;
        }
        i += salto[(unsigned char) t[i + m - 1]];
    }
    return alinhamentos;
}

int main(void) {
    const char *cardapio = "PASTEL DE CARNE, PASTEL DE PIZZA E PASTEL DE QUEIJO";
    const char *padroes[] = {"QUEIJO", "PASTEL", "FRANGO"};
    int a1;

    for (int k = 0; k < 3; k++) {
        int h = horspool(cardapio, padroes[k], &a1);
        printf("%-6s: Horspool %2d alinhamentos (achou %d)\n", padroes[k], h, a1);
    }
    return 0;
}
