# Módulo 24 · Busca de padrões em texto

Ctrl+F no navegador, `grep` no terminal, o antivírus procurando a assinatura de
um vírus, o filtro que esconde palavrões no chat, o laboratório procurando um
trecho de DNA num genoma de 3 bilhões de letras. Tudo isso é o mesmo problema:
achar um **padrão** de `m` letras dentro de um **texto** de `n` letras.

A solução óbvia, testar cada posição, funciona e é o que você escreveria sem
pensar. Mas ela tem um pior caso de O(n·m), e em textos grandes isso pesa. Este
módulo mostra três ideias diferentes para fazer melhor, cada uma com um truque
que vale para muito além de strings: **não reler** o que já foi visto (KMP),
**pular** o que não pode dar certo (Horspool) e **comparar números** em vez de
letras (Rabin-Karp).

O módulo junta várias peças anteriores: strings e `string.h` (0041), ponteiros
e aritmética de endereços (0047), o `size_t` e seus perigos (0003), a análise de
custo (0072), invariantes (0073), hashing (0105) e ponteiros para função (0050).
No fim, os quatro algoritmos viram um TAD e você monta um **mini-grep** que
mede qual trabalha menos.

## O que você vai aprender

- a **força bruta** e o `strstr`: ocorrências sobrepostas, o laço até `n - m` e
  a armadilha do `size_t`
- o **KMP**: bordas, a tabela π e uma busca O(n + m) que nunca volta no texto
- o **Horspool**: comparar da direita para a esquerda e saltar com uma tabela
  de 256 posições, com o cuidado do `unsigned char`
- o **Rabin-Karp**: hash rolante, aritmética modular em C e falsos positivos
- a comparar algoritmos por **comparações de letra** e por tempo com `clock()`,
  e a escolher o certo para cada texto

## Como estudar cada assunto

1. Leia o texto e olhe o **diagrama da ideia**: o texto aparece como uma fileira
   de gavetas, uma letra em cada, e o padrão aparece embaixo, encostado em cada
   alinhamento.
2. Leia o código. É o mesmo exemplo, com os mesmos valores.
3. Faça o **Passo a passo** com papel e lápis antes de conferir a tabela.
4. Siga o **fluxograma** com o dedo.
5. Rode os exemplos. Mude o texto e o padrão, compare as contagens.
6. Faça os exercícios. ★☆☆ é aquecimento, ★★☆ pede raciocínio, ★★★ é desafio.
   As dicas vêm logo abaixo do enunciado: tente antes de ler.

No meio de cada assunto tem uma **Pergunta para você**. Responda antes de rodar.

## As cores e as formas

Nos fluxogramas, caixa azul é dado entrando ou saindo, roxa é o programa
fazendo alguma coisa, amarela é pergunta. Verde é o caminho que o exemplo
segue; cinza, o que ele não usa.

Nas fileiras de letras dos diagramas da ideia, **verde** é letra que bateu (ou
ocorrência achada), **vermelha** é a letra que falhou (ou o falso positivo),
**amarela** é a letra que decide o próximo passo, **roxa** é o padrão, **azul**
é texto ainda não comparado e **cinza** é o que o algoritmo não precisou olhar.

<p align="center"><img src="../legenda.svg" alt="Legenda: formas e cores do fluxograma" width="916"></p>

## Antes de começar

Os exemplos dos quatro primeiros assuntos cabem cada um num arquivo só: os
algoritmos são funções curtas, e ver a função inteira junto do `main` ajuda
mais do que separar em `.h` e `.c`. No assunto 0161 eles viram o TAD
`padroes.h`, que o `rodar` compila junto com os exemplos e exercícios da pasta.

Vários exemplos contam **comparações de letra**. Isso não faz parte do
algoritmo: é o "cronômetro" que mostra o custo e que dá o mesmo número em
qualquer máquina. Tempo de relógio só aparece no A321.

Os algoritmos trabalham com **bytes**. Em UTF-8, uma letra acentuada ocupa dois
bytes acima de 127, e num `char` com sinal eles viram números negativos. Isso
não atrapalha comparar, mas atrapalha usar a letra como índice de tabela: o
assunto 0159 mostra o problema e o conserto.

Alguns exercícios de "ache o erro" trazem o bug de propósito, e o
AddressSanitizer (ou o UBSan) do `rodar` vai parar o programa. É esperado: o
enunciado avisa.

{{indice}}

---

{{assuntos}}

---

## Desafios do módulo

Problemas para fechar o módulo, misturando os assuntos. Escreva em C e rode
com o `rodar`.

**1. O curinga.** Adapte a força bruta para aceitar `?` no padrão, valendo
qualquer letra. Procure `c?sa` em `"casa cosa cesta case"`.

<details><summary>Resposta</summary>

A única mudança é a comparação do laço de dentro: a letra casa se
`padrao[j] == '?' || padrao[j] == texto[i + j]`. As ocorrências ficam em **0**
("casa") e **5** ("cosa"); "cesta" falha no `t` e "case" no `e`. Repare que o
KMP e o Horspool não se adaptam tão fácil: a tabela π e a de saltos supõem que
cada letra do padrão é uma letra só.

</details>

**2. Quantas, afinal?** Num texto com mil letras `a`, quantas ocorrências de
`aa` existem contando as sobrepostas? E sem contar? Quantas comparações a força
bruta faz?

<details><summary>Resposta</summary>

Sobrepostas: **999** (uma para cada `i` de 0 a 998). Sem sobreposição
(recomeçando em `i + m` depois de achar): **500**. A força bruta testa os 999
alinhamentos e compara as 2 letras em todos: **1998** comparações. Aqui ela
faz o máximo possível, porque todo alinhamento é uma ocorrência.

</details>

**3. A tabela π de um nome.** Calcule a tabela π de `paraparapa` e diga qual é
a maior borda da palavra inteira.

<details><summary>Resposta</summary>

`pi = 0 0 0 0 1 2 3 4 5 6`. A maior borda tem **6** letras: `parapa`, que é o
começo e também o fim de `paraparapa`. Seguindo a corrente, `pi[5] = 2` dá a
borda seguinte, `pa`. O menor período é `10 - 6 = 4` ("para"), mas 4 não divide
10: a palavra não é uma repetição exata (sobra um "pa").

</details>

**4. O salto perfeito.** Um texto de 3000 letras não tem nenhum `x`, `y` ou `z`.
Quantos alinhamentos e quantas comparações o Horspool faz para procurar `xyz`?
E a força bruta?

<details><summary>Resposta</summary>

Toda letra sob a última casa está fora do padrão, então todo salto é 3: os
alinhamentos são `i = 0, 3, ..., 2997`, ou seja, **1000**, com 1 comparação
cada: **1000** comparações. A força bruta testa os 2998 alinhamentos, com uma
comparação cada (o `x` nunca bate): **2998**. É o melhor caso do Horspool,
`n / m`.

</details>

**5. Rotação.** Escreva `bool eh_rotacao(const char *a, const char *b)`, que diz
se `b` é `a` "girada" (como `drape` é `pedra` girada). Use uma busca de padrão,
em O(n).

<details><summary>Resposta</summary>

Se os tamanhos diferem, não é. Senão, monte `a + a` (por exemplo,
`pedrapedra`) e procure `b` nela com o KMP: toda rotação de `a` aparece dentro
de `a + a`. `drape` aparece na posição 2, então **é** rotação; `perda` não
aparece, então **não é**. Custo O(n) com o KMP; a força bruta aqui pode chegar
a O(n²).

</details>

**6. Quase igual.** Procure `casa` em `"a cosa e a caza na casa"` aceitando
**até uma letra diferente** (o mesmo tamanho, sem inserir nem apagar).

<details><summary>Resposta</summary>

Força bruta que conta as diferenças de cada alinhamento e desiste quando passa
de 1. Aparecem `cosa` na posição **2**, `caza` na **11** e `casa` (exata) na
**19**. Os algoritmos espertos do módulo supõem casamento exato; busca
aproximada é outra família (a distância de edição, do assunto 0142, é o
começo dela).

</details>

**7. Vários tamanhos.** O filtro de spoiler do A320 só funciona com palavras do
mesmo tamanho. Como estender o Rabin-Karp para `{"final", "morre", "vilao",
"mata", "beijo"}`?

<details><summary>Resposta</summary>

Agrupe os padrões por tamanho: aqui, 5 letras (`final`, `morre`, `vilao`,
`beijo`) e 4 (`mata`). Faça uma passada com janela rolante de 5 e outra de 4
(ou as duas no mesmo laço, com dois hashes rolando juntos). Com `k` tamanhos
diferentes, o custo é O(k·n) mais as conferências. Para dezenas de tamanhos,
a estrutura certa é uma trie com ligações de falha (o algoritmo de
Aho-Corasick, um "KMP para vários padrões").

</details>

**8. O pior caso do Rabin-Karp.** Mostre um texto e um padrão em que o
Rabin-Karp faz `(n - m + 1) · m` comparações de letra, por maior que seja o
`q`.

<details><summary>Resposta</summary>

Texto `aaaa...a` e padrão `aaa`. Todas as janelas são iguais ao padrão, então
todos os hashes batem, e **não são** falsos positivos: cada conferência é
necessária e compara `m` letras. Nenhuma escolha de `q` evita isso. O mesmo
texto deixa a força bruta e o Horspool no máximo também; só o KMP fica em O(n),
porque depois de achar ele reaproveita a borda.

</details>

**9. A palavra inteira, com `strstr`.** Conte quantas vezes a palavra `de`
aparece **sozinha** em `"desde cedo, de dia e de noite, ele decide"`, usando
`strstr` e `isalpha`.

<details><summary>Resposta</summary>

Chame `strstr` a partir de `p + 1` depois de cada achado e, para cada `p`,
confira se a letra antes (se existir) e a letra em `p + 2` não são letras. Os
`de` de "desde" (dois) e de "decide" (dois, no começo e no fim) ficam de fora; sobram **2**: "de dia" e
"de noite". O cuidado é não ler `p[-1]` quando `p` é o começo do texto.

</details>

**10. O grep com contexto.** Estenda o A322 com a opção `-C 1`: além da linha
que tem o padrão, mostre a anterior e a seguinte, sem repetir linhas quando
duas ocorrências estão perto.

<details><summary>Resposta</summary>

Guarde a linha anterior num segundo buffer (copiando com `strcpy` antes de
ler a próxima) e um contador "faltam mostrar depois". Ao achar, mostre a
anterior se ela ainda não saiu, mostre a atual e ponha o contador em 1. Numa
linha sem o padrão, se o contador é positivo, mostre e decremente. Uma variável
com o número da última linha impressa evita repetição. É um exercício de
máquina de estados com `fgets`, e a busca continua sendo uma chamada só.

</details>

## Para ler mais

- FEOFILOFF, P. *Algoritmos em linguagem C*. Rio de Janeiro: Elsevier, 2009. Cap. 13 (busca de palavras em um texto: algoritmo trivial e Boyer-Moore).
- FEOFILOFF, P. *Algoritmo de Knuth-Morris-Pratt*. São Paulo: IME-USP. Disponível em: <https://www.ime.usp.br/~pf/estruturas-de-dados/aulas/kmp.html>.
- SZWARCFITER, J. L.; MARKENZON, L. *Estruturas de dados e seus algoritmos*. 3. ed. Rio de Janeiro: LTC, 2010. Cap. de casamento de cadeias (força bruta e KMP).
- CORMEN, T. H. et al. *Algoritmos: teoria e prática*. 3. ed. Rio de Janeiro: Elsevier, 2012. Cap. 32 (correspondência de cadeias: ingênuo, Rabin-Karp, autômatos e KMP).
- SEDGEWICK, R.; WAYNE, K. *Algorithms*. 4. ed. Boston: Addison-Wesley, 2011. Seção 5.3 (substring search).
- KNUTH, D. E.; MORRIS, J. H.; PRATT, V. R. Fast pattern matching in strings. *SIAM Journal on Computing*, v. 6, n. 2, p. 323-350, 1977.
- HORSPOOL, R. N. Practical fast searching in strings. *Software: Practice and Experience*, v. 10, n. 6, p. 501-506, 1980.
- KARP, R. M.; RABIN, M. O. Efficient randomized pattern-matching algorithms. *IBM Journal of Research and Development*, v. 31, n. 2, p. 249-260, 1987.
- CELES, W.; RANGEL, J. L. *Apostila de estruturas de dados*. Rio de Janeiro: PUC-Rio, 2002. Cap. de arquivos (um "grep" simplificado com `fgets` e `strstr`).
- DEITEL, P.; DEITEL, H. *C: como programar*. 6. ed. São Paulo: Pearson Prentice Hall, 2011. Cap. 8 (funções de busca de `string.h`).
- KERNIGHAN, B. W.; RITCHIE, D. M. *C: a linguagem de programação padrão ANSI*. Rio de Janeiro: Campus, 1989. Seções 4.1 (um programa que mostra as linhas com um padrão) e 5.10 (o mesmo programa com as opções `-x` e `-n`).
- CPPREFERENCE. *strstr* e *clock*. Disponível em: <https://en.cppreference.com/w/c/string/byte/strstr> e <https://en.cppreference.com/w/c/chrono/clock>.
- LINUX MAN-PAGES. *strstr(3)*, *clock(3)* e *grep(1)*. Disponível em: <https://man7.org/linux/man-pages/>.
