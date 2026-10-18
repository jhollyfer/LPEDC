# Módulo 19 · Enumeração e backtracking

Muito problema real não tem fórmula. Que combinação de produtos fecha o
crédito exato? Em que ordem o motoboy faz as entregas? Onde ficam as rainhas,
como sair do labirinto, que dígito vai em cada casa do sudoku? Para todos
eles, o jeito honesto é **testar as possibilidades**. A questão é testar com
método: sem esquecer nenhuma, sem repetir nenhuma e sem perder tempo com as
que já se sabe que não servem.

O módulo começa pela **enumeração**: gerar todos os subconjuntos e todas as
permutações com recursão. Daí nasce o **backtracking**, a técnica que
constrói a solução uma escolha por vez e **volta atrás** assim que percebe que
o caminho não dá em nada. O resto do módulo aplica a mesma ideia a
problemas cada vez maiores: soma de subconjuntos, N-rainhas, labirintos,
flood fill e, no fim, um resolvedor de sudoku completo.

A mudança na cabeça é enxergar o problema como uma **árvore de decisões**.
Cada nível é uma escolha; cada caminho da raiz até uma folha é uma tentativa
completa. Enumerar é visitar a árvore inteira. Fazer backtracking é visitar a
árvore **podando** os galhos que não podem ter solução. E o segredo que
separa o código que funciona do que não funciona cabe numa frase: tudo o que
você muda antes de descer, você **desfaz** depois de voltar.

## O que você vai aprender

- gerar todos os **subconjuntos** de um conjunto, pela recursão e pelos **bits** de um número
- gerar todas as **permutações** com troca, recursão e desfazer, e o vetor de **usados**
- o esqueleto do **backtracking**: caso de parada, **poda** e escolha com desfazer
- a **soma de subconjuntos** e o efeito da poda no número de chamadas
- as **N-rainhas** com vetores de colunas e diagonais, testando o ataque em O(1)
- achar um caminho num **labirinto** em matriz e pintar regiões com **flood fill**
- juntar tudo num **resolvedor de sudoku**, e acelerar a busca escolhendo a casa mais apertada

## Como estudar cada assunto

1. Leia o texto e olhe o **diagrama da ideia**: quase sempre é a árvore de
   decisões do exemplo, ou o tabuleiro dele, com os mesmos valores do código.
2. Leia o código. Procure sempre as três partes: onde a função **para**, onde
   ela **poda** e onde ela **escolhe e desfaz**.
3. Siga o **fluxograma** com o dedo. Em backtracking ele é curto, porque a
   recursão esconde a repetição: cada caixa de chamada recursiva é o
   fluxograma inteiro de novo.
4. Rode os exemplos. Mude a ordem das opções, tire a poda, esqueça o
   desfazer de propósito e compare a saída e o número de chamadas.
5. Faça os exercícios. ★☆☆ é aquecimento, ★★☆ pede raciocínio, ★★★ é desafio.
   As dicas vêm logo abaixo do enunciado: tente antes de ler.

Quase todo programa do módulo conta as **chamadas** da função recursiva. É o
jeito mais simples de ver uma poda funcionando: a saída fica igual e o número
cai.

## As cores e as formas

Caixa azul é dado entrando ou saindo, roxa é o programa fazendo alguma coisa,
amarela é pergunta. Verde é o caminho que o exemplo segue; cinza, o que ele não
usa. Nas árvores de decisão, amarelo é uma decisão ainda aberta, verde é uma
solução, vermelho é um galho podado e cinza é um beco sem saída. Nos
tabuleiros, as casas verdes são a solução e as vermelhas, as proibidas.

<p align="center"><img src="../legenda.svg" alt="Legenda: formas e cores do fluxograma" width="916"></p>

## Antes de começar

Este módulo é **recursão** do começo ao fim: revise os assuntos 0031 (pilha de
chamadas), 0032 e 0033 se ainda precisar pensar muito para seguir uma função
que chama a si mesma. Você também vai usar matrizes (0039), operadores de
bits (0065) e o vetor de `bool` de `<stdbool.h>`. O labirinto é a DFS do
assunto 0111 com a matriz no lugar do grafo, e a BFS (0110) aparece como a
ferramenta certa para o menor caminho. A pilha (0082) é a saída quando a
recursão ficaria funda demais.

Uma convenção vale para o módulo todo: **os vetores de marcação começam e
terminam a busca do mesmo jeito**. Se, depois de um backtracking, sobrou algum
`true` que não estava lá no começo, faltou um desfazer.

Um aviso: o exercício E773 é um "ache o bug" cujo código, de propósito,
derruba o programa com estouro de pilha. O AddressSanitizer vai acusar
`stack-overflow` até você consertar.

{{indice}}

---

{{assuntos}}

---

## Desafios do módulo

Problemas para resolver no papel e, quando fizer sentido, num arquivo `.c` seu.
Eles misturam os assuntos do módulo.

**1. Amigo secreto.** Quatro amigos sorteiam o amigo secreto e ninguém pode
tirar o próprio nome. Quantos sorteios válidos existem? E com cinco amigos?

<details><summary>Resposta</summary>

São **9** com quatro e **44** com cinco. Cada sorteio é uma permutação em que
`pos[i] != i` para todo `i` (um **desarranjo**). Caminho: a permutação com
vetor de usados do exemplo A251, com uma poda a mais: na posição `i`, pule o
candidato `i`. A conta direta é 4! · (1 - 1 + 1/2 - 1/6 + 1/24) = 9.

</details>

**2. O quadrado mágico.** Quantos jeitos há de escolher três números
diferentes de 1 a 9 que somam 15 (sem importar a ordem)?

<details><summary>Resposta</summary>

São **8**: {1, 5, 9}, {1, 6, 8}, {2, 4, 9}, {2, 5, 8}, {2, 6, 7}, {3, 4, 8},
{3, 5, 7} e {4, 5, 6}. São exatamente as 3 linhas, as 3 colunas e as 2
diagonais do quadrado mágico 3 × 3. Caminho: combinações de 3 com o
`inicio` do exemplo A250 e a poda "passou de 15, volte".

</details>

**3. Somando 15.** Quantos subconjuntos de {1, 2, ..., 10} somam exatamente
15? Que poda funciona quando os números estão em ordem crescente?

<details><summary>Resposta</summary>

São **20** subconjuntos. Com os números em ordem crescente, dá para podar mais
cedo que no texto: se `soma + v[i]` já passa de 15, nenhum item a partir de
`i` cabe (todos são maiores), e a função pode voltar sem tentar nem o caminho
"sem o item".

</details>

**4. Dois times de mesma soma.** As camisas de 1 a 8 precisam ser divididas
em dois times cuja soma dos números seja igual. De quantas formas?

<details><summary>Resposta</summary>

A soma total é 36, então cada time soma **18**. Há 14 subconjuntos de
{1..8} com soma 18, mas cada divisão aparece duas vezes (o time e o
complemento): **7** divisões. Caminho: o E748, fixando a camisa 1 num dos
times para não contar em dobro.

</details>

**5. BANANA.** Quantos anagramas diferentes tem a palavra BANANA? Quantas
linhas a recursão por trocas do texto mostraria?

<details><summary>Resposta</summary>

São 6! / (3! · 2!) = 720 / 12 = **60** anagramas diferentes. A recursão por
trocas não sabe que as letras iguais são iguais: mostraria as **720** ordens,
cada anagrama repetido 12 vezes. O jeito do exemplo A252, com a contagem de
cada letra, gera só os 60.

</details>

**6. Troco de R$ 1,00.** De quantas formas dá para formar R$ 1,00 com moedas
de 5, 10, 25 e 50 centavos, podendo repetir moedas? Como evitar contar
"50 + 25 + 25" e "25 + 50 + 25" como formas diferentes?

<details><summary>Resposta</summary>

São **40** formas. Para não repetir, escolha as moedas em ordem não
crescente: a função recebe o índice da maior moeda ainda permitida e só
desce para moedas iguais ou menores. É a mesma ideia do `inicio` das
combinações (A250), e o problema volta no módulo de programação dinâmica.

</details>

**7. Caminhos na praça.** Numa grade vazia 3 × 3, quantos caminhos sem
repetir casa vão de um canto ao canto oposto (andando na horizontal e na
vertical)? E numa 4 × 4?

<details><summary>Resposta</summary>

São **12** na 3 × 3 e **184** na 4 × 4 (numa 5 × 5, 8512). É o exemplo A258
sem paredes. O número explode porque, ao desmarcar a casa na volta, a busca
deixa de ser O(L · C): cada caminho diferente é visitado inteiro.

</details>

**8. Rainhas impossíveis.** Mostre, no papel, por que não existe solução das
N-rainhas para N = 2 e N = 3. E das 92 soluções do 8-rainhas, quantas têm uma
rainha em algum canto do tabuleiro?

<details><summary>Resposta</summary>

N = 2: as duas casas da linha 1 estão na coluna ou na diagonal da rainha da
linha 0. N = 3: rainha da linha 0 no canto deixa uma casa só na linha 1, e as
duas juntas atacam a linha 2 inteira; no meio, ela ataca a linha 1 inteira. No
8-rainhas, **16** soluções têm rainha num canto. Caminho: conte as soluções
em que `pos[0]` ou `pos[7]` vale 0 ou 7.

</details>

**9. O décimo estado.** No código de Gray de 4 bits (o pisca-pisca do E750
com quatro lâmpadas), qual é o 10º estado, contando o 0000 como o 1º?

<details><summary>Resposta</summary>

O 10º estado é o de `m = 9`: `9 ^ (9 >> 1)` = `1001 ^ 0100` = **1101**. O
anterior (m = 8) é 1100, então a passagem acende a lâmpada 0.

</details>

**10. Sudoku sem chute.** No jogo do texto (assunto 0130), quantas casas vazias
têm um candidato só logo no começo? Por que preencher essas casas antes da
busca ajuda?

<details><summary>Resposta</summary>

São **2**: a (4, 0), que só aceita o 3, e a (5, 5), que só aceita o 7.
Preencher uma casa de candidato único não cria ramo nenhum na árvore, e ainda
corta candidatos das vizinhas, que às vezes ficam com um candidato só também.
A heurística do exemplo A260 faz isso naturalmente: a casa de 1 candidato é
sempre a mais apertada.

</details>

**11. Quanto tempo?** Um computador faz uns 100 milhões de chamadas
recursivas simples por segundo. Quanto tempo leva enumerar todos os
subconjuntos de 30 itens, sem poda nenhuma? E de 40?

<details><summary>Resposta</summary>

A árvore tem 2ⁿ⁺¹ - 1 nós. Com 30 itens, uns **2,1 bilhões** de chamadas:
cerca de 21 segundos. Com 40, uns **2,2 trilhões**: mais de 6 horas. Cada
item a mais dobra o tempo. É por isso que a poda importa, e é por isso que
problemas como a mochila ganham, no módulo 21, um método que não testa tudo.

</details>

## Para ler mais

- FEOFILOFF, P. *Algoritmos em linguagem C*. Rio de Janeiro: Elsevier, 2009. Capítulo sobre enumeração (subsequências, combinações e permutações) e os exercícios de backtracking.
- FEOFILOFF, P. *Projeto de algoritmos em C*: enumeração e backtracking. São Paulo: IME-USP. Disponível em: <https://www.ime.usp.br/~pf/algoritmos/>.
- TENENBAUM, A. M.; LANGSAM, Y.; AUGENSTEIN, M. J. *Estruturas de dados usando C*. São Paulo: Makron Books, 1995. Cap. 3: recursividade (oito rainhas e labirinto com backtracking).
- WIRTH, N. *Algoritmos e estruturas de dados*. Rio de Janeiro: LTC, 1989. Capítulo sobre algoritmos de tentativa e erro (as oito rainhas e o passeio do cavalo).
- ZIVIANI, N. *Projeto de algoritmos: com implementações em Pascal e C*. 3. ed. São Paulo: Cengage Learning, 2011. Paradigmas de projeto: tentativa e erro.
- DEITEL, P.; DEITEL, H. *C: como programar*. 6. ed. São Paulo: Pearson, 2011. Exercícios do passeio do cavalo, das oito rainhas e do labirinto; apêndice sobre sudoku.
- CASTILHO, M. A.; SILVA, F.; WEINGAERTNER, D. *Algoritmos e estruturas de dados 1*. Curitiba: UFPR, 2020. Capítulos sobre matrizes e o flood fill.
- ROVAI, K. R. *Algoritmos e estrutura de dados*. Londrina: Editora e Distribuidora Educacional, 2018. Pilhas: o labirinto e a memória de decisões.
- KNUTH, D. E. *The art of computer programming*. v. 4A: combinatorial algorithms, part 1. Boston: Addison-Wesley, 2011. Geração de tuplas (código de Gray), permutações e combinações.
- CORMEN, T. H. et al. *Algoritmos: teoria e prática*. 3. ed. Rio de Janeiro: Elsevier, 2012. Cap. 22: busca em profundidade e busca em largura (a base do labirinto e do flood fill).
- KERNIGHAN, B. W.; RITCHIE, D. M. *C: a linguagem de programação padrão ANSI*. Rio de Janeiro: Campus, 1989. Seção 4.10: recursividade.
