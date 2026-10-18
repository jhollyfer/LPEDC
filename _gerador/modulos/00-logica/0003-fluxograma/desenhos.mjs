import { bifurcacao } from '../../../tipos/ideia.mjs'

const desenho = bifurcacao({
  inicio: { forma: 'caixinha', y: 340, nome: 'minutos', valor: '40', tipo: 'tempo parado', w: 270 },
  pergunta: ['minutos <= 15 ?'],
  sim: { rotulo: 'sai de graça', texto: ['Grátis. Boa compra!'], cor: 'cinza' },
  nao: { rotulo: 'cobra', texto: ['Valor: R$ 8.00'], cor: 'verde' },
})
// o exemplo segue pelo Não: a seta do Sim fica cinza e a do Não fica verde
desenho.setas[1].cor = 'cinza'
desenho.setas[2].cor = 'verde'
export const ideia = desenho

export const fluxograma = {
  nos: [
    ['A', 'inicio', 'Início'],
    ['B', 'io', 'Ler minutos'],
    ['C', 'dec', 'minutos <= 15?'],
    ['D', 'io', 'Mostrar "Grátis"'],
    ['E', 'io', 'Mostrar "Valor: R$ 8.00"'],
    ['F', 'inicio', 'Fim'],
  ],
  setas: [
    ['A', 'B'],
    ['B', 'C'],
    ['C', 'D', 'Sim'],
    ['C', 'E', 'Não'],
    ['D', 'F'],
    ['E', 'F'],
  ],
  caminho: ['A', 'B', 'C', 'E', 'F'],
}
