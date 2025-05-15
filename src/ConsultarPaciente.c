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
    printf("\n ======== %s =========\n", titulo);
    printf("%s:\n", (*campo).pergunta);
    fgets((char*)(*campo).resposta, (*campo).tamanho,stdin);
    ((char*)(*campo).resposta)[strcspn((char*)(*campo).resposta, "\n")] = '\0';
    return 0;
}


void ConsultarPaciente(void) {

char nome [50];
char* criterioBusca = nome;
char linha[200];
bool encontrado= false;

FILE *arquivo= fopen("paciente.db", "r");

struct Opcoes listaOpcoes[]={
    {
    .tipo = texto,
    .pergunta = "Digite o NOME COMPLETO do Paciente que deseja consultar",
    .resposta = criterioBusca,
    .tamanho = sizeof(nome)
   }
};

Menu("CONSULTAR PACIENTE", listaOpcoes);

printf("\n=== Dados do Paciente ===\n");

    while (fgets(linha, sizeof(linha), arquivo)){
     if((strncasecmp(linha, "Nome:", 5) == 0 && strncasecmp(linha + 6, criterioBusca, strlen(criterioBusca)) == 0 )){
        encontrado = true;

     do {   
        printf("%s", linha);
        } while (fgets(linha, sizeof(linha), arquivo)&& strstr (linha, "==============") == NULL);
        printf("==============\n");
        break; 
    }
}
        if (!encontrado) {
        printf("Paciente não encontrado! \n");
    }

    fclose(arquivo);

}

