#ifndef DESENALG_LIBRARY_H
#define DESENALG_LIBRARY_H

typedef struct Tarefas { 
 int prioridade;
 char categoria[100];
 char descricao[300];
} Tarefas;

void criaTarefas(int numeroTarefa);
void listaTarefas(int numeroTarefa);
void deltarTarefa(int numeroTarefa, int prioridade);
void verficaPrioridade(int numeroDeTarefa);
#endif 
