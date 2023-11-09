#include <stdio.h>
#include <string.h>
#include "lib.h"

int main() {
    int numeroDeTarefas = 0;
    int escolha;
    int escolherPrioridade; 
    //listaTarefas = carregar("tarefas.bin");

    while (1) {
        printf("\nOpções:\n");
        printf("1. Adicionar nova tarefa\n");
        printf("2. Deletar Tarefas\n");
        printf("3. Listar tarefas\n");
        printf("4. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &escolha);
  
          switch(escolha){
           case(1):{
            criaTarefas(numeroDeTarefas);
            numeroDeTarefas++;
            break;
            }
            case(2):{
              printf("Digite a prioridade da Tarefa que deseja deletar:");
              scanf("%d", &escolherPrioridade);
              deltarTarefa(numeroDeTarefas, escolherPrioridade);
              break;
            }
           case(3):{
            listaTarefas(numeroDeTarefas);
            break;
            }
            default:
                printf("Opção inválida. Tente novamente.\n");
        }
    }

    return 0;
}