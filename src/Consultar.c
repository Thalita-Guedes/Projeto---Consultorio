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

void ConsultarPaciente(void){
    printf("==========================================================\n");
    printf("== Consultar Paciente ==\n");
    printf("==========================================================\n");
    
    // abre o arquivo 
    FILE *arquivo = fopen ("paciente.db","r");

    char linha[200]; // buffer que armazena cada linha lida do arquivo
    char criterioBusca[100];//variavel que armazena quem o usuario busca
    bool encontrado = false; //variavel que sinaliza verdade quando o cadastro é encontrado
    
    printf("Digite o NOME COMPLETO do Paciente que deseja consultar: \n");
    //lê o que vem do teclado e armazena em criterioBusca
    fgets(criterioBusca, sizeof(criterioBusca), stdin);
    //acessa atraves de [] a posição do \n que o strcspn retorna e substitui por\o
    criterioBusca [strcspn(criterioBusca, "\n")] = 0;

    printf("\n=== Dados do Paciente ===\n");
    
    // lê uma linha de cada vez do arquivo 
    while (fgets(linha, sizeof(linha), arquivo)){ //até que chegue o final do arquivo ou que haja um erro causando a interropção da leitura que tornara a condição falsa, o loop continua.
     
    //strsrt compara as variaveis para encontrar em linha o que esta em criterioBusca  
     if((strstr(linha, criterioBusca)!= NULL)){// (!=   significa encontrado)
        //variavel que sinaliza verdade quando o cadastro é encontrado
        encontrado = true;
    
    // O uso do Do, garante execução ao menos uma vez antes mesmo de testar a condição
    do {
        printf("%s", linha);//mostra o conteudo da variavel linha na tela
       }

    // lê uma linha de cada vez do arquivo e guarda na buffer verificando se a linha atual contém o separador enquanto essa condição é verdadeira o loop continua, quando encontra strstr retorna NULL e o laço para
    while (fgets(linha, sizeof(linha), arquivo) && strstr (linha, "==============") == NULL);
        printf("==============\n");
        break; 
    }
}

    // Se encontrado for falso então a mensagem aparece na tela
    if (!encontrado) {
    printf("Paciente não encontrado!\n");
}

fclose(arquivo);
}
  
void ConsultarFuncionario(void){

    printf("==========================================================\n");
    printf("== Consultar Funcionário ==\n");
    printf("==========================================================\n");

    FILE *arquivo = fopen ("funcionario.db","r");

    char linha[200];
    char criterioBusca[100];
    bool encontrado = false;
    
    printf("Digite o NOME COMPLETO do funcionário que deseja consultar: \n");
    fgets(criterioBusca, sizeof(criterioBusca), stdin);
    criterioBusca [strcspn(criterioBusca, "\n")] = 0;

    printf("\n=== Dados do Funcionário ===\n");

    while (fgets(linha, sizeof(linha), arquivo)){

     if((strstr(linha, criterioBusca)!= NULL)){
        encontrado = true;

     do {   
        printf("%s", linha);
        }

    while (fgets(linha, sizeof(linha), arquivo)&& strstr (linha, "==============") == NULL);
        printf("==============\n");
        break; 
    }
}
        if (!encontrado) {
        printf("Funcionário não encontrado! \n");
    }

    fclose(arquivo);

}
#endif