## 0181 · Juntando tudo

A recepção do posto de saúde do bairro tem três perguntas o dia inteiro.
"Esse CPF já tem cadastro?" "Qual é a próxima consulta depois das 8h45?" "A
dona Ana desmarcou: quem estava esperando?" Cada pergunta pede uma estrutura
diferente, e este programa usa as três que o módulo construiu:

- os **pacientes** ficam numa **tabela hash com dispersão dupla** (0179),
  pelo CPF: cadastro e busca exata em O(1) em média. O `m` é 101, primo, e a
  carga fica abaixo de 1/2;
- os **horários** ficam numa **rubro-negra clássica** com sentinela (0177),
  pela hora em HHMM: marcar custa O(log n) mesmo que a recepção marque tudo
  em ordem, e "a próxima depois de tal hora" é o **teto** seguido do
  **sucessor** (0175), O(log n);
- a **fila de espera** é uma **lista dupla circular com sentinela** (0174):
  entra no fim, sai do começo ou do meio (quando o paciente consegue horário
  por outro caminho), sem caso especial.

As estruturas conversam por **chaves**, não por ponteiros: o nó da árvore
guarda o CPF de quem marcou, o paciente na hash guarda o horário dele, a fila
guarda CPFs. Assim, cada uma pode mudar por dentro (uma rotação, uma
sondagem) sem invalidar nada nas outras.

Uma decisão de projeto: a rubro-negra do 0177 não tem remoção. Em vez de remover, a consulta desmarcada deixa o **horário vago**
na árvore (`cpf = 0`): o nó continua lá e pode ser reaproveitado na próxima
marcação. É a mesma ideia da lápide da hash, numa árvore. A agenda de um dia
tem poucas dezenas de horários; o custo de guardar os vagos é pequeno.

Cinco pacientes se cadastram. Carla marca às 8h00, Ana
às 9h00, Bruno às 10h30. Diego quer as 9h00, já ocupadas, e vai para a espera;
Elisa também. Ana desmarca: o primeiro da fila, Diego, assume. No desenho, as
três estruturas depois disso:

{{ideia}}

O TAD é o `agenda.h`, e o `agenda.c` reúne as três implementações (com
`static`, para os nomes não vazarem). A operação que junta as três é o
cancelamento:

```c
int ag_cancela(Agenda *a, int horario) {
    NoAg *x = busca_no(a, horario);  // rubro-negra: O(log n)
    if (x == &a->nil || x->cpf == 0) {
        return -1;
    }
    paciente(a, x->cpf)->horario = -1; // hash: O(1) em média
    x->cpf = 0;
    a->consultas--;
    if (a->na_fila == 0) {
        return 0; // ninguém esperando: o horário fica vago na árvore
    }
    int cpf = a->fila.prox->cpf; // fila: o primeiro, sem if de lista vazia
    ag_marca(a, horario, cpf);   // ag_marca já tira ele da fila
    return cpf;
}
```

E a recepção:

```c
#include <stdio.h>
#include "agenda.h"

int main(void) {
    Agenda *a = ag_cria();
    if (a == NULL) {
        return 1;
    }
    ag_cadastra(a, 123456789, "Ana");
    ag_cadastra(a, 987654321, "Bruno");
    ag_cadastra(a, 111222333, "Carla");
    ag_cadastra(a, 444555666, "Diego");
    ag_cadastra(a, 777888999, "Elisa");

    ag_marca(a, 900, 123456789);
    ag_marca(a, 1030, 987654321);
    ag_marca(a, 800, 111222333);
    if (!ag_marca(a, 900, 444555666)) {
        printf("09:00 já está ocupado: Diego vai para a espera\n");
        ag_espera(a, 444555666);
    }
    ag_espera(a, 777888999);
    ag_mostra(a);
    ag_mostra_espera(a);

    int quem = ag_cancela(a, 900); // a Ana desmarcou
    printf("Ana desmarcou as 09:00; quem assumiu: %s\n", ag_nome(a, quem));
    int h = ag_proximo(a, 845);
    printf("Próxima consulta depois das 08:45: %02d:%02d\n", h / 100, h % 100);
    ag_mostra(a);
    ag_mostra_espera(a);
    ag_estatisticas(a);
    ag_libera(a);
    return 0;
}
// Saída:
// 09:00 já está ocupado: Diego vai para a espera
// 08:00  Carla
// 09:00  Ana
// 10:30  Bruno
// Espera: Diego Elisa
// Ana desmarcou as 09:00; quem assumiu: Diego
// Próxima consulta depois das 08:45: 09:00
// 08:00  Carla
// 09:00  Diego
// 10:30  Bruno
// Espera: Elisa
// Horários na árvore: 3 (3 com consulta) | altura 1 | altura negra 1
// Pacientes: 5 em 101 posições | média de sondagens: 1.00
// Na fila de espera: 1
```

O fluxograma segue o cancelamento das 9h00. O horário existe e tem
consulta, a Ana fica sem horário, e como a fila não está vazia, o Diego (o
primeiro) assume e sai da fila:

{{fluxograma}}

> [!WARNING]
> Quando duas estruturas guardam a mesma informação, elas têm que mudar
> **juntas**. Aqui, o horário do paciente está na hash (`p->horario`) e na
> árvore (`x->cpf`). Se o cancelamento zerar só a árvore, a Ana continua
> "com consulta" na hash e nunca mais consegue marcar. Toda operação da
> agenda que mexe numa das duas mexe na outra antes de voltar. Um
> `ag_confere` que percorre a árvore e compara com a hash é um bom teste
> para esse tipo de programa.


> [!TIP]
> **Por dentro do C:** a `struct Agenda` guarda a tabela de 101 pacientes
> **dentro dela** (101 × 40 bytes, cerca de 4 KB), mais as duas sentinelas:
> um `calloc` só cria tudo, e o zero do `calloc` já deixa toda posição da
> hash como `LIVRE`. Os nós da árvore e da fila vêm de `malloc`, um por
> horário e um por pessoa na fila, e `ag_libera` devolve cada um. Como o
> `Agenda` é um **tipo opaco** (o `.h` só declara `typedef struct Agenda
> Agenda`), quem usa a agenda não enxerga nenhuma das três estruturas: dá
> para trocar a rubro-negra por uma AVL sem mudar uma linha do cliente.

> [!NOTE]
> **Pergunta para você:** depois do exemplo, a Elisa ainda está na espera. Se
> o Bruno desmarcar as 10h30 e, em seguida, a Carla desmarcar as 8h00, quem
> fica com cada horário? E o que `ag_proximo(a, 700)` devolve no fim?

{{pratique}}
