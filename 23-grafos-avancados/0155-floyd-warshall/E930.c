// 0155 · Floyd-Warshall: todos os pares
// Exercício E930 · ★★★
//
// De volta aos cinco bairros do texto. A tabela já foi calculada quando a
// prefeitura abre uma rua nova, Feira -> Vila, de 1 minuto. Rodar o
// Floyd-Warshall de novo custa O(V³). Escreva nova_rua(d, a, b, w), que
// atualiza a tabela em O(V²): qualquer caminho que melhora com a rua nova
// passa por ela uma vez só, então é "de i até a", mais w, mais "de b até j".
// O main confere o resultado contra um Floyd completo feito do zero.
//
//   Saída esperada:
//   Centro    0   5   2   8   7
//   Porto     8   0   3   3   2
//   Vila     11   3   0   6   5
//   Alto      5  10   7   0  12
//   Feira     6   4   1   1   0
//   Confere com o Floyd completo: sim
//
// Dicas:
// 1. Para cada par (i, j): se d[i][a] + w + d[b][j] < d[i][j], troque.
// 2. Dá para atualizar no lugar: com pesos não negativos, a rua nova não
//    encurta nenhum caminho que termina em a nem nenhum que começa em b, e
//    por isso d[i][a] e d[b][j] não mudam no meio. Na dúvida, copie antes
//    a coluna a e a linha b em dois vetores e use as cópias.
// 3. Resposta esperada: a saída acima. Mudam três casas: Porto -> Vila
//    (10 vira 3), Feira -> Porto (11 vira 4) e Feira -> Vila (8 vira 1).
//
// Escreva sua resposta abaixo (escreva nova_rua):

#include <stdbool.h>
#include <stdio.h>

#define V 5
#define INFINITO 1000000000

const char *bairros[V] = {"Centro", "Porto", "Vila", "Alto", "Feira"};

void floyd(int d[V][V]) {
    for (int k = 0; k < V; k++)
        for (int i = 0; i < V; i++)
            for (int j = 0; j < V; j++)
                if (d[i][k] + d[k][j] < d[i][j]) d[i][j] = d[i][k] + d[k][j];
}

void monta(int d[V][V], int ruas[][3], int n) {
    for (int i = 0; i < V; i++)
        for (int j = 0; j < V; j++) d[i][j] = (i == j) ? 0 : INFINITO;
    for (int r = 0; r < n; r++) d[ruas[r][0]][ruas[r][1]] = ruas[r][2];
}

// rua nova a -> b com w minutos: atualize d em O(V²), sem rodar floyd de novo
void nova_rua(int d[V][V], int a, int b, int w) {
    (void)d; // apague estas quatro linhas
    (void)a;
    (void)b;
    (void)w;
}

int main(void) {
    int ruas[][3] = {{0, 2, 2}, {2, 1, 3}, {0, 1, 6}, {1, 3, 4},
                     {3, 0, 5}, {2, 4, 7}, {4, 3, 1}, {1, 4, 2}, {4, 2, 1}};
    int d[V][V], conferencia[V][V];
    monta(d, ruas, 8); // a cidade de antes: sem a rua 9
    floyd(d);

    nova_rua(d, 4, 2, 1); // abriu a rua Feira -> Vila, 1 minuto: O(V²)

    monta(conferencia, ruas, 9); // refaz tudo do zero, com a rua nova: O(V³)
    floyd(conferencia);

    bool igual = true;
    for (int i = 0; i < V; i++) {
        printf("%-7s", bairros[i]);
        for (int j = 0; j < V; j++) {
            printf("%4d", d[i][j]);
            if (d[i][j] != conferencia[i][j]) igual = false;
        }
        printf("\n");
    }
    printf("Confere com o Floyd completo: %s\n", igual ? "sim" : "não");
    return 0;
}
