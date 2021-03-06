#define NUMERO_LINHAS 200

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
        string linhas[NUMERO_LINHAS], linhaAux;

        fstream arquivo;

        void criaArquivo();

        void imprimeArquivo();

        void scanArquivo();

        void percorrerString(int i, int cont);

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

        string verificaCodigoRepetido();

        string completaNumero(string numero);

        void substituiLinha(string novaLinha, string numero);

        void substituiArquivo();

        Gerente stringToGerente(int i);

        Operador stringToOperador(int i);

        Diretor stringToDiretor(int i);

        Presidente stringToPresidente(int i);

        bool verificaCalculoFolha(string str);

        void limpaFolhas();

        void imprimeFolhaFuncionario(int i);
};