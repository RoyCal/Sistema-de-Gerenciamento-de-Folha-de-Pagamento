#pragma once
#include "Funcionario.h"
#include "Gerente.h"
#include "Diretor.h"
#include "Presidente.h"

class Operador : public Funcionario{
    public:
        Operador();

        void setDesignacao();

        void getAtributos(string codigo);

        void imprimeRegistro();

        string operadorToGerente();

        string operadorToDiretor();

        string operadorToPresidente();

        void aumentaSalario();
};