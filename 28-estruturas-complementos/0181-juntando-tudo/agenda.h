// agenda.h · agenda de consultas: pacientes numa hash com dispersão dupla,
// horários numa rubro-negra (Cormen) e fila de espera numa lista com sentinela
#ifndef AGENDA_H
#define AGENDA_H

#include <stdbool.h>

typedef struct Agenda Agenda;

Agenda *ag_cria(void); // NULL se faltar memória

// cadastra o paciente (cpf: os 9 primeiros dígitos); false se já existe ou se a tabela encheu
bool ag_cadastra(Agenda *a, int cpf, const char *nome);
const char *ag_nome(const Agenda *a, int cpf); // NULL se não cadastrado

// marca a consulta (horário em HHMM); false se o horário está ocupado, o
// paciente não existe ou já tem consulta
bool ag_marca(Agenda *a, int horario, int cpf);

// põe o paciente no fim da fila de espera; false se não existe, já tem
// consulta ou já está na fila
bool ag_espera(Agenda *a, int cpf);

// desmarca a consulta do horário. O primeiro da fila de espera assume o
// horário. Devolve o cpf de quem assumiu, 0 se o horário ficou vago, -1 se
// não havia consulta ali
int ag_cancela(Agenda *a, int horario);

int ag_horario_de(const Agenda *a, int cpf); // -1 se não tem consulta
int ag_proximo(const Agenda *a, int horario); // menor horário >= horario com consulta; -1 se não há

// copia para horarios[] (até max) os horários com consulta entre de e ate,
// em ordem; devolve quantos copiou
int ag_intervalo(const Agenda *a, int de, int ate, int *horarios, int max);

void ag_mostra(const Agenda *a);        // as consultas em ordem de horário
void ag_mostra_espera(const Agenda *a); // a fila de espera, do primeiro ao último
void ag_estatisticas(const Agenda *a);  // altura da árvore, sondagens, fila

void ag_libera(Agenda *a);

#endif
