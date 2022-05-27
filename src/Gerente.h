#pragma once
#include "Funcionario.h"
#include "Operador.h"
#include "Diretor.h"
#include "Presidente.h"

class Gerente : public Funcionario{
    private:
        string areaDeSupervisao;

    public:
        Gerente();

        void setDesignacao();

        void setAreaSupervisao(string str);
        string getAreaSupervisao();

        void getAtributos(string codigo);

        string atributosToString();

        void imprimeRegistro();

        string gerenteToOperador();

        string gerenteToDiretor();

        string gerenteToPresidente();

        void aumentaSalario();
};