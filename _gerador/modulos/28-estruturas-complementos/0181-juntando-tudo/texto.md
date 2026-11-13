## 0181 · Juntando tudo

Um sistema de verdade raramente cabe numa estrutura só. A recepção de um
posto de saúde responde a três perguntas o dia inteiro: "esse CPF já tem
cadastro?", "qual a próxima consulta depois das 8h45?" e "a paciente
desmarcou; quem estava esperando?". Cada pergunta tem uma estrutura do módulo
que a responde bem, e o trabalho deste assunto é fazer as três funcionarem
juntas sem que uma desarrume a outra.

A primeira pergunta é uma busca exata: dado um CPF, ache o paciente. Não
interessa a ordem dos CPFs, só achar rápido. Isso pede uma **tabela hash**,
aqui com a **dispersão dupla** do 0179, que dá busca em O(1) em média. O
tamanho escolhido é `m = 101`, um primo, como a dispersão dupla pede, e a
tabela fica com menos da metade ocupada, o que mantém as sondagens poucas
(CORMEN et al., 2024, cap. 11).

A segunda pergunta é de ordem: "a próxima depois de tal hora". Uma hash não
responde isso, porque ela espalha as chaves de propósito. Os horários vão
então para uma **rubro-negra clássica** com sentinela, a do 0177, com a hora
escrita como número no formato HHMM (8h45 vira 845). Marcar um horário custa
O(log n). Para achar a próxima consulta, você usa o **teto** da hora pedida,
o menor horário maior ou igual a ela. Se esse horário estiver vago, você
segue pelo **sucessor** do 0175 até achar um ocupado (CORMEN et al., 2024,
cap. 13).

A terceira pergunta é de chegada: quem pediu primeiro tem a vez. A **fila de
espera** é a lista dupla circular com sentinela do 0174. O paciente entra no
fim; sai do começo quando um horário vaga, ou do meio se desistir. Graças à
sentinela, nenhuma dessas saídas tem caso especial (CORMEN et al., 2024, cap.
10).

O ponto delicado é a ligação entre as três. Elas conversam por **chaves**, não
por ponteiros: o nó da árvore guarda o CPF de quem marcou, o paciente na hash
guarda o horário dele, e a fila guarda CPFs. Isso importa porque as
estruturas mexem nos próprios nós. Uma rotação na rubro-negra muda quem é
filho de quem, e uma sondagem pode pôr o paciente numa posição diferente da
inicial. Se uma estrutura guardasse um ponteiro para dentro da outra, essas
mudanças poderiam deixá-lo apontando para o lugar errado. Com chaves, cada
estrutura faz o que quiser por dentro, e a outra continua achando o dado pela
chave.

Falta decidir o que acontece com um horário desmarcado sem ninguém na espera.
A rubro-negra do 0177 não implementou a remoção, então o nó continua na
árvore com `cpf = 0`, marcando o **horário vago**. É a mesma ideia da lápide
da hash: a posição existe, mas não guarda ninguém.

Por fim, o cliente não precisa saber de nada disso. O `agenda.h` só declara
`typedef struct Agenda Agenda`, sem mostrar os campos. Isso é um **tipo
opaco**: o programa da recepção usa a agenda só pelas funções do `.h`, e você
pode trocar a rubro-negra por uma AVL sem mudar uma linha dele (CELES;
CERQUEIRA; RANGEL, 2016).

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
