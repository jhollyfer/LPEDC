## 0149 · Juntando tudo: corretor ortográfico

- **Duas perguntas ao dicionário**: "esta palavra existe?" (busca exata) e "quais
  palavras estão perto desta?". Perto é a poucas **edições** (assunto 0142):
  tirar, pôr ou trocar uma letra, ou trocar duas vizinhas.
- **Gerar candidatos**: aplicar à palavra errada todas as edições e ver quais
  existem. "fiera" gera 290 candidatos, e só "feira" existe.
- **Dicionário em trie** (assunto 0147): cada busca custa O(L), e um candidato
  sem prefixo válido ("fx...") morre no segundo nó (ZIVIANI, 2010, cap. 5).
- **Alternativas**: a hash faz a busca exata em O(1) na média; a BST, em
  O(log n) comparações de string (SZWARCFITER; MARKENZON, 2010).
- **Memória e cache**: 84 palavras viram 239 nós de 216 bytes (cerca de 51 KB),
  espalhados no heap. Cada acesso pode faltar no cache, e por isso a hash costuma
  vencer na busca exata.

O A297 compara as três com 2500 palavras de duas sílabas e 5000 buscas (metade
acha, metade não):

| | BST | Tabela hash | Trie |
| --- | --- | --- | --- |
| custo da busca exata | 17,2 comparações de string | 1,3 comparação de string | 4 nós (o tamanho da palavra) |
| memória | 60 KB | 60 KB | 661 KB |
| palavras com um prefixo | dá, com um percurso por intervalo | não dá | desce até o prefixo e lista |
| ordem alfabética | percurso em ordem | não dá | percurso por letra |
| depende de n? | sim, log n | não (com fator de carga bom) | não |

A trie ganha em tudo que envolve **prefixo**; um corretor de verdade combina
trie e hash.

> [!WARNING]
> `cor_proxima` só reconhece `'a'` a `'z'`: maiúscula e acento viram separadores
> ("Hoje" sai "oje"; "pão" sai "p" e "o"). E `cor_sugere` usa um vetor de
> `COR_MAX + 1` posições, porque pôr uma letra aumenta a palavra.

{{exemplo}}

O secretário da associação do bairro quer revisar o aviso da semana. São 18
palavras e cinco problemas: três erros com uma sugestão só, um "caa" que pode
ser três palavras e um "esquina" certo, mas fora do dicionário de 84 palavras:

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
