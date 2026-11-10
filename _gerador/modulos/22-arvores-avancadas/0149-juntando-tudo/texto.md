## 0149 · Juntando tudo: corretor ortográfico

O secretário da associação do bairro quer um programa que leia o aviso da
semana ("o onibus pasou", "a fiera da rua"), aponte as palavras que não existem
e sugira a correção.

Um corretor faz duas perguntas ao dicionário, milhares de vezes por texto:
**"esta palavra existe?"** (busca exata) e **"quais palavras de verdade estão
perto desta?"**. "Perto" é a poucas **edições** (assunto 0142): tirar, pôr ou
trocar uma letra, ou trocar duas letras vizinhas.

Sugerir é **gerar candidatos**: aplicar à palavra errada todas as edições e ver
quais existem. Para "fiera", são 5 jeitos de tirar, 4 de trocar vizinhas,
5 · 25 de trocar uma letra e 6 · 26 de pôr uma letra: 290 candidatos, e só
"feira" existe. O custo de 290 buscas depende da estrutura do dicionário.

O dicionário fica numa **trie** (assunto 0147): cada busca custa O(L), e um
candidato que não começa como palavra nenhuma ("fx...") morre no segundo nó.
Uma hash também faria a busca exata em O(1) na média, e uma BST em O(log n)
comparações; a comparação está no fim do assunto.

O TAD está em `corretor.h` e `corretor.c`: `cor_carrega_basico` monta um
dicionário de 84 palavras, `cor_proxima` separa o texto em palavras,
`cor_contem` faz a busca exata e `cor_sugere` gera e filtra os candidatos.

O aviso tem 18 palavras e cinco problemas: três erros com uma sugestão só, um
"caa" que pode ser três palavras e um "esquina" que está certo, mas fora do
dicionário:

{{ideia}}

No miolo de `cor_sugere`, `anota` confere cada candidato na trie, descarta
repetidos e mantém a lista em ordem alfabética:

```c
int cor_sugere(const NoC *d, const char *palavra, char sug[][COR_MAX], int max) {
    int n = (int)strlen(palavra);
    int qtd = 0;
    char c[COR_MAX + 1];
    if (n >= COR_MAX - 1) {
        return 0;
    }
    for (int i = 0; i < n; i++) { // 1. tirar a letra i
        memcpy(c, palavra, i);
        strcpy(c + i, palavra + i + 1);
        anota(d, c, sug, &qtd, max);
    }
    for (int i = 0; i + 1 < n; i++) { // 2. trocar as letras i e i + 1 de lugar
        strcpy(c, palavra);
        char t = c[i];
        c[i] = c[i + 1];
        c[i + 1] = t;
        anota(d, c, sug, &qtd, max);
    }
    for (int i = 0; i < n; i++) { // 3. trocar a letra i por outra
        strcpy(c, palavra);
        for (char l = 'a'; l <= 'z'; l++) {
            if (l != palavra[i]) {
                c[i] = l;
                anota(d, c, sug, &qtd, max);
            }
        }
    }
    for (int i = 0; i <= n; i++) { // 4. pôr uma letra na posição i
        for (char l = 'a'; l <= 'z'; l++) {
            memcpy(c, palavra, i);
            c[i] = l;
            strcpy(c + i + 1, palavra + i);
            anota(d, c, sug, &qtd, max);
        }
    }
    return qtd;
}
```

O programa do secretário:

```c
#include <stdio.h>
#include "corretor.h"

int main(void) {
    NoC *dic = cor_cria();
    int n = cor_carrega_basico(dic);
    printf("Dicionário: %d palavras em %d nós\n", n, cor_nos(dic));

    const char *texto = "hoje o onibus pasou no ponto, e a fiera tinha bolo e cafe baratoo na caa da esquina.";
    char palavra[COR_MAX], sug[5][COR_MAX];
    int total = 0, erros = 0;
    while (cor_proxima(&texto, palavra)) {
        total++;
        if (cor_contem(dic, palavra)) {
            continue;
        }
        erros++;
        int k = cor_sugere(dic, palavra, sug, 5);
        printf("\"%s\"? Sugestões:", palavra);
        for (int i = 0; i < k; i++) {
            printf(" %s", sug[i]);
        }
        printf(k == 0 ? " nenhuma\n" : "\n");
    }
    printf("%d palavras, %d para revisar\n", total, erros);

    cor_libera(dic);
    return 0;
}
// Saída:
// Dicionário: 84 palavras em 239 nós
// "pasou"? Sugestões: passou
// "fiera"? Sugestões: feira
// "baratoo"? Sugestões: barato
// "caa"? Sugestões: cama cara casa
// "esquina"? Sugestões: nenhuma
// 18 palavras, 5 para revisar
```

O fluxograma é um laço sobre as palavras: só as desconhecidas pagam o preço dos
candidatos. O caminho verde é o de "fiera", seguido do fim do texto:

{{fluxograma}}

### Trie, hash ou BST?

O A297 monta as três estruturas com o mesmo dicionário de 2500 palavras de duas
sílabas e faz 5000 buscas (metade acha, metade não):

| | BST | Tabela hash | Trie |
| --- | --- | --- | --- |
| custo da busca exata | 17,2 comparações de string | 1,3 comparação de string | 4 nós (o tamanho da palavra) |
| memória | 60 KB | 60 KB | 661 KB |
| palavras com um prefixo | dá, com um percurso por intervalo | não dá | desce até o prefixo e lista |
| ordem alfabética | percurso em ordem | não dá | percurso por letra |
| depende de n? | sim, log n | não (com fator de carga bom) | não |

A hash ganha na busca exata e a trie perde na memória, mas a trie ganha em tudo
que envolve **prefixo**: autocompletar e cortar candidatos que já nascem
errados. Um corretor de verdade combina as duas.

> [!WARNING]
> `cor_proxima` só reconhece `'a'` a `'z'`: maiúscula e acento viram
> separadores ("Hoje" sai "oje"; "pão" sai "p" e "o"). Em UTF-8, `'ã'` ocupa
> 2 bytes e não cabe num índice de 0 a 25. Além disso, `cor_sugere` usa um
> vetor de `COR_MAX + 1` posições, porque pôr uma letra aumenta a palavra.

> [!TIP]
> A trie de 84 palavras tem 239 nós de 216 bytes (cerca de 51 KB). Cada nó fica
> num ponto do heap, e cada acesso pode ser uma falta de cache; por isso a hash
> costuma vencer a trie na busca exata.

> [!NOTE]
> **Pergunta para você:** se o aviso tivesse "onibu", quais sugestões
> apareceriam? E "aa"? Confira trocando o texto do exemplo.

{{pratique}}
