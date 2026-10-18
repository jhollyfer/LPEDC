// 0023 · switch, case, break e fall-through
// Exercício E135 · ★★☆
//
// Preveja a saída deste switch para n = 2, 5, 7 e 9. Repare que o default
// está no meio e que nem todo case tem break.
//
//   switch (n) {
//   case 2:
//       printf("dois ");
//   case 5:
//       printf("cinco ");
//       break;
//   default:
//       printf("outro ");
//   case 7:
//       printf("sete ");
//   }
//   printf("fim\n");
//
// Dicas:
// 1. O switch pula para o rótulo certo (ou para o default, esteja ele onde
//    estiver) e desce até um break ou até o fim.
// 2. O default não precisa ser o último. Depois dele, o case 7 está logo
//    embaixo.
// 3. Resposta esperada: 2 → "dois cinco fim"; 5 → "cinco fim";
//    7 → "sete fim"; 9 → "outro sete fim".
//
// Escreva sua resposta abaixo:

#include <stdio.h>

int main(void) {

    return 0;
}
