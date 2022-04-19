#pragma once
#include "Funcionario.h"

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
};