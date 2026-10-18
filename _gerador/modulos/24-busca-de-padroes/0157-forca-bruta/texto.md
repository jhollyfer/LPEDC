## 0157 · Força bruta

Você aperta Ctrl+F no PDF do contrato de aluguel e digita "multa". Em menos de
um segundo, o leitor pinta todas as ocorrências. Por trás disso há um problema
clássico: achar um **padrão** (a palavra procurada) dentro de um **texto**. Ele
aparece no editor, no `grep`, no antivírus, na análise de DNA e no filtro de
spam.

Os nomes de sempre: o texto tem `n` letras e o padrão tem `m`, com `m <= n`. Um
**alinhamento** é encostar o padrão no texto a partir de uma posição `i`. Se as
`m` letras batem com `texto[i..i+m-1]`, há uma **ocorrência** em `i`.

A **força bruta** (ou busca ingênua) testa todos os alinhamentos, um por um:
`i = 0, 1, 2, ..., n - m`. Em cada um, compara letra a letra da esquerda para a
direita e desiste na primeira diferença. São `n - m + 1` alinhamentos: o último
começa em `n - m`, porque depois dele o padrão não cabe mais.

Ocorrências podem se **sobrepor**: em "banana", o "ana" aparece em 1 e em 3,
dividindo o "a" do meio. A força bruta acha as duas porque avança o alinhamento
de 1 em 1, aconteça o que acontecer.

Quanto custa? Num texto comum, quase todo alinhamento falha na primeira ou na
segunda letra, e o total fica perto de `n` comparações. No **pior caso**, cada
alinhamento compara quase o padrão inteiro antes de falhar: até
`(n - m + 1) · m` comparações, que é **O(n·m)**. Procurar `"00001"` num código
de vinte zeros faz isso (veja o A314). Os próximos três assuntos são três jeitos
de trabalhar menos que isso.

Vamos ver na prática. A placa da feira diz "banana bacana" e você procura "ana".
São 11 alinhamentos. No 0, o "b" já não bate. No 1, as três letras batem:
ocorrência. No 5, o "a" bate e o espaço não. No 10, ocorrência de novo:

{{ideia}}

O mesmo exemplo em C, contando as comparações de letra:

```c
#include <stdio.h>
#include <string.h>

// mostra cada posição onde o padrão aparece; devolve quantas vezes apareceu
int forca_bruta(const char *texto, const char *padrao, int *comparacoes) {
    int n = (int) strlen(texto);
    int m = (int) strlen(padrao);
    int achados = 0;
    *comparacoes = 0;
    for (int i = 0; i <= n - m; i++) {    // cada alinhamento possível
        int j = 0;
        while (j < m) {
            (*comparacoes)++;
            if (texto[i + j] != padrao[j]) {
                break;                    // errou uma letra: desiste daqui
            }
            j++;
        }
        if (j == m) {                     // as m letras bateram
            printf("  achou na posição %d\n", i);
            achados++;
        }
    }
    return achados;
}

int main(void) {
    const char *placa = "banana bacana";
    int comparacoes;

    printf("Procurando \"ana\" em \"%s\":\n", placa);
    int total = forca_bruta(placa, "ana", &comparacoes);
    printf("%d ocorrências, %d comparações\n", total, comparacoes);
    return 0;
}
// Saída:
// Procurando "ana" em "banana bacana":
//   achou na posição 1
//   achou na posição 3
//   achou na posição 10
// 3 ocorrências, 19 comparações
```

### Passo a passo

As 19 comparações, alinhamento por alinhamento (o texto tem `n = 13` letras, o
padrão `m = 3`):

| i | trecho do texto | comparações | resultado |
| --- | --- | --- | --- |
| 0 | `ban` | 1 (`b` ≠ `a`) | falha |
| 1 | `ana` | 3 | **ocorrência** |
| 2 | `nan` | 1 | falha |
| 3 | `ana` | 3 | **ocorrência** |
| 4 | `na␣` | 1 | falha |
| 5 | `a␣b` | 2 (o espaço ≠ `n`) | falha |
| 6, 7 | `␣ba`, `bac` | 1 cada | falha |
| 8 | `aca` | 2 (`c` ≠ `n`) | falha |
| 9 | `can` | 1 | falha |
| 10 | `ana` | 3 | **ocorrência** |

O teto seria `11 · 3 = 33`. Deu 19 porque a maioria dos alinhamentos falha cedo.

Repara no fluxograma: dois laços, um dentro do outro. O de fora anda o
alinhamento `i`; o de dentro anda a letra `j`. O `i` sempre avança 1, tenha
achado ou não:

{{fluxograma}}

A biblioteca já tem essa busca pronta: `strstr(texto, padrao)`, de `string.h`,
devolve um ponteiro para a primeira ocorrência, ou `NULL` se não houver. A
posição é a diferença de endereços, `p - texto`. Para achar a próxima, chame de
novo a partir de `p + 1` (o exemplo A313 mostra a diferença entre recomeçar em
`p + 1` e em `p + m`).

> [!WARNING]
> O laço vai até `i <= n - m`, **inclusive**. Com `i < n - m`, a ocorrência que
> encosta no fim do texto (o "ana" da posição 10) some. E guarde `n` e `m` em
> `int`: o `strlen` devolve `size_t`, que não tem sinal. Se o padrão for maior
> que o texto, `n - m` em `size_t` não fica negativo, **dá a volta** e vira um
> número enorme. O laço sai lendo memória além do `'\0'` (o exercício E941 cai
> nessa).

> [!TIP]
> **Por dentro do C:** o texto é um vetor de `char` contíguo, então o laço de
> dentro lê bytes vizinhos, e o cache do processador adora isso. A força bruta
> não gasta memória extra nenhuma: O(1). O `strstr` da glibc não é a força bruta
> deste assunto: para padrões maiores ele usa o algoritmo **Two-Way**, que é
> linear no pior caso, e instruções que comparam vários bytes de uma vez. Repara
> também que `strstr` recebe `const char *` e devolve `char *` sem `const`: se
> o texto era um literal, escrever pelo ponteiro devolvido é comportamento
> indefinido (assunto 0048).

> [!NOTE]
> **Pergunta para você:** quantas comparações a força bruta faz para procurar
> "aaab" em "aaaaaaaaab" (nove "a" e um "b")? E para procurar "baaa" no mesmo
> texto? Conte no papel e depois troque os valores no código para conferir.

{{pratique}}
