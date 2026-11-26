## 0160 · Rabin-Karp

Você tem dois arquivos de 1 GB e quer saber se são iguais. Comparar byte a
byte funciona, mas existe um atalho: calcular um **hash** de cada um, um
número pequeno que resume o conteúdo (hashing, assunto 0105). O hash
funciona como uma **impressão digital**. Se os hashes diferem, os arquivos
com certeza diferem. Se batem, os arquivos provavelmente são iguais, e só
então vale conferir byte a byte.

O **algoritmo de Rabin-Karp** leva essa ideia para a busca de padrão
(KARP; RABIN, 1987). Ele calcula o hash do padrão uma vez. Depois calcula o
hash de cada **janela** do texto, isto é, de cada trecho de `m` letras
seguidas, e só compara letra a letra quando o hash da janela bate com o do
padrão. A maioria das janelas é descartada por uma única comparação de
números.

Há um obstáculo. Calcular o hash de uma janela do zero custa `m` passos, e
com `n - m + 1` janelas voltamos ao O(n·m) da força bruta. A saída é o
**hash rolante**: a janela seguinte é quase a mesma, perde uma letra à
esquerda e ganha outra à direita, e o hash novo pode sair do antigo em O(1)
(CORMEN et al., 2024, cap. 32).

Veja com dígitos, que é mais fácil. No texto `2718`, com `m = 3`, a primeira
janela `271` é o número 271. A próxima, `718`, sai assim: tire o dígito que
sai, multiplicado pelo peso dele (`2 · 100`), desloque uma casa
multiplicando por 10 e some o dígito que entra.

```c
// janela 271 -> janela 718
int nova = (271 - 2 * 100) * 10 + 8;   // 718
```

O peso do dígito que sai é `10^(m-1)`, calculado uma vez antes da busca.
Com letras a conta é a mesma, só que na base 256, já que cada letra é um
byte.

Só que um número de `m` letras na base 256 fica enorme e estoura qualquer
tipo inteiro do C. Por isso toda conta é feita **módulo um primo `q`**:
guarda-se só o resto da divisão por `q`, e as somas e multiplicações
continuam funcionando sobre os restos (SEDGEWICK; WAYNE, 2011). Com letras, `q` deve ser um primo
grande, como 1.000.003, e as contas vão em `long long` (assunto 0003),
porque o produto de dois restos estoura um `int`, e overflow de inteiro com
sinal é comportamento indefinido.

O resto tem um preço. Janelas diferentes podem deixar o mesmo resto: com
`q = 13`, `182` e `845` deixam resto 0. Isso é uma **colisão**, também
chamada de **falso positivo**: o hash diz "talvez", e a janela não é o
padrão. Por isso a conferência letra a letra nunca pode ser pulada. Quanto
maior o `q`, mais raras as colisões; o A319 mostra os falsos positivos
caindo de 48 para 0 conforme o `q` cresce.

O custo segue dessas duas peças. Com `q` grande, quase nenhuma janela pede
conferência, e a busca custa O(n + m) na média. No pior caso, se toda janela
colidir, cada uma pede `m` comparações, e o custo volta a O(n·m) (CORMEN et
al., 2024, cap. 32). O ponto forte do Rabin-Karp é outro: como ele trata o
texto como números, procurar vários padrões de mesmo tamanho ao mesmo tempo
custa quase o mesmo que procurar um.

> [!WARNING]
> Em C, o resto de número negativo é negativo: `-7 % 13` vale `-7`, não `6`.
> `ht - t[i] * pot` fica negativo com frequência, e um hash negativo nunca
> bate com o do padrão: a busca **perde ocorrências** sem erro. Por isso a
> linha é `(ht - t[i] * pot % Q + Q) % Q`.

{{exemplo}}

Procure `182` em `2718281828459` com `q = 13`, pequeno de propósito. O hash do
padrão é 0, e nas 11 janelas o 0 aparece três vezes: duas são o `182` e uma é o
`845`, um falso positivo:

{{ideia}}

Em C:

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

São duas operações por janela, com qualquer `m`. A conferência letra a letra
quase nunca roda quando `q` é grande:

{{fluxograma}}
