#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

#include "inc/Cadastro.h"

#define VERSION_APLICACAO   "1.0"

static int MyGetChar()
{
    int myChar = -1;

    while(true)
    {
        int key = getchar();
        if (key == '\n')
        {
            break;
        }
        else
        {
            myChar = key;
        }
    }

    return myChar;
}

int main (void)
{
    while(true)
    {
        printf("==================================================\n");
        printf("== Aplicacao Consultorio               versao: %s\n", VERSION_APLICACAO);
        printf("==================================================\n");

        printf("Selecione uma opcao:\n");
        printf("  1) Cadastrar paciente\n");
        printf("  2) Cadastrar functionario\n");
        printf("  3) Consultar paciente\n");
        printf("  4) Consultar funcionario\n");
        printf("  5) Atualiza paciente\n");
        printf("  6) Atualiza funcionario\n");
        printf("  7) Deletar paciente\n");
        printf("  8) Deletar funcionario\n");
        printf("  x) Sair\n");

        int opcaoSelecionada = MyGetChar();
        switch(opcaoSelecionada){
            case '1':
                CadastraPaciente();
                break;
            case '2':
                CadastraFunctionario();
                break;
            case '3':
                printf("Opcao selcionada foi 'Consultar paciente'\n");
                break;
            case '4':
                printf("Opcao selcionada foi 'Consultar functionario'\n");
                break;
            case '5':
                printf("Opcao selcionada foi 'Atualizar paciente'\n");
                break;
            case '6':
                printf("Opcao selcionada foi 'Atualizar paciente'\n");
                break;
            case '7':
                printf("Opcao selcionada foi 'Deletar paciente'\n");
                break;
            case '8':
                printf("Opcao selcionada foi 'Deletar functionario'\n");
                break;
            case 'x':
            case 'X':
                return 0;
            default:
                printf("Opcao invalida\n");
                break;
        }
    }
}