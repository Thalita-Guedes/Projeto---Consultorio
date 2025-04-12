#ifndef _PACIENTE_H_INCLUDED_
#define _PACIENTE_H_INCLUDED_

/** Headers com definições necessarias */
#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include "Pessoa.h"

/** Tipos de dados */

enum Convenio {
    Sim,
    Nao,
};

enum PlanoSaude {
    Amil,
    Sulamerica,
    Bradesco,
    Intermedica,
    NaoPossui,
};

struct Paciente {
    char codigo[32];
    struct Pessoa pessoa;
    char ehPrimeriaConsulta [5];
    enum Convenio convenio;
    enum PlanoSaude planosaude; 
    char nomeConvenio[32];
};

#endif /** !_PACIENTE_H_INCLUED_ */