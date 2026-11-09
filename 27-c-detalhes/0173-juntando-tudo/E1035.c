// 0173 · Juntando tudo: o controle de acesso
// Exercício E1035 · ★★☆
//
// As duas funções abaixo compilam sem nenhum aviso, mas estão erradas:
//
//   - revogar deveria tirar as permissões de m, e devolve um número enorme;
//   - tem_todas deveria responder se p tem TODAS as permissões de m, e
//     responde se tem ALGUMA.
//
// Conserte as duas, sem mexer no main.
//
//   Saída esperada:
//   depois de revogar: 3
//   tem R e I? nao
//   tem E e R? sim
//
// Dicas:
// 1. Rode antes: sai 4294967295 e "sim" duas vezes.
// 2. p | ~m liga todos os bits que NÃO estão em m. Para apagar, o
//    operador é outro.
// 3. (p & m) != 0 é "sobrou algum". "Sobraram todos" compara com m.
// 4. Resposta esperada: a saída acima.
//
// Escreva sua resposta abaixo (conserte o código):

#include <stdbool.h>
#include <stdio.h>

#define ENTRAR   (1u << 0) // E
#define REUNIAO  (1u << 1) // R
#define IMPRIMIR (1u << 2) // I
#define GARAGEM  (1u << 3) // G
#define CONFIG   (1u << 4) // C
#define QTD_PERMS 5

unsigned revogar(unsigned p, unsigned m) {
    return p | ~m;
}

bool tem_todas(unsigned p, unsigned m) {
    return (p & m) != 0;
}

int main(void) {
    unsigned p = ENTRAR | REUNIAO | IMPRIMIR;
    p = revogar(p, IMPRIMIR);
    printf("depois de revogar: %u\n", p);
    printf("tem R e I? %s\n", tem_todas(p, REUNIAO | IMPRIMIR) ? "sim" : "nao");
    printf("tem E e R? %s\n", tem_todas(p, ENTRAR | REUNIAO) ? "sim" : "nao");
    return 0;
}
