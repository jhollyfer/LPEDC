// Lista · Módulo 05 · Vetores, matrizes e strings
// Exercício P0523 · ★★★ · Lendo a planilha em CSV
//
// Uma planilha de municípios do Amazonas foi exportada em CSV, com os campos
// separados por ponto e vírgula (cidade;UF;população). Uma das linhas veio com
// a UF vazia:
//
//   char linhas[4][48] = {"Manaus;AM;2063547", "Parintins;;96372",
//                         "Itacoatiara;AM;103598", "Manacapuru;AM;101883"};
//
// Escreva int separar(const char linha[], char campos[3][32]), que copia
// cada campo para uma linha de campos (sem usar strtok) e devolve quantos
// campos achou. Converta a população com a sua própria conta de dígitos (nada
// de atoi). Mostre uma tabela alinhada, com "??" no lugar da UF vazia, e no
// fim o total e a cidade mais populosa:
//
//   Saída esperada:
//   Manaus       AM   2063547
//   Parintins    ??     96372
//   Itacoatiara  AM    103598
//   Manacapuru   AM    101883
//   Total: 2365400 habitantes
//   Mais populosa: Manaus
//
// Dicas:
// 1. Ande pela linha com i; um índice c diz em qual campo você está e um j,
//    a posição dentro do campo. Ao ver ';', feche o campo atual com '\0',
//    faça c++ e j = 0. No fim da linha, feche o último campo.
// 2. Campo vazio não é problema: ";;" fecha um campo com zero caracteres,
//    e campos[1][0] fica '\0'. Teste com campos[1][0] == '\0'.
// 3. Para a tabela: printf("%-12s %-3s %8d\n", ...).
// 4. Total e maior: guarde o índice da maior população, como no P0501.
// 5. Resposta esperada: a saída acima (total 2365400, Manaus a maior).
//
// Escreva sua resposta abaixo:

#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(void) {
    char linhas[4][48] = {"Manaus;AM;2063547", "Parintins;;96372",
                          "Itacoatiara;AM;103598", "Manacapuru;AM;101883"};
    (void) linhas; // apague esta linha quando escrever

    return 0;
}
