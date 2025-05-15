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

void DeletarPaciente(void){

char cpfBuscado [20];
char linha [500];
char cpfLido[25];
bool excluir = false;
bool pacienteDeletado = false;
bool dentroBloco = false;
char blocoPaciente[400] = "\0";
char nomePaciente[50]="";

 FILE *arquivo = fopen ("paciente.db","r");
 FILE *temp = fopen("temp.db", "w"); 

struct Opcoes listaOpcoes[]={
    {
    .tipo = texto,
    .pergunta = "Digite o CPF do Paciente que deseja consultar",
    .resposta = cpfBuscado,
    .tamanho = sizeof(cpfBuscado)
    },
};

Menu("Deletar Paciente", listaOpcoes);

       while (fgets(linha, sizeof(linha), arquivo)) {

            if (strncmp(linha, "Nome:", 5) == 0) {
                dentroBloco = true;
                excluir = false; 
                blocoPaciente[0] = '\0';

                strncpy(nomePaciente, linha + 6, sizeof(nomePaciente));
                nomePaciente[strcspn(nomePaciente, "\n")] = '\0';
            }

            if (dentroBloco){
               strcat(blocoPaciente, linha);

            if (strncmp(linha, "CPF:", 4) == 0){
                strncpy(cpfLido,linha + 4, sizeof(cpfLido));
                cpfLido[strcspn(cpfLido, "\n")]= '\0';


                if (strcmp(cpfLido, cpfBuscado) == 0){
                    excluir = true;
                    printf("Paciente encontrado!\nNome: %s\nCPF: %s\nDeletando cadastro...\n", nomePaciente, cpfLido);
                    pacienteDeletado = true;
           } 
        }  
       
        if (strncmp(linha, "===============", 15) == 0) {
            dentroBloco = false;
    
        if (!excluir) {
            fputs(blocoPaciente, temp);
        } 
    }
}   else {
    
    fputs(linha, temp);
}
}
        fclose(arquivo);
        fclose(temp);
        
        remove("paciente.db");
        rename("temp.db", "paciente.db");
         
        if (pacienteDeletado) {
        printf("Cadastro de paciente deletado com sucesso!\n");
    } else {
        printf("CPF não encontrado. Nenhum cadastro foi deletado.\n");
    }
}
        
    









