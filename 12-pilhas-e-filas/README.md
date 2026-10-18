<!-- Gerado por _gerador. Para mudar este arquivo, edite _gerador/modulos/12-pilhas-e-filas/ e rode: cd _gerador && npm run gerar -->

# Módulo 12 · Pilhas e filas

A lista encadeada do módulo 11 deixa você inserir e remover em qualquer
lugar. Este módulo faz o contrário: **proíbe**. Uma pilha só mexe no topo;
uma fila só entra por um lado e sai pelo outro. Parece perda, mas é a
restrição que dá a garantia: o desfazer sempre desfaz o último passo, e quem
chegou primeiro sempre é atendido primeiro.

Você usa essas estruturas o dia inteiro sem ver. A pilha de chamadas do seu
programa, o Ctrl+Z, o botão Voltar e o *parser* do TypeScript são pilhas. O
*event loop* do Node, a fila de jobs do seu backend e a impressora do
escritório são filas. Aqui você constrói as duas do zero, cada uma de dois
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
   As dicas ficam escondidas: abra só se travar.

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
assunto 0079.

Cada pasta de assunto traz os arquivos do TAD ao lado dos exemplos:
`pilha.h` e `pilha.c`, `fila.h` e `fila.c` ou `deque.h` e `deque.c`. O
`rodar` compila esses `.c` de apoio junto com qualquer exemplo ou exercício
da pasta, então basta:

```bash
~/LPEDC/rodar 12-pilhas-e-filas/0087-pilha/A173.c
```

Por isso, num exercício, **não** crie funções com os nomes do TAD
(`pilha_cria`, `fila_insere`...): o ligador reclamaria de definição
duplicada. Os exercícios que pedem uma estrutura diferente usam outros nomes
e trazem tudo no próprio arquivo.

| # | Assunto | Pasta |
| --- | --- | --- |
| [0087](#0087--pilha) | Pilha | [`0087-pilha/`](0087-pilha/) |
| [0088](#0088--pilha-encadeada) | Pilha encadeada | [`0088-pilha-encadeada/`](0088-pilha-encadeada/) |
| [0089](#0089--pilha-na-prática-parênteses-e-notação-pós-fixa) | Pilha na prática: parênteses e notação pós-fixa | [`0089-pilha-aplicacoes/`](0089-pilha-aplicacoes/) |
| [0090](#0090--fila) | Fila | [`0090-fila/`](0090-fila/) |
| [0091](#0091--fila-encadeada) | Fila encadeada | [`0091-fila-encadeada/`](0091-fila-encadeada/) |
| [0092](#0092--deque) | Deque | [`0092-deque/`](0092-deque/) |
| [0093](#0093--juntando-tudo-a-calculadora-de-expressões) | Juntando tudo: a calculadora de expressões | [`0093-juntando-tudo/`](0093-juntando-tudo/) |

---

## 0087 · Pilha

Você monta o pedido no app de delivery: pizza, refrigerante, pudim. Bateu o
arrependimento e você toca em "desfazer". Sai o pudim, o último que entrou.
Ninguém espera que o desfazer apague a pizza lá do começo.

Esse comportamento tem nome: **pilha** (*stack*). Só uma ponta está ao seu
alcance, o **topo**. Tudo entra por cima e sai por cima, então o último a
entrar é o primeiro a sair: **LIFO** (*last in, first out*). É a pilha de
pratos do restaurante por quilo, o Ctrl+Z do editor, o botão Voltar do
navegador e a pilha de chamadas que você viu no assunto 0036.

As operações são poucas, e é isso que dá força à pilha:

- **empilhar** (*push*): põe um item no topo;
- **desempilhar** (*pop*): tira o item do topo e devolve o valor;
- **olhar o topo** (*peek*): lê o topo sem tirar;
- **vazia?**: pergunta se ainda tem alguma coisa.

No JS, um array já faz isso: `pedido.push(2590)` e `pedido.pop()`. No C não
existe nada pronto, então você monta a pilha como um **TAD** (assunto 0079):
o `pilha.h` diz **o que** a pilha faz e o `pilha.c` decide **como**. Quem usa
só inclui o `.h`:

```c
typedef struct pilha Pilha; // tipo opaco: os campos ficam no pilha.c

Pilha *pilha_cria(void);                     // pilha vazia (NULL se faltar memória)
void pilha_libera(Pilha *p);                 // devolve toda a memória da pilha
bool pilha_vazia(const Pilha *p);            // true se não tem nada
int pilha_tamanho(const Pilha *p);           // quantos itens tem
bool pilha_empilha(Pilha *p, int valor);     // push: false se não coube
bool pilha_desempilha(Pilha *p, int *valor); // pop: false se estava vazia
bool pilha_topo(const Pilha *p, int *valor); // peek: olha o topo sem tirar
```

Repare no `bool` de volta. O valor desempilhado vem pelo ponteiro, e o retorno
só diz se deu certo. Tirar de uma pilha vazia (**underflow**) é erro de lógica
de quem chamou. Empilhar numa pilha cheia (**overflow**) só acontece porque o
vetor tem tamanho fixo.

Por dentro, a versão deste assunto usa um **vetor** e um contador `n`. O fundo
fica em `itens[0]`, o topo em `itens[n - 1]`, e `n` é a próxima vaga. O trecho
que importa do [`pilha.c`](0087-pilha/pilha.c):

```c
struct pilha {
    int itens[CAPACIDADE]; // CAPACIDADE = 100
    int n;                 // quantos itens estão na pilha
};

bool pilha_empilha(Pilha *p, int valor) {
    if (p->n == CAPACIDADE) {
        return false; // cheia: estouro (overflow)
    }
    p->itens[p->n] = valor;
    p->n++;
    return true;
}

bool pilha_desempilha(Pilha *p, int *valor) {
    if (p->n == 0) {
        return false; // vazia: nada para tirar (underflow)
    }
    p->n--;
    *valor = p->itens[p->n]; // o valor continua no vetor, mas saiu da pilha
    return true;
}
```

Vamos ver na prática. Os três preços entram em centavos (2590, 800 e 1200),
um em cima do outro. No vetor, ocupam as gavetas 0, 1 e 2, e `n` vale 3. O
desfazer tira o 1200 do topo:

<p align="center"><img src="0087-pilha/ideia.svg" alt="Diagrama da ideia: Pilha" width="858"></p>

O programa do pedido. Ele não sabe que existe um vetor lá dentro: só conversa
com as funções do `pilha.h`:

```c
#include <stdio.h>
#include "pilha.h"

int main(void) {
    Pilha *pedido = pilha_cria();
    if (pedido == NULL) {
        return 1;
    }

    // preços em centavos: inteiro não tem erro de arredondamento
    pilha_empilha(pedido, 2590); // pizza: R$ 25,90
    pilha_empilha(pedido, 800);  // refrigerante: R$ 8,00
    pilha_empilha(pedido, 1200); // pudim: R$ 12,00

    int preco;
    if (pilha_desempilha(pedido, &preco)) { // "desfazer": sai o último que entrou
        printf("Desfeito: R$ %d,%02d\n", preco / 100, preco % 100);
    }
    if (pilha_topo(pedido, &preco)) { // só olha, não tira
        printf("Agora no topo: R$ %d,%02d\n", preco / 100, preco % 100);
    }
    printf("Itens no pedido: %d\n", pilha_tamanho(pedido));

    pilha_libera(pedido);
    return 0;
}
// Saída:
// Desfeito: R$ 12,00
// Agora no topo: R$ 8,00
// Itens no pedido: 2
```

Repara no fluxograma do desfazer: a primeira coisa é perguntar se a pilha está
vazia. Só depois `n` diminui e o valor é lido:

<p align="center"><img src="0087-pilha/fluxograma.svg" alt="Fluxograma: Pilha" width="506"></p>

> [!WARNING]
> A ordem de `n--` e da leitura é o erro clássico. Se você lê `itens[n]` antes
> de diminuir `n`, pega a gaveta **vazia** logo acima do topo: lixo, ou um
> valor velho que já tinha saído. Fixe a convenção e não misture: aqui `n` é a
> próxima vaga (empilha em `itens[n]` e depois `n++`; desempilha com `n--` e
> depois lê). Muito livro usa `topo = -1` para pilha vazia, e aí o topo é
> `itens[topo]`. As duas funcionam. Misturar as duas não.

> [!TIP]
> **Por dentro do C:** desempilhar **não apaga** nada. O 1200 continua na
> gaveta 2; ele só deixou de fazer parte da pilha porque `n` voltou para 2. O
> próximo `push` escreve por cima. Por isso empilhar e desempilhar custam
> **O(1)**: uma conta e uma cópia, não importa se a pilha tem 3 ou 100 itens.
> E repare no tamanho: `sizeof(struct pilha)` dá 404 bytes (100 `int` de 4
> bytes, mais o `n`), alocados de uma vez pelo `malloc` no `pilha_cria`, mesmo
> com só 3 itens dentro. O vetor é a casa da pilha, não a pilha.

> [!NOTE]
> **Pergunta para você:** no A173, se o cliente tocar em "desfazer" mais três
> vezes seguidas, o que cada chamada de `pilha_desempilha` devolve? E o que
> fica em `preco` na última? Pense antes de testar.

### Hora de praticar

Os arquivos ficam em [`0087-pilha/`](0087-pilha/). Os comandos funcionam de qualquer pasta do terminal. Nos exemplos, rode, mude, quebre e rode de novo. Nos exercícios, a resposta vai dentro do próprio arquivo. ★☆☆ é aquecimento, ★★☆ pede raciocínio e ★★★ é desafio.

**Exemplo A173 · Desfazer no app de delivery**

```c
#include <stdio.h>
#include "pilha.h"

int main(void) {
    Pilha *pedido = pilha_cria();
    if (pedido == NULL) {
        return 1;
    }

    // preços em centavos: inteiro não tem erro de arredondamento
    pilha_empilha(pedido, 2590); // pizza: R$ 25,90
    pilha_empilha(pedido, 800);  // refrigerante: R$ 8,00
    pilha_empilha(pedido, 1200); // pudim: R$ 12,00

    int preco;
    if (pilha_desempilha(pedido, &preco)) { // "desfazer": sai o último que entrou
        printf("Desfeito: R$ %d,%02d\n", preco / 100, preco % 100);
    }
    if (pilha_topo(pedido, &preco)) { // só olha, não tira
        printf("Agora no topo: R$ %d,%02d\n", preco / 100, preco % 100);
    }
    printf("Itens no pedido: %d\n", pilha_tamanho(pedido));

    pilha_libera(pedido);
    return 0;
}
// Saída:
// Desfeito: R$ 12,00
// Agora no topo: R$ 8,00
// Itens no pedido: 2
```

```bash
~/LPEDC/rodar 12-pilhas-e-filas/0087-pilha/A173.c
```

**Exemplo A174 · Decimal para binário: a pilha inverte a ordem**

```c
#include <stdio.h>
#include "pilha.h"

int main(void) {
    Pilha *restos = pilha_cria();
    if (restos == NULL) {
        return 1;
    }

    int n = 13;
    printf("%d em binário: ", n);
    // os restos da divisão por 2 saem do bit menos significativo para o mais
    // significativo: 1, 0, 1, 1. A pilha devolve na ordem certa: 1, 1, 0, 1.
    while (n > 0) {
        pilha_empilha(restos, n % 2);
        n = n / 2;
    }

    int bit;
    while (pilha_desempilha(restos, &bit)) { // false quando a pilha esvazia
        printf("%d", bit);
    }
    printf("\n");

    pilha_libera(restos);
    return 0;
}
// Saída:
// 13 em binário: 1101
```

```bash
~/LPEDC/rodar 12-pilhas-e-filas/0087-pilha/A174.c
```

#### Exercícios

**Exercício E517** · ★☆☆

O garçom empilha as comandas no espeto do balcão, e a cozinha sempre pega a
de cima. Sem rodar, preveja o que o programa abaixo mostra, linha por linha.
Depois responda: se o laço final terminasse e você chamasse
pilha_desempilha(p, &x) mais uma vez, o que a função devolveria? E quanto
ficaria valendo x?

<details>
<summary>Dicas</summary>

1. Desenhe a pilha de lado, com o topo à direita, e atualize a cada linha.
2. pilha_topo só olha: a pilha não muda.
3. Resposta esperada: "7", "9", "2 1", "4 " e "vazia? 1". Mais um
   desempilha devolve false e não mexe em x, que continua 4.

</details>

```bash
~/LPEDC/rodar 12-pilhas-e-filas/0087-pilha/E517.c
```

**Exercício E518** · ★☆☆

Leia uma palavra com fgets e mostre a palavra de trás para frente usando a
pilha do pilha.h: empilhe cada letra e depois desempilhe tudo. Um char é
um número pequeno, então cabe no int da pilha.


```text
Digite uma palavra: ROMA
Ao contrário: AMOR
```

<details>
<summary>Dicas</summary>

1. Tire o '\n' que o fgets deixa no fim antes de empilhar (assunto 0047).
2. Empilhe com pilha_empilha(p, palavra[i]) e mostre com printf("%c", c).
3. Resposta esperada: com ROMA, "Ao contrário: AMOR". Com OVO, "OVO".

</details>

```bash
~/LPEDC/rodar 12-pilhas-e-filas/0087-pilha/E518.c
```

**Exercício E519** · ★★☆

Complete a função soma_pedido: ela devolve a soma de todos os preços da
pilha (em centavos), usando só as funções do pilha.h. A pilha tem que
voltar exatamente como estava, na mesma ordem: o cliente ainda pode
querer desfazer.


```text
Saída esperada:
Total: R$ 45,90
Topo continua: R$ 12,00 (3 itens)
```

<details>
<summary>Dicas</summary>

1. Você não enxerga o vetor lá dentro: para ver um item, precisa
   desempilhar.
2. Use uma segunda pilha: desempilhe tudo para ela, somando, e depois
   devolva tudo para a original. Ela volta na ordem certa porque inverter
   duas vezes desfaz a inversão.
3. Não esqueça de liberar a pilha auxiliar.
4. Resposta esperada: Total: R$ 45,90 e o topo continua R$ 12,00, com 3
   itens.

</details>

```bash
~/LPEDC/rodar 12-pilhas-e-filas/0087-pilha/E519.c
```

**Exercício E520** · ★★☆

No balcão do restaurante cabem 4 bandejas empilhadas. Este programa traz a
própria pilha (com a convenção topo = -1 para pilha vazia) e tenta
empilhar 5 bandejas. A quinta deveria ser recusada, mas o programa tem um
bug. Rode com o rodar: o sanitizer acusa o erro (procure "out of bounds").
Ache a linha, explique o que acontece na memória e conserte.


```text
Saída esperada depois do conserto:
Empilhou a bandeja 1
Empilhou a bandeja 2
Empilhou a bandeja 3
Empilhou a bandeja 4
Balcão cheio: a bandeja 5 ficou de fora
No topo: bandeja 4
```

<details>
<summary>Dicas</summary>

1. Com topo = -1 para vazia, o topo aponta para o último item, não para a
   próxima vaga.
2. Qual é o maior índice válido de um vetor com CAPACIDADE posições?
3. Resposta esperada: o teste de cheia compara topo com CAPACIDADE, mas
   com essa convenção a pilha enche quando topo == CAPACIDADE - 1. Do
   jeito que está, a quinta bandeja é escrita em itens[4], fora do vetor
   (cai em cima do campo topo, que vira 5). Conserto:
   if (b->topo == CAPACIDADE - 1).

</details>

```bash
~/LPEDC/rodar 12-pilhas-e-filas/0087-pilha/E520.c
```

**Exercício E521** · ★★★

Os números 1, 2, 3, 4 chegam nessa ordem. A cada passo você pode empilhar
o próximo que chegou (E) ou desempilhar e mostrar o topo (D). A sequência
EEDEDDED, por exemplo, mostra 2 3 1 4.

Escreva a função void simula(const char *ops), que recebe a sequência de
letras e mostra os números na ordem em que saem. Se aparecer um D com a
pilha vazia, mostre "erro: pilha vazia" e pare. Teste com as três
sequências do main pronto abaixo.


```text
Saída esperada:
EEDEDDED: 2 3 1 4
EEEDDDED: 3 2 1 4
EDDE: 1 erro: pilha vazia
```


Depois responda sem programar: dá para sair 3 1 2 4? Por quê?

<details>
<summary>Dicas</summary>

1. Guarde num int o próximo número a chegar (começa em 1).
2. pilha_desempilha devolve false com a pilha vazia: é o seu teste de
   erro.
3. Libere a pilha antes de sair da função, inclusive no caso de erro.
4. Resposta esperada: as três linhas acima. 3 1 2 4 é impossível: para o
   3 sair primeiro, o 1 e o 2 precisam estar empilhados com o 2 por cima
   do 1. Então o 2 sai antes do 1, sempre.

</details>

```bash
~/LPEDC/rodar 12-pilhas-e-filas/0087-pilha/E521.c
```

**Exercício E522** · ★★★

A bancada da cozinha tem 6 lugares e guarda duas pilhas ao mesmo tempo:
os pratos limpos crescem a partir da esquerda (posição 0) e os sujos a
partir da direita (posição 5), uma em direção à outra. Assim nenhuma das
duas fica com espaço sobrando enquanto a outra está cheia: a bancada só
enche quando os 6 lugares estão ocupados.

Escreva do zero (sem o pilha.h) uma struct Bancada com um vetor de 6 int e
dois índices, e as funções empilha_limpo, empilha_sujo, desempilha_limpo e
desempilha_sujo, todas devolvendo bool. Teste assim: empilhe os limpos 1, 2
e 3; os sujos 10, 20 e 30; tente empilhar o limpo 4 (tem que falhar);
desempilhe um sujo; empilhe o limpo 4 de novo; e esvazie as duas pilhas
mostrando o que sai.


```text
Saída esperada:
Limpo 4: bancada cheia
Saiu o sujo 30
Limpo 4: ok
Limpos: 4 3 2 1
Sujos: 20 10
```

<details>
<summary>Dicas</summary>

1. Use n_limpos (próxima vaga da esquerda, começa em 0) e topo_sujos
   (começa em 6 e diminui antes de cada empilhamento sujo).
2. A bancada está cheia quando n_limpos == topo_sujos.
3. Desempilhar limpo: n_limpos > 0. Desempilhar sujo: topo_sujos < 6.
4. Resposta esperada: as cinco linhas acima.

</details>

```bash
~/LPEDC/rodar 12-pilhas-e-filas/0087-pilha/E522.c
```

---

## 0088 · Pilha encadeada

Na planilha do orçamento, a célula B2 começou em R$ 1500 e você mudou para
1800, 2100 e 2500. Agora aperta Ctrl+Z duas vezes. A planilha não sabe quantas
vezes você vai editar: pode ser 3, pode ser 3 mil. Uma pilha com
`CAPACIDADE 100` fixa não serve.

A pilha do 0087 tem um teto porque mora num vetor. A saída é guardar cada item
num **nó** alocado com `malloc`, como na lista encadeada do módulo 11. A pilha
cresce um nó por vez e só "enche" quando acaba a memória.

A pergunta que decide tudo: **o topo fica no começo ou no fim da lista?** No
começo. Inserir e remover no início de uma lista simples custa O(1): você
mexe só no ponteiro de entrada. No fim, para remover o último você precisaria
achar o **penúltimo**, e isso exige percorrer a lista inteira, O(n). Então:

- **empilhar** = inserir no início: o novo nó aponta para o antigo topo, e o
  topo passa a ser o novo;
- **desempilhar** = remover do início: guarda o valor, avança o topo, libera
  o nó velho;
- **vazia** = `topo == NULL`.

O melhor: o [`pilha.h`](0088-pilha-encadeada/pilha.h) é **idêntico** ao do
0087. Só o [`pilha.c`](0088-pilha-encadeada/pilha.c) mudou. Esse é o ganho do
TAD: o A173 do delivery roda sem mudar uma vírgula com esta implementação.
Por dentro, a struct agora guarda um ponteiro:

```c
typedef struct no {
    int valor;
    struct no *prox; // o nó de baixo
} No;

struct pilha {
    No *topo; // NULL quando a pilha está vazia
    int n;    // quantos itens (para pilha_tamanho não percorrer a lista)
};

bool pilha_empilha(Pilha *p, int valor) {
    No *novo = malloc(sizeof *novo);
    if (novo == NULL) {
        return false; // só "enche" quando acaba a memória
    }
    novo->valor = valor;
    novo->prox = p->topo; // o novo aponta para o antigo topo
    p->topo = novo;       // e passa a ser o topo
    p->n++;
    return true;
}

bool pilha_desempilha(Pilha *p, int *valor) {
    if (p->topo == NULL) {
        return false;
    }
    No *velho = p->topo;
    *valor = velho->valor; // lê ANTES de liberar
    p->topo = velho->prox;
    free(velho);
    p->n--;
    return true;
}
```

Vamos ver na prática. Antes de cada edição, o valor antigo da B2 vai para a
pilha: 1500, depois 1800, depois 2100. O último a entrar, 2100, fica no
primeiro nó, e é ele que o primeiro Ctrl+Z devolve:

<p align="center"><img src="0088-pilha-encadeada/ideia.svg" alt="Diagrama da ideia: Pilha encadeada" width="890"></p>

O programa da planilha:

```c
#include <stdio.h>
#include "pilha.h"

int main(void) {
    Pilha *desfazer = pilha_cria();
    if (desfazer == NULL) {
        return 1;
    }

    int celula = 1500; // B2: orçamento do mês, em R$
    int novos[] = {1800, 2100, 2500};
    for (int i = 0; i < 3; i++) {
        pilha_empilha(desfazer, celula); // guarda o valor antigo antes de mudar
        celula = novos[i];
        printf("B2 = %d\n", celula);
    }

    // a pilha agora é: topo -> 2100 -> 1800 -> 1500 -> NULL
    for (int i = 0; i < 2; i++) { // Ctrl+Z duas vezes
        if (pilha_desempilha(desfazer, &celula)) {
            printf("Ctrl+Z: B2 = %d\n", celula);
        }
    }
    printf("Ainda dá para desfazer %d vez(es)\n", pilha_tamanho(desfazer));

    pilha_libera(desfazer); // libera o nó que sobrou e a própria pilha
    return 0;
}
// Saída:
// B2 = 1800
// B2 = 2100
// B2 = 2500
// Ctrl+Z: B2 = 2100
// Ctrl+Z: B2 = 1800
// Ainda dá para desfazer 1 vez(es)
```

Repara no fluxograma do empilhar o 2100: a ordem das duas ligações importa.
Primeiro o novo nó aponta para o topo antigo, só depois o topo muda:

<p align="center"><img src="0088-pilha-encadeada/fluxograma.svg" alt="Fluxograma: Pilha encadeada" width="469"></p>

> [!WARNING]
> Troque a ordem e você perde a pilha inteira. Se fizer `p->topo = novo`
> antes de `novo->prox = p->topo`, o novo nó aponta para **ele mesmo**, e os
> nós 1800 e 1500 ficam sem ninguém apontando para eles: vazamento de memória
> e uma pilha que só tem o 2100 em loop. No desempilhar, o perigo é o
> contrário: ler `velho->valor` **depois** do `free(velho)` é usar memória
> liberada, e o AddressSanitizer acusa `heap-use-after-free`.

> [!TIP]
> **Por dentro do C:** cada nó ocupa 16 bytes: 4 do `int`, 4 de
> **preenchimento** (*padding*) para alinhar o ponteiro e 8 do ponteiro, num
> sistema de 64 bits. Para guardar 4 bytes de dado, você gasta 16, mais o
> controle interno do `malloc`. O vetor do 0087 gasta 4 bytes por item, todos
> juntos na memória, o que o cache do processador adora. A encadeada troca
> espaço e velocidade por **não ter teto**. E todo `malloc` do empilhar
> precisa de um `free`: é por isso que `pilha_libera` percorre a lista toda
> antes de liberar a struct.

> [!NOTE]
> **Pergunta para você:** no A175, se o laço do Ctrl+Z rodasse 5 vezes em vez
> de 2, quantas linhas `Ctrl+Z` apareceriam e qual seria o último valor de B2?
> Siga a lista do desenho antes de rodar.

### Hora de praticar

Os arquivos ficam em [`0088-pilha-encadeada/`](0088-pilha-encadeada/). Os comandos funcionam de qualquer pasta do terminal. Nos exemplos, rode, mude, quebre e rode de novo. Nos exercícios, a resposta vai dentro do próprio arquivo. ★☆☆ é aquecimento, ★★☆ pede raciocínio e ★★★ é desafio.

**Exemplo A175 · Ctrl+Z na planilha**

```c
#include <stdio.h>
#include "pilha.h"

int main(void) {
    Pilha *desfazer = pilha_cria();
    if (desfazer == NULL) {
        return 1;
    }

    int celula = 1500; // B2: orçamento do mês, em R$
    int novos[] = {1800, 2100, 2500};
    for (int i = 0; i < 3; i++) {
        pilha_empilha(desfazer, celula); // guarda o valor antigo antes de mudar
        celula = novos[i];
        printf("B2 = %d\n", celula);
    }

    // a pilha agora é: topo -> 2100 -> 1800 -> 1500 -> NULL
    for (int i = 0; i < 2; i++) { // Ctrl+Z duas vezes
        if (pilha_desempilha(desfazer, &celula)) {
            printf("Ctrl+Z: B2 = %d\n", celula);
        }
    }
    printf("Ainda dá para desfazer %d vez(es)\n", pilha_tamanho(desfazer));

    pilha_libera(desfazer); // libera o nó que sobrou e a própria pilha
    return 0;
}
// Saída:
// B2 = 1800
// B2 = 2100
// B2 = 2500
// Ctrl+Z: B2 = 2100
// Ctrl+Z: B2 = 1800
// Ainda dá para desfazer 1 vez(es)
```

```bash
~/LPEDC/rodar 12-pilhas-e-filas/0088-pilha-encadeada/A175.c
```

**Exemplo A176 · Sem teto: 100 mil itens na pilha encadeada**

```c
#include <stdio.h>
#include "pilha.h"

// A pilha do vetor (0087) recusaria o 101º item. Esta só para quando acabar a
// memória. O código é o mesmo do cliente da 0087: só o pilha.c mudou.
int main(void) {
    Pilha *p = pilha_cria();
    if (p == NULL) {
        return 1;
    }

    int recusados = 0;
    for (int i = 1; i <= 100000; i++) {
        if (!pilha_empilha(p, i)) {
            recusados++;
        }
    }
    printf("Empilhados: %d, recusados: %d\n", pilha_tamanho(p), recusados);

    int topo;
    if (pilha_topo(p, &topo)) {
        printf("No topo: %d\n", topo);
    }

    // pilha_libera percorre os 100 mil nós; sem ela, o AddressSanitizer
    // acusaria 100 mil vazamentos de 16 bytes
    pilha_libera(p);
    return 0;
}
// Saída:
// Empilhados: 100000, recusados: 0
// No topo: 100000
```

```bash
~/LPEDC/rodar 12-pilhas-e-filas/0088-pilha-encadeada/A176.c
```

#### Exercícios

**Exercício E523** · ★☆☆

Sem rodar, desenhe a lista encadeada da pilha depois de cada linha do main
(no formato topo -> ... -> NULL) e preveja a saída. Depois conte: até o
fim do programa, quantas vezes o malloc foi chamado? E o free? Lembre que
pilha_cria também faz um malloc.

<details>
<summary>Dicas</summary>

1. Empilhar insere no início: o novo nó vira o primeiro da lista.
2. Cada empilha faz um malloc; cada desempilha faz um free; pilha_libera
   faz um free por nó que sobrou e mais um da struct.
3. Resposta esperada: mostra "8", "9" e "2 itens, topo 5". A lista final
   é topo -> 5 -> 3 -> NULL. São 5 mallocs (1 da pilha + 4 nós) e 5 frees
   (2 nos desempilhas + 2 nós no pilha_libera + 1 da struct).

</details>

```bash
~/LPEDC/rodar 12-pilhas-e-filas/0088-pilha-encadeada/E523.c
```

**Exercício E524** · ★☆☆

Você vai lendo os valores das notas fiscais do mês (inteiros, em reais) até
digitar 0. Não dá para saber de antemão quantas são, e por isso a pilha
encadeada é perfeita. No fim, mostre quantas notas foram lidas e os
valores da última para a primeira. Se o scanf falhar (alguém digitou uma
letra), pare de ler como se fosse o 0.


```text
Digite os valores (0 para terminar): 120 45 300 0
Lidas 3 notas. Da última para a primeira: 300 45 120
```

<details>
<summary>Dicas</summary>

1. while (scanf("%d", &valor) == 1 && valor != 0) { ... }
2. pilha_tamanho dá a contagem sem você precisar de outro contador.
3. Resposta esperada: com 120 45 300 0, "Lidas 3 notas. Da última para a
   primeira: 300 45 120".

</details>

```bash
~/LPEDC/rodar 12-pilhas-e-filas/0088-pilha-encadeada/E524.c
```

**Exercício E525** · ★★☆

O botão Voltar do navegador é uma pilha de páginas. Este programa monta a
própria pilha encadeada, com um texto em cada nó (por isso não usa o
pilha.h, que guarda int). Complete as funções:

- visita: cria um nó com a url e põe no topo (devolve false se faltar
memória);
- voltar: tira a página do topo, mas só se ela não for a única (da
primeira página não se volta). Devolve false se não deu para voltar.


```text
Saída esperada:
Agora em: receitas.com
Voltar -> ge.globo.com
Agora em: cifraclub.com.br
Voltar -> ge.globo.com
Voltar -> g1.globo.com
Não dá para voltar de g1.globo.com
```

<details>
<summary>Dicas</summary>

1. Em visita, faça como no pilha_empilha: malloc, copie a url com strcpy,
   ligue novo->ant ao topo antigo e só então troque o topo.
2. A página é a única quando h->topo->ant == NULL.
3. Em voltar, guarde o nó velho, avance o topo e só depois dê free.
4. Resposta esperada: as seis linhas acima, sem vazamento no sanitizer.

</details>

```bash
~/LPEDC/rodar 12-pilhas-e-filas/0088-pilha-encadeada/E525.c
```

**Exercício E526** · ★★☆

Pilha de pratos do restaurante, cada prato com um número. Este programa
compila (o gcc 13 até solta um aviso: leia com atenção) e, sem o
sanitizer, às vezes mostra os números certos. Mesmo assim está errado:
rode com o rodar e leia o relatório do AddressSanitizer. Responda:

a) Qual é o nome do erro no relatório e em que linha ele acontece?
b) Por que o programa às vezes "funciona" sem o sanitizer?
c) Como consertar mudando a ordem de duas linhas?


```text
Saída esperada depois do conserto:
Tirou o prato 30
Tirou o prato 20
Tirou o prato 10
```

<details>
<summary>Dicas</summary>

1. Procure "heap-use-after-free" e o número da linha no relatório.
2. Depois do free, o nó não é mais seu, mesmo que os bytes ainda estejam
   lá.
3. Resposta esperada: a) heap-use-after-free, na linha que faz
   "*numero = velho->numero", depois do free(velho); b) o free só marca
   a memória como livre: até alguém reaproveitá-la, os bytes antigos
   continuam lá, então ler parece funcionar por sorte; c) ler o valor
   antes do free (passe a linha do *numero para antes do free).

</details>

```bash
~/LPEDC/rodar 12-pilhas-e-filas/0088-pilha-encadeada/E526.c
```

**Exercício E527** · ★★★

Os pedidos da cozinha chegaram empilhados fora de ordem: 5, 3, 8, 1 e 4 (o
4 no topo). Escreva void ordena(Pilha *p), que deixa a pilha ordenada com o
MENOR no topo, usando só as funções do pilha.h e no máximo UMA pilha
auxiliar (nada de vetor). Depois o main desempilha e mostra tudo.


```text
Saída esperada:
1 3 4 5 8
```

<details>
<summary>Dicas</summary>

1. A auxiliar fica sempre ordenada, com o MAIOR no topo dela.
2. Tire um valor x da original. Enquanto o topo da auxiliar for maior que
   x, devolva esse topo para a original. Então empilhe x na auxiliar.
3. Quando a original esvaziar, despeje a auxiliar de volta nela: o maior
   vai para o fundo, e o menor fica no topo.
4. Resposta esperada: 1 3 4 5 8. No pior caso são O(n²) movimentos, como
   na ordenação por inserção (assunto 0098).

</details>

```bash
~/LPEDC/rodar 12-pilhas-e-filas/0088-pilha-encadeada/E527.c
```

**Exercício E528** · ★★★

Uma estação meteorológica empilha as temperaturas do dia e às vezes
descarta a última leitura (sensor com defeito). A qualquer momento ela
quer saber a MENOR temperatura que está na pilha, e essa consulta precisa
custar O(1): nada de percorrer a pilha.

Escreva um tipo PilhaMin com duas Pilha * dentro (a dos valores e a dos
mínimos) e as funções min_cria, min_empilha, min_desempilha, min_atual e
min_libera. Teste empilhando 22, 19, 25, 17 e 30 e depois desempilhando
quatro vezes.


```text
Saída esperada:
empilha 22 -> mínimo 22
empilha 19 -> mínimo 19
empilha 25 -> mínimo 19
empilha 17 -> mínimo 17
empilha 30 -> mínimo 17
desempilha 30 -> mínimo 17
desempilha 17 -> mínimo 19
desempilha 25 -> mínimo 19
desempilha 19 -> mínimo 22
```

<details>
<summary>Dicas</summary>

1. A pilha dos mínimos anda junto com a dos valores: a cada empilhamento,
   empilhe nela o menor entre o valor novo e o mínimo atual.
2. Ao desempilhar, tire das duas.
3. min_atual é só um pilha_topo na pilha dos mínimos.
4. Resposta esperada: as nove linhas acima. Custa o dobro de memória em
   troca de O(1) na consulta.

</details>

```bash
~/LPEDC/rodar 12-pilhas-e-filas/0088-pilha-encadeada/E528.c
```

---

## 0089 · Pilha na prática: parênteses e notação pós-fixa

Você esquece de fechar um colchete no VS Code e, na hora, o editor sublinha
de vermelho o lugar certo. Ele não está contando parênteses. Está usando uma
pilha.

Com um tipo só de parêntese, um contador resolve: soma 1 no `(`, tira 1 no
`)`, nunca pode ficar negativo e tem que terminar em zero. Com três tipos
(`()`, `[]`, `{}`) o contador quebra. Em `( [ ) ]` tem duas aberturas e dois
fechamentos, a conta fecha, e a expressão está errada: o `)` chegou quando
quem estava esperando era o `[`.

A regra que você precisa é: **todo fechamento casa com a abertura mais
recente que ainda não fechou**. "Mais recente ainda pendente" é exatamente o
topo de uma pilha. O algoritmo:

1. abriu (`(`, `[` ou `{`): **empilha**;
2. fechou: **desempilha** e confere se é o par certo. Pilha vazia ou par
   errado: erro;
3. qualquer outro caractere: ignora;
4. acabou a string: a pilha tem que estar **vazia**. Se sobrou alguém, faltou
   fechar.

Vamos ver na prática com `{ x = v[(i + 1)] }`. Tirando o resto, sobram os
delimitadores `{ [ ( ) ] }`. Os três primeiros são empilhados. Quando chega o
`)`, o topo é `(`: casou, desempilha e segue. Depois `]` casa com `[` e `}`
casa com `{`:

<p align="center"><img src="0089-pilha-aplicacoes/ideia.svg" alt="Diagrama da ideia: Pilha na prática: parênteses e notação pós-fixa" width="858"></p>

O verificador, testado com quatro expressões. O `pilha.h` e o `pilha.c` são
os mesmos do 0088 e estão na pasta do assunto:

```c
#include <stdbool.h>
#include <stdio.h>
#include "pilha.h"

// a abertura que combina com cada fechamento
char abertura_de(char fecha) {
    if (fecha == ')') {
        return '(';
    }
    if (fecha == ']') {
        return '[';
    }
    return '{';
}

bool balanceada(const char *s) {
    Pilha *p = pilha_cria();
    if (p == NULL) {
        return false;
    }
    bool ok = true;
    for (int i = 0; s[i] != '\0' && ok; i++) {
        char c = s[i];
        if (c == '(' || c == '[' || c == '{') {
            pilha_empilha(p, c); // abriu: espera o fechamento lá na frente
        } else if (c == ')' || c == ']' || c == '}') {
            int topo;
            // fechou: tem que existir uma abertura e ela tem que ser do mesmo tipo
            if (!pilha_desempilha(p, &topo) || topo != abertura_de(c)) {
                ok = false;
            }
        }
    }
    if (!pilha_vazia(p)) {
        ok = false; // sobrou abertura sem fechamento
    }
    pilha_libera(p);
    return ok;
}

int main(void) {
    const char *testes[] = {"{ x = v[(i + 1)] }", "( [ ) ]", "(a + b))", "{ [ ("};
    for (int i = 0; i < 4; i++) {
        printf("%-20s %s\n", testes[i], balanceada(testes[i]) ? "balanceada" : "com erro");
    }
    return 0;
}
// Saída:
// { x = v[(i + 1)] }   balanceada
// ( [ ) ]              com erro
// (a + b))             com erro
// { [ (                com erro
```

Repara no fluxograma: o laço só tem duas saídas antecipadas para o erro, e a
pergunta "pilha vazia?" só acontece quando a string acaba:

<p align="center"><img src="0089-pilha-aplicacoes/fluxograma.svg" alt="Fluxograma: Pilha na prática: parênteses e notação pós-fixa" width="796"></p>

### Notação pós-fixa

A segunda aplicação clássica é fazer conta. A conta do bar foi `(35 + 25) * 3
/ 4`: três rodadas de petisco e bebida, divididas por 4 amigos. Na notação de
sempre (**infixa**), o operador fica no meio e você precisa de parênteses e de
regras de precedência. Na **pós-fixa** (a da calculadora HP 12C), o operador
vem **depois** dos dois operandos: `35 25 + 3 * 4 /`. Sem parênteses, sem
precedência: a ordem da escrita já é a ordem das contas.

Para avaliar, uma pilha de números: número **empilha**; operador
**desempilha dois**, faz a conta e **empilha o resultado**. No fim, sobra um
número só, o resultado:

| lê | faz | pilha (topo à direita) |
| --- | --- | --- |
| `35` | empilha | 35 |
| `25` | empilha | 35 25 |
| `+` | tira 25 e 35, empilha 35 + 25 | 60 |
| `3` | empilha | 60 3 |
| `*` | tira 3 e 60, empilha 60 * 3 | 180 |
| `4` | empilha | 180 4 |
| `/` | tira 4 e 180, empilha 180 / 4 | 45 |

Cada um paga R$ 45. O exemplo A178 faz exatamente essa tabela em C, juntando
os dígitos de `35` num número só e acusando expressão inválida quando falta
operando ou sobra número na pilha. É assim que compiladores e máquinas
virtuais (a JVM, o WebAssembly) calculam: traduzem a sua expressão para algo
parecido com a pós-fixa e rodam numa pilha.

> [!WARNING]
> Na pós-fixa, o **primeiro** a sair da pilha é o operando da **direita**.
> Em `8 3 -`, desempilha o 3 (b) e depois o 8 (a), e a conta é `a - b = 5`.
> Inverter dá `-5`, e o erro some na soma e na multiplicação, que não ligam
> para a ordem. Teste sempre com `-` e `/`. No verificador de parênteses, o
> erro clássico é esquecer o passo 4: sem conferir se a pilha terminou
> vazia, `{ [ (` passa como balanceada.

> [!TIP]
> **Por dentro do C:** o `char` que entra no `pilha_empilha(p, c)` vira `int`
> sem cast nenhum (promoção de inteiros), e `'('` é só o número 40 na tabela
> ASCII. Na pós-fixa, `expr[i] - '0'` transforma o caractere `'7'` (55) no
> número 7, porque os dígitos são consecutivos na tabela. E o tamanho da pilha
> nunca passa do número de caracteres da string: no pior caso, `((((((`, tudo
> é empilhado. Memória **O(n)**, tempo **O(n)**: cada caractere é visto uma
> vez e entra e sai da pilha no máximo uma vez.

> [!NOTE]
> **Pergunta para você:** quanto vale `2 3 4 * +`? E `2 3 + 4 *`? Escreva as
> duas na forma infixa, com parênteses só onde precisa, antes de testar no
> A178.

### Hora de praticar

Os arquivos ficam em [`0089-pilha-aplicacoes/`](0089-pilha-aplicacoes/). Os comandos funcionam de qualquer pasta do terminal. Nos exemplos, rode, mude, quebre e rode de novo. Nos exercícios, a resposta vai dentro do próprio arquivo. ★☆☆ é aquecimento, ★★☆ pede raciocínio e ★★★ é desafio.

**Exemplo A177 · Parênteses, colchetes e chaves balanceados**

```c
#include <stdbool.h>
#include <stdio.h>
#include "pilha.h"

// a abertura que combina com cada fechamento
char abertura_de(char fecha) {
    if (fecha == ')') {
        return '(';
    }
    if (fecha == ']') {
        return '[';
    }
    return '{';
}

bool balanceada(const char *s) {
    Pilha *p = pilha_cria();
    if (p == NULL) {
        return false;
    }
    bool ok = true;
    for (int i = 0; s[i] != '\0' && ok; i++) {
        char c = s[i];
        if (c == '(' || c == '[' || c == '{') {
            pilha_empilha(p, c); // abriu: espera o fechamento lá na frente
        } else if (c == ')' || c == ']' || c == '}') {
            int topo;
            // fechou: tem que existir uma abertura e ela tem que ser do mesmo tipo
            if (!pilha_desempilha(p, &topo) || topo != abertura_de(c)) {
                ok = false;
            }
        }
    }
    if (!pilha_vazia(p)) {
        ok = false; // sobrou abertura sem fechamento
    }
    pilha_libera(p);
    return ok;
}

int main(void) {
    const char *testes[] = {"{ x = v[(i + 1)] }", "( [ ) ]", "(a + b))", "{ [ ("};
    for (int i = 0; i < 4; i++) {
        printf("%-20s %s\n", testes[i], balanceada(testes[i]) ? "balanceada" : "com erro");
    }
    return 0;
}
// Saída:
// { x = v[(i + 1)] }   balanceada
// ( [ ) ]              com erro
// (a + b))             com erro
// { [ (                com erro
```

```bash
~/LPEDC/rodar 12-pilhas-e-filas/0089-pilha-aplicacoes/A177.c
```

**Exemplo A178 · A conta do bar em notação pós-fixa**

```c
#include <stdbool.h>
#include <stdio.h>
#include "pilha.h"

// Avalia uma expressão pós-fixa com inteiros não negativos separados por
// espaço e os operadores + - * /. Devolve false se a expressão for inválida.
bool avalia(const char *expr, int *resultado) {
    Pilha *p = pilha_cria();
    if (p == NULL) {
        return false;
    }
    bool ok = true;
    for (int i = 0; expr[i] != '\0' && ok; i++) {
        char c = expr[i];
        if (c >= '0' && c <= '9') {
            int numero = 0;
            while (expr[i] >= '0' && expr[i] <= '9') { // junta os dígitos: "35" -> 35
                numero = numero * 10 + (expr[i] - '0');
                i++;
            }
            i--; // o for vai somar 1 de novo
            pilha_empilha(p, numero);
        } else if (c == '+' || c == '-' || c == '*' || c == '/') {
            int a, b;
            // o primeiro a sair é o operando da DIREITA
            if (!pilha_desempilha(p, &b) || !pilha_desempilha(p, &a) || (c == '/' && b == 0)) {
                ok = false;
            } else if (c == '+') {
                pilha_empilha(p, a + b);
            } else if (c == '-') {
                pilha_empilha(p, a - b);
            } else if (c == '*') {
                pilha_empilha(p, a * b);
            } else {
                pilha_empilha(p, a / b);
            }
        }
    }
    // no fim tem que sobrar exatamente um número: o resultado
    if (ok && (!pilha_desempilha(p, resultado) || !pilha_vazia(p))) {
        ok = false;
    }
    pilha_libera(p);
    return ok;
}

int main(void) {
    // (35 + 25) * 3 / 4: três rodadas de petisco (R$ 35) e bebida (R$ 25),
    // divididas entre 4 amigos
    const char *expr = "35 25 + 3 * 4 /";
    int total;
    if (avalia(expr, &total)) {
        printf("%s = %d\n", expr, total);
    }
    if (!avalia("35 +", &total)) {
        printf("35 + : expressão inválida\n");
    }
    return 0;
}
// Saída:
// 35 25 + 3 * 4 / = 45
// 35 + : expressão inválida
```

```bash
~/LPEDC/rodar 12-pilhas-e-filas/0089-pilha-aplicacoes/A178.c
```

#### Exercícios

**Exercício E529** · ★☆☆

Sem programar, escreva cada expressão na notação pós-fixa e calcule o
valor. Depois avalie a última, que já está em pós-fixa, fazendo a tabela
"lê / faz / pilha" do texto.


```text
a) (7 + 3) * 2
b) 7 + 3 * 2
c) 100 / (2 + 3) - 4
d) 6 2 / 3 1 - *        (já em pós-fixa)
```

<details>
<summary>Dicas</summary>

1. Os números aparecem na mesma ordem nas duas notações; só os
   operadores mudam de lugar.
2. Na b, a multiplicação acontece primeiro, então o * aparece antes do +.
3. Resposta esperada: a) 7 3 + 2 * = 20; b) 7 3 2 * + = 13;
   c) 100 2 3 + / 4 - = 16; d) pilha 6 | 6 2 | 3 | 3 3 | 3 3 1 | 3 2 | 6,
   então vale 6 (a infixa é (6 / 2) * (3 - 1)).

</details>

```bash
~/LPEDC/rodar 12-pilhas-e-filas/0089-pilha-aplicacoes/E529.c
```

**Exercício E530** · ★☆☆

Quando só existe um tipo de delimitador, nem precisa de pilha. Escreva
bool parenteses_ok(const char *s) usando só um contador int: soma 1 no
"(", tira 1 no ")". Teste com as quatro strings abaixo. Depois responda:
por que essa ideia não serve para "( [ ) ]"?


```text
Saída esperada:
(a+(b*c))  ok
(a+b))(    erro
)(         erro
((x)       erro
```

<details>
<summary>Dicas</summary>

1. Se o contador ficar negativo no meio do caminho, já é erro: fechou
   sem abrir. É o que pega o ")(".
2. No fim, ok só se o contador for 0.
3. Use printf("%-10s %s\n", s, ...) para alinhar.
4. Resposta esperada: as quatro linhas acima. Com tipos diferentes, o
   contador só sabe QUANTOS estão abertos, não QUAL foi o último a abrir.

</details>

```bash
~/LPEDC/rodar 12-pilhas-e-filas/0089-pilha-aplicacoes/E530.c
```

**Exercício E531** · ★★☆

Este verificador é mais educado que o do A177: além de dizer que deu
errado, diz onde e por quê. Sem rodar, preveja as quatro linhas que ele
mostra. Atenção às posições: a primeira posição da string é 0.

<details>
<summary>Dicas</summary>

1. Faça uma tabela com a posição, o caractere e a pilha depois dele.
2. O laço para no primeiro erro; "faltou fechar" só aparece quando a
   string acaba sem erro antes.
3. Resposta esperada:
   [1, (2, 3)]: ok
   {a: [1, 2}]: esperava ] e veio } na posição 9
   f(x)): fecha sem abrir na posição 4
   if (a[0] {: faltou fechar 2

</details>

```bash
~/LPEDC/rodar 12-pilhas-e-filas/0089-pilha-aplicacoes/E531.c
```

**Exercício E532** · ★★☆

Esta calculadora pós-fixa (operandos de um dígito) compila sem aviso e
acerta a soma. Mas erra outras contas. Rode, compare com a saída esperada,
ache o bug e conserte mexendo no mínimo de código.


```text
Saída esperada depois do conserto:
2 3 + = 5
8 3 - = 5
8 4 / = 2
9 5 2 - * = 27
```

<details>
<summary>Dicas</summary>

1. Rode: a soma está certa, a subtração dá -5 e a divisão dá 0. O que a
   soma tem que a subtração e a divisão não têm?
2. Qual operando sai primeiro da pilha: o da esquerda ou o da direita?
3. Resposta esperada: os dois pilha_desempilha estão na ordem errada. O
   primeiro a sair é o operando da direita, então ele tem que ir para b.
   Trocando a ordem (desempilha em b, depois em a), as quatro contas
   ficam certas. A soma e a multiplicação escondiam o erro porque
   a + b == b + a.

</details>

```bash
~/LPEDC/rodar 12-pilhas-e-filas/0089-pilha-aplicacoes/E532.c
```

**Exercício E533** · ★★★

Escreva void para_posfixa(const char *in, char *out), que converte uma
expressão infixa com operandos de UM dígito, + - * / e parênteses para a
notação pós-fixa, com um espaço entre os símbolos. Use a pilha do pilha.h
para guardar os operadores e os "(". As regras (o algoritmo do
"pátio de manobras", de Dijkstra):

- dígito: vai direto para a saída;
- "(": empilha;
- ")": desempilha para a saída até achar o "(", que é descartado;
- operador: enquanto o topo for um operador de precedência MAIOR OU IGUAL,
desempilha para a saída; depois empilha o operador;
- fim da entrada: desempilha tudo o que sobrou para a saída.


```text
Saída esperada:
1+2*3 -> 1 2 3 * +
(6+2)*5-8/4 -> 6 2 + 5 * 8 4 / -
(1+2)*(3-4) -> 1 2 + 3 4 - *
9-4-2 -> 9 4 - 2 -
```

<details>
<summary>Dicas</summary>

1. Uma função int precedencia(int op): 2 para * e /, 1 para + e -, 0 para
   "(" (assim o "(" nunca sai por causa de um operador).
2. Monte a saída com um índice: out[k++] = c; out[k++] = ' '; e no fim
   troque o último espaço por '\0'.
3. O "maior ou igual" é o que faz 9-4-2 virar (9-4)-2, e não 9-(4-2).
4. Resposta esperada: as quatro linhas acima. Confira a segunda no A178
   (troque os números): o valor de (6+2)*5-8/4 é 38.

</details>

```bash
~/LPEDC/rodar 12-pilhas-e-filas/0089-pilha-aplicacoes/E533.c
```

**Exercício E534** · ★★★

Faça uma calculadora pós-fixa de verdade: ela lê expressões, uma por linha
(com fgets), até o fim da entrada (Ctrl+D no terminal), aceita números com
vários dígitos e, em vez de quebrar, explica o erro:

- "falta operando": operador sem dois números na pilha;
- "divisão por zero";
- "sobrou número na pilha": terminou com mais de um número;
- "símbolo inválido 'x'": qualquer coisa que não seja dígito, espaço ou
+ - * /;
- linha vazia: ignore.


```text
Teste: printf '10 2 8 * + 3 -\n4 0 /\n5 +\n1 2 3 +\n2 x +\n' | rodar E534.c
= 23
erro: divisão por zero
erro: falta operando
erro: sobrou número na pilha
erro: símbolo inválido 'x'
```

<details>
<summary>Dicas</summary>

1. Uma função int avalia(const char *linha, int *resultado) que devolve um
   código (0 = ok, 1, 2, 3, 4 para cada erro) deixa o main simples.
2. Crie a pilha dentro de avalia e libere em TODOS os caminhos de saída.
3. Junte os dígitos como no A178. O '\n' do fgets conta como espaço.
4. Resposta esperada: as cinco linhas acima.

</details>

```bash
~/LPEDC/rodar 12-pilhas-e-filas/0089-pilha-aplicacoes/E534.c
```

---

## 0090 · Fila

Na lotérica, você pega a senha 35 e espera. Quem chegou antes é atendido
antes, e ninguém fura: a senha 40, que acabou de sair da maquininha, vai
esperar todo mundo da frente.

Isso é uma **fila** (*queue*): entra pelo **fim**, sai pelo **início**. O
primeiro a entrar é o primeiro a sair: **FIFO** (*first in, first out*). É o
contrário da pilha. Na computação, fila aparece onde existe ordem de chegada:
a fila de impressão, as requisições esperando o servidor Fastify, os eventos
esperando o *event loop* do Node, as mensagens de um RabbitMQ.

O TAD tem a mesma cara da pilha, no [`fila.h`](0090-fila/fila.h):

```c
typedef struct fila Fila; // tipo opaco: os campos ficam no fila.c

Fila *fila_cria(void);                          // fila vazia (NULL se faltar memória)
void fila_libera(Fila *f);                      // devolve toda a memória da fila
bool fila_vazia(const Fila *f);                 // true se não tem ninguém
int fila_tamanho(const Fila *f);                // quantos estão na fila
bool fila_insere(Fila *f, int valor);           // entra no fim: false se não coube
bool fila_retira(Fila *f, int *valor);          // sai do início: false se vazia
bool fila_primeiro(const Fila *f, int *valor);  // olha quem é o próximo, sem tirar
```

Guardar uma fila num vetor tem um problema que a pilha não tinha. A pilha
mexe numa ponta só. A fila mexe nas duas: entra à direita e sai à esquerda.
Se, a cada atendimento, você empurrar todo mundo uma casa para a esquerda
(como o `shift()` do JS faz), cada retirada custa **O(n)**. Se não empurrar,
a fila vai "andando" para a direita e bate no fim do vetor com as primeiras
gavetas vazias.

A saída é a **fila circular**: quando o índice passa da última gaveta, volta
para a 0. O vetor vira um anel. Basta guardar onde está o **início** e
quantos itens tem (`n`); a próxima vaga é `(inicio + n) % CAPACIDADE`. O `%`
faz a volta: com 8 gavetas, depois da 7 vem `(7 + 1) % 8 = 0`. O coração do
[`fila.c`](0090-fila/fila.c):

```c
#define CAPACIDADE 8

struct fila {
    int itens[CAPACIDADE];
    int inicio; // posição do primeiro da fila (o próximo a sair)
    int n;      // quantos estão na fila: separa "cheia" de "vazia"
};

bool fila_insere(Fila *f, int valor) {
    if (f->n == CAPACIDADE) {
        return false; // cheia
    }
    int fim = (f->inicio + f->n) % CAPACIDADE; // dá a volta no fim do vetor
    f->itens[fim] = valor;
    f->n++;
    return true;
}

bool fila_retira(Fila *f, int *valor) {
    if (f->n == 0) {
        return false; // vazia
    }
    *valor = f->itens[f->inicio];
    f->inicio = (f->inicio + 1) % CAPACIDADE;
    f->n--;
    return true;
}
```

Vamos ver na prática. O painel da lotérica guarda 8 senhas. Chegam as senhas
31 a 36 (gavetas 0 a 5). O caixa atende 4, e o início anda até a gaveta 4.
Chegam 37 a 40: o 37 e o 38 ocupam as gavetas 6 e 7, e o 39 e o 40 **dão a
volta** e caem nas gavetas 0 e 1, que já estavam livres:

<p align="center"><img src="0090-fila/ideia.svg" alt="Diagrama da ideia: Fila" width="864"></p>

O programa da lotérica. Ele só vê as funções do `fila.h`; a volta no vetor é
problema do `fila.c`:

```c
#include <stdio.h>
#include "fila.h"

int main(void) {
    Fila *senhas = fila_cria(); // o painel guarda até 8 senhas
    if (senhas == NULL) {
        return 1;
    }

    for (int s = 31; s <= 36; s++) { // chegam 6 pessoas
        fila_insere(senhas, s);
    }

    printf("Atendidas:");
    for (int i = 0; i < 4; i++) { // o caixa chama 4
        int s;
        if (fila_retira(senhas, &s)) {
            printf(" %d", s);
        }
    }

    printf("\nChegaram:");
    for (int s = 37; s <= 40; s++) { // 39 e 40 dão a volta no vetor
        if (fila_insere(senhas, s)) {
            printf(" %d", s);
        }
    }

    printf("\nNa fila (%d):", fila_tamanho(senhas));
    int s;
    while (fila_retira(senhas, &s)) {
        printf(" %d", s);
    }
    printf("\n");

    fila_libera(senhas);
    return 0;
}
// Saída:
// Atendidas: 31 32 33 34
// Chegaram: 37 38 39 40
// Na fila (6): 35 36 37 38 39 40
```

Repara no fluxograma da entrada da senha 39: naquela hora, `inicio = 4` e
`n = 4`, e o `%` manda o 39 para a gaveta 0:

<p align="center"><img src="0090-fila/fluxograma.svg" alt="Fluxograma: Fila" width="522"></p>

> [!WARNING]
> Sem o contador `n`, cheia e vazia ficam **iguais**. Se você guardar só
> `inicio` e `fim`, a fila vazia tem `inicio == fim`, e a fila cheia, depois
> de dar a volta completa, também. Há duas saídas: guardar `n`, como aqui, ou
> **sacrificar uma gaveta** e dizer que está cheia quando
> `(fim + 1) % CAPACIDADE == inicio` (aí só cabem 7 em 8). Muito livro usa a
> segunda. Outra armadilha: calcular o tamanho como `fim - inicio`. Com a
> fila dando a volta (início 4, fim 2) isso dá -2.

> [!TIP]
> **Por dentro do C:** o `%` é uma divisão inteira, uma das instruções mais
> lentas do processador (dezenas de ciclos, contra 1 de uma soma). Por isso
> filas de alto desempenho, como os *ring buffers* do kernel do Linux e das
> placas de rede, usam capacidade **potência de 2**: com 8 gavetas e `i`
> não negativo,
> `i % 8` é o mesmo que `i & 7`, e o compilador já faz essa troca sozinho
> quando a constante é potência de 2. Retirar não apaga nada: o 33 e o 34
> continuam nas gavetas 2 e 3 até alguém escrever por cima. Inserir e retirar
> custam **O(1)**, sem mover ninguém.

> [!NOTE]
> **Pergunta para você:** depois do último laço do A179, a fila está vazia.
> Quanto valem `inicio` e `n` lá dentro? Em que gaveta entraria a próxima
> senha?

### Hora de praticar

Os arquivos ficam em [`0090-fila/`](0090-fila/). Os comandos funcionam de qualquer pasta do terminal. Nos exemplos, rode, mude, quebre e rode de novo. Nos exercícios, a resposta vai dentro do próprio arquivo. ★☆☆ é aquecimento, ★★☆ pede raciocínio e ★★★ é desafio.

**Exemplo A179 · As senhas da lotérica**

```c
#include <stdio.h>
#include "fila.h"

int main(void) {
    Fila *senhas = fila_cria(); // o painel guarda até 8 senhas
    if (senhas == NULL) {
        return 1;
    }

    for (int s = 31; s <= 36; s++) { // chegam 6 pessoas
        fila_insere(senhas, s);
    }

    printf("Atendidas:");
    for (int i = 0; i < 4; i++) { // o caixa chama 4
        int s;
        if (fila_retira(senhas, &s)) {
            printf(" %d", s);
        }
    }

    printf("\nChegaram:");
    for (int s = 37; s <= 40; s++) { // 39 e 40 dão a volta no vetor
        if (fila_insere(senhas, s)) {
            printf(" %d", s);
        }
    }

    printf("\nNa fila (%d):", fila_tamanho(senhas));
    int s;
    while (fila_retira(senhas, &s)) {
        printf(" %d", s);
    }
    printf("\n");

    fila_libera(senhas);
    return 0;
}
// Saída:
// Atendidas: 31 32 33 34
// Chegaram: 37 38 39 40
// Na fila (6): 35 36 37 38 39 40
```

```bash
~/LPEDC/rodar 12-pilhas-e-filas/0090-fila/A179.c
```

**Exemplo A180 · Painel cheio: a fila circular reaproveita as vagas**

```c
#include <stdio.h>
#include "fila.h"

int main(void) {
    Fila *f = fila_cria();
    if (f == NULL) {
        return 1;
    }

    // 9 senhas para um painel de 8: a última é recusada
    for (int s = 1; s <= 9; s++) {
        if (!fila_insere(f, s)) {
            printf("Senha %d recusada: painel cheio\n", s);
        }
    }

    // 3 atendimentos liberam as posições 0, 1 e 2 do vetor...
    int s;
    for (int i = 0; i < 3; i++) {
        fila_retira(f, &s);
    }

    // ...e as próximas senhas entram nelas, sem mover ninguém
    for (s = 9; s <= 11; s++) {
        if (fila_insere(f, s)) {
            printf("Senha %d entrou\n", s);
        }
    }

    fila_primeiro(f, &s);
    printf("Próxima a ser chamada: %d (de %d na fila)\n", s, fila_tamanho(f));
    fila_libera(f);
    return 0;
}
// Saída:
// Senha 9 recusada: painel cheio
// Senha 9 entrou
// Senha 10 entrou
// Senha 11 entrou
// Próxima a ser chamada: 4 (de 8 na fila)
```

```bash
~/LPEDC/rodar 12-pilhas-e-filas/0090-fila/A180.c
```

#### Exercícios

**Exercício E535** · ★☆☆

Faça o teste de mesa de uma fila circular como a do fila.c, mas com
CAPACIDADE 4. Para cada operação, anote o vetor (use _ para gaveta nunca
usada), inicio e n. Quando uma inserção for recusada, diga por quê.


```text
insere 1, insere 2, retira, insere 3, insere 4,
insere 5, insere 6, retira, retira
```


No fim: quem sobrou na fila, na ordem de saída? Em que gaveta entraria o
próximo?

<details>
<summary>Dicas</summary>

1. A posição de inserção é (inicio + n) % 4; retirar faz
   inicio = (inicio + 1) % 4.
2. Retirar não apaga a gaveta: o valor velho fica lá.
3. Resposta esperada: o 5 entra na gaveta 0 (deu a volta) e o vetor fica
   [5, 2, 3, 4] com inicio 1 e n 4; o 6 é recusado (n == 4, cheia). As
   retiradas finais devolvem 2 e 3. Sobram 4 e 5, com inicio 3 e n 2; o
   próximo entraria na gaveta (3 + 2) % 4 = 1.

</details>

```bash
~/LPEDC/rodar 12-pilhas-e-filas/0090-fila/E535.c
```

**Exercício E536** · ★☆☆

A impressora do escritório recebe quatro trabalhos, nesta ordem, com 3, 10,
2 e 5 páginas. Use o fila.h para guardar o número de páginas de cada
trabalho e depois "imprima" todos na ordem de chegada, mostrando o total no
fim.


```text
Saída esperada:
Trabalho 1: 3 páginas
Trabalho 2: 10 páginas
Trabalho 3: 2 páginas
Trabalho 4: 5 páginas
Total: 20 páginas em 4 trabalhos
```

<details>
<summary>Dicas</summary>

1. Guarde as páginas num vetor e insira com um for.
2. Antes de esvaziar a fila, guarde fila_tamanho num int: depois ela vale 0.
3. Resposta esperada: as cinco linhas acima.

</details>

```bash
~/LPEDC/rodar 12-pilhas-e-filas/0090-fila/E536.c
```

**Exercício E537** · ★★☆

Outra convenção muito comum de fila circular não guarda o contador n. Ela
guarda inicio (o próximo a sair) e fim (a próxima vaga) e SACRIFICA uma
gaveta: a fila está vazia quando inicio == fim e cheia quando
(fim + 1) % TAM == inicio. Com TAM 5, cabem só 4.

Complete as quatro funções. O main testa: insere 1 a 5 (o 5 é recusado),
retira dois, insere 6 e 7, tenta o 8 (recusado) e esvazia a fila.


```text
Saída esperada:
5 recusado: fila cheia
saiu 1
saiu 2
8 recusado: fila cheia
Na fila: 3 4 6 7
```

<details>
<summary>Dicas</summary>

1. fc_vazia e fc_cheia são uma linha cada, com as fórmulas do enunciado.
2. fc_insere grava em itens[fim] e avança fim com % TAM.
3. fc_retira lê itens[inicio] e avança inicio com % TAM.
4. Resposta esperada: as cinco linhas acima. O 6 entra na gaveta 4 e fim
   dá a volta para 0; o 7 entra na 0 e fim vira 1. Aí (1 + 1) % 5 == 2,
   que é o inicio: cheia, e o 8 é recusado.

</details>

```bash
~/LPEDC/rodar 12-pilhas-e-filas/0090-fila/E537.c
```

**Exercício E538** · ★★☆

O drive-thru da lanchonete usa uma fila circular com inicio, fim (próxima
vaga) e uma gaveta sacrificada. O programa compila sem aviso, nenhum
sanitizer reclama, e mesmo assim o telão mostra que há -2 carros na fila.
Ache o erro, explique por que ele só aparece depois de um tempo e
conserte.


```text
Saída esperada depois do conserto:
Carros na fila: 5
Carros na fila: 1
Carros na fila: 4
```

<details>
<summary>Dicas</summary>

1. Desenhe o vetor de 6 gavetas e acompanhe inicio e fim em cada etapa.
2. Na terceira linha, inicio = 4 e fim = 2. Quantos carros há de verdade?
3. Resposta esperada: tamanho faz fim - inicio, que só funciona enquanto a
   fila não deu a volta no vetor. Depois que fim volta para o começo,
   fim < inicio e a conta fica negativa. Conserto:
   return (f->fim - f->inicio + TAM) % TAM;

</details>

```bash
~/LPEDC/rodar 12-pilhas-e-filas/0090-fila/E538.c
```

**Exercício E539** · ★★★

Batata quente: 7 pessoas numeradas de 1 a 7 estão em roda. A batata passa
de mão em mão, e quem estiver com ela na 3ª passada sai. A contagem
recomeça de quem estava ao lado, até sobrar uma pessoa. (É o famoso
problema de Josephus.)

Resolva com o fila.h: a roda é a fila. "Passar a batata" é tirar do
início e pôr de novo no fim. Na 3ª pessoa, tire e não devolva. Mostre a
ordem de saída e quem sobrou.


```text
Saída esperada:
Saíram: 3 6 2 7 5 1
Sobrou: 4
```

<details>
<summary>Dicas</summary>

1. Insira 1 a 7. Enquanto fila_tamanho > 1: faça 2 vezes "retira e
   insere de novo"; na 3ª, retire e mostre.
2. A capacidade do fila.c é 8, então 7 pessoas cabem.
3. Cada eliminação custa m operações de fila: no total, O(n · m).
4. Resposta esperada: Saíram: 3 6 2 7 5 1 e Sobrou: 4.

</details>

```bash
~/LPEDC/rodar 12-pilhas-e-filas/0090-fila/E539.c
```

**Exercício E540** · ★★★

O app de corrida mostra a velocidade média dos últimos 3 registros do GPS
(uma média móvel). As leituras foram 60, 64, 70, 66, 58 e 62 km/h. A partir
da terceira leitura, mostre a média da janela.

A condição: nada de somar a janela inteira a cada leitura. Guarde a janela
numa fila do fila.h e mantenha uma soma: quando um valor entra, soma; quando
a janela passa de 3, o mais antigo sai da fila e é subtraído. Cada leitura
custa O(1), qualquer que seja o tamanho da janela.


```text
Saída esperada:
Leitura 3: média 64.7 km/h
Leitura 4: média 66.7 km/h
Leitura 5: média 64.7 km/h
Leitura 6: média 62.0 km/h
```

<details>
<summary>Dicas</summary>

1. A fila é a escolha certa porque o primeiro a sair da janela é o
   primeiro que entrou.
2. Faça a divisão em double: soma / 3.0.
3. Resposta esperada: as quatro linhas acima (194/3, 200/3, 194/3,
   186/3).

</details>

```bash
~/LPEDC/rodar 12-pilhas-e-filas/0090-fila/E540.c
```

---

## 0091 · Fila encadeada

Sexta à noite, a cozinha da pizzaria recebe os pedidos do app. O painel de 8
lugares do 0090 lotou às 20h, e o nono pedido foi recusado. Pedido recusado é
cliente perdido. A fila precisa crescer o quanto for preciso.

A solução é a mesma da pilha: trocar o vetor por **nós** encadeados. Só que a
fila mexe nas duas pontas, e isso muda o desenho. Pense nos ponteiros de uma
lista simples:

- **retirar** do começo é fácil: `inicio = inicio->prox`, O(1);
- **inserir** no fim exigiria andar a lista até o último, O(n)... a não ser
  que você guarde um segundo ponteiro, o **fim**, sempre apontando para o
  último nó. Aí inserir também é O(1): `fim->prox = novo; fim = novo`.

Repare na direção: a fila **sai pelo início e entra pelo fim**. O contrário
(entrar pelo início, sair pelo fim) não funciona bem numa lista simples,
porque para remover o último você precisaria do penúltimo, e o nó não sabe
quem está antes dele.

O [`fila.h`](0091-fila-encadeada/fila.h) é o mesmo do 0090, palavra por
palavra. O [`fila.c`](0091-fila-encadeada/fila.c) agora guarda dois
ponteiros, e os casos de borda moram neles:

```c
struct fila {
    NoFila *inicio; // o próximo a sair; NULL se vazia
    NoFila *fim;    // o último que entrou; NULL se vazia
    int n;
};

bool fila_insere(Fila *f, int valor) {
    NoFila *novo = malloc(sizeof *novo);
    if (novo == NULL) {
        return false;
    }
    novo->valor = valor;
    novo->prox = NULL; // vai ser o último
    if (f->fim == NULL) {
        f->inicio = novo; // fila vazia: o novo também é o primeiro
    } else {
        f->fim->prox = novo; // pendura atrás do último
    }
    f->fim = novo;
    f->n++;
    return true;
}

bool fila_retira(Fila *f, int *valor) {
    if (f->inicio == NULL) {
        return false;
    }
    NoFila *velho = f->inicio;
    *valor = velho->valor;
    f->inicio = velho->prox;
    if (f->inicio == NULL) {
        f->fim = NULL; // saiu o último: o fim não pode apontar para o nó liberado
    }
    free(velho);
    f->n--;
    return true;
}
```

Vamos ver na prática. Chegam os pedidos 501, 502 e 503. A cozinha pega o
501: o início anda para o 502 e o nó do 501 é liberado. Chega o 504, que é
pendurado depois do 503, e o fim passa a apontar para ele:

<p align="center"><img src="0091-fila-encadeada/ideia.svg" alt="Diagrama da ideia: Fila encadeada" width="858"></p>

O programa da cozinha:

```c
#include <stdio.h>
#include "fila.h"

int main(void) {
    Fila *pedidos = fila_cria();
    if (pedidos == NULL) {
        return 1;
    }

    fila_insere(pedidos, 501); // chegam três pedidos do app
    fila_insere(pedidos, 502);
    fila_insere(pedidos, 503);

    int p;
    if (fila_retira(pedidos, &p)) { // a cozinha pega o mais antigo
        printf("Preparando: %d\n", p);
    }
    fila_insere(pedidos, 504); // entra mais um, lá no fim

    // a fila agora é: inicio -> 502 -> 503 -> 504 <- fim
    if (fila_primeiro(pedidos, &p)) {
        printf("Próximo: %d (%d esperando)\n", p, fila_tamanho(pedidos));
    }

    fila_libera(pedidos); // libera os 3 nós que sobraram
    return 0;
}
// Saída:
// Preparando: 501
// Próximo: 502 (3 esperando)
```

Repara no fluxograma da entrada do 504: a fila não estava vazia, então o
caminho passa por `fim->prox = novo`. Na fila vazia, quem recebe o novo nó é
o `inicio`:

<p align="center"><img src="0091-fila-encadeada/fluxograma.svg" alt="Fluxograma: Fila encadeada" width="597"></p>

> [!WARNING]
> Os dois bugs clássicos estão nas bordas. Ao inserir na fila **vazia**,
> esquecer de atualizar o `inicio` deixa a fila "vazia" para sempre, mesmo
> com nós dentro. Ao retirar o **último**, esquecer de zerar o `fim` é pior:
> o `fim` continua apontando para o nó que acabou de levar `free`, e o
> próximo `fila_insere` escreve `fim->prox` em memória liberada. O
> AddressSanitizer acusa `heap-use-after-free`; sem ele, o programa às vezes
> funciona e às vezes corrompe o heap.

> [!TIP]
> **Por dentro do C:** a encadeada nunca recusa um pedido (só se acabar a
> memória), mas cada `fila_insere` chama o `malloc` e cada `fila_retira`
> chama o `free`. Essas chamadas custam bem mais que escrever numa gaveta de
> vetor: o alocador procura um bloco livre, guarda o tamanho dele num
> cabeçalho escondido e, de vez em quando, pede memória ao sistema
> operacional. Em sistemas que fazem milhões de operações por segundo, como
> servidores e jogos, o normal é a fila circular, crescendo com `realloc`
> quando enche, ou uma lista de nós reaproveitados.

> [!NOTE]
> **Pergunta para você:** no A182, se o cliente 3 levasse 1 minuto em vez de
> 4, quanto cada um esperaria? A maior fila mudaria? Simule à mão antes de
> rodar.

### Hora de praticar

Os arquivos ficam em [`0091-fila-encadeada/`](0091-fila-encadeada/). Os comandos funcionam de qualquer pasta do terminal. Nos exemplos, rode, mude, quebre e rode de novo. Nos exercícios, a resposta vai dentro do próprio arquivo. ★☆☆ é aquecimento, ★★☆ pede raciocínio e ★★★ é desafio.

**Exemplo A181 · Os pedidos da cozinha**

```c
#include <stdio.h>
#include "fila.h"

int main(void) {
    Fila *pedidos = fila_cria();
    if (pedidos == NULL) {
        return 1;
    }

    fila_insere(pedidos, 501); // chegam três pedidos do app
    fila_insere(pedidos, 502);
    fila_insere(pedidos, 503);

    int p;
    if (fila_retira(pedidos, &p)) { // a cozinha pega o mais antigo
        printf("Preparando: %d\n", p);
    }
    fila_insere(pedidos, 504); // entra mais um, lá no fim

    // a fila agora é: inicio -> 502 -> 503 -> 504 <- fim
    if (fila_primeiro(pedidos, &p)) {
        printf("Próximo: %d (%d esperando)\n", p, fila_tamanho(pedidos));
    }

    fila_libera(pedidos); // libera os 3 nós que sobraram
    return 0;
}
// Saída:
// Preparando: 501
// Próximo: 502 (3 esperando)
```

```bash
~/LPEDC/rodar 12-pilhas-e-filas/0091-fila-encadeada/A181.c
```

**Exemplo A182 · Simulando o caixa do mercado**

```c
#include <stdio.h>
#include "fila.h"

#define CLIENTES 5

int main(void) {
    int chegada[CLIENTES] = {0, 1, 2, 5, 6}; // minuto em que cada um chega
    int duracao[CLIENTES] = {3, 2, 4, 1, 2}; // minutos de atendimento

    Fila *fila = fila_cria(); // guarda o número de cada cliente
    if (fila == NULL) {
        return 1;
    }

    int proximo = 0;  // próximo cliente a chegar
    int restante = 0; // minutos que faltam para o caixa ficar livre
    int atendidos = 0, espera_total = 0, maior_fila = 0;

    for (int minuto = 0; atendidos < CLIENTES; minuto++) {
        while (proximo < CLIENTES && chegada[proximo] == minuto) {
            fila_insere(fila, proximo); // chegou: vai para o fim da fila
            proximo++;
        }
        if (restante == 0 && !fila_vazia(fila)) { // caixa livre: chama o próximo
            int c;
            fila_retira(fila, &c);
            int espera = minuto - chegada[c];
            printf("Minuto %2d: cliente %d no caixa (esperou %d)\n", minuto, c + 1, espera);
            espera_total += espera;
            restante = duracao[c];
            atendidos++;
        }
        if (fila_tamanho(fila) > maior_fila) {
            maior_fila = fila_tamanho(fila);
        }
        if (restante > 0) {
            restante--; // passa um minuto de atendimento
        }
    }
    printf("Espera média: %.1f min; maior fila: %d\n", (double)espera_total / CLIENTES, maior_fila);

    fila_libera(fila);
    return 0;
}
// Saída:
// Minuto  0: cliente 1 no caixa (esperou 0)
// Minuto  3: cliente 2 no caixa (esperou 2)
// Minuto  5: cliente 3 no caixa (esperou 3)
// Minuto  9: cliente 4 no caixa (esperou 4)
// Minuto 10: cliente 5 no caixa (esperou 4)
// Espera média: 2.6 min; maior fila: 2
```

```bash
~/LPEDC/rodar 12-pilhas-e-filas/0091-fila-encadeada/A182.c
```

#### Exercícios

**Exercício E541** · ★☆☆

Sem rodar, desenhe a lista da fila depois de cada operação do main, no
formato inicio -> ... -> NULL, marcando onde está o fim. Preveja a saída.
Depois responda: em quais momentos inicio e fim apontam para o MESMO nó?

<details>
<summary>Dicas</summary>

1. Insere pendura no fim; retira tira do início.
2. inicio == fim (sem ser NULL) quer dizer fila com um só nó.
3. Resposta esperada: mostra "7 4 9 " e depois "sobrou 1 (1 na fila)".
   A sequência é [7], [7, 4], [4], [4, 9], [9], [9, 1], [1]. inicio e
   fim apontam para o mesmo nó quando a fila tem um nó só: depois de
   inserir o 7 e depois de cada retirada.

</details>

```bash
~/LPEDC/rodar 12-pilhas-e-filas/0091-fila-encadeada/E541.c
```

**Exercício E542** · ★☆☆

Na UBS, a recepcionista digita as senhas que vão chegando até digitar 0.
Depois o painel chama todo mundo na ordem de chegada. Use o fila.h (aqui,
sem limite de tamanho). Se ninguém chegou, mostre "Ninguém na fila". Se o
scanf falhar, pare de ler como se fosse o 0.


```text
Senhas (0 para terminar): 12 15 18 0
Chamando senha 12
Chamando senha 15
Chamando senha 18
```

<details>
<summary>Dicas</summary>

1. while (scanf("%d", &s) == 1 && s != 0) fila_insere(...).
2. Use fila_vazia antes de começar a chamar.
3. Resposta esperada: as três chamadas acima; com só "0", "Ninguém na
   fila".

</details>

```bash
~/LPEDC/rodar 12-pilhas-e-filas/0091-fila-encadeada/E542.c
```

**Exercício E543** · ★★☆

A fila do caixa da padaria guarda o NOME de cada cliente, então o programa
traz a própria fila encadeada, com um texto em cada nó. Complete:

- entra: cria um nó com o nome e pendura no fim (cuidado com a fila vazia);
- sai: copia o nome do primeiro para destino, tira o nó e libera (cuidado
com a fila que fica vazia). Devolve false se não tinha ninguém.


```text
Saída esperada:
Atendendo Ana
Atendendo Bruno
Atendendo Carla
Atendendo Davi
Fila vazia
```

<details>
<summary>Dicas</summary>

1. Copie o nome com strcpy (os nomes do teste cabem em 30 bytes).
2. Em entra: se f->fim == NULL, o novo também vira f->inicio.
3. Em sai: se f->inicio virou NULL, f->fim também precisa virar NULL.
4. Resposta esperada: as cinco linhas acima, sem erro do sanitizer.

</details>

```bash
~/LPEDC/rodar 12-pilhas-e-filas/0091-fila-encadeada/E543.c
```

**Exercício E544** · ★★☆

A fila de pedidos da cozinha funciona bem no começo da noite. Mas o
sanitizer explode quando a fila esvazia e chega um pedido novo. Rode, leia
o relatório (procure "heap-use-after-free" e a linha) e conserte. Explique
por que o erro só aparece nessa situação.


```text
Saída esperada depois do conserto:
Pronto: 11
Pronto: 12
Pronto: 13
Pronto: 14
```

<details>
<summary>Dicas</summary>

1. Em que linha o relatório aponta? Que ponteiro está sendo usado ali?
2. Depois de cozinha_sai tirar o último pedido, para onde aponta f->fim?
3. Resposta esperada: cozinha_sai não zera o fim quando a fila esvazia.
   O fim continua apontando para o nó liberado, e o próximo cozinha_entra
   vê fim != NULL e escreve f->fim->prox nesse nó morto. Conserto: depois
   de avançar o início, if (f->inicio == NULL) f->fim = NULL;

</details>

```bash
~/LPEDC/rodar 12-pilhas-e-filas/0091-fila-encadeada/E544.c
```

**Exercício E545** · ★★★

No banco, a lei manda atender primeiro quem tem prioridade, mas sem largar
a fila comum esquecida. A regra da agência: chame 2 preferenciais, depois
1 comum, e repita. Se uma das filas estiver vazia, chame da outra.

Use duas filas do fila.h. As senhas preferenciais são 101, 102 e 103; as
comuns, 1, 2, 3 e 4. Mostre a ordem de chamada, com P na frente das
preferenciais e C na frente das comuns.


```text
Saída esperada:
Chamando: P101 P102 C1 P103 C2 C3 C4
```

<details>
<summary>Dicas</summary>

1. Um contador de preferenciais chamadas seguidas decide de qual fila
   tirar: se for menor que 2 e a preferencial não estiver vazia, tire
   dela; senão, tire da comum (e zere o contador).
2. Cuidado com o caso "contador chegou a 2, mas a comum está vazia": aí
   a preferencial continua.
3. O laço roda enquanto alguma das duas filas tiver gente.
4. Resposta esperada: Chamando: P101 P102 C1 P103 C2 C3 C4.

</details>

```bash
~/LPEDC/rodar 12-pilhas-e-filas/0091-fila-encadeada/E545.c
```

**Exercício E546** · ★★★

Dá para fazer uma fila com UM ponteiro só: numa lista circular, o último
nó aponta de volta para o primeiro. Guardando só ultimo, o primeiro é
ultimo->prox. Escreva do zero (sem o fila.h) as funções


```text
bool circ_insere(No **ultimo, int valor)
bool circ_retira(No **ultimo, int *valor)
```


e teste com a mesma história do A181: entram 501, 502 e 503, sai um, entra
o 504 e a fila é esvaziada.


```text
Saída esperada:
Preparando: 501
Depois: 502 503 504
```

<details>
<summary>Dicas</summary>

1. Fila vazia: ultimo == NULL. Com um nó só, ele aponta para ele mesmo.
2. Inserir: o novo aponta para o primeiro (ultimo->prox), o antigo
   último aponta para o novo, e o novo vira o último.
3. Retirar: o primeiro é ultimo->prox. Se ele for o próprio último (um
   nó só), a fila fica vazia; senão, ultimo->prox pula para o seguinte.
4. Resposta esperada: as duas linhas acima, sem vazamento.

</details>

```bash
~/LPEDC/rodar 12-pilhas-e-filas/0091-fila-encadeada/E546.c
```

---

## 0092 · Deque

No app de música, você monta a fila: faixa 5, faixa 8, faixa 3. Aí lembra de
uma que quer ouvir agora e toca em "tocar em seguida": a faixa 11 fura a fila
e vai para a **frente**. Depois desiste da última que adicionou e a tira do
**fim**. Nem pilha nem fila fazem isso.

Essa estrutura é o **deque** (*double-ended queue*, fala-se "deck"): uma
**fila dupla**, que entra e sai pelas **duas** pontas. São quatro operações
principais:

- `deque_insere_inicio` e `deque_retira_inicio`: mexem na frente;
- `deque_insere_fim` e `deque_retira_fim`: mexem no fundo.

O deque generaliza as duas estruturas que você já viu. Usando só uma ponta
(insere e retira no fim), ele é uma **pilha**. Inserindo no fim e retirando
no início, é uma **fila**. No JS, o array tem as quatro operações (`push`,
`pop`, `unshift`, `shift`), mas `unshift` e `shift` custam O(n), porque
deslocam todo mundo. Aqui as quatro custam **O(1)**.

A implementação do [`deque.c`](0092-deque/deque.c) é a fila circular do 0090
com uma novidade: o `inicio` agora também anda para **trás**. Para inserir na
frente, ele recua uma gaveta, e da gaveta 0 ele volta para a última. A conta
de "gaveta anterior" mora numa função auxiliar `static`, que só o `deque.c`
enxerga:

```c
#define CAPACIDADE 8

// gaveta anterior a i, dando a volta: anterior(0) = CAPACIDADE - 1
static int anterior(int i) {
    return (i - 1 + CAPACIDADE) % CAPACIDADE; // (i - 1) % CAPACIDADE daria -1 com i = 0
}

bool deque_insere_inicio(Deque *d, int valor) {
    if (d->n == CAPACIDADE) {
        return false;
    }
    d->inicio = anterior(d->inicio); // o início recua uma gaveta
    d->itens[d->inicio] = valor;
    d->n++;
    return true;
}

bool deque_retira_fim(Deque *d, int *valor) {
    if (d->n == 0) {
        return false;
    }
    *valor = d->itens[(d->inicio + d->n - 1) % CAPACIDADE]; // o último ocupado
    d->n--;
    return true;
}
```

`deque_insere_fim` e `deque_retira_inicio` são iguais aos da fila. Retirar
do fim é o mais simples de todos: basta diminuir `n`.

Vamos ver na prática. As faixas 5, 8 e 3 entram pelo fim, nas gavetas 0, 1
e 2. A faixa 11 entra pela frente: o início, que estava na gaveta 0, recua e
dá a volta para a gaveta 7. A ordem da fila fica 11, 5, 8, 3:

<p align="center"><img src="0092-deque/ideia.svg" alt="Diagrama da ideia: Deque" width="864"></p>

O programa da fila de músicas:

```c
#include <stdio.h>
#include "deque.h"

int main(void) {
    Deque *fila = deque_cria(); // guarda o número da faixa do álbum
    if (fila == NULL) {
        return 1;
    }

    deque_insere_fim(fila, 5); // "adicionar à fila": vai para o fim
    deque_insere_fim(fila, 8);
    deque_insere_fim(fila, 3);
    deque_insere_inicio(fila, 11); // "tocar em seguida": fura a fila

    // ordem agora: 11 5 8 3
    int faixa;
    if (deque_retira_inicio(fila, &faixa)) {
        printf("Tocando a faixa %d\n", faixa);
    }
    if (deque_retira_fim(fila, &faixa)) { // desistiu da última que adicionou
        printf("Removida a faixa %d\n", faixa);
    }

    printf("Ainda na fila:");
    while (deque_retira_inicio(fila, &faixa)) {
        printf(" %d", faixa);
    }
    printf("\n");

    deque_libera(fila);
    return 0;
}
// Saída:
// Tocando a faixa 11
// Removida a faixa 3
// Ainda na fila: 5 8
```

Repara no fluxograma da entrada da faixa 11: a única diferença para a fila é
o passo que faz o início recuar com `anterior`, que soma 8 antes do `%` para
o índice não ficar negativo:

<p align="center"><img src="0092-deque/fluxograma.svg" alt="Fluxograma: Deque" width="535"></p>

> [!WARNING]
> Em C, o resto de um número negativo é **negativo**: `-1 % 8` vale `-1`, não
> 7. (A matemática diria 7; o C17 manda a divisão truncar em direção ao zero,
> e o resto acompanha o sinal do dividendo.) Então `(inicio - 1) %
> CAPACIDADE`, com `inicio = 0`, dá `-1`, e `itens[-1]` escreve **fora** do
> vetor. Some a capacidade antes do `%`: `(inicio - 1 + CAPACIDADE) %
> CAPACIDADE`. O JS tem a mesma pegadinha: `-1 % 8` também dá `-1` lá.

> [!TIP]
> **Por dentro do C:** a palavra `static` numa função fora de qualquer bloco
> não tem nada a ver com variável estática: ela tira a função da **ligação
> externa**. O ligador nem fica sabendo que `anterior` existe, então outro
> arquivo pode ter a sua própria `anterior` sem conflito. É o jeito do C de
> fazer uma função **privada** do módulo, como um método `private` no TS. O
> deque com lista encadeada também é possível, mas precisa de lista **dupla**
> (assunto 0084): para retirar do fim, o último nó tem que saber quem é o
> penúltimo.

> [!NOTE]
> **Pergunta para você:** se o A183 fizesse mais um `deque_insere_inicio`
> logo depois do 11, em que gaveta o novo item cairia? E se o deque estivesse
> com as 8 gavetas ocupadas?

### Hora de praticar

Os arquivos ficam em [`0092-deque/`](0092-deque/). Os comandos funcionam de qualquer pasta do terminal. Nos exemplos, rode, mude, quebre e rode de novo. Nos exercícios, a resposta vai dentro do próprio arquivo. ★☆☆ é aquecimento, ★★☆ pede raciocínio e ★★★ é desafio.

**Exemplo A183 · A fila de músicas do streaming**

```c
#include <stdio.h>
#include "deque.h"

int main(void) {
    Deque *fila = deque_cria(); // guarda o número da faixa do álbum
    if (fila == NULL) {
        return 1;
    }

    deque_insere_fim(fila, 5); // "adicionar à fila": vai para o fim
    deque_insere_fim(fila, 8);
    deque_insere_fim(fila, 3);
    deque_insere_inicio(fila, 11); // "tocar em seguida": fura a fila

    // ordem agora: 11 5 8 3
    int faixa;
    if (deque_retira_inicio(fila, &faixa)) {
        printf("Tocando a faixa %d\n", faixa);
    }
    if (deque_retira_fim(fila, &faixa)) { // desistiu da última que adicionou
        printf("Removida a faixa %d\n", faixa);
    }

    printf("Ainda na fila:");
    while (deque_retira_inicio(fila, &faixa)) {
        printf(" %d", faixa);
    }
    printf("\n");

    deque_libera(fila);
    return 0;
}
// Saída:
// Tocando a faixa 11
// Removida a faixa 3
// Ainda na fila: 5 8
```

```bash
~/LPEDC/rodar 12-pilhas-e-filas/0092-deque/A183.c
```

**Exemplo A184 · Palíndromo com deque: compara as duas pontas**

```c
#include <stdbool.h>
#include <stdio.h>
#include "deque.h"

bool palindromo(const char *palavra) {
    Deque *d = deque_cria();
    if (d == NULL) {
        return false;
    }
    for (int i = 0; palavra[i] != '\0'; i++) {
        deque_insere_fim(d, palavra[i]); // até 8 letras: a capacidade do deque.c
    }
    bool ok = true;
    // tira uma letra de cada ponta enquanto sobrarem pelo menos duas
    while (deque_tamanho(d) > 1 && ok) {
        int frente, tras;
        deque_retira_inicio(d, &frente);
        deque_retira_fim(d, &tras);
        if (frente != tras) {
            ok = false;
        }
    }
    deque_libera(d);
    return ok;
}

int main(void) {
    const char *palavras[] = {"RADAR", "REVIVER", "PRATO", "OSSO"};
    for (int i = 0; i < 4; i++) {
        printf("%-8s %s\n", palavras[i], palindromo(palavras[i]) ? "é palíndromo" : "não é");
    }
    return 0;
}
// Saída:
// RADAR    é palíndromo
// REVIVER  é palíndromo
// PRATO    não é
// OSSO     é palíndromo
```

```bash
~/LPEDC/rodar 12-pilhas-e-filas/0092-deque/A184.c
```

#### Exercícios

**Exercício E547** · ★☆☆

Sem rodar, preveja a saída. Desenhe o deque como uma fileira, com a
frente à esquerda, e atualize a cada operação.

<details>
<summary>Dicas</summary>

1. insere_inicio põe à esquerda; insere_fim, à direita.
2. primeiro e ultimo só olham.
3. Resposta esperada: a ordem depois das quatro inserções é 4 2 1 3. A
   saída é "saiu do fim: 3", "saiu da frente: 4" e "frente 2, fundo 1,
   tamanho 2".

</details>

```bash
~/LPEDC/rodar 12-pilhas-e-filas/0092-deque/E547.c
```

**Exercício E548** · ★☆☆

Num vetor circular de cap gavetas, escreva a função
int volta(int i, int passos, int cap), que devolve a gaveta que fica
passos casas ANTES de i, dando a volta quantas vezes for preciso. passos
pode ser maior que cap. Antes, mostre com printf quanto o C calcula para
-1 % 8 e -9 % 8 (e repare no sinal).


```text
Saída esperada:
-1 % 8 = -1
-9 % 8 = -1
volta(0, 1, 8) = 7
volta(3, 5, 8) = 6
volta(2, 18, 8) = 0
```

<details>
<summary>Dicas</summary>

1. (i - passos) pode ser bem negativo. Primeiro reduza passos com
   passos % cap, aí i - passos fica maior que -cap.
2. Depois some cap e tire o resto: (i - passos % cap + cap) % cap.
3. Para mostrar o %, escreva %% dentro do printf.
4. Resposta esperada: as cinco linhas acima.

</details>

```bash
~/LPEDC/rodar 12-pilhas-e-filas/0092-deque/E548.c
```

**Exercício E549** · ★★☆

No vôlei, os 6 jogadores de um time fazem rodízio. Guarde os números 1 a 6
num deque do deque.h e escreva três funções que usam só a interface:

- void mostra(Deque *d): mostra os itens da frente para o fundo, sem
perder nenhum (o deque tem que ficar igual);
- void gira_esquerda(Deque *d, int k): o da frente vai para o fundo, k
vezes;
- void gira_direita(Deque *d, int k): o do fundo vem para a frente, k
vezes.


```text
Saída esperada:
Início: 1 2 3 4 5 6
Esquerda 2: 3 4 5 6 1 2
Direita 3: 6 1 2 3 4 5
```

<details>
<summary>Dicas</summary>

1. mostra pode girar o deque uma volta completa: tira da frente, mostra e
   põe no fundo, deque_tamanho vezes.
2. gira_direita é o espelho: retira_fim e insere_inicio.
3. Cada giro custa O(1). Num vetor comum, girar uma posição custaria
   O(n), porque todo mundo anda uma casa.
4. Resposta esperada: as três linhas acima.

</details>

```bash
~/LPEDC/rodar 12-pilhas-e-filas/0092-deque/E549.c
```

**Exercício E550** · ★★☆

Embarque no avião: quem viaja com criança de colo entra na frente da fila;
o resto entra no fim. Este programa traz o próprio deque circular e
compila sem aviso, mas o sanitizer reclama logo no primeiro passageiro
com criança. Rode, leia a mensagem ("index -1 out of bounds") e conserte.


```text
Saída esperada depois do conserto:
Embarcando: 40 10 20 30
```

<details>
<summary>Dicas</summary>

1. Com inicio = 0, quanto vale (inicio - 1) % TAM em C?
2. Releia a pegadinha do resto negativo no texto do assunto.
3. Resposta esperada: em entra_na_frente, (e->inicio - 1) % TAM dá -1
   quando inicio é 0, porque em C o resto acompanha o sinal do dividendo.
   Conserto: e->inicio = (e->inicio - 1 + TAM) % TAM;

</details>

```bash
~/LPEDC/rodar 12-pilhas-e-filas/0092-deque/E550.c
```

**Exercício E551** · ★★★

O deque também pode ser feito com nós, mas precisa de lista DUPLA: para
retirar do fim, o último nó tem que saber quem é o penúltimo (o ant).
Complete as quatro operações deste deque encadeado, sem limite de
capacidade. O main repete a história da fila de músicas do A183.


```text
Saída esperada:
Tocando a faixa 11
Removida a faixa 3
Ainda na fila: 5 8
```

<details>
<summary>Dicas</summary>

1. Deque vazio: inicio == fim == NULL. Inserir no vazio faz os dois
   apontarem para o novo nó.
2. Inserir no início: novo->prox = inicio; inicio->ant = novo (se havia
   alguém); inicio = novo. O fim é o espelho, com ant e prox trocados.
3. Retirar do fim: o novo fim é fim->ant. Se ele for NULL, o deque
   esvaziou e inicio também vira NULL; senão, o novo fim fica com
   prox = NULL.
4. Resposta esperada: as três linhas acima, sem erro do sanitizer.

</details>

```bash
~/LPEDC/rodar 12-pilhas-e-filas/0092-deque/E551.c
```

**Exercício E552** · ★★★

As máximas de 8 dias foram 24, 27, 22, 25, 30, 21, 19 e 23 graus. Para
cada janela de 3 dias seguidos, mostre a maior temperatura. O jeito óbvio
olha os 3 dias de cada janela. O jeito esperto, com um deque, faz o
trabalho todo em O(n), qualquer que seja o tamanho da janela.

A ideia: o deque guarda ÍNDICES de dias, com as temperaturas em ordem
decrescente da frente para o fundo. Para cada dia i:

- enquanto a temperatura do índice no FUNDO for menor ou igual à do dia
i, retire do fundo (esse dia nunca mais vai ser máximo);
- insira i no fundo;
- se o índice da FRENTE saiu da janela (i - frente >= 3), retire da
frente;
- a partir do dia 3 (i >= 2), a frente é a máxima da janela.


```text
Saída esperada:
Dias 1-3: máxima 27
Dias 2-4: máxima 27
Dias 3-5: máxima 30
Dias 4-6: máxima 30
Dias 5-7: máxima 30
Dias 6-8: máxima 23
```

<details>
<summary>Dicas</summary>

1. Use deque_ultimo e deque_primeiro para olhar as pontas sem tirar.
2. O deque nunca guarda mais que 3 índices, então a capacidade 8 do
   deque.c sobra.
3. Cada índice entra uma vez e sai no máximo uma vez: O(n) no total.
4. Resposta esperada: as seis linhas acima.

</details>

```bash
~/LPEDC/rodar 12-pilhas-e-filas/0092-deque/E552.c
```

---

## 0093 · Juntando tudo: a calculadora de expressões

Lembra da conta do bar do 0089? Lá, você mesmo escreveu `35 25 + 3 * 4 /`
na notação pós-fixa. Ninguém digita assim no celular. A pessoa quer digitar
`(35 + 25) * 3 / 4` e ver 45. O programa do módulo faz o caminho inteiro, e
usa as duas estruturas: uma **fila** e duas **pilhas**.

São duas etapas, uma linha de produção:

1. **converter** a infixa para pós-fixa. Os números vão direto para uma
   fila de saída, na ordem em que aparecem. Os operadores esperam numa
   **pilha**: um operador só pode ir para a fila quando ninguém mais forte
   precisa passar na frente. É o algoritmo do **pátio de manobras**
   (*shunting-yard*), de Dijkstra, o mesmo do exercício E533;
2. **avaliar** a pós-fixa. Os itens saem da fila na ordem em que entraram
   (FIFO, exatamente o que a pós-fixa exige) e passam por uma **pilha de
   valores**, como no A178.

Por que fila no meio, e não uma string? Porque a etapa 1 produz itens e a
etapa 2 consome itens, um de cada vez, na mesma ordem. É o padrão
**produtor e consumidor**, o mesmo de um *pipe* no terminal ou de uma fila de
mensagens entre dois serviços. E a fila guarda o número 35 inteiro, sem
precisar juntar dígitos de novo.

Um detalhe: a fila e a pilha do curso só guardam `int`. Como fazer caber um
`+` ali? Os números da calculadora são sempre `>= 0`, então os operadores
viram **códigos negativos** com um `enum` (assunto 0068): `SOMA = -1`,
`SUB = -2` e assim por diante. Na hora de avaliar, `t >= 0` é número e
`t < 0` é operador. É um truque comum quando o tipo é fixo; a alternativa
seria uma `struct` com uma etiqueta dizendo o que o item é.

As regras da conversão, para cada símbolo lido:

- número: vai para a **fila**;
- `(`: empilha;
- `)`: desempilha para a fila até achar o `(`, que é descartado;
- operador: enquanto o topo tiver precedência **maior ou igual**, desempilha
  para a fila; depois empilha o operador;
- fim: o que sobrou na pilha vai para a fila.

Vamos ver na prática. Com `(35 + 25) * 3 / 4`, a fila de saída fica
`35 25 + 3 * 4 /`. Na avaliação, a pilha de valores chega a ter 180 e 4
quando aparece o `/`, e a última conta dá 45:

<p align="center"><img src="0093-juntando-tudo/ideia.svg" alt="Diagrama da ideia: Juntando tudo: a calculadora de expressões" width="862"></p>

O programa completo. A pasta tem o `pilha.h`/`pilha.c` do 0088 e o
`fila.h`/`fila.c` do 0091, e o `rodar` compila os quatro junto:

```c
#include <stdbool.h>
#include <stdio.h>
#include "fila.h"
#include "pilha.h"

// Na fila e na pilha só cabe int. Números são >= 0; operadores e o "("
// viram códigos negativos, que nunca se confundem com um número.
enum { SOMA = -1, SUB = -2, MULT = -3, DIV = -4, ABRE = -5 };

int codigo_de(char c) {
    return c == '+' ? SOMA : c == '-' ? SUB : c == '*' ? MULT : DIV;
}

int precedencia(int op) {
    return (op == MULT || op == DIV) ? 2 : (op == SOMA || op == SUB) ? 1 : 0; // ABRE: 0
}

// Etapa 1: infixa -> fila em ordem pós-fixa. A pilha segura os operadores.
bool converte(const char *s, Fila *saida) {
    Pilha *ops = pilha_cria();
    if (ops == NULL) {
        return false;
    }
    int topo;
    for (int i = 0; s[i] != '\0'; i++) {
        char c = s[i];
        if (c >= '0' && c <= '9') {
            int numero = 0;
            for (; s[i] >= '0' && s[i] <= '9'; i++) {
                numero = numero * 10 + (s[i] - '0');
            }
            i--;
            fila_insere(saida, numero); // número vai direto para a saída
        } else if (c == '(') {
            pilha_empilha(ops, ABRE);
        } else if (c == ')') {
            while (pilha_desempilha(ops, &topo) && topo != ABRE) {
                fila_insere(saida, topo);
            }
        } else if (c == '+' || c == '-' || c == '*' || c == '/') {
            int op = codigo_de(c);
            // sai antes quem tem precedência maior ou igual (conta da esquerda primeiro)
            while (pilha_topo(ops, &topo) && precedencia(topo) >= precedencia(op)) {
                pilha_desempilha(ops, &topo);
                fila_insere(saida, topo);
            }
            pilha_empilha(ops, op);
        }
    }
    while (pilha_desempilha(ops, &topo)) {
        fila_insere(saida, topo);
    }
    pilha_libera(ops);
    return true;
}

// Etapa 2: consome a fila pós-fixa com uma pilha de valores.
bool avalia(Fila *posfixa, int *resultado) {
    Pilha *val = pilha_cria();
    if (val == NULL) {
        return false;
    }
    bool ok = true;
    int t, a, b;
    printf("Pós-fixa: ");
    while (ok && fila_retira(posfixa, &t)) {
        if (t >= 0) {
            printf(" %d", t);
            pilha_empilha(val, t);
        } else if (!pilha_desempilha(val, &b) || !pilha_desempilha(val, &a) || (t == DIV && b == 0)) {
            ok = false;
        } else {
            printf(" %c", t == SOMA ? '+' : t == SUB ? '-' : t == MULT ? '*' : '/');
            pilha_empilha(val, t == SOMA ? a + b : t == SUB ? a - b : t == MULT ? a * b : a / b);
        }
    }
    printf("\n");
    ok = ok && pilha_desempilha(val, resultado) && pilha_vazia(val);
    pilha_libera(val);
    return ok;
}

int main(void) {
    const char *contas[] = {"(35 + 25) * 3 / 4", "2 * (3 + 4) - 10 / 5"};
    for (int i = 0; i < 2; i++) {
        Fila *posfixa = fila_cria();
        if (posfixa == NULL) {
            return 1;
        }
        int r;
        printf("Infixa:    %s\n", contas[i]);
        if (converte(contas[i], posfixa) && avalia(posfixa, &r)) {
            printf("Resultado: %d\n", r);
        } else {
            printf("Expressão inválida\n");
        }
        fila_libera(posfixa);
    }
    return 0;
}
// Saída:
// Infixa:    (35 + 25) * 3 / 4
// Pós-fixa:  35 25 + 3 * 4 /
// Resultado: 45
// Infixa:    2 * (3 + 4) - 10 / 5
// Pós-fixa:  2 3 4 + * 10 5 / -
// Resultado: 12
```

Repara no fluxograma: as duas etapas ficam em sequência, e as perguntas de
erro só aparecem na avaliação, que é onde falta de operando e divisão por
zero se revelam:

<p align="center"><img src="0093-juntando-tudo/fluxograma.svg" alt="Fluxograma: Juntando tudo: a calculadora de expressões" width="612"></p>

O segundo exemplo, A186, junta fila e pilha de outro jeito: as letras de uma
frase entram nas duas ao mesmo tempo. A fila devolve na ordem original, a
pilha devolve ao contrário. Se as duas sequências baterem letra por letra, a
frase é um palíndromo.

> [!WARNING]
> O "maior **ou igual**" da conversão não é detalhe. Com só "maior", `8 - 3 -
> 2` vira `8 3 2 - -`, que calcula `8 - (3 - 2) = 7`. O certo é
> `(8 - 3) - 2 = 3`: operadores de mesma precedência associam **à esquerda**,
> então o que já está na pilha sai antes do novo. (A potência é a exceção que
> associa à direita, e por isso este programa não tem `^`.) Esse é o bug do
> E556.

> [!TIP]
> **Por dentro do C:** os quatro `.c` da pasta são compilados separados e
> juntados pelo ligador. O nó da pilha se chama `No` e o da fila, `NoFila`,
> mas, compilados separados, os dois poderiam se chamar `No`: tipo não tem
> ligação, ele só existe dentro do arquivo que o declara, e o ligador nunca o
> vê. Conflito haveria se os dois definissem uma **função** com o mesmo nome,
> como `cria`: por isso cada TAD prefixa as suas (`pilha_`, `fila_`). Repare também no custo: cada
> símbolo da expressão entra e sai da fila uma vez e de cada pilha no máximo
> uma vez, então a calculadora inteira é **O(n)** no tamanho da expressão.

> [!NOTE]
> **Pergunta para você:** como fica a pós-fixa de `100 / (2 + 3) - 4`? E o
> resultado? Faça a conversão à mão, com a pilha de operadores desenhada,
> antes de trocar a expressão no A185.

### Hora de praticar

Os arquivos ficam em [`0093-juntando-tudo/`](0093-juntando-tudo/). Os comandos funcionam de qualquer pasta do terminal. Nos exemplos, rode, mude, quebre e rode de novo. Nos exercícios, a resposta vai dentro do próprio arquivo. ★☆☆ é aquecimento, ★★☆ pede raciocínio e ★★★ é desafio.

**Exemplo A185 · A calculadora completa: infixa, pós-fixa e resultado**

```c
#include <stdbool.h>
#include <stdio.h>
#include "fila.h"
#include "pilha.h"

// Na fila e na pilha só cabe int. Números são >= 0; operadores e o "("
// viram códigos negativos, que nunca se confundem com um número.
enum { SOMA = -1, SUB = -2, MULT = -3, DIV = -4, ABRE = -5 };

int codigo_de(char c) {
    return c == '+' ? SOMA : c == '-' ? SUB : c == '*' ? MULT : DIV;
}

int precedencia(int op) {
    return (op == MULT || op == DIV) ? 2 : (op == SOMA || op == SUB) ? 1 : 0; // ABRE: 0
}

// Etapa 1: infixa -> fila em ordem pós-fixa. A pilha segura os operadores.
bool converte(const char *s, Fila *saida) {
    Pilha *ops = pilha_cria();
    if (ops == NULL) {
        return false;
    }
    int topo;
    for (int i = 0; s[i] != '\0'; i++) {
        char c = s[i];
        if (c >= '0' && c <= '9') {
            int numero = 0;
            for (; s[i] >= '0' && s[i] <= '9'; i++) {
                numero = numero * 10 + (s[i] - '0');
            }
            i--;
            fila_insere(saida, numero); // número vai direto para a saída
        } else if (c == '(') {
            pilha_empilha(ops, ABRE);
        } else if (c == ')') {
            while (pilha_desempilha(ops, &topo) && topo != ABRE) {
                fila_insere(saida, topo);
            }
        } else if (c == '+' || c == '-' || c == '*' || c == '/') {
            int op = codigo_de(c);
            // sai antes quem tem precedência maior ou igual (conta da esquerda primeiro)
            while (pilha_topo(ops, &topo) && precedencia(topo) >= precedencia(op)) {
                pilha_desempilha(ops, &topo);
                fila_insere(saida, topo);
            }
            pilha_empilha(ops, op);
        }
    }
    while (pilha_desempilha(ops, &topo)) {
        fila_insere(saida, topo);
    }
    pilha_libera(ops);
    return true;
}

// Etapa 2: consome a fila pós-fixa com uma pilha de valores.
bool avalia(Fila *posfixa, int *resultado) {
    Pilha *val = pilha_cria();
    if (val == NULL) {
        return false;
    }
    bool ok = true;
    int t, a, b;
    printf("Pós-fixa: ");
    while (ok && fila_retira(posfixa, &t)) {
        if (t >= 0) {
            printf(" %d", t);
            pilha_empilha(val, t);
        } else if (!pilha_desempilha(val, &b) || !pilha_desempilha(val, &a) || (t == DIV && b == 0)) {
            ok = false;
        } else {
            printf(" %c", t == SOMA ? '+' : t == SUB ? '-' : t == MULT ? '*' : '/');
            pilha_empilha(val, t == SOMA ? a + b : t == SUB ? a - b : t == MULT ? a * b : a / b);
        }
    }
    printf("\n");
    ok = ok && pilha_desempilha(val, resultado) && pilha_vazia(val);
    pilha_libera(val);
    return ok;
}

int main(void) {
    const char *contas[] = {"(35 + 25) * 3 / 4", "2 * (3 + 4) - 10 / 5"};
    for (int i = 0; i < 2; i++) {
        Fila *posfixa = fila_cria();
        if (posfixa == NULL) {
            return 1;
        }
        int r;
        printf("Infixa:    %s\n", contas[i]);
        if (converte(contas[i], posfixa) && avalia(posfixa, &r)) {
            printf("Resultado: %d\n", r);
        } else {
            printf("Expressão inválida\n");
        }
        fila_libera(posfixa);
    }
    return 0;
}
// Saída:
// Infixa:    (35 + 25) * 3 / 4
// Pós-fixa:  35 25 + 3 * 4 /
// Resultado: 45
// Infixa:    2 * (3 + 4) - 10 / 5
// Pós-fixa:  2 3 4 + * 10 5 / -
// Resultado: 12
```

```bash
~/LPEDC/rodar 12-pilhas-e-filas/0093-juntando-tudo/A185.c
```

**Exemplo A186 · Palíndromo com uma fila e uma pilha**

```c
#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include "fila.h"
#include "pilha.h"

// A fila devolve as letras na ordem em que entraram; a pilha, ao contrário.
// Se as duas sequências forem iguais, a frase é um palíndromo.
bool palindromo(const char *frase) {
    Fila *f = fila_cria();
    Pilha *p = pilha_cria();
    bool ok = f != NULL && p != NULL;
    for (int i = 0; ok && frase[i] != '\0'; i++) {
        unsigned char c = (unsigned char)frase[i];
        if (isalpha(c)) { // ignora espaços e pontuação
            int letra = toupper(c);
            fila_insere(f, letra);
            pilha_empilha(p, letra);
        }
    }
    int da_fila, da_pilha;
    while (ok && fila_retira(f, &da_fila) && pilha_desempilha(p, &da_pilha)) {
        if (da_fila != da_pilha) {
            ok = false;
        }
    }
    if (f != NULL) {
        fila_libera(f);
    }
    if (p != NULL) {
        pilha_libera(p);
    }
    return ok;
}

int main(void) {
    // sem acentos de propósito: em UTF-8, "ô" ocupa 2 bytes e isalpha não o
    // reconhece como letra
    const char *frases[] = {"Socorram-me, subi no onibus em Marrocos", "A base do teto desaba", "Pilha e fila"};
    for (int i = 0; i < 3; i++) {
        printf("%s: %s\n", frases[i], palindromo(frases[i]) ? "sim" : "não");
    }
    return 0;
}
// Saída:
// Socorram-me, subi no onibus em Marrocos: sim
// A base do teto desaba: sim
// Pilha e fila: não
```

```bash
~/LPEDC/rodar 12-pilhas-e-filas/0093-juntando-tudo/A186.c
```

#### Exercícios

**Exercício E553** · ★☆☆

Faça à mão a conversão de 2 * (3 + 4) com as regras do texto. Para cada
símbolo, anote o que está na pilha de operadores e o que já está na fila
de saída. Depois avalie a fila com a pilha de valores.

<details>
<summary>Dicas</summary>

1. Comece com a pilha e a fila vazias. O 2 vai direto para a fila.
2. O "(" sempre empilha; o "+" que vem depois não tira o "*" de lá,
   porque o "(" está no meio.
3. Resposta esperada: depois do "4", a pilha é * ( + e a fila é 2 3 4.
   O ")" manda o + para a fila e descarta o "(". No fim, o * sai. Pós-fixa:
   2 3 4 + *. Avaliação: 2 | 2 3 | 2 3 4 | 2 7 | 14. Resultado: 14.

</details>

```bash
~/LPEDC/rodar 12-pilhas-e-filas/0093-juntando-tudo/E553.c
```

**Exercício E554** · ★☆☆

O sistema da fila do banco chamou as senhas ao contrário por engano, e
agora é preciso desfazer a ordem. Escreva void inverte(Fila *f), que
inverte a ordem da fila usando uma pilha auxiliar (as duas da pasta).
Teste com a fila 10 20 30 40.


```text
Saída esperada:
Antes: 10 20 30 40
Depois: 40 30 20 10
```

<details>
<summary>Dicas</summary>

1. Esvazie a fila na pilha; depois esvazie a pilha na fila.
2. Para mostrar a fila sem perder ninguém, retire, mostre e insira de
   novo, fila_tamanho vezes.
3. Resposta esperada: as duas linhas acima.

</details>

```bash
~/LPEDC/rodar 12-pilhas-e-filas/0093-juntando-tudo/E554.c
```

**Exercício E555** · ★★☆

Pergunta clássica de entrevista: faça uma FILA usando só duas PILHAS.
Escreva um tipo FilaDuasPilhas com duas Pilha * (entrada e saida) e as
funções fdp_insere e fdp_retira:

- inserir: empilha na entrada;
- retirar: se a saida estiver vazia, despeje a entrada inteira nela
(isso inverte a ordem); depois desempilhe da saida.

Teste: insira 1, 2 e 3, retire um, insira 4 e retire todos.


```text
Saída esperada:
Saiu: 1
Depois: 2 3 4
```

<details>
<summary>Dicas</summary>

1. Só despeje quando a saida estiver VAZIA. Despejar com a saida ainda
   cheia mistura a ordem.
2. Cada item é empilhado e desempilhado no máximo duas vezes, então,
   na média, cada operação custa O(1) (custo amortizado), mesmo que um
   despejo isolado custe O(n).
3. Resposta esperada: as duas linhas acima.

</details>

```bash
~/LPEDC/rodar 12-pilhas-e-filas/0093-juntando-tudo/E555.c
```

**Exercício E556** · ★★☆

Esta versão enxuta da calculadora (operandos de um dígito, sem
parênteses) acerta 2+3*4, mas erra 8-3-2 e 9/3/3. Compila sem aviso e o
sanitizer não reclama: o erro é de lógica. Rode, compare as pós-fixas com
as que você faria à mão, ache a linha e conserte.


```text
Saída esperada depois do conserto:
2+3*4 -> 2 3 4 * + = 14
8-3-2 -> 8 3 - 2 - = 3
9/3/3 -> 9 3 / 3 / = 1
```

<details>
<summary>Dicas</summary>

1. Compare "8 3 2 - -" com "8 3 - 2 -". Qual conta cada uma faz?
2. Quando chega um operador com a MESMA precedência do topo, quem deve
   ir primeiro para a fila: o que já estava na pilha ou o novo?
3. Resposta esperada: o while da conversão usa ">" e deveria usar ">=".
   Com ">", operadores iguais ficam empilhados e a conta associa à
   direita: 8 - (3 - 2) = 7 e 9 / (3 / 3) = 9.

</details>

```bash
~/LPEDC/rodar 12-pilhas-e-filas/0093-juntando-tudo/E556.c
```

**Exercício E557** · ★★★

O estacionamento da vila é um beco sem saída onde cabem 4 carros em fila
indiana: quem entrou por último fica na boca do beco. Para um carro do
fundo sair, todos os que estão na frente dele saem para a rua (cada um
conta uma MANOBRA), ele vai embora, e os outros voltam na mesma ordem.
Com o beco cheio, quem chega espera numa fila na rua e entra assim que
abrir uma vaga.

Simule com uma pilha (o beco), uma pilha auxiliar (a rua, na manobra) e
uma fila (a espera). Os eventos são: entram 1, 2, 3, 4 e 5; saem 2, 1, 4,
3 e 5. Ao sair, mostre quantas manobras aquele carro fez.


```text
Saída esperada:
Carro 5 espera na rua
Carro 2 saiu; manobras: 0
Carro 5 entrou (vinha da fila)
Carro 1 saiu; manobras: 0
Carro 4 saiu; manobras: 2
Carro 3 saiu; manobras: 2
Carro 5 saiu; manobras: 3
```

<details>
<summary>Dicas</summary>

1. Guarde as manobras num vetor int manobras[6], indexado pelo número do
   carro.
2. Para tirar o carro X: desempilhe do beco para a auxiliar até achar X
   (somando 1 nas manobras de cada um que saiu), descarte X e devolva
   todos da auxiliar para o beco.
3. Depois de cada saída, se a fila de espera não estiver vazia, o
   primeiro entra no beco.
4. Represente os eventos com dois vetores: char tipo[] = "EEEEESSSSS" e
   int carro[] = {1, 2, 3, 4, 5, 2, 1, 4, 3, 5}.
5. Resposta esperada: as sete linhas acima.

</details>

```bash
~/LPEDC/rodar 12-pilhas-e-filas/0093-juntando-tudo/E557.c
```

**Exercício E558** · ★★★

O sistema operacional divide a CPU entre os processos com o rodízio
(round-robin): cada processo da fila roda no máximo 2 ms (o quantum). Se
terminou, sai; se não, volta para o FIM da fila com o tempo que falta.
Quatro processos chegam juntos, nesta ordem: P1 precisa de 5 ms, P2 de 3,
P3 de 1 e P4 de 4.

Simule com uma fila do fila.h (guardando o número do processo) e um vetor
com o tempo restante de cada um. Mostre o instante em que cada processo
termina e o tempo médio de término.


```text
Saída esperada:
t = 5 ms: P3 terminou
t = 10 ms: P2 terminou
t = 12 ms: P4 terminou
t = 13 ms: P1 terminou
Tempo médio de término: 10.0 ms
```

<details>
<summary>Dicas</summary>

1. A cada volta: retire um processo, rode min(2, restante) ms somando no
   relógio, desconte do restante e, se ainda sobrar, insira de novo.
2. Faça o teste de mesa da fila antes: [1 2 3 4], [2 3 4 1], [3 4 1 2]...
3. Resposta esperada: as cinco linhas acima ((13 + 10 + 5 + 12) / 4).

</details>

```bash
~/LPEDC/rodar 12-pilhas-e-filas/0093-juntando-tudo/E558.c
```

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
Simule com o `simula` do E521.

</details>

**2. Tags HTML balanceadas.** Escreva um verificador para tags simples, sem
atributos: `<p><b>oi</b></p>` está certo, `<p><b>oi</p></b>` não. Teste
também com `<ul><li>a</li><li>b</li></ul>`.

<details><summary>Resposta</summary>

Primeiro, segundo e terceiro: certo, errado, certo. É o A177 com palavras no
lugar de caracteres: ao ler `<nome>`, empilhe o nome (numa pilha de strings
encadeada, como a do E525); ao ler `</nome>`, desempilhe e compare com
`strcmp`. No fim, a pilha precisa estar vazia.

</details>

**3. Duas pilhas, uma fila e o custo.** Na fila com duas pilhas do E555,
faça 1000 inserções seguidas e depois 1000 retiradas. Quantos `pilha_empilha`
acontecem no total? E se você alternar uma inserção e uma retirada?

<details><summary>Resposta</summary>

No primeiro caso, 2000: cada item é empilhado na entrada e depois uma vez na
saída (o despejo único acontece na primeira retirada). Alternando, também
2000: cada item ainda passa uma vez por cada pilha. É o **custo amortizado**:
uma retirada pode custar O(n), mas a média por operação é O(1).

</details>

**4. Fila circular que cresce.** Mude o `fila.c` do 0090 para começar com 4
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

**5. O caixa com dois atendentes.** Refaça o A182 com dois caixas e uma fila
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

**10. Avaliar com variáveis.** Estenda o A185 para aceitar letras como
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
