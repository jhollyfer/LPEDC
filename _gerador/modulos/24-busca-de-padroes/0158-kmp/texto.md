## 0158 · KMP

A central do alarme desarma quando a senha `12123` aparece no teclado. Ela
não guarda o histórico das teclas: só lembra quanto da senha já foi
digitado. Você digita `1 2 1 2`, erra e aperta `1`. A central precisa
recomeçar do zero? A força bruta recomeçaria: voltaria no texto e testaria o
alinhamento seguinte. Só que as últimas teclas lidas, `1 2 1`, já formam o
começo da senha, e jogar isso fora é desperdício.

O **KMP**, de Knuth, Morris e Pratt, é a busca que nunca volta no texto: lê
cada letra uma única vez, da esquerda para a direita, e custa **O(n + m)** em
qualquer caso (KNUTH; MORRIS; PRATT, 1977). O segredo está numa observação
simples. Se `k` letras já casaram e a próxima falhou, você sabe exatamente o
que acabou de ler: as últimas `k` letras do texto são `padrao[0..k-1]`. Então
a pergunta "quanto do que li ainda serve?" depende **só do padrão**, e pode
ser respondida antes de olhar o texto (CORMEN et al., 2024, cap. 32).

A resposta tem nome. Um **prefixo próprio** de uma string é um pedaço do
começo dela que não é ela inteira; um **sufixo** é um pedaço do fim. A
**borda** de uma string é o maior prefixo próprio que também é sufixo
(SZWARCFITER; MARKENZON, 2010). Em `1212`, o prefixo `12` também fecha a
string, então a borda é `12`. Em `121`, a borda é `1`. Em `1213`, nenhum
prefixo próprio termina a string, e a borda é vazia, de tamanho 0. A borda
diz quanto do casamento sobrevive a uma falha: se a central leu `1212` e a
próxima tecla não serve, o `12` do fim ainda pode ser o começo da senha.

A **tabela π** (pi) guarda a borda de cada começo do padrão: `pi[j]` é o
tamanho da borda de `padrao[0..j]`. Para `12123`, os pedaços são `1`, `12`,
`121`, `1212` e `12123`, com bordas de tamanho 0, 0, 1, 2 e 0. Logo
`pi = [0, 0, 1, 2, 0]`. A tabela se calcula com a mesma lógica da busca: é
o padrão sendo procurado dentro dele mesmo, em O(m).

Com a tabela pronta, a busca guarda um único número, `k`, quantas letras do
padrão já casaram. Para cada letra do texto, três coisas podem acontecer. Se
a letra é `padrao[k]`, o casamento cresce: `k++`. Se não é e `k > 0`, o
casamento encolhe para a borda, `k = pi[k - 1]`, e a **mesma** letra é
testada de novo; isso pode se repetir várias vezes, até a letra servir ou
`k` chegar a 0. Se `k` chega a `m`, achou uma ocorrência, e `k` recua para
`pi[m - 1]` para não perder ocorrências sobrepostas (CORMEN et al., 2024,
cap. 32).

```c
while (k > 0 && texto[i] != padrao[k]) k = pi[k - 1];
if (texto[i] == padrao[k]) k++;
```

Volte ao alarme. As teclas `1 2 1 2` casam quatro letras, `k = 4`. A quinta
tecla, `1`, não é o `3` esperado. A central consulta `pi[3] = 2`: o `12` do
fim continua valendo, e `k` vira 2. Agora o `1` é testado contra
`padrao[2]`, que é `1`, e casa. O padrão escorregou duas casas sem que a
central relesse nada.

Por que o custo é linear? Olhe o `k`. Ele sobe no máximo 1 por letra do
texto, então sobe no máximo `n` vezes no total. Cada recuo o diminui pelo
menos 1, e ele nunca fica negativo, então não dá para recuar mais vezes do
que ele subiu. Somando subidas e recuos, a busca faz no máximo `2n`
comparações. A tabela custa O(m) pelo mesmo argumento, e o total é
O(n + m). A garantia vale para qualquer texto, inclusive os que levam a
força bruta ao pior caso.

> [!WARNING]
> O recuo é um `while`, não um `if`: depois de `k = pi[k - 1]` a letra pode
> continuar não servindo. Com `if`, a busca "acha" ocorrências que não
> existem (o E947 testa isso). E os livros usam convenções diferentes para a
> tabela (começando em 1, deslocada, com -1): misturar convenções dá erro de
> um.

{{exemplo}}

A central de um alarme desarma quando a senha `12123` aparece no teclado, sem
guardar histórico. Com as teclas `1 2 1 2 1 2 3`, a quinta tecla falha, a
central usa `pi[3] = 2` e o padrão escorrega duas casas; a senha se completa na
sétima tecla:

{{ideia}}

Em C, o `printf` do laço mostra o `k` depois de cada tecla:

```c
#include <stdio.h>
#include <string.h>

#define MAX_PADRAO 32

// pi[j] = tamanho da maior borda de p[0..j] (prefixo próprio que também é sufixo)
void calcula_pi(const char *p, int m, int pi[]) {
    int k = 0;                            // tamanho da borda atual
    pi[0] = 0;
    for (int j = 1; j < m; j++) {
        while (k > 0 && p[j] != p[k]) {
            k = pi[k - 1];                // tenta a borda menor
        }
        if (p[j] == p[k]) {
            k++;
        }
        pi[j] = k;
    }
}

// lê o texto uma vez só, da esquerda para a direita; k = letras já casadas
int kmp(const char *texto, const char *padrao) {
    int n = (int) strlen(texto);
    int m = (int) strlen(padrao);
    int pi[MAX_PADRAO];
    int k = 0, achados = 0;
    calcula_pi(padrao, m, pi);
    for (int i = 0; i < n; i++) {
        while (k > 0 && texto[i] != padrao[k]) {
            printf("  '%c' não continua os %d casados: k = pi[%d] = %d\n",
                   texto[i], k, k - 1, pi[k - 1]);
            k = pi[k - 1];
        }
        if (texto[i] == padrao[k]) {
            k++;
        }
        printf("tecla %c: k = %d\n", texto[i], k);
        if (k == m) {
            printf("  senha completa! começou na posição %d\n", i - m + 1);
            achados++;
            k = pi[k - 1];                // continua valendo para a próxima
        }
    }
    return achados;
}

int main(void) {
    const char *senha = "12123";
    const char *teclas = "1212123";
    int pi[MAX_PADRAO];
    int m = (int) strlen(senha);

    calcula_pi(senha, m, pi);
    printf("pi de %s:", senha);
    for (int j = 0; j < m; j++) {
        printf(" %d", pi[j]);
    }
    printf("\n");
    kmp(teclas, senha);
    return 0;
}
// Saída:
// pi de 12123: 0 0 1 2 0
// tecla 1: k = 1
// tecla 2: k = 2
// tecla 1: k = 3
// tecla 2: k = 4
//   '1' não continua os 4 casados: k = pi[3] = 2
// tecla 1: k = 3
// tecla 2: k = 4
// tecla 3: k = 5
//   senha completa! começou na posição 2
```

### Passo a passo

A tabela π de `12123`; o `k` é a borda do pedaço anterior:

| j | pedaço `p[0..j]` | `p[j]` vs `p[k]` | k depois | `pi[j]` | borda |
| --- | --- | --- | --- | --- | --- |
| 0 | `1` | (sempre 0) | 0 | 0 | nenhuma |
| 1 | `12` | `2` vs `1`: não | 0 | 0 | nenhuma |
| 2 | `121` | `1` vs `1`: sim | 1 | 1 | `1` |
| 3 | `1212` | `2` vs `2`: sim | 2 | 2 | `12` |
| 4 | `12123` | `3` vs `1`: não, recua para `pi[1] = 0`; `3` vs `1`: não | 0 | 0 | nenhuma |

Na busca, foram 8 comparações para 7 teclas (uma a mais pelo recuo). A força
bruta faria 11.

O recuo é um laço **dentro** do laço do texto e mexe só em `k`. O índice `i`
nunca anda para trás:

{{fluxograma}}
