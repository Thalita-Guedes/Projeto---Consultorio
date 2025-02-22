#ifndef _PACIENTE_H_INCLUED_
#define _PACIENTE_H_INCLUED_

/** Headers com definições necessarias */
#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include "inc/Pessoa.h"

/** Tipos de dados */
struct Paciente {
    char codigo[32];
    struct Pessoa pessoa;
    bool ehPrimeriaConsulta;
};

#endif /** !_PACIENTE_H_INCLUED_ */