#ifndef _FUNCIONARIO_H_INCLUDED_
#define _FUNCIONARIO_H_INCLUDED_

/** Headers com definições necessarias */
#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include "Pessoa.h"

/** Tipos de dados */

enum Cargo {
    Medico,
    Recepcionista,
    Faxineira,
    Guarda,
};

enum Especialidade {
    ClinicoGeral,
    Ortopedista,
    Cardiologista,
    Pediatra,
    dermatologista,
};

struct Medico {
    char crm[32];
    enum Especialidade especialidade;
};

struct Funcionario {
    struct Pessoa pessoa;
    char codigo[32];
    enum Cargo cargo;
    struct Medico medico; 
};

#endif /** !_FUNCIONARIO_H_INCLUED_ */