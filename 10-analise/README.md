<!-- Gerado por _gerador. Para mudar este arquivo, edite _gerador/modulos/10-analise/ e rode: cd _gerador && npm run gerar -->

# Módulo 10 · Pensar como cientista da computação

Até aqui a pergunta foi "como escrevo isso em C?". Daqui para a frente, com
listas, pilhas, árvores e grafos, ela muda para "**qual** jeito de escrever é o
certo?". Para listar pedidos dá para usar um vetor ou uma lista encadeada, e
para achar um cliente, uma busca sequencial, uma binária ou uma tabela hash.
Todas funcionam com 10 itens. Com 1 milhão, umas respondem na hora e outras
travam o servidor.

Este módulo é a caixa de ferramentas para decidir. São três ideias que
atravessam o resto do curso: **medir o custo** contando passos e resumindo o
crescimento na notação O; **ter certeza de que está certo** com invariantes de
laço, em vez de confiar em meia dúzia de testes; e **esconder os detalhes**
atrás de um tipo abstrato de dado, para poder trocar a implementação sem
quebrar quem usa.

Quem vem do TypeScript já esbarrou nisso sem nome: o `includes` dentro do
`filter` que deixou a tela lenta, a classe com campos `#privados`, a
`interface` que esconde a implementação. Aqui é a mesma coisa, com o C
mostrando o custo de cada escolha.

## O que você vai aprender

- medir a **eficiência** de um algoritmo contando passos: melhor, pior e caso médio
- ler e escrever a **notação O**: O(1), O(log n), O(n), O(n log n) e O(n²), e por que constantes somem
- enunciar **invariantes de laço** e usá-los para provar que um laço está certo (e achar bugs)
- montar um **tipo abstrato de dado** com interface (`.h`), implementação (`.c`) e tipo opaco: o padrão de todos os próximos módulos

## Como estudar cada assunto

1. Leia o texto e olhe o **diagrama da ideia**: é o exemplo desenhado.
2. Leia o código. É o mesmo exemplo, com os mesmos valores.
3. Siga o **fluxograma** com o dedo: é o caminho que o programa faz.
4. Rode os exemplos. Mude o n, troque os dados, quebre um invariante de
   propósito e veja o `assert` disparar.
5. Faça os exercícios. ★☆☆ é aquecimento, ★★☆ pede raciocínio, ★★★ é desafio.
   As dicas vêm logo abaixo do enunciado: tente antes de ler.

No meio de cada assunto tem uma **Pergunta para você**. Responda antes de rodar.

## As cores e as formas

Caixa azul é dado entrando ou saindo, roxa é o programa fazendo alguma coisa,
amarela é pergunta. Verde é o caminho que o exemplo segue (e, nas tabelas de
custo, o que continua leve); vermelho é erro ou custo que explodiu; cinza, o
que o exemplo não usa.

<p align="center"><img src="../legenda.svg" alt="Legenda: formas e cores do fluxograma" width="916"></p>

## Antes de começar

Você vai usar tudo dos módulos anteriores, em especial funções, vetores,
ponteiros, `malloc`/`free` e `struct`. Duas novidades pequenas:

- `<assert.h>`: `assert(condicao)` para o programa na hora se a condição for
  falsa. É o jeito de transformar um invariante em código.
- **arquivos de apoio**: no assunto 0079, a pasta tem `contador.h`,
  `contador.c`, `conta.h` e `conta.c` além dos exemplos. O `rodar` compila
  junto todo `.c` da pasta que não se chama `A000.c`/`E000.c`, então é só
  rodar o exemplo, como sempre:

```bash
~/LPEDC/rodar 10-analise/0079-tad/A157.c
```

Os contadores de passos dos exemplos não medem segundos: medem trabalho. Rode
na sua máquina e os números saem iguais aos do texto.

| # | Assunto | Pasta |
| --- | --- | --- |
| [0076](#0076--eficiência-contar-passos) | Eficiência: contar passos | [`0076-eficiencia/`](0076-eficiencia/) |
| [0077](#0077--notação-o-como-o-custo-cresce) | Notação O: como o custo cresce | [`0077-big-o/`](0077-big-o/) |
| [0078](#0078--invariantes-de-laço-e-corretude) | Invariantes de laço e corretude | [`0078-invariantes/`](0078-invariantes/) |
| [0079](#0079--tad-interface-h-e-implementação-c) | TAD: interface (.h) e implementação (.c) | [`0079-tad/`](0079-tad/) |

---

## 0076 · Eficiência: contar passos

Sexta à noite, padaria cheia. Você entrega a comanda 70 no caixa e a moça
procura no bolo de comandas, uma por uma. Se a sua for a primeira, você sai
na hora. Se for a última, espera o bolo inteiro. Com 8 comandas, tanto faz.
Com 800, faz muita diferença.

Até aqui a pergunta era "o programa está **certo**?". A partir de agora vem a
segunda: "ele é **rápido** o bastante?". E "rápido" não se mede em segundos.
O mesmo código leva 2 ms no seu notebook, 9 ms num Raspberry Pi e 40 ms se o
Chrome estiver aberto com 30 abas. Segundos medem a máquina, não o algoritmo.

O que não muda de máquina para máquina é **quantos passos** o algoritmo dá.
Você escolhe a operação que domina o trabalho (a **operação dominante**) e
conta quantas vezes ela acontece. Numa busca, é a comparação `v[i] == alvo`.
O `i++` e o `i < n` também rodam, mas andam junto com a comparação: contar um
ou outro dá a mesma ideia de custo.

A conta depende da entrada, e não só do tamanho dela. Por isso se fala em três
casos:

- **melhor caso**: a entrada mais camarada (a comanda está na frente): 1 passo;
- **pior caso**: a mais azarada (está no fim ou nem está lá): n passos;
- **caso médio**: a média de todas as posições possíveis: (n + 1) / 2 passos.

O pior caso é o que importa para prometer alguma coisa: "nunca passa de n
passos". O melhor caso não promete nada; é como dizer que a Marginal nunca tem
trânsito porque às 4 da manhã ela estava livre.

Vamos ver na prática. A comanda 70 está na posição 6. A busca compara com as 6
primeiras, erra todas, e acerta na 7ª comparação. A 41 sai em 1 passo; a 99,
que não está no bolo, custa as 8:

<p align="center"><img src="0076-eficiencia/ideia.svg" alt="Diagrama da ideia: Eficiência: contar passos" width="858"></p>

O contador é uma variável global que a função soma a cada comparação. É
instrumentação: um "medidor" que você acopla ao código só para estudar o
custo.

```c
#include <stdio.h>

int passos = 0; // conta as comparações: a operação que domina o custo

// Devolve o índice de alvo em v[0..n-1], ou -1 se ele não estiver lá.
int busca(const int v[], int n, int alvo) {
    for (int i = 0; i < n; i++) {
        passos++; // vai comparar v[i] com o alvo
        if (v[i] == alvo) {
            return i;
        }
    }
    return -1;
}

int main(void) {
    int comandas[8] = {41, 17, 88, 23, 56, 9, 70, 35};
    int alvos[3] = {41, 70, 99};

    for (int k = 0; k < 3; k++) {
        passos = 0; // zera antes de cada busca
        int pos = busca(comandas, 8, alvos[k]);
        printf("comanda %d: posição %2d, passos: %d\n", alvos[k], pos, passos);
    }
    return 0;
}
// Saída:
// comanda 41: posição  0, passos: 1
// comanda 70: posição  6, passos: 7
// comanda 99: posição -1, passos: 8
```

Agora imagine o bolo crescendo. Contar passos para vários tamanhos de entrada
e pôr numa tabela é o jeito honesto de comparar algoritmos:

| comandas (n) | melhor caso | caso médio | pior caso |
| --- | --- | --- | --- |
| 8 | 1 | 4,5 | 8 |
| 800 | 1 | 400,5 | 800 |
| 80.000 | 1 | 40.000,5 | 80.000 |

Multiplicou n por 100, o pior caso também multiplicou por 100. Guarde essa
frase: ela é o assunto inteiro do próximo tópico.

Repara no fluxograma: o laço só tem duas saídas. Ou a pergunta "achou?"
responde Sim, ou as comandas acabam. Cada volta pelo losango de baixo é um
passo a mais no contador:

<p align="center"><img src="0076-eficiencia/fluxograma.svg" alt="Fluxograma: Eficiência: contar passos" width="869"></p>

> [!WARNING]
> Contar a coisa errada engana. Se você puser o `passos++` **depois** do `if`
> que dá `return`, a comparação que acertou não entra na conta e a busca da
> comanda 41 aparece com 0 passos. E se esquecer de zerar o contador entre uma
> busca e outra, ele acumula: 1, 8, 16. Confira sempre o caso mais simples à
> mão (achar na primeira posição custa 1).

> [!TIP]
> **Por dentro do C:** medir tempo com `clock()` de `<time.h>` funciona, mas
> engana fácil com entradas pequenas: numa busca de microssegundos, o ruído
> (outros programas, cache, o próprio sistema) é maior que o tempo medido, e
> cada execução dá um número diferente. Pior: compilado com `-O2`, o
> `gcc` pode **apagar** um laço inteiro cujo resultado ninguém usa, e o tempo
> medido vira zero. Contar passos não tem esses problemas: o contador é usado
> no `printf`, então o compilador é obrigado a manter o laço, e o número sai
> igual em qualquer máquina.

> [!NOTE]
> **Pergunta para você:** se o bolo tivesse 8 comandas **em ordem crescente**
> (9, 17, 23, ..., 88), dava para parar antes ao procurar a 50, que não existe?
> Quantos passos a busca gastaria? E no pior caso, mudou alguma coisa?

### Hora de praticar

Os arquivos ficam em [`0076-eficiencia/`](0076-eficiencia/). Os comandos funcionam de qualquer pasta do terminal. Nos exemplos, rode, mude, quebre e rode de novo. Nos exercícios, a resposta vai dentro do próprio arquivo. ★☆☆ é aquecimento, ★★☆ pede raciocínio e ★★★ é desafio.

**Exemplo A151 · Quantas comparações para achar a comanda**

```c
#include <stdio.h>

int passos = 0; // conta as comparações: a operação que domina o custo

// Devolve o índice de alvo em v[0..n-1], ou -1 se ele não estiver lá.
int busca(const int v[], int n, int alvo) {
    for (int i = 0; i < n; i++) {
        passos++; // vai comparar v[i] com o alvo
        if (v[i] == alvo) {
            return i;
        }
    }
    return -1;
}

int main(void) {
    int comandas[8] = {41, 17, 88, 23, 56, 9, 70, 35};
    int alvos[3] = {41, 70, 99};

    for (int k = 0; k < 3; k++) {
        passos = 0; // zera antes de cada busca
        int pos = busca(comandas, 8, alvos[k]);
        printf("comanda %d: posição %2d, passos: %d\n", alvos[k], pos, passos);
    }
    return 0;
}
// Saída:
// comanda 41: posição  0, passos: 1
// comanda 70: posição  6, passos: 7
// comanda 99: posição -1, passos: 8
```

```bash
~/LPEDC/rodar 10-analise/0076-eficiencia/A151.c
```

**Exemplo A152 · Três tarefas, três ritmos**

```c
#include <stdio.h>

// O grupo do condomínio tem n moradores. Três tarefas, contadas passo a passo:
//   aviso:      o síndico manda UMA mensagem no grupo
//   convite:    o síndico manda uma mensagem para cada morador
//   cumprimento: cada par de moradores troca um "bom dia"

long tarefa_aviso(int n) {
    (void)n;          // não importa quantos moradores existem
    long passos = 0;
    passos++;         // uma mensagem só
    return passos;
}

long tarefa_convite(int n) {
    long passos = 0;
    for (int i = 0; i < n; i++) {
        passos++;     // uma mensagem por morador
    }
    return passos;
}

long tarefa_cumprimento(int n) {
    long passos = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            passos++; // o par (i, j) se cumprimenta
        }
    }
    return passos;
}

int main(void) {
    int tamanhos[3] = {10, 100, 1000};

    printf("%6s %7s %9s %12s\n", "n", "aviso", "convite", "cumprimento");
    for (int k = 0; k < 3; k++) {
        int n = tamanhos[k];
        printf("%6d %7ld %9ld %12ld\n", n, tarefa_aviso(n), tarefa_convite(n),
               tarefa_cumprimento(n));
    }
    return 0;
}
// Saída:
//      n   aviso   convite  cumprimento
//     10       1        10           45
//    100       1       100         4950
//   1000       1      1000       499500
```

```bash
~/LPEDC/rodar 10-analise/0076-eficiencia/A152.c
```

#### Exercícios

**Exercício E451** · ★☆☆

Antes de rodar, preveja quantos passos cada trecho conta. Anote os quatro
números, depois rode e confira.


```text
a) for (i = 0; i < 6; i++)  for (j = 0; j < 4; j++)  passos++;
b) for (i = 0; i < 6; i++)  for (j = i; j < 6; j++)  passos++;
c) for (i = 1; i < 100; i = i * 2)  passos++;
d) for (i = 0; i < 10; i++)  if (i % 3 == 0) passos++;
```

**Dicas:**

1. Em a), o laço de dentro roda inteiro a cada volta do de fora.
2. Em b), o laço de dentro encolhe: começa em i. Faça a lista 6 + 5 + ...
3. Em c), escreva os valores de i: 1, 2, 4, ... até passar de 99.
4. Resposta esperada: a) 24; b) 21 (6 + 5 + 4 + 3 + 2 + 1); c) 7
   (i = 1, 2, 4, 8, 16, 32, 64); d) 4 (i = 0, 3, 6, 9).

```bash
~/LPEDC/rodar 10-analise/0076-eficiencia/E451.c
```

**Exercício E452** · ★☆☆

A função abaixo acha a maior temperatura de uma semana e meia (10 dias).
Complete o código com dois contadores globais: "comparacoes" (quantas vezes
a função compara t[i] com o maior até agora) e "trocas" (quantas vezes o
maior até agora muda de valor). Mostre os dois no final.


```text
Saída esperada:
Maior: 36
Comparações: 9
Trocas: 3
```

**Dicas:**

1. O maior começa como t[0]. A primeira comparação é com t[1].
2. Some 1 em comparacoes antes do if; some 1 em trocas dentro dele.
3. Com n valores, achar o maior custa sempre n - 1 comparações, não importa
   a ordem. Já o número de trocas depende da ordem dos dados.
4. Resposta esperada: Maior: 36, Comparações: 9, Trocas: 3 (o maior muda
   para 31, depois 35, depois 36).

```bash
~/LPEDC/rodar 10-analise/0076-eficiencia/E452.c
```

**Exercício E453** · ★★☆

O texto disse que, em média, a busca sequencial custa (n + 1) / 2
comparações. Não acredite: meça. Escreva um programa que, para n = 10, 100
e 1000:

1. preenche um vetor com os códigos de produto v[i] = 3 * i + 1;
2. busca, um por um, TODOS os códigos que estão no vetor, somando os passos
de todas as buscas;
3. mostra o total e a média de passos por busca.


```text
Saída esperada:
n =   10: total     55, média   5.5
n =  100: total   5050, média  50.5
n = 1000: total 500500, média 500.5
```

**Dicas:**

1. Use um vetor de 1000 posições e só as n primeiras em cada rodada.
2. Reaproveite a busca do A151 com o contador global; zere-o uma vez por n,
   não a cada busca, para acumular o total.
3. Achar o código da posição i custa i + 1 passos. Somando de 1 até n dá
   n(n + 1) / 2; dividindo por n, (n + 1) / 2.
4. Resposta esperada: médias 5.5, 50.5 e 500.5.

```bash
~/LPEDC/rodar 10-analise/0076-eficiencia/E453.c
```

**Exercício E454** · ★★☆

Dois jeitos de saber se n é primo, contando as divisões (n % d) como passo:


```text
ingênuo: testa todo d de 2 até n - 1;
esperto: testa d de 2 enquanto d * d <= n. Se n tivesse um divisor maior
         que a raiz, teria também um menor, que já teria aparecido.
```


Escreva as duas funções (devolvem bool) com contadores e mostre a tabela
para os primos 97, 997 e 9973.


```text
Saída esperada:
    n  ingênuo  esperto
   97       95        8
  997      995       30
 9973     9971       98
```

**Dicas:**

1. Primo é o pior caso dos dois: nenhuma divisão dá resto 0, então o laço
   vai até o fim.
2. Use dois contadores globais e zere os dois antes de cada n.
3. Repare: n cresceu 100 vezes; o ingênuo cresceu 100 vezes, o esperto
   só uns 12. A raiz de 100 é 10.
4. Resposta esperada: a tabela acima.

```bash
~/LPEDC/rodar 10-analise/0076-eficiencia/E454.c
```

**Exercício E455** · ★★★

Este programa busca três senhas de atendimento do banco e deveria mostrar
os passos 1, 4 e 6. Ele compila sem aviso, mas mostra 0, 3 e 9. Há DOIS
erros na instrumentação (a busca em si está certa). Ache e conserte os dois.


```text
Saída esperada:
senha 12: passos 1
senha 8: passos 4
senha 40: passos 6
```

**Dicas:**

1. Faça o teste de mesa da senha 12, que está na posição 0. Quando o
   passos++ roda?
2. Depois olhe a senha 8: o 3 que apareceu é dela ou é acumulado?
3. Resposta esperada: (1) o passos++ está depois do if que dá return, então
   a comparação que acerta nunca é contada: ele tem de vir antes do if;
   (2) o contador é zerado uma vez só, antes do for do main: tem de ser
   zerado dentro do for, antes de cada busca.

```bash
~/LPEDC/rodar 10-analise/0076-eficiencia/E455.c
```

**Exercício E456** · ★★★

No assunto 0038 você viu que o Fibonacci recursivo é lento. Agora meça o
quanto. Escreva:

- fib_rec(n): a versão recursiva (fib(0) = 0, fib(1) = 1), somando 1 num
contador global "chamadas" a cada vez que a função é chamada;
- fib_it(n): a versão com laço, somando 1 num contador "somas" a cada soma.

Mostre a tabela para n = 10, 20 e 30. Use long para os contadores.


```text
Saída esperada:
 n     fib  chamadas  somas
10      55       177      9
20    6765     21891     19
30  832040   2692537     29
```


Depois responda: quando n aumenta 1, as chamadas da recursiva se
multiplicam por quanto, mais ou menos?

**Dicas:**

1. Zere os contadores antes de cada n.
2. A versão com laço guarda os dois últimos valores e anda n - 1 vezes.
3. fib_rec(n) chama fib_rec(n - 1) e fib_rec(n - 2): o fib(28) é calculado
   do zero 2 vezes, o fib(27) 3 vezes, o fib(26) 5 vezes...
4. Resposta esperada: a tabela acima. A cada +1 no n, as chamadas
   multiplicam por cerca de 1,618 (a razão áurea): de n = 10 para 20 elas
   crescem 21891 / 177 ≈ 124 vezes, e 1,618 elevado a 10 ≈ 123. Isso é
   crescimento exponencial.

```bash
~/LPEDC/rodar 10-analise/0076-eficiencia/E456.c
```

---

## 0077 · Notação O: como o custo cresce

Você fez o app da hamburgueria. Testou com 8 pedidos: voou. Uma semana depois,
64 pedidos por noite: tudo bem. Aí veio a Black Friday com 1024 pedidos e uma
tela travou. O código não mudou. O que mudou foi o **n**, e cada parte do
programa reagiu de um jeito diferente a ele.

O assunto anterior contou passos. Este pergunta: **como a contagem cresce
quando n cresce?** É o que a **notação O** (fala-se "ó grande") resume numa
expressão curta. Ela ignora duas coisas de propósito:

- **constantes multiplicativas**: 3n e 100n são os dois O(n). A constante
  depende da máquina e de detalhes; o formato do crescimento, não;
- **termos menores**: em n² + 50n + 7, o n² engole o resto quando n cresce.
  Com n = 1000, ele vale 1.000.000 e o 50n só 50.000. Fica O(n²).

A definição de verdade: f(n) é **O(g(n))** se existe uma constante c tal que
f(n) ≤ c · g(n) para todo n a partir de algum ponto. É um **teto**: "nunca
cresce mais rápido que g". As cinco classes que você vai encontrar o curso
inteiro, da melhor para a pior:

| classe | nome | n dobra, o custo... | exemplo |
| --- | --- | --- | --- |
| O(1) | constante | fica igual | `v[i]`, topo da pilha |
| O(log n) | logarítmica | ganha **1** passo | busca binária |
| O(n) | linear | dobra | somar um vetor |
| O(n log n) | "n log n" | pouco mais que dobra | merge sort |
| O(n²) | quadrática | **quadruplica** | comparar todos os pares |

Para ler a classe de um código, olhe os laços. Um laço que anda de 1 em 1 até
n é O(n). Dois laços aninhados até n, O(n²). Um laço que **divide** n por 2 a
cada volta é O(log n): de 1024 até 1 são só 10 cortes, porque 2¹⁰ = 1024. E a
base do log não importa: trocar log₂ por log₁₀ só muda uma constante.

Vamos ver na prática. Cinco perguntas sobre os mesmos pedidos, cada uma com o
seu ritmo. Em verde, o que continua leve em 1024; em vermelho, o que explodiu:

<p align="center"><img src="0077-big-o/ideia.svg" alt="Diagrama da ideia: Notação O: como o custo cresce" width="858"></p>

Cada função conta os passos de uma pergunta. Rode e veja a tabela se formar:

```c
#include <stdio.h>

// O(1): qual é o primeiro pedido da fila? Basta olhar a posição 0.
long passos_constante(int n) {
    (void)n;
    return 1;
}

// O(log n): cortar a lista ordenada ao meio até sobrar 1 pedido.
long passos_log(int n) {
    long passos = 0;
    while (n > 1) {
        n = n / 2;
        passos++;
    }
    return passos;
}

// O(n): somar o faturamento, olhando cada pedido uma vez.
long passos_linear(int n) {
    long passos = 0;
    for (int i = 0; i < n; i++) {
        passos++;
    }
    return passos;
}

// O(n log n): para cada pedido de hoje, uma busca binária na lista de ontem.
long passos_n_log_n(int n) {
    long passos = 0;
    for (int i = 0; i < n; i++) {
        passos += passos_log(n);
    }
    return passos;
}

// O(n²): comparar cada pedido com todos os outros, atrás de duplicados.
long passos_quadratico(int n) {
    long passos = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            passos++;
        }
    }
    return passos;
}

int main(void) {
    int tamanhos[3] = {8, 64, 1024};

    printf("%6s %5s %6s %6s %8s %8s\n", "n", "O(1)", "log n", "n", "n log n", "n^2");
    for (int k = 0; k < 3; k++) {
        int n = tamanhos[k];
        printf("%6d %5ld %6ld %6ld %8ld %8ld\n", n, passos_constante(n), passos_log(n),
               passos_linear(n), passos_n_log_n(n), passos_quadratico(n));
    }
    return 0;
}
// Saída:
//      n  O(1)  log n      n  n log n      n^2
//      8     1      3      8       24       28
//     64     1      6     64      384     2016
//   1024     1     10   1024    10240   523776
```

Repare na última coluna: comparar todos os pares dá n(n − 1)/2, que é mais ou
menos n²/2. A metade é uma constante e some na notação: continua O(n²). De 64
para 1024 o n cresceu 16 vezes e essa coluna cresceu 260 vezes. A do log
ganhou 4 passos.

Repara no fluxograma: é o laço do O(log n) com n = 1024. A pergunta "n > 1?"
responde Sim só 10 vezes, porque cada volta joga metade fora:

<p align="center"><img src="0077-big-o/fluxograma.svg" alt="Fluxograma: Notação O: como o custo cresce" width="531"></p>

> [!WARNING]
> O(n) não é "sempre mais rápido" que O(n²). A notação fala do **crescimento**,
> não do tempo para um n específico. Um algoritmo de 100n passos perde de um de
> n² até n = 100 (o exemplo A154 mostra a virada). Para 10 itens, o simples
> costuma ganhar. A segunda pegadinha é a inversa: um laço O(n) que chama, a
> cada volta, uma função O(n) dá **O(n²)**, mesmo parecendo um laço só. No JS
> é o `array.includes()` dentro de um `filter()`; no C, o `strlen(s)` na
> condição do `for`.

> [!TIP]
> **Por dentro do C:** por que `v[i]` é O(1), não importa se i vale 3 ou 3
> milhões? Porque o vetor é contínuo na memória e o endereço sai de uma conta
> só: `endereço de v + i * sizeof(int)`. O processador faz isso numa instrução.
> Numa lista encadeada (módulo 11) não existe essa conta: para chegar no
> elemento i é preciso seguir i ponteiros, um por um. Mesma pergunta, O(n).
> A escolha da estrutura de dados decide a classe antes de você escrever o
> algoritmo.

> [!NOTE]
> **Pergunta para você:** se um algoritmo O(n²) leva 1 segundo com 10.000
> pedidos, quanto ele leva com 100.000? E um O(n log n) que também leva 1
> segundo com 10.000? Faça a conta antes de olhar os exercícios.

### Hora de praticar

Os arquivos ficam em [`0077-big-o/`](0077-big-o/). Os comandos funcionam de qualquer pasta do terminal. Nos exemplos, rode, mude, quebre e rode de novo. Nos exercícios, a resposta vai dentro do próprio arquivo. ★☆☆ é aquecimento, ★★☆ pede raciocínio e ★★★ é desafio.

**Exemplo A153 · Cinco perguntas sobre os pedidos**

```c
#include <stdio.h>

// O app da hamburgueria tem n pedidos. Cada função conta os passos de uma
// pergunta diferente sobre eles.

// O(1): qual é o primeiro pedido da fila? Basta olhar a posição 0.
long passos_constante(int n) {
    (void)n;
    return 1;
}

// O(log n): cortar a lista ordenada ao meio até sobrar 1 pedido
// (é o que a busca binária faz, no assunto 0095).
long passos_log(int n) {
    long passos = 0;
    while (n > 1) {
        n = n / 2;
        passos++;
    }
    return passos;
}

// O(n): somar o faturamento, olhando cada pedido uma vez.
long passos_linear(int n) {
    long passos = 0;
    for (int i = 0; i < n; i++) {
        passos++;
    }
    return passos;
}

// O(n log n): para cada pedido de hoje, uma busca binária na lista de ontem.
long passos_n_log_n(int n) {
    long passos = 0;
    for (int i = 0; i < n; i++) {
        passos += passos_log(n);
    }
    return passos;
}

// O(n²): comparar cada pedido com todos os outros, atrás de duplicados.
long passos_quadratico(int n) {
    long passos = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            passos++;
        }
    }
    return passos;
}

int main(void) {
    int tamanhos[3] = {8, 64, 1024};

    printf("%6s %5s %6s %6s %8s %8s\n", "n", "O(1)", "log n", "n", "n log n", "n^2");
    for (int k = 0; k < 3; k++) {
        int n = tamanhos[k];
        printf("%6d %5ld %6ld %6ld %8ld %8ld\n", n, passos_constante(n), passos_log(n),
               passos_linear(n), passos_n_log_n(n), passos_quadratico(n));
    }
    return 0;
}
// Saída:
//      n  O(1)  log n      n  n log n      n^2
//      8     1      3      8       24       28
//     64     1      6     64      384     2016
//   1024     1     10   1024    10240   523776
```

```bash
~/LPEDC/rodar 10-analise/0077-big-o/A153.c
```

**Exemplo A154 · A constante grande perde no fim**

```c
#include <stdio.h>

// Duas bibliotecas de cálculo de frete para n pedidos:
//   A: faz 100 contas fixas por pedido          -> 100n passos, O(n)
//   B: compara cada pedido com cada pedido      -> n² passos,   O(n²)
// Para n pequeno, B ganha. Depois de um ponto, A ganha para sempre.

long biblioteca_a(int n) {
    long passos = 0;
    for (int i = 0; i < n; i++) {
        for (int k = 0; k < 100; k++) {
            passos++;
        }
    }
    return passos;
}

long biblioteca_b(int n) {
    long passos = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            passos++;
        }
    }
    return passos;
}

int main(void) {
    int tamanhos[5] = {10, 50, 100, 200, 1000};

    printf("%5s %8s %8s  %s\n", "n", "A: 100n", "B: n^2", "mais rápida");
    for (int k = 0; k < 5; k++) {
        int n = tamanhos[k];
        long a = biblioteca_a(n);
        long b = biblioteca_b(n);
        const char *vence = a < b ? "A" : (b < a ? "B" : "empate");
        printf("%5d %8ld %8ld  %s\n", n, a, b, vence);
    }
    return 0;
}
// Saída:
//     n  A: 100n   B: n^2  mais rápida
//    10     1000      100  B
//    50     5000     2500  B
//   100    10000    10000  empate
//   200    20000    40000  A
//  1000   100000  1000000  A
```

```bash
~/LPEDC/rodar 10-analise/0077-big-o/A154.c
```

#### Exercícios

**Exercício E457** · ★☆☆

Dê a classe O de cada trecho, em função de n. Escreva a resposta como
comentário e justifique em uma linha (quantas vezes o corpo roda?).


```text
a) for (i = 0; i < n; i++)  for (j = 0; j < 10; j++)  x++;
b) for (i = 1; i < n; i = i * 2)  x++;
c) for (i = 0; i < n; i++)  for (j = 0; j < i; j++)  x++;
d) x = v[n / 2] + v[0];
e) for (i = 0; i < n; i++)  x++;
   for (j = 0; j < n; j++)  x++;
f) for (i = 0; i < n; i++)  for (j = n; j > 1; j = j / 2)  x++;
```

**Dicas:**

1. Um laço de dentro com tamanho fixo (10) é constante: não depende de n.
2. Laços em sequência somam; laços aninhados multiplicam.
3. Em c), o de dentro roda 0 + 1 + 2 + ... + (n - 1) = n(n - 1)/2 vezes.
4. Resposta esperada: a) O(n) (10n); b) O(log n); c) O(n²); d) O(1);
   e) O(n) (2n); f) O(n log n).

```bash
~/LPEDC/rodar 10-analise/0077-big-o/E457.c
```

**Exercício E458** · ★☆☆

Seis colegas contaram os passos dos seus algoritmos e chegaram nestas
fórmulas. Simplifique cada uma para a notação O mais justa (a menor classe
que serve), usando as duas regras: descartar constantes e ficar com o termo
que domina.


```text
a) 3n² + 10n + 7
b) 500
c) n + log n
d) 2n log n + 50n
e) n³ / 1000 + n²
f) n(n + 1) / 2
```

**Dicas:**

1. Para achar o termo que domina, troque n por 1.000.000 e veja qual parte
   fica enorme.
2. Em e), o 1/1000 é só uma constante: n³ ainda ganha de n² para n grande.
3. Em f), abra a conta: n²/2 + n/2.
4. Resposta esperada: a) O(n²); b) O(1); c) O(n); d) O(n log n); e) O(n³);
   f) O(n²).

```bash
~/LPEDC/rodar 10-analise/0077-big-o/E458.c
```

**Exercício E459** · ★★☆

O cupom fiscal tem códigos de produto de 0 a 999. Você quer saber se algum
código aparece repetido. Escreva duas funções que devolvem bool e contam
passos (comparações ou consultas):

- repetido_pares(v, n): compara cada par (i, j) com i < j. O(n²).
- repetido_marcas(v, n): usa um vetor bool visto[1000] (todo false no
começo); para cada código, consulta visto[codigo] e marca. O(n).

Teste com n = 100 e n = 1000, com v[i] = (i * 37) % 1000 (que não tem
repetidos: é o pior caso, as duas vão até o fim).


```text
Saída esperada:
n =  100: pares   4950 passos, marcas  100 passos
n = 1000: pares 499500 passos, marcas 1000 passos
```

**Dicas:**

1. Em repetido_marcas, o passo é cada consulta a visto[v[i]].
2. Para zerar o vetor de marcas: bool visto[1000] = {false};
3. A versão com marcas troca memória (1000 bools) por tempo. Funciona aqui
   porque os códigos são pequenos; com CPFs, precisaria de outra ideia
   (a tabela hash do módulo 15).
4. Resposta esperada: a saída acima; as duas respondem "sem repetidos".

```bash
~/LPEDC/rodar 10-analise/0077-big-o/E459.c
```

**Exercício E460** · ★★☆

A "regra do dobro": rode um algoritmo com n e com 2n e divida os passos.
Razão perto de 1 (com +1 passo) é O(log n); perto de 2, O(n); perto de 4,
O(n²). Complete o main para mostrar, para cada função misteriosa, os passos
com n = 1000 e n = 2000 e a razão entre eles. Depois dê a classe de cada uma.


```text
Saída esperada:
a:     334 ->     667  razão 2.00
b:      10 ->      11  razão 1.10
c:  500000 -> 2000000  razão 4.00
d:      32 ->      45  razão 1.41
```

**Dicas:**

1. Use (double)p2 / p1 para a razão não virar divisão inteira.
2. A d) não é nenhuma das cinco classes do texto. Que número elevado ao
   quadrado dá 2? Pense em d * d < n.
3. Resposta esperada: a) O(n) (n/3 passos); b) O(log n); c) O(n²) (n²/2);
   d) O(√n), raiz de n: dobrar n multiplica por √2 ≈ 1,41.

```bash
~/LPEDC/rodar 10-analise/0077-big-o/E460.c
```

**Exercício E461** · ★★★

Você precisa ordenar a lista de entregas e tem duas opções:


```text
A: um algoritmo simples, que gasta 2n² passos;
B: um sofisticado, que gasta 50 n log₂ n passos.
```


B é O(n log n) e A é O(n²), então B ganha "no fim". Mas a partir de que n?
Escreva um programa que encontra o MENOR n (começando em 2) em que B gasta
menos passos que A, e mostra os dois custos nesse n. Mostre também uma
tabela para n = 10, 100, 1000 e 10000.


```text
Saída esperada:
B passa a ganhar em n = 190 (A: 72200, B: 71914)
     n           A          B
    10         200       1661
   100       20000      33219
  1000     2000000     498289
 10000   200000000    6643856
```

**Dicas:**

1. log2() está em <math.h> (o rodar já liga com -lm). Faça as contas em
   double.
2. Um laço n = 2, 3, 4, ... que para (break) no primeiro n em que
   50 * n * log2(n) < 2.0 * n * n.
3. Mostre os doubles com %.0f para arredondar.
4. Resposta esperada: n = 190. Para listas com menos de 190 entregas, o
   "pior" algoritmo é o mais rápido. Com 10000, B é 30 vezes mais rápido.

```bash
~/LPEDC/rodar 10-analise/0077-big-o/E461.c
```

**Exercício E462** · ★★★

Este programa conta as vogais de um texto de n letras. A função tamanho()
faz o mesmo que o strlen (anda até o '\0') e conta cada letra visitada como
um passo. Rode e veja os passos para n = 1000, 2000 e 4000:


```text
n = 1000: 400 vogais, 1001000 passos
n = 2000: 800 vogais, 4002000 passos
n = 4000: 1600 vogais, 16004000 passos
```


a) Pela regra do dobro, qual é a classe O desse código?
b) Onde está o desperdício?
c) Refatore para ficar O(n), sem mudar a função tamanho(), e mostre a nova
contagem de passos.

**Dicas:**

1. Quantas vezes a condição do for é avaliada? E o que ela chama?
2. O texto não muda dentro do laço. Precisa medir o tamanho dele toda vez?
3. Resposta esperada: a) O(n²): n dobra, os passos multiplicam por 4;
   b) tamanho(texto) está na condição do for, que roda n + 1 vezes, e cada
   chamada custa n passos: n(n + 1); c) guarde o tamanho numa variável
   antes do laço (int n = tamanho(texto);) e use i < n. Os passos caem para
   1000, 2000 e 4000.

```bash
~/LPEDC/rodar 10-analise/0077-big-o/E462.c
```

---

## 0078 · Invariantes de laço e corretude

Fim do expediente na lanchonete. Você confere o caixa: troco inicial mais as
vendas do dia tem que bater com o que está na gaveta. E essa conta não vale
só no fim: depois de **cada** cliente atendido, "gaveta = troco + vendas até
agora" continua verdadeiro. Se em algum momento não bater, você sabe que o
erro aconteceu ali.

Um laço funciona igual. Testar com alguns valores mostra que ele acertou
**naqueles** valores. Para ter certeza de que acerta sempre, você procura uma
frase que fica verdadeira volta após volta. Essa frase é o **invariante de
laço**: uma relação entre as variáveis que vale **no começo de cada
iteração**, logo antes do teste do laço.

Para falar de pedaços de vetor, use a notação `v[0..i-1]`: os elementos de
índice 0 até i − 1. Quando i vale 0, o pedaço está vazio. Com ela, o
invariante de "achar o maior" fica assim: **`maior` é um máximo de
`v[0..i-1]`**. Diz o que o laço já sabe, não como ele anda.

Mostrar que um laço está certo com um invariante tem quatro passos, como uma
prova por indução:

1. **Início**: o invariante vale antes da primeira volta.
2. **Manutenção**: se vale no começo de uma volta, vale no começo da
   seguinte.
3. **Término**: quando o teste falha, invariante + condição de parada dão o
   resultado que você queria.
4. **Parada**: alguma quantidade inteira diminui a cada volta e não pode
   diminuir para sempre (é a **variante**). Garante que o laço acaba.

Esse jeito de pensar também melhora a documentação. A função promete "recebe
n ≥ 1 e v; devolve o valor de **um** elemento máximo de `v[0..n-1]`". Fala de
todos os parâmetros, diz a restrição (n ≥ 1) e usa "um" porque pode haver
empate. É o contrato, sem contar o "como".

Vamos ver na prática. Os Pix do dia foram 120, 45, 300, 80, 210 e 95. No
começo da volta com i = 4, a parte verde já foi vista e o invariante garante
que `maior` (300) é o maior dela. A parte cinza ainda não importa:

<p align="center"><img src="0078-invariantes/ideia.svg" alt="Diagrama da ideia: Invariantes de laço e corretude" width="893"></p>

O `assert` de `<assert.h>` transforma o invariante em código: se a condição
for falsa, o programa para na hora e diz a linha. A função `eh_maximo` é lenta
de propósito: ela confere o invariante do jeito mais burro possível, só para
testar.

```c
#include <assert.h>
#include <stdbool.h>
#include <stdio.h>

// Devolve true se x é um máximo de v[0..i-1]: x está lá e ninguém passa dele.
bool eh_maximo(const int v[], int i, int x) {
    bool esta = false;
    for (int k = 0; k < i; k++) {
        if (v[k] > x) {
            return false;
        }
        if (v[k] == x) {
            esta = true;
        }
    }
    return esta;
}

// Recebe n >= 1 e v; devolve o valor de um elemento máximo de v[0..n-1].
int maximo(const int v[], int n) {
    int maior = v[0];
    int i = 1;
    while (i < n) {
        // invariante: maior é um máximo de v[0..i-1]
        assert(eh_maximo(v, i, maior));
        printf("i = %d: maior = %d\n", i, maior);
        if (v[i] > maior) {
            maior = v[i];
        }
        i++;
    }
    // na saída, i == n: o invariante diz que maior é um máximo de v[0..n-1]
    assert(eh_maximo(v, n, maior));
    return maior;
}

int main(void) {
    int pix[6] = {120, 45, 300, 80, 210, 95};

    printf("Maior Pix: R$ %d\n", maximo(pix, 6));
    return 0;
}
// Saída:
// i = 1: maior = 120
// i = 2: maior = 120
// i = 3: maior = 300
// i = 4: maior = 300
// i = 5: maior = 300
// Maior Pix: R$ 300
```

### Passo a passo

Os quatro passos aplicados a esse laço, com o teste de mesa do lado:

| começo da volta | i | `v[0..i-1]` | maior | invariante vale? |
| --- | --- | --- | --- | --- |
| 1ª | 1 | 120 | 120 | sim: um elemento só é o máximo dele mesmo (**início**) |
| 2ª | 2 | 120, 45 | 120 | sim: 45 não passou de 120 |
| 3ª | 3 | 120, 45, 300 | 300 | sim: 300 passou e virou o maior |
| 4ª | 4 | ..., 80 | 300 | sim |
| 5ª | 5 | ..., 210 | 300 | sim |
| teste falha | 6 | o vetor todo | 300 | sim, e i == n: é a resposta (**término**) |

**Manutenção**: se `maior` é o máximo de `v[0..i-1]`, a volta compara com
`v[i]` e fica com o maior dos dois. Então `maior` passa a ser o máximo de
`v[0..i]`, e o `i++` faz disso "o máximo de `v[0..i-1]`" de novo. **Parada**:
n − i diminui 1 por volta e o laço acaba quando chega a 0.

Repara no fluxograma: o invariante mora na seta que volta para o losango
"i < 6?". Toda vez que o caminho passa por ali, a frase é verdadeira:

<p align="center"><img src="0078-invariantes/fluxograma.svg" alt="Fluxograma: Invariantes de laço e corretude" width="593"></p>

> [!WARNING]
> O erro clássico é o **início**: `int maior = 0;` parece inofensivo e passa
> em todos os testes com valores positivos. Com saldos todos negativos (−120,
> −45, −300), a função devolve 0, um valor que nem está no vetor. O invariante
> denuncia na hora: antes da primeira volta, 0 não é um máximo de `v[0..0]`.
> Comece com `maior = v[0]` e i = 1, e escreva a restrição n ≥ 1 no contrato.

> [!TIP]
> **Por dentro do C:** `assert(cond)` é uma macro. Se `cond` for falsa, ela
> imprime arquivo, linha e a condição, e chama `abort()`. Compilando com
> `-DNDEBUG`, o pré-processador troca cada `assert` por **nada**: nem a
> condição é calculada. Por isso o `eh_maximo`, que é O(n) dentro de um laço
> O(n), deixa o teste O(n²) mas não custa nada na versão final. A regra que
> sai disso: nunca ponha dentro do `assert` algo que o programa precisa
> fazer, como `assert(fp = fopen(...))`. Com `NDEBUG`, o arquivo nem abre.

> [!NOTE]
> **Pergunta para você:** no exemplo A156 (fichas de R$ 5 com R$ 47), o
> invariante é `valor == q * ficha + r` e `r >= 0`. O que garante que o laço
> termina? E se a ficha custasse R$ 0, qual dos quatro passos falharia?

### Hora de praticar

Os arquivos ficam em [`0078-invariantes/`](0078-invariantes/). Os comandos funcionam de qualquer pasta do terminal. Nos exemplos, rode, mude, quebre e rode de novo. Nos exercícios, a resposta vai dentro do próprio arquivo. ★☆☆ é aquecimento, ★★☆ pede raciocínio e ★★★ é desafio.

**Exemplo A155 · O maior Pix do dia, com invariante**

```c
#include <assert.h>
#include <stdbool.h>
#include <stdio.h>

// Devolve true se x é um máximo de v[0..i-1]: x está lá e ninguém passa dele.
bool eh_maximo(const int v[], int i, int x) {
    bool esta = false;
    for (int k = 0; k < i; k++) {
        if (v[k] > x) {
            return false;
        }
        if (v[k] == x) {
            esta = true;
        }
    }
    return esta;
}

// Recebe n >= 1 e v; devolve o valor de um elemento máximo de v[0..n-1].
int maximo(const int v[], int n) {
    int maior = v[0];
    int i = 1;
    while (i < n) {
        // invariante: maior é um máximo de v[0..i-1]
        assert(eh_maximo(v, i, maior));
        printf("i = %d: maior = %d\n", i, maior);
        if (v[i] > maior) {
            maior = v[i];
        }
        i++;
    }
    // na saída, i == n: o invariante diz que maior é um máximo de v[0..n-1]
    assert(eh_maximo(v, n, maior));
    return maior;
}

int main(void) {
    int pix[6] = {120, 45, 300, 80, 210, 95};

    printf("Maior Pix: R$ %d\n", maximo(pix, 6));
    return 0;
}
// Saída:
// i = 1: maior = 120
// i = 2: maior = 120
// i = 3: maior = 300
// i = 4: maior = 300
// i = 5: maior = 300
// Maior Pix: R$ 300
```

```bash
~/LPEDC/rodar 10-analise/0078-invariantes/A155.c
```

**Exemplo A156 · Fichas e troco: o invariante da divisão**

```c
#include <assert.h>
#include <stdio.h>

// Com R$ 47, quantas fichas de R$ 5 dá para comprar, e quanto sobra?
// É a divisão inteira 47 / 5, feita só com subtrações.
//
// Invariante (vale no começo de cada volta): valor == q * ficha + r e r >= 0
// Variante (garante que o laço termina): r diminui a cada volta.
int main(void) {
    int valor = 47, ficha = 5;
    int q = 0;     // fichas compradas
    int r = valor; // dinheiro que sobrou

    while (r >= ficha) {
        assert(valor == q * ficha + r && r >= 0);
        r = r - ficha;
        q = q + 1;
    }
    // invariante + saída do laço (r < ficha): q é o quociente e r o resto
    assert(valor == q * ficha + r && r >= 0 && r < ficha);

    printf("%d = %d * %d + %d\n", valor, q, ficha, r);
    printf("Fichas: %d, troco: R$ %d\n", q, r);
    printf("Confere com / e %%: %d e %d\n", valor / ficha, valor % ficha);
    return 0;
}
// Saída:
// 47 = 9 * 5 + 2
// Fichas: 9, troco: R$ 2
// Confere com / e %: 9 e 2
```

```bash
~/LPEDC/rodar 10-analise/0078-invariantes/A156.c
```

#### Exercícios

**Exercício E463** · ★☆☆

Escreva o invariante de cada laço: a frase que vale no começo de cada volta,
logo antes do teste. Use a notação v[0..i-1].


```text
a) s = 0;
   for (i = 0; i < n; i++)  s = s + gastos[i];
```



```text
b) c = 0;
   for (i = 0; i < n; i++)  if (notas[i] >= 6) c++;
```



```text
c) p = 1;
   for (k = 0; k < e; k++)  p = p * 2;
```



```text
d) k = n - 1;
   while (k >= 0 && v[k] != x)  k--;
```

**Dicas:**

1. Pergunte: "o que o laço já sabe sobre a parte que ele já viu?".
2. Confira o início: com i = 0, o pedaço v[0..-1] está vazio. A soma de
   nada é 0; a contagem de nada é 0.
3. Em d), o laço anda de trás para frente: a parte já vista fica à direita
   de k.
4. Resposta esperada: a) s é a soma de gastos[0..i-1]; b) c é o número de
   notas >= 6 em notas[0..i-1]; c) p == 2 elevado a k; d) x não está em
   v[k+1..n-1].

```bash
~/LPEDC/rodar 10-analise/0078-invariantes/E463.c
```

**Exercício E464** · ★☆☆

As vendas da barraca na feira foram R$ 35, 12, 50, 8 e 27. Complete a
função soma():

1. escreva o laço que soma v[0..n-1];
2. escreva o invariante como comentário dentro do laço;
3. confira o invariante com assert, usando a função soma_ate(), que já
está pronta (ela recalcula a soma de v[0..i-1] do jeito lento).


```text
Saída esperada:
Total: R$ 132
```

**Dicas:**

1. Comece com s = 0 e i = 0. O assert vai logo no começo do corpo do laço.
2. assert(s == soma_ate(v, i));
3. Depois do laço, um último assert(s == soma_ate(v, n)) fecha o término.
4. Resposta esperada: Total: R$ 132. Invariante: s é a soma de v[0..i-1].

```bash
~/LPEDC/rodar 10-analise/0078-invariantes/E464.c
```

**Exercício E465** · ★★☆

A função ultima() procura a ÚLTIMA vez que um aluno tirou certa nota,
andando do fim para o começo. Ela já funciona (rode). Prove que está certa
com os quatro passos, usando o invariante "x não está em v[k+1..n-1]":


```text
1. início: vale antes da primeira volta?
2. manutenção: se vale no começo de uma volta, vale no começo da próxima?
3. término: o laço para por um de dois motivos. O que cada um garante?
4. parada: que quantidade diminui?
```


Escreva a prova como comentário.

**Dicas:**

1. No começo, k = n - 1. Quem é v[n..n-1]?
2. Uma volta só acontece se v[k] != x. Depois do k--, o pedaço já visto
   ganhou exatamente esse v[k].
3. Atenção à ordem do && no while: o que aconteceria se fosse
   v[k] != x && k >= 0?
4. Resposta esperada: 1) k = n - 1 e v[n..n-1] é vazio: x não está nele;
   2) a volta só roda se v[k] != x, então depois do k-- o x continua fora
   de v[k+1..n-1]; 3) se parou com k >= 0, v[k] == x e ninguém à direita é
   x: é a última ocorrência; se parou com k == -1, x não está em v[0..n-1]
   e devolver -1 é o certo; 4) k diminui 1 por volta e não passa de -1. O
   k >= 0 vem primeiro no && para nunca ler v[-1] (curto-circuito).

```bash
~/LPEDC/rodar 10-analise/0078-invariantes/E465.c
```

**Exercício E466** · ★★☆

O banco quer saber qual cliente está "menos no vermelho": o maior saldo
entre contas todas negativas. O programa compila sem aviso, passou em todos
os testes com saldos positivos, mas aqui mostra 0.


```text
Saída esperada:
Maior saldo: R$ -45
```


a) Qual dos quatro passos da prova (início, manutenção, término, parada)
falha? Mostre o momento exato.
b) Conserte sem tratar "todos negativos" como caso especial.
c) O que a função deveria exigir de n? Escreva o contrato correto.

**Dicas:**

1. Invariante pretendido: maior é um máximo de v[0..i-1]. Ele vale antes
   da primeira volta?
2. Um máximo de um pedaço tem que ser um elemento desse pedaço.
3. Resposta esperada: a) o início: antes da primeira volta (i = 0, pedaço
   vazio) maior vale 0, e depois de olhar o -120 ele continua 0, que nem
   está no vetor; o invariante "maior é um elemento máximo" nunca valeu;
   b) int maior = v[0]; e o laço começa em i = 1; c) "recebe n >= 1 e v;
   devolve o valor de um elemento máximo de v[0..n-1]".

```bash
~/LPEDC/rodar 10-analise/0078-invariantes/E466.c
```

**Exercício E467** · ★★★

Escreva int lg(int n), que devolve o piso de log₂ n (o maior i com
2 elevado a i <= n), para n >= 1, SEM math.h: divida n por 2 até chegar a
1, contando as divisões.

Escreva o invariante como comentário e prove o término. Depois teste: mostre
lg de 1, 10, 1000, 1024 e 100000, e compare lg(n) com floor(log2(n)) de
math.h para todo n de 1 a 100000, contando as divergências.


```text
Saída esperada:
lg(1) = 0
lg(10) = 3
lg(1000) = 9
lg(1024) = 10
lg(100000) = 16
divergências de 1 a 100000: 0
```

**Dicas:**

1. Use uma cópia m de n e um contador i: i = 0, m = n; enquanto m > 1,
   m = m / 2 e i++.
2. Invariante: (2 elevado a i) * m <= n < (2 elevado a i) * (m + 1). Teste
   com n = 10: (i, m) passa por (0, 10), (1, 5), (2, 2), (3, 1).
3. No término, m == 1: o invariante vira 2^i <= n < 2^(i+1).
4. Resposta esperada: a saída acima. Parada: m cai pelo menos pela metade
   a cada volta e o laço para quando chega a 1.

```bash
~/LPEDC/rodar 10-analise/0078-invariantes/E467.c
```

**Exercício E468** · ★★★

O vetor de pedidos do dia tem valores em reais, e os cancelados aparecem
como 0. Escreva int remove_zeros(int v[], int n), que tira os zeros do
vetor, mantendo a ordem dos outros, e devolve quantos sobraram. Regras:
sem vetor auxiliar e numa passada só (O(n)).

Escreva o invariante do seu laço como comentário e confira com o vetor
{25, 0, 0, 40, 0, 15, 30, 0}.


```text
Saída esperada:
Sobraram 4: 25 40 15 30
```

**Dicas:**

1. Use dois índices: j lê todos os elementos; i marca onde escrever o
   próximo que não é zero.
2. Invariante: i <= j e v[0..i-1] são os valores não nulos de v[0..j-1]
   original, na mesma ordem.
3. Se v[j] != 0, copie para v[i] e avance i. Avance j sempre.
4. Resposta esperada: Sobraram 4: 25 40 15 30. Uma versão que "puxa" todo
   mundo uma casa para a esquerda a cada zero também funciona, mas é O(n²).

```bash
~/LPEDC/rodar 10-analise/0078-invariantes/E468.c
```

---

## 0079 · TAD: interface (.h) e implementação (.c)

Na entrada do estacionamento do shopping tem um painel: "VAGAS LIVRES: 3". A
cancela só abre se houver vaga. Você não sabe se o sistema conta com sensor no
chão, câmera ou planilha, e não precisa saber. Você só usa três "botões":
entrar, sair e ver quantas vagas sobram.

Um **tipo abstrato de dado** (TAD) é isso no código: um tipo definido pelas
**operações** que ele oferece, não pelo jeito como guarda os dados. Quem usa (o
**cliente**) conhece só as operações. Quem implementa pode trocar tudo por
dentro sem avisar ninguém, desde que as operações continuem cumprindo o
prometido.

No TypeScript você faz isso com uma `class` de campos `#privados` ou com um
módulo que exporta só funções. No C, a divisão é física, em dois arquivos:

- **`contador.h`, a interface**: o contrato. Declara o tipo e os protótipos,
  cada um com um comentário dizendo o que entra, o que sai e o que pode dar
  errado. É o que o cliente inclui.
- **`contador.c`, a implementação**: define a `struct` com os campos e escreve
  as funções. O cliente nunca inclui este arquivo; ele só é compilado junto.

O truque que fecha a porta é o **tipo opaco**. O `.h` diz apenas
`typedef struct contador Contador;`, sem os campos. Para o compilador, no
cliente, `struct contador` é um **tipo incompleto**: dá para ter um ponteiro
`Contador *`, mas não dá para criar uma variável `Contador`, nem usar
`sizeof`, nem acessar `->valor`. Por isso todo TAD opaco tem uma função
`_cria`, que faz o `malloc` lá dentro, e uma `_libera`, que faz o `free`.

Fechar a porta não é burocracia: é o que permite ao TAD garantir um
**invariante**, como no assunto anterior. O contador promete
`0 <= valor <= limite`. Se o cliente pudesse escrever `vagas->valor = 99`, a
promessa não valeria nada.

Vamos ver na prática. O cliente `A157.c` inclui só o contrato. O `contador.c`
também inclui o contrato e guarda a `struct` escondida. Na memória, o cliente
tem só um ponteiro para um bloco no heap que ele não consegue abrir:

<p align="center"><img src="0079-tad/ideia.svg" alt="Diagrama da ideia: TAD: interface (.h) e implementação (.c)" width="870"></p>

O contrato, completo, está em `contador.h` na pasta do assunto. O cliente
estaciona 4 carros num lugar com 3 vagas:

```c
#include <stdio.h>

#include "contador.h" // só a interface: a struct está escondida em contador.c

int main(void) {
    Contador *vagas = contador_cria(3); // estacionamento com 3 vagas
    if (vagas == NULL) {
        printf("Sem memória\n");
        return 1;
    }

    const char *placas[4] = {"RIO2A18", "SPX3B45", "BHZ7C09", "CWB1D77"};
    for (int i = 0; i < 4; i++) {
        if (contador_incrementa(vagas)) {
            printf("%s entrou (%d/%d)\n", placas[i], contador_valor(vagas),
                   contador_limite(vagas));
        } else {
            printf("%s: lotado, espere\n", placas[i]);
        }
    }

    contador_decrementa(vagas); // um carro sai
    printf("Um carro saiu (%d/%d)\n", contador_valor(vagas), contador_limite(vagas));

    if (contador_incrementa(vagas)) {
        printf("CWB1D77 entrou (%d/%d)\n", contador_valor(vagas), contador_limite(vagas));
    }

    contador_libera(vagas);
    return 0;
}
// Saída:
// RIO2A18 entrou (1/3)
// SPX3B45 entrou (2/3)
// BHZ7C09 entrou (3/3)
// CWB1D77: lotado, espere
// Um carro saiu (2/3)
// CWB1D77 entrou (3/3)
```

E o lado escondido, em `contador.c`. Repare que ele inclui o próprio `.h`:
assim o compilador confere que cada função bate com o protótipo prometido.

```c
#include <stdlib.h>

#include "contador.h"

// Invariante da struct: 0 <= valor <= limite e limite >= 1.
struct contador {
    int valor;
    int limite;
};

Contador *contador_cria(int limite) {
    if (limite < 1) {
        return NULL;
    }
    Contador *c = malloc(sizeof *c);
    if (c == NULL) {
        return NULL;
    }
    c->valor = 0;
    c->limite = limite;
    return c;
}

bool contador_incrementa(Contador *c) {
    if (c->valor == c->limite) {
        return false; // recusa em vez de quebrar o invariante
    }
    c->valor++;
    return true;
}
// ... contador_libera, contador_decrementa, contador_zera,
//     contador_valor e contador_limite seguem o mesmo estilo
```

Repara no fluxograma: o cliente só conversa com o TAD pelas funções. Quem
decide "lotado" é o `contador_incrementa`, que devolve `false`. O cliente só
reage à resposta:

<p align="center"><img src="0079-tad/fluxograma.svg" alt="Fluxograma: TAD: interface (.h) e implementação (.c)" width="679"></p>

### O padrão dos próximos módulos

Toda estrutura de dados dos módulos 11 a 16 (lista, pilha, fila, árvore, hash,
grafo) segue este molde. Para um TAD `x`:

1. **Pasta do assunto**: `x.h`, `x.c` e os exemplos `A###.c`. O `rodar`
   compila junto todo `.c` da pasta que não se chama `A000.c`/`E000.c`. À mão:
   `gcc A157.c contador.c -o a157`.
2. **`x.h`**: comentário dizendo o que o TAD é; *include guard*
   (`#ifndef X_H`); só os `#include` de que a interface precisa (em geral
   `<stdbool.h>`); `typedef struct x X;`; protótipos com prefixo `x_`, cada um
   com o seu contrato em comentário.
3. **`x.c`**: inclui as bibliotecas e o próprio `"x.h"`; define a `struct x`
   com o invariante comentado em cima; funções auxiliares internas são
   `static` (ficam invisíveis fora do arquivo).
4. **Nomes das operações**: `x_cria` (devolve `NULL` se faltar memória),
   `x_libera` (aceita `NULL`), e verbos no presente para o resto:
   `x_insere`, `x_remove`, `x_valor`. Leitura recebe `const X *`.
5. **Erros**: operação que pode falhar devolve `bool`; valor de saída vai por
   ponteiro (`bool pilha_desempilha(Pilha *p, int *valor)`). O TAD não
   imprime mensagem de erro: quem decide o que mostrar é o cliente.
6. **Cliente**: `#include "x.h"` com aspas, guarda só `X *`, confere o `NULL`
   do `_cria` e chama `_libera` no fim. Nunca usa `->` num `X`.

> [!WARNING]
> Se o cliente tentar `vagas->valor = 0;` ou `Contador c;`, o erro é de
> **compilação**: `invalid use of incomplete typedef 'Contador'`. É o tipo
> opaco funcionando, não um defeito. Não "conserte" movendo a `struct` para o
> `.h`: aí qualquer cliente volta a poder quebrar o invariante. Se falta uma
> operação, acrescente uma função na interface. O outro tropeço clássico é
> esquecer o `contador.c` na hora de compilar à mão: o erro vira
> `undefined reference to 'contador_cria'`, que é do **ligador**.

> [!TIP]
> **Por dentro do C:** o `#include "contador.h"` é só colar texto. Depois do
> pré-processador, o cliente tem os protótipos e a frase "existe uma
> `struct contador`", mais nada. O compilador gera `A157.o` sem saber o
> tamanho da struct (nem precisa: ponteiro tem sempre 8 bytes numa máquina de
> 64 bits). O `contador.o` sabe o tamanho e os deslocamentos dos campos
> (`valor` no byte 0, `limite` no byte 4). O ligador junta os dois. Por isso
> mudar a struct exige recompilar só o `contador.c`: o binário do cliente nem
> muda.

> [!NOTE]
> **Pergunta para você:** no exemplo A158, a conta guarda o saldo em
> centavos (`int`), e não em reais (`double`). Por quê? E se o banco quisesse
> trocar para `long long` amanhã, quais arquivos mudariam: `conta.h`,
> `conta.c` ou o cliente?

### Hora de praticar

Os arquivos ficam em [`0079-tad/`](0079-tad/). Os comandos funcionam de qualquer pasta do terminal. Nos exemplos, rode, mude, quebre e rode de novo. Nos exercícios, a resposta vai dentro do próprio arquivo. ★☆☆ é aquecimento, ★★☆ pede raciocínio e ★★★ é desafio.

**Exemplo A157 · A cancela do estacionamento**

```c
#include <stdio.h>

#include "contador.h" // só a interface: a struct está escondida em contador.c

int main(void) {
    Contador *vagas = contador_cria(3); // estacionamento com 3 vagas
    if (vagas == NULL) {
        printf("Sem memória\n");
        return 1;
    }

    const char *placas[4] = {"RIO2A18", "SPX3B45", "BHZ7C09", "CWB1D77"};
    for (int i = 0; i < 4; i++) {
        if (contador_incrementa(vagas)) {
            printf("%s entrou (%d/%d)\n", placas[i], contador_valor(vagas),
                   contador_limite(vagas));
        } else {
            printf("%s: lotado, espere\n", placas[i]);
        }
    }

    contador_decrementa(vagas); // um carro sai
    printf("Um carro saiu (%d/%d)\n", contador_valor(vagas), contador_limite(vagas));

    if (contador_incrementa(vagas)) {
        printf("CWB1D77 entrou (%d/%d)\n", contador_valor(vagas), contador_limite(vagas));
    }

    contador_libera(vagas);
    return 0;
}
// Saída:
// RIO2A18 entrou (1/3)
// SPX3B45 entrou (2/3)
// BHZ7C09 entrou (3/3)
// CWB1D77: lotado, espere
// Um carro saiu (2/3)
// CWB1D77 entrou (3/3)
//
// Compilando à mão, sem o rodar: gcc A157.c contador.c -o a157
```

```bash
~/LPEDC/rodar 10-analise/0079-tad/A157.c
```

**Exemplo A158 · A conta que nunca fica negativa**

```c
#include <stdbool.h>
#include <stdio.h>

#include "conta.h"

// Mostra o resultado de uma operação e o saldo em reais.
void mostra(const Conta *c, const char *operacao, bool deu_certo) {
    int s = conta_saldo(c);
    printf("%-6s saldo R$ %3d,%02d  (%s)\n", deu_certo ? "ok" : "negado", s / 100,
           s % 100, operacao);
}

int main(void) {
    Conta *ana = conta_cria("Ana Souza");
    if (ana == NULL) {
        printf("Sem memória\n");
        return 1;
    }
    printf("Conta de %s\n", conta_titular(ana));

    mostra(ana, "depósito 150,00", conta_deposita(ana, 15000));
    mostra(ana, "saque 49,90", conta_saca(ana, 4990));
    mostra(ana, "saque 200,00", conta_saca(ana, 20000)); // não cobre: negado
    mostra(ana, "depósito -10,00", conta_deposita(ana, -1000)); // inválido
    mostra(ana, "saque 100,10", conta_saca(ana, 10010)); // zera certinho

    // ana->saldo = 1000000;  // não compila: o cliente não vê os campos
    conta_libera(ana);
    return 0;
}
// Saída:
// Conta de Ana Souza
// ok     saldo R$ 150,00  (depósito 150,00)
// ok     saldo R$ 100,10  (saque 49,90)
// negado saldo R$ 100,10  (saque 200,00)
// negado saldo R$ 100,10  (depósito -10,00)
// ok     saldo R$   0,00  (saque 100,10)
```

```bash
~/LPEDC/rodar 10-analise/0079-tad/A158.c
```

#### Exercícios

**Exercício E469** · ★☆☆

Use o TAD Contador desta pasta (leia o contador.h; não abra o contador.c)
para controlar a lotação de uma van escolar de 4 lugares:

1. crie o contador e confira o NULL;
2. 6 alunos tentam subir: conte quantos subiram e quantos ficaram no ponto;
3. na escola, 3 descem; mostre quantos ficaram a bordo;
4. na garagem, zere o contador, mostre e libere.


```text
Saída esperada:
Subiram 4, ficaram no ponto 2
Depois de descerem 3: 1 a bordo
Na garagem: 0 a bordo
```

**Dicas:**

1. #include "contador.h", com aspas: o arquivo está na pasta, não no
   sistema. O rodar compila o contador.c junto.
2. contador_incrementa devolve false quando a van está cheia: use isso
   para contar quem ficou no ponto.
3. Resposta esperada: a saída acima. Repare que você não precisou saber
   como o contador guarda o valor.

```bash
~/LPEDC/rodar 10-analise/0079-tad/E469.c
```

**Exercício E470** · ★☆☆

Este cliente NÃO COMPILA, de propósito. Ele controla as senhas da fila da
lotérica e tenta mexer direto nos campos do contador. Rode, leia o erro do
gcc e responda:

a) O que quer dizer "invalid use of incomplete typedef"?
b) Por que o autor do TAD quis que isso desse erro?

Depois conserte usando só as funções do contador.h.


```text
Saída esperada:
Na fila: 2
Na fila: 0
```

**Dicas:**

1. O contador.h só diz que existe uma struct contador, sem os campos.
2. Procure no contador.h uma função que zera e outra que lê o valor.
3. Resposta esperada: a) no cliente, struct contador é um tipo incompleto:
   o compilador não sabe os campos nem o tamanho, então não deixa usar ->;
   b) para proteger o invariante 0 <= valor <= limite: só o contador.c
   mexe nos campos. Conserto: contador_valor(fila) para ler e
   contador_zera(fila) para zerar.

```bash
~/LPEDC/rodar 10-analise/0079-tad/E470.c
```

**Exercício E471** · ★★☆

Escreva um TAD Ponto para o app de entregas, com estas operações:


```text
Ponto *ponto_cria(double x, double y);   // NULL se faltar memória
void ponto_libera(Ponto *p);
double ponto_x(const Ponto *p);
double ponto_y(const Ponto *p);
double ponto_distancia(const Ponto *a, const Ponto *b);
```


Num projeto de verdade seriam ponto.h e ponto.c. Aqui, para o exercício
ficar num arquivo só, separe as três partes com comentários: "ponto.h"
(typedef e protótipos), "ponto.c" (struct e funções) e "cliente" (main).
No main, use só as funções, nunca os campos: loja em (0, 0), cliente em
(3, 4); depois um ponto A em (-2, 1) e um ponto B em (4, 9). Distâncias em
km.


```text
Saída esperada:
Loja (0.0, 0.0) -> cliente (3.0, 4.0): 5.00 km
A -> B: 10.00 km
```

**Dicas:**

1. Distância: sqrt(dx * dx + dy * dy), com sqrt de <math.h>.
2. typedef struct ponto Ponto; em cima, a struct ponto { double x, y; }
   só na parte "ponto.c".
3. São 4 pontos criados: 4 ponto_libera no fim (o rodar acusa vazamento).
4. Resposta esperada: a saída acima (os triângulos 3-4-5 e 6-8-10).

```bash
~/LPEDC/rodar 10-analise/0079-tad/E471.c
```

**Exercício E472** · ★★☆

O TAD Conta desta pasta (conta.h) não tem transferência. Você não pode
mexer no conta.c nem no conta.h. Escreva, no cliente, a função


```text
bool transfere(Conta *de, Conta *para, int centavos);
```


que só move o dinheiro se der para sacar da origem, e devolve se deu certo.
Teste com um Pix da Bia para o Caio: a Bia tem R$ 80,00 e o Caio, R$ 10,00.
Primeiro ela tenta mandar R$ 100,00; depois, R$ 35,50.


```text
Saída esperada:
Pix de R$ 100,00: negado
Pix de R$ 35,50: ok
Bia: R$ 44,50 | Caio: R$ 45,50
```

**Dicas:**

1. Saque primeiro. Só deposite se o saque deu certo; assim ninguém ganha
   dinheiro do nada.
2. Os valores são centavos: R$ 35,50 é 3550.
3. Para mostrar: saldo / 100 e saldo % 100 com %02d.
4. Resposta esperada: a saída acima. Repare que a nova operação respeita o
   invariante (saldo >= 0) de graça, porque só usa operações que já o
   respeitam.

```bash
~/LPEDC/rodar 10-analise/0079-tad/E472.c
```

**Exercício E473** · ★★★

A receita pede 1/2 xícara de leite e depois mais 1/3. Escreva um TAD
Racional (fração), num arquivo só, separado em "racional.h", "racional.c" e
"cliente", com o invariante: denominador > 0 e fração sempre simplificada
(mdc(|num|, den) == 1). Operações:


```text
Racional *racional_cria(int num, int den);  // NULL se den == 0
void racional_libera(Racional *r);
Racional *racional_soma(const Racional *a, const Racional *b);
Racional *racional_multiplica(const Racional *a, const Racional *b);
void racional_imprime(const Racional *r);   // ex.: 5/6
```


No cliente, mostre: 1/2 + 1/3; 2/4 (já simplificado); 3/-6; (1/2) * (2/3);
e tente criar 1/0.


```text
Saída esperada:
1/2 + 1/3 = 5/6
2/4 vira 1/2
3/-6 vira -1/2
1/2 * 2/3 = 1/3
1/0: não existe
```

**Dicas:**

1. Toda criação passa por racional_cria, que simplifica e acerta o sinal.
   Assim soma e multiplica só fazem a conta e chamam racional_cria.
2. a/b + c/d = (a*d + c*b) / (b*d). O mdc vem de Euclides (assunto 0038)
   e pode ser uma função static.
3. Denominador negativo: troque o sinal dos dois.
4. Cada Racional devolvido é um malloc: libere todos.
5. Resposta esperada: a saída acima.

```bash
~/LPEDC/rodar 10-analise/0079-tad/E473.c
```

**Exercício E474** · ★★★

O TAD Horario abaixo guarda a hora e o minuto em dois campos. Reescreva SÓ
a parte "horario.c" para guardar um campo único: os minutos desde a
meia-noite (0 a 1439). A parte "horario.h" e o cliente (main) não podem
mudar nem uma letra, e a saída tem de continuar idêntica:


```text
Saída esperada:
Ônibus sai às 22:50
Viagem de 85 min: chega às 00:15
Do embarque até 06:00: 430 min
```


Depois responda: qual das duas versões deixou horario_minutos_ate mais
simples? E o que isso mostra sobre esconder a struct?

**Dicas:**

1. h:m vira h * 60 + m. De volta: hora = total / 60, minuto = total % 60.
2. Avançar com a volta do dia: total = (total + minutos) % 1440.
3. Diferença para a frente: (b - a + 1440) % 1440.
4. Resposta esperada: a mesma saída. A versão com minutos totais deixa
   avanca e minutos_ate com uma linha cada; hora e minuto viram contas.
   Como o cliente só usa as funções, a troca não o afeta: é a promessa do
   TAD.

```bash
~/LPEDC/rodar 10-analise/0079-tad/E474.c
```

---

## Desafios do módulo

Problemas que misturam os quatro assuntos, do médio ao difícil. Alguns pedem
código; outros, só papel.

**1. Convidados em comum.** Você tem a lista de convidados do seu aniversário
(n nomes) e a do seu amigo (m nomes) e quer saber quem está nas duas. Quantas
comparações faz o jeito "cada nome meu contra cada nome dele"? E se as duas
listas estiverem em ordem alfabética?

<details><summary>Resposta</summary>

O jeito ingênuo faz **n · m** comparações: O(n · m), O(n²) se forem do mesmo
tamanho. Com as duas ordenadas, ande com um índice em cada lista, como numa
intercalação: compare os dois nomes da vez e avance o menor. Cada comparação
avança pelo menos um índice, então são no máximo **n + m** comparações: O(n).

</details>

**2. O cronômetro dedurou.** Um relatório leva 2 s com 1 milhão de linhas e
8 s com 2 milhões. Qual a classe O provável? Quanto ele vai levar com 4
milhões?

<details><summary>Resposta</summary>

Dobrou n, o tempo multiplicou por 4: **O(n²)**. Com 4 milhões, mais um
dobro: 8 × 4 = **32 s**. É a regra do dobro do E460 aplicada a tempo em vez de
passos.

</details>

**3. Um milhão de CPFs.** Num vetor ordenado de 1.000.000 de CPFs, quantas
comparações a busca binária faz no pior caso? E a sequencial?

<details><summary>Resposta</summary>

A binária corta pela metade a cada comparação: 2²⁰ = 1.048.576 ≥ 1.000.000,
então **20 comparações** (mais ou menos uma, conforme o detalhe da
implementação). A sequencial, no pior caso, **1.000.000**. É a tabela de
O(log n) contra O(n) do assunto 0077, com números de verdade.

</details>

**4. A conta da pergunta.** No assunto 0077: um algoritmo O(n²) leva 1 s com
10.000 pedidos. Quanto leva com 100.000? E um O(n log n) que também leva 1 s
com 10.000?

<details><summary>Resposta</summary>

O(n²): n multiplicou por 10, o tempo por 10² = **100 s**. O(n log n): o tempo
multiplica por 10 × (log 100.000 / log 10.000) = 10 × 5/4 = **12,5 s**. A base
do log não importa, porque ela se cancela na divisão.

</details>

**5. Soma dos dígitos com invariante.** Escreva uma função que soma os dígitos
de n ≥ 0 tirando o último dígito com `% 10` e `/ 10`. Enuncie o invariante e
teste com 4096.

<details><summary>Resposta</summary>

Com `m` começando em n e `soma` em 0, o invariante é
**soma + (soma dos dígitos de m) == soma dos dígitos de n**. Cada volta passa
o último dígito de `m` para `soma`, então a igualdade continua valendo. Quando
`m` chega a 0, a soma dos dígitos de `m` é 0 e `soma` é a resposta. A variante
é `m`, que cai a cada volta. Para 4096: 4 + 0 + 9 + 6 = **19**.

</details>

**6. Potência em O(log n).** Calcule 3¹³ sem fazer 12 multiplicações:
enquanto o expoente `e` for maior que 0, se `e` for ímpar multiplique o
resultado `r` pela base `b`; depois `b = b * b` e `e = e / 2`. Qual é o
invariante? Quantas voltas o laço dá?

<details><summary>Resposta</summary>

Invariante: **r · bᵉ == 3¹³** (com r = 1, b = 3 e e = 13 no começo, vale). O
expoente passa por 13, 6, 3, 1 e 0: **4 voltas**, e o resultado é
**1.594.323**. O expoente cai pela metade a cada volta, então o laço é
O(log e), contra O(e) do jeito ingênuo.

</details>

**7. Projete antes de codar.** Escreva só o `fila_senhas.h` de um TAD para as
senhas de atendimento do banco: tirar senha, chamar a próxima, ver quantas
pessoas esperam. Siga o padrão do assunto 0079, com o contrato de cada função.

<details><summary>Resposta</summary>

Uma resposta possível: `typedef struct fila_senhas FilaSenhas;`,
`FilaSenhas *fila_senhas_cria(void);` (NULL se faltar memória),
`void fila_senhas_libera(FilaSenhas *f);`,
`int fila_senhas_tira(FilaSenhas *f);` (devolve o número da nova senha),
`bool fila_senhas_chama(FilaSenhas *f, int *senha);` (false se ninguém espera)
e `int fila_senhas_esperando(const FilaSenhas *f);`. Repare que nada no `.h`
diz se é vetor ou lista: isso é problema do `.c` (e do módulo 12).

</details>

**8. O contrato fala de custo?** Duas implementações do mesmo `contador.h`:
uma guarda o valor num `int`; a outra guarda o horário de cada entrada num
vetor e, em `contador_valor`, conta as entradas. As duas cumprem o contrato?
Qual a diferença para quem usa?

<details><summary>Resposta</summary>

As duas cumprem: devolvem o mesmo valor. Mas a primeira tem `contador_valor`
em **O(1)** e a segunda em **O(n)**. Um cliente que chama `contador_valor`
dentro de um laço passa de O(n) para O(n²) sem mudar uma linha. Por isso boas
bibliotecas documentam o custo junto com o contrato (a biblioteca padrão do
C++ faz isso em cada operação).

</details>

**9. O par que soma 100.** Num vetor de n preços, você procura o primeiro par
(i < j) com `v[i] + v[j] == 100` usando dois laços e para no primeiro achado.
Qual o melhor caso, o pior caso e a classe O que se costuma dar?

<details><summary>Resposta</summary>

Melhor caso: os dois primeiros já somam 100, **1 comparação**, O(1). Pior
caso: não existe par, todos os n(n − 1)/2 pares são testados, **O(n²)**. A
classe que se dá é a do pior caso: O(n²). O `break` melhora a média, não a
garantia.

</details>

**10. Maior e menor de uma vez.** Achar o maior e o menor de n números com
dois laços separados custa 2n − 2 comparações. Existe um jeito com cerca de
3n/2: pegue os números de dois em dois, compare os dois entre si e só depois
compare o maior do par com o maior geral e o menor do par com o menor geral.
Implemente com contador e confira para n = 10.

<details><summary>Resposta</summary>

Para n = 10: o jeito separado faz **18** comparações; o de pares, **13**
(1 para o primeiro par e 3 para cada um dos outros 4 pares: 3n/2 − 2). As duas
são O(n): a notação O não enxerga a diferença, mas o contador enxerga. É o
lembrete do assunto 0076: a constante importa quando n é fixo.

</details>

## Para ler mais

- FEOFILOFF, P. *Algoritmos em linguagem C*. Rio de Janeiro: Elsevier, 2009. Partes sobre documentação, invariantes e análise de algoritmos. Disponível em: <https://www.ime.usp.br/~pf/algoritmos/>.
- CELES, W.; RANGEL, J. L. *Apostila de estruturas de dados*. Rio de Janeiro: PUC-Rio, Departamento de Informática, 2002. Cap. 9: tipos abstratos de dados.
- CELES, W.; CERQUEIRA, R.; RANGEL, J. L. *Introdução a estruturas de dados: com técnicas de programação em C*. Rio de Janeiro: Elsevier, 2004.
- TENENBAUM, A. M.; LANGSAM, Y.; AUGENSTEIN, M. J. *Estruturas de dados usando C*. São Paulo: Makron Books, 1995. Cap. 1 (tipos abstratos de dados) e seção 6.1 (eficiência e notação O).
- DEITEL, P.; DEITEL, H. *C: como programar*. 6. ed. São Paulo: Pearson Prentice Hall, 2011. Cap. 6: busca e ordenação de vetores.
- ROCHA, A. M. A.; BORGES, A. R. O. S. *Programação, estruturas de dados e algoritmos em C*. Aveiro: Universidade de Aveiro, Departamento de Eletrônica e Telecomunicações. Cap. 5: memórias e programação modular.
- CORMEN, T. H. et al. *Algoritmos: teoria e prática*. 3. ed. Rio de Janeiro: Elsevier, 2012. Cap. 2 (invariantes de laço) e cap. 3 (crescimento de funções).
- KERNIGHAN, B. W.; RITCHIE, D. M. *C: a linguagem de programação padrão ANSI*. Rio de Janeiro: Campus, 1989. Seção 4.5: arquivos de cabeçalho.
- CPPREFERENCE. *assert*. Disponível em: <https://en.cppreference.com/w/c/error/assert>.
