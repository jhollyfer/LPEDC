## 0046 · Passagem por referência

- **Só existe passagem por valor** no C: a função recebe uma cópia (assunto
  0029) (DEITEL; DEITEL, 2011, cap. 7).
- **Passagem por referência**: o C a simula passando o **endereço**. A cópia
  do endereço aponta para a mesma gaveta, e `*a` é a própria variável de quem
  chamou (KERNIGHAN; RITCHIE, 1989, cap. 5).
- **Sintaxe**: a função recebe ponteiros (`void troca(int *a, int *b)`); quem
  chama passa endereços (`troca(&arroz, &feijao)`) (BACKES, 2013, cap. 10).
- **O `&` do `scanf`**: ele precisa escrever na variável, então pede o
  endereço. `scanf("%s", nome)` vai sem `&` porque o nome do vetor já é
  endereço (BACKES, 2013, cap. 10).
- **Vários resultados**: o `return` devolve um valor só; para devolver mais,
  a função escreve em ponteiros recebidos (o A092 racha a conta) (DEITEL;
  DEITEL, 2011, cap. 7).
- **`const int *p`**: a função só lê; o compilador recusa `*p = ...`. Struct
  grande vai assim (DEITEL; DEITEL, 2011, cap. 7).

> [!WARNING]
> Esquecer o `&` na chamada manda o número 8 onde se espera um endereço, e o
> programa cai. Esquecer o `*` na função (`a = b;`) troca só os ponteiros
> locais. Quem mexe no dado de quem chamou é sempre `*a`.

{{exemplo}}

No mercadinho, as etiquetas saíram trocadas: arroz a R$ 8, feijão a R$ 25. A
`troca` recebe `0x1000` e `0x1004`, guarda o 8 em `tmp` e mexe direto nas
gavetas do `main`:

{{ideia}}

```c
#include <stdio.h>

// recebe CÓPIAS: troca as cópias e o main nem fica sabendo
void troca_copias(int a, int b) {
    int tmp = a;
    a = b;
    b = tmp;
}

// recebe ENDEREÇOS: troca o que está nas gavetas do main
void troca(int *a, int *b) {
    int tmp = *a; // guarda o valor da primeira gaveta
    *a = *b;      // primeira gaveta recebe o da segunda
    *b = tmp;     // segunda gaveta recebe o guardado
}

int main(void) {
    int arroz = 8, feijao = 25; // digitados trocados: o arroz é o mais caro

    troca_copias(arroz, feijao);
    printf("Depois de troca_copias: arroz %d, feijão %d\n", arroz, feijao);

    if (arroz < feijao) {         // o pacote de arroz deveria custar mais
        troca(&arroz, &feijao);   // passa os endereços, não os valores
    }
    printf("Depois de troca:        arroz %d, feijão %d\n", arroz, feijao);
    return 0;
}
// Saída:
// Depois de troca_copias: arroz 8, feijão 25
// Depois de troca:        arroz 25, feijão 8
```

O `main` só chama a troca se os preços estão fora de ordem; a troca são três
passos, com a variável auxiliar:

{{fluxograma}}

### Passo a passo

Teste de mesa de `troca(&arroz, &feijao)`, com os endereços do desenho:

| linha | `a` | `b` | `tmp` | `arroz` (0x1000) | `feijao` (0x1004) |
| --- | --- | --- | --- | --- | --- |
| entrada na função | 0x1000 | 0x1004 | ? | 8 | 25 |
| `tmp = *a` | 0x1000 | 0x1004 | 8 | 8 | 25 |
| `*a = *b` | 0x1000 | 0x1004 | 8 | **25** | 25 |
| `*b = tmp` | 0x1000 | 0x1004 | 8 | 25 | **8** |

`a` e `b` nunca mudam: muda o que está nas gavetas para onde apontam.
