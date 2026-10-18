// A245 · O pódio sem ordenar a tabela

#include <stdio.h>

typedef struct {
    char nome[10];
    int pontos;
} Jogador;

void troca(Jogador *a, Jogador *b) {
    Jogador aux = *a;
    *a = *b;
    *b = aux;
}

int separa(Jogador v[], int p, int r) {
    int pivo = v[r].pontos, j = p;
    for (int k = p; k < r; k++) {
        if (v[k].pontos <= pivo) {
            troca(&v[j], &v[k]);
            j++;
        }
    }
    troca(&v[j], &v[r]);
    return j;
}

// deixa na posição k quem ficaria lá se v fosse ordenado; de brinde, à
// esquerda de k só ficam pontos <= e à direita só pontos >=
void seleciona(Jogador v[], int n, int k) {
    int p = 0, r = n - 1;
    while (p < r) {
        int j = separa(v, p, r);
        if (j == k) {
            return;
        }
        if (k < j) {
            r = j - 1;
        } else {
            p = j + 1;
        }
    }
}

int main(void) {
    Jogador torneio[] = {
        {"Bia", 1820}, {"Davi", 2150}, {"Edu", 1675}, {"Fábio", 2310}, {"Gabi", 1990},
        {"Hugo", 1540}, {"Íris", 2240}, {"Juca", 1880}, {"Kátia", 2075}, {"Léo", 1760},
        {"Malu", 1930}, {"Nico", 1610},
    };
    int n = 12;

    seleciona(torneio, n, n - 3);       // os 3 maiores vão para v[9..11]
    printf("depois da seleção:");
    for (int i = 0; i < n; i++) {
        printf(" %d", torneio[i].pontos);
    }
    printf("\n");

    // só os 3 do fim precisam de ordem: um insertion sort de 3 elementos
    for (int i = n - 2; i < n; i++) {
        Jogador x = torneio[i];
        int j = i;
        while (j > n - 3 && torneio[j - 1].pontos > x.pontos) {
            torneio[j] = torneio[j - 1];
            j--;
        }
        torneio[j] = x;
    }
    printf("ouro: %s (%d), prata: %s (%d), bronze: %s (%d)\n",
           torneio[n - 1].nome, torneio[n - 1].pontos, torneio[n - 2].nome,
           torneio[n - 2].pontos, torneio[n - 3].nome, torneio[n - 3].pontos);
    return 0;
}
// Saída:
// depois da seleção: 1540 1610 1675 1990 1820 1880 2075 1760 1930 2150 2240 2310
// ouro: Fábio (2310), prata: Íris (2240), bronze: Davi (2150)
//
// Repare na linha do meio: o vetor NÃO está ordenado (1990 antes de 1820,
// 2075 antes de 1760), mas os três últimos são os três maiores. O
// quickselect para k = n - 3 garante isso de graça, porque cada separação
// deixa os maiores à direita do pivô. Para o pódio, basta ordenar esses 3.
// Com uma tabela de 1 milhão de jogadores, são uns poucos milhões de passos,
// em vez de ordenar tudo.
