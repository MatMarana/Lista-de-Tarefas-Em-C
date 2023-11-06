#ifndef DESENALG_LIBRARY_H
#define DESENALG_LIBRARY_H

struct Tarefa {
    int prioridade;
    char categoria[100];
    char descricao[300];
    struct Tarefa* proxima;
};
typedef struct Tarefa Tarefa;

Tarefa* criar(int prioridade, const char* categoria, const char* descricao);
void adicionar(Tarefa** lista, Tarefa* novaTarefa);
void listar(Tarefa* lista);
void deletar(Tarefa** lista, int prioridade);
void salvar(Tarefa* lista, const char* nomeArquivo);
Tarefa* carregar(const char* nomeArquivo); 

#endif 
