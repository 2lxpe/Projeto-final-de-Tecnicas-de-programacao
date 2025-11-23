#include <stdio.h>
#include <string.h>

#define MAX_TAREFAS 100

char titulos[MAX_TAREFAS][100];
char descricoes[MAX_TAREFAS][250];
int prioridades[MAX_TAREFAS];
int prazos[MAX_TAREFAS];
int total_tarefas = 0;

void cadastrarTarefa();
void listarTarefas();
void editarTarefa();
void removerTarefa();

int main() {
    int opcao;
    do {
        printf("\n= SISTEMA DE TAREFAS =\n");
        printf("1. Cadastrar tarefa\n");
        printf("2. Listar tarefas\n");
        printf("3. Editar tarefa\n");
        printf("4. Remover tarefa\n");
        printf("0. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                cadastrarTarefa();
                break;
            case 2:
                listarTarefas();
                break;
            case 3:
                editarTarefa();
                break;
            case 4:
                removerTarefa();
                break;
            case 0:
                printf("Saindo do sistema...\n");
                break;
            default:
                printf("Opcao invalida!\n");
        }
    } while (opcao != 0);

    return 0;
}

void cadastrarTarefa() {
    if (total_tarefas >= MAX_TAREFAS) {
        printf("\nErro: limite de tarefas atingido!\n");
        return;
    }

    printf("\n- Nova tarefa (%d) -\n", total_tarefas + 1);
    
    printf("Titulo: ");
    scanf(" %[^\n]", titulos[total_tarefas]);

    printf("Descricao: ");
    scanf(" %[^\n]", descricoes[total_tarefas]);

    printf("Prioridade (1-baixa, 2-media, 3-alta): ");
    scanf("%d", &prioridades[total_tarefas]);

    printf("Prazo (dias): ");
    scanf("%d", &prazos[total_tarefas]);

    total_tarefas++;
    printf("Tarefa cadastrada com sucesso!\n");
}

void listarTarefas() {
    if (total_tarefas == 0) {
        printf("\nNenhuma tarefa cadastrada.\n");
        return;
    }

    printf("\n-Lista de tarefas-\n");
    for (int i = 0; i < total_tarefas; i++) {
        printf("\n[ID: %d] Titulo: %s\n", i + 1, titulos[i]);
        printf("Descricao: %s\n", descricoes[i]);
        
        switch (prioridades[i]) {
            case 1: printf("Prioridade: baixa\n"); break;
            case 2: printf("Prioridade: media\n"); break;
            case 3: printf("Prioridade: alta\n"); break;
            default: printf("Prioridade: indefinida\n");
        }

        if (prazos[i] <= 0) printf("Status: vencida\n");
        else printf("Status: em dia (%d dias restantes)\n", prazos[i]);
    }
}

void editarTarefa() {
    int id;
    listarTarefas();
    if (total_tarefas == 0) return;

    printf("\nDigite o ID da tarefa para editar: ");
    scanf("%d", &id);

    if (id < 1 || id > total_tarefas) {
        printf("ID invalido!\n");
        return;
    }

    int indice = id - 1;

    printf("\nEditando tarefa '%s'...\n", titulos[indice]);
    
    printf("Novo titulo: ");
    scanf(" %[^\n]", titulos[indice]);

    printf("Nova descricao: ");
    scanf(" %[^\n]", descricoes[indice]);

    printf("Nova prioridade (1-baixa, 2-media, 3-alta): ");
    scanf("%d", &prioridades[indice]);

    printf("Novo prazo (dias): ");
    scanf("%d", &prazos[indice]);

    printf("Tarefa editada com sucesso!\n");
}

void removerTarefa() {
    int id;
    listarTarefas();
    if (total_tarefas == 0) return;

    printf("\nDigite o ID da tarefa para excluir: ");
    scanf("%d", &id);

    if (id < 1 || id > total_tarefas) {
        printf("ID invalido!\n");
        return;
    }

    int indice = id - 1;

    for (int i = indice; i < total_tarefas - 1; i++) {
        strcpy(titulos[i], titulos[i + 1]);
        strcpy(descricoes[i], descricoes[i + 1]); 
        prioridades[i] = prioridades[i + 1]; 
        prazos[i] = prazos[i + 1];
    }

    total_tarefas--;
    printf("Tarefa removida com sucesso!\n");
}