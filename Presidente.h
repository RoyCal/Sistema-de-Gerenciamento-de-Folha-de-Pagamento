#pragma once
#include "Funcionario.h"
#include "Operador.h"
#include "Gerente.h"
#include "Diretor.h"

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

        string presidenteToOperador();

        string presidenteToGerente();

        string presidenteToDiretor();
};