## 0158 · KMP

A central do alarme de casa desarma quando a senha `12123` aparece no teclado.
Ninguém aperta "Enter": a central olha as teclas uma a uma, conforme chegam, e
não guarda o histórico. Você digita `1 2 1 2`, erra e aperta `1`. A central
precisa recomeçar do zero?

Não precisa. As últimas teclas foram `1 2 1`, e `1 2 1` é o começo da senha.
A força bruta jogaria isso fora: voltaria ao alinhamento seguinte e compararia
de novo letras que já tinha visto. O **KMP** (Knuth, Morris e Pratt, 1977)
nunca volta no texto. Cada letra do texto é lida uma vez, e a busca custa
**O(n + m)**, sempre.

O truque é olhar só para o padrão. Se `k` letras do padrão já casaram e a
próxima falhou, o que o texto tem no fim é exatamente `padrao[0..k-1]`. A
pergunta "quanto disso ainda serve como começo do padrão?" depende **só do
padrão**, então dá para responder antes de ler o texto.

A resposta é a **borda**: o maior prefixo próprio de uma string que também é
sufixo dela. Em `1212`, o prefixo `12` também é o fim: a borda tem 2 letras. Em
`121` a borda é `1`. Em `1213`, não há borda. A **tabela π** (pi) guarda isso
para cada pedaço do padrão: `pi[j]` é o tamanho da borda de `padrao[0..j]`.
Para `12123`, `pi = [0, 0, 1, 2, 0]`.

A busca guarda um número só, `k`, quantas letras já casaram. Para cada letra do
texto:

- se ela é `padrao[k]`, o casamento cresce: `k++`;
- se não é e `k > 0`, recua para a borda, `k = pi[k - 1]`, e tenta de novo com
  a **mesma** letra (pode recuar várias vezes);
- se `k` chega a `m`, achou; recua para `pi[m - 1]` e segue, para pegar
  ocorrências sobrepostas.

A própria tabela π sai do mesmo jeito: é o padrão sendo procurado dentro dele
mesmo. Por isso as duas funções do código se parecem tanto.

Vamos ver na prática. As teclas são `1 2 1 2 1 2 3`. As quatro primeiras casam
(`k = 4`). A quinta, `1`, não é o `3` esperado. Em vez de recomeçar, a central
olha `pi[3] = 2`: o `1 2` do fim continua valendo, e o padrão "escorrega" duas
casas para a frente sem reler nada. A mesma tecla `1` agora casa com
`padrao[2]`, e a senha se completa na sétima tecla:

{{ideia}}

O mesmo exemplo em C. O `printf` dentro do laço mostra o `k` depois de cada
tecla:

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

A tabela π de `12123`, letra por letra. O `k` é a borda do pedaço anterior:

| j | pedaço `p[0..j]` | `p[j]` vs `p[k]` | k depois | `pi[j]` | borda |
| --- | --- | --- | --- | --- | --- |
| 0 | `1` | (sempre 0) | 0 | 0 | nenhuma |
| 1 | `12` | `2` vs `1`: não | 0 | 0 | nenhuma |
| 2 | `121` | `1` vs `1`: sim | 1 | 1 | `1` |
| 3 | `1212` | `2` vs `2`: sim | 2 | 2 | `12` |
| 4 | `12123` | `3` vs `1`: não, recua para `pi[1] = 0`; `3` vs `1`: não | 0 | 0 | nenhuma |

Na busca, foram 8 comparações para 7 teclas: uma a mais por causa do recuo na
quinta. A força bruta faria 11 (5 no alinhamento 0, 1 no alinhamento 1, 5 no
alinhamento 2).

Repara no fluxograma: o texto avança num laço só, e o recuo é um laço **dentro**
dele que mexe apenas em `k`. O índice `i` do texto nunca anda para trás:

{{fluxograma}}

Por que é O(n)? O `k` sobe no máximo 1 por letra do texto, então sobe no máximo
`n` vezes no total. Cada recuo diminui o `k`, e ele nunca fica negativo: não dá
para descer mais do que subiu. Somando avanços e recuos, a busca faz no máximo
`2n` comparações, por pior que seja o texto. A tabela custa O(m) pelo mesmo
argumento.

> [!WARNING]
> O recuo é um `while`, não um `if`. Depois de `k = pi[k - 1]`, a letra do
> texto pode continuar não servindo, e aí é preciso recuar de novo, até ela
> casar ou `k` chegar a 0. Com `if`, o `k` fica maior do que deveria, e a
> busca "acha" ocorrências que não existem (o E947 mostra um alarme desarmando
> sem a senha). Outro tropeço comum: a tabela tem várias convenções nos livros
> (começando em 1, deslocada, com -1 na primeira casa). Misturar a tabela de um
> livro com a busca de outro dá erro de um.

> [!TIP]
> **Por dentro do C:** a tabela π é um vetor de `m` inteiros: para um padrão de
> 32 letras são 128 bytes na pilha, e ela não depende do tamanho do texto. O
> texto, por sua vez, é lido **uma vez, em ordem, sem voltar**. Isso deixa o KMP
> trabalhar sobre um fluxo de `getchar()` ou de `fgetc()` sem guardar o texto
> em lugar nenhum: um arquivo de 10 GB passa por ele com a memória da tabela e
> de um `int`. A força bruta não consegue isso, porque volta `j - 1` letras a
> cada falha.

> [!NOTE]
> **Pergunta para você:** qual é a tabela π de `aabaaab`? E quantas vezes o
> `k` recua quando o texto é `aabaaaab`? Calcule no papel, depois troque a senha
> e as teclas no código e confira.

{{pratique}}
