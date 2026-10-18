// 0066 · Juntando tudo: o cardápio
// Exercício E396 · ★★★
//
// Um valor JSON pode ser número, texto, booleano ou null.
// Represente isso em C com uma union etiquetada:
//
//   typedef enum { J_NULO, J_NUMERO, J_TEXTO, J_BOOL } TipoJson;
//   typedef struct {
//       TipoJson tipo;
//       union { double numero; char texto[32]; bool booleano; } v;
//   } ValorJson;
//
// e um campo de objeto: typedef struct { char chave[16]; ValorJson valor; }
// Campo. Escreva void imprimir_valor(const ValorJson *v) e
// void imprimir_objeto(const Campo campos[], int n) e monte o perfil abaixo.
//
//   Saída esperada:
//   {"nome": "Ana", "idade": 31, "altura": 1.68, "ativa": true, "apelido": null}
//
// Dicas:
// 1. Número: %g mostra 31 e 1.68 sem zeros sobrando.
// 2. Texto vai entre aspas: printf("\"%s\"", v->v.texto).
// 3. Vírgula entre campos, mas não depois do último: imprima ", " antes de
//    cada campo menos o primeiro.
// 4. Inicialize com nome de campo:
//    {"idade", {J_NUMERO, .v.numero = 31}}.
// 5. Resposta esperada: a linha acima.
//
// Escreva sua resposta abaixo:

#include <stdbool.h>
#include <stdio.h>

int main(void) {

    return 0;
}
