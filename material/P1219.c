// Lista · Módulo 12 · Pilhas e filas
// Exercício P1219 · ★★☆ · O Ctrl+Z do bloco de notas
//
// Todo editor guarda as operações numa PILHA: desfazer é desempilhar a
// última e fazer o contrário dela. Escreva um mini editor com um texto
// (char[100]) e uma pilha de operações sobre vetor (até 20), em que cada
// operação guarda o tipo ('D' digitou, 'A' apagou) e o pedaço de texto
// envolvido:
//
//   void digita(Editor *e, const char *s)  // põe s no fim e empilha {'D', s}
//   void apaga(Editor *e, int k)           // tira os k últimos e empilha
//                                          // {'A', o que foi apagado}
//   bool desfaz(Editor *e)                 // false se não há o que desfazer
//
// Faça: digita "Bom", digita " dia", apaga 3, digita "tarde" e depois
// desfaz cinco vezes, mostrando o texto entre colchetes a cada passo.
//
//   Saída esperada:
//   digita: [Bom]
//   digita: [Bom dia]
//   apaga:  [Bom ]
//   digita: [Bom tarde]
//   desfaz: [Bom ]
//   desfaz: [Bom dia]
//   desfaz: [Bom]
//   desfaz: []
//   desfaz: nada para desfazer
//
// Dicas:
// 1. Desfazer um 'D' é apagar strlen(texto da operação) letras do fim.
//    Desfazer um 'A' é colar o texto guardado de volta no fim (strcat).
// 2. Para guardar o que apagou: copie &e->texto[n - k] para a operação
//    ANTES de pôr o '\0' em e->texto[n - k].
// 3. Resposta esperada: a saída acima.
//
// Escreva sua resposta abaixo:

#include <stdbool.h>
#include <stdio.h>
#include <string.h>

typedef struct {
    char tipo;      // 'D' digitou, 'A' apagou
    char texto[32];
} Operacao;

typedef struct {
    char texto[100];
    Operacao pilha[20];
    int n; // operações na pilha
} Editor;

int main(void) {

    return 0;
}
