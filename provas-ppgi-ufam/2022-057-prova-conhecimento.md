# PPGI/UFAM - Edital 057/2022 PROPESP/UFAM - Prova de Conhecimento

Fontes: `2022-057.pdf` (caderno com a resposta oficial marcada em negrito em cada questão, mais o cartão de respostas de 27/01/2023). Sem questões anuladas e sem figuras.

## Gabarito

| Questão | Resp. | Questão | Resp. |
|---|---|---|---|
| 01 | D | 11 | D |
| 02 | C | 12 | D |
| 03 | B | 13 | A |
| 04 | C | 14 | A |
| 05 | B | 15 | A |
| 06 | D | 16 | C |
| 07 | D | 17 | B |
| 08 | D | 18 | A |
| 09 | B | 19 | B |
| 10 | A | 20 | B |

## Questões

### QUESTÃO 01
Indique qual é a saída correta do seguinte programa em python:

```python
class Vector():
   def __init__(self, row: list()):
       self.row = row

   def dot_product(self, column):
       return sum(self.row[i] * column.row[i] for i in range(len(self.row)))

vec_1 = Vector([0,2,0,0,5])
vec_2 = Vector([1,0,3,4,0])
print(vec_1.dot_product(vec_2))
```

a) 15
b) [0, 0, 0, 0, 0]
c) [1, 2, 3, 4, 5]
d) 0

### QUESTÃO 02
Sobre as características das árvores de pesquisa binária, considere as afirmações:

1. TODOS os nós da subárvore à esquerda são menores que o pai
2. O nó mais à esquerda é o menor de TODOS os nós, enquanto que o nó mais à direita é o maior de TODOS
3. O sucessor de um nó x é o nó com a menor chave maior que a chave de x, e este sucessor estará SEMPRE em um nível (altura) acima de x, ou seja, mais próximo da raiz.

Quais são verdadeiras?

a) Apenas as afirmações 2 e 3
b) Todas as afirmações
c) Apenas as afirmações 1 e 2
d) Apenas a afirmação 1

### QUESTÃO 03
Sobre ordenação, considere as afirmações:

1. O Quicksort é um dos algoritmos mais conhecidos, pois possui complexidade, no pior caso, de O(n log n)
2. O Quicksort e Mergesort usam a técnica de divisão e conquista
3. O Mergesort possui complexidade assintótica Θ(n log n) no caso médio.
4. Caso a lista já esteja ordenada, o Selectionsort têm complexidade de O(n).

Tais afirmações são, respectivamente:

a) Verdadeira, verdadeira, verdadeira, verdadeira
b) Falsa, verdadeira, verdadeira, falsa
c) Verdadeira, falsa, falsa, verdadeira
d) Falsa, falsa, falsa, falsa

### QUESTÃO 04
Os seguintes itens são inseridos em uma árvore binária de busca: 8, 3, 4, 9, 5, 6, 2, 1, 7. Qual item é colocado na raiz?

a) 1
b) 4
c) 8
d) 9

### QUESTÃO 05
Para a implementação eficiente (O(1)) de uma pilha usando lista simplesmente encadeada, onde os push's e pop's são executados?

a) Push depois do último elemento, pop no último elemento
b) Push antes do primeiro elemento, pop no primeiro elemento
c) Push antes do primeiro elemento, pop no último elemento
d) Push depois do último elemento, pop no primeiro elemento

### QUESTÃO 06
Indique qual é a saída correta do seguinte programa escrito em python:

```python
class Vector():
   def __init__(self, row: list()):
       self.row = row

   def dot_product(self, column):
       return sum(self.row[i] * column.row[i] for i in range(len(self.row)))

vec_1 = Vector([1,2,3,4,5])
vec_2 = vec_1
vec_2.row[2] = 15
print(vec_1.row)
```

a) [ 2 15 4 5]
b) [ 0 1 2 15 4 5]
c) [ 1 2 15 4 15]
d) [ 1 2 15 4 5]

### QUESTÃO 07
Considere as funções f(n)=(n+1)(n−1) e g(n)=8log2(n)+1, sendo n>0. Podemos afirmar que:

a) f(n) é exponencial e g(n) é exponencial
b) f(n) é quadrática e g(n) é linear
c) g(n)=Ω(f(n))
d) g(n)=O(f(n))

### QUESTÃO 08
Indique qual é a saída correta do seguinte programa escrito em python:

```python
def fibonacci(n):
   if n==1:
        return 0
   elif n==2:
        return 1
   else:
        return fibonacci(n-1) + fibonacci(n-2)


n = 7
print(fibonacci(n))
```

a) 13
b) 5
c) 0
d) 8

### QUESTÃO 09
Um grafo é uma árvore se e somente se:

a) É planar
b) É conexo, não direcionado e não contém ciclos
c) É completamente conectado
d) Todo grafo é uma árvore

### QUESTÃO 10
Matrizes são estruturas de dados de n-dimensões que podem ser implementadas utilizando arrays (vetores). Por simplicidade, chamaremos de matrizes as matrizes bidimensionais numéricas (que armazenam números inteiros). Sendo assim, marque a alternativa INCORRETA.

a) O produto de duas matrizes, a primeira com ‘m’ linhas e ‘n’ colunas e a segunda com ‘x’ linhas e ‘y’ colunas, resulta em uma matriz de ‘n’ linhas e ‘y’ colunas.
b) Uma das formas triviais de implementar a soma dos elementos de uma matriz pode ser realizada através de dois laços aninhados (um sobre as linhas e o outro sobre as colunas) e um acumulador de valores.
c) Uma matriz também pode ser representada utilizando listas encadeadas (utilizando referências ou ponteiros).
d) Uma matriz de ‘m’ linhas e ‘n’ colunas contêm ‘m*n’ espaços para alocação de números inteiros.

### QUESTÃO 11
Considere o pseudo algoritmo abaixo:

```c
void Inserir(int vetor[], int N, int novo) {
   /* tamanho do vetor N+1*/
   i = 1;
   j = N; /* ocupação do vetor */
   while (i <= j){
     meio = (int) floor((i+j)/2); /* função piso, exemplo: (int) floor(2.6) retorna 2 */
     if (vetor[meio] > novo) { j = meio-1; }
     else { i = meio + 1; }
   }
   vetor[N+1] = novo;
   for (k=N+1; k == i; k--) {
     trocar(vetor,k,k-1); /* Função que inverte a ordem dos elementos da posição k, k-1 */
   }
}
```

Considere as afirmações:

1. Realiza a inserção do novo elemento com menos comparações que o algoritmo da ordenação por inserção.
2. Realiza a inserção com o mesmo número de comparações que o algoritmo da ordenação por inserção.
3. Realiza a inserção do novo elemento com o mesmo número de movimentações que o algoritmo da ordenação por inserção.

Sobre as afirmações anteriores, é correto dizer que:

a) Somente a 1 é correta
b) 2 e 3 são corretas
c) Somente a 3 é correta
d) 1 e 3 são corretas

### QUESTÃO 12
Qual das opções melhor representa o limite superior assintótico do tempo de execução do algoritmo Quick Sort no pior caso?

a) O(n)
b) O(n log n)
c) O(n!)
d) O(n^2)

### QUESTÃO 13
O que faz o código C abaixo?

```c
#include <stdio.h>
#define MAX 50

int main() {
    int m, soma=0;
    int mat[MAX][MAX];
    scanf("%d", &m);
    for (int i=0; i<m; i++)
        for (int j=0; j<m; j++)
             scanf("%d", &mat[i][j]);
    for (int i=0; i<m; i++)
        for (int j=i; j<m; j++)
             soma += mat[i][j];
    printf("%d\n", soma);
}
```

a) Calcula e imprime a soma dos elementos iguais ou acima da diagonal principal da matriz.
b) Calcula e imprime a soma dos elementos da matriz.
c) Imprime somente o último valor da matriz, ou seja, mat[m][m].
d) Calcula e imprime a soma dos elementos iguais ou abaixo da diagonal principal da matriz.

### QUESTÃO 14
Analise o seguinte programa em C e indique a saída correta:

```c
void func1 (int x) { x = 9 * x; }
void func2 (int v[]) { v[0] = 3 * v[0]; }
void main (void) {
  int x, v[2];
  x = 222;
  func1(x);
  printf("x: %d\n", x);
  v[0] = 333;
  func2(v);
  printf("v[0]: %d\n", v[0]);
}
```

a) x: 222 e v[0]: 999
b) x: 222 e v[0]: 222
c) x: 222 e v[0]: 666
d) x: 222 e v[0]: 333

### QUESTÃO 15
O que faz o seguinte código em C?

```c
Lista* abracadabra (Lista* l, int v) {
  Lista* novo = (Lista*) malloc(sizeof(Lista));
  novo->info = v;
  novo->prox = l;
  novo->ant = NULL;
  if (l) { l->ant = novo };
  return novo;
}
```

a) Insere inteiros em uma lista duplamente encadeada, onde tais elementos são sempre inseridos no início da lista.
b) Insere inteiros em uma lista duplamente encadeada, onde tais elementos são sempre inseridos no final da lista.
c) Insere inteiros em uma lista simplesmente encadeada, onde tais elementos são sempre inseridos no início da lista.
d) Insere inteiros em uma lista simplesmente encadeada, onde tais elementos são sempre inseridos no fim da lista.

### QUESTÃO 16
Considere uma tabela hash de comprimento m=9, que usa endereçamento aberto e a técnica de sondagem linear (linear probing) para resolver colisões. Considere também a função de dispersão h(k) = k mod m, onde k é a chave a ser inserida. Por fim, as seguintes chaves foram inseridas: 73, 24, 16, 46, 28 (nesta ordem). Escolha a opção que representa esta tabela após estas operações:

a) ø – 73 – 16 – ø – ø – 28 – 24 – 46 – ø
b) 28 – 46 – 73 – ø – ø – ø – ø – 24 – 16
c) ø – 73 – 46 – 28 – ø – ø – 24 – 16
d) 73 – 46 – ø – ø – ø – ø – 28 – 24 – 16

### QUESTÃO 17
Sobre árvores vermelho-preto, considere as afirmações:

1. A raiz é preta
2. Toda subárvore nula é preta,
3. Se um nó é vermelho, então os filhos são pretos.

Qual são verdadeiras:

a) Apenas as afirmações 2 e 3
b) Todas as afirmações
c) Apenas as afirmações 1 e 2
d) Apenas a afirmação 1

### QUESTÃO 18
Sobre os grafos, considere as afirmações:

1. O algoritmo de Dijkstra é conhecido por descobrir o menor caminho entre dois vértices, mas só funciona para casos pequenos ou médios, por possuir complexidade exponencial.
2. Na implementação da busca em largura, uma fila é normalmente utilizada.
3. Em grafos esparsos, a implementação por matriz de adjacências consome mais memória do que a implementação por lista de adjacências.

Quais são verdadeiras?

a) Apenas as afirmações 2 e 3
b) Apenas as afirmações 1 e 2
c) Apenas a afirmação 1
d) Nenhuma das afirmações

### QUESTÃO 19
Em uma árvore AVL, considerando que já possuímos a referência para um nó que queremos remover da árvore (não precisa fazer busca), o melhor e o pior caso para remover este elemento são, respectivamente:

a) O(log n), O(log n)
b) O(1), O(log n)
c) O(1), O(n)
d) O(log n), O(n)

### QUESTÃO 20
Considere as seguintes operações em uma lista implementada usando vetores: busca por um elemento, acesso por índice, inserção no início da lista, inserção no final da lista, remoção por índice. As complexidades do pior caso dessas operações, na ordem mencionada, são:

a) O(n), O(1), O(1), O(n), O(n)
b) O(n), O(1), O(n), O(1), O(n)
c) O(1), O(n), O(n), O(n), O(1)
d) O(n), O(n), O(1), O(n), O(1)
