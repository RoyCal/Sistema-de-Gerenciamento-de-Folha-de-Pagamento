#pragma once
#include "Funcionario.h"

class Presidente : public Funcionario{
    private:
        string areaDeFormacao;
        string formacaoMaxima;
    public:
        Presidente();

        void setDesignacao();

        void setAreaDeFormacao(string str);
        string getAreaDeFormacao();

        void setFormacaoMaxima(string str);
        string getFormacaoMaxima();

        void getAtributos(string codigo);

        string atributosToString();

        void imprimeRegistro();
};