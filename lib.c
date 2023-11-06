#include "lib.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Tarefa tarefas[100];

Tarefa* criar(int prioridade, const char* categoria, const char* descricao) {
    Tarefa* novaTarefa = (struct Tarefa*)malloc(sizeof(struct Tarefa)); // aloca a memória do tamanho da struc
    if (novaTarefa == NULL) {
        printf("Erro ao alocar memória para a tarefa.\n");
        exit(1);
    } // verifica se foi possível alocar a memória para o struct
      novaTarefa->prioridade = prioridade; // o valor da prioridade da tarefa recebe a prioridade usada como argumento na função
    strncpy(novaTarefa->categoria, categoria, sizeof(novaTarefa->categoria) - 1); // copia a string categoria para a nova tarefa
    strncpy(novaTarefa->descricao, descricao, sizeof(novaTarefa->descricao) - 1); // copia a string dexrição para a nova tarefa
    novaTarefa->proxima = NULL; // indica que a tarefa criada é a última adicionada

    return novaTarefa;
}

void adicionar(Tarefa** lista, Tarefa* novaTarefa) { // verfica se a está vazia, caso esteje a tarefa será a primeira. Caso contrario irá percorrer a lista até achar a posição da tarefa de acordo com sua prioridade
    if (*lista == NULL || novaTarefa->prioridade > (*lista)->prioridade) { 
        novaTarefa->proxima = *lista;
        *lista = novaTarefa;
    } else {
        Tarefa* atual = *lista;
        while (atual->proxima != NULL && novaTarefa->prioridade <= atual->proxima->prioridade) {
            atual = atual->proxima;
        }
        novaTarefa->proxima = atual->proxima;
        atual->proxima = novaTarefa;
    }
}

void listar(Tarefa* lista) {
    if (lista == NULL) {
        printf("\nLista de tarefas vazia.\n"); // se  a lista tiver vazia printa que está vazia
        return;
    } 

    printf("\nLista de tarefas:\n");
    while (lista != NULL) { //se não estiver vazia printa as tarefas existentes
        printf("Prioridade: %d\n", lista->prioridade);
        printf("Categoria: %s\n", lista->categoria);
        printf("Descrição: %s\n", lista->descricao);
        printf("\n");
        lista = lista->proxima;
    }
}

void deletar(Tarefa** lista, int prioridade) { // recebe a prioridade da tarefa a ser deletada, e caso não exista printa que não foi possível apagar a tarefa
    struct Tarefa* atual = *lista;
    struct Tarefa* anterior = NULL;

    while (atual != NULL && atual->prioridade != prioridade) {
        anterior = atual;
        atual = atual->proxima;
    }

    if (atual == NULL) {
        printf("Tarefa com prioridade %d não encontrada.\n", prioridade);
        return;
    }

    if (anterior == NULL) { // se anterior estiver vazia, a lista recebe a variavel proxima fazendo que a proxima tarefa adicionada seja a primeira da lista
        *lista = atual->proxima;
    } else { // senão ela é deletada e a tarefa anterior ocupa o lugar dela
        anterior->proxima = atual->proxima;
    }

    free(atual); // limpa a variavel atual
    printf("Tarefa com prioridade %d deletada com sucesso.\n", prioridade);
}

void salvar(Tarefa* lista, const char* nomeArquivo) { // salva os dados da strcut tarefa em arquivo binário
    FILE* arquivo = fopen(nomeArquivo, "wb");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo para escrita.\n");
        return;
    }

    while (lista != NULL) {
        fwrite(lista, sizeof(struct Tarefa), 1, arquivo);
        lista = lista->proxima;
    }

    fclose(arquivo);
}

 Tarefa* carregar(const char* nomeArquivo) { // carrega os dados do arquivo binario
    FILE* arquivo = fopen(nomeArquivo, "rb");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo para leitura.\n");
        return NULL;
    }

    Tarefa* lista = NULL;
    Tarefa tarefa;

    while (fread(&tarefa, sizeof(struct Tarefa), 1, arquivo) == 1) {
        struct Tarefa* novaTarefa = criar(tarefa.prioridade, tarefa.categoria, tarefa.descricao);
        adicionar(&lista, novaTarefa);
    }

    fclose(arquivo);
    return lista;
}
