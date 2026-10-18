## 0160 · Rabin-Karp

Para saber se dois arquivos de 1 GB são iguais, você não compara byte a byte
toda vez: calcula uma **impressão digital** de cada um (um hash) e compara dois
números. Se os números diferem, os arquivos com certeza diferem. Se batem,
muito provavelmente são iguais, e só aí vale conferir de verdade.

O **Rabin-Karp** (1987) usa essa ideia na busca de padrões. Calcula o hash do
padrão uma vez. Depois calcula o hash de cada **janela** de `m` letras do texto
e só compara letra a letra quando os hashes batem. É o assunto 0105 (hashing)
aplicado a pedaços de texto.

Mas calcular o hash de cada janela do zero custa `m` passos, e aí não se ganha
nada da força bruta. O pulo do gato é o **hash rolante**: a janela seguinte
perde uma letra na esquerda e ganha uma na direita, e o hash novo sai do antigo
em O(1).

Pense em dígitos. A janela `271` é o número 271. A próxima, `718`, é
`(271 - 2·100)·10 + 8`: tira o dígito que sai (pesando 10^(m-1)), desloca uma
casa e soma o que entra. Com letras é igual, só que na base 256, uma "casa" por
byte. Como esses números ficam enormes, tudo é feito **módulo um primo `q`**:
o hash é o resto, e a regra continua valendo com `% q` a cada passo.

O preço do resto é a **colisão**: duas janelas diferentes podem ter o mesmo
resto. Isso é um **falso positivo**, e é por isso que a conferência letra a
letra nunca pode ser pulada. Com `q` grande, colisões ficam raras, e a busca
custa O(n + m) na média. No pior caso (tudo colidindo), volta a O(n·m).

Vamos ver na prática. Você procura `182` na sequência `2718281828459`, com
`q = 13` (pequeno de propósito, para aparecer colisão). O hash do padrão é
`182 % 13 = 0`. Rolando a janela pelas 11 posições, o hash 0 aparece três
vezes: duas são o `182` de verdade, e uma é o `845`, que também deixa resto 0:

{{ideia}}

O mesmo exemplo em C:

```c
#include <stdio.h>
#include <string.h>

#define BASE 10   // dígitos: cada janela é um número na base 10
#define Q 13      // o módulo (de propósito pequeno, para aparecer colisão)

// as m letras de t e de p são iguais? (a conferência de verdade)
int iguais(const char *t, const char *p, int m) {
    for (int j = 0; j < m; j++) {
        if (t[j] != p[j]) {
            return 0;
        }
    }
    return 1;
}

int rabin_karp(const char *t, const char *p) {
    int n = (int) strlen(t);
    int m = (int) strlen(p);
    int pot = 1;                              // BASE^(m-1) % Q
    for (int j = 0; j < m - 1; j++) {
        pot = pot * BASE % Q;
    }
    int hp = 0, ht = 0;                       // hash do padrão e da 1ª janela
    for (int j = 0; j < m; j++) {
        hp = (hp * BASE + (p[j] - '0')) % Q;
        ht = (ht * BASE + (t[j] - '0')) % Q;
    }

    int achados = 0;
    for (int i = 0; i <= n - m; i++) {
        printf("janela %.*s: hash %2d", m, t + i, ht);
        if (ht == hp) {                       // hash igual: só agora compara
            if (iguais(t + i, p, m)) {
                printf("  confere: ocorrência em %d", i);
                achados++;
            } else {
                printf("  confere: falso positivo");
            }
        }
        printf("\n");
        if (i < n - m) {                      // rola: tira t[i], põe t[i+m]
            ht = (ht - (t[i] - '0') * pot % Q + Q) % Q;
            ht = (ht * BASE + (t[i + m] - '0')) % Q;
        }
    }
    return achados;
}

int main(void) {
    const char *codigo = "2718281828459";
    printf("hash de 182: %d\n", 182 % Q);
    int total = rabin_karp(codigo, "182");
    printf("%d ocorrências\n", total);
    return 0;
}
// Saída:
// hash de 182: 0
// janela 271: hash 11
// janela 718: hash  3
// janela 182: hash  0  confere: ocorrência em 2
// janela 828: hash  9
// janela 281: hash  8
// janela 818: hash 12
// janela 182: hash  0  confere: ocorrência em 6
// janela 828: hash  9
// janela 284: hash 11
// janela 845: hash  0  confere: falso positivo
// janela 459: hash  4
// 2 ocorrências
```

### Passo a passo

A primeira rolada, de `271` (hash 11) para `718`. O `pot` é `10² % 13 = 9`:

| Passo | Conta | Resultado |
| --- | --- | --- |
| tira o 2 | `2 · 9 % 13 = 5`; `(11 - 5 + 13) % 13` | 6 |
| desloca e põe o 8 | `(6 · 10 + 8) % 13 = 68 % 13` | **3** |
| confere do zero | `718 % 13 = 718 - 715` | 3 |

Duas operações por janela, não importa o tamanho do padrão. Com `m = 1000`, a
força bruta pode gastar até mil comparações por janela; o hash rolante continua
gastando duas contas.

Repara no fluxograma: o caminho comum é só calcular, comparar dois números e
rolar. A comparação letra a letra fica num desvio que quase nunca é tomado
quando `q` é grande:

{{fluxograma}}

> [!WARNING]
> Em C, o resto de número negativo é negativo: `-7 % 13` vale `-7`, não `6`.
> Na rolagem, `ht - t[i] * pot` fica negativo com frequência, e um hash
> negativo nunca bate com o do padrão: a busca **perde ocorrências** sem dar
> erro nenhum (o E959 cai nisso). Por isso a linha é
> `(ht - t[i] * pot % Q + Q) % Q`: reduz o produto, soma `Q` e só então tira o
> resto. E nunca pule a conferência letra a letra: sem ela, o `845` acima
> seria contado como ocorrência.

> [!TIP]
> **Por dentro do C:** com letras, a base é 256 e o módulo deve ser um primo
> grande, como 1.000.003. O maior valor intermediário é `ht * 256`, perto de
> 2,6·10⁸: cabe num `int` de 32 bits, mas com folga pequena. Use `long long`
> (assunto 0003) e você pode subir o `q` sem medo de overflow, que em `int`
> com sinal é comportamento indefinido. Escolher o `q` primo e distante de
> potências de 2 espalha melhor os restos. O exemplo A319 mostra os falsos
> positivos caindo de 48 para 0 conforme o `q` cresce.

> [!NOTE]
> **Pergunta para você:** com `q = 13`, procurando `828` na mesma sequência,
> quantos falsos positivos aparecem? Use os hashes da saída acima para
> responder sem rodar, e depois troque o padrão no código para conferir.

{{pratique}}
