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

void AtualizarPaciente(void){
    
    char criterioBusca[50];
    char linha [500];
    char campo[50];
    char novoDado[100];
    char campoComDoisPontos[100];
    bool encontrado = false;
    bool campoEncontrado = false;

    FILE *arquivo = fopen ("paciente.db","r");
    FILE *temp = fopen("temp.db", "w"); 

    struct Opcoes listaOpcoes[]={
    {
    .tipo = texto,
    .pergunta = "Digite o NOME COMPLETO do Paciente que deseja atualizar",
    .resposta = criterioBusca,
    .tamanho = sizeof(criterioBusca)
    },
    {
    .tipo = texto,
    .pergunta = "Escolha um campo para alterar(Nome, Idade, Altura, Peso, RG, CPF, Endereço, Telefone, Email, Gênero, Código Paciente , Primeira Consulta, Possui Convênio, Qual Convênio.)",
    .resposta = campo,
    .tamanho = sizeof(campo)
    },
    {
    .tipo = texto,
    .pergunta = "Digite o novo dado",
    .resposta = novoDado,
    .tamanho = sizeof(novoDado)
    }
};

Menu("Atualizar Paciente", &listaOpcoes[0]);

   while (fgets(linha, sizeof(linha), arquivo)) {
    if (strncasecmp(linha, "Nome:", 5) == 0 && strncasecmp(linha + 6, criterioBusca, strlen(criterioBusca)) == 0) {
    encontrado = true;
    printf ("Paciente encontrado! \n %s", linha);
    fprintf(temp, "%s", linha);

Menu("Campo de Alteração", &listaOpcoes[1]);
Menu("Novo Dado", &listaOpcoes[2]);

    snprintf(campoComDoisPontos, sizeof(campoComDoisPontos), "%s:", campo);

    while (fgets(linha, sizeof(linha), arquivo)) {
      if(strncasecmp(linha,campoComDoisPontos, strlen(campoComDoisPontos))== 0){
        if (strcasecmp(campo, "CPF") == 0 && strlen(novoDado) == 11) {
            fprintf(temp, "CPF: %.3s.%.3s.%.3s-%.2s\n", novoDado, novoDado + 3, novoDado + 6, novoDado + 9);
        }
        else if (strcasecmp(campo, "RG") == 0 && strlen(novoDado) == 8) {
            fprintf(temp, "RG: %.2s.%.3s.%.3s\n", novoDado, novoDado + 2, novoDado + 5);
        }
        else if (strcasecmp(campo, "Peso") == 0) {
            if (!strstr(novoDado, "kg")) {
                fprintf(temp, "Peso: %skg\n", novoDado);
            } else {
                fprintf(temp, "Peso: %s\n", novoDado);
            }
        }
        else if (strcasecmp(campo, "Altura") == 0) {
            if (!strstr(novoDado, "m")) {
                fprintf(temp, "Altura: %sm\n", novoDado);
            } else {
                fprintf(temp, "Altura: %s\n", novoDado);
            }
        }
        else {
            fprintf(temp, "%s: %s\n", campo, novoDado);
                } 
                campoEncontrado = true;
            } else {
                    fprintf(temp, "%s", linha);
                }
            }

            if (!campoEncontrado) {
                printf("Aviso: O campo '%s' não foi encontrado no cadastro!\n", campo);
            }
            break;
        } else {
            fprintf(temp, "%s", linha);
               }
    }
    fclose(arquivo);
    fclose(temp);

    if (!encontrado) {
        printf("Paciente não encontrado!\n");
        remove("temp.db");
    } else {
        printf("Paciente Atualizado com sucesso!\n");
        remove("paciente.db");
        rename("temp.db", "paciente.db");
    }
}


