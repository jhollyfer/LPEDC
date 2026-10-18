// 0023 · Break e continue
// Exercício E136 · ★★☆
//
// Um sensor manda até 5 códigos: 1 = normal, 2 = alerta, 9 = desligou. Quando
// chega o 9, o programa deveria parar de ler. Mas rodando com
//
//   printf '1\n2\n9\n1\n2\n' | ~/LPEDC/rodar 03-repeticoes/0023-break-continue/E136.c
//
// ele continua lendo depois do 9. O código com o erro está logo abaixo.
// Explique por que o break não para o laço e conserte.
//
// Dicas:
// 1. Dentro de um switch, de quem o break está saindo?
// 2. Depois do switch, ainda dentro do for, você pode testar o código de novo.
// 3. Resposta esperada: o break do "case 9" sai só do switch (o mais interno),
//    não do for. Conserto: depois do switch, "if (codigo == 9) break;" (ou
//    trocar o switch por if/else if). Corrigido, mostra normal, alerta,
//    "sensor desligou" e "Leituras: 3".
//
// Escreva sua resposta abaixo (conserte o código):

#include <stdio.h>

int main(void) {
    int codigo;
    int leituras = 0;

    for (int i = 1; i <= 5; i++) {
        if (scanf("%d", &codigo) != 1) {
            break;
        }
        leituras++;
        switch (codigo) {
        case 1:
            printf("normal\n");
            break;
        case 2:
            printf("alerta\n");
            break;
        case 9:
            printf("sensor desligou\n");
            break; // a ideia era parar de ler aqui
        default:
            printf("código desconhecido\n");
        }
    }
    printf("Leituras: %d\n", leituras);
    return 0;
}
