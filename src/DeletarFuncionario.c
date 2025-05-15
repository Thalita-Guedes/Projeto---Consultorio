#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

#include "../inc/Cadastro.h"
#include "../inc/Paciente.h"
#include "../inc/Funcionario.h"
#include "../inc/Pessoa.h"

static int Menu(const char* titulo, struct Opcoes* campo){
    printf("\n ========%s=========\n", titulo);
    printf("%s:\n", (*campo).pergunta);
    fgets((char*)(*campo).resposta, (*campo).tamanho,stdin);
    ((char*)(*campo).resposta)[strcspn((char*)(*campo).resposta, "\n")] = '\0';
    return 0;
}

void DeletarFuncionario(void){

char cpfBuscado [20];
char linha [500];
char cpfLido[25];
bool excluir = false;
bool funcionarioDeletado= false;
bool dentroBloco = false;
char blocoFuncionario[400] = "\0";
char nomeFuncionario[50]= "";

 FILE *arquivo = fopen ("funcionario.db","r");
 FILE *temp = fopen("temp.db", "w"); 

struct Opcoes listaOpcoes[]={
    {
    .tipo = texto,
    .pergunta = "Digite o CPF do funcionário que deseja consultar",
    .resposta = cpfBuscado,
    .tamanho = sizeof(cpfBuscado)
    },
};

Menu("Deletar Funcionário", listaOpcoes);

       while (fgets(linha, sizeof(linha), arquivo)){

            if (strncmp(linha, "Nome:", 5) == 0) {
                dentroBloco = true;
                excluir = false; 
                blocoFuncionario[0] = '\0';

                strncpy(nomeFuncionario, linha + 6, sizeof(nomeFuncionario));
                nomeFuncionario[strcspn(nomeFuncionario, "\n")] = '\0';
            }

            if (dentroBloco){
               strcat(blocoFuncionario, linha);

            if (strncmp(linha, "CPF:", 4) == 0){
                strncpy(cpfLido, linha + 4, sizeof(cpfLido));
                cpfLido[strcspn(cpfLido, "\n")]= '\0';

            if (strcmp(cpfLido, cpfBuscado) == 0){
                excluir = true;
                printf("Paciente encontrado!\nNome: %s\nCPF: %s\nDeletando cadastro...\n", nomeFuncionario, cpfLido);
                funcionarioDeletado = true;
           } 
        }  
       
        if (strncmp(linha, "===============", 15) == 0) {
            dentroBloco = false;
    
        if (!excluir) {
            fputs(blocoFuncionario, temp);
        } 
    }
}   else {
    
    fputs(linha, temp);
}
}
        fclose(arquivo);
        fclose(temp);
        
        remove("funcionario.db");
        rename("temp.db", "funcionario.db");
         
       if (funcionarioDeletado) {
        printf("Cadastro de funcionário deletado com sucesso!\n");
    } else {
        printf("CPF não encontrado. Nenhum cadastro foi deletado.\n");
    }
        
    }
