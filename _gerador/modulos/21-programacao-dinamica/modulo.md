# Módulo 21 · Programação dinâmica

No módulo 04, o Fibonacci recursivo ficou famoso por ser lento: `fib(40)`
leva centenas de milhões de chamadas para chegar num número que um laço
calcula em 40 passos. Lá ficou a pergunta: por que a recursão é tão cara? A
resposta é que ela resolve as **mesmas** perguntas de novo e de novo. Este
módulo é sobre o remédio: anotar cada resposta na primeira vez e consultar
nas próximas.

Essa ideia, a **programação dinâmica**, resolve problemas que
pareciam exigir testar todas as combinações: o menor número de moedas para
um troco qualquer, o que levar na mochila sem passar do peso, o que duas
sequências de DNA têm em comum, quantas edições separam a palavra digitada
da palavra certa. Todos têm a mesma cara: uma **recorrência** que olha para
o último passo, uma **tabela** que guarda os subproblemas e uma **volta**
pela tabela que reconstrói a solução.

No módulo 20 você viu os gulosos, que acertam quando a melhor escolha de
agora nunca atrapalha o futuro, e viu também em que casos eles erram. A PD é o que
se usa quando o guloso não serve: ela considera todas as escolhas, mas
paga cada subproblema uma vez só. A troca é memória por tempo, e o "Por
dentro do C" de cada assunto mostra quanto essa memória custa.

O módulo fecha com um **mini-diff**, a ferramenta
que mostra o que mudou entre duas versões de um arquivo de texto.

## O que você vai aprender

- **memoização** (de cima para baixo) e **tabela** (de baixo para cima), e
  como contar o custo de uma PD: subproblemas × trabalho de cada um
- reconhecer quando a PD se aplica: **subproblemas que se repetem** e
  **subestrutura ótima**
- **troco**: o menor número de moedas para qualquer sistema e quantas
  combinações existem (e a diferença entre combinação e sequência)
- **mochila 0/1**: a tabela n × W, a recuperação dos itens e o truque de uma
  linha só com o laço descendo
- **LCS**: a maior subsequência comum e a volta pela tabela
- **distância de edição** (Levenshtein): inserir, remover e trocar
- juntar tudo num **mini-diff** entre dois arquivos, com leitura de linhas,
  vetor que cresce e tabela no heap

## Antes de começar

Você vai precisar da recursão (assuntos 0032 e 0033), de matrizes (0039),
de strings (0041 e 0042) e de memória dinâmica (0054 e 0055). O assunto
0133, do troco guloso, é o ponto de partida do 0139, e a mochila
fracionária do 0135 é a prima fácil da mochila 0/1.

Quase todos os exemplos cabem num arquivo só, com a tabela numa matriz de
tamanho fixo (`#define MAX 50`). Isso é de propósito: deixa a recorrência à
vista. Nos programas "de verdade" (o mini-diff), a tabela vai para o heap,
num bloco só do `malloc`.

A multiplicação de uma **cadeia de matrizes**, outro clássico de PD do Cormen
e do cursinho do PPGI, tem assunto próprio, o 0185.

Alguns exercícios de "ache o erro" trazem o bug de propósito, e o
AddressSanitizer (ou o UBSan) do `rodar` vai acusar ou parar o programa. É
esperado: o enunciado avisa.

PD se aprende preenchendo tabela: faça o **Passo a passo** com papel e lápis
antes de conferir. O diagrama da ideia quase sempre é a própria tabela, e o
fluxograma é a decisão de uma célula. Nas tabelas, **roxa** é a célula que está
sendo calculada (ou de onde a volta parte), **verde** é a escolhida ou o
caminho da solução, **amarela** é a opção que perdeu (ou um passo da volta
que não entra na resposta) e **cinza** é o que não chega a ser usado.

{{indice}}

---

{{assuntos}}

---

## Desafios do módulo

Problemas para fechar o módulo, misturando os assuntos. Escreva em C e rode
com o `rodar`.

**1. A madeireira e o corte das tábuas.** Uma tábua de 8 m pode ser vendida
inteira ou cortada em pedaços de metro inteiro. O preço de cada pedaço, por
tamanho de 1 a 8 m, é: R$ 2, 5, 9, 10, 13, 17, 18 e 22. Qual o maior
faturamento com uma tábua de 8 m, e quais cortes?

<details><summary>Resposta</summary>

É um "troco" de maximização: `B[k] = maior entre preco[i] + B[k - i]`, para
`i` de 1 a `k`, com `B[0] = 0`. A tabela fica `0 2 5 9 11 14 18 20 23`, e a
resposta é **R$ 23**: pedaços de 2 + 3 + 3 m (5 + 9 + 9). Vender inteira dá
só R$ 22. Guarde em `S[k]` o tamanho do primeiro pedaço para reconstruir os
cortes, como o `ultimo[]` do assunto 0139.

</details>

**2. O maior terreno quadrado.** Num mapa de lotes, 1 é terreno livre e 0 é
ocupado:

```
1 0 1 1 1
1 1 1 1 1
0 1 1 1 1
1 1 1 1 0
1 1 0 1 1
```

Qual o maior quadrado só de 1s? Resolva em O(linhas × colunas).

<details><summary>Resposta</summary>

`q[i][j]` = lado do maior quadrado de 1s com canto inferior direito em
`(i, j)`. Se a célula é 1, `q[i][j] = 1 + menor(q[i-1][j], q[i][j-1],
q[i-1][j-1])`; se é 0, vale 0. O maior valor é **3**, terminando em `(2, 4)`:
linhas 0 a 2, colunas 2 a 4. É a mesma "olhada para três vizinhos" da
distância de edição.

</details>

**3. A grade com atalho diagonal.** Na grade do A275, sem obras, o
entregador pode andar para a direita, para baixo **ou na diagonal** (direita
e baixo de uma vez). Quantas rotas existem numa grade de 4 × 4 cruzamentos,
de um canto ao outro?

<details><summary>Resposta</summary>

Agora são três vizinhos: `r[i][j] = r[i-1][j] + r[i][j-1] + r[i-1][j-1]`,
com `r[0][0] = 1`. São **63** rotas (contra 20 sem a diagonal). Esses são
os números de Delannoy.

</details>

**4. A palavra que vira palíndromo.** Qual o menor número de letras que é
preciso **inserir** em ARARAQUARA para ela virar um palíndromo (ler igual
de trás para a frente)? E em OVO? E em BANANA?

<details><summary>Resposta</summary>

O que já é "palíndromo escondido" na palavra é a LCS dela com ela mesma
invertida; o resto precisa ganhar um par. Inserções = `n - LCS(s,
reverso(s))`: ARARAQUARA precisa de **3**, OVO de **0** e BANANA de **1**
(BANANAB). Uma PD direta, `p[i][j]` para o pedaço `s[i..j]`, dá o mesmo
resultado.

</details>

**5. Mochila com estoque infinito.** Com capacidade 10 e itens (peso,
valor) = (3, 40), (4, 50), (5, 62), compare a mochila 0/1 com a mochila
**ilimitada**, em que cada item pode ir quantas vezes quiser.

<details><summary>Resposta</summary>

A 0/1 dá **112** (pesos 4 + 5). A ilimitada dá **130** (3 + 3 + 4: 40 + 40
+ 50). A diferença no código é uma só: no vetor de uma linha, o laço de
capacidade **sobe** em vez de descer, exatamente o "erro" do A279. Na
mochila ilimitada, ele é o certo.

</details>

**6. Quantas vezes a palavra se esconde.** Quantas vezes ABC aparece como
**subsequência** em AABBCC? E ANA em BANANA?

<details><summary>Resposta</summary>

`w[k]` = de quantos jeitos os `k` primeiros caracteres do padrão aparecem
no texto lido até agora. Para cada letra do texto, de `k` alto para baixo:
se ela é igual a `padrao[k-1]`, `w[k] += w[k-1]` (o mesmo laço descendo da
mochila 0/1). AABBCC tem **8** (2 × 2 × 2 escolhas); BANANA tem **4**.

</details>

**7. A maior sequência crescente, sem LCS.** No E846 você usou a LCS com o
vetor ordenado. Resolva direto: para `10 4 12 6 15 8 9 20 3 11`, qual o
tamanho da maior subsequência estritamente crescente?

<details><summary>Resposta</summary>

`f[i]` = tamanho da maior crescente que **termina** em `v[i]`: `f[i] = 1 +
maior f[j]` com `j < i` e `v[j] < v[i]`. O vetor `f` fica `1 1 2 2 3 3 4 5
1 5`, e a resposta é **5** (por exemplo 4 6 8 9 20). É O(n²); existe uma
versão O(n log n) com busca binária (assunto 0090).

</details>

**8. Dá para dividir ao meio?** Cinco irmãos herdaram objetos avaliados em
R$ 3, 1, 5, 9 e 12 mil e querem saber se dá para dividir tudo em dois
lotes de **mesmo** valor. E se fossem R$ 3, 1, 5, 9 e 11 mil?

<details><summary>Resposta</summary>

É o A280 com a pergunta "a soma total / 2 é alcançável?". No primeiro caso
o total é 30 e 15 = 3 + 12 é alcançável: **sim**. No segundo, o total é 29,
ímpar: **não**, sem nem montar a tabela.

</details>

**9. Quebrar sem espaços.** Uma mensagem chegou sem espaços:
`cafecomleitequente`. Com o dicionário {cafe, com, leite, quente, co, mleite,
que, nte}, ela pode ser quebrada em palavras? De quantos jeitos?

<details><summary>Resposta</summary>

`q[i]` = de quantos jeitos o prefixo de tamanho `i` se quebra em palavras;
`q[0] = 1` e `q[i]` soma `q[i - tamanho]` para cada palavra do dicionário
que termina exatamente na posição `i`. São **4** jeitos: "cafe com leite"
ou "cafe co mleite", seguido de "quente" ou "que nte". Com memoização, uma
recursão que testa cada palavra no começo faz o mesmo.

</details>

**10. Distância de edição com pouca memória.** Duas sequências de DNA têm
100 mil bases cada. A tabela inteira da distância de edição teria 10¹⁰
células. Como calcular só a distância com memória O(n)?

<details><summary>Resposta</summary>

Cada linha da tabela só usa a de cima: guarde duas linhas e troque os
ponteiros a cada volta, como no A281. São 2 × 100.001 `int`, uns 800 KB, em
vez de 40 GB. O tempo continua O(m × n). Recuperar as operações com pouca
memória também é possível (algoritmo de Hirschberg, que divide a tabela ao
meio recursivamente), mas dá mais trabalho.

</details>

## Questões no estilo da prova

Questões objetivas no formato da Prova de Conhecimentos do PPGI: uma
alternativa certa. Resolva no papel, com a tabela à mão, antes de abrir o
gabarito.

**1.** Na mochila 0/1 com capacidade `W = 7` e os itens (peso, valor) = (1,
3), (3, 4), (4, 6) e (5, 7), nessa ordem, `t[i][c]` é o maior valor usando
só os itens `1..i` com capacidade `c`. Qual o valor de `t[4][7]`?

- (A) 9
- (B) 13
- (C) 10
- (D) 11
- (E) 16

<details><summary>Gabarito</summary>

**(C).** A linha 4 da tabela fica `0 3 3 4 7 9 10 10`. Dois conjuntos
empatam em 10: pesos 3 + 4 (4 + 6) e pesos 1 + 5 (3 + 7). O 13 (3 + 4 + 6)
pesaria 8 kg, e o 16 é a soma de todos os valores, sem limite de peso. Veja
0140.

</details>

**2.** Qual o tamanho da maior subsequência comum (LCS) de `AMAZONAS` e
`MANAUS`?

- (A) 5
- (B) 4
- (C) 6
- (D) 3
- (E) 8

<details><summary>Gabarito</summary>

**(A).** `MANAS`: M, A, N, A e S aparecem nessa ordem nas duas palavras.
Uma subsequência não precisa ser contígua; a maior **substring** comum
seria bem menor. O 6 seria a palavra `MANAUS` inteira, que não é
subsequência de `AMAZONAS` (não tem U). Veja 0141.

</details>

**3.** Sobre a LCS de duas sequências de tamanhos `m` e `n` pela tabela de
programação dinâmica, é correto afirmar:

- (A) o tempo é Θ(m + n), porque cada letra é lida uma vez.
- (B) o tempo é Θ(2^m), porque toda subsequência de uma das sequências é testada.
- (C) para obter só o tamanho da LCS, a tabela inteira de Θ(m × n) posições é indispensável.
- (D) o tempo é Θ(m × n × min(m, n)), porque cada célula percorre uma linha inteira.
- (E) o tempo é Θ(m × n); para obter só o tamanho, duas linhas, Θ(min(m, n)) de memória, bastam.

<details><summary>Gabarito</summary>

**(E).** São `(m + 1) × (n + 1)` células, cada uma em O(1). Cada linha só
lê a de cima, então duas linhas bastam para o tamanho (escolha a sequência
menor para as colunas). Para **recuperar** a LCS, o caminho simples precisa
da tabela inteira. Veja 0141 e o A281.

</details>

**4.** A mochila 0/1 por programação dinâmica roda em O(n × W), em que `W`
é a capacidade. Por que isso **não** prova que o problema é polinomial?

- (A) Porque a PD só funciona quando todos os pesos são iguais.
- (B) Porque `W` é um número da entrada, escrito com cerca de log₂ W bits: O(n × W) é exponencial no tamanho da entrada (tempo pseudopolinomial).
- (C) Porque a tabela tem 2ⁿ linhas.
- (D) Porque a recuperação dos itens custa O(2ⁿ).
- (E) Porque a PD dá só uma aproximação do ótimo.

<details><summary>Gabarito</summary>

**(B).** Dobrar o número de bits de `W` eleva `W` ao quadrado. O(n × W) é
polinomial no **valor** de `W`, não no tamanho da entrada; por isso se diz
**pseudopolinomial**. A versão de decisão da mochila é NP-completa (assunto
0186). A tabela tem `n + 1` linhas, e a recuperação é O(n). Veja 0140.

</details>

**5.** A função abaixo é chamada com `memo[]` todo em `-1`. Quantas vezes
`formas` é executada, contando a chamada inicial, em `formas(20)`?

```c
long long memo[50];

long long formas(int n) {
    if (n <= 1) {
        return 1;
    }
    if (memo[n] != -1) {
        return memo[n];
    }
    memo[n] = formas(n - 1) + formas(n - 2);
    return memo[n];
}
```

- (A) 20
- (B) 21
- (C) 10.946
- (D) 39
- (E) 21.891

<details><summary>Gabarito</summary>

**(D).** A primeira descida, `formas(20)`, `formas(19)`, ..., `formas(1)`,
são 20 chamadas. Na volta, cada `n` de 2 a 20 faz a segunda chamada,
`formas(n - 2)`, que acha a resposta pronta (ou é caso base): mais 19. Em
geral, `2n - 1`. Sem o memo seriam 21.891 chamadas, e 10.946 é o valor de
`formas(20)`. Veja 0138.

</details>

**6.** Sobre programação dinâmica (PD), analise as afirmações.

- I. Para a PD servir, o problema precisa ter subestrutura ótima e
  subproblemas sobrepostos.
- II. A memoização (de cima para baixo) e o preenchimento da tabela (de baixo
  para cima) resolvem cada subproblema uma única vez.
- III. Assim como no guloso, a PD nunca precisa guardar o resultado de
  subproblemas.

Marque a alternativa **CORRETA**.

- (A) I e II, apenas.
- (B) I e III, apenas.
- (C) II e III, apenas.
- (D) I, apenas.
- (E) I, II e III.

<details><summary>Gabarito</summary>

**(A).** I é o critério do Cormen: a solução ótima é feita de soluções ótimas
de subproblemas (**subestrutura ótima**) e esses subproblemas se repetem
(**sobrepostos**). II é verdadeira: é por guardar o resultado que o custo cai
de exponencial para polinomial. III é falsa: guardar os resultados é o
que define a PD; o guloso é que decide sem olhar para trás (0133). Veja 0138 e
0139.

</details>

**7.** Com moedas de 1, 3 e 4 e troco de 6, sejam `G` o número de moedas
do algoritmo guloso (maior moeda que cabe) e `D` o mínimo calculado pela
programação dinâmica `dp[v] = 1 + min(dp[v - moeda])`. Então:

- (A) G = 2 e D = 2.
- (B) G = 3 e D = 3.
- (C) G = 3 e D = 2.
- (D) G = 2 e D = 3.
- (E) G = 4 e D = 2.

<details><summary>Gabarito</summary>

**(C).** O guloso faz 4 + 1 + 1 (três moedas); a PD acha 3 + 3 (duas). A PD
nunca perde para o guloso, porque testa todas as últimas moedas. Veja 0133
e 0139.

</details>

**8.** Qual a distância de edição (Levenshtein: inserir, remover ou trocar
uma letra, custo 1 cada) entre `TERRA` e `TORTA`?

- (A) 0
- (B) 1
- (C) 3
- (D) 4
- (E) 2

<details><summary>Gabarito</summary>

**(E).** As palavras têm o mesmo tamanho e diferem em duas posições: troca
o E por O e o segundo R por T. Não dá com 1, porque uma operação só muda
uma posição (ou o tamanho). Veja 0142.

</details>

**9.** O trecho preenche o vetor `g` com capacidade 7 e os itens (peso,
valor) = (2, 3) e (3, 5). Repare no sentido do laço de `c`. Qual o valor
de `g[7]` no fim?

```c
int peso[] = {2, 3}, valor[] = {3, 5};
int g[8] = {0};
for (int i = 0; i < 2; i++) {
    for (int c = peso[i]; c <= 7; c++) {
        if (g[c - peso[i]] + valor[i] > g[c]) {
            g[c] = g[c - peso[i]] + valor[i];
        }
    }
}
```

- (A) 8
- (B) 11
- (C) 10
- (D) 13
- (E) 5

<details><summary>Gabarito</summary>

**(B).** Com `c` **subindo**, `g[c - peso[i]]` já pode conter o próprio
item `i`, e cada item vale quantas vezes couber: é a mochila **ilimitada**.
O melhor é 2 + 2 + 3 (3 + 3 + 5 = 11). Com o laço descendo (mochila 0/1),
seria 8 (os dois itens, uma vez cada). Veja 0140 e o A279.

</details>

**10.** Sobre memoização (de cima para baixo) e tabela (de baixo para
cima), analise as afirmações.

- I. A memoização tem complexidade assintótica pior que a da tabela, porque
  faz chamadas recursivas.
- II. A memoização resolve só os subproblemas que a resposta realmente usa; a
  tabela costuma preencher todos.
- III. A tabela exige uma ordem de preenchimento em que as dependências já
  estejam prontas.
- IV. Nas duas, o custo é (número de subproblemas) × (trabalho de cada um).

Marque a alternativa **CORRETA**.

- (A) I e II, apenas.
- (B) I, III e IV, apenas.
- (C) I e IV, apenas.
- (D) II, III e IV, apenas.
- (E) I, II, III e IV.

<details><summary>Gabarito</summary>

**(D).** I é falsa: as duas têm o mesmo custo assintótico; a memoização só
paga o frame de cada chamada (e pode estourar a pilha). II, III e IV são
verdadeiras. Veja 0138.

</details>

## Para ler mais

- CORMEN, T. H.; LEISERSON, C. E.; RIVEST, R. L.; STEIN, C. *Algoritmos: teoria e prática*. 4. ed. Rio de Janeiro: GEN LTC, 2024. Cap. 14 (programação dinâmica: corte de hastes, cadeia de matrizes, LCS, subestrutura ótima e subproblemas sobrepostos) e seção 15.2 (mochila 0/1 contra a fracionária).
- ZIVIANI, N. *Projeto de algoritmos: com implementações em Pascal e C*. 3. ed. rev. e ampl. São Paulo: Cengage Learning, 2010. Cap. 2 (paradigmas de projeto de algoritmos, com programação dinâmica).
- LINTZMAYER, C. N.; MOTA, G. O. *Análise de algoritmos e de estruturas de dados*. Santo André: UFABC; São Paulo: IME-USP, 2023. Versão preliminar. Cap. de programação dinâmica (memoização, mochila, alinhamento de sequências).
- FEOFILOFF, P. *Algoritmos em linguagem C*. Rio de Janeiro: Elsevier, 2009. Caps. de recursão e de enumeração, base para entender o custo da recursão pura.
- SZWARCFITER, J. L.; MARKENZON, L. *Estruturas de dados e seus algoritmos*. 3. ed. Rio de Janeiro: LTC, 2010. Seção de árvore binária de busca ótima, um exemplo clássico de programação dinâmica.
- TENENBAUM, A. M.; LANGSAM, Y.; AUGENSTEIN, M. J. *Estruturas de dados usando C*. São Paulo: Makron Books, 1995. Cap. 3 (recursão, o custo do Fibonacci recursivo e a versão iterativa).
- KLEINBERG, J.; TARDOS, É. *Algorithm design*. Boston: Pearson, 2006. Cap. 6 (programação dinâmica: mochila, alinhamento de sequências e o algoritmo de Hirschberg).
- KERNIGHAN, B. W.; RITCHIE, D. M. *C: a linguagem de programação padrão ANSI*. Rio de Janeiro: Campus, 1989. Seções 5.7 a 5.9 (matrizes multidimensionais e vetores de ponteiros).
- LEVENSHTEIN, V. I. Binary codes capable of correcting deletions, insertions, and reversals. *Soviet Physics Doklady*, v. 10, n. 8, p. 707-710, 1966.
- MYERS, E. W. An O(ND) difference algorithm and its variations. *Algorithmica*, v. 1, p. 251-266, 1986.
- LINUX MAN-PAGES. *diff(1)*. Disponível em: <https://man7.org/linux/man-pages/man1/diff.1.html>.
- CPPREFERENCE. *fgets* e *strcspn*. Disponível em: <https://en.cppreference.com/w/c/io/fgets>.
