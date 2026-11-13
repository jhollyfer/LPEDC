## 0047 · Ponteiros e vetores

Numa rua de loteamento, os números das casas sobem de 4 em 4: 1000, 1004,
1008. "Três casas depois da 1000" é a 1012, não a 1003. Num vetor de `int`
acontece o mesmo: as gavetas ficam coladas e cada item ocupa 4 bytes. Os
ponteiros sabem disso e fazem a conta por você, e é essa conta que liga
ponteiros e vetores.

Comece pelo nome do vetor. Numa expressão, ele quase sempre **vira** o
endereço do primeiro elemento: `kwh` vale `&kwh[0]`. Essa conversão se chama
**decaimento**; diz-se que o vetor decai para ponteiro (KERNIGHAN; RITCHIE,
1989, cap. 5). É por isso que você passa um vetor a uma função sem `&` e a
função altera o original (assunto 0038): ela recebe esse endereço.

Com um ponteiro dentro de um vetor, vale a **aritmética de ponteiros**. A
regra principal: `p + 1` é o endereço do **próximo elemento**, e não do
próximo byte. O C multiplica o 1 pelo tamanho do tipo apontado, 4 bytes num
`int *` e 8 num `double *`. Daí saem as outras operações. `p++` avança um
elemento e `p--` volta um. Se `p` e `q` apontam para o mesmo vetor, `q - p`
dá **quantos elementos** há entre eles, e `p < q` diz qual vem antes (DEITEL;
DEITEL, 2011, cap. 7). Comparar ponteiros de vetores diferentes não tem
sentido.

Juntando as peças, chega-se à regra central: **`v[i]` é exatamente
`*(v + i)`**. Ande `i` elementos a partir do começo e pegue o que tem lá. Os
colchetes são só um jeito mais curto de escrever essa conta, e por isso valem
para ponteiro também: `p[2]` é `*(p + 2)`, contado de onde `p` aponta
**agora**, e não do começo do vetor (DEITEL; DEITEL, 2011, cap. 7).

```c
int kwh[5] = {210, 185, 190, 240, 175};
int *p = &kwh[1];               // p aponta para o 185
printf("%d %d\n", p[0], p[2]);  // 185 240
printf("%td\n", p - kwh);       // 1 (elementos, não bytes)
```

Mesmo com tanta semelhança, vetor **não é** ponteiro. `sizeof kwh` dá o
tamanho do vetor inteiro (20 bytes), enquanto `sizeof p` dá 8, o tamanho de
um endereço. E o nome do vetor é um endereço fixo: `kwh = outro;` e `kwh++`
não compilam, enquanto `p++` é permitido (BACKES, 2013, cap. 10).

Na matriz (assunto 0039), a regra vale em dois níveis: `m[i][j]` é
`*(*(m + i) + j)`. O ponto que a prova adora é o tamanho do passo. Em
`int m[3][4]`, cada elemento de `m` é uma linha inteira, então `m + 1` anda
**16 bytes** (4 `int`). Já `m[0]` é a primeira linha, que decai para um
`int *`, e `m[0] + 1` anda só 4 bytes (BACKES, 2013, cap. 10).

Ao percorrer um vetor com ponteiro, o laço costuma parar em `kwh + 5`, o
endereço **um depois do último**. O C garante que esse endereço pode ser
calculado e comparado, mas nunca lido: não há elemento ali (KERNIGHAN;
RITCHIE, 1989, cap. 5). Os laços com `p++` e com `i++` têm o mesmo
desempenho; prefira o índice, que quase sempre fica mais claro.

> [!WARNING]
> `*p + 1` soma 1 ao valor; `*(p + 1)` anda uma gaveta e pega o valor dela,
> porque o `*` vem antes do `+`. `*p++` lê o valor e depois avança o
> ponteiro; `(*p)++` soma 1 no valor. E passar do fim (`p <= kwh + 5`) dá
> `stack-buffer-overflow` no AddressSanitizer.

{{exemplo}}

O consumo de luz de 5 meses está em `kwh`. O ponteiro `p` começa em `0x1000`
e anda uma gaveta por vez, somando, até chegar a `kwh + 5`:

{{ideia}}

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

O `const int *p` só lê pelo ponteiro, mas pode andar. É o acumulador do
assunto 0025, com o ponteiro no lugar do índice:

{{fluxograma}}

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
