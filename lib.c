#include "lib.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

Tarefas tarefas[100];

void criaTarefas(int numeroTarefa){  // função que cria tarefa

  printf("Digite a prioridade da Tarefa: "); 
  scanf("%d", &tarefas[numeroTarefa].prioridade); // recebe a prioridade da tarefa
  
  printf("Digite a descrição da Tarefa: ");
  scanf("%s", tarefas[numeroTarefa].descricao); // recebe a descrição da tarefa
  
  printf("Digite a categoria da Tarefa: ");
  scanf("%s", tarefas[numeroTarefa].categoria); // recebe a categoria da tarefa
  
  printf("Digite o estado da Tarefa: ");
  scanf("%s", tarefas[numeroTarefa].estado); // recebe o estado da tarefa

}

void deltarTarefa(int numeroTarefa, int prioridade){ 
    for( int i = 0; i < numeroTarefa - 1; i++){ // identa a struct até o número de clientes cadastrados
      if(tarefas[i].prioridade == prioridade){ // se a prioridade recebida existe na lista de tarefas
      tarefas[i] = tarefas[i + 1]; // apaga a tarefa com a prioridade digitada
    }
  }
}


void listaTarefas(int numeroTarefa){ 
  for(int i = 0; i < numeroTarefa; i++){ // identa a struct até o número de clientes cadastrados
    printf("Prioridade: %d \n", tarefas[i].prioridade); // printa a prioridade das tarefas
    printf("Estado: %s \n", tarefas[i].estado); // printa o estado das tarefas
    printf("Categoria: %s \n", tarefas[i].categoria); // printa a categoria das tarefas
    printf("Descrição: %s \n", tarefas[i].descricao); // printa a descrição das tarefas
    }
}

void verficaPrioridade(int numeroDeTarefa){ 
  Tarefas temp;
  int max;
  for (int i = 0; i < numeroDeTarefa - 1; i++) { // identa a struct até o número de clientes cadastrados
    max = i;  //variavel maxx se torna igual a i
    for (int j = i + 1; j < numeroDeTarefa; j++) { // identa a struct até o número de clientes cadastrados
      if (tarefas[j].prioridade > tarefas[max].prioridade) { // se tarefa no indice j for maior que tarefs no indice max
        max = j; // variavel max se torna igual a j
      }
    }
    if (max != i) { //se max for diferente de i
      temp = tarefas[i]; //  temp recebe o array de tarefas no indice i
      tarefas[i] = tarefas[max]; // tarefas no indice i recebe tarefas no indice max
      tarefas[max] = temp; // tarefas ni indice max recebe temp
    }
  }
}


void alteraTarefa(int numeroDeTarefa, int prioridade){
 char escolha[20]; // variavel que armazena a escolha feita pelo usuario
 int novaPrioridade; // variavel que armazena a nova prioidade da tarefa
 char novoEstado[15]; // variavel que armazena o novo estado da tarefa
 char novaCategoria[100]; // variavel que armazena a nova categoria da tarefa
 char novaDescricao[300]; // variavel que armazena a nova descrição da tarefa
  for(int i = 0; i < numeroDeTarefa; i++){ // identa a struct ate o numero de clientes cadastrados
    if(prioridade == tarefas[i].prioridade){ // se a prioridade recebida existe na lista de tarefas
      printf("Digite o que deseja alterar: \n");
      scanf("%s", escolha); // recebe a variavel que o usuario deseja alterar
      if(strcmp(escolha, "prioridade") == 0){ // se a variavel digitada for igual prioridade
        printf("Digite a nova prioridade: ");
        scanf("%d", &novaPrioridade); // recebe a prioridade digitada
        tarefas[i].prioridade = novaPrioridade; // altera a prioridade na struct
      } else if(strcmp(escolha, "estado") == 0){ // se a variavel digitada for igual estado
        printf("Digite o novo estado: "); 
        scanf("%s", novoEstado); //recebe o estado digitado
        strcpy(tarefas[i].estado, novoEstado); // altera o estado na struct
      } else if(strcmp(escolha, "categoria") == 0){ // se a variavel digitada for igual categoria
        printf("Digite a nova categoria: ");
        scanf("%s", novaCategoria); // recebe a categoria digitada
        strcpy(tarefas[i].categoria, novaCategoria); // altera a categroria na struct
      } else if(strcmp(escolha, "descrição") == 0){ // se a variavel digitada for igual descrição
        printf("Digite a nova descrição: ");
        scanf("%s", novaDescricao); //recebe a descrição digitada
        strcpy(tarefas[i].descricao, novaDescricao); // altera a descrição na struct
      }
    }
  }
}


void filtraPrioridade(int numeroDeTarefa, int prioridade){ 
  for(int i = 0; i < numeroDeTarefa; i++){ // identa a struct ate o numero de clientes cadastrados
    if(prioridade == tarefas[i].prioridade){ // verifica se a prioridade recebida existe na lista de tarefas
      printf("Prioridade: %d \n", tarefas[i].prioridade);
          printf("Estado: %s \n", tarefas[i].estado);
          printf("Categoria: %s \n", tarefas[i].categoria);
        printf("Descrição: %s \n", tarefas[i].descricao);  // printa as tarefas que tenham prioridade iguais as digitadas
    }
  }
}

void filtraEstado(int numeroDeTarefa, char estado[15]){
  for(int i = 0; i < numeroDeTarefa; i++){ // identa a struct ate o numero de clientes cadastrados
    if(strcmp(estado, tarefas[i].estado) == 0){ // verifica se o estado recebido existe na lista de tarefas
      printf("Prioridade: %d \n", tarefas[i].prioridade);
          printf("Estado: %s \n", tarefas[i].estado);
          printf("Categoria: %s \n", tarefas[i].categoria);
        printf("Descrição: %s \n", tarefas[i].descricao); // printa as tarefas que tenham estados iguais aos digitados
    }
  }
}

void filtraCategoria(int numeroDeTarefa, char categoria[100]){
  for(int i = 0; i < numeroDeTarefa; i++){ // identa a struct ate o numero de clientes cadastrados
    if(strcmp(categoria, tarefas[i].categoria) == 0){ // verifica se a categoria recebida existe na lista de tarefas
      printf("Prioridade: %d \n", tarefas[i].prioridade);
          printf("Estado: %s \n", tarefas[i].estado);
          printf("Categoria: %s \n", tarefas[i].categoria);
        printf("Descrição: %s \n", tarefas[i].descricao); // printa as tarefas que tenham categorias iguais as digitadas
    }
  }
}

void filtraPrioridadeCategoria(int numeroDeTarefa, int prioridade, char categoria[100]){
  for(int i = 0; i < numeroDeTarefa; i++){ // identa a struct ate o numero de clientes cadastrados
    if(prioridade == tarefas[i].prioridade && strcmp(categoria, tarefas[i].categoria) == 0){ // verifica se a prioridade 
      printf("Prioridade: %d \n", tarefas[i].prioridade);                                    // e categoria recebidas existem
      printf("Estado: %s \n", tarefas[i].estado);                                            // no array de tarefas
      printf("Categoria: %s \n", tarefas[i].categoria);
      printf("Descrição: %s \n", tarefas[i].descricao); // printa as tarefas que tenham prioridade e categorias iguais as 
    }                                                   // digitadas
  }
}

void exportaPrioridade(int numeroDeTarefa, int prioridade){
    FILE *fp; // cria um arquivo fp
    fp = fopen("Prioridade.txt", "w"); //abre o arquivo .txt em modo de escrita
    for (int i = 0; i < numeroDeTarefa; i++) { // identa a struct ate o numero de clientes cadastrados
        if (tarefas[i].prioridade == prioridade) { // verifica se a prioridade recebida existe na lista de tarefas
            fprintf(fp, "%d %s %s %s\n", tarefas[i].prioridade, tarefas[i].estado, tarefas[i].categoria, tarefas[i].descricao);
        } // printa as tarefas que tenham prioridades iguais as digitadas no arquivo fp
    }
    fclose(fp);
}

void exportaCategoria(int numeroDeTarefa, char categoria[100]){
    FILE *fp; // cria um arquivo fp
    fp = fopen("Categoria.txt", "w"); //abre o arquivo .txt em modo de escrita
    for (int i = 0; i < numeroDeTarefa; i++) { // identa a struct ate o numero de clientes cadastrados
        if (strcmp(categoria, tarefas[i].categoria) == 0) { // verifica se a categoria recebida existe na lista de tarefas
            fprintf(fp, "%d %s %s %s\n", tarefas[i].prioridade, tarefas[i].estado, tarefas[i].categoria, tarefas[i].descricao);
        } // printa as tarefas que tenham categoria iguais as digitadas no arquivo fp
    }
    fclose(fp);
}

void exportaPrioridadeCategoria(int numeroDeTarefa, int prioridade, char categoria[100]){
    FILE *fp; // cria um arquivo fp
    fp = fopen("Prioridade e Categoria.txt", "w"); //abre o arquivo .txt em modo de escrita
    for (int i = 0; i < numeroDeTarefa; i++) { // identa a struct ate o numero de clientes cadastrados
        if (strcmp(categoria, tarefas[i].categoria) == 0 && tarefas[i].prioridade == prioridade) { // verifica se a prioridade e categoria recebida existe na lista de tarefas
            fprintf(fp, "%d %s %s %s\n", tarefas[i].prioridade, tarefas[i].estado, tarefas[i].categoria, tarefas[i].descricao);
        } // printa as tarefas que tenham prioridades e categorias iguais as digitadas no arquivo fp
    }
    fclose(fp);
}

void salvar(Tarefas* lista, const char* nomeArquivo) { // salva os dados da struct tarefa em arquivo binário
    FILE* arquivo = fopen(nomeArquivo, "wb");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo para escrita.\n");
        return;
    }

    while (lista != NULL) {
        fwrite(lista, sizeof(Tarefas), 1, arquivo);
    }

    fclose(arquivo);
}

Tarefas* carregar(int numeroDeTarefas, const char* nomeArquivo) { // carrega os dados do arquivo binario
    FILE* arquivo = fopen(nomeArquivo, "rb");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo para leitura.\n");
        return NULL;
    }
    Tarefas* lista = malloc(numeroDeTarefas * sizeof(Tarefas));

  for (int i = 0; i < numeroDeTarefas; i++) {
      fread(&lista[i], sizeof(Tarefas), 1, arquivo);
  }

    fclose(arquivo);
    return lista;
}