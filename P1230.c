// Lista · Módulo 12 · Pilhas e filas
// Exercício P1230 · ★★★ · O expediente da lotérica com arquivo de log
//
// Junte filas com arquivos (módulo 09). Às 8h, seis clientes já estão na
// fila da lotérica, cada um com senha, tipo (A aposta, B boleto, S saque)
// e minutos de atendimento:
//
//   1 B 3   2 A 1   3 B 4   4 A 2   5 S 5   6 A 1
//
// 1. Ponha as senhas numa fila circular de structs (capacidade 8).
// 2. Atenda em ordem com um caixa só, começando no minuto 0, e grave cada
//    atendimento como uma linha "senha tipo inicio fim" em
//    /tmp/p1230_log.txt.
// 3. Feche o log, reabra para leitura e, só com o que está no arquivo
//    (fscanf), monte o relatório: quantos atendimentos e quantos minutos de
//    cada tipo, a espera média (o "inicio" de cada um) e o minuto em que o
//    expediente terminou. Apague o log no fim.
//
//   Saída esperada:
//   Log gravado: 6 linhas
//   Apostas: 3 (4 min)
//   Boletos: 2 (7 min)
//   Saques: 1 (5 min)
//   Espera média: 6.67 min
//   Fim do atendimento: minuto 16
//
// Dicas:
// 1. Os atendimentos vão de 0 a 3, 3 a 4, 4 a 8, 8 a 10, 10 a 15 e 15 a 16.
//    O fim de um é o início do próximo.
// 2. Leia o log com while (fscanf(arq, "%d %c %d %d", ...) == 4). O espaço
//    antes do %c pula o separador.
// 3. O relatório não usa a fila: a fila só existe durante o expediente; o
//    log é o que sobra depois. Espera média = (0 + 3 + 4 + 8 + 10 + 15) / 6.
// 4. Resposta esperada: a saída acima.
//
// Escreva sua resposta abaixo:

#include <stdbool.h>
#include <stdio.h>

#define CAP 8

typedef struct {
    int senha;
    char tipo; // 'A' aposta, 'B' boleto, 'S' saque
    int minutos;
} Atendimento;

int main(void) {

    return 0;
}
