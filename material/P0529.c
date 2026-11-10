// Lista · Módulo 05 · Vetores, matrizes e strings
// Exercício P0529 · ★★★ · Conserte o gerador de etiquetas
//
// O programa abaixo gera a etiqueta de envio "PARA: <nome> - <cidade>/<UF>"
// e confere se o envio é expresso. Ele tem TRÊS erros de propósito:
// - um o gcc avisa (leia o warning);
// - um o AddressSanitizer acusa quando roda;
// - um é de lógica: o programa roda, mas a etiqueta sai errada.
//
// Conserte os três. Ele deve mostrar:
//
//   Saída esperada:
//   PARA: Benedita Farias - Boa Vista/RR
//   Tamanho: 36
//   Envio expresso: entrega em 2 dias
//
// Dicas:
// 1. Comparar strings com == compara os ENDEREÇOS dos dois vetores, não o
//    texto: use strcmp(...) == 0.
// 2. Conte os bytes da etiqueta: "PARA: " (6) + nome + " - " (3) + cidade +
//    "/" + UF + '\0'. Cabe em 24?
// 3. strcpy no lugar do primeiro strcat apaga o que já estava lá; strcat no
//    lugar do strcpy inicial lê lixo. Olhe qual dos dois está em cada linha.
// 4. Resposta esperada: a saída acima (etiqueta com 36 caracteres).
//
// Escreva sua resposta abaixo:

#include <stdio.h>
#include <string.h>

int main(void) {
    char nome[] = "Benedita Farias";
    char cidade[] = "Boa Vista";
    char uf[] = "RR";
    char tipo[] = "expresso";
    char etiqueta[24];

    strcpy(etiqueta, "PARA: ");
    strcat(etiqueta, nome);
    strcat(etiqueta, " - ");
    strcpy(etiqueta, cidade);
    strcat(etiqueta, "/");
    strcat(etiqueta, uf);

    printf("%s\n", etiqueta);
    printf("Tamanho: %zu\n", strlen(etiqueta));
    if (tipo == "expresso") {
        printf("Envio expresso: entrega em 2 dias\n");
    } else {
        printf("Envio comum: entrega em 7 dias\n");
    }
    return 0;
}
