#pragma once

#include "Funcionario.h"
#include "Operador.h"
#include "Gerente.h"
#include "Diretor.h"
#include "Presidente.h"
#include "Arquivo.h"
#include <iostream>
#include <fstream>
#include <string>

class Sistema{
    private:
        int i, j, k, l, m, escolha, escolha1, count, count2, count3;
        int flag = 0;
        float somaSalarios;

        string numero, designacao, strAux1, strAux2, mes, nome, dataHoje;

        Funcionario *funcionario;

        Operador operador;
        Gerente gerente;
        Diretor diretor;
        Presidente presidente;

        Arquivo arquivo;

    public:
        void rodarSistema(bool x);

        void imprimeMenuPrincipal();

        bool verificaIntervaloDatas(string data1, string data2, string dataRef);

        void adicionarFuncionario();

        void editarAtributo();

        void excluirRegistro();

        void exibirRegistro();

        void listaDeFuncionarios();

        void concederAumento();

        void calcularFolhaSalarial();

        void consultarFolhaFuncionario();

        void consultarFolhaEmpresa();

        void limparRegistroDasFolhas();

        void buscarFuncionario();

        void finalizarSistema();

        void switchMeses();

        bool menuLogin();
};