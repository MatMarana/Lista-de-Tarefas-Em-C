#include <stdio.h>
#include <string.h>
#include "lib.h"

int main() {
  int numeroDeTarefas = 0;
  int escolha;
  int escolherPrioridade;
  char escolherEstado[15];
  char escolherCategoria[100];
  //listaTarefas = carregar("tarefas.bin");

  while (1) {
    printf("\nOpções:\n");
    printf("1. Adicionar nova tarefa\n");
    printf("2. Deletar Tarefas\n");
    printf("3. Listar tarefas\n");
    printf("4. Edite uma Tarefa Cadastrada\n");
    printf("5. Filtre Tarefas por Prioridade\n");
    printf("6. Filtre Tarefas por Estado\n");
    printf("7. Filtre Tarefas por Categoria\n");
    printf("8. Filtre Tarefas por Prioridade e Categoria\n");
    printf("9. Filtre Tarefas por Prioridade e as Veja em um Arquivo de Texto\n");
    printf("10. Filtre Tarefas por Categoria e as Veja em um Arquivo de Texto\n");
    printf("11. Filtre Tarefas por Prioridade e Categoria e as Veja em um Arquivo de Texto\n");
    printf("Escolha uma opção: ");
    scanf("%d", &escolha);

    switch(escolha){
     case(1):{
      criaTarefas(numeroDeTarefas);
      numeroDeTarefas++;
      break;
      }
      case(2):{
        printf("Digite a prioridade da Tarefa que deseja deletar: ");
        scanf("%d", &escolherPrioridade);
        deltarTarefa(numeroDeTarefas, escolherPrioridade);
        numeroDeTarefas--;
        break;
      }
     case(3):{
      listaTarefas(numeroDeTarefas);
      break;
      }
      case(4):{
        printf("Digite a prioridade da Tarefa que deseja alterar: ");
        scanf("%d", &escolherPrioridade);
        alteraTarefa(numeroDeTarefas, escolherPrioridade);
        break;
      }
      case(5):{
        printf("Digite a prioridade das tarefas: ");
        scanf("%d", &escolherPrioridade);
        filtraPrioridade(numeroDeTarefas,escolherPrioridade);
        break;
      }
      case(6):{
        printf("Digite o estado das tarefas: ");
        scanf("%s", escolherEstado);
        filtraEstado(numeroDeTarefas, escolherEstado);
        break;
      }
      case(7):{
        printf("Digite a categoria das tarefas: ");
        scanf("%s", escolherCategoria);
        filtraCategoria(numeroDeTarefas, escolherCategoria);
        break;
      }
      case(8):{
        printf("Digite a categoria das tarefas: ");
        scanf("%s", escolherCategoria);
        printf("Digite a prioridade das tarefas: ");
        scanf("%d", &escolherPrioridade);
        filtraPrioridadeCategoria(numeroDeTarefas,escolherPrioridade, escolherCategoria);
        break;
      }
      case(9):{
        printf("Digite a prioridade das tarefas: ");
        scanf("%d", &escolherPrioridade);
        exportaPrioridade(numeroDeTarefas,escolherPrioridade);
        break;
      }
      default:{
        printf("Opção inválida. Tente novamente.\n");
      }
    }
    
  }
}