## 0046 · Passagem por referência

No mercadinho, as etiquetas saíram trocadas: o arroz ficou a R$ 8 e o feijão
a R$ 25. Você quer uma função `troca` que conserte isso, recebendo os dois
preços e trocando um pelo outro. A versão óbvia, que recebe dois `int` e
troca, compila e roda, mas os preços do `main` continuam errados. O motivo
está no jeito como o C chama funções.

No C, **todo argumento é passado por valor** (assunto 0029): a função recebe
uma **cópia** do que você mandou (DEITEL; DEITEL, 2011, cap. 7). Uma chamada
`troca_copias(arroz, feijao)` cria duas variáveis novas, `a` e `b`, com 8 e
25. A função troca essas cópias e termina, e as cópias somem junto com o
frame dela (assunto 0031). O `arroz` do `main` nem fica sabendo.

A imagem é a de uma reforma. Se você entrega ao pintor uma foto da sua sala,
ele pinta a foto e a parede continua igual. Se entrega o endereço da casa, ele
vai até lá e pinta a parede de verdade. Em C, a saída é entregar o
**endereço** em vez do valor. O endereço também chega como cópia, mas a
cópia aponta para **a mesma gaveta**, e `*a` dentro da função é a própria
variável de quem chamou. Esse arranjo se chama **passagem por referência**; o
C não tem esse mecanismo pronto e o simula com ponteiros (KERNIGHAN; RITCHIE,
1989, cap. 5).

Na prática, a mudança aparece nos dois lados. A função declara ponteiros nos
parâmetros, `void troca(int *a, int *b)`, e quem chama passa endereços,
`troca(&arroz, &feijao)` (BACKES, 2013, cap. 10). Dentro da função, cada
leitura e escrita no dado de fora passa pelo `*`: guarde `*a` numa auxiliar,
copie `*b` para `*a` e a auxiliar para `*b`.

Isso explica o `&` que você escreve no `scanf` desde o começo do curso.
`scanf("%d", &total)` precisa **escrever** na variável, então pede o
endereço dela. Sem o `&`, ele receberia uma cópia do lixo guardado em
`total` e escreveria num endereço inventado. Já `scanf("%s", nome)` vai sem
`&` porque o nome de um vetor já é o endereço do primeiro elemento (BACKES,
2013, cap. 10); o assunto 0047 detalha essa conversão.

O mesmo recurso resolve outro limite. O `return` devolve **um** valor só.
Quando a função precisa entregar dois ou mais resultados, ela recebe
ponteiros e escreve neles: cada ponteiro é uma caixa de saída que quem chamou
preparou. O A092 racha a conta de um restaurante assim, devolvendo o valor de
cada pessoa e a sobra (DEITEL; DEITEL, 2011, cap. 7).

Passar um endereço custa 8 bytes, seja qual for o tamanho do dado apontado.
Por isso, no módulo 08, uma struct grande vai para a função por ponteiro,
mesmo quando a função só precisa lê-la. Nesse caso, marque o parâmetro como
`const int *p`: a função pode ler `*p`, e o compilador recusa qualquer
`*p = ...` lá dentro (DEITEL; DEITEL, 2011, cap. 7).

> [!WARNING]
> Esquecer o `&` na chamada, `troca(arroz, feijao)`, manda o número 8 onde se
> espera um endereço; o compilador avisa e, se rodar, o programa cai.
> Esquecer o `*` na função (`a = b;`) troca só os ponteiros locais, que são
> cópias. Quem mexe no dado de quem chamou é sempre `*a`.

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
