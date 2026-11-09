# Módulo 12 · Pilhas e filas

A lista encadeada do módulo 11 deixa você inserir e remover em qualquer
lugar. Este módulo faz o contrário: **proíbe**. Uma pilha só mexe no topo;
uma fila só entra por um lado e sai pelo outro. Parece perda, mas a restrição
traz uma garantia: o desfazer sempre desfaz o último passo, e quem chegou
primeiro é atendido primeiro.

Você usa essas estruturas o dia inteiro sem perceber. A pilha de chamadas do seu
programa, o Ctrl+Z, o botão Voltar e o *parser* de um compilador são pilhas. A
fila de processos do sistema operacional, a fila de jobs do seu backend e a
impressora do escritório são filas. Aqui você constrói as duas do zero, cada
uma de dois jeitos (vetor e lista encadeada), sempre como **TAD**: o mesmo
`.h`, o `.c` trocado por baixo, e o programa cliente não muda.

## O que você vai aprender

- o TAD **pilha** (LIFO) sobre vetor: empilhar, desempilhar, topo, *overflow* e *underflow*
- a **pilha encadeada**: por que o topo fica no começo da lista
- duas aplicações clássicas: **parênteses balanceados** e **notação pós-fixa**
- o TAD **fila** (FIFO) e a **fila circular** sobre vetor, com o `%` dando a volta
- a **fila encadeada** com ponteiros de início e fim, e os bugs das bordas
- o **deque**, que entra e sai pelas duas pontas, e a pegadinha do resto negativo
- uma calculadora que junta tudo: infixa → pós-fixa → resultado

## Antes de começar

Os diagramas da ideia mostram a memória por dentro: neles, verde marca o item
que está saindo e cinza a gaveta que já virou vaga.

Você precisa estar à vontade com ponteiros, `malloc`/`free`, `struct` com
`->` e listas encadeadas (módulos 06, 07, 08 e 11), além da ideia de TAD do
assunto 0074.

Cada pasta de assunto traz os arquivos do TAD ao lado dos exemplos:
`pilha.h` e `pilha.c`, `fila.h` e `fila.c` ou `deque.h` e `deque.c`. O
`rodar` compila esses `.c` de apoio junto com qualquer exemplo ou exercício
da pasta:

```bash
~/LPEDC/rodar 12-pilhas-e-filas/0082-pilha/A163.c
```

Num exercício, **não** crie funções com os nomes do TAD
(`pilha_cria`, `fila_insere`...): o ligador reclamaria de definição
duplicada. Os exercícios que pedem uma estrutura diferente usam outros nomes
e trazem tudo no próprio arquivo.

{{indice}}

---

{{assuntos}}

---

## Desafios do módulo

Problemas para resolver num arquivo seu, misturando os assuntos do módulo.
Use os TADs das pastas ou escreva a estrutura do zero.

**1. Quais saídas são possíveis?** Os números 1, 2, 3, 4 e 5 entram numa
pilha nessa ordem, e você pode desempilhar quando quiser. Escreva
`bool possivel(const int *saida, int n, char *ops)` com o TAD `pilha.h`,
que simula a pilha e, quando a saída for possível, preenche `ops` com a
sequência de `E` (empilha) e `D` (desempilha) usada. Teste com (a) 3 2 1 5 4;
(b) 4 5 3 1 2; (c) 1 2 3 4 5; (d) 5 4 3 2 1.

<details><summary>Resposta</summary>

```
(a) 3 2 1 5 4: possivel com EEEDDDEEDD
(b) 4 5 3 1 2: impossivel
(c) 1 2 3 4 5: possivel com EDEDEDEDED
(d) 5 4 3 2 1: possivel com EEEEEDDDDD
```

Dica: para cada número da saída, empilhe os próximos que chegam enquanto o
topo não for ele (e ainda houver números); se mesmo assim o topo não for
ele, é impossível. Em (b), quando o 3 sai, o 2 está por cima do 1, então o 2
teria que sair antes. Libere a pilha nos dois caminhos.

</details>

**2. Tags HTML balanceadas.** Escreva um verificador para tags simples, sem
atributos: `<p><b>oi</b></p>` está certo, `<p><b>oi</p></b>` não. Teste
também com `<ul><li>a</li><li>b</li></ul>`.

<details><summary>Resposta</summary>

Certo, errado, certo. É o verificador do 0084 com palavras no lugar de
caracteres: ao ler `<nome>`, empilhe o nome (numa pilha de strings
encadeada, como a do E495); ao ler `</nome>`, desempilhe e compare com
`strcmp`. No fim, a pilha precisa estar vazia.

</details>

**3. Duas pilhas, uma fila e o custo.** Pegue a fila com duas pilhas do E525
e conte as chamadas de `pilha_empilha` numa variável global (troque as
chamadas por uma `conta_empilha` que soma 1 e empilha). Faça 1000 inserções
seguidas e depois 1000 retiradas; zere o contador e faça 1000 vezes "insere
um, retira um". Imprima o contador e a soma dos itens retirados nos dois
casos.

<details><summary>Resposta</summary>

```
1000 insercoes e depois 1000 retiradas: 2000 empilhas (soma 500500)
alternando 1000 vezes: 2000 empilhas (soma 500500)
```

Dica: a soma confere que saiu tudo, na ordem certa ou não (1 + ... + 1000).
Nos dois casos cada item é empilhado uma vez na entrada e uma vez na saída:
**custo amortizado**. Uma retirada pode custar O(n) (o despejo), mas a
média por operação é O(1).

</details>

**4. Fila circular que cresce.** Mude o `fila.c` do 0085 para começar com 4
gavetas alocadas com `malloc` e dobrar com `realloc` quando encher, sem mudar
o `fila.h`. Teste inserindo 1 a 10 depois de ter retirado dois itens (para a
fila já ter dado a volta).

<details><summary>Resposta</summary>

A pegadinha: depois do `realloc`, os itens que deram a volta ficam no lugar
errado. Com capacidade 4, início 2 e itens nas gavetas 2, 3, 0, 1, dobrar
para 8 deixa as gavetas 4 a 7 vazias **no meio** da fila. A saída mais simples
é copiar os `n` itens, na ordem da fila, para um vetor novo a partir da
gaveta 0 e zerar o `inicio`. A ordem de saída tem que continuar 3 4 5 ... 10.

</details>

**5. O caixa com dois atendentes.** Refaça o A172 com dois caixas e uma fila
única (como no banco). Com os mesmos clientes (chegadas 0, 1, 2, 5, 6 e
durações 3, 2, 4, 1, 2), qual é a espera média?

<details><summary>Resposta</summary>

**0,2 minuto** (contra 2,6 com um caixa). O cliente 1 vai para o caixa A (0
a 3) e o 2 para o B (1 a 3). O 3 chega no minuto 2 com os dois ocupados e
espera 1 minuto. O 4 e o 5 encontram um caixa livre. Esperas: 0, 0, 1, 0, 0.
Simule minuto a minuto, com um contador de "minutos restantes" por caixa.

</details>

**6. Pós-fixa para infixa.** Escreva o caminho inverso: receba `5 1 2 + 4 *
+ 3 -` e mostre `((5 + ((1 + 2) * 4)) - 3)`, com todos os parênteses.

<details><summary>Resposta</summary>

Use uma pilha de **strings** (vetores de char num nó encadeado, ou um vetor
de `char[64]`). Número: empilha o texto. Operador: desempilha b e a e empilha
`"(" a " op " b ")"`, montado com `snprintf`. O resultado da expressão vale
14.

</details>

**7. Deque de entrada restrita.** Um deque que só aceita inserção no fim,
mas deixa retirar das duas pontas. Os números 1, 2, 3 e 4 chegam nessa ordem,
e você pode retirar (de qualquer ponta) quando quiser. Escreva
`bool possivel(const int *alvo, int n)`, que testa recursivamente todas as
escolhas (inserir o próximo, tirar do início, tirar do fim) e diz se dá para
obter a saída `alvo`. Teste com 4 1 3 2 e 4 2 1 3 e depois passe pelas 24
ordens de 1 a 4, imprimindo as impossíveis e quantas são.

<details><summary>Resposta</summary>

```
4 1 3 2: possivel
4 2 1 3: impossivel
impossivel: 4 2 1 3
impossivel: 4 2 3 1
2 de 24 ordens sao impossiveis
```

Dica: guarde o deque num vetor com `ini` e `fim` e a função recursiva recebe
o próximo número a chegar e quantos já saíram; só tire de uma ponta se o
número dela for o próximo esperado, e desfaça a mudança ao voltar da
recursão. As 24 ordens saem de quatro `for` aninhados que pulam valores
repetidos. Em 4 2 1 3, para o 4 sair primeiro o deque precisa estar
1 2 3 4, e aí o 2 está no meio.

</details>

**8. Palíndromo de números.** Sem converter para string, use uma fila e uma
pilha para dizer se o número 1234321 é palíndromo. E 123321? E 120?

<details><summary>Resposta</summary>

Sim, sim e não. Tire os dígitos com `% 10` e `/ 10`, colocando cada um na
fila e na pilha. A fila devolve os dígitos do último para o primeiro (porque
o `% 10` começa pelas unidades) e a pilha devolve na ordem original; se as
duas sequências baterem, é palíndromo. 120 dá 0 2 1 contra 1 2 0.

</details>

**9. A fila do restaurante com desistência.** Numa fila encadeada, um cliente
de número x desiste e vai embora do meio da fila. Escreva
`bool fila_desiste(Fila *f, int x)` usando só o `fila.h`, sem acessar os nós.
Qual é o custo?

<details><summary>Resposta</summary>

Gire a fila uma volta completa: retire cada item e insira de novo no fim,
exceto o x, que é descartado. A ordem dos outros se mantém e o custo é
**O(n)**. Com acesso aos nós seria O(n) também (precisa achar o x), mas sem
o malloc e o free de cada volta. A fila não foi feita para remover do meio.

</details>

**10. Avaliar com variáveis.** Estenda o A175 para aceitar letras como
variáveis, com os valores num vetor `int val[26]`: com A = 3, B = 4 e C = 5,
calcule `A + B * C` e `(A + B) * C`.

<details><summary>Resposta</summary>

**23** e **35**. Na conversão, letra é tratada como número (vai direto para
a fila), mas guardada com outro código, por exemplo `1000 + (letra - 'A')`.
Na avaliação, um código `>= 1000` empilha `val[codigo - 1000]`. As
pós-fixas ficam `A B C * +` e `A B + C *`.

</details>

## Questões no estilo da prova

Questões objetivas no formato da prova do mestrado do PPGI/UFAM. Resolva no
papel, desenhando a pilha ou a fila a cada operação, e só depois abra o
gabarito. As simulações e os trechos de código foram conferidos rodando
programas em C (`gcc -std=c17 -Wall`, com AddressSanitizer). Nos trechos, o nó
é `typedef struct no { int valor; struct no *prox; } No;`. Atenção a "sempre",
"com certeza" e "nunca".

**Questão 1.** Uma pilha de inteiros começa vazia. Qual é a sequência de
valores devolvidos pelas operações `desempilha`, na ordem em que elas
ocorrem?

```text
empilha(5)  empilha(2)  desempilha  empilha(7)  empilha(1)  desempilha
desempilha  empilha(9)  desempilha  empilha(3)  desempilha
```

- (A) 2 1 7 9 3
- (B) 2 7 1 9 3
- (C) 5 2 7 9 3
- (D) 2 1 7 3 9
- (E) 5 2 7 1 9

<details><summary>Gabarito</summary>

**(A)**. Acompanhando o topo: `[5]`, `[5 2]`, sai 2, `[5 7]`, `[5 7 1]`, sai
1, sai 7, `[5 9]`, sai 9, `[5 3]`, sai 3. Saídas: 2 1 7 9 3, e o 5 fica no
fundo. A (C) e a (E) são o raciocínio de fila (sai o mais antigo). Veja 0082.

</details>

**Questão 2.** Uma fila de inteiros começa vazia. As operações são
`enfileira(x)` e `desenfileira`. Depois da sequência abaixo, a fila, do
início para o fim, contém:

```text
enfileira(4)  enfileira(8)  desenfileira  enfileira(6)  desenfileira
enfileira(2)  enfileira(9)  desenfileira  enfileira(5)
```

- (A) 5 9 2
- (B) 9 2 5
- (C) 6 2 9 5
- (D) 2 9 5
- (E) 8 6 2 9 5

<details><summary>Gabarito</summary>

**(D)**. Os três `desenfileira` tiram, nessa ordem, o 4, o 8 e o 6 (sempre o
que está há mais tempo). Sobram, na ordem de chegada, 2, 9 e 5. A (A) é a
fila lida ao contrário (visão de pilha). Veja 0085.

</details>

**Questão 3.** Uma fila circular em vetor de capacidade `C = 6` guarda
`inicio` (posição do próximo a sair) e `n` (quantos itens há). Enfileirar
grava em `(inicio + n) % C` e depois faz `n++`; desenfileirar faz
`inicio = (inicio + 1) % C` e `n--`. Partindo da fila vazia com
`inicio = 0`, ocorrem 5 enfileiramentos, 3 desenfileiramentos, 3
enfileiramentos e 2 desenfileiramentos, nessa ordem. Qual é o valor de
`inicio` agora e em que posição do vetor entra o próximo item?

- (A) `inicio` = 5, próximo item na posição 8.
- (B) `inicio` = 5, próximo item na posição 2.
- (C) `inicio` = 3, próximo item na posição 2.
- (D) `inicio` = 2, próximo item na posição 5.
- (E) `inicio` = 0, próximo item na posição 3.

<details><summary>Gabarito</summary>

**(B)**. Estados `(inicio, n)`: depois dos 5 primeiros, `(0, 5)`; depois dos
3 desenfileiramentos, `(3, 2)`; depois dos 3 enfileiramentos, `(3, 5)`
(o último ocupou a posição `(3 + 4) % 6 = 1`, dando a volta); depois de
2 desenfileiramentos, `(5, 3)`. O próximo item vai para
`(5 + 3) % 6 = 2`. A (A) esqueceu o `% C`: a posição 8 nem existe. Veja
0085.

</details>

**Questão 4.** Considere as afirmações sobre pilhas e filas:

I. Numa pilha, o próximo elemento a ser removido é sempre o último que foi
inserido e ainda não foi removido.
II. Numa fila, o próximo elemento a ser removido é o último que foi inserido.
III. Se os valores 1, 2 e 3 entram, nessa ordem, numa pilha (com remoções
intercaladas permitidas), a saída 3 1 2 é possível.
IV. Se os valores 1, 2 e 3 entram, nessa ordem, numa fila, eles só podem sair
na ordem 1, 2, 3.

- (A) Apenas I.
- (B) Apenas II e III.
- (C) Apenas I, III e IV.
- (D) Apenas II e IV.
- (E) Apenas I e IV.

<details><summary>Gabarito</summary>

**(E)**. I é a definição de pilha (LIFO). II é falsa: na fila sai o primeiro
que entrou (FIFO). III é falsa: para o 3 sair primeiro, o 1 e o 2 já estão
empilhados, com o 2 acima do 1, então o 2 sai antes do 1: as saídas
possíveis com a entrada 1 2 3 são 123, 132, 213, 231 e 321, e a 312 não está
entre elas. IV é verdadeira: a fila nunca troca a ordem. Veja 0082 e 0085.

</details>

**Questão 5.** Considere as afirmações sobre aplicações de pilhas e filas:

I. A chamada de funções recursivas usa, na memória, uma pilha.
II. Para verificar se os parênteses de uma expressão estão balanceados, a
pilha pode chegar a ter um tamanho proporcional ao da expressão (por exemplo,
com `((((`).
III. O "desfazer" (Ctrl+Z) de um editor é uma aplicação típica de fila.
IV. Uma expressão pós-fixa nunca precisa de pilha para ser avaliada.

- (A) Apenas I.
- (B) Apenas II e III.
- (C) Apenas I e II.
- (D) Apenas III e IV.
- (E) Todas estão corretas.

<details><summary>Gabarito</summary>

**(C)**. I é verdadeira: cada chamada empilha seu registro, e a volta
desempilha. II é verdadeira: cada `(` espera na pilha o seu `)`. III é falsa:
o "desfazer" desfaz primeiro a **última** ação, que é o comportamento de pilha.
IV é falsa ("nunca"): os operandos esperam numa pilha até chegar o operador.
Veja 0082 e 0084.

</details>

**Questão 6.** Considere as afirmações sobre implementações:

I. Numa pilha em vetor com `n` itens e espaço livre, empilhar custa O(1).
II. Numa fila encadeada com ponteiros `inicio` e `fim`, enfileirar e
desenfileirar custam O(1).
III. Numa fila circular em vetor de capacidade `C`, com `inicio` e `n`, a
próxima posição livre é `(inicio + n) % C`.
IV. Num deque feito com lista simplesmente encadeada com `inicio` e `fim`,
remover do fim custa O(1).

- (A) Apenas I e II.
- (B) Apenas I, II e III.
- (C) Apenas II, III e IV.
- (D) Apenas I e IV.
- (E) Todas estão corretas.

<details><summary>Gabarito</summary>

**(B)**. I, II e III são verdadeiras. IV é falsa: remover o último nó de uma
lista simples exige mudar o `prox` do penúltimo, e achar o penúltimo custa
O(n). Por isso o deque encadeado usa lista **dupla**. Veja 0083, 0086 e
0087.

</details>

**Questão 7.** A pilha encadeada tem os valores 7 (topo), 5 e 2. Qual
afirmação sobre o trecho é **correta**?

```c
int desempilha(No *topo) {
    int v = topo->valor;
    No *aux = topo;
    topo = topo->prox;
    free(aux);
    return v;
}

/* no main, com topo apontando para o nó do 7: */
int x = desempilha(topo);
int y = desempilha(topo);
```

- (A) `x` vale 7 e `y` vale 5.
- (B) `x` e `y` valem 7, porque a pilha não é alterada.
- (C) O código não compila: `topo` é reatribuído dentro da função.
- (D) `x` vale 7, mas o `topo` do `main` continua no nó liberado, e a segunda chamada lê memória já devolvida.
- (E) `x` vale 7 e `y` vale 5, mas o nó do 5 é perdido na memória.

<details><summary>Gabarito</summary>

**(D)**. `topo` é recebido **por valor**: `topo = topo->prox` muda só a
cópia local. O `main` continua apontando para o nó do 7, que já passou pelo
`free`. A segunda chamada lê `topo->valor` de memória liberada (o
AddressSanitizer acusa `heap-use-after-free`), e o `y` é lixo. Para a função mexer no `topo` do chamador, ela recebe
`No **topo`. Veja 0083 e 0049.

</details>

**Questão 8.** Na fila encadeada abaixo, `insere` pendura o nó novo atrás de
`fim`, ou o torna `inicio` quando `fim` é `NULL`. Depois de `insere(1)`,
`insere(2)`, `retira`, `retira` e `insere(3)`, o que acontece?

```c
int retira(Fila *f, int *v) {
    if (f->inicio == NULL) return 0;
    No *velho = f->inicio;
    *v = velho->valor;
    f->inicio = velho->prox;
    free(velho);
    return 1;
}
```

- (A) A fila fica com um único nó, o 3, como esperado.
- (B) A fila fica com os nós 2 e 3.
- (C) O programa não compila, porque `retira` não atualiza `fim`.
- (D) A fila fica com o 3, mas o segundo `retira` devolve 0.
- (E) `insere(3)` escreve em um nó já liberado (via `f->fim`), e `inicio` continua `NULL`: o 3 se perde.

<details><summary>Gabarito</summary>

**(E)**. Quando o segundo `retira` esvazia a fila, `inicio` vira `NULL`, mas
`fim` continua apontando para o nó do 2, que acabou de ser liberado. Em
`insere(3)`, `fim` não é `NULL`, então o código faz
`f->fim->prox = novo`, escrevendo num bloco liberado, e `inicio` nunca é
atualizado: o 3 fica solto. O AddressSanitizer reporta `heap-use-after-free`
na escrita. A correção é, em `retira`, fazer `if (f->inicio == NULL)
f->fim = NULL;` antes do `free`. Veja 0086.

</details>

**Questão 9.** A expressão pós-fixa `20 4 2 + 3 * -` é avaliada com uma
pilha: números são empilhados, e cada operador desempilha dois operandos
(primeiro o `b`, depois o `a`), calcula `a op b` e empilha o resultado.
Qual o valor final?

- (A) 2
- (B) -2
- (C) 18
- (D) 6
- (E) 26

<details><summary>Gabarito</summary>

**(A)**. Pilha: `[20 4 2]`; o `+` dá `4 + 2 = 6`, `[20 6]`; empilha 3,
`[20 6 3]`; o `*` dá `6 * 3 = 18`, `[20 18]`; o `-` calcula `a - b` com
`a = 20` e `b = 18`, resultado 2. A (B) troca a ordem dos operandos
(`18 - 20`), erro comum em operador não comutativo. Em infixa, é
`20 - (4 + 2) * 3`. A pilha chega a 3 itens. Veja 0084.

</details>

**Questão 10.** Marque a alternativa **INCORRETA**.

- (A) Desempilhar de uma pilha vazia deve ser tratado como erro (*underflow*), e não pode devolver um valor qualquer.
- (B) Na fila circular em vetor, guardar `inicio` e `n` evita confundir fila cheia com fila vazia.
- (C) Numa pilha encadeada em que o topo é o primeiro nó da lista, empilhar custa O(n), pois é preciso achar o último nó.
- (D) Um deque permite inserir e remover nas duas extremidades.
- (E) Uma recursão profunda demais pode estourar a pilha de chamadas.

<details><summary>Gabarito</summary>

**(C)**. Com o topo no primeiro nó, empilhar é criar o nó, apontar o `prox`
dele para o topo antigo e mover o topo: O(1), sem percorrer nada. A (A), a
(B) e a (D) são definições, e a (E) é o estouro de pilha (*stack overflow*) da
recursão sem parada ou funda demais. Veja 0083 e 0087.

</details>

## Para ler mais

- CORMEN, T. H.; LEISERSON, C. E.; RIVEST, R. L.; STEIN, C. *Algoritmos: teoria e prática*. 4. ed. Rio de Janeiro: GEN LTC, 2024. Cap. 10: estruturas de dados elementares (pilhas e filas).
- ZIVIANI, N. *Projeto de algoritmos: com implementações em Pascal e C*. 3. ed. São Paulo: Cengage Learning, 2010. Cap. 3: estruturas de dados básicas (pilhas e filas).
- CELES, W.; CERQUEIRA, R.; RANGEL, J. L. *Introdução a estruturas de dados: com técnicas de programação em C*. 2. ed. Rio de Janeiro: Elsevier, 2016.
- CELES, W.; RANGEL, J. L. *Apostila de estruturas de dados*. Rio de Janeiro: PUC-Rio, Departamento de Informática, 2002. Pilhas e filas.
- FEOFILOFF, P. *Algoritmos em linguagem C*. Rio de Janeiro: Elsevier, 2009. Capítulos de pilhas e filas. Disponível em: <https://www.ime.usp.br/~pf/algoritmos/>.
- TENENBAUM, A. M.; LANGSAM, Y.; AUGENSTEIN, M. J. *Estruturas de dados usando C*. São Paulo: Makron Books, 1995. Cap. 2 (pilha) e cap. 4 (filas e listas).
- LAUREANO, M. *Estrutura de dados com algoritmos e C*. Rio de Janeiro: Brasport, 2008. Caps. 3 (pilha) e 4 (fila).
- ROCHA, A. M. A.; BORGES, A. R. O. S. *Programação, estruturas de dados e algoritmos em C*. Aveiro: Universidade de Aveiro, Departamento de Eletrônica e Telecomunicações. Cap. 7: filas e pilhas.
- DEITEL, P.; DEITEL, H. *C: como programar*. 6. ed. São Paulo: Pearson Prentice Hall, 2011. Cap. 12: estruturas de dados.
- KERNIGHAN, B. W.; RITCHIE, D. M. *The C programming language*. 2. ed. Englewood Cliffs: Prentice Hall, 1988. Seção 4.3: a calculadora polonesa reversa.
- DIJKSTRA, E. W. *Algol 60 translation*: an Algol 60 translator for the X1. Amsterdam: Mathematisch Centrum, 1961. (Report MR 35). A origem do algoritmo do pátio de manobras.
- CPPREFERENCE. *Arithmetic operators*: divisão inteira e resto. Disponível em: <https://en.cppreference.com/w/c/language/operator_arithmetic>.
