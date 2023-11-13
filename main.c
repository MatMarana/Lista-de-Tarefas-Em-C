#include <stdio.h>
#include <string.h>
#include "lib.h"

int main() {
  Tarefas* listaDeTarefas = NULL;
  int numeroDeTarefas = 0; // variavel de controle
  int escolha; // variavel de controle
  int escolherPrioridade; // variavel de controle
  char escolherEstado[15]; // variavel de controle
  char escolherCategoria[100]; // variavel de controle
  listaDeTarefas = carregar(numeroDeTarefas, "tarefas.bin"); // carrega o arquivo binario

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
    printf("9. Exportar por Prioridade em Arquivo de Texto\n");
    printf("10. Exportar por Categoria em Arquivo de Texto\n");
    printf("11. Exportar por Prioridade e Categoria em Arquivo de Texto\n");
    printf("0. Sair\n");
    printf("Escolha uma opção: ");
    scanf("%d", &escolha); // menu que rece a variavel escolha, utilizada para chamar as funções

    switch(escolha){
     case(1):{ //  caso escolha = 1
      criaTarefas(numeroDeTarefas); // chama a função cria tarefas
      numeroDeTarefas++; // numero de tarefas aumenta 1
      break;
      }
      case(2):{ //  caso escolha = 2
        printf("Digite a prioridade da Tarefa que deseja deletar: ");
        scanf("%d", &escolherPrioridade); // recebe a prioridade digitada
        deltarTarefa(numeroDeTarefas, escolherPrioridade); // chama a função deletar tarefas
        numeroDeTarefas--; // numero de tarefas diminiu 1
        break;
      }
     case(3):{ //  caso escolha = 3
      verficaPrioridade(numeroDeTarefas); // ordena as tarefas por ordem de prioridade
      listaTarefas(numeroDeTarefas); // chama a função listar tarefas
      break;
      }
      case(4):{ //  caso escolha = 4
        printf("Digite a prioridade da Tarefa que deseja alterar: ");
        scanf("%d", &escolherPrioridade); // recebe a prioridade digitada
        alteraTarefa(numeroDeTarefas, escolherPrioridade); // chama a função alterar tarefas
        break;
      }
      case(5):{ //  caso escolha = 5
        printf("Digite a prioridade das tarefas: ");
        scanf("%d", &escolherPrioridade); // recebe a prioridade digitada
        filtraPrioridade(numeroDeTarefas,escolherPrioridade); // chama a função filtrar por prioridade
        break;
      }
      case(6):{ //  caso escolha = 6
        printf("Digite o estado das tarefas: ");
        scanf("%s", escolherEstado); //recebe o estado digitado
        filtraEstado(numeroDeTarefas, escolherEstado); // chama a função filtrar por estado
        break;
      }
      case(7):{ //  caso escolha = 7
        printf("Digite a categoria das tarefas: ");
        scanf("%s", escolherCategoria); //recebe a categoria digitada
        filtraCategoria(numeroDeTarefas, escolherCategoria); // chama a função filtrar por categoria
        break;
      }
      case(8):{ //  caso escolha = 8
        printf("Digite a categoria das tarefas: ");
        scanf("%s", escolherCategoria); //recebe a categoria digitada
        printf("Digite a prioridade das tarefas: ");
        scanf("%d", &escolherPrioridade); // recebe a prioridade digitada
        filtraPrioridadeCategoria(numeroDeTarefas,escolherPrioridade, escolherCategoria); // chama a função filtrar por prioridade e categoria
        break;
      }
      case(9):{ //  caso escolha = 9
        printf("Digite a prioridade das tarefas: ");
        scanf("%d", &escolherPrioridade); // recebe a prioridade digitada
        exportaPrioridade(numeroDeTarefas,escolherPrioridade); // chama a função exportar por prioridade
        break;
      }
      case(10):{ //  caso escolha = 10
        printf("Digite a categoria das tarefas: ");
        scanf("%s", escolherCategoria); //recebe a categoria digitada
        exportaCategoria(numeroDeTarefas, escolherCategoria); // chama a função exportar por categoria
        break;
      }
      case(11):{ //  caso escolha = 11
        printf("Digite a categoria das tarefas: ");
        scanf("%s", escolherCategoria); //recebe a categoria digitada
        printf("Digite a prioridade das tarefas: ");
        scanf("%d", &escolherPrioridade); // recebe a prioridade digitada
        exportaPrioridadeCategoria(numeroDeTarefas,escolherPrioridade, escolherCategoria); // chama a função exportar por prioridade e categoria
        break;
      }
    }
    if(escolha == 0){ //  caso escolha = 0
      salvar(listaDeTarefas,"tarefas.bin"); // salva os dados em binario
      break; // sai do programa
    }
  }
}