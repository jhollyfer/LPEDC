## 0149 · Juntando tudo: corretor ortográfico

O secretário da associação do bairro quer um programa que leia o aviso da
semana, como "o onibus pasou" ou "a fiera da rua", aponte as palavras que
não existem e sugira a correção. É um corretor ortográfico, e ele junta
várias estruturas do curso.

Por baixo, o corretor faz **duas perguntas ao dicionário**, milhares de
vezes por texto. A primeira é "esta palavra existe?", uma busca exata. A
segunda é "quais palavras de verdade estão perto desta?". Perto, aqui, quer
dizer a poucas **edições** de distância, no sentido do assunto 0142: tirar
uma letra, pôr uma letra, trocar uma letra por outra ou trocar duas letras
vizinhas de lugar. Essa última operação não estava na distância de
Levenshtein, mas é o erro de digitação mais comum.

A segunda pergunta parece exigir comparar a palavra errada com o
dicionário inteiro. O corretor faz o contrário: **gera candidatos**. Ele
aplica à palavra errada todas as edições possíveis e pergunta, para cada
resultado, se ele existe. Para "fiera", com 5 letras, são 5 jeitos de tirar
uma letra, 4 de trocar duas vizinhas, 5 × 25 de trocar uma letra e 6 × 26 de
pôr uma letra: 290 candidatos. Desses, só "feira" existe. A segunda pergunta
virou 290 buscas exatas, e o custo delas depende de como o dicionário está
guardado.

O dicionário fica numa **trie** (assunto 0147). Cada busca custa O(L), com
L o tamanho da palavra, sem depender do tamanho do dicionário. E a trie tem
uma vantagem extra para candidatos: ela descobre cedo que uma palavra não
existe. Um candidato que começa com "fx" morre no segundo nó, porque nenhuma
palavra começa assim (ZIVIANI, 2010, cap. 5).

Há outras opções para o dicionário. Uma **tabela hash** faz a busca exata em
O(1) na média, calculando direto a posição da palavra. Uma **BST** faz em
O(log n) comparações de string (SZWARCFITER; MARKENZON, 2010). O exemplo
A297 monta as três com o mesmo dicionário de 2500 palavras de duas sílabas
e faz 5000 buscas, metade de palavras que existem e metade de palavras que
não existem. A tabela resume o que ele mede e o que cada estrutura sabe
fazer:

| | BST | Tabela hash | Trie |
| --- | --- | --- | --- |
| custo da busca exata | 17,2 comparações de string | 1,3 comparação de string | 4 nós (o tamanho da palavra) |
| memória | 60 KB | 60 KB | 661 KB |
| palavras com um prefixo | dá, com um percurso por intervalo | não dá | desce até o prefixo e lista |
| ordem alfabética | percurso em ordem | não dá | percurso por letra |
| depende de n? | sim, log n | não (com fator de carga bom) | não |

Leia a tabela pela linha da memória. A trie de 84 palavras do exemplo deste
assunto tem 239 nós de 216 bytes, cerca de 51 KB, e cada nó fica num ponto
diferente do heap. Andar de nó em nó obriga o processador a buscar memória
que não está no cache, a memória rápida perto dele. A hash lê poucas
posições próximas e costuma vencer a trie na busca exata.

A trie ganha em tudo que envolve **prefixo**: autocompletar, listar em
ordem alfabética e cortar candidatos que já nascem errados. A hash ganha na
pergunta "existe?" pura. Por isso um corretor de verdade combina as duas.

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
