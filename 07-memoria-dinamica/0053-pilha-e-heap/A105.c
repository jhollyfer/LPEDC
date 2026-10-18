// A105 · Um bloco, três funções

#include <stdio.h>
#include <stdlib.h>

int blocos_abertos = 0; // DADOS: conta os blocos do heap ainda não devolvidos

// Cria o bolão no heap. O tamanho só aparece na hora de rodar.
int *criar_bolao(int participantes) {
    int *palpites = malloc(participantes * sizeof *palpites); // HEAP
    if (palpites != NULL) {
        blocos_abertos++;
    }
    return palpites; // o frame de criar_bolao some aqui; o bloco, não
}

// Outra função, outro frame: mexe no MESMO bloco só pelo endereço.
void anotar_palpites(int *palpites, int participantes) {
    for (int i = 0; i < participantes; i++) { // i mora na PILHA deste frame
        palpites[i] = (i * 3) % 5; // quantos gols cada um aposta
    }
}

// Uma terceira função decide a hora de devolver o bloco.
void encerrar_bolao(int *palpites) {
    free(palpites);
    blocos_abertos--;
}

int main(void) {
    int participantes = 4;
    int *bolao = criar_bolao(participantes);
    if (bolao == NULL) {
        printf("Sem memória\n");
        return 1;
    }
    printf("Blocos abertos: %d\n", blocos_abertos);

    anotar_palpites(bolao, participantes);
    for (int i = 0; i < participantes; i++) {
        printf("Participante %d: palpite %d\n", i + 1, bolao[i]);
    }

    encerrar_bolao(bolao);
    bolao = NULL; // o endereço guardado não vale mais nada
    printf("Blocos abertos: %d\n", blocos_abertos);
    return 0;
}
// Saída:
// Blocos abertos: 1
// Participante 1: palpite 0
// Participante 2: palpite 3
// Participante 3: palpite 1
// Participante 4: palpite 4
// Blocos abertos: 0
//
// O bloco nasceu em criar_bolao, foi preenchido em anotar_palpites e morreu
// em encerrar_bolao. Nenhuma das três precisou estar viva ao mesmo tempo que
// as outras: quem manda no tempo de vida de um bloco do heap é você.
