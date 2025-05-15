#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

#include "../inc/Cadastro.h"
#include "../inc/Paciente.h"
#include "../inc/Funcionario.h"
#include "../inc/Pessoa.h"

#define VERSION_APLICACAO   "1.0"

static int MyGetChar()//limita o uso da funçao MyGetChar a esse arquivo
{
    int myChar = getchar(); // variavel recebe o valor Lido pelo teclado
    getchar(); // Consome o '\n' que fica no buffer
    return myChar; // retorna o caractere lido

    while(true)  //loop que será sempre verdadeiro ate encontrar break
    {
        int key = getchar();// variavel que recebe o valor lido do teclado por getchar
        if (key == '\n')// verifica se o que esta em key é igual a \n
        {
            break;   
        }
        else
        {
            myChar = key; // se o caracter ñ for enter é armazenado em mychar
        }
    }

    return myChar; // retorna o valor de mychar
}

int main (void)
{
    while(true) // loop infinito, sendo interrompido por x
    {
        printf("==================================================\n");
        printf("== Aplicacao Consultorio ==              versao: %s\n", VERSION_APLICACAO);
        printf("==================================================\n");

        printf("Selecione uma opcao:\n");
        printf("  0) Cadastrar paciente\n");
        printf("  1) Cadastrar funcionario\n");
        printf("  2) Consultar paciente\n");
        printf("  3) Consultar funcionario\n");
        printf("  4) Atualizar paciente\n");
        printf("  5) Atualizar funcionario\n");
        printf("  6) Deletar paciente\n");
        printf("  7) Deletar funcionario\n");
        printf("  8) Exibir Todos os cadastros de Paciente\n");
        printf("  9) Exibir Todos os cadastros de funcionario\n");
        printf("  x) Sair\n");

        int opcaoSelecionada = MyGetChar();//chama a funçao myGetChar que lê um único caractere digitado pelo usuário e remove o \n (ENTER).
        printf("Você escolheu a opção: %c\n", opcaoSelecionada);

        switch(opcaoSelecionada){ // verifica a opção digitada pelo usuário e chama a função correspondente
            case '0':
                printf("Opcao selecionada foi 'Cadastrar paciente'\n");
                CadastraPaciente();
                printf("\n Digite c para voltar ao menu...");// Pausa antes de voltar ao menu
                getchar(); // Aguarda o usuário apertar ENTER
                break;
            case '1':
                printf("Opcao selecionada foi 'Cadastrar funcionário'\n");
                CadastraFuncionario();
                printf("\nPressione ENTER para voltar ao menu...");
                getchar();
                break;
            case '2':
                printf("Opcao selecionada foi 'Consultar paciente'\n");
                ConsultarPaciente();
                printf("\nPressione ENTER para voltar ao menu...");
                getchar();
                break;
            case '3':
                printf("Opcao selecionada foi 'Consultar funcionário'\n");
                ConsultarFuncionario();
                printf("\nPressione ENTER para voltar ao menu...");
                getchar();
                break;
            case '4':
                printf("Opcao selecionada foi 'Atualizar paciente'\n");
                AtualizarPaciente();
                printf("\nPressione ENTER para voltar ao menu...");
                getchar();
                break;
            case '5':
                printf("Opcao selecionada foi 'Atualizar funcionário'\n");
                AtualizarFuncionario();
                printf("\nPressione ENTER para voltar ao menu...");
                getchar();
                break;
            case '6':
                printf("Opcao selecionada foi 'Deletar paciente'\n");
                DeletarPaciente();
                printf("\nPressione ENTER para voltar ao menu...");
                getchar();
                break;
            case '7':
                printf("Opcao selecionada foi 'Deletar funcionário'\n");
                DeletarFuncionario();
                printf("\nPressione ENTER para voltar ao menu...");
                getchar();
                break;
            case '8':
                printf("Opcao selecionada foi 'Exibir todos os cadastros de pacientes'\n");
                ExibirTodosPacientes();
                printf("\nPressione ENTER para voltar ao menu...");
                getchar();
                break;
            case '9':
                printf("Opcao selecionada foi 'Exibir todos os cadastros de funcionários'\n");
                ExibirTodosFuncionarios();
                printf("\nPressione ENTER para voltar ao menu...");
                getchar();
                break;
            case 'x':
            case 'X':
                return 0;
            default:
                printf("Opcao invalida\n");
                printf("\nPressione ENTER para voltar ao menu...");
                getchar();
                break;
        }
    }
}