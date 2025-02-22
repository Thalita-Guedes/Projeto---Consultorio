#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

#include "inc/Cadastro.h"
#include "inc/Paciente.h"

void CadastraPaciente(void)
{
    struct Paciente paciente;

    printf("==========================================================\n");
    printf("== Cadastro de Paciente\n");
    printf("==========================================================\n");
    
    printf("Digite nome:\n");
    scanf("%99s", &paciente.pessoa.nome[0]); // mesma coisa que scanf("%*.s", 100, paciente.pessoa.nome);
    printf("Digite idade:\n");
    scanf("%hhd", &paciente.pessoa.idade);

    /** Salva a esturura Paciente no arquivo 'paciente.db' */

}


void CadastraFunctionario(void)
{
    /** Repetir o processor do Paciente, mas, para functionario e salvar em 'funcionario.db' */
    printf("Opcao selcionada foi 'cadastrar fucionario'\n");
}