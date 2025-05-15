#ifndef _CADASTRO_H_INCLUDED_
#define _CADASTRO_H_INCLUDED_

/** Headers com definições necessarias */
#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>

enum Tipo {
    texto,
    numeroInteiro,
    numeroDecimal,  
};

struct Opcoes{
    enum Tipo tipo;
    char* pergunta;
    void* resposta;
    int tamanho;
};

/** Funções */
void CadastraPaciente(void);
void CadastraFuncionario(void);
void ConsultarPaciente(void);
void ConsultarFuncionario(void);
void AtualizarPaciente(void);
void AtualizarFuncionario(void);
void DeletarPaciente(void);
void DeletarFuncionario(void);
void ExibirTodosPacientes(void);
void ExibirTodosFuncionarios(void);


#endif /** !_CADASTRO_H_INCLUED_ */