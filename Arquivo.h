#define NUMERO_LINHAS 100

#pragma once
#include <iostream>
#include <fstream>

using namespace std;

class Arquivo{
    public:
        void criaArquivo();

        void imprimeArquivo();

        void scanArquivo();

        void stringToCode(int i);

        void atualizaArquivo(string str);

        fstream arquivo;

        string linhas[NUMERO_LINHAS], linhaAux;
};