#ifndef _FUNCIONARIO_H_INCLUED_
#define _FUNCIONARIO_H_INCLUED_

/** Headers com definições necessarias */
#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include "inc/Pessoa.h"

/** Tipos de dados */
struct Funcionario {
    struct Pessoa pessoa;
    char codigo[32];
};

enum Especialidade {
    ClinicoGeral,
    Ordopedista,
};

struct Medico {
    struct Funcionario funcionario;
    char crm[32];
    enum Especialidade especialidade;
};

struct Recepcionista {
    struct Funcionario funcionario;
};

#endif /** !_FUNCIONARIO_H_INCLUED_ */