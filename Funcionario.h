#pragma once
#include <iostream>
#include <fstream>

using namespace std;

class Funcionario{
    protected:
        string codigo;
        string nome;
        string endereco;
        string telefone;
        string dataDeIngresso;
        string designacao;
        double salario;
        string dataAniversario;

    public:
        Funcionario(string designacao);

        void setCodigo(string str);
        string getCodigo();

        void setNome(string str);
        string getNome();

        void setEndereco(string str);
        string getEndereco();

        void setTelefone(string str);
        string getTelefone();

        void setDataDeIngresso(string str);
        string getDataDeIngresso();

        virtual void setDesignacao() = 0;
        string getDesignacao();

        void setSalario(float x);
        float getSalario();

        void setDataAniversario(string str);
        string getDataAniversario();

        string CEPtoEndereco(string CEP);

        virtual void getAtributos(string codigo) = 0;

        virtual string atributosToString();
};