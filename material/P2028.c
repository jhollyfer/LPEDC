// Lista · Módulo 20 · Divisão e conquista e algoritmos gulosos
// Exercício P2028 · ★★★ · Vigias para o dia inteiro
//
// O condomínio precisa de vigia das 0h às 24h, sem buraco, e cada vigia da
// lista só aceita um turno fixo [ini, fim] (horas, e um turno cobre de ini
// até fim, inclusive as pontas):
//
//   Edu [0, 6]   Bia [2, 9]   Gil [5, 12]   Ana [8, 14]   Caio [10, 18]
//   Rui [15, 20]   Lia [17, 24]   Davi [19, 24]   Teo [0, 4]
//
// Contratar custa caro: qual o MENOR número de vigias que cobre [0, 24]?
// O guloso da COBERTURA DE INTERVALOS: com a cobertura indo até a hora t
// (começa em 0), entre os turnos que começam em t ou antes, escolha o que
// termina MAIS TARDE; agora t vira o fim dele. Pare quando t chegar a 24 ou
// quando ninguém conseguir avançar (aí há um buraco). Escreva do zero e,
// depois, rode de novo sem a Caio e mostre onde fica o buraco.
//
//   Saída esperada:
//   Todos:
//     Edu [0, 6]
//     Gil [5, 12]
//     Caio [10, 18]
//     Lia [17, 24]
//     Total: 4 vigias
//   Sem a Caio:
//     Edu [0, 6]
//     Gil [5, 12]
//     Ana [8, 14]
//     Buraco: ninguém cobre depois das 14h
//
// Dicas:
// 1. Com poucos turnos, cada passo pode olhar todos (O(n²) no total);
//    ordenando por início dá O(n log n).
// 2. "Ninguém consegue avançar" é: o melhor fim achado é <= t.
// 3. Resposta esperada: 4 vigias (Edu, Gil, Caio e Lia); sem a Caio, a
//    cobertura trava às 14h: o Rui só chega às 15h.
//
// Escreva sua resposta abaixo:

#include <stdio.h>

int main(void) {

    return 0;
}
