// 0173 · Juntando tudo: o controle de acesso
// Exercício E1038 · ★★★
//
// Em vez de papel único, agora cada pessoa participa de vários grupos. Um
// grupo concede algumas permissões e pode negar outras, e a negação de
// qualquer grupo vence a concessão de qualquer outro. Escreva:
//
//   unsigned calcular(int k, const int ids[k], const Grupo grupos[])
//
// que recebe os índices dos k grupos da pessoa (um parâmetro VLA) e devolve
// as permissões finais: (OU de todos os concede) & ~(OU de todos os nega).
//
//   grupos: equipe   concede E R
//           financeiro concede I
//           estagio  nega G C
//           motorista concede G
//   Lia participa de equipe, financeiro e motorista.
//   Teo participa de equipe, motorista e estagio.
//
//   Saída esperada:
//   Lia: ERIG-
//   Teo: ER---
//
// Dicas:
// 1. Acumule duas máscaras separadas no laço: concede e nega. Só no fim
//    aplique a negação; se aplicar grupo a grupo, a ordem dos grupos
//    mudaria o resultado.
// 2. No main, os ids podem ser VLAs: int k = 3; int ids_lia[k]; e preencha
//    um por um (VLA não aceita = {...}).
// 3. Resposta esperada: a saída acima.
//
// Escreva sua resposta abaixo:

#include <stdio.h>

#define ENTRAR   (1u << 0) // E
#define REUNIAO  (1u << 1) // R
#define IMPRIMIR (1u << 2) // I
#define GARAGEM  (1u << 3) // G
#define CONFIG   (1u << 4) // C
#define QTD_PERMS 5

typedef struct {
    char nome[16];
    unsigned concede;
    unsigned nega;
} Grupo;

int main(void) {
    Grupo grupos[] = {
        {"equipe", ENTRAR | REUNIAO, 0},
        {"financeiro", IMPRIMIR, 0},
        {"estagio", 0, GARAGEM | CONFIG},
        {"motorista", GARAGEM, 0},
    };
    (void)grupos; // apague esta linha
    return 0;
}
