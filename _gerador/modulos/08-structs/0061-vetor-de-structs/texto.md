## 0061 · Vetor de structs

- **Vetor de structs**: `Time tabela[4];` são quatro `Time` seguidos na
  memória, com os bytes de cada struct dentro do vetor (BACKES, 2013, cap. 8).
- **Índice antes do ponto**: `tabela[2].nome`. Primeiro a posição, depois o
  campo; `tabela.nome[2]` não faz sentido, porque o vetor não tem campos
  (BACKES, 2013, cap. 8).
- **Inicialização**: chaves dentro de chaves. Sem o tamanho entre colchetes, o
  compilador conta, e `sizeof tabela / sizeof tabela[0]` dá a quantidade
  (DEITEL; DEITEL, 2011, cap. 10).

```c
Time tabela[] = {
    {"Bahia", 8, 5, 3},
    {"Flamengo", 9, 6, 1},
};
```

- **Cópia inteira**: `tabela[i] = tabela[j]` copia o time todo. Ao ordenar,
  troque as structs, não campo a campo (BACKES, 2013, cap. 8).
- **Guardar o índice**: o índice diz **onde** está o elemento e permite mexer
  nele (`tabela[lider].vitorias++`); uma cópia fica desligada da tabela.

> [!WARNING]
> O C não confere limites: `tabela[4]` num vetor de 4 times lê lixo ou derruba
> o programa. E trocar só o nome ao ordenar embaralha nomes e pontos.

{{exemplo}}

Quatro times na tabela do campeonato. O programa calcula os pontos de cada um
(3 por vitória, 1 por empate) e guarda o **índice** do melhor até agora.
Palmeiras, no índice 2, termina na frente:

{{ideia}}

```c
#include <stdio.h>

typedef struct {
    char nome[20];
    int vitorias;
    int empates;
    int derrotas;
} Time;

int pontos(Time t) {
    return 3 * t.vitorias + t.empates;
}

int main(void) {
    Time tabela[] = {
        {"Bahia", 8, 5, 3},
        {"Flamengo", 9, 6, 1},
        {"Palmeiras", 10, 4, 2},
        {"Vasco", 7, 7, 2},
    };
    int n = sizeof tabela / sizeof tabela[0]; // 4 times

    int lider = 0; // índice do melhor até agora
    for (int i = 0; i < n; i++) {
        printf("%d. %-10s %2d pts\n", i, tabela[i].nome, pontos(tabela[i]));
        if (pontos(tabela[i]) > pontos(tabela[lider])) {
            lider = i;
        }
    }
    printf("Líder: %s, com %d pontos\n", tabela[lider].nome, pontos(tabela[lider]));
    printf("A tabela ocupa %zu bytes (%d x %zu)\n", sizeof tabela, n, sizeof(Time));
    return 0;
}
// Saída:
// 0. Bahia      29 pts
// 1. Flamengo   33 pts
// 2. Palmeiras  34 pts
// 3. Vasco      28 pts
// Líder: Palmeiras, com 34 pontos
// A tabela ocupa 128 bytes (4 x 32)
```

É o padrão "maior até agora" do módulo de laços, comparando um valor calculado
de cada struct:

{{fluxograma}}
