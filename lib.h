#ifndef DESENALG_LIBRARY_H
#define DESENALG_LIBRARY_H

typedef struct Tarefas { 
 int prioridade;
 char estado[15];
 char categoria[100];
 char descricao[300];
} Tarefas;

void criaTarefas(int numeroTarefa);
void listaTarefas(int numeroTarefa);
void deltarTarefa(int numeroTarefa, int prioridade);
void verficaPrioridade(int numeroDeTarefa);

void filtraPrioridade(int numeroDeTarefa, int prioridade);
void filtraEstado(int numeroDeTarefa, char estado[15]);
void filtraCategoria(int numeroDeTarefa, char categoria[100]);
void filtraPrioridadeCategoria(int numeroDeTarefa, int prioridade, char categroia[100]);
#endif 
