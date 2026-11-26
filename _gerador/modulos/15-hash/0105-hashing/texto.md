## 0105 · A ideia e a função hash

Num vetor, `v[i]` custa **O(1)**: o C calcula o endereço da posição `i` e vai
direto a ela, sem olhar as outras. A busca sequencial e a binária não têm essa
sorte, porque precisam comparar a chave com vários itens até achar o certo. A
tabela hash nasce de uma pergunta simples: dá para transformar a chave num
índice e ter o acesso direto do vetor para qualquer tipo de chave?

Quando a chave já é um número pequeno, a resposta é sim, e de graça. Com
`const char *estado[100]`, o DDD 61 serve de índice e `estado[61]` devolve "DF"
num passo só. Isso se chama **endereçamento direto**: a chave é o próprio
índice do vetor (TENENBAUM; LANGSAM; AUGENSTEIN, 1995, cap. 7). O exemplo A209
mostra essa tabela. O método falha em dois casos. Se a chave é grande, o vetor
fica impossível: um CPF tem 11 dígitos e pediria cem bilhões de posições para
guardar algumas centenas de clientes. E se a chave nem é número, como um nome,
não há índice para usar.

Pense no guarda-volumes de uma academia. A recepcionista não procura armário
vago de porta em porta: aplica uma regra ao seu nome, e a regra devolve o
número do armário. Na saída, a mesma regra diz onde estão as suas coisas. Essa
regra é a **função hash**, que recebe a chave e devolve um índice entre `0` e
`m - 1`, sendo `m` o tamanho do vetor. O vetor que guarda os itens é a
**tabela hash**, e cada posição dele é um **balde** (CORMEN et al., 2024, cap. 11).

Nem toda regra serve. A função precisa ser **determinística**: a mesma chave
sempre dá o mesmo índice, senão você guarda num balde e procura em outro. Ela
precisa ser **rápida**, porque roda a cada busca e a cada inserção. E precisa
**espalhar**: chaves diferentes devem cair em baldes diferentes o máximo
possível. Para espalhar bem, o cálculo deve usar todas as partes da chave. Uma
função que olha só a primeira letra põe "Ana" e "Alice" sempre juntas
(TENENBAUM; LANGSAM; AUGENSTEIN, 1995, cap. 7).

Para chave inteira, a regra mais usada é o **método da divisão**: `h(k) = k mod m`,
que em C se escreve `k % m`. O resto da divisão por `m` sempre fica entre `0` e
`m - 1`, que é exatamente a faixa dos baldes. A escolha de `m` pesa. Prefira um
primo longe de uma potência de 2. Com `m = 2^p`, o resto guarda só os `p` bits
de baixo da chave e ignora o resto dela: com `m = 16`, as chaves 5, 21 e 37
caem todas no balde 5 (CORMEN et al., 2024, cap. 11). O **método da
multiplicação** fica para o assunto 0178.

Para texto, o caminho mais simples é somar os códigos das letras e tirar o
resto por `m`. A letra é um `char`, e no gcc de PC o `char` tem sinal: os bytes
do "ã" em UTF-8 viram números negativos, e um resto negativo (`-98 % 8` dá `-2`)
seria um índice fora do vetor. Por isso a função lê cada letra como
`unsigned char` e acumula a soma num `unsigned`. Quando um `unsigned` estoura,
ele volta a contar do zero (aritmética módulo 2³²), e isso é definido pela
norma; o estouro de `int` não é (KERNIGHAN; RITCHIE, 1988, seção 6.6).

Agora o ponto que define todo o resto do módulo. Existem muito mais chaves
possíveis do que baldes, então duas chaves diferentes **vão** cair no mesmo
balde. Isso é uma **colisão**, e nenhuma função a evita para sempre (KNUTH,
1998, seção 6.4). O que se faz é tratá-la, e os assuntos 0106 e 0107 mostram
as duas maneiras clássicas.

O aperto da tabela tem nome: **fator de carga**, `α = n / m`, o número de itens
dividido pelo número de baldes, ou quantos itens cabem em média em cada balde.
Cinco itens em 7 baldes dão α ≈ 0,71. Quanto mais perto de 1, mais colisões
aparecem e mais devagar a tabela fica (CORMEN et al., 2024, cap. 11).

> [!WARNING]
> A soma **não vê a ordem das letras**: "amor", "roma", "mora" e "ramo" somam
> 431 e caem no mesmo balde. Use o **polinômio** `h = h * 31 + letra`, que
> multiplica cada letra pela sua posição (exemplo A210).

{{exemplo}}

O guarda-volumes da academia tem 7 armários, e a regra é "soma dos códigos das
letras, resto por 7". "caio" soma 412 e cai no 6; "bia" soma 300, também dá 6
e chegou antes. Os outros três caem em armários livres:

{{ideia}}

No código, o vetor `dono` é a tabela e `NULL` é armário vazio. O programa só
**detecta** a colisão:

```c
#include <stdio.h>

#define ARMARIOS 7

// função hash: soma os códigos das letras e reduz para 0..6
int armario(const char *nome) {
    unsigned soma = 0;
    for (int i = 0; nome[i] != '\0'; i++) {
        soma += (unsigned char)nome[i]; // o byte da letra, sempre >= 0
    }
    return (int)(soma % ARMARIOS);
}

int main(void) {
    const char *dono[ARMARIOS] = {NULL}; // NULL = armário vazio
    const char *alunos[] = {"ana", "davi", "lia", "bia", "caio"};

    for (int i = 0; i < 5; i++) {
        int a = armario(alunos[i]);
        if (dono[a] == NULL) {
            dono[a] = alunos[i];
            printf("%-4s -> armário %d\n", alunos[i], a);
        } else {
            printf("%-4s -> armário %d (colisão com %s!)\n", alunos[i], a, dono[a]);
        }
    }
    return 0;
}
// Saída:
// ana  -> armário 3
// davi -> armário 0
// lia  -> armário 2
// bia  -> armário 6
// caio -> armário 6 (colisão com bia!)
```

O fluxograma mostra o caminho do "caio": quatro voltas no laço, índice 6,
armário ocupado, colisão:

{{fluxograma}}
