## 0105 · A ideia e a função hash

Na academia, o guarda-volumes tem 7 armários. A recepcionista não procura um
vago de porta em porta: aplica uma **regra** ao seu nome, e a regra devolve o
número do armário. Na saída, a mesma regra diz onde estão as suas coisas.

Acessar `v[i]` custa **O(1)**. Quando a chave é um número pequeno, ela serve
de índice: com `const char *estado[100]`, `estado[61]` é "DF" em um passo. É o
**endereçamento direto** (exemplo A209). Falha se a chave é grande (um CPF tem
11 dígitos) ou não é número (um nome).

A saída é uma **função hash**: ela recebe a chave e devolve um índice entre
`0` e `m - 1`, sendo `m` o tamanho da tabela. O vetor com os itens é a
**tabela hash**, e cada posição é um **balde**. Uma boa função é
**determinística** (mesma chave, mesmo índice), **rápida** e **espalhadora**
(chaves diferentes caem em baldes diferentes).

Para inteiros, vale o **método da divisão**: `h(k) = k mod m`, em C `k % m`.
O Cormen recomenda `m` primo e longe de uma potência de 2, porque com
`m = 2^p` o resto guarda só os `p` bits de baixo da chave. O **método da
multiplicação** fica para o assunto 0178. Para texto, o mais simples é somar
os códigos das letras e tirar o resto.

Há mais chaves possíveis do que baldes, então duas chaves diferentes **vão**
cair no mesmo balde: é a **colisão**. Ela não se evita; trata-se nos próximos
dois assuntos. O **fator de carga** `α = n / m` mede o aperto: 5 alunos em 7
armários dão α ≈ 0,71. Perto de 1 ou acima, a colisão aumenta.

Os alunos ana, davi, lia, bia e caio chegam nessa ordem; a regra é "soma dos
códigos das letras, resto por 7". "caio" soma 412, e 412 % 7 = 6; "bia" soma
300 e também dá 6, e chegou antes. Os outros três caem em armários livres:

{{ideia}}

No código, o vetor `dono` é a tabela e `NULL` é armário vazio. O programa só
**detecta** a colisão:

```c
#include <stdio.h>

#define ARMARIOS 7

// função hash: soma os códigos das letras e reduz para 0..6
int armario(const char *nome) {
    unsigned soma = 0;
    for (int i = 0; nome[i] != '\0'; i++) {
        soma += (unsigned char)nome[i]; // o byte da letra, sempre >= 0
    }
    return (int)(soma % ARMARIOS);
}

int main(void) {
    const char *dono[ARMARIOS] = {NULL}; // NULL = armário vazio
    const char *alunos[] = {"ana", "davi", "lia", "bia", "caio"};

    for (int i = 0; i < 5; i++) {
        int a = armario(alunos[i]);
        if (dono[a] == NULL) {
            dono[a] = alunos[i];
            printf("%-4s -> armário %d\n", alunos[i], a);
        } else {
            printf("%-4s -> armário %d (colisão com %s!)\n", alunos[i], a, dono[a]);
        }
    }
    return 0;
}
// Saída:
// ana  -> armário 3
// davi -> armário 0
// lia  -> armário 2
// bia  -> armário 6
// caio -> armário 6 (colisão com bia!)
```


O fluxograma mostra o caminho do "caio": quatro voltas no laço, índice 6,
armário ocupado, colisão:

{{fluxograma}}

> [!WARNING]
> A soma **não vê a ordem das letras**: "amor", "roma", "mora" e "ramo" somam
> 431 e caem no mesmo balde. Use o **polinômio** `h = h * 31 + letra`, que
> multiplica cada letra pela sua posição (exemplo A210).

> [!TIP]
> **Por dentro do C:** `char` tem sinal no gcc de PC, e o "ã" em UTF-8 vira
> bytes negativos, o que gera resto negativo (`-98 % 8` dá `-2`). Por isso a
> função usa `unsigned char` e acumula em `unsigned`, cujo estouro é definido
> (módulo 2³²); o de `int` é indefinido.

> [!NOTE]
> **Pergunta para você:** com 10 armários em vez de 7, quais alunos colidiriam?
> Use as somas (ana 304, davi 420, lia 310, bia 300, caio 412) antes de
> trocar `7` por `10` no código.

{{pratique}}
