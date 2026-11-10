// A181 · Anagramas: borbulhando as letras

#include <stdio.h>
#include <stdbool.h>
#include <string.h>

// ordena as letras da string s com bubble sort (char também é número)
void ordena_letras(char s[], bool mostrar) {
    int n = (int) strlen(s);          // o '\0' do fim fica fora
    bool trocou = true;
    for (int passada = 1; passada < n && trocou; passada++) {
        trocou = false;
        for (int j = 0; j < n - passada; j++) {
            if (s[j] > s[j + 1]) {    // compara os códigos das letras
                char aux = s[j];
                s[j] = s[j + 1];
                s[j + 1] = aux;
                trocou = true;
            }
        }
        if (mostrar) {
            printf("  passada %d: %s\n", passada, s);
        }
    }
}

bool anagramas(const char *a, const char *b, bool mostrar) {
    char x[32], y[32];
    if (strlen(a) != strlen(b) || strlen(a) >= sizeof x) {
        return false;
    }
    strcpy(x, a);                     // ordena cópias: as originais ficam intactas
    strcpy(y, b);
    ordena_letras(x, mostrar);
    ordena_letras(y, false);
    return strcmp(x, y) == 0;         // mesmas letras ordenadas = anagramas
}

int main(void) {
    printf("ordenando \"pernambuco\":\n");
    bool r = anagramas("pernambuco", "cobrapenum", true);
    printf("pernambuco / cobrapenum: %s\n", r ? "anagramas" : "não");
    printf("amor / roma: %s\n", anagramas("amor", "roma", false) ? "anagramas" : "não");
    printf("pato / topo: %s\n", anagramas("pato", "topo", false) ? "anagramas" : "não");
    return 0;
}
// Saída (a passada 7 não troca nada: a bandeira encerra):
// ordenando "pernambuco":
//   passada 1: epnambrcou
//   passada 2: enambpcoru
//   passada 3: eambncopru
//   passada 4: aebmcnopru
//   passada 5: abecmnopru
//   passada 6: abcemnopru
//   passada 7: abcemnopru
// pernambuco / cobrapenum: anagramas
// amor / roma: anagramas
// pato / topo: não
