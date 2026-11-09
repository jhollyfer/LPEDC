// 0186 · P e NP
// Exercício E1116 · ★★★
//
// Ache o bug. Este verificador do churrasco do texto aprova qualquer
// palpite. Só o palpite 2 satisfaz todas as cláusulas, mas a saída diz que
// os três satisfazem:
//
//   Saída que aparece:
//   Palpite 1: Ana Davi -> satisfaz
//   Palpite 2: Beto Davi -> satisfaz
//   Palpite 3: Ana Beto Caio -> satisfaz
//
//   Saída esperada:
//   Palpite 1: Ana Davi -> não satisfaz
//   Palpite 2: Beto Davi -> satisfaz
//   Palpite 3: Ana Beto Caio -> não satisfaz
//
// O programa compila e roda sem erro; o problema é de lógica. Conserte o
// verificador.
//
// Dicas:
// 1. Uma fórmula em FNC é um E de cláusulas. Quantas cláusulas verdadeiras
//    bastam para este verificador dizer "satisfaz"?
// 2. Dentro da cláusula vale o OU (basta um literal); entre as cláusulas
//    vale o E (todas). O laço pode sair cedo só no "não".
// 3. Resposta esperada: a saída esperada acima.
//
// Escreva sua resposta abaixo (conserte o código):

#include <stdbool.h>
#include <stdio.h>

#define NV 4
#define NC 5

const char *nomes[NV + 1] = {"", "Ana", "Beto", "Caio", "Davi"};
const int formula[NC][3] = {{1, 2, 0}, {-1, -3, 0}, {3, 4, 0}, {-2, 4, 0}, {-4, -1, 3}};

bool satisfaz(const bool vai[]) {
    for (int c = 0; c < NC; c++) {
        bool algum = false;
        for (int i = 0; i < 3 && formula[c][i] != 0; i++) {
            int lit = formula[c][i];
            if (lit > 0 ? vai[lit] : !vai[-lit]) algum = true;
        }
        if (algum) return true; // esta cláusula está ok
    }
    return false;
}

int main(void) {
    bool palpites[3][NV + 1] = {
        {false, true, false, false, true}, // Ana e Davi
        {false, false, true, false, true}, // Beto e Davi
        {false, true, true, true, false},  // Ana, Beto e Caio
    };
    for (int p = 0; p < 3; p++) {
        printf("Palpite %d:", p + 1);
        for (int v = 1; v <= NV; v++)
            if (palpites[p][v]) printf(" %s", nomes[v]);
        printf(" -> %s\n", satisfaz(palpites[p]) ? "satisfaz" : "não satisfaz");
    }
    return 0;
}
