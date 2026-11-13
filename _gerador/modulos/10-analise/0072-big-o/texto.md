## 0072 · Notação O: como o custo cresce

Você fez o app da hamburgueria. Com 8 pedidos por noite, voou; com 64, tudo
bem; na Black Friday, com 1024, uma tela travou. O código não mudou. Mudou o
**n**, o número de pedidos, e cada parte do programa reagiu de um jeito. O
assunto 0071 ensinou a contar passos para um n. Agora a pergunta é outra:
**como essa contagem cresce quando n cresce?**

Pense em duas contas de luz. Uma cobra R$ 10 fixos mais R$ 1 por kWh; a outra,
R$ 0 fixos mais R$ 0,01 por kWh ao quadrado. Num mês de pouco consumo, a
segunda sai mais barata. Mas o que decide qual é cara de verdade é o formato
da conta quando o consumo sobe, e não o valor fixo. A **notação O** (lê-se
"ó grande") descreve esse formato: ela diz como a contagem de passos cresce
quando n cresce, numa expressão curta como O(n) ou O(n²) (CORMEN et al.,
2024, cap. 3).

Para chegar a essa expressão, a notação descarta de propósito duas coisas. A
primeira são as **constantes multiplicativas**: 3n e 100n são ambos O(n). A
constante depende da máquina e de detalhes do código; o formato do
crescimento, não. Se n dobra, 3n e 100n dobram do mesmo jeito (CELES;
RANGEL, 2002).

A segunda são os **termos menores**. Em n² + 50n + 7, o n² manda quando n
cresce: com n = 1000, ele vale 1.000.000, o 50n vale 50.000 e o 7 quase
nada. A soma fica perto de n², e a classe é O(n²) (ZIVIANI, 2010, cap. 1).

A definição formal, no nome do Cormen, diz exatamente quando isso vale: f(n)
é **O(g(n))** se existem uma constante c > 0 e um ponto de partida n₀ tais
que 0 ≤ f(n) ≤ c · g(n) para todo n ≥ n₀ (CORMEN et al., 2024, cap. 3). Leia
assim: a partir de algum tamanho, f nunca passa de um múltiplo de g. É um
**teto**. Para n² + 50n + 7, c = 2 e n₀ = 51 funcionam, porque a partir daí
50n + 7 fica abaixo de n². Os valores pequenos de n, antes de n₀, não contam.

O O tem dois parentes. **Ω** (ômega) é o piso: f(n) ≥ c · g(n) a partir de
n₀, ou seja, f cresce pelo menos tanto quanto g. **Θ** (teta) é teto e piso
juntos, o crescimento exato: n² + 50n + 7 é Θ(n²). O assunto 0166 trata os
três com cuidado (CORMEN et al., 2024, cap. 3).

Para ler a classe de um código, olhe os laços (FEOFILOFF, 2009). Um laço que
anda de 1 em 1 até n é O(n). Dois laços aninhados, cada um até n, dão n
vezes n passos, O(n²). Um laço que **divide** n por 2 a cada volta é
O(log n): de 1024 até 1 são só 10 cortes, porque 2¹⁰ = 1024. A base do
logaritmo não importa, porque trocar log₂ por log₁₀ só multiplica por uma
constante, e a notação já descarta constantes.

A estrutura de dados também decide a classe. `v[i]` num vetor é O(1), porque
o vetor ocupa memória contínua e o endereço sai de uma conta só:
`endereço de v + i * sizeof(int)`. Numa lista encadeada, que aparece no
módulo 11, não existe essa conta: chegar ao elemento i exige seguir i
ponteiros, um depois do outro, e custa O(n) (CELES; CERQUEIRA; RANGEL, 2016).

As cinco classes que você vai encontrar no curso, da melhor para a pior. A
terceira coluna é o teste mais prático: o que acontece com o custo quando o
n dobra.

| classe | nome | n dobra, o custo... | exemplo |
| --- | --- | --- | --- |
| O(1) | constante | fica igual | `v[i]`, topo da pilha |
| O(log n) | logarítmica | ganha **1** passo | busca binária |
| O(n) | linear | dobra | somar um vetor |
| O(n log n) | "n log n" | pouco mais que dobra | merge sort |
| O(n²) | quadrática | **quadruplica** | comparar todos os pares |

> [!WARNING]
> O(n) não é "sempre mais rápido" que O(n²): a notação fala do crescimento,
> não do tempo para um n específico. Um algoritmo de 100n passos perde de um
> de n² até n = 100. E um laço O(n) que chama a cada volta uma função O(n) dá
> **O(n²)**, como o `strlen(s)` na condição do `for`.

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
