#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

#include "../inc/Cadastro.h"
#include "../inc/Paciente.h"
#include "../inc/Funcionario.h"
#include "../inc/Pessoa.h"


static int Menu (const char* Titulo, struct Opcoes*ponteiroOpcoes, int numeroPerguntas){

    printf ("==================================\n");
    printf ("=== %s === \n ",Titulo);
    printf ("==================================\n");

    for (int i = 0; i < numeroPerguntas; i++){
        printf("%s:\n", ponteiroOpcoes[i].pergunta);

    switch (ponteiroOpcoes[i].tipo){
    case texto: {
        char* ponteiroResposta = (char*) ponteiroOpcoes[i].resposta;

        do {
            fgets(ponteiroResposta, ponteiroOpcoes[i].tamanho, stdin);
            ponteiroResposta[strcspn(ponteiroResposta,"\n")] = '\0';

            if (strcmp(ponteiroResposta, "c")== 0){
                printf("Cadastro abortado pelo usuário.\n");
                return -1;
             }
            
            if (strcmp(ponteiroOpcoes[i].pergunta, "Digite o RG do funcionário.")==0){
            if (strlen(ponteiroResposta)!= 9 || strspn(ponteiroResposta, "0123456789")!= 9){
                printf("RG Inválido! Deve conter 9 digitos numéricos.\n");
                printf("POr favor, digite novamente o RG do funcionário!\n");
                continue;
            }
        }
            if (strcmp(ponteiroOpcoes[i].pergunta,"Digite o CPF do funcionário" )== 0) { 
            if (strlen(ponteiroResposta)!= 11 || strspn(ponteiroResposta,"0123456789")!= 11){
                printf("CPF Inválido! Deve conter 11 digitos numéricos. \n");
                printf("Por favor, digite novamente o CPF do funcionário!\n");
                continue;
            }
        }
            if (strcmp(ponteiroOpcoes[i].pergunta, "Digite o Telefone no  Formato (xx)9xxxxxxxx")==0){
            if (strlen(ponteiroResposta)!=13 || ponteiroResposta[0]!= '(' || ponteiroResposta[3]!= ')' || ponteiroResposta[4]!= '9'){
                printf("Telefone Inválido! Siga o formato (xx)9xxxxxxxx \n");
                printf("Por favor, digite novamente o telefone do funcionário.\n");
                continue;
            }
        }
            if (strcmp(ponteiroOpcoes[i].pergunta, "Digite o email do funcionário.")== 0){
            if (strstr(ponteiroResposta, "@")== NULL || strstr (ponteiroResposta, ".") == NULL){
                printf("Email Inválido! O mesmo deve conter '@' e '.' \n");
                printf("Por favor, digite novamente o email do funcionário.\n");
                continue;
            }
        }
        break;
        } while (1);
          break;
    }   
     case numeroInteiro: {
        int* ponteiroNumero= (int*)ponteiroOpcoes[i].resposta;
        char buffer[64];

        do {
            fgets(buffer, sizeof(buffer), stdin);
            buffer[strcspn(buffer, "\n")] = '\0';

            if (strcmp(buffer, "c")== 0){
                printf("Cadastro abortado pelo usuário.\n");
                return -1;
            }

            *ponteiroNumero = atoi(buffer);

            if (strcmp(ponteiroOpcoes[i].pergunta, "Digite a idade do funcionário.")== 0){
            if (*ponteiroNumero < 0 || *ponteiroNumero > 105){
                printf("Idade Inválida. A idade deve estar entre 0 e 105 anos. \n");
                printf("Por favor, digite novamente a idade do funcionário.\n");
                continue;
            }
        }
        break;
    } while (1);
      break;
}

    case numeroDecimal:{
        float* ponteiroNumero= (float*) ponteiroOpcoes[i].resposta;
        char buffer [64];

        do {
            fgets(buffer, sizeof(buffer), stdin);
            buffer[strcspn(buffer, "\n")] = '\0';

            if (strcmp(buffer, "c")== 0){
                printf("Cadastro abortado pelo usuário.\n");
                return -1;
            }

               *ponteiroNumero= atof(buffer);

            if (strcmp(ponteiroOpcoes[i].pergunta, "Digite o peso do funcionário")){
            if (*ponteiroNumero < 0 || *ponteiroNumero > 300 ){
                printf("Peso Inválido. O peso deve estar entre 0 e 300");
                printf("Por favor, digite novamente o peso.\n");
                continue;
            }
         }
     
            break;
        } while (1);
            break;
    }  
        default:
        return-1;
}
  }
    }

    void CadastraFuncionario(void) {

        struct Funcionario funcionario;
        
        struct Opcoes listaOpcoes[] = {
         {
         .tipo = texto,
         .pergunta = "Digite o nome do funcionário",
         .resposta = &funcionario.pessoa.nome,
         .tamanho = sizeof(funcionario.pessoa.nome)
        },
        {
         .tipo = numeroInteiro,
         .pergunta = "Digite a idade do funcionário",
         .resposta = &funcionario.pessoa.idade,
         .tamanho = sizeof(funcionario.pessoa.idade)
        },
        {
         .tipo = numeroDecimal,
         .pergunta = "Digite a altura do funcionário no Formato 0.00",
         .resposta = &funcionario.pessoa.altura,
         .tamanho = sizeof(funcionario.pessoa.altura)
        },
        {
         .tipo = numeroDecimal,
         .pergunta = "Digite o peso do funcionário",
         .resposta = &funcionario.pessoa.peso,
         .tamanho = sizeof(funcionario.pessoa.peso)
        },
        {
         .tipo = texto,
         .pergunta = "Digite o RG do funcionário",
         .resposta = &funcionario.pessoa.rg,
         .tamanho = sizeof(funcionario.pessoa.rg)
        },
        {
         .tipo = texto,
         .pergunta = "Digite o CPF do funcionário",
         .resposta = &funcionario.pessoa.cpf,
         .tamanho = sizeof(funcionario.pessoa.cpf)
        },
        {
         .tipo = texto,
         .pergunta = "Digite endereço do funcionário",
         .resposta = &funcionario.pessoa.endereco,
         .tamanho = sizeof(funcionario.pessoa.endereco)
        },
        {
         .tipo = texto,
         .pergunta = "Digite o telefone no Formato (xx)9xxxxxxxx",
         .resposta = &funcionario.pessoa.telefone,
         .tamanho = sizeof(funcionario.pessoa.telefone)
        },
        {
         .tipo = texto,
         .pergunta = "Digite o email do funcionário",
         .resposta = &funcionario.pessoa.email,
         .tamanho = sizeof(funcionario.pessoa.email)
        },
        {
         .tipo = numeroInteiro,
         .pergunta = "Digite o gênero (Escolha 0 para Masculino ou 1 Feminino)",
         .resposta = &funcionario.pessoa.genero,
         .tamanho = sizeof(funcionario.pessoa.genero)
       },
       {
         .tipo = texto,
         .pergunta = "Digite o código do funcionário",
         .resposta = &funcionario.codigo,
         .tamanho = sizeof(funcionario.codigo)
       },
       {
        .tipo = numeroInteiro,
        .pergunta = "Escolha o cargo:(0 = Médico, 1 = Recepcionista, 2 = Faxineira, 3 = Guarda)",
        .resposta = &funcionario.cargo,
        .tamanho = sizeof(funcionario.cargo)
      }
      };

      struct Opcoes listaMedico[] = {
      {
        .tipo = texto,
        .pergunta = "Digite o CRM do médico",
        .resposta = &funcionario.medico.crm,
        .tamanho = sizeof(funcionario.medico.crm)
      },
      {
        .tipo = numeroInteiro,
        .pergunta = "Escolha a especialidade (0 = Clinico Geral, 1 = Ortopedista, 2 = Cardiologista, 3 = Pediatra, 4 = Dermatologista",
        .resposta = &funcionario.medico.especialidade,
        .tamanho = sizeof(funcionario.medico.especialidade)
      }
    };

      if (Menu("Cadastro de Funcionário", listaOpcoes, sizeof(listaOpcoes)/sizeof(listaOpcoes[0])) == -1) {
        printf("Cadastro cancelado.\n");
        return;
      }
       if (funcionario.cargo == 0) {
        if (Menu("Dados do Médico", listaMedico, sizeof(listaMedico)/sizeof(listaMedico[0]))== -1){
          printf("Cadastro cancelado.\n");
          return;
        }
    }
    
    
    FILE *arquivo= fopen ("funcionario.db","a");
    
    fprintf(arquivo,"Nome: %s\n", funcionario.pessoa.nome);
    fprintf(arquivo,"Idade:%danos\n", funcionario.pessoa.idade);
    fprintf(arquivo,"Altura: %.2fm\n", funcionario.pessoa.altura);
    fprintf(arquivo,"Peso: %.2fkg\n", funcionario.pessoa.peso);
    
    fprintf(arquivo,"RG: %c%c.%c%c%c.%c%c%c-%c\n", 
    funcionario.pessoa.rg[0], 
    funcionario.pessoa.rg[1],
    funcionario.pessoa.rg[2], 
    funcionario.pessoa.rg[3], 
    funcionario.pessoa.rg[4],
    funcionario.pessoa.rg[5], 
    funcionario.pessoa.rg[6], 
    funcionario.pessoa.rg[7],
    funcionario.pessoa.rg[8]);
    
    fprintf(arquivo,"CPF:%c%c%c.%c%c%c.%c%c%c-%c%c\n",
    funcionario.pessoa.cpf[0], 
    funcionario.pessoa.cpf[1], 
    funcionario.pessoa.cpf[2],
    funcionario.pessoa.cpf[3], 
    funcionario.pessoa.cpf[4], 
    funcionario.pessoa.cpf[5],
    funcionario.pessoa.cpf[6], 
    funcionario.pessoa.cpf[7], 
    funcionario.pessoa.cpf[8],
    funcionario.pessoa.cpf[9], 
    funcionario.pessoa.cpf[10]);
    
    fprintf(arquivo,"Endereço: %s\n", funcionario.pessoa.endereco);
    fprintf(arquivo,"Telefone:%s\n", funcionario.pessoa.telefone);
    fprintf(arquivo,"Email: %s\n", funcionario.pessoa.email);
    fprintf(arquivo,"Gênero: (0- Masculino / 1- Feminino) %d\n", funcionario.pessoa.genero);
    fprintf(arquivo,"Código Funcionário: %s\n", funcionario.codigo);
    fprintf(arquivo,"Cargo:(0 = Médico, 1 = Recepcionista, 2 = Faxineira, 3 = Guarda) %d\n", funcionario.cargo);

    if (funcionario.cargo == 0) {
    fprintf(arquivo,"CRM: %s\n", funcionario.medico.crm);
    fprintf(arquivo,"Especialidade:(0 = Clinico Geral, 1 = Ortopedista, 2 = Cardiologista, 3 = Pediatra, 4 = Dermatologista) %d\n", funcionario.medico.especialidade);
}

    fprintf(arquivo,"===============\n"); 
    fprintf(arquivo, "\n\n");
    
    fclose(arquivo);
    }


    
       
       
        
   

    