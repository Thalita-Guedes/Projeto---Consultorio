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
    
    char nomeBuscado [100];//variavel que armazena o paciente que sera deletado
    char linha [500];//buffer que armazena o que é lido de arquivo 
    bool excluir = false;//variavel que sinaliza verdade quando o paciente que devera ser deletado é encontrado 
    bool dentroBloco = false;//variavel q indica verdadeiro ao entrar em um bloco de cadastro de um paciente
    
    printf("Digite o NOME COMPLETO do Paciente que deseja deletar:\n");
        //lê do teclado e armazena em nome buscado 
        fgets(nomeBuscado, sizeof(nomeBuscado), stdin);
        //acessa atraves de [] a posição do \n que o strcspn retorna e substitui por\o
        nomeBuscado[strcspn(nomeBuscado, "\n")] = 0;  
    
        printf("\nBuscando paciente: %s\n", nomeBuscado);
    
        //Lê cada linha de arquivo e armazena no buffer linha
        while (fgets(linha, sizeof(linha), arquivo)) { 
    
            // strncmp vai encontrar a palavra Nome em linha retornando ==0 ao encontrar
            if (strncmp(linha, "Nome:", 5) == 0) {
    
                //variavel sinaliza verdadeiro quando é encontrado "nome" em linha significando que esta dentro de um bloco de cadastro
                dentroBloco = true;
    
                // variavel que sinalizara verdadeiro quando for excluir o paciente
                excluir = false; 
    
              //verifica a variavel linha a partir do 6 caractere e nomeBuscado independente de a escrita ser minuscula ou maiuscula, para saber se trata-se do paciente que o usuario deseja deletar se retornar verdadeiro ==0 o nomeBuscado foi encontrado em linha
            if (strncasecmp(linha + 6, nomeBuscado, strlen(nomeBuscado)) == 0){
    
                //e a variavel excluir sinaliza verdadeiro significando que o paciente foi encontrado e deve ser deletado
                excluir = true;
    
                //exibe a informaçao na tela 
                printf("Paciente encontrado! Deletando cadastro...\n");
            }   
        }
    
        if (!excluir) {
            //se excluir for falso significa que aquele não é o paciente que deve ser apagado, ou seja se ñ for para excluir os dados são copiado para temp
            fputs(linha, temp);
        } 
           
        // strncmp busca o separador na variavel linha ao encontrar retorna ==0 (verdadeiro) 
        if (strncmp(linha, "===============", 15) == 0) {
    
            //dentroBloco sinaliza falso indicando que ao encontrar o separador acabou o bloco de paciente 
            dentroBloco = false;
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
    
    char nomeBuscado [100];
    char linha [500];
    bool excluir = false;
    bool dentroBloco = false;
    
    printf("Digite o NOME COMPLETO do Funcionário que deseja deletar:\n");
        fgets(nomeBuscado, sizeof(nomeBuscado), stdin);
        nomeBuscado[strcspn(nomeBuscado, "\n")] = 0;  
    
        printf("\nBuscando funcionário: %s\n", nomeBuscado);
    
        while (fgets(linha, sizeof(linha), arquivo)) { 
    
            if (strncmp(linha, "Nome:", 5) == 0) {
                dentroBloco = true;
                excluir = false; 
                
            if (strstr(linha, nomeBuscado) != NULL) {
                excluir = true;
                printf("Funcionário encontrado! Deletando cadastro...\n");
            }   
        }
    
        if (!excluir) {
            fputs(linha, temp);
        } 
    
        if (strncmp(linha, "===============", 15) == 0) {
            dentroBloco = false;
        } 
    }
        fclose(arquivo);
        fclose(temp);
    
        remove("funcionario.db");
        rename("temp.db", "funcionario.db");
    
        printf("Cadastro de funcionario deletado com sucesso!\n");
        
    }
    