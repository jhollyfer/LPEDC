// A307 · Ciclo negativo no câmbio: dinheiro que se multiplica

#include <math.h>
#include <stdio.h>

#define V 4
#define E 10

typedef struct {
    int de, para;
    double taxa; // 1 unidade de "de" vira taxa unidades de "para"
} Troca;

const char *moedas[V] = {"Real", "Dólar", "Euro", "Peso"};

int main(void) {
    Troca t[E] = {{0, 1, 0.20}, {1, 0, 4.95}, {1, 2, 0.92}, {2, 1, 1.07}, {2, 0, 5.45},
                  {0, 2, 0.18}, {0, 3, 180}, {3, 0, 0.0054}, {1, 3, 880}, {3, 1, 0.0011}};

    // multiplicar taxas vira somar logaritmos; "ganhar" (produto > 1) vira soma < 0
    double dist[V];
    int anterior[V];
    for (int v = 0; v < V; v++) {
        dist[v] = INFINITY;
        anterior[v] = -1;
    }
    dist[0] = 0;
    for (int rodada = 1; rodada <= V - 1; rodada++)
        for (int k = 0; k < E; k++) {
            double peso = -log(t[k].taxa);
            if (dist[t[k].de] + peso < dist[t[k].para]) {
                dist[t[k].para] = dist[t[k].de] + peso;
                anterior[t[k].para] = t[k].de;
            }
        }

    int x = -1; // rodada extra: alguém ainda melhora?
    for (int k = 0; k < E && x == -1; k++)
        if (dist[t[k].de] - log(t[k].taxa) < dist[t[k].para] - 1e-12) x = t[k].para;
    if (x == -1) {
        printf("Sem arbitragem: nenhuma volta dá lucro\n");
        return 0;
    }
    for (int i = 0; i < V; i++) x = anterior[x]; // V passos para trás: com certeza dentro do ciclo

    int ciclo[V + 1], n = 0, v = x;
    do { // anda pelos anteriores até voltar a x
        ciclo[n++] = v;
        v = anterior[v];
    } while (v != x);

    double produto = 1;
    printf("Ciclo: %s", moedas[x]);
    for (int i = n - 1; i >= 0; i--) { // os anteriores vêm de trás para frente
        int de = ciclo[(i + 1) % n], para = ciclo[i];
        for (int k = 0; k < E; k++)
            if (t[k].de == de && t[k].para == para) produto *= t[k].taxa;
        printf(" -> %s", moedas[para]);
    }
    printf("\nR$ 1000.00 viram R$ %.2f numa volta\n", 1000 * produto);
    return 0;
}
// Saída:
// Ciclo: Real -> Dólar -> Euro -> Real
// R$ 1000.00 viram R$ 1002.80 numa volta
//
// Um ciclo negativo, aqui, é dinheiro infinito: cada volta multiplica o
// valor por 1,0028. Na vida real, a cotação se ajusta em segundos, e as
// taxas de cada troca comem o lucro.
