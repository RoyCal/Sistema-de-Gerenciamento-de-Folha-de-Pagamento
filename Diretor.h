#pragma once
#include "Funcionario.h"
#include "Operador.h"
#include "Gerente.h"
#include "Presidente.h"

class Diretor : public Funcionario{
    private:
        string areaDeSupervisao;
        string areaDeFormacao;

    public:
        Diretor();

        void setDesignacao();

        void setAreaSupervisao(string str);
        string getAreaSupervisao();
        
        void setAreaDeFormacao(string str);
        string getAreaDeFormacao();

        void getAtributos(string codigo);

        string atributosToString();

        void imprimeRegistro();

        string diretorToOperador();

        string diretorToGerente();

        string diretorToPresidente();

        void aumentaSalario();
};