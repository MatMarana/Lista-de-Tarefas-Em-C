#include "lib.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

Tarefas tarefas[100];

void criaTarefas(int numeroTarefa){ 

  printf("Digite a prioridade da Tarefa: ");
  scanf("%d", &tarefas[numeroTarefa].prioridade);
  
  printf("Digite a descrição da Tarefa: ");
  scanf("%s", tarefas[numeroTarefa].descricao);
  
  printf("Digite a categoria da Tarefa: ");
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


void alteraTarefa(int numeroDeTarefa, int prioridade){
 char escolha[20];
 int novaPrioridade;
 char novoEstado[15];
 char novaCategoria[100];
 char novaDescricao[300];
  for(int i = 0; i < numeroDeTarefa; i++){
    if(prioridade == tarefas[i].prioridade){
      printf("Digite o que deseja alterar: \n");
      scanf("%s", escolha);
      if(strcmp(escolha, "Prioridade") == 0){
        printf("Digite a nova prioridade: ");
        scanf("%d", &novaPrioridade);
        tarefas[i].prioridade = novaPrioridade;
      } else if(strcmp(escolha, "Estado") == 0){
        printf("Digite o novo estado: ");
        scanf("%s", novoEstado);
        strcpy(tarefas[i].estado, novoEstado);
      } else if(strcmp(escolha, "Categoria") == 0){
        printf("Digite a nova categoria: ");
        scanf("%s", novaCategoria);
        strcpy(tarefas[i].categoria, novaCategoria);
      } else if(strcmp(escolha, "Descrição") == 0){
        printf("Digite a nova descrição: ");
        scanf("%s", novaDescricao);
        strcpy(tarefas[i].descricao, novaDescricao);
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

void filtraCategoria(int numeroDeTarefa, char categoria[100]){
  for(int i = 0; i < numeroDeTarefa; i++){
    if(strcmp(categoria, tarefas[i].categoria) == 0){
      printf("Prioridade: %d \n", tarefas[i].prioridade);
          printf("Estado: %s \n", tarefas[i].estado);
          printf("Categoria: %s \n", tarefas[i].categoria);
        printf("Descrição: %s \n", tarefas[i].descricao);
    }
  }
}

void filtraPrioridadeCategoria(int numeroDeTarefa, int prioridade, char categoria[100]){
  for(int i = 0; i < numeroDeTarefa; i++){
    if(prioridade == tarefas[i].prioridade && strcmp(categoria, tarefas[i].categoria) == 0){
      printf("Prioridade: %d \n", tarefas[i].prioridade);
      printf("Estado: %s \n", tarefas[i].estado);
      printf("Categoria: %s \n", tarefas[i].categoria);
      printf("Descrição: %s \n", tarefas[i].descricao);
    }
  }
}