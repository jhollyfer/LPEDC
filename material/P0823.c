// Lista · Módulo 08 · Tipos compostos
// Exercício P0823 · ★★★ · Do CSV para o vetor de structs
//
// O formulário de inscrição da corrida de rua exportou um CSV, uma pessoa por
// linha (nome;idade;cidade), e algumas linhas vieram com defeito:
//
//   const char *linhas[7] = {"Ana Paula;34;Manaus", "Joel;abc;Parintins",
//                            "Rosa;52;Manaus", "Iuri;19;Itacoatiara",
//                            "Sem cidade;40", "Marta;27;Parintins",
//                            "Caio;61;Manaus"};
//
// Crie typedef struct { char nome[24]; int idade; char cidade[16]; } Atleta;
// e escreva bool ler_atleta(const char *linha, Atleta *a), que separa os
// três campos (com strchr ou andando com um ponteiro), confere se a idade é
// só de dígitos, se há exatamente 3 campos e se cada texto cabe no seu
// campo, e preenche *a. Guarde as linhas boas num vetor de Atleta, mostre as
// recusadas e, das aceitas, a média de idade, o mais velho e quantos atletas
// há por cidade:
//
//   Saída esperada:
//   Recusada: "Joel;abc;Parintins"
//   Recusada: "Sem cidade;40"
//   Aceitas: 5
//   Média de idade: 38.6
//   Mais velho: Caio, 61 anos
//   Manaus: 3
//   Itacoatiara: 1
//   Parintins: 1
//
// Dicas:
// 1. strchr(s, ';') devolve o endereço do próximo ';' (ou NULL). A
//    distância (p - s) é o tamanho do campo: copie com memcpy e feche com
//    '\0' (confira antes se cabe).
// 2. Para a contagem por cidade, um segundo vetor de structs { char
//    cidade[16]; int total; } que cresce quando aparece cidade nova (procure
//    com strcmp).
// 3. Converta a idade com a sua própria conta (o atoi aceitaria "abc" e
//    devolveria 0 sem avisar).
// 4. Resposta esperada: a saída acima.
//
// Escreva sua resposta abaixo:

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

int main(void) {
    const char *linhas[7] = {"Ana Paula;34;Manaus", "Joel;abc;Parintins",
                             "Rosa;52;Manaus", "Iuri;19;Itacoatiara",
                             "Sem cidade;40", "Marta;27;Parintins",
                             "Caio;61;Manaus"};
    (void) linhas; // apague esta linha quando escrever

    return 0;
}
