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

Num exercício, então, **não** crie funções com os nomes do TAD
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

Questões objetivas no formato da prova do mestrado. Desenhe a pilha ou a fila
a cada operação antes de escolher a alternativa.

**1.** Numa pilha inicialmente vazia são feitas, nesta ordem: PUSH(4),
PUSH(7), POP, PUSH(2), PUSH(9), POP, POP, PUSH(5). Quais valores saem, na
ordem, e qual fica no topo?

- (A) saem 4, 2, 9; topo 5
- (B) saem 7, 9, 2; topo 5
- (C) saem 7, 2, 9; topo 5
- (D) saem 7, 9, 2; topo 4
- (E) saem 4, 7, 2; topo 9

<details><summary>Gabarito</summary>

**B.** O primeiro POP tira o 7. Depois a pilha é `4 2 9` (topo à direita): sai
o 9 e depois o 2. Entra o 5 sobre o 4, e a pilha termina `4 5`. Veja 0082.

</details>

**2.** Os números 1, 2, 3, 4, 5 são empilhados **nesta ordem**, mas
desempilhamentos podem acontecer a qualquer momento entre um empilhamento e
outro. Cada número desempilhado é impresso. Qual sequência **não** pode ser
impressa?

- (A) `1 2 3 4 5`
- (B) `3 2 1 5 4`
- (C) `2 4 3 5 1`
- (D) `4 3 5 1 2`
- (E) `5 4 3 2 1`

<details><summary>Gabarito</summary>

**D.** Para sair o 4 primeiro, entram 1, 2, 3, 4; saem 4 e 3; entra e sai o 5.
Sobram 1 e 2 na pilha, com o **2 no topo**: o 1 não pode sair antes dele. As
outras são possíveis (a (A) desempilha logo depois de cada empilhamento). Veja
0082.

</details>

**3.** Uma fila circular usa um vetor de 8 posições (0 a 7) com os índices
`head` (o primeiro da fila) e `tail` (a próxima vaga), como no Cormen: fila
vazia é `head == tail` e, para cheia e vazia não se confundirem, uma posição
fica sempre livre. Começando com `head = tail = 0`, são feitos 6 ENQUEUE, 4
DEQUEUE e mais 5 ENQUEUE. Qual é o estado final?

- (A) `head = 4`, `tail = 11`, com 7 elementos
- (B) `head = 4`, `tail = 3`, com 6 elementos
- (C) `head = 0`, `tail = 7`, com 7 elementos
- (D) `head = 4`, `tail = 2`, e o último ENQUEUE dá *overflow*
- (E) `head = 4`, `tail = 3`, com 7 elementos, e a fila está cheia

<details><summary>Gabarito</summary>

**E.** Depois dos 6 ENQUEUE, `tail = 6`; os 4 DEQUEUE levam `head` a 4. Os 5
ENQUEUE usam as posições 6, 7, 0, 1 e 2, e `tail` dá a volta até
`(6 + 5) % 8 = 3`. São 7 elementos, o máximo dessa convenção:
`(tail + 1) % 8 == head`. O Cormen indexa o vetor de 1 a n, mas a conta é a
mesma. Veja 0085 (o aviso sobre sacrificar uma gaveta).

</details>

**4.** Qual é o valor da expressão pós-fixa `8 2 5 * + 1 3 2 * + 4 - /`?

- (A) 6
- (B) 18
- (C) 2
- (D) 3
- (E) 9

<details><summary>Gabarito</summary>

**A.** Com a pilha: `2 5 *` dá 10, `8 10 +` dá 18; depois `3 2 *` dá 6,
`1 6 +` dá 7, `7 4 -` dá 3; por fim `18 3 /` dá 6. Na infixa:
`(8 + 2 * 5) / (1 + 3 * 2 - 4)`. Veja 0084.

</details>

**5.** Convertendo a expressão infixa `A * (B + C) - D / E` para a notação
pós-fixa, o resultado é:

- (A) `A B * C + D E / -`
- (B) `A B C + D E / * -`
- (C) `A B C + * D E / -`
- (D) `* A + B C - / D E`
- (E) `A B C * + D E - /`

<details><summary>Gabarito</summary>

**C.** O parêntese obriga `B + C` antes do `*`: `A B C + *`. Depois, `D / E`
vira `D E /`, e o `-` de menor precedência fica por último. A (D) é a forma
prefixa (com a ordem errada). Veja 0084 e 0088.

</details>

**6.** Num deque inicialmente vazio são feitas: `insere_fim(1)`,
`insere_fim(2)`, `insere_inicio(3)`, `insere_inicio(4)`, `retira_fim()`,
`insere_fim(5)`, `retira_inicio()`. Qual é o conteúdo final, do início para o
fim?

- (A) `4 3 1`
- (B) `3 1 5`
- (C) `1 2 5`
- (D) `3 1 2 5`
- (E) `5 1 3`

<details><summary>Gabarito</summary>

**B.** Depois das quatro inserções: `4 3 1 2`. Sai o 2 (fim), entra o 5 no
fim (`4 3 1 5`) e sai o 4 (início). Veja 0087.

</details>

**7.** Uma fila é implementada com duas pilhas, E e S. ENQUEUE empilha em E.
DEQUEUE, se S estiver vazia, desempilha **todos** os itens de E empilhando-os
em S, e então desempilha de S. Sobre o custo, é correto afirmar:

- (A) todo DEQUEUE custa O(1) no pior caso.
- (B) todo DEQUEUE custa Θ(n).
- (C) todo ENQUEUE custa Θ(n).
- (D) uma sequência de n operações pode custar Θ(n²).
- (E) um DEQUEUE isolado pode custar Θ(n), mas n operações custam O(n) no total: O(1) amortizado.

<details><summary>Gabarito</summary>

**E.** Cada item é empilhado e desempilhado no máximo duas vezes (uma em E e
uma em S), então o total de n operações é O(n), embora o DEQUEUE que faz o
despejo custe proporcional ao que estava em E. Veja o exercício E525 (0088) e o
custo amortizado do 0075.

</details>

**8.** Qual implementação de **fila de prioridade** com n elementos faz
inserção e remoção do máximo em O(log n) **no pior caso**?

- (A) heap binário
- (B) vetor ordenado
- (C) lista encadeada não ordenada
- (D) fila circular em vetor
- (E) árvore binária de busca sem balanceamento

<details><summary>Gabarito</summary>

**A.** O heap sobe ou desce por um único caminho de altura ⌊log₂ n⌋. No vetor
ordenado, inserir custa O(n); na lista não ordenada, achar o máximo custa
O(n); a fila circular é FIFO, não por prioridade; a BST degenera em O(n). Veja
0102.

</details>

**9.** O que o trecho imprime?

```c
int p[10], topo = -1;
for (int i = 1; i <= 5; i++) {
    p[++topo] = i * i;
    if (i % 2 == 0) {
        topo--;
    }
}
printf("%d %d\n", topo, p[topo]);
```

- (A) `4 25`
- (B) `2 16`
- (C) `2 25`
- (D) `1 9`
- (E) `3 25`

<details><summary>Gabarito</summary>

**C.** Aqui `topo` é o índice do topo (pilha vazia é `-1`). Os pares
empilham e logo desempilham: o 4 sai, o 16 sai. Ficam 1, 9 e 25 nas posições
0, 1 e 2, com `topo = 2`. O 16 foi escrito em `p[2]` e depois o 25 escreveu
por cima. Veja 0082 (as duas convenções de topo).

</details>

**10.** O que o programa imprime?

```c
#include <stdio.h>
#define N 5

int q[N], ini = 0, fim = 0;

void enfileira(int x) {
    if ((fim + 1) % N == ini) {
        printf("cheia ");
        return;
    }
    q[fim] = x;
    fim = (fim + 1) % N;
}

int desenfileira(void) {
    int x = q[ini];
    ini = (ini + 1) % N;
    return x;
}

int main(void) {
    for (int i = 1; i <= 5; i++) {
        enfileira(i * 10);
    }
    desenfileira();
    desenfileira();
    enfileira(60);
    enfileira(70);
    enfileira(80);
    printf("%d %d\n", ini, fim);
    return 0;
}
```

- (A) `2 1`
- (B) `cheia 2 0`
- (C) `cheia 0 2`
- (D) `cheia cheia 2 1`
- (E) `cheia cheia 1 2`

<details><summary>Gabarito</summary>

**D.** Com uma posição sacrificada, cabem 4 em 5: o 50 é recusado. Saem 10 e
20 (`ini = 2`). O 60 vai para `q[4]` e `fim` dá a volta para 0; o 70 vai para
`q[0]` e `fim = 1`. O 80 encontra `(1 + 1) % 5 == 2 == ini`: cheia de novo.
Veja 0085.

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
