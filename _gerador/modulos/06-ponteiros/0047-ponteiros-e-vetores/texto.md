## 0047 · Ponteiros e vetores

- **Decaimento**: numa expressão, o nome do vetor quase sempre **vira** o
  endereço do primeiro elemento: `kwh` vale `&kwh[0]` (KERNIGHAN; RITCHIE,
  1989, cap. 5).
- **Aritmética de ponteiros**: `p + 1` é o **próximo elemento**, não o próximo
  byte; o C multiplica pelo tamanho do tipo. `p++` avança um, `q - p` dá
  quantos elementos há entre eles (DEITEL; DEITEL, 2011, cap. 7).
- **`v[i]` é `*(v + i)`**: ande `i` elementos e pegue o que tem lá. Vale para
  ponteiro: `p[2]` é `*(p + 2)`, contado de onde `p` aponta agora (DEITEL;
  DEITEL, 2011, cap. 7).
- **Vetor não é ponteiro**: `sizeof kwh` dá o vetor inteiro (20), `sizeof p`
  dá 8, e `kwh++` não compila (BACKES, 2013, cap. 10).
- **Matriz**: `m[i][j]` é `*(*(m + i) + j)`. Em `int m[3][4]`, `m + 1` anda uma
  linha (16 bytes) e `m[0] + 1` anda 4 (BACKES, 2013, cap. 10).
- **Um depois do último**: `kwh + 5` pode ser calculado e comparado, nunca
  lido (KERNIGHAN; RITCHIE, 1989, cap. 5).

> [!WARNING]
> `*p + 1` soma 1 ao valor; `*(p + 1)` anda uma gaveta. `*p++` lê e depois
> avança; `(*p)++` soma 1 no valor. Passar do fim (`p <= kwh + 5`) dá
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
