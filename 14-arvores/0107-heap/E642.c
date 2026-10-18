// 0107 · Heap e fila de prioridade
// Exercício E642 · ★★★
//
// Ache o bug. Este heap de máximo foi escrito sem o TAD. Chegam pacientes
// com gravidade 40, 70, 20, 90, 30 e 50, e todos são atendidos. A ordem
// deveria ser da maior para a menor gravidade:
//
//   Saída esperada:
//   Atendimento: 90 70 50 40 30 20
//
//   Saída que aparece:
//   Atendimento: 90 70 40 30 50 20
//
// O programa não quebra; o erro é de lógica, numa linha da descida. Ache,
// conserte e mostre, com o vetor, o momento exato em que o heap quebrou.
//
// Dicas:
// 1. Depois das chegadas o vetor é [90 70 50 40 30 20]. Faça à mão a
//    remoção do 90 e depois a do 70, seguindo o código ao pé da letra.
// 2. Na segunda remoção o 30 está na raiz, com os filhos 40 e 50. Com quem o
//    código troca? E com quem deveria trocar?
// 3. Resposta esperada: a linha "if (v[f] <= v[i] && f + 1 < n)" só olha o
//    filho direito quando o esquerdo não serve. Ela troca com o PRIMEIRO
//    filho maior que o pai, e não com o MAIOR: o 40 sobe para a raiz acima
//    do 50. O certo é "if (f + 1 < n && v[f + 1] > v[f])". Consertado:
//    90 70 50 40 30 20.
//
// Escreva sua resposta abaixo (conserte o código):

#include <stdio.h>

#define CAP 10

int v[CAP];
int n = 0;

void troca(int a, int b) {
    int t = v[a];
    v[a] = v[b];
    v[b] = t;
}

void chega(int x) {
    int i = n++;
    v[i] = x;
    while (i > 0 && v[(i - 1) / 2] < v[i]) {
        troca((i - 1) / 2, i);
        i = (i - 1) / 2;
    }
}

int atende(void) {
    int max = v[0];
    v[0] = v[--n];
    int i = 0;
    while (2 * i + 1 < n) {
        int f = 2 * i + 1;
        if (v[f] <= v[i] && f + 1 < n) {
            f++;
        }
        if (v[i] >= v[f]) {
            break;
        }
        troca(i, f);
        i = f;
    }
    return max;
}

int main(void) {
    int chegada[] = {40, 70, 20, 90, 30, 50};
    for (int k = 0; k < 6; k++) {
        chega(chegada[k]);
    }
    printf("Atendimento:");
    while (n > 0) {
        printf(" %d", atende());
    }
    printf("\n");
    return 0;
}
