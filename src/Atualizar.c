#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

#include "../inc/Cadastro.h"
#include "../inc/Paciente.h"
#include "../inc/Funcionario.h"
#include "../inc/Pessoa.h"

void AtualizarPaciente(void){

    printf("==========================================================\n");
    printf("== Atualizar  Paciente ==\n");
    printf("==========================================================\n");

    // o arquivo é aberto em modo leitura
    FILE *arquivo = fopen ("paciente.db","r");
    // um arquivo temporario é aberto para armazenar o cadastro atualizado
    FILE *temp = fopen("temp.db", "w"); 

    char criterioBusca [100];// variavel q recebe o paciente q será atualizado
    char linha [500];//buffer armazenar cada linha lida de arquivo
    bool encontrado = false;//variavel que sinaliza verdade quando o cadastro é encontrado
    
    printf("Digite o NOME COMPLETO do Paciente que deseja Atualizar:\n");
    //lê o que vem do teclado e armazena em criterioBusca
    fgets(criterioBusca, sizeof(criterioBusca), stdin);
    //acessa atraves de [] a posição do \n que o strcspn retorna e substitui por\o
    criterioBusca [strcspn (criterioBusca, "\n")]= 0;
     
    printf("\n=== Buscando Paciente ===\n");
    
    // lê uma linha de cada vez do arquivo 
    while (fgets(linha, sizeof(linha), arquivo)){

        //strsrt verifica as variaveis para encontrar em linha o que esta em criterioBusca  
        if (strstr (linha, criterioBusca)!= NULL){// (!=   significa encontrado)

            //variavel que sinaliza verdade quando o paciente é encontrado no arquivo
            encontrado = true;

            //Exibe na tela o que esta na variavel linha
            printf ("Paciente encontrado! \n %s", linha);
             
            //copia para o arquivo temp o que esta no buffer linha
            fprintf(temp, "%s", linha);
            
            // exibe na tela opçoes disponiveis para alteração
            printf ("Escolha um campo para alterar (Nome, Idade, Altura, Peso, RG, CPF, Endereço, Telefone, Email, Gênero, Código, Primeira Consulta, Convênio):\n ");

            // variavel que armazenara o campo escolhido pelo usuario
            char campo [50];

            // lê do teclado e guarda na variavel campo
            fgets(campo, sizeof(campo), stdin);

            //acessa atraves de [] a posição do \n que o strcspn retorna e substitui por\o
            campo [strcspn(campo,"\n")] = 0;
            
            // variavel que vai armazenar o conteudo de campo adicionando os : na palavra
            char campoComDoisPontos[100];

            //O conteudo da variavel campo vai ser copiado para campoComDoisPontos adicionando atraves do snprintf o : no texto 
            snprintf(campoComDoisPontos, sizeof(campoComDoisPontos), "%s:", campo);

            //variavel que vai armazenar o dado atualizado
            char novoDado [100];

            //exibe na tela a instruçao do que o usuario deve fazer com o campo escolhido
            printf("Digite o novo dado para %s:\n",campo);

            //Lê do teclado e armazena na variavel novoDado
            fgets(novoDado, sizeof(novoDado), stdin);

            //acessa atraves de [] a posição do \n que o strcspn retorna e substitui por\o
            novoDado[strcspn(novoDado,"\n")]=0;

            //variavel que vai sinalizar se o campo foi encontrado em arquivo
            bool campoEncontrado = false;
    
        // lê uma linha de cada vez do arquivo 
    while (fgets(linha, sizeof(linha), arquivo)) {

    //strncasecmp verifica se o conteudo de campoComDoisPontos esta em linha independente da escrita ser maiuscula ou minuscula, se retornar ==0 significa que foi encontrado 
        if (strncasecmp(linha, campoComDoisPontos, strlen(campoComDoisPontos))==0){

            // se ambos os conteudos forem o mesmo, é copiado para o arquivo temp o que esta em novoDado e o que esta em campo
            fprintf(temp, "%s: %s\n", campo, novoDado);

            //variavel que sinaliza se o campo foi encontrado como verdadeiro 
            campoEncontrado = true; 
            
        } else {
            //se campoEncontrado for falso significando que nao foi encontrado o paciente e por isso nao houve alteraçao então o que esta em linha sera copiado para temp
            fprintf(temp, "%s", linha); 
          }
     }
        if (!campoEncontrado) {
            //se campoEncontrado for falso sera exibido na tela essa mensagem
            printf("Aviso: O campo '%s' não foi encontrado no cadastro!\n", campo);
            }
            
        } else {
            fprintf(temp, "%s", linha);
        }
    }
      
    fclose(arquivo);
    fclose (temp);

        if (!encontrado) {
            //Se encontrado for falso exibe na tela essa mensagem
            printf("Paciente não encontrado!\n");
            //temp.db é removido
            remove ("temp.db");
        } else {
            //se encontrado nao for falso, significa que é verdadeiro entao exibe na tela 
            printf("Paciente Atualizado com sucesso!\n");
            //e paciente.db é removido 
            remove("paciente.db");
            // e temp.db é renomeado para paciente.db pois os dados alterados estão armazenados nele.
            rename("temp.db", "paciente.db");
        }
    }    

void AtualizarFuncionario(void){

    printf("==========================================================\n");
    printf("== Atualizar  Funcionário \n");
    printf("==========================================================\n");

    FILE *arquivo = fopen ("funcionario.db","r");
    FILE *temp = fopen("temp.db", "w");

    char criterioBusca [100];
    char linha [500];
    bool encontrado = false;
    
    printf("Digite o NOME COMPLETO do Funcionário que deseja Atualizar:\n");
    fgets(criterioBusca, sizeof(criterioBusca), stdin);
    criterioBusca [strcspn (criterioBusca, "\n")]= 0;
     
    printf("\n=== Buscando Funcionário ===\n");

    while (fgets(linha, sizeof(linha), arquivo)){
        if (strstr (linha, criterioBusca)!= NULL){
            encontrado = true;
            printf ("Funcionário encontrado! \n %s", linha);
     
            fprintf(temp, "%s", linha);

            printf ("Escolha um campo para alterar (Nome, Idade, Altura, Peso, RG, CPF, Endereço, Telefone, Email, Gênero, Código, Cargo, CRM, Especialidade):\n ");
            char campo [50];
            fgets(campo, sizeof(campo), stdin);
            campo [strcspn(campo,"\n")] = 0;

            char campoComDoisPontos[100];
            snprintf(campoComDoisPontos, sizeof(campoComDoisPontos), "%s:", campo);

            char novoDado [100];
            printf("Digite o novo dado para %s:\n",campo);
            fgets(novoDado, sizeof(novoDado), stdin);
            novoDado[strcspn(novoDado,"\n")]=0;

            bool campoEncontrado = false;

    while (fgets(linha, sizeof(linha), arquivo)) {
        if (strncasecmp(linha, campoComDoisPontos, strlen(campoComDoisPontos))==0){
            fprintf(temp, "%s: %s\n", campo, novoDado); 
            campoEncontrado = true; 
        } else {
            fprintf(temp, "%s", linha); 
          }
     }
        
        if (!campoEncontrado) {
            printf("Aviso: O campo '%s' não foi encontrado no cadastro!\n", campo);
            }
            
        } else {
            fprintf(temp, "%s", linha);
        }
    }
      
    fclose(arquivo);
    fclose (temp);

        if (!encontrado) {
            printf("Funcionário não encontrado!\n");
            remove ("temp.db");
        } else {
            printf("Funcionário Atualizado com sucesso!\n");
            remove("funcionario.db");
            rename("temp.db", "funcionario.db");
        }
    }    

