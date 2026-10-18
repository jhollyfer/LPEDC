## 0105 · A ideia e a função hash

Na academia, o guarda-volumes tem 7 armários. A recepcionista não procura um
armário vago de porta em porta, nem anota numa lista quem ficou onde. Ela
aplica uma **regra** ao seu nome e a regra devolve o número do armário. Na
saída, a mesma regra diz onde estão as suas coisas, sem procurar nada.

Você já viu buscas de todo tipo: sequencial em O(n), binária em O(log n), na
árvore de busca em O(log n) se ela estiver equilibrada. Existe uma busca ainda
melhor, que você usa desde o começo do curso: `v[i]`. Acessar um vetor pelo
índice custa **O(1)**, não importa o tamanho.

Quando a chave já é um número pequeno, dá para usá-la direto como índice. Os
DDDs vão de 11 a 99, então `const char *estado[100]` resolve: `estado[61]` é
"DF", em um passo. Isso é **endereçamento direto**. O problema aparece quando
a chave é grande ou não é número: um CPF tem 11 dígitos (um vetor de 100
bilhões de posições para guardar 50 alunos?) e um nome nem é número.

A saída é uma **função hash** (função de espalhamento): ela pega a chave, seja
qual for, e devolve um índice entre `0` e `m - 1`, onde `m` é o tamanho da
tabela. O vetor que guarda os itens nessas posições é a **tabela hash**, e cada
posição é um **balde**.

Uma boa função hash tem três qualidades:

- **determinística**: a mesma chave dá sempre o mesmo índice, senão você não
  acha mais o que guardou;
- **rápida**: custa pouco calcular, senão perde a graça do O(1);
- **espalha bem**: chaves diferentes caem em baldes diferentes, sem amontoar.

Para inteiros, a função clássica é o resto: `k % m`. Para texto, o jeito mais
simples é somar os códigos das letras e tirar o resto. Só que existem mais
chaves possíveis do que baldes, então duas chaves diferentes **vão** cair no
mesmo balde um dia. Isso é uma **colisão**. Não dá para evitar, só deixar
rara e saber tratar (os próximos dois assuntos).

A conta que mede o aperto da tabela é o **fator de carga**: `α = n / m`, o
número de itens dividido pelo número de baldes. Com 5 alunos em 7 armários,
α ≈ 0,71. Quanto mais perto de 1 (ou acima), mais colisão.

Vamos ver na prática. Os 5 alunos chegam na ordem ana, davi, lia, bia e caio.
A regra é "soma dos códigos das letras, resto por 7". Para "caio": 99 + 97 +
105 + 111 = 412, e 412 % 7 = 6. Só que "bia" (98 + 105 + 97 = 300) também deu
6, e chegou antes. Os outros três caem em armários livres:

{{ideia}}

O mesmo guarda-volumes em C. O vetor `dono` é a tabela: `NULL` quer dizer
armário vazio. O programa só **detecta** a colisão; resolver fica para o
próximo assunto:

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

Repara no fluxograma: a função hash é só um laço que acumula a soma, letra por
letra, e um resto no final. O caminho mostrado é o do "caio": quatro voltas no
laço, índice 6, armário ocupado, colisão:

{{fluxograma}}

> [!WARNING]
> Somar os códigos é fácil, mas a soma **não vê a ordem das letras**. "amor",
> "roma", "mora" e "ramo" têm as mesmas letras, então dão a mesma soma (431) e
> caem todos no mesmo balde. Anagramas são comuns em nomes e códigos ("AB12" e
> "BA21"). Use o **polinômio**: `h = h * 31 + letra`. Cada letra é
> multiplicada pela sua posição, e a ordem passa a contar (exemplo A210).

> [!TIP]
> **Por dentro do C:** o C não tem "letra"; tem bytes. Em UTF-8, o "ã" ocupa
> dois bytes, `0xC3 0xA3`, e no gcc para PC o tipo `char` tem **sinal**: esses
> bytes valem -61 e -93. Somados num `int`, podem deixar a soma negativa, e o
> resto de um negativo em C é negativo: `-98 % 8` dá `-2`, índice fora do vetor. Por isso a função converte
> para `unsigned char` (0 a 255) e acumula num `unsigned`. E tem mais um
> motivo: estourar um `unsigned` é definido (a conta dá a volta, módulo 2³²),
> enquanto estourar um `int` é comportamento indefinido. O polinômio estoura o
> tempo todo, de propósito.

> [!NOTE]
> **Pergunta para você:** se a tabela tivesse 10 armários em vez de 7, quais
> alunos colidiriam? Faça as contas com as somas (ana 304, davi 420, lia 310,
> bia 300, caio 412) antes de trocar `7` por `10` no exemplo A209 e rodar.

{{pratique}}
