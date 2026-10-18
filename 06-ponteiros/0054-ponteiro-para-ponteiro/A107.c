// A107 · As vagas do estacionamento

#include <stdio.h>

int main(void) {
    int vagas = 40;      // vagas livres no estacionamento do shopping
    int *p = &vagas;     // p guarda o endereço de vagas
    int **pp = &p;       // pp guarda o endereço de p

    printf("&vagas = %p\n", (void *)&vagas);
    printf("p      = %p   (o endereço de vagas)\n", (void *)p);
    printf("&p     = %p\n", (void *)&p);
    printf("pp     = %p   (o endereço de p)\n", (void *)pp);
    printf("*pp    = %p   (o que tem em p)\n", (void *)*pp);
    printf("**pp   = %d\n", **pp);

    **pp = **pp - 2;     // entraram 2 carros: muda vagas em dois saltos
    printf("vagas  = %d\n", vagas);
    return 0;
}
// Saída (os endereços mudam a cada execução):
// &vagas = 0x7fe808c00030
// p      = 0x7fe808c00030   (o endereço de vagas)
// &p     = 0x7fe808c00040
// pp     = 0x7fe808c00040   (o endereço de p)
// *pp    = 0x7fe808c00030   (o que tem em p)
// **pp   = 40
// vagas  = 38
