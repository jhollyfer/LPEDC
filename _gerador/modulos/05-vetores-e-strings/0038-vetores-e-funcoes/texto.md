## 0038 · Vetores e funções

- **Vetor como argumento**: o C não copia o vetor; passa **o endereço onde ele
  começa**. Por isso a função mexe no vetor original (DEITEL; DEITEL, 2011,
  cap. 6).
- **Sintaxe**: no parâmetro, colchetes vazios (`double precos[]`); na chamada,
  só o nome (`cardapio`). Um número dentro dos colchetes do parâmetro é
  ignorado (BACKES, 2013, cap. 9).
- **Tamanho junto**: só o endereço chega, então o tamanho vai num parâmetro à
  parte. Vetor + tamanho é um par do curso inteiro (BACKES, 2013, cap. 9).
- **`const`**: `const double precos[]` promete só ler; escrever nele é erro de
  compilação (DEITEL; DEITEL, 2011, cap. 6).
- **Elemento sozinho**: `cardapio[0]` vai por valor, como qualquer `double`
  (DEITEL; DEITEL, 2011, cap. 6).
- **Custo**: passar um vetor custa um endereço (8 bytes), tenha ele 4 itens ou
  um milhão. No módulo 06 esse endereço vira **ponteiro** (KERNIGHAN; RITCHIE,
  1989, cap. 5).

```c
void reajustar(double precos[], int n, double percentual); // protótipo
reajustar(cardapio, 4, 10);                                // chamada
```

> [!WARNING]
> **`sizeof` dentro da função não dá o tamanho do vetor.** Em `reajustar`,
> `sizeof(precos)` vale 8, o tamanho de um endereço. O gcc avisa
> (`-Wsizeof-array-argument`).

{{exemplo}}

A lanchonete reajusta o cardápio em 10%. A função recebe o endereço de
`cardapio` em `precos`, e cada `precos[i]` é a mesma gaveta que `cardapio[i]`:

{{ideia}}

```c
#include <stdio.h>

#define ITENS 4

// const: esta função promete só ler o vetor
void mostrar(const double precos[], int n) {
    for (int i = 0; i < n; i++) {
        printf("R$ %6.2f\n", precos[i]);
    }
}

// sem const: esta função escreve nas gavetas do vetor de quem chamou
void reajustar(double precos[], int n, double percentual) {
    for (int i = 0; i < n; i++) {
        precos[i] = precos[i] * (1 + percentual / 100);
    }
}

int main(void) {
    double cardapio[ITENS] = {12.50, 8.00, 22.90, 5.50};

    reajustar(cardapio, ITENS, 10); // vai o vetor (sem colchetes) e o tamanho

    printf("Depois do reajuste de 10%%:\n");
    mostrar(cardapio, ITENS);
    return 0;
}
// Saída:
// Depois do reajuste de 10%:
// R$  13.75
// R$   8.80
// R$  25.19
// R$   6.05
```

A função é `void`, mas o `main` enxerga os preços novos, porque ela escreveu
direto no vetor dele:

{{fluxograma}}
