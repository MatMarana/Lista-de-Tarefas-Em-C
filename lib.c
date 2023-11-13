#include "lib.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

Tarefas tarefas[100];

void criaTarefas(int numeroTarefa){ 

  printf("Digite a prioridade da Tarefa\n");
  scanf("%d", &tarefas[numeroTarefa].prioridade);
  
  printf("Digite a descrição da Tarefa\n");
  scanf("%s", tarefas[numeroTarefa].descricao);
  
  printf("Digite a categoria da Tarefa\n");
  scanf("%s", tarefas[numeroTarefa].categoria);
  
  printf("Digite o estado da Tarefa\n");
  scanf("%s", tarefas[numeroTarefa].estado);

  verficaPrioridade(numeroTarefa);

}

void deltarTarefa(int numeroTarefa, int prioridade){ // arrumar 
    for ( int i = 0; i < numeroTarefa; i++) {
        if (tarefas[i].prioridade == prioridade) {
          break;
        }
    for(; i < numeroTarefa - 1; i++){
      tarefas[i] = tarefas[i + 1];
    }
  }
}


void listaTarefas(int numeroTarefa){
  for(int i = 0; i < numeroTarefa; i++){
    printf("Prioridade: %d \n", tarefas[i].prioridade);
    printf("Estado: %s \n", tarefas[i].estado);
    printf("Categoria: %s \n", tarefas[i].categoria);
    printf("Descrição: %s \n", tarefas[i].descricao);
    }
}

void verficaPrioridade(int numeroDeTarefa){ // arrumar
  Tarefas temp;
  for(int i = 0; i < numeroDeTarefa; i ++){
    for(int j = 0; j < numeroDeTarefa; j++){
      if(tarefas[i].prioridade < tarefas[j].prioridade){
        temp = tarefas[i];
        tarefas[i] = tarefas[j];
        tarefas[j] = temp;
      } else {
        temp = tarefas[j];
        tarefas[j] = tarefas[i];
        tarefas[i] = temp;
      }
    } 
  }
}

void filtraPrioridade(int numeroDeTarefa, int prioridade){
  for(int i = 0; i < numeroDeTarefa; i++){
    if(prioridade == tarefas[i].prioridade){
      printf("Prioridade: %d \n", tarefas[i].prioridade);
          printf("Estado: %s \n", tarefas[i].estado);
          printf("Categoria: %s \n", tarefas[i].categoria);
        printf("Descrição: %s \n", tarefas[i].descricao); 
    }
  }
}

void filtraEstado(int numeroDeTarefa, char estado[15]){
  for(int i = 0; i < numeroDeTarefa; i++){
    if(strcmp(estado, tarefas[i].estado) == 0){
      printf("Prioridade: %d \n", tarefas[i].prioridade);
          printf("Estado: %s \n", tarefas[i].estado);
          printf("Categoria: %s \n", tarefas[i].categoria);
        printf("Descrição: %s \n", tarefas[i].descricao); 
    }
  }
}