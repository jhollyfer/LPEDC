// 0134 · Seleção de intervalos
// Exercício E802 · ★★☆
//
// A fiscal da vigilância sanitária precisa passar por todas as feiras de
// domingo. Ela anda rápido: numa visita, num certo horário, fiscaliza todas
// as feiras abertas naquela hora. Os horários são FECHADOS, [abre, fecha]:
//
//   Pinheiros 7-12, Lapa 6-9, Tatuapé 10-14, Mooca 8-11,
//   Liberdade 13-18, Butantã 15-17, Santana 16-20
//
// Qual é o menor número de visitas? Guloso: ordene pela hora de
// fechamento; pegue a feira que fecha primeiro e ainda não foi vista e
// marque uma visita na hora em que ela FECHA (o mais tarde possível, para
// pegar o maior número de outras abertas). Mostre cada visita com as feiras
// abertas naquela hora, olhando só as que vêm dali em diante na ordem.
//
//   Saída esperada:
//   Visita às 9h: Lapa Mooca Pinheiros
//   Visita às 14h: Tatuapé Liberdade
//   Visita às 17h: Butantã Liberdade Santana
//   Total: 3 visitas
//
// Dicas:
// 1. Guarde a hora da última visita (começa em -1). A feira i ainda não foi
//    vista se abre depois dela: f[i].abre > ultima.
// 2. Para listar quem está aberta na hora h: f[j].abre <= h && h <= f[j].fecha.
// 3. Resposta esperada: a saída acima. A Liberdade aparece duas vezes
//    porque está aberta nas duas horas; ela já estava coberta na visita das
//    14h. É o problema do texto visto ao contrário: cada visita "fura" todas
//    as feiras que a cruzam.
//
// Escreva sua resposta abaixo:

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    const char *feira;
    int abre, fecha; // horário fechado [abre, fecha]
} Feira;

int main(void) {
    Feira f[] = {
        {"Pinheiros", 7, 12},  {"Lapa", 6, 9},        {"Tatuapé", 10, 14},
        {"Mooca", 8, 11},      {"Liberdade", 13, 18}, {"Butantã", 15, 17},
        {"Santana", 16, 20},
    };
    int n = 7;
    (void)f;
    (void)n;

    return 0;
}
