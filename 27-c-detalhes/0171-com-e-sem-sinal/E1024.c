// 0171 · Com sinal e sem sinal
// Exercício E1024 · ★★☆
//
// As duas funções abaixo compilam sem nenhum aviso, mas erram por causa do
// size_t, que nunca é negativo:
//
//   - mais_longo devolve o nome mais comprido (no empate, o segundo);
//   - restantes diz quantos caracteres ainda cabem numa mensagem de até
//     limite caracteres, e deve dar 0 quando a mensagem já passou.
//
// Conserte as duas sem mudar a assinatura nem o main.
//
//   Saída esperada:
//   mais longo: Bernardo
//   mais longo: Bernardo
//   restam 7 caracteres
//   restam 0 caracteres
//
// Escreva sua resposta abaixo (conserte o código):

#include <stdio.h>
#include <string.h>

const char *mais_longo(const char *a, const char *b) {
    if (strlen(a) - strlen(b) > 0) {
        return a;
    }
    return b;
}

size_t restantes(const char *msg, size_t limite) {
    return limite - strlen(msg);
}

int main(void) {
    printf("mais longo: %s\n", mais_longo("Ana", "Bernardo"));
    printf("mais longo: %s\n", mais_longo("Bernardo", "Ana"));
    printf("restam %zu caracteres\n", restantes("Oi, tudo bem?", 20));
    printf("restam %zu caracteres\n", restantes("Chego em 15 minutos, me espera", 20));
    return 0;
}
