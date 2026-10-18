// 0028 · Break e continue
// Exercício E168 · ★★★
//
// Tem gente que acha que break e continue deixam o laço difícil de ler,
// porque a saída fica escondida no meio do corpo. Refatore o programa abaixo
// para NÃO usar break nem continue: use uma variável bool (assunto 0017) na
// condição do while e if/else no corpo. A saída tem que ser a mesma.
//
//   double soma = 0.0, nota;
//   int contadas = 0;
//   while (1) {
//       printf("Nota (-1 encerra): ");
//       if (scanf("%lf", &nota) != 1) break;
//       if (nota < 0) break;
//       if (nota > 10) {
//           printf("  nota %.1f ignorada\n", nota);
//           continue;
//       }
//       soma += nota;
//       contadas++;
//   }
//   if (contadas > 0) {
//       printf("Média de %d notas: %.2f\n", contadas, soma / contadas);
//   }
//
// Teste com 8, 12, 6.5, 9 e -1.
//
// Dicas:
// 1. bool continuar = true; while (continuar) { ... }
// 2. Onde havia break, faça continuar = false. Onde havia continue, use um
//    else para que a soma não aconteça.
// 3. Resposta esperada: "  nota 12.0 ignorada" e "Média de 3 notas: 7.83".
//
// Escreva sua resposta abaixo:

#include <stdbool.h>
#include <stdio.h>

int main(void) {

    return 0;
}
