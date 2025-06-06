
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

void CadastraPaciente(void){ //função

    struct Paciente paciente; // declaração da variavel do tipo struct
    char buffer[100]; // variavel para armazenar o que é lido do teclado

    printf("==========================================================\n");
    printf("== Cadastro de Paciente ==\n");
    printf("==========================================================\n");
    printf("Aperte o ENTER a qualquer momento para sair do cadastro \n");
    
    printf("Digite o nome:\n");
    // lê o que vem do teclado e armazena na variavel paciente
    fgets(paciente.pessoa.nome, sizeof(paciente.pessoa.nome), stdin);
    
    // verifica na variavel se a primeira posição é enter(\0) se sim entao sai da função e exibe a mensagem
    if (paciente.pessoa.nome[0] == '\n'){ 
        printf("Sair do Cadastro foi solicitado pelo usuário\n");
        return;  
    }
    paciente.pessoa.nome[strcspn(paciente.pessoa.nome, "\n")] = '\0';
      // procura o \n na variavel e o substitui por \0 

    do{
    printf("Digite a idade:\n");
    fgets(buffer, sizeof(buffer), stdin);//lê o que vem do teclado e armazena no buffer

    if (buffer[0] == '\n'){
        printf("Sair do Cadastro foi solicitado pelo usuário \n");
        return;  
    }
    paciente.pessoa.idade = atoi(buffer);// converte atraves do atoi o que vem do teclado em inteiro e armazena em paciente

    if (paciente.pessoa.idade <= 0 || paciente.pessoa.idade > 105){
        printf("Idade inválida. Digite um valor entre 1 e 105 anos. \n");
    }
} while (paciente.pessoa.idade <= 0 || paciente.pessoa.idade > 105);

    printf("Digite a altura:\n");
    fgets(buffer, sizeof(buffer), stdin);

    if (buffer[0] == '\n'){
        printf("Sair do Cadastro foi solicitado pelo usuário \n");
        return;  
     }
    paciente.pessoa.altura = atof(buffer);

    do {    
    printf("Digite o peso:\n");
    fgets(buffer, sizeof(buffer), stdin);

    if (buffer[0] == '\n'){
        printf("Sair do Cadastro foi solicitado pelo usuário \n");
        return;  
    }
    paciente.pessoa.peso = atof(buffer);

    if (paciente.pessoa.peso <= 0 || paciente.pessoa.peso > 350){
        printf("Peso inválido. Digite um valor entre 0 a 350. \n");
    }
} while (paciente.pessoa.peso <= 0 || paciente.pessoa.peso > 350);

    do{
    printf("Digite o RG :\n");
    fgets(paciente.pessoa.rg, sizeof(paciente.pessoa.rg), stdin);

    if (paciente.pessoa.rg[0] == '\n'){
        printf("Sair do Cadastro foi solicitado pelo usuário \n");
        return;  
    }
    paciente.pessoa.rg[strcspn(paciente.pessoa.rg, "\n")] = '\0';

    if (strlen(paciente.pessoa.rg) != 9){
        printf ("RG inválido. O mesmo deve conter 9 dígitos. \n");
    }
} while (strlen (paciente.pessoa.rg) != 9);

    do{
    printf("Digite o CPF :\n");
    fgets(paciente.pessoa.cpf, sizeof(paciente.pessoa.cpf), stdin);

    if (paciente.pessoa.cpf[0] =='\n'){
        printf("Sair do Cadastro foi solicitado pelo usuário \n");
        return;
    }
    paciente.pessoa.cpf[strcspn(paciente.pessoa.cpf, "\n")] = '\0';

    if (strlen(paciente.pessoa.cpf) != 11){
        printf("CPF inválido. O mesmo deve conter 11 dígitos \n");
    }
} while (strlen(paciente.pessoa.cpf) != 11);

    printf("Digite o endereço :\n");
    fgets(paciente.pessoa.endereco, sizeof(paciente.pessoa.endereco), stdin);
    if (paciente.pessoa.endereco[0] == '\n'){
        printf("Sair do Cadastro foi solicitado pelo usuário \n");
        return; 
    }
    paciente.pessoa.endereco[strcspn(paciente.pessoa.endereco,"\n")] = '\0';

    do{
    printf("Digite o telefone (Formato (xx)9xxxxxxxx):\n");
    fgets(paciente.pessoa.telefone, sizeof(paciente.pessoa.telefone), stdin);

    if  (paciente.pessoa.telefone[0] =='\n'){
        printf("Sair do Cadastro foi solicitado pelo usuario \n");
        return;
    }
    paciente.pessoa.telefone[strcspn(paciente.pessoa.telefone, "\n")] = '\0';

    if (strlen(paciente.pessoa.telefone)!= 13 || paciente.pessoa.telefone[0] !='('  || paciente.pessoa.telefone[3] != ')' || paciente.pessoa.telefone[4] != '9') {
        printf("Telefone inválido. Siga o formato (xx)9xxxxxxxx \n");
    }
} while ((strlen(paciente.pessoa.telefone)!= 13 || paciente.pessoa.telefone[0] !='('  || paciente.pessoa.telefone[3] != ')' || paciente.pessoa.telefone[4] != '9'));

    do {
    printf("Digite o email :\n");
    fgets(paciente.pessoa.email, sizeof(paciente.pessoa.email), stdin);

    if  (paciente.pessoa.email[0] =='\n'){
         printf("Sair do Cadastro foi solicitado pelo usuario \n");
         return;
    }
    paciente.pessoa.email[strcspn(paciente.pessoa.email, "\n")] = '\0';

    if (strchr(paciente.pessoa.email, '@')== NULL || strchr(paciente.pessoa.email, '.') ==NULL){
        printf ("Email inválido. O mesmo deve conter '@' e '.' \n");
    }
} while (strchr(paciente.pessoa.email, '@') == NULL || strchr (paciente.pessoa.email, '.') == NULL);

    printf("Digite o gênero(Escolha 0 para Masculino ou 1 para Feminino):\n");
    fgets(buffer, sizeof(buffer), stdin);
    if  (buffer[0] =='\n'){
        printf("Sair do Cadastro foi solicitado pelo usuario \n");
        return;
    }
    paciente.pessoa.genero = atoi(buffer);

    printf("Digite o código de paciente:\n");
    fgets(paciente.codigo, sizeof(paciente.codigo), stdin);
    if   (paciente.codigo[0] =='\n'){
    printf("Sair do Cadastro foi solicitado pelo usuario \n");
        return;
    }
    paciente.codigo[strcspn(paciente.codigo, "\n")] = '\0';

    printf("Primeira consulta? (Digite 0 para sim e 1 para não):\n");
    fgets(paciente.ehPrimeriaConsulta, sizeof(paciente.ehPrimeriaConsulta), stdin);
    if   (paciente.ehPrimeriaConsulta[0] == '\n'){
    printf("Sair do Cadastro foi solicitado pelo usuario \n");
        return;
    }
    paciente.ehPrimeriaConsulta[strcspn(paciente.ehPrimeriaConsulta, "\n")] = '\0';

    printf("Possui convênio? (Digite 0 para Sim e 1 para Não):\n");
    fgets(buffer, sizeof(buffer), stdin);
    if  (buffer[0] =='\n'){
    printf("Sair do Cadastro foi solicitado pelo usuario \n");
        return;
    }
    paciente.convenio = atoi(buffer);
   
    printf("Qual o convênio? (Digite 0 para Amil, 1 para Sulamerica, 2 para Bradesco, 3 para Intermédica, 4 para Não Possui):\n");
    fgets(buffer, sizeof(buffer), stdin);
    if   (buffer[0] == '\n'){
    printf("Sair do Cadastro foi solicitado pelo usuario \n");
        return;
    }    
    paciente.planosaude = atoi(buffer);

    // arquivo que vai guardar os dados que receberam as variaveis 
    FILE *arquivo= fopen ("paciente.db","a");

    fprintf(arquivo,"Nome: %s\n", paciente.pessoa.nome);
    fprintf(arquivo,"Idade:%d\n", paciente.pessoa.idade);
    fprintf(arquivo,"Altura: %.2f\n", paciente.pessoa.altura);
    fprintf(arquivo,"Peso: %.2f\n", paciente.pessoa.peso);

    fprintf(arquivo,"RG: %c%c.%c%c%c.%c%c%c-%c\n", 
    paciente.pessoa.rg[0], 
    paciente.pessoa.rg[1],
    paciente.pessoa.rg[2], 
    paciente.pessoa.rg[3], 
    paciente.pessoa.rg[4],
    paciente.pessoa.rg[5], 
    paciente.pessoa.rg[6], 
    paciente.pessoa.rg[7],
    paciente.pessoa.rg[8]);

    fprintf(arquivo,"CPF:%c%c%c.%c%c%c.%c%c%c-%c%c\n",
    paciente.pessoa.cpf[0], 
    paciente.pessoa.cpf[1], 
    paciente.pessoa.cpf[2],
    paciente.pessoa.cpf[3], 
    paciente.pessoa.cpf[4], 
    paciente.pessoa.cpf[5],
    paciente.pessoa.cpf[6], 
    paciente.pessoa.cpf[7], 
    paciente.pessoa.cpf[8],
    paciente.pessoa.cpf[9], 
    paciente.pessoa.cpf[10]);

    fprintf(arquivo,"Endereço: %s\n", paciente.pessoa.endereco);
    fprintf(arquivo,"Telefone:%s\n", paciente.pessoa.telefone);
    fprintf(arquivo,"Email: %s\n", paciente.pessoa.email);
    fprintf(arquivo,"Gênero (0- Masculino / 1- Feminino): %d\n", paciente.pessoa.genero);
    fprintf(arquivo,"Código Paciente: %s\n", paciente.codigo);
    fprintf(arquivo,"Primeira Consulta (0- sim / 1- não): %s\n", paciente.ehPrimeriaConsulta);
    fprintf(arquivo,"Possui Convênio (0- sim / 1- não): %d\n", paciente.convenio);
    fprintf(arquivo,"Qual o convênio (0- Amil / 1- Sulamerica / 2- Bradesco / 3- Intermédica / 4- Não Possui): %d\n", paciente.planosaude);
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
    printf("Aperte o ENTER a qualquer momento para sair do cadastro \n");
    
    printf("Digite o nome:\n");
    fgets(funcionario.pessoa.nome, sizeof(funcionario.pessoa.nome), stdin);
    if (funcionario.pessoa.nome[0]== '\n'){
        printf("Sair do Cadastro foi solicitado pelo usuario \n");
        return;
    }
    funcionario.pessoa.nome[strcspn(funcionario.pessoa.nome, "\n")] = '\0';
    
    printf("Digite a idade:\n");
    fgets(buffer, sizeof(buffer), stdin);
    if (buffer[0] == '\n') {
        printf("Sair do Cadastro foi solicitado pelo usuario \n");
        return;  
    }
    funcionario.pessoa.idade = atoi(buffer);

    printf("Digite a altura:\n");
    fgets(buffer, sizeof(buffer), stdin);
    if (buffer[0] == '\n') {
        printf("Sair do Cadastro foi solicitado pelo usuario \n");
        return;
    }
    funcionario.pessoa.altura = atof(buffer);

    printf("Digite o peso:\n");
    fgets(buffer, sizeof(buffer), stdin);
    if (buffer[0] == '\n'){
        printf("Sair do Cadastro foi solicitado pelo usuario \n");
        return;
    }
    funcionario.pessoa.peso = atof(buffer);

    printf("Digite o RG :\n");
    fgets(funcionario.pessoa.rg, sizeof(funcionario.pessoa.rg), stdin);
    if (funcionario.pessoa.rg[0] == '\n') {
        printf("Sair do Cadastro foi solicitado pelo usuario \n");
        return;
    }
    funcionario.pessoa.rg[strcspn(funcionario.pessoa.rg, "\n")] = '\0';

    printf("Digite o CPF :\n");
    fgets(funcionario.pessoa.cpf, sizeof(funcionario.pessoa.cpf), stdin);
    if (funcionario.pessoa.cpf[0] == '\n'){
        printf("Sair do Cadastro foi solicitado pelo usuario \n");
        return;
    }
    funcionario.pessoa.cpf[strcspn(funcionario.pessoa.cpf, "\n")] = '\0';

    printf("Digite o endereço :\n");
    fgets(funcionario.pessoa.endereco, sizeof(funcionario.pessoa.endereco), stdin);
    if (funcionario.pessoa.endereco[0] == '\n'){
        printf("Sair do Cadastro foi solicitado pelo usuario \n");
        return;
    }
    funcionario.pessoa.endereco[strcspn(funcionario.pessoa.endereco,"\n")] = '\0';

    printf("Digite o telefone :\n");
    fgets(funcionario.pessoa.telefone, sizeof(funcionario.pessoa.telefone), stdin);
    if (funcionario.pessoa.telefone[0] == '\n'){
        printf("Sair do Cadastro foi solicitado pelo usuario \n");
        return;
    }
    funcionario.pessoa.telefone[strcspn(funcionario.pessoa.telefone, "\n")] = '\0';

    printf("Digite o email :\n");
    fgets(funcionario.pessoa.email, sizeof(funcionario.pessoa.email), stdin);
    if (funcionario.pessoa.email[0] == '\n'){
        printf("Sair do Cadastro foi solicitado pelo usuario \n");
        return;
    }
    funcionario.pessoa.email[strcspn(funcionario.pessoa.email, "\n")] = '\0';

    printf("Digite o gênero (Escolha 0 para Masculino ou 1 para Feminino):\n");
    fgets(buffer, sizeof(buffer), stdin);
    if (buffer[0] == '\n'){
        printf("Sair do Cadastro foi solicitado pelo usuario \n");
        return; 
    }
    funcionario.pessoa.genero = atoi(buffer);

    printf("Digite o código de funcionário:\n");
    fgets(funcionario.codigo, sizeof(funcionario.codigo), stdin);
    if (funcionario.codigo[0] == '\n') {
        printf("Sair do Cadastro foi solicitado pelo usuario \n");
        return;
    }
    funcionario.codigo[strcspn(funcionario.codigo, "\n")] = '\0';

    printf("Escolha o cargo:(0 para Médico, 1 para Recepcionista, 2 para Faxineira, 3 para Guarda)\n");
    fgets(buffer, sizeof(buffer), stdin);
    if (buffer[0] == '\n'){
        printf("Sair do Cadastro foi solicitado pelo usuario \n");
        return;
    }
    funcionario.cargo = atoi(buffer);

    printf("Digite o CRM:\n");
    fgets(funcionario.medico.crm, sizeof(funcionario.medico.crm), stdin);
    if (funcionario.medico.crm[0] == '\n'){
        printf("Sair do Cadastro foi solicitado pelo usuario \n");
        return;
    }
    funcionario.medico.crm[strcspn(funcionario.medico.crm, "\n")] = '\0';
   
    printf("Escolha a especialidade (Digite 0 para Clinico Geral, 1 para Ortopedista, 2 para Cardiologista, 3 para Pediatra, 4 para Dermatologista):\n");
    fgets(buffer, sizeof(buffer), stdin);
    if (buffer[0] == '\n'){
        printf("Sair do Cadastro foi solicitado pelo usuario");
        return;
    }
    funcionario.medico.especialidade = atoi(buffer);

    FILE *arquivo= fopen ("funcionario.db","a");

    fprintf(arquivo,"Nome: %s\n", funcionario.pessoa.nome);
    fprintf(arquivo,"Idade:%d\n", funcionario.pessoa.idade);
    fprintf(arquivo,"Altura: %.2f m\n", funcionario.pessoa.altura);
    fprintf(arquivo,"Peso: %.2f kg\n", funcionario.pessoa.peso);
    fprintf(arquivo,"RG: %s\n", funcionario.pessoa.rg);
    fprintf(arquivo,"CPF: %s\n", funcionario.pessoa.cpf);
    fprintf(arquivo,"Endereço: %s\n", funcionario.pessoa.endereco);
    fprintf(arquivo,"Telefone: %s\n", funcionario.pessoa.telefone);
    fprintf(arquivo,"Email: %s\n", funcionario.pessoa.email);
    fprintf(arquivo,"Gênero (0 Masculino / 1 Feminino): %d\n", funcionario.pessoa.genero);
    fprintf(arquivo,"Código Funcionario: %s\n", funcionario.codigo);
    fprintf(arquivo,"Cargo (0-Médico / 1-Recepcionista / 2-Faxineira / 3-Guarda): %d\n", funcionario.cargo);
    fprintf(arquivo,"CRM: %s\n", funcionario.medico.crm);
    fprintf(arquivo,"Qual é a especialidade(0- Clinico Geral / 1- Ortopedista / 2- Cardiologista / 3- Pediatra / 4- Dermatologista): %d\n", funcionario.medico.especialidade);
    fprintf(arquivo,"===============\n"); 
    fprintf(arquivo, "\n\n");

    fclose(arquivo);
}

#endif