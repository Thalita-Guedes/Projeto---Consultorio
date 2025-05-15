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

    for (int i = 0; i< numeroPerguntas; i++){
        printf ("%s:\n", ponteiroOpcoes[i].pergunta);

    switch (ponteiroOpcoes[i].tipo){
        case texto:{
            char* ponteiroResposta = (char*) ponteiroOpcoes[i].resposta;
            
            do {
                fgets (ponteiroResposta,ponteiroOpcoes[i].tamanho, stdin);
                ponteiroResposta[strcspn(ponteiroResposta, "\n")] = '\0';

                if (strcmp(ponteiroResposta, "c") == 0) {
                    printf("Cadastro abortado pelo usuário.\n");
                    return -1; 
                }
                

            if (strcmp (ponteiroOpcoes[i].pergunta, "Digite o RG do paciente") == 0){
            if (strlen(ponteiroResposta)!= 9 || strspn(ponteiroResposta, "0123456789")!= 9){
                printf("RG inválido! Deve conter exatamente 9 dígitos numéricos.\n");
                printf("Por favor digite novamente o RG do paciente.\n");
                continue;
          }
    } 
           if (strcmp(ponteiroOpcoes[i].pergunta, "Digite o CPF do paciente") == 0) { 
            if (strlen(ponteiroResposta) != 11 || strspn(ponteiroResposta, "0123456789") != 11) {
            printf("CPF inválido! Deve conter exatamente 11 dígitos numéricos.\n"); 
            printf("Por favor digite novamente o CPF do paciente.\n");
            continue;
        }
    } 
           if (strcmp(ponteiroOpcoes[i].pergunta, "Digite o telefone no Formato (xx)9xxxxxxxx") == 0) {
            if(strlen(ponteiroResposta)!= 13 || ponteiroResposta[0]!='('  || ponteiroResposta[3] != ')' || ponteiroResposta[4] != '9') {
            printf("Telefone inválido. Siga o formato (xx)9xxxxxxxx \n");
            printf("Por favor digite novamente o Telefone do paciente.\n");
            continue;
         }
     }
            if (strcmp(ponteiroOpcoes[i].pergunta, "Digite o email do paciente") == 0) { 
             if (strchr(ponteiroResposta, '@')== NULL || strchr(ponteiroResposta, '.') ==NULL){
                printf ("Email inválido. O mesmo deve conter '@' e '.' \n");
                printf("Por favor digite novamente o email do paciente.\n");
                continue;
      }
    }
      break;
} while (1);
      break;
 }           
    
        case numeroInteiro:{
        
            int* ponteiroNumero = (int*) ponteiroOpcoes[i].resposta;
            char buffer[64];
            do{
                fgets (buffer, sizeof(buffer), stdin);
                buffer[strcspn(buffer, "\n")] = '\0';
                
                if (strcmp(buffer, "c") == 0) {
                    printf("Cadastro abortado pelo usuário.\n");
                    return -1; // Interrompe a execução do Menu
                }

                *ponteiroNumero = atoi(buffer);

            if (strcmp(ponteiroOpcoes[i].pergunta, "Digite a idade do paciente") == 0) {
             if (*ponteiroNumero < 0 || *ponteiroNumero > 105 ) {
                printf ("Idade inválida! A idade deve estar entre 0 e 105 anos. \n ");
                printf("Por favor, digite novamente a idade do paciente.\n"); 
                continue;
             }
        } 
        break;   
       } while (1);
       break;   
}          

        case numeroDecimal:{
        float* ponteiroNumero = (float*) ponteiroOpcoes[i].resposta;
               char buffer[64];
               do {
                fgets (buffer, sizeof(buffer), stdin);
                buffer[strcspn(buffer, "\n")] = '\0';

                if (strcmp(buffer, "c") == 0) {
                    printf("Cadastro abortado pelo usuário.\n");
                    return -1; // Interrompe a execução do Menu
                }

                *ponteiroNumero = atof(buffer);  
                
            if (strcmp (ponteiroOpcoes[i].pergunta, "Digite a altura do paciente") == 0){
                if (*ponteiroNumero < 0 || *ponteiroNumero > 2.5){
                    printf("Tamanho inválido! o Tamanho deve estar entre 0 e 2.5 metros.\n");
                    printf("Por favor digite novamente o Tamanho do paciente.\n");
                    continue;
                }
            }

           if (strcmp (ponteiroOpcoes[i].pergunta, "Digite o peso do paciente") == 0) {
            if (*ponteiroNumero < 0 || *ponteiroNumero > 300){
                printf("Peso inválido!O peso deve estar entre 0 e 300 kg.");
                printf("Por favor digite novamente o peso do paciente.\n");
                continue;
            }
        }

        break;
    } while(1);
        break;
    }
        default:
        return -1; 
}  
  }
    }
    

void CadastraPaciente(void) {

   struct Paciente paciente;
   
   struct Opcoes listaOpcoes[] = {
    {
    .tipo = texto,
    .pergunta = "Digite o nome do paciente",
    .resposta = &paciente.pessoa.nome,
    .tamanho = sizeof(paciente.pessoa.nome)
   },
   {
    .tipo = numeroInteiro,
    .pergunta = "Digite a idade do paciente",
    .resposta = &paciente.pessoa.idade,
    .tamanho = sizeof(paciente.pessoa.idade)
   },
   {
    .tipo = numeroDecimal,
    .pergunta = "Digite a altura do paciente no Formato 0.00",
    .resposta = &paciente.pessoa.altura,
    .tamanho = sizeof(paciente.pessoa.altura)
   },
   {
    .tipo = numeroDecimal,
    .pergunta = "Digite o peso do paciente",
    .resposta = &paciente.pessoa.peso,
    .tamanho = sizeof(paciente.pessoa.peso)
   },
   {
    .tipo = texto,
    .pergunta = "Digite o RG do paciente",
    .resposta = &paciente.pessoa.rg,
    .tamanho = sizeof(paciente.pessoa.rg)
   },
   {
    .tipo = texto,
    .pergunta = "Digite o CPF do paciente",
    .resposta = &paciente.pessoa.cpf,
    .tamanho = sizeof(paciente.pessoa.cpf)
   },
   {
    .tipo = texto,
    .pergunta = "Digite endereço do paciente",
    .resposta = &paciente.pessoa.endereco,
    .tamanho = sizeof(paciente.pessoa.endereco)
   },
   {
    .tipo = texto,
    .pergunta = "Digite o telefone no Formato (xx)9xxxxxxxx",
    .resposta = &paciente.pessoa.telefone,
    .tamanho = sizeof(paciente.pessoa.telefone)
   },
   {
    .tipo = texto,
    .pergunta = "Digite o email do paciente",
    .resposta = &paciente.pessoa.email,
    .tamanho = sizeof(paciente.pessoa.email)
   },
   {
    .tipo = numeroInteiro,
    .pergunta = "Digite o gênero (Escolha 0 para Masculino ou 1 Feminino)",
    .resposta = &paciente.pessoa.genero,
    .tamanho = sizeof(paciente.pessoa.genero)
  },
  {
    .tipo = texto,
    .pergunta = "Digite o código do paciente",
    .resposta = &paciente.codigo,
    .tamanho = sizeof(paciente.codigo)
  },
  {
    .tipo = texto,
    .pergunta = "Primeira consulta? (Digite 0 para sim e 1 para não)",
    .resposta = &paciente.ehPrimeriaConsulta,
    .tamanho = sizeof(paciente.ehPrimeriaConsulta)
   },
   {
    .tipo = numeroInteiro,
    .pergunta = "Possui convênio? (Digite 0 para sim e 1 para não)",
    .resposta = &paciente.convenio,
    .tamanho = sizeof(paciente.convenio)
   },
   {
    .tipo = numeroInteiro,
    .pergunta = "Qual o convênio? (Digite 0 para Amil, 1 para Sulamerica, 2 para Bradesco, 3 para Intermédica, 4 para Não Possui)",
    .resposta = &paciente.planosaude,
    .tamanho = sizeof(paciente.planosaude)
   },
};

   if (Menu("Cadastro de Paciente", listaOpcoes, sizeof(listaOpcoes)/sizeof(listaOpcoes[0])) == -1) {
    printf("Cadastro cancelado.\n");
    return;
  }


FILE *arquivo= fopen ("paciente.db","a");

fprintf(arquivo,"Nome: %s\n", paciente.pessoa.nome);
fprintf(arquivo,"Idade:%danos\n", paciente.pessoa.idade);
fprintf(arquivo,"Altura: %.2fm\n", paciente.pessoa.altura);
fprintf(arquivo,"Peso: %.2fkg\n", paciente.pessoa.peso);

fprintf(arquivo,"RG:%c%c.%c%c%c.%c%c%c-%c\n", 
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
fprintf(arquivo,"Gênero: (0- Masculino / 1- Feminino) %d\n", paciente.pessoa.genero);
fprintf(arquivo,"Código Paciente: %s\n", paciente.codigo);
fprintf(arquivo,"Primeira Consulta: (0- sim / 1- não) %s\n", paciente.ehPrimeriaConsulta);
fprintf(arquivo,"Possui Convênio: (0- sim / 1- não) %d\n", paciente.convenio);
fprintf(arquivo,"Qual convênio:(0- Amil/ 1- Sulamerica/ 2- Bradesco/ 3- Intermédica/ 4- Não Possui) %d\n", paciente.planosaude);
fprintf(arquivo,"===============\n"); 
fprintf(arquivo, "\n\n");

fclose(arquivo);
}


   