#if 0
#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

#include "../inc/Cadastro.h"
#include "../inc/Paciente.h"
#include "../inc/Funcionario.h"
#include "../inc/Pessoa.h"


void ExibirTodosPacientes(void){

    printf("==========================================================\n");
    printf("== Todos os Cadastros de Paciente ==\n");
    printf("==========================================================\n");
    
    FILE *arquivo = fopen ("paciente.db","r");
    
    char linha [500];
    
    while(fgets(linha, sizeof(linha), arquivo) != NULL){
        printf("%s", linha);
    }

    fclose(arquivo);
}

void ExibirTodosFuncionario(void){

    printf("==========================================================\n");
    printf("== Todos os Cadastros de Paciente ==\n");
    printf("==========================================================\n");
    
    FILE *arquivo = fopen ("funcionario.db","r");
    
    char linha [500];
    
    while(fgets(linha, sizeof(linha), arquivo) != NULL){
        printf("%s", linha);
    }

    fclose(arquivo);
}
 
#endif