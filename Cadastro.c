#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

#include "../inc/Cadastro.h"
#include "../inc/Paciente.h"
#include "../inc/Funcionario.h"
#include "../inc/Pessoa.h"

void CadastraPaciente(void){

    struct Paciente paciente;
    char buffer[100]; 

    printf("==========================================================\n");
    printf("== Cadastro de Paciente ==\n");
    printf("==========================================================\n");
    
    printf("Digite o nome:\n");
    fgets(paciente.pessoa.nome, sizeof(paciente.pessoa.nome), stdin);
    paciente.pessoa.nome[strcspn(paciente.pessoa.nome, "\n")] = '\0';
    
    printf("Digite a idade:\n");
    fgets(buffer, sizeof(buffer), stdin);
    paciente.pessoa.idade = atoi(buffer);

    printf("Digite a altura:\n");
    fgets(buffer, sizeof(buffer), stdin);
    paciente.pessoa.altura = atof(buffer);

    printf("Digite o peso:\n");
    fgets(buffer, sizeof(buffer), stdin);
    paciente.pessoa.peso = atof(buffer);

    printf("Digite o RG :\n");
    fgets(paciente.pessoa.rg, sizeof(paciente.pessoa.rg), stdin);
    paciente.pessoa.rg[strcspn(paciente.pessoa.rg, "\n")] = '\0';

    printf("Digite o CPF :\n");
    fgets(paciente.pessoa.cpf, sizeof(paciente.pessoa.cpf), stdin);
    paciente.pessoa.cpf[strcspn(paciente.pessoa.cpf, "\n")] = '\0';

    printf("Digite o endereço :\n");
    fgets(paciente.pessoa.endereco, sizeof(paciente.pessoa.endereco), stdin);
    paciente.pessoa.endereco[strcspn(paciente.pessoa.endereco,"\n")] = '\0';

    printf("Digite o telefone :\n");
    fgets(paciente.pessoa.telefone, sizeof(paciente.pessoa.telefone), stdin);
    paciente.pessoa.telefone[strcspn(paciente.pessoa.telefone, "\n")] = '\0';

    printf("Digite o email :\n");
    fgets(paciente.pessoa.email, sizeof(paciente.pessoa.email), stdin);
    paciente.pessoa.email[strcspn(paciente.pessoa.email, "\n")] = '\0';

    printf("Digite o gênero (Escolha 0 para Masculino ou 1 para Feminino):\n");
    fgets(buffer, sizeof(buffer), stdin);
    paciente.pessoa.genero = atoi(buffer);

    printf("Digite o código de paciente:\n");
    fgets(paciente.codigo, sizeof(paciente.codigo), stdin);
    paciente.codigo[strcspn(paciente.codigo, "\n")] = '\0';

    printf("Primeira consulta:(sim/nao)\n");
    fgets(paciente.ehPrimeriaConsulta, sizeof(paciente.ehPrimeriaConsulta), stdin);
    paciente.ehPrimeriaConsulta[strcspn(paciente.ehPrimeriaConsulta, "\n")] = '\0';

    printf("Possui convênio? (Digite 0 para Sim e 1 para Não):\n");
    fgets(buffer, sizeof(buffer), stdin);
    paciente.convenio = atoi(buffer);
   
    printf("Qual o convênio (Escolha 0 para Amil, 1 para Sulamerica, 2 para Bradesco, 3 para Intermédica, 4 para Não Possui):\n");
    fgets(buffer, sizeof(buffer), stdin);
    paciente.planosaude = atoi(buffer);

    FILE *arquivo= fopen ("paciente.db","a");

    fprintf(arquivo,"Nome: %s\n", paciente.pessoa.nome);
    fprintf(arquivo,"Idade:%d\n", paciente.pessoa.idade);
    fprintf(arquivo,"Altura: %f\n", paciente.pessoa.altura);
    fprintf(arquivo,"Peso: %f\n", paciente.pessoa.peso);
    fprintf(arquivo,"RG: %s\n", paciente.pessoa.rg);
    fprintf(arquivo,"CPF: %s\n", paciente.pessoa.cpf);
    fprintf(arquivo,"Endereço: %s\n", paciente.pessoa.endereco);
    fprintf(arquivo,"Telefone: %s\n", paciente.pessoa.telefone);
    fprintf(arquivo,"Email: %s\n", paciente.pessoa.email);
    fprintf(arquivo,"Gênero: %d\n", paciente.pessoa.genero);
    fprintf(arquivo,"Código Paciente: %s\n", paciente.codigo);
    fprintf(arquivo,"Primeira Consulta:(sim/nao) %s\n", paciente.ehPrimeriaConsulta);
    fprintf(arquivo,"Possui Convênio: %d\n", paciente.convenio);
    fprintf(arquivo,"Qual o convênio: %d\n", paciente.planosaude);
    fprintf(arquivo,"===============\n"); 
    fprintf(arquivo, "\n\n");

    fclose(arquivo);
}

void CadastraFuncionario(void){

    struct Funcionario funcionario;
    char buffer[100]; 

    printf("==========================================================\n");
    printf("== Cadastro de Funcionário == \n");
    printf("==========================================================\n");
    
    printf("Digite o nome:\n");
    fgets(funcionario.pessoa.nome, sizeof(funcionario.pessoa.nome), stdin);
    funcionario.pessoa.nome[strcspn(funcionario.pessoa.nome, "\n")] = '\0';
    
    printf("Digite a idade:\n");
    fgets(buffer, sizeof(buffer), stdin);
    funcionario.pessoa.idade = atoi(buffer);

    printf("Digite a altura:\n");
    fgets(buffer, sizeof(buffer), stdin);
    funcionario.pessoa.altura = atof(buffer);

    printf("Digite o peso:\n");
    fgets(buffer, sizeof(buffer), stdin);
    funcionario.pessoa.peso = atof(buffer);

    printf("Digite o RG :\n");
    fgets(funcionario.pessoa.rg, sizeof(funcionario.pessoa.rg), stdin);
    funcionario.pessoa.rg[strcspn(funcionario.pessoa.rg, "\n")] = '\0';

    printf("Digite o CPF :\n");
    fgets(funcionario.pessoa.cpf, sizeof(funcionario.pessoa.cpf), stdin);
    funcionario.pessoa.cpf[strcspn(funcionario.pessoa.cpf, "\n")] = '\0';

    printf("Digite o endereço :\n");
    fgets(funcionario.pessoa.endereco, sizeof(funcionario.pessoa.endereco), stdin);
    funcionario.pessoa.endereco[strcspn(funcionario.pessoa.endereco,"\n")] = '\0';

    printf("Digite o telefone :\n");
    fgets(funcionario.pessoa.telefone, sizeof(funcionario.pessoa.telefone), stdin);
    funcionario.pessoa.telefone[strcspn(funcionario.pessoa.telefone, "\n")] = '\0';

    printf("Digite o email :\n");
    fgets(funcionario.pessoa.email, sizeof(funcionario.pessoa.email), stdin);
    funcionario.pessoa.email[strcspn(funcionario.pessoa.email, "\n")] = '\0';

    printf("Digite o gênero (Escolha 0 para Masculino ou 1 para Feminino):\n");
    fgets(buffer, sizeof(buffer), stdin);
    funcionario.pessoa.genero = atoi(buffer);

    printf("Digite o código de funcionário:\n");
    fgets(funcionario.codigo, sizeof(funcionario.codigo), stdin);
    funcionario.codigo[strcspn(funcionario.codigo, "\n")] = '\0';

    printf("Escolha o cargo:(0 para Médico, 1 para Recepcionista, 2 para Faxineira, 3 para Guarda)\n");
    fgets(buffer, sizeof(buffer), stdin);
    funcionario.cargo = atoi(buffer);

    printf("Digite o CRM:\n");
    fgets(funcionario.medico.crm, sizeof(funcionario.medico.crm), stdin);
    funcionario.medico.crm[strcspn(funcionario.medico.crm, "\n")] = '\0';
   
    printf("Escolha a especialidade (Digite 0 para Clinico Geral, 1 para Ortopedista, 2 para Cardiologista, 3 para Pediatra, 4 para Dermatologista):\n");
    fgets(buffer, sizeof(buffer), stdin);
    funcionario.medico.especialidade = atoi(buffer);

    FILE *arquivo= fopen ("funcionario.db","a");

    fprintf(arquivo,"Nome: %s\n", funcionario.pessoa.nome);
    fprintf(arquivo,"Idade:%d\n", funcionario.pessoa.idade);
    fprintf(arquivo,"Altura: %f\n", funcionario.pessoa.altura);
    fprintf(arquivo,"Peso: %f\n", funcionario.pessoa.peso);
    fprintf(arquivo,"RG: %s\n", funcionario.pessoa.rg);
    fprintf(arquivo,"CPF: %s\n", funcionario.pessoa.cpf);
    fprintf(arquivo,"Endereço: %s\n", funcionario.pessoa.endereco);
    fprintf(arquivo,"Telefone: %s\n", funcionario.pessoa.telefone);
    fprintf(arquivo,"Email: %s\n", funcionario.pessoa.email);
    fprintf(arquivo,"Gênero: %d\n", funcionario.pessoa.genero);
    fprintf(arquivo,"Código Funcionario: %s\n", funcionario.codigo);
    fprintf(arquivo,"Cargo: %d\n", funcionario.cargo);
    fprintf(arquivo,"CRM: %s\n", funcionario.medico.crm);
    fprintf(arquivo,"Qual é a especialidade: %d\n", funcionario.medico.especialidade);
    fprintf(arquivo,"===============\n"); 
    fprintf(arquivo, "\n\n");

    fclose(arquivo);
}

void ConsultarPaciente(void){
    
    printf("==========================================================\n");
    printf("== Consultar Paciente ==\n");
    printf("==========================================================\n");

    FILE *arquivo = fopen ("paciente.db","r");

    char linha[200];
    char criterioBusca[100];
    bool encontrado = false;
    
    printf("Digite o NOME COMPLETO do Paciente que deseja consultar: \n");
    fgets(criterioBusca, sizeof(criterioBusca), stdin);
    criterioBusca [strcspn(criterioBusca, "\n")] = 0;

    printf("\n=== Dados do Paciente ===\n");

    while (fgets(linha, sizeof(linha), arquivo)){

     if((strstr(linha, criterioBusca)!= NULL)){
        encontrado = true;

    do {
        printf("%s", linha);
       }

    while (fgets(linha, sizeof(linha), arquivo) && strstr (linha, "==============") == NULL);
        printf("==============\n");
        break; 
    }
}
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
void AtualizarPaciente(void){

    printf("==========================================================\n");
    printf("== Atualizar  Paciente ==\n");
    printf("==========================================================\n");

    FILE *arquivo = fopen ("paciente.db","r");
    FILE *temp = fopen("temp.db", "w"); 

    char criterioBusca [100];
    char linha [500];
    bool encontrado = false;
    
    printf("Digite o NOME COMPLETO do Paciente que deseja Atualizar:\n");
    fgets(criterioBusca, sizeof(criterioBusca), stdin);
    criterioBusca [strcspn (criterioBusca, "\n")]= 0;
     
    printf("\n=== Buscando Paciente ===\n");

    while (fgets(linha, sizeof(linha), arquivo)){
        if (strstr (linha, criterioBusca)!= NULL){
            encontrado = true;
            printf ("Paciente encontrado! \n %s", linha);
     
            fprintf(temp, "%s", linha);

            printf ("Escolha um campo para alterar (Nome, Idade, Altura, Peso, RG, CPF, Endereço, Telefone, Email, Gênero, Código, Primeira Consulta, Convênio):\n ");
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
            printf("Paciente não encontrado!\n");
            remove ("temp.db");
        } else {
            printf("Paciente Atualizado com sucesso!\n");
            remove("paciente.db");
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

void DeletarPaciente(void){

printf("==========================================================\n");
printf("== Deletar  Paciente ==\n");
printf("==========================================================\n");

FILE *arquivo = fopen ("paciente.db","r");
FILE *temp = fopen("temp.db", "w"); 

char nomeBuscado [100];
char linha [500];
bool excluir = false;
bool dentroBloco = false;

printf("Digite o NOME COMPLETO do Paciente que deseja deletar:\n");
    fgets(nomeBuscado, sizeof(nomeBuscado), stdin);
    nomeBuscado[strcspn(nomeBuscado, "\n")] = 0;  

    printf("\nBuscando paciente: %s\n", nomeBuscado);

    while (fgets(linha, sizeof(linha), arquivo)) { 

        if (strncmp(linha, "Nome:", 5) == 0) {
            dentroBloco = true;
            excluir = false; 
            
        if (strncasecmp(linha + 6, nomeBuscado, strlen(nomeBuscado)) == 0){
            excluir = true;
            printf("Paciente encontrado! Deletando cadastro...\n");
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

    remove("paciente.db");
    rename("temp.db", "paciente.db");

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
