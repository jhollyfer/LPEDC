// Lista · Módulo 08 · Tipos compostos
// Exercício P0829 · ★★★ · A multa da biblioteca
//
// A biblioteca municipal empresta livros por 14 dias e cobra R$ 1,50 por dia
// de atraso. Crie typedef struct { int dia, mes, ano; } Data; e
// typedef struct { char titulo[32]; char leitor[16]; Data saida, devolucao; }
// Emprestimo;. Escreva long dias_desde_inicio(Data d), que conta os dias de
// 01/01/0001 até d (somando 365 ou 366 por ano completo e os dias dos meses
// completos do ano de d), e use a diferença entre duas datas para achar o
// atraso. Mostre, para cada empréstimo, os dias com o livro, o atraso e a
// multa, e o total arrecadado:
//
//   Saída esperada:
//   Dois Irmãos (Clarice): 9 dias, atraso 0, multa R$ 0.00
//   Vidas Secas (Otávio): 21 dias, atraso 7, multa R$ 10.50
//   Macunaíma (Fabiana): 32 dias, atraso 18, multa R$ 27.00
//   O Cortiço (Ramon): 21 dias, atraso 7, multa R$ 10.50
//   Total: R$ 48.00
//
// Dicas:
// 1. Reaproveite o bissexto e o dias_no_mes do P0805.
// 2. dias = soma, de 1 até ano - 1, de (bissexto(a) ? 366 : 365) + soma
//    dos meses de 1 até mes - 1 + dia. Para datas próximas, só a DIFERENÇA
//    importa: o número em si é grande, use long.
// 3. Atraso = dias com o livro - 14, se for positivo; senão, 0.
// 4. Atenção às viradas: 20/12/2025 a 10/01/2026 são 21 dias, e 2028 é
//    bissexto (29/02 existe).
// 5. Resposta esperada: a saída acima (total R$ 48.00).
//
// Escreva sua resposta abaixo:

#include <stdio.h>
#include <stdbool.h>

typedef struct {
    int dia, mes, ano;
} Data;

typedef struct {
    char titulo[32];
    char leitor[16];
    Data saida, devolucao;
} Emprestimo;

int main(void) {
    Emprestimo v[4] = {
        {"Dois Irmãos", "Clarice", {3, 11, 2026}, {12, 11, 2026}},
        {"Vidas Secas", "Otávio", {20, 12, 2025}, {10, 1, 2026}},
        {"Macunaíma", "Fabiana", {1, 3, 2026}, {2, 4, 2026}},
        {"O Cortiço", "Ramon", {20, 2, 2028}, {12, 3, 2028}},
    };
    (void) v; // apague esta linha quando escrever

    return 0;
}
