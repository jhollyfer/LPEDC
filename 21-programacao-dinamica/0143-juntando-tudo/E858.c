// 0143 · Juntando tudo: um mini-diff
// Exercício E858 · ★★★
//
// Quando dois arquivos têm centenas de linhas e só duas mudaram, o diff
// completo é inútil: ninguém acha as mudanças no meio de tudo. O "diff -u"
// mostra só as linhas mudadas e algumas linhas iguais em volta, o
// CONTEXTO, e troca cada trecho pulado por "...".
//
// As duas versões de uma receita de bolo já estão no main. Escreva o diff
// com 1 linha de contexto (#define CONTEXTO 1): uma linha igual só aparece
// se estiver a no máximo 1 posição de uma mudança na sequência de
// operações; cada trecho escondido (inclusive no começo e no fim) vira
// uma linha "...". As mudanças saem como "- texto" e "+ texto"; as linhas de
// contexto, como "  texto".
//
//   Saída esperada:
//   ...
//     2. Unte a forma com manteiga.
//   - 3. Bata 3 ovos com 2 xícaras de açúcar.
//   + 3. Bata 3 ovos com 1 xícara de açúcar.
//     4. Junte 1 xícara de leite.
//   ...
//     11. Desenforme.
//   - 12. Sirva.
//   + 12. Cubra com calda de chocolate.
//   + 13. Sirva.
//
// Dicas:
// 1. Faça em duas passadas. Na 1ª, a volta do texto, mas em vez de imprimir,
//    guarde cada operação num vetor op[] (' ', '-' ou '+') e o texto num
//    vetor de ponteiros.
// 2. Na 2ª, a operação t aparece se alguma operação entre t - CONTEXTO e
//    t + CONTEXTO não for ' '.
// 3. Guarde o índice da última operação mostrada: se a próxima a aparecer
//    não for a seguinte, imprima "..." antes. No fim, se sobrou alguma
//    escondida, mais um "...".
// 4. Teste com CONTEXTO 0 e 2 também.
// 5. Resposta esperada: a saída acima.
//
// Escreva sua resposta abaixo:

#include <stdio.h>
#include <string.h>

int main(void) {
    const char *a[] = {"1. Pré-aqueça o forno a 180 graus.",
                       "2. Unte a forma com manteiga.",
                       "3. Bata 3 ovos com 2 xícaras de açúcar.",
                       "4. Junte 1 xícara de leite.",
                       "5. Acrescente 3 xícaras de farinha.",
                       "6. Misture até ficar liso.",
                       "7. Coloque 1 colher de fermento.",
                       "8. Despeje na forma.",
                       "9. Asse por 40 minutos.",
                       "10. Espere esfriar.",
                       "11. Desenforme.",
                       "12. Sirva."};
    const char *b[] = {"1. Pré-aqueça o forno a 180 graus.",
                       "2. Unte a forma com manteiga.",
                       "3. Bata 3 ovos com 1 xícara de açúcar.",
                       "4. Junte 1 xícara de leite.",
                       "5. Acrescente 3 xícaras de farinha.",
                       "6. Misture até ficar liso.",
                       "7. Coloque 1 colher de fermento.",
                       "8. Despeje na forma.",
                       "9. Asse por 40 minutos.",
                       "10. Espere esfriar.",
                       "11. Desenforme.",
                       "12. Cubra com calda de chocolate.",
                       "13. Sirva."};
    int m = 12, n = 13;

    (void) a; // tire estas três linhas quando usar a, b, m e n
    (void) b;
    (void) m, (void) n;

    return 0;
}
