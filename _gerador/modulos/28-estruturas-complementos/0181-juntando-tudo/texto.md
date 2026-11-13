## 0181 · Juntando tudo

- **Pacientes numa hash com dispersão dupla** (0179), pelo CPF: busca exata
  em O(1) em média, com `m = 101` primo e carga abaixo de 1/2
  (CORMEN et al., 2024, cap. 11).
- **Horários numa rubro-negra** com sentinela (0177), pela hora em HHMM:
  marcar custa O(log n); "a próxima depois de tal hora" é o teto seguido do
  **sucessor** (0175) (CORMEN et al., 2024, cap. 13).
- **Fila de espera numa lista dupla circular com sentinela** (0174): entra no
  fim e sai do começo ou do meio, sem caso especial (CORMEN et al., 2024, cap. 10).
- **Ligação por chaves**: o nó da árvore guarda o CPF, o paciente guarda o
  horário, a fila guarda CPFs. Rotação ou sondagem não invalidam as outras
  estruturas.
- **Horário vago**: a rubro-negra do 0177 não tem remoção; a consulta
  desmarcada deixa `cpf = 0` no nó, como a lápide da hash.
- **Tipo opaco**: o `.h` só declara `typedef struct Agenda Agenda`; dá para
  trocar a rubro-negra por uma AVL sem mudar o cliente (CELES; CERQUEIRA;
  RANGEL, 2016).

> [!WARNING]
> Quando duas estruturas guardam a mesma informação, elas mudam **juntas**.
> Se o cancelamento zerar só a árvore (`x->cpf`) e esquecer a hash
> (`p->horario`), a paciente nunca mais consegue marcar.

{{exemplo}}

A recepção de um posto de saúde cadastra cinco pacientes. Carla marca às
8h00, Ana às 9h00, Bruno às 10h30; Diego e Elisa esperam pelas 9h00. Ana
desmarca e Diego assume. As estruturas depois disso:

{{ideia}}

O `agenda.c` reúne as três implementações (com `static`). A operação que as
junta é o cancelamento:

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

O programa da recepção:

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

O fluxograma segue o cancelamento das 9h00: a Ana fica sem horário e, como a
fila não está vazia, o Diego assume e sai dela:

{{fluxograma}}
