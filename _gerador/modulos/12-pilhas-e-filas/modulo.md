# Módulo 12 · Pilhas e filas

A lista encadeada do módulo 11 deixa você inserir e remover em qualquer
lugar. Este módulo faz o contrário: **proíbe**. Uma pilha só mexe no topo;
uma fila só entra por um lado e sai pelo outro. Parece perda, mas é a
restrição que dá a garantia: o desfazer sempre desfaz o último passo, e quem
chegou primeiro sempre é atendido primeiro.

Você usa essas estruturas o dia inteiro sem ver. A pilha de chamadas do seu
programa, o Ctrl+Z, o botão Voltar e o *parser* de um compilador são pilhas. A
fila de processos do sistema operacional, a fila de jobs do seu backend e a
impressora do escritório são filas. Aqui você constrói as duas do zero, cada uma de dois
jeitos (vetor e lista encadeada), sempre como **TAD**: o mesmo `.h`, o
`.c` trocado por baixo, e o programa cliente nem percebe.

## O que você vai aprender

- o TAD **pilha** (LIFO) sobre vetor: empilhar, desempilhar, topo, *overflow* e *underflow*
- a **pilha encadeada**: por que o topo fica no começo da lista
- duas aplicações clássicas: **parênteses balanceados** e **notação pós-fixa**
- o TAD **fila** (FIFO) e a **fila circular** sobre vetor, com o `%` dando a volta
- a **fila encadeada** com ponteiros de início e fim, e os bugs das bordas
- o **deque**, que entra e sai pelas duas pontas, e a pegadinha do resto negativo
- uma calculadora que junta tudo: infixa → pós-fixa → resultado

## Como estudar cada assunto

1. Leia o texto e olhe o **diagrama da ideia**: é o exemplo desenhado, com a
   memória por dentro.
2. Leia o código. É o mesmo exemplo, com os mesmos valores.
3. Siga o **fluxograma** com o dedo: é o caminho de uma operação.
4. Rode os exemplos. Mude um valor, quebre de propósito, rode de novo.
5. Faça os exercícios. ★☆☆ é aquecimento, ★★☆ pede raciocínio, ★★★ é desafio.
   As dicas vêm logo abaixo do enunciado: tente antes de ler.

No meio de cada assunto tem uma **Pergunta para você**. Responda antes de rodar.

## As cores e as formas

Caixa azul é dado entrando ou saindo, roxa é o programa fazendo alguma coisa,
amarela é pergunta. Verde é o caminho que o exemplo segue (e, nos desenhos de
memória, o item que está saindo); cinza é o que ele não usa ou a gaveta que
já virou vaga.

<p align="center"><img src="../legenda.svg" alt="Legenda: formas e cores do fluxograma" width="916"></p>

## Antes de começar

Você precisa estar à vontade com ponteiros, `malloc`/`free`, `struct` com
`->` e listas encadeadas (módulos 06, 07, 08 e 11), além da ideia de TAD do
assunto 0074.

Cada pasta de assunto traz os arquivos do TAD ao lado dos exemplos:
`pilha.h` e `pilha.c`, `fila.h` e `fila.c` ou `deque.h` e `deque.c`. O
`rodar` compila esses `.c` de apoio junto com qualquer exemplo ou exercício
da pasta, então basta:

```bash
~/LPEDC/rodar 12-pilhas-e-filas/0082-pilha/A163.c
```

Por isso, num exercício, **não** crie funções com os nomes do TAD
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
pilha nessa ordem, e você pode desempilhar quando quiser. Quais destas saídas
são possíveis: (a) 3 2 1 5 4; (b) 4 5 3 1 2; (c) 1 2 3 4 5; (d) 5 4 3 2 1?

<details><summary>Resposta</summary>

(a), (c) e (d) são possíveis. (b) não: quando o 3 sai, o 1 e o 2 estão na
pilha com o 2 por cima, então o 2 tem que sair antes do 1. A regra geral:
uma saída é impossível se tiver o padrão "c ... a ... b" com a < b < c.
Simule com o `simula` do E491.

</details>

**2. Tags HTML balanceadas.** Escreva um verificador para tags simples, sem
atributos: `<p><b>oi</b></p>` está certo, `<p><b>oi</p></b>` não. Teste
também com `<ul><li>a</li><li>b</li></ul>`.

<details><summary>Resposta</summary>

Primeiro, segundo e terceiro: certo, errado, certo. É o verificador do 0084 com palavras
no lugar de caracteres: ao ler `<nome>`, empilhe o nome (numa pilha de strings
encadeada, como a do E495); ao ler `</nome>`, desempilhe e compare com
`strcmp`. No fim, a pilha precisa estar vazia.

</details>

**3. Duas pilhas, uma fila e o custo.** Na fila com duas pilhas do E525,
faça 1000 inserções seguidas e depois 1000 retiradas. Quantos `pilha_empilha`
acontecem no total? E se você alternar uma inserção e uma retirada?

<details><summary>Resposta</summary>

No primeiro caso, 2000: cada item é empilhado na entrada e depois uma vez na
saída (o despejo único acontece na primeira retirada). Alternando, também
2000: cada item ainda passa uma vez por cada pilha. É o **custo amortizado**:
uma retirada pode custar O(n), mas a média por operação é O(1).

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
e você pode retirar (de qualquer ponta) quando quiser. Dá para obter a saída
4 1 3 2? E 4 2 1 3?

<details><summary>Resposta</summary>

4 1 3 2 **sim**: insira os quatro, retire o 4 do fim, o 1 do início, o 3 do
fim e o 2. 4 2 1 3 **não**: para o 4 sair primeiro, o deque precisa estar
1 2 3 4; aí o 2 está no meio e não sai antes do 1 ou do 3. Das 24 ordens,
só 4 2 1 3 e 4 2 3 1 são impossíveis. Confirme com um programa que testa
todas as escolhas recursivamente.

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
o malloc e o free de cada volta. Remover do meio não é o forte da fila.

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

## Para ler mais

- CELES, W.; RANGEL, J. L. *Apostila de estruturas de dados*. Rio de Janeiro: PUC-Rio, Departamento de Informática, 2002. Pilhas e filas.
- FEOFILOFF, P. *Algoritmos em linguagem C*. Rio de Janeiro: Elsevier, 2009. Capítulos de pilhas e filas. Disponível em: <https://www.ime.usp.br/~pf/algoritmos/>.
- TENENBAUM, A. M.; LANGSAM, Y.; AUGENSTEIN, M. J. *Estruturas de dados usando C*. São Paulo: Makron Books, 1995. Cap. 2 (pilha) e cap. 4 (filas e listas).
- LAUREANO, M. *Estrutura de dados com algoritmos e C*. Rio de Janeiro: Brasport, 2008. Caps. 3 (pilha) e 4 (fila).
- ROCHA, A. M. A.; BORGES, A. R. O. S. *Programação, estruturas de dados e algoritmos em C*. Aveiro: Universidade de Aveiro, Departamento de Eletrônica e Telecomunicações. Cap. 7: filas e pilhas.
- DEITEL, P.; DEITEL, H. *C: como programar*. 6. ed. São Paulo: Pearson Prentice Hall, 2011. Cap. 12: estruturas de dados.
- KERNIGHAN, B. W.; RITCHIE, D. M. *The C programming language*. 2. ed. Englewood Cliffs: Prentice Hall, 1988. Seção 4.3: a calculadora polonesa reversa.
- DIJKSTRA, E. W. *Algol 60 translation*: an Algol 60 translator for the X1. Amsterdam: Mathematisch Centrum, 1961. (Report MR 35). A origem do algoritmo do pátio de manobras.
- CPPREFERENCE. *Arithmetic operators*: divisão inteira e resto. Disponível em: <https://en.cppreference.com/w/c/language/operator_arithmetic>.
