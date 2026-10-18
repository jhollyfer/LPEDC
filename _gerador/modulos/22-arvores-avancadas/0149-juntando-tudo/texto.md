## 0149 · Juntando tudo: corretor ortográfico

A associação do bairro manda um aviso por semana no grupo de mensagens, e quem
digita é sempre com pressa: "o onibus pasou", "a fiera da rua". O secretário
quer um programa que leia o aviso, aponte as palavras que não existem e
sugira a correção, como o sublinhado vermelho do editor de texto.

Um corretor faz duas perguntas ao dicionário, milhares de vezes por texto. A
primeira é **"esta palavra existe?"**, uma busca exata. A segunda é **"quais
palavras de verdade estão perto desta?"**, e "perto" quer dizer a poucas
**edições** de distância, a ideia da distância de edição do assunto 0142. Uma
edição é tirar uma letra, pôr uma letra, trocar uma letra por outra ou trocar
duas letras vizinhas de lugar (o erro de digitação mais comum de todos).

O jeito simples de sugerir é **gerar os candidatos**: aplicar à palavra errada
todas as edições possíveis e perguntar ao dicionário quais deles existem. Para
"fiera", com 5 letras, são 5 jeitos de tirar, 4 de trocar vizinhas, 5 · 25 de
trocar uma letra e 6 · 26 de pôr uma letra: 290 candidatos. Quase todos são
lixo ("iera", "fxera"); só "feira" está no dicionário. O corretor faz 290
buscas exatas para cada palavra errada, e a estrutura do dicionário decide
quanto isso custa.

O dicionário fica numa **trie** (assunto 0147). Cada busca custa O(L), o tamanho
da palavra, não importa se o dicionário tem 80 ou 300 mil palavras, e um
candidato que nem começa como palavra nenhuma ("fx...") morre no segundo nó.
Uma tabela hash também responderia a busca exata em O(1) na média, e uma BST
em O(log n) comparações de strings. A comparação completa está no fim do
assunto.

O TAD fica em `corretor.h` e `corretor.c`: `cor_carrega_basico` monta um
dicionário com 84 palavras comuns, `cor_proxima` separa o texto em palavras,
`cor_contem` faz a busca exata e `cor_sugere` gera e filtra os candidatos.

Vamos ver na prática. O aviso desta semana tem 18 palavras e cinco problemas:
três erros de digitação com uma sugestão só, um "caa" que pode ser três
palavras e um "esquina" que está certo, mas não está no dicionário:

{{ideia}}

O coração do `cor_sugere`. Cada candidato vai para `anota`, que confere na
trie, descarta repetidos e mantém a lista em ordem alfabética:

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

Repara no fluxograma: o programa é um laço sobre as palavras. A maioria passa
direto pela pergunta "está no dicionário?"; só as desconhecidas pagam o preço
dos candidatos. O caminho verde é o de uma palavra como "fiera", seguido do
fim do texto:

{{fluxograma}}

### Trie, hash ou BST?

O exemplo A297 monta as três estruturas com o mesmo dicionário de 2500
palavras de duas sílabas e faz 5000 buscas (metade acha, metade não):

| | BST | Tabela hash | Trie |
| --- | --- | --- | --- |
| custo da busca exata | 17,2 comparações de string | 1,3 comparação de string | 4 nós (o tamanho da palavra) |
| memória | 60 KB | 60 KB | 661 KB |
| palavras com um prefixo | dá, com um percurso por intervalo | não dá | desce até o prefixo e lista |
| ordem alfabética | percurso em ordem | não dá | percurso por letra |
| depende de n? | sim, log n | não (com fator de carga bom) | não |

A hash ganha na busca exata e a trie perde feio na memória. A trie ganha em
tudo que envolve **prefixo**: autocompletar, "maior prefixo em comum", cortar
candidatos que já nascem errados. Um corretor de verdade combina as duas
coisas, e muitas vezes troca o nó de 26 ponteiros por um nó mais enxuto.

> [!WARNING]
> `cor_proxima` só reconhece letras de `'a'` a `'z'`. Maiúscula e acento viram
> separadores: "Hoje" sai como "oje", e "pão" sai como "p" e "o". Antes de
> conferir um texto de verdade, normalize as maiúsculas (exercício E890) e
> decida o que fazer com os acentos: em UTF-8, `'ã'` ocupa 2 bytes e não cabe
> num índice de 0 a 25. A outra pegadinha é de tamanho: `cor_sugere` monta os
> candidatos num vetor de `COR_MAX + 1` posições, porque pôr uma letra deixa a
> palavra uma letra maior que a original.

> [!TIP]
> **Por dentro do C:** a trie de 84 palavras tem 239 nós de 216 bytes, cerca de
> 51 KB, para guardar 351 letras. Cada busca de candidato custa no máximo
> L acessos a nós, mas cada nó fica num lugar diferente do heap (um `calloc` por
> nó), e cada acesso pode ser uma falta de cache. A tabela hash calcula o
> hash, vai a um balde e compara uma string: poucos acessos, quase sempre
> vizinhos. Por isso, em medição de tempo, a hash costuma vencer a trie na busca
> exata mesmo com o mesmo O(L).

> [!NOTE]
> **Pergunta para você:** se o aviso tivesse "onibu", quais sugestões
> apareceriam? E "aa"? Pense em quais palavras do dicionário estão a uma edição
> de cada uma e confira trocando o texto do exemplo.

{{pratique}}
