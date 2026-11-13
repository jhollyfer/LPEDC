## 0072 · Notação O: como o custo cresce

- **Notação O** ("ó grande"): diz como a contagem de passos cresce quando n
  cresce (CORMEN et al., 2024, cap. 3).
- **Ignora constantes**: 3n e 100n são ambos O(n). A constante depende da
  máquina; o formato do crescimento, não (CELES; RANGEL, 2002).
- **Ignora termos menores**: em n² + 50n + 7, com n = 1000, o n² vale 1.000.000
  e o 50n só 50.000. Fica O(n²) (ZIVIANI, 2010, cap. 1).
- **Definição**: f(n) é **O(g(n))** se existem c > 0 e n₀ com
  0 ≤ f(n) ≤ c · g(n) para todo n ≥ n₀. É um **teto** (CORMEN et al., 2024, cap. 3).
- **Ω e Θ**: Ω é o piso e Θ, teto e piso juntos: n² + 50n + 7 é Θ(n²)
  (assunto 0166) (CORMEN et al., 2024, cap. 3).
- **Ler a classe nos laços**: de 1 em 1 até n é O(n); dois aninhados, O(n²);
  um que **divide** n por 2 a cada volta, O(log n). De 1024 até 1 são 10
  cortes. A base do log não importa (FEOFILOFF, 2009).
- **Acesso O(1)**: `v[i]` sai de uma conta de endereço. Numa lista encadeada,
  chegar ao elemento i exige seguir i ponteiros, O(n)
  (CELES; CERQUEIRA; RANGEL, 2016).

| classe | nome | n dobra, o custo... | exemplo |
| --- | --- | --- | --- |
| O(1) | constante | fica igual | `v[i]`, topo da pilha |
| O(log n) | logarítmica | ganha **1** passo | busca binária |
| O(n) | linear | dobra | somar um vetor |
| O(n log n) | "n log n" | pouco mais que dobra | merge sort |
| O(n²) | quadrática | **quadruplica** | comparar todos os pares |

> [!WARNING]
> O(n) não é "sempre mais rápido" que O(n²): um algoritmo de 100n passos perde
> de um de n² até n = 100. E um laço O(n) que chama a cada volta uma função O(n)
> dá **O(n²)**, como o `strlen(s)` na condição do `for`.

{{exemplo}}

O app da hamburgueria faz cinco perguntas sobre os mesmos pedidos, com 8, 64 e
1024 pedidos. Em verde, o que continua leve em 1024; em vermelho, o que
explodiu:

{{ideia}}

```c
#include <stdio.h>

// O(1): qual é o primeiro pedido da fila? Basta olhar a posição 0.
long passos_constante(int n) {
    (void)n;
    return 1;
}

// O(log n): cortar a lista ordenada ao meio até sobrar 1 pedido.
long passos_log(int n) {
    long passos = 0;
    while (n > 1) {
        n = n / 2;
        passos++;
    }
    return passos;
}

// O(n): somar o faturamento, olhando cada pedido uma vez.
long passos_linear(int n) {
    long passos = 0;
    for (int i = 0; i < n; i++) {
        passos++;
    }
    return passos;
}

// O(n log n): para cada pedido de hoje, uma busca binária na lista de ontem.
long passos_n_log_n(int n) {
    long passos = 0;
    for (int i = 0; i < n; i++) {
        passos += passos_log(n);
    }
    return passos;
}

// O(n²): comparar cada pedido com todos os outros, atrás de duplicados.
long passos_quadratico(int n) {
    long passos = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            passos++;
        }
    }
    return passos;
}

int main(void) {
    int tamanhos[3] = {8, 64, 1024};

    printf("%6s %5s %6s %6s %8s %8s\n", "n", "O(1)", "log n", "n", "n log n", "n^2");
    for (int k = 0; k < 3; k++) {
        int n = tamanhos[k];
        printf("%6d %5ld %6ld %6ld %8ld %8ld\n", n, passos_constante(n), passos_log(n),
               passos_linear(n), passos_n_log_n(n), passos_quadratico(n));
    }
    return 0;
}
// Saída:
//      n  O(1)  log n      n  n log n      n^2
//      8     1      3      8       24       28
//     64     1      6     64      384     2016
//   1024     1     10   1024    10240   523776
```

Comparar todos os pares dá n(n − 1)/2, cerca de n²/2: continua O(n²). De 64
para 1024, n cresceu 16 vezes, a última coluna 260 vezes e a do log ganhou 4
passos. O fluxograma mostra o laço do O(log n) com n = 1024: "n > 1?" responde
Sim só 10 vezes:

{{fluxograma}}
