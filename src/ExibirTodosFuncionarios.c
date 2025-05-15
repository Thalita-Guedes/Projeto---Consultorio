#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

#include "../inc/Cadastro.h"
#include "../inc/Paciente.h"
#include "../inc/Funcionario.h"
#include "../inc/Pessoa.h"

static int Menu(const char* titulo){
    printf("\n ========%s=========\n", titulo);
    return 0;
}

void ExibirTodosFuncionarios(void){
     char linha [500];
     FILE *arquivo = fopen ("funcionario.db","r");

Menu("Exibir Todos os Funcionários");

    while(fgets(linha, sizeof(linha), arquivo) != NULL){
        printf("%s", linha);
    }

    fclose(arquivo);
}

