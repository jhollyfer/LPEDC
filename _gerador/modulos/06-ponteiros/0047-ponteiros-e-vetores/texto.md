## 0047 · Ponteiros e vetores

Numa rua de loteamento, os números das casas sobem de 4 em 4: 1000, 1004,
1008. "Três casas depois da 1000" é a 1012, não a 1003. Os ponteiros fazem essa
conta por você.

Num vetor, as gavetas ficam coladas (assunto 0044). E o nome do vetor, numa
expressão, quase sempre **vira** o endereço do primeiro elemento: `kwh` vale
`&kwh[0]`. Por isso você passa um vetor sem `&` e a função altera o original
(assunto 0038): ela recebe esse endereço.

Com um ponteiro dentro de um vetor vale a **aritmética de ponteiros**:

- `p + 1` é o endereço do **próximo elemento**, não do próximo byte: o C
  multiplica pelo tamanho do tipo (4 bytes num `int *`, 8 num `double *`);
- `p++` avança um elemento; `p--` volta um;
- `q - p` (mesmo vetor) dá **quantos elementos** há entre eles;
- `p < q` compara posições, só com sentido dentro do mesmo vetor.

Daí a regra central: **`v[i]` é exatamente `*(v + i)`**, ou seja, "ande `i`
elementos e pegue o que tem lá". Vale para ponteiro também: `p[2]` é
`*(p + 2)`, contado de onde `p` aponta **agora**.

Mas vetor **não é** ponteiro. `sizeof kwh` dá o vetor inteiro (20 bytes),
`sizeof p` dá 8. E `kwh = outro;` ou `kwh++` não compilam: o nome do vetor é
um endereço fixo. Diz-se que o vetor **decai** para ponteiro.

Na matriz (assunto 0039) a regra vale em dois níveis: `m[i][j]` é
`*(*(m + i) + j)`. Em `int m[3][4]`, cada elemento de `m` é uma linha inteira,
então `m + 1` anda **16 bytes** (4 `int`) e `m[0] + 1` anda só 4. Prova adora
essa diferença.

O consumo de luz de 5 meses está em `kwh`. O ponteiro `p` começa em `kwh`
(gaveta `0x1000`) e anda uma gaveta por vez, somando. Quando chega a `kwh + 5`,
"um depois do último", o laço para:

{{ideia}}

O mesmo percurso no código, com o endereço a cada passo:

```c
#include <stdio.h>

int main(void) {
    int kwh[5] = {210, 185, 240, 198, 225}; // consumo de 5 meses
    int soma = 0;

    // kwh sozinho vira &kwh[0]; kwh + 5 é "um depois do último"
    for (const int *p = kwh; p < kwh + 5; p++) {
        printf("p = %p  *p = %d\n", (void *)p, *p);
        soma += *p;
    }
    printf("Total: %d kWh  Média: %.1f kWh\n", soma, soma / 5.0);

    // as duas notações são a mesma conta
    printf("kwh[3] = %d  *(kwh + 3) = %d\n", kwh[3], *(kwh + 3));
    return 0;
}
// Saída (os endereços mudam a cada execução; repare que sobem de 4 em 4):
// p = 0x7fa4cb400020  *p = 210
// p = 0x7fa4cb400024  *p = 185
// p = 0x7fa4cb400028  *p = 240
// p = 0x7fa4cb40002c  *p = 198
// p = 0x7fa4cb400030  *p = 225
// Total: 1058 kWh  Média: 211.6 kWh
// kwh[3] = 198  *(kwh + 3) = 198
```

O `const int *p` diz que o laço só **lê** pelo ponteiro: `*p = 0` não
compilaria. O ponteiro em si pode andar.

### Passo a passo

Com os endereços fictícios do desenho (`kwh` em `0x1000`):

| volta | `p` | `*p` | `soma` depois | `p < kwh + 5`? |
| --- | --- | --- | --- | --- |
| 1 | 0x1000 | 210 | 210 | sim |
| 2 | 0x1004 | 185 | 395 | sim |
| 3 | 0x1008 | 240 | 635 | sim |
| 4 | 0x100C | 198 | 833 | sim |
| 5 | 0x1010 | 225 | 1058 | sim |
| fim | 0x1014 | (não lê) | 1058 | **não**: para |

`kwh + 5` é `0x1014`: pode ser calculado e comparado, nunca lido.

É o acumulador do assunto 0025, mas quem anda é o ponteiro, não um índice:

{{fluxograma}}

> [!WARNING]
> `*p + 1` e `*(p + 1)` diferem. O `*` vem antes do `+`: `*p + 1` pega o valor e
> soma 1 (211); `*(p + 1)` anda uma gaveta e pega o valor dela (185). Do mesmo
> tipo: `*p++` lê o valor e **depois** avança o ponteiro, enquanto `(*p)++` soma 1
> no valor. E passar do fim (`p <= kwh + 5`) lê a gaveta de outra variável: o
> AddressSanitizer acusa `stack-buffer-overflow`.

> [!TIP]
> **Por dentro do C:** `kwh[i]` é `*(kwh + i)`, no endereço
> `kwh + i * sizeof(int)`. Como a soma é comutativa, `i[kwh]` também compila;
> nunca escreva isso. Os laços com `p++` e com `i++` têm o mesmo desempenho;
> prefira o índice, quase sempre mais claro.

> [!NOTE]
> **Pergunta para você:** com `int *p = &kwh[1];` e depois `p += 2;`, quanto
> valem `*p`, `p[1]`, `p[-1]` e `p - kwh`?

{{pratique}}
