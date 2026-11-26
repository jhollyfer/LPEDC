## 0073 · Invariantes de laço e corretude

Você escreveu um laço que acha o maior Pix do dia e testou com três vetores.
Funcionou nos três. Isso prova que ele acerta **naqueles** três vetores, e
mais nada. Para ter certeza de que acerta com qualquer entrada, inclusive as
que você não pensou em testar, é preciso um argumento, e não mais testes.

Pense no caixa da lanchonete. No fim do expediente, troco inicial mais vendas
tem de bater com o dinheiro da gaveta. Essa conta não vale só no fim: depois
de **cada** cliente, "gaveta = troco + vendas até agora" continua verdadeira.
Se em algum momento não bater, você sabe que o erro foi naquele cliente. Um
laço bem escrito tem uma frase desse tipo. O **invariante de laço** é uma
relação entre as variáveis que vale **no começo de cada iteração**, logo antes
do teste do laço. Ele serve para explicar o que o laço faz e para provar que
o laço está certo (FEOFILOFF, 2009).

Para escrever invariantes sobre vetores, use a notação `v[0..i-1]`: os
elementos de índice 0 até i − 1. Quando i vale 0, o trecho é vazio. Com ela,
o invariante de "achar o maior" fica: **`maior` é um máximo de
`v[0..i-1]`** (FEOFILOFF, 2009). A frase diz o que o laço já sabe sobre a
parte que viu, e não como ele anda. No começo da volta com i = 4, os quatro
primeiros Pix já foram vistos, e `maior` guarda o maior deles.

Mostrar que um laço está certo com o invariante tem quatro passos, no mesmo
espírito de uma prova por indução, que vale para o primeiro caso e passa de
um caso ao seguinte (CORMEN et al., 2024, cap. 2):

1. **Início**: o invariante vale antes da primeira volta.
2. **Manutenção**: se vale no começo de uma volta, vale no começo da seguinte.
3. **Término**: quando o teste falha, invariante + condição de parada dão o
   resultado.
4. **Parada**: uma quantidade inteira, a **variante**, diminui a cada volta.

No laço do maior, com `maior = v[0]` e i = 1, o **início** vale: um elemento
sozinho é o máximo dele mesmo. Na **manutenção**, se `maior` é o máximo de
`v[0..i-1]`, a volta compara com `v[i]` e fica com o maior dos dois; agora
`maior` é o máximo de `v[0..i]`, e o `i++` devolve a frase à forma original.
No **término**, o teste `i < n` falha com i == n, e o invariante passa a dizer
"`maior` é um máximo de `v[0..n-1]`", o vetor inteiro: é a resposta.

Os três primeiros passos mostram que, **se** o laço acabar, a resposta está
certa. O quarto mostra que ele acaba. A **variante** é uma quantidade inteira
que diminui a cada volta e não pode diminuir para sempre. No laço do maior,
é n − i: começa em n − 1, perde 1 por volta e chega a 0, e aí o laço para.

O mesmo raciocínio melhora a documentação. O comentário de uma função é um
**contrato**: diz o que ela faz, e não como. "Recebe n ≥ 1 e v; devolve o
valor de **um** elemento máximo de `v[0..n-1]`" cobre todos os parâmetros,
diz a restrição (n ≥ 1, porque com o vetor vazio não há máximo) e usa "um"
porque pode haver empate (FEOFILOFF, 2009). Quem chama a função lê só isso e
sabe o que esperar.

Para conferir um invariante enquanto o programa roda, use o `assert(cond)`,
de `<assert.h>`. Se `cond` for falsa, ele mostra o arquivo, a linha e a
condição, e encerra o programa na hora. Compilado com `-DNDEBUG`, o `assert`
vira nada, e nem a condição é calculada (CPPREFERENCE, s.d.). Por isso você
pode pôr dentro dele uma conferência lenta, só para teste, que não custa
nada na versão final.

> [!WARNING]
> O erro clássico é o **início**: `int maior = 0;` passa nos testes com
> valores positivos, mas com −120, −45, −300 devolve 0, que nem está no vetor.
> Comece com `maior = v[0]` e i = 1. E nunca ponha dentro do `assert` algo que
> o programa precisa fazer, como `assert(fp = fopen(...))`: com `-DNDEBUG`,
> some.

{{exemplo}}

Os Pix do dia foram 120, 45, 300, 80, 210 e 95. No começo da volta com i = 4, a
parte verde já foi vista e `maior` (300) é o maior dela:

{{ideia}}

O `assert` transforma o invariante em código. A `eh_maximo` é lenta de
propósito: confere o invariante pelo caminho ingênuo, só para testar.

```c
#include <assert.h>
#include <stdbool.h>
#include <stdio.h>

// Devolve true se x é um máximo de v[0..i-1]: x está lá e ninguém passa dele.
bool eh_maximo(const int v[], int i, int x) {
    bool esta = false;
    for (int k = 0; k < i; k++) {
        if (v[k] > x) {
            return false;
        }
        if (v[k] == x) {
            esta = true;
        }
    }
    return esta;
}

// Recebe n >= 1 e v; devolve o valor de um elemento máximo de v[0..n-1].
int maximo(const int v[], int n) {
    int maior = v[0];
    int i = 1;
    while (i < n) {
        // invariante: maior é um máximo de v[0..i-1]
        assert(eh_maximo(v, i, maior));
        printf("i = %d: maior = %d\n", i, maior);
        if (v[i] > maior) {
            maior = v[i];
        }
        i++;
    }
    // na saída, i == n: o invariante diz que maior é um máximo de v[0..n-1]
    assert(eh_maximo(v, n, maior));
    return maior;
}

int main(void) {
    int pix[6] = {120, 45, 300, 80, 210, 95};

    printf("Maior Pix: R$ %d\n", maximo(pix, 6));
    return 0;
}
// Saída:
// i = 1: maior = 120
// i = 2: maior = 120
// i = 3: maior = 300
// i = 4: maior = 300
// i = 5: maior = 300
// Maior Pix: R$ 300
```

### Passo a passo

Os quatro passos neste laço, com o teste de mesa:

| começo da volta | i | `v[0..i-1]` | maior | invariante vale? |
| --- | --- | --- | --- | --- |
| 1ª | 1 | 120 | 120 | sim: um elemento só é o máximo dele mesmo (**início**) |
| 2ª | 2 | 120, 45 | 120 | sim: 45 não passou de 120 |
| 3ª | 3 | 120, 45, 300 | 300 | sim: 300 passou e virou o maior |
| 4ª | 4 | ..., 80 | 300 | sim |
| 5ª | 5 | ..., 210 | 300 | sim |
| teste falha | 6 | o vetor todo | 300 | sim, e i == n: é a resposta (**término**) |

**Manutenção**: se `maior` é o máximo de `v[0..i-1]`, a volta compara com
`v[i]` e fica com o maior dos dois: `maior` passa a ser o máximo de `v[0..i]`,
e o `i++` devolve a forma "máximo de `v[0..i-1]`". **Parada**: n − i diminui 1
por volta e o laço acaba em 0.

No fluxograma, o invariante fica na seta que volta ao losango "i < 6?". Toda
vez que o caminho passa ali, a frase é verdadeira:

{{fluxograma}}
