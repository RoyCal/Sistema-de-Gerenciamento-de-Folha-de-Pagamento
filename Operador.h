#pragma once
#include "Funcionario.h"

class Operador : public Funcionario{
    public:
        Operador();

        void setDesignacao();

        void getAtributos(string codigo);
};