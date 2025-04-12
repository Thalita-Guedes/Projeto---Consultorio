#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

#include "../inc/Cadastro.h"
#include "../inc/Paciente.h"
#include "../inc/Funcionario.h"
#include "../inc/Pessoa.h"

void CadastraPaciente(void){ //função

    struct Paciente paciente; // declaração da variavel do tipo struct
    char buffer[100]; // variavel para armazenar o que é lido do teclado

    printf("==========================================================\n");
    printf("== Cadastro de Paciente ==\n");
    printf("==========================================================\n");
    
    printf("Digite o nome:\n");
    // lê o que vem do teclado e armazena na variavel paciente
    fgets(paciente.pessoa.nome, sizeof(paciente.pessoa.nome), stdin);
    // procura o \n na variavel e o substitui por \o
    paciente.pessoa.nome[strcspn(paciente.pessoa.nome, "\n")] = '\0';
    
    printf("Digite a idade:\n");
    //lê o que vem do teclado e armazena no buffer
    fgets(buffer, sizeof(buffer), stdin);
    // converte atraves do atoi o que vem do teclado em inteiro e armazena em paciente
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

    // arquivo que vai guardar os dados que receberam as variaveis 
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
