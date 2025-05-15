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

void DeletarPaciente(void){

    printf("==========================================================\n");
    printf("== Deletar  Paciente ==\n");
    printf("==========================================================\n");
    
    //arquivo aberto em modo leitura
    FILE *arquivo = fopen ("paciente.db","r");
    //arquivo temporario que armazena o cadastro atualizado
    FILE *temp = fopen("temp.db", "w"); 
    
    char cpfBuscado [20];//variavel que armazena o paciente que sera deletado
    char linha [500];//buffer que armazena o que é lido de arquivo 
    bool excluir = false;//variavel que sinaliza verdade quando o paciente que devera ser deletado é encontrado 
    bool dentroBloco = false;//variavel q indica verdadeiro ao entrar em um bloco de cadastro de um paciente
    char blocoPaciente[400] = "\0";
    
    printf("Digite o CPF do Paciente que deseja deletar:\n");
        //lê do teclado e armazena em  cpfbuscado 
        fgets(cpfBuscado, sizeof(cpfBuscado), stdin);
        //acessa atraves de [] a posição do \n que o strcspn retorna e substitui por\o
        cpfBuscado[strcspn(cpfBuscado, "\n")] = 0;  
    
        printf("\nBuscando paciente: %s\n", cpfBuscado);
    
        //Lê cada linha de arquivo e armazena no buffer linha
        while (fgets(linha, sizeof(linha), arquivo)) { 
    
            // strncmp vai encontrar a palavra CPF em linha retornando ==0 ao encontrar
            if (strncmp(linha, "Nome:", 5) == 0) {
    
                //variavel sinaliza verdadeiro quando é encontrado "Nome" em linha significando que esta dentro de um bloco de cadastro
                dentroBloco = true;
    
                // variavel que sinalizara verdadeiro quando for excluir o paciente
                excluir = false; 

                blocoPaciente[0] = '\0';
            }

            if (dentroBloco){
               strcat(blocoPaciente, linha);
              //verifica a variavel linha a partir do 5 caractere e cpfBuscado, para saber se trata-se do paciente que o usuario deseja deletar se retornar verdadeiro ==0 o nomeBuscado foi encontrado em linha
            if (strncmp(linha, "CPF:", 4) == 0){
                if (strncmp(linha + 5, cpfBuscado, strlen(cpfBuscado)) == 0){
                    excluir = true;
                //exibe a informaçao na tela 
                printf("Paciente encontrado! Deletando cadastro...\n");
           } 
        }  
        // strncmp busca o separador na variavel linha ao encontrar retorna ==0 (verdadeiro) 
        if (strncmp(linha, "===============", 15) == 0) {
            dentroBloco = false;
    
        if (!excluir) {
            //se excluir for falso significa que aquele não é o paciente que deve ser apagado, ou seja se ñ for para excluir os dados são copiado para temp
            fputs(blocoPaciente, temp);
        } 
    }
}   else {
    // Para fora de blocos (ex: antes do primeiro "Nome:"), grava direto
    fputs(linha, temp);
}
}
        fclose(arquivo);
        fclose(temp);
        
        remove("paciente.db");// remove paciente.db
        rename("temp.db", "paciente.db");// renomeia temp que possui o campo alterado para paciente.db
    
        //exibe na tela a mensagem 
        printf("Cadastro de paciente deletado com sucesso!\n");
        
    }
 
    
    void DeletarFuncionario(void){
    printf("==========================================================\n");
    printf("== Deletar  Funcionário ==\n");
    printf("==========================================================\n");
    
    
    FILE *arquivo = fopen ("funcionario.db","r");
    FILE *temp = fopen("temp.db", "w"); 
    
    char cpfBuscado [20];
    char linha [500];
    bool excluir = false; 
    bool dentroBloco = false;
    char blocoFuncionario[400] = "\0";
    
    printf("Digite o CPF do Funcionário que deseja deletar:\n");
        fgets(cpfBuscado, sizeof(cpfBuscado), stdin);
        cpfBuscado[strcspn(cpfBuscado, "\n")] = 0;  
    
        printf("\nBuscando Funcionário: %s\n", cpfBuscado);
    
        
        while (fgets(linha, sizeof(linha), arquivo)) { 
            if (strncmp(linha, "Nome:", 5) == 0) {
                dentroBloco = true;
                excluir = false; 
                blocoFuncionario[0] = '\0';
            }

            if (dentroBloco){
               strcat(blocoFuncionario, linha);

            if (strncmp(linha, "CPF:", 4) == 0){
                if (strncmp(linha + 5, cpfBuscado, strlen(cpfBuscado)) == 0){
                    excluir = true;
                    printf("Funcionário encontrado! Deletando cadastro...\n");
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
        printf("Cadastro de funcionário deletado com sucesso!\n");
        
    }
    # endif