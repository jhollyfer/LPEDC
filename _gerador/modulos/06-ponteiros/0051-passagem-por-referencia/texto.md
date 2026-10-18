## 0051 · Passagem por referência

No mercadinho, alguém digitou as etiquetas trocadas: o arroz saiu por
R$ 8 e o feijão por R$ 25. Você quer uma função `troca` que conserte isso.
Parece fácil, mas a versão óbvia não funciona, e entender por que é entender
como o C chama funções.

No C, **todo argumento é passado por valor** (assunto 0034): a função recebe
uma **cópia**. `troca_copias(arroz, feijao)` cria duas variáveis novas, `a`
e `b`, com 8 e 25 dentro. A função troca as cópias, termina, e as cópias
somem junto com o frame dela (assunto 0036). O `arroz` do `main` nem ficou
sabendo.

No JS é igual para números: `function troca(a, b)` também não troca dois
`number` de quem chamou. A diferença é que no C existe a saída: em vez do
valor, passe o **endereço**.

A função passa a receber ponteiros, `void troca(int *a, int *b)`, e quem
chama entrega os endereços: `troca(&arroz, &feijao)`. O endereço também é
copiado, mas a cópia de um endereço aponta para **a mesma gaveta**. Dentro
da função, `*a` é o próprio `arroz` do `main`. Isso se chama **passagem por
referência** (no C, simulada com ponteiros).

Agora o mistério do `scanf` está resolvido. `scanf("%d", &total)` precisa
**escrever** na sua variável, então pede o endereço dela. Sem o `&`, ele
receberia uma cópia do lixo que está em `total` e tentaria escrever num
endereço inventado. E por que `scanf("%s", nome)` vai sem `&`? Porque o nome
de um vetor já vira o endereço do primeiro elemento (assunto 0043; o 0052
mostra os detalhes).

O mesmo truque resolve outro problema: o `return` devolve **um** valor só.
Quando a função precisa entregar dois ou mais resultados, ela recebe
ponteiros e escreve neles (o A102 racha a conta e devolve o valor de cada
um e a sobra).

Vamos ver na prática. A função `troca` recebe os endereços `0x1000` e
`0x1004`, guarda o 8 numa variável `tmp` e mexe direto nas gavetas do
`main`:

{{ideia}}

No código, as duas versões lado a lado. Repare que só a segunda conserta as
etiquetas:

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

### Passo a passo

Teste de mesa da chamada `troca(&arroz, &feijao)`, com os endereços
fictícios do desenho:

| linha | `a` | `b` | `tmp` | `arroz` (0x1000) | `feijao` (0x1004) |
| --- | --- | --- | --- | --- | --- |
| entrada na função | 0x1000 | 0x1004 | ? | 8 | 25 |
| `tmp = *a` | 0x1000 | 0x1004 | 8 | 8 | 25 |
| `*a = *b` | 0x1000 | 0x1004 | 8 | **25** | 25 |
| `*b = tmp` | 0x1000 | 0x1004 | 8 | 25 | **8** |

`a` e `b` nunca mudam: o que muda é o que está nas gavetas para onde eles
apontam.

Repara no fluxograma: o `main` só chama a troca se os preços estão fora de
ordem. A troca em si são três passos, sempre com a variável auxiliar:

{{fluxograma}}

> [!WARNING]
> Dois erros clássicos. Esquecer o `&` na chamada: `troca(arroz, feijao)`
> manda o número 8 onde a função espera um endereço. O compilador avisa
> (`makes pointer from integer without a cast`) e, se rodar, o programa
> tenta escrever na "gaveta 8" e cai. E esquecer o `*` dentro da função:
> `tmp = a; a = b;` troca os **ponteiros** locais, que são cópias; nada muda
> lá fora. Dentro da função, quem mexe no dado do chamador é sempre `*a`.

> [!TIP]
> **Por dentro do C:** no x86-64, os primeiros argumentos viajam em
> registradores do processador. Passar `&arroz` é copiar 8 bytes, o tamanho
> de um endereço, não importa o tamanho do dado apontado. Por isso, no
> módulo 08, struct grande vai por ponteiro: copiar 8 bytes é mais barato
> que copiar 200. Quando a função só precisa **ler**, use `const int *p`: o
> compilador recusa qualquer `*p = ...` lá dentro, e quem lê o protótipo sabe
> que o dado volta intacto.

> [!NOTE]
> **Pergunta para você:** o que acontece em `troca(&arroz, &arroz)`? Os dois
> ponteiros apontam para a mesma gaveta. O valor de `arroz` muda?

{{pratique}}
