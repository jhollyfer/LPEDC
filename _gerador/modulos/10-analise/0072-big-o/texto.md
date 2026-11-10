## 0072 · Notação O: como o custo cresce

Você fez o app da hamburgueria. Com 8 pedidos, voou; com 64 por noite, tudo
bem; na Black Friday, com 1024, uma tela travou. O código não mudou, o **n**
sim, e cada parte reagiu de um jeito.

O assunto anterior contou passos. Agora a pergunta é **como a contagem cresce
quando n cresce**, e a **notação O** (fala-se "ó grande") responde com uma
expressão curta. Ela ignora de propósito:

- **constantes multiplicativas**: 3n e 100n são ambos O(n). A constante
  depende da máquina; o formato do crescimento, não;
- **termos menores**: em n² + 50n + 7, o n² domina quando n cresce. Com
  n = 1000, ele vale 1.000.000 e o 50n só 50.000. Fica O(n²).

Definição formal (Cormen): f(n) é **O(g(n))** se existem c > 0 e n₀ com
0 ≤ f(n) ≤ c · g(n) para todo n ≥ n₀. É um **teto**: "nunca cresce mais rápido
que g". **Ω** é o piso (f ≥ c · g) e **Θ**, teto e piso juntos: n² + 50n + 7
é Θ(n²) (assunto 0166). As cinco classes do curso, da melhor para a pior:

| classe | nome | n dobra, o custo... | exemplo |
| --- | --- | --- | --- |
| O(1) | constante | fica igual | `v[i]`, topo da pilha |
| O(log n) | logarítmica | ganha **1** passo | busca binária |
| O(n) | linear | dobra | somar um vetor |
| O(n log n) | "n log n" | pouco mais que dobra | merge sort |
| O(n²) | quadrática | **quadruplica** | comparar todos os pares |

Para ler a classe de um código, olhe os laços. Um laço de 1 em 1 até n é
O(n). Dois aninhados até n, O(n²). Um laço que **divide** n por 2 a cada
volta é O(log n): de 1024 até 1 são 10 cortes, porque 2¹⁰ = 1024. A base do
log não importa: trocar log₂ por log₁₀ só muda uma constante.

O exemplo faz cinco perguntas sobre os mesmos pedidos, cada uma com seu ritmo.
Em verde, o que continua leve em 1024; em vermelho, o que explodiu:

{{ideia}}

Cada função conta os passos de uma pergunta:

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

Na última coluna, comparar todos os pares dá n(n − 1)/2, cerca de n²/2. A
metade é constante e some: continua O(n²). De 64 para 1024, n cresceu 16
vezes, essa coluna 260 vezes, e a do log ganhou 4 passos.

O fluxograma mostra o laço do O(log n) com n = 1024. "n > 1?" responde Sim só
10 vezes, porque cada volta joga metade fora:

{{fluxograma}}

> [!WARNING]
> O(n) não é "sempre mais rápido" que O(n²): a notação fala do
> **crescimento**, não do tempo para um n específico. Um algoritmo de 100n
> passos perde de um de n² só a partir de n = 100 (o A144 mostra a virada).
> Para 10 itens, o simples costuma ganhar. A pegadinha inversa: um laço O(n)
> que chama a cada volta uma função O(n) dá **O(n²)**. Exemplo clássico: o
> `strlen(s)` na condição do `for`.

> [!TIP]
> **Por dentro do C:** `v[i]` é O(1) porque o vetor é contínuo e o endereço
> sai de uma conta: `endereço de v + i * sizeof(int)`. Numa lista encadeada
> (módulo 11) não há essa conta: chegar ao elemento i exige seguir i
> ponteiros, O(n). A estrutura de dados decide a classe antes do algoritmo.

> [!NOTE]
> **Pergunta para você:** se um algoritmo O(n²) leva 1 segundo com 10.000
> pedidos, quanto ele leva com 100.000? E um O(n log n) que também leva 1
> segundo com 10.000? Faça a conta antes de olhar os exercícios.

{{pratique}}
