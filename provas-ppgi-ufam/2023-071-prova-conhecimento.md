# PPGI/UFAM - Edital 071/2023 PROPESP/UFAM - Prova de Conhecimento

Fontes: `2023-071.pdf` (caderno, 9 páginas) e `2023-071-gabarito.pdf` (Anexo V, gabarito definitivo do processo seletivo 2024/01).
Questões 01, 07 e 10 constam como anuladas no gabarito definitivo.

## Gabarito definitivo

| Questão | Resp. | Questão | Resp. |
|---|---|---|---|
| 01 | Anulada | 11 | D |
| 02 | A | 12 | B |
| 03 | B | 13 | C |
| 04 | C | 14 | D |
| 05 | B | 15 | B |
| 06 | B | 16 | A |
| 07 | Anulada | 17 | C |
| 08 | D | 18 | D |
| 09 | B | 19 | B |
| 10 | Anulada | 20 | B |

## Questões

### QUESTÃO 01
Considere o código abaixo cujo objetivo é ordenar um vetor de inteiros com n elementos de maneira crescente:

```c
void algoritmo(int v[], int n) {
  int i,j,k, tmp;

 for(i = 0; i < n-1; i++) {
  k = i;
    for(j = 0; j < n; j++) {
        if(v[k] > v[j]) {  k = j  }
    }
    tmp = v[k];
    v[k] = v[i];
    v[i] = tmp;
}
```

a) O código ordena o vetor por seleção de maneira crescente
b) O código não ordena o vetor por seleção e não pode ser modificado para ordenar por seleção de maneira crescente com correção em uma única linha de código.
c) O código pode ser alterado em uma única linha para ordenar o vetor de maneira crescente por seleção
d) O código ordena corretamente o vetor, mas não usa o algoritmo de seleção

### QUESTÃO 02
Sobre o heapsort, é correto afirmar que:

I) Seu custo no pior caso é O(n log n), onde n é o tamanho do vetor
II) O algoritmo pode ser dividido em duas etapas, sendo a primeira usada para construir um heap e a segunda para usar o heap como forma eficiente de executar uma estratégia de ordenação por seleção
III) Tem custo máximo quadrático no pior caso

a) Apenas I e II estão corretas
b) Apenas II e III estão corretas
c) Apenas I está correta
d) Apenas III está correta

### QUESTÃO 03
Em um heap binário de mínimo contendo N elementos e implementado em um vetor, sabendo-se que o elemento mínimo está na posição zero do vetor, a operação de remover o elemento da raiz (o da posição zero) e deixar a estrutura do heap correta ao final, com o restante das chaves formando um heap, pode ser implementada, na melhor maneira possível, a custo:

a) N log N no pior caso
b) Log N no pior caso, mesmo sabendo-se que o custo de mover todos os elementos de um vetor para o lado é N
c) N no pior caso, mesmo sabendo-se que o custo de mover todos os elementos de um vetor para o lado é N
d) A custo O(1) no pior caso, pois sabemos que o elemento está na posição zero

### QUESTÃO 04
Se um programador fez testes para avaliar o tempo de execução para entradas de tamanho 100 em um programa Θ(n³) e obteve tempo de 1 minuto, quanto tempo demoraria para uma entrada de tamanho 300? (Considere que 100 é suficientemente grande para desprezar fatores menores na função de custo, e que o custo unitário por operação não variou com o tamanho do problema entre os dois experimentos.)

a) 3 minutos
b) 9 minutos
c) 27 minutos
d) 300 minutos

### QUESTÃO 05
Sobre as afirmativas abaixo:

I) Todo algoritmo que não seja vazio tem custo Ω(1)
II) Todo algoritmo tem custo O(nⁿ)
III) Nenhum algoritmo que não seja vazio tem custo o(2) – "ó pequeno de 2"

a) Apenas I e II estão corretas
b) Apenas I e III estão corretas
c) Apenas II e III estão corretas
d) Todas estão corretas

### QUESTÃO 06
Considere o vetor abaixo, o qual é apresentado em uma tabela onde a primeira linha indica a posição dos elementos e a segunda linha os valores armazenados.

| 0 | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 |
|---|---|---|---|---|---|---|---|---|
| 2 | 4 | 6 | 8 | 10 | 12 | 14 | 16 | 18 |

Uma busca binária nesse vetor compararia a chave 9 com os seguintes valores do vetor:

a) 2, 6, 10, 14 e 18
b) 10, 4, 6 e 8
c) Nenhuma porque a chave não existe no vetor
d) 10, 14 e 18

### QUESTÃO 07
Sobre o custo das operações de busca por uma chave em árvores vermelho e preto, sabe-se que:

I) Uma árvore vermelho e preto tem altura máxima log n, onde n é o número de chaves, pois a mesma é balanceada
II) Uma árvore vermelho e preto tem altura máxima inferior a 3 log n, onde n é o número de chaves, pois a mesma é balanceada
III) Uma árvore vermelho e preto pode ser degenerada no pior caso, tendo custo de busca crescendo linearmente com o número de elementos, mas em situações muito raras, pois a mesma é balanceada

a) Apenas I é verdadeira
b) Apenas II é verdadeira
c) Apenas III é verdadeira
d) Apenas I e II são verdadeiras

### QUESTÃO 08
Considere uma pilha que inicialmente estava vazia e na qual inseriu-se as chaves 2, 4 e 6, 8 e 10 nessa ordem. Sobre uma operação de remoção de elemento da mesma (retirada padrão de uma pilha), considerando-se que a estrutura de dados usada é uma lista encadeada, pode-se afirmar que:

I) A remoção retira a chave 2
II) A remoção da chave 10
III) Custo computacional proporcional ao tamanho da pilha
IV) Custo computacional constante, não importando o tamanho da pilha

a) Apenas I e III estão corretas
b) Apenas I e IV estão corretas
c) Apenas II e III estão corretas
d) Apenas II e IV estão corretas

### QUESTÃO 09
Sobre um vetor que se mantém de forma ordenada a cada inserção, remoção ou alteração feita, qual a alternativa verdadeira ao usarmos os algoritmos mais eficientes para cada operação:

a) A inserção tem custo linear no pior caso, a remoção tem custo linear no pior caso e a busca mais eficiente possível tem custo linear
b) A inserção tem custo linear no pior caso, a remoção tem custo linear no pior caso e a busca tem custo logarítmico no pior caso
c) A inserção tem custo logarítmico no pior caso, a remoção tem custo logarítmico no pior caso e a busca mais eficiente possível tem custo constante
d) A inserção tem custo linear no pior caso, a remoção tem custo logarítmico no pior caso e a busca mais eficiente possível tem custo logarítmico

### QUESTÃO 10
Sobre os algoritmos de ordenação quicksort, mergesort e inserção, é correto afirmar que:

I) O quicksort é o que apresenta melhor desempenho no pior caso dentre os três algoritmos, sendo por isso o algoritmo mais usado
II) A ordenação por inserção tende a ser a mais rápida em casos de ordenação de um vetor onde o número de elementos fora de ordem é menor que um décimo de log N, sendo N o número de elementos do vetor e N um valor grande
III) O mergesort é o que tem menor custo assintótico no pior caso quando comparamos os três algoritmos

a) Apenas I é verdadeira
b) Apenas II é verdadeira
c) Apenas III é verdadeira
d) As alternativas A, B e C não são corretas

### QUESTÃO 11
Marque a alternativa correta sobre os custos, no pior caso, dos melhores algoritmos conhecidos para inserir um elemento, remover um elemento e pesquisar por uma chave em um vetor que contenha n elementos, sendo a busca feita pelo campo usado para ordenar o vetor. Considere que o vetor sempre esteja ordenado antes da operação e permaneça ordenado após a operação. Pode-se dizer que as operações de inserção, remoção e busca nesse cenário têm, respectivamente, custo no pior caso:

a) O(n. log(n)), O(n. log(n)) e O(log(n))
b) O(n. log(n)), O(n. log(n)) e O(n)
c) O(n), O(n) e O(n)
d) O(n), O(n) e O(log(n))

### QUESTÃO 12
Considere que um vetor de 8 elementos está sendo ordenado de forma crescente pelo algoritmo quicksort, e que após a escolha do pivot (elemento usado como chave para o particionamento) e ao final do primeiro particionamento, o vetor tenha ficado com os seguintes valores:

| 2 | 5 | 9 | 1 | 7 | 2 | 1 | 9 |
|---|---|---|---|---|---|---|---|

Dado o resultado, pode-se afirmar que:

a) O valor 2 pode ter sido o pivô que gerou a partição
b) O valor 9 pode ter sido o pivô que gerou a partição
c) O valor 1 pode ter sido o pivô que gerou a partição
d) O valor 7 pode ter sido o pivô que gerou a partição

### QUESTÃO 13
Considere uma tabela hash por encadeamento onde os elementos inseridos são números inteiros positivos. Considere que a tabela tem tamanho 5 e que a função de espalhamento (função de hash) calcula o resto da divisão do valor do elemento por 5 para determinar a posição de inserção na tabela. Quantas colisões de chaves teremos se a tabela estiver inicialmente vazia e inserirmos as chaves 2, 5, 9, 20 e 7?

a) Não há colisões
b) Uma colisão
c) Duas colisões
d) Três colisões

### QUESTÃO 14
Considere uma árvore binária de pesquisa sem balanceamento contendo como dado números inteiros, que começou vazia, e onde foram inseridos posteriormente, nesta ordem, os valores 10, 5, 20, 1, 30, 7 e 15. Uma chave de busca nessa árvore sem balanceamento terá que comparar a chave de busca, na pior das hipóteses, com:

a) 7 nós da árvore
b) 6 nós da árvore
c) 2 nós da árvore
d) 3 nós da árvore

### QUESTÃO 15
Dado o seguinte pseudocódigo Python de busca binária recursiva, indique qual das opções abaixo é impressa pela linha final print().

```python
def pesquisa_binaria_recursiva(A, esquerda, direita, item):
    if direita < esquerda:
        return -1
    meio = (esquerda + direita) // 2
    if A[meio] == item:
        return meio
    elif A[meio] > item:
        return pesquisa_binaria_recursiva(A, esquerda, meio - 1, item)
    else:
        return pesquisa_binaria_recursiva(A, meio + 1, direita, item)

A = [0, 100, 20, 30, 40, 50, 60, 70]
print("Pesquisa com sucesso:", pesquisa_binaria_recursiva(A, 0, len(A) - 1, 100))
```

a) Pesquisa com sucesso: 100
b) Pesquisa com sucesso: -1
c) Pesquisa com sucesso: 1
d) Pesquisa com sucesso: 2

### QUESTÃO 16
Considere a seguinte afirmação:

Considerando o pior caso no custo das operações, em uma tabela hash com encadeamento na qual uma lista encadeada é usada para tratamento de colisões e uma chave no hash não pode se repetir, uma inserção tem custo de __, enquanto que uma busca tem custo de __. Entretanto, se tirarmos a lista encadeada e usarmos uma árvore rubro-negra para o tratamento de colisões, o custo de inserção na tabela hash passa a ser __ e o custo de busca passa a ser __.

Assinale a opção que preenche corretamente os campos em branco:

a) O(n), O(n), O(log n), O(log n)
b) O(1), O(n), O(1), O(log n)
c) O(n), O(1), O(log n), O(1)
d) O(1), O(1), O(1), O(1)

### QUESTÃO 17
Dado o seguinte pseudocódigo Python de busca binária recursiva, indique quantas vezes ocorre a chamada da função pesquisa_binaria_recursiva():

```python
def pesquisa_binaria_recursiva(A, esquerda, direita, item):
    if direita < esquerda:
        return -1
    meio = (esquerda + direita) // 2
    if A[meio] == item:
        return meio
    elif A[meio] > item:
        return pesquisa_binaria_recursiva(A, esquerda, meio - 1, item)
    else:
        return pesquisa_binaria_recursiva(A, meio + 1, direita, item)

A = [0, 100, 20, 30, 40, 50, 60, 70]
print("Pesquisa com sucesso:", pesquisa_binaria_recursiva(A, 0, len(A) - 1, 70))
```

a) 0 vezes
b) 3 vezes
c) 4 vezes
d) 5 vezes

### QUESTÃO 18
Dado o seguinte pseudocódigo Python, indique a saída correta que será impressa na tela do computador:

```python
import numpy as np

A = [[0, 2, 1],[1, 0, 0]]
B = [[7, 0],[0, 10],[11, 0]]

def operacao_com_matrizes():
    resultado = np.zeros((2,2))
    for i in range(len(A)):
        for j in range(len(B[0])):
            for k in range(len(B)):
                resultado[i][j] += A[i][k] * B[k][j]
    return resultado

print(operacao_com_matrizes())
```

a)
```
[[0. 2. 1.]
 [1. 0. 0.]]
```
b)
```
[[ 7.  0.]
 [ 0. 10.]
 [11.  0.]]
```
c)
```
[[ 7.  0.]
 [11. 20.]]
```
d)
```
[[11. 20.]
 [ 7.  0.]]
```

### QUESTÃO 19
Dado o seguinte pseudocódigo Python, indique a saída correta que será impressa na tela do computador quando a seguinte sequência de comandos é executada:

```python
class Stack:
    def __init__(self):
        self.stack = []

    def pushit(self,value):
        self.stack.append(value)

    def popit(self):
        try:
            self.stack.pop()
        except:
            print('empty stack')
            self.stack = []
```

Os comandos executados são:

```python
stack = Stack(); stack.pushit(1); stack.pushit(3); stack.popit(); stack.popit(); stack.popit(); stack.pushit(2); stack.pushit(1); stack.popit(); print(stack.stack)
```

a) [2, 1]
b) empty stack
   [2]
c) empty stack
   []
d) []

### QUESTÃO 20
Dado o seguinte pseudocódigo Python, indique qual seria a saída correta no terminal do computador:

```python
def func1(fator):
    def func2(x):
        return x * fator
    return func2

funcao = func1(3)
print(funcao(5))
```

a) A saída é um erro pois a primeira função retorna outra função mas não passou o argumento 'fator'
b) A saída é 15
c) A saída é 3
d) A saída é 0
