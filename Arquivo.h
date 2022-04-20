#define NUMERO_LINHAS 100

#pragma once
#include "Operador.h"
#include "Gerente.h"
#include "Diretor.h"
#include "Presidente.h"
#include <iostream>
#include <fstream>

using namespace std;

class Arquivo{
    public:
        void criaArquivo();

        void imprimeArquivo();

        void scanArquivo();

        void stringToCode(int i);

        void stringToNome(int i);

        void stringToEndereco(int i);

        void stringTotelefone(int i);
        
        void stringToDataIngresso(int i);

        void stringToAreaSupervisao(int i);

        void stringToAreaFormacaoDiretor(int i);

        void stringToAreaFormacaoPresidente(int i);

        void stringToFormacaoAcadMax(int i);

        string getDesignacao(int i);

        void stringToSalario(int i);

        void stringToDataAniversario(int i);

        void atualizaArquivo(string str);

        fstream arquivo;

        string linhas[NUMERO_LINHAS], linhaAux;
};