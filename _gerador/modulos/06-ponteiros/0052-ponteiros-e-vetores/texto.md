## 0052 · Ponteiros e vetores

Numa rua de loteamento, os números das casas sobem de 4 em 4: 1000, 1004,
1008. Se alguém diz "três casas depois da 1000", você não anda 3 números:
anda 3 casas e chega na 1012. Os ponteiros fazem essa conta por você.

Num vetor, as gavetas ficam coladas (assunto 0049). E quase sempre que o
nome do vetor aparece numa expressão, ele **vira** o endereço do primeiro
elemento: `kwh` vale o mesmo que `&kwh[0]`. É por isso que você passa um
vetor para uma função sem `&` e ela altera o original (assunto 0043): ela
recebe esse endereço.

Com um ponteiro para dentro de um vetor, vale a **aritmética de ponteiros**:

- `p + 1` é o endereço do **próximo elemento**, não do próximo byte. O C
  multiplica pelo tamanho do tipo: num `int *`, `p + 1` anda 4 bytes; num
  `double *`, anda 8;
- `p++` avança o ponteiro um elemento; `p--` volta um;
- `q - p` (dois ponteiros do mesmo vetor) dá **quantos elementos** há entre
  eles;
- `p < q` compara posições, mas só faz sentido dentro do mesmo vetor.

Daí sai a regra mais importante do assunto: **`v[i]` é exatamente
`*(v + i)`**. O colchete é só um jeito curto de escrever "ande `i`
elementos e pegue o que tem lá". Vale para vetor e vale para ponteiro:
`p[2]` é `*(p + 2)`, contado a partir de onde `p` aponta **agora**.

Mas vetor **não é** ponteiro. `sizeof kwh` dá o vetor inteiro (20 bytes),
`sizeof p` dá 8. E `kwh = outro;` ou `kwh++` não compilam: o nome do vetor
é um endereço fixo, não uma variável que guarda endereço. O certo é dizer
que o vetor **decai** para ponteiro.

Vamos ver na prática. O consumo de luz de 5 meses está em `kwh`. O ponteiro
`p` começa em `kwh` (gaveta `0x1000`) e anda uma gaveta de cada vez,
somando o que encontra. Quando `p` chega em `kwh + 5`, a gaveta "um depois
do último", o laço para:

{{ideia}}

O mesmo percurso no código, mostrando o endereço a cada passo:

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

O `const int *p` diz que o laço só **lê** pelo ponteiro: `*p = 0` ali dentro
não compilaria. O ponteiro em si pode andar à vontade.

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

`kwh + 5` é `0x1014`: pode ser calculado e comparado, mas nunca lido.

Repara no fluxograma: é o laço de acumulador do assunto 0030, só que quem
anda é o ponteiro, não um índice:

{{fluxograma}}

> [!WARNING]
> `*p + 1` e `*(p + 1)` são coisas diferentes. O `*` vem antes do `+`, então
> `*p + 1` pega o valor e soma 1 (211); `*(p + 1)` anda uma gaveta e pega o
> valor dela (185). Na mesma família: `*p++` lê o valor e **depois** avança o
> ponteiro (o `++` vale para `p`), enquanto `(*p)++` soma 1 no valor. E
> passar do fim (`p <= kwh + 5`) lê a gaveta de outra variável: o C não
> confere, o AddressSanitizer acusa `stack-buffer-overflow`.

> [!TIP]
> **Por dentro do C:** para o compilador, `kwh[i]` é `*(kwh + i)`, e o
> endereço calculado é `kwh + i * sizeof(int)`, uma multiplicação e uma
> soma que o processador faz numa instrução só. Como a soma é comutativa,
> `i[kwh]` também compila e dá o mesmo valor. É uma curiosidade famosa;
> nunca escreva isso. E por que o laço com `p++` e o laço com `i++` dão o
> mesmo desempenho? Porque o otimizador transforma um no outro. Escolha o
> que deixa o código mais claro, quase sempre o índice.

> [!NOTE]
> **Pergunta para você:** com `int *p = &kwh[1];` e depois `p += 2;`, quanto
> valem `*p`, `p[1]`, `p[-1]` e `p - kwh`?

{{pratique}}
