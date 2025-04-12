#ifndef _PESSOA_H_INCLUDED_
#define _PESSOA_H_INCLUDED_

/** Headers com definições necessarias */
#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>

/** Tipos de dados */

enum Genero {
    Masculino,
    Feminino,
};

struct Pessoa {
    char nome[100];
    int8_t idade;
    float altura;
    float peso;
    char rg[20];
    char cpf[20];
    char endereco[100];
    char telefone[32];
    char email[100];
    enum Genero genero;
};

#endif /** !_PESSOA_H_INCLUDED_ */