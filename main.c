#include <stdio.h>
#include <string.h>
#include "lib.h"

int main() {
    struct Tarefa* listaTarefas = NULL;
    listaTarefas = carregar("tarefas.bin");

    while (1) {
        printf("\nOpções:\n");
        printf("1. Adicionar nova tarefa\n");
        printf("2. Listar tarefas\n");
        printf("3. Deletar tarefa\n");
        printf("4. Sair\n");
        printf("Escolha uma opção: ");

        int escolha;
        scanf("%d", &escolha);

        switch (escolha) {
            case 1: {
                int prioridade;
                char categoria[100];
                char descricao[300];

                printf("\nDigite a prioridade: ");
                scanf("%d", &prioridade);

                printf("Digite a categoria: ");
                scanf("%s", categoria);

                printf("Digite a descrição: ");
                scanf(" %[^\n]", descricao);

                Tarefa* novaTarefa = criar(prioridade, categoria, descricao);
                adicionar(&listaTarefas, novaTarefa);
                printf("\nTarefa adicionada com sucesso!\n");
                break;
            }
            case 2:
                listar(listaTarefas);
                break;
            case 3: {
                int prioridade;
                printf("\nDigite a prioridade da tarefa a ser deletada: ");
                scanf("%d", &prioridade);
                deletar(&listaTarefas, prioridade);
                break;
            }
            case 4:
               salvar(listaTarefas, "tarefas.bin");
                printf("Tarefas salvas com sucesso.\n");
                // Liberar memória antes de sair
                while (listaTarefas != NULL) {
                    struct Tarefa* temp = listaTarefas;
                    listaTarefas = listaTarefas->proxima;
                    free(temp);
                }
                return 0;
            default:
                printf("Opção inválida. Tente novamente.\n");
        }
    }

    return 0;
}