// Lista · Módulo 23 · Grafos: estrutura e caminhos
// Exercício P2325 · ★★★ · Quantas ordens tem a reforma
//
// Contar as ordenações topológicas com backtracking (assunto 0127) gasta
// um passo por ORDEM: sem regra nenhuma, 12 tarefas teriam 12! = 479
// milhões de ordens. A programação dinâmica conta sem listar: jeitos[S] é
// quantas ordens existem para fazer PRIMEIRO exatamente o conjunto S de
// tarefas (S guardado como bits de um int). Começa com jeitos[0] = 1 e,
// para cada S e cada tarefa v fora de S cujos pré-requisitos estão todos
// em S, soma jeitos[S] em jeitos[S | 1 << v].
//
// Escreva do zero enumera(feitas) (o backtracking) e conta_pd(), com
// pred[v] = bits dos pré-requisitos de v. Teste os três casos:
//
//   Banheiro, 6 tarefas: 0->1, 0->2, 1->3, 3->4, 2->4, 4->5
//   Casa, 12 tarefas: 0->1, 0->2, 0->3, 1->4, 2->4, 3->5, 4->6, 5->6,
//                     6->7, 6->8, 7->9, 8->10, 9->11, 10->11
//   Sem regras, 12 tarefas: só a PD (o backtracking demoraria demais)
//
//   Saída esperada:
//   Banheiro (6 tarefas): backtracking 3, PD 3
//   Casa (12 tarefas): backtracking 120, PD 120
//   Sem regras (12 tarefas): PD 479001600
//
// Dicas:
// 1. v está em S quando (S >> v & 1) é 1. "Todos os pré-requisitos em S"
//    é (pred[v] & ~S) == 0.
// 2. A PD tem 2^n estados e n transições por estado: O(2^n · n), umas 50
//    mil operações para n = 12, contra milhões de folhas do backtracking.
//    Use long long: 12! não cabe em muitos tipos menores.
// 3. Resposta esperada: 3 ordens no banheiro, 120 na casa e 479001600 sem
//    regras.
//
// Escreva sua resposta abaixo:

#include <stdio.h>

int main(void) {

    return 0;
}
