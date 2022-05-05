#define MAXIMO_HORA_EXTRA 8
#define MAXIMO_DIAS_TRABALHADOS 22

#pragma once
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>

using namespace std;

class Funcionario{
    protected:
        string codigo;
        string nome;
        string endereco;
        string telefone;
        string dataDeIngresso;
        string designacao;
        float salario;
        string dataAniversario;
        float salarioLiquido;

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

        float getSalarioLiquido();

        string CEPtoEndereco(string CEP); //mudar classe

        virtual void getAtributos(string codigo) = 0;

        virtual string atributosToString();

        virtual void imprimeRegistro() = 0;

        virtual void aumentaSalario() = 0;

        bool verificaValidadeData(string str); //mudar classe

        bool verificaValidadeDataAniversario(string str); //mudar classe

        bool verificaAnoBisexto(int ano); //mudar classe

        string calculaFolhaSalarial(int i);

        bool verificaIntervaloDatas(string data1, string data2, string dataRef); //mudar classe
};