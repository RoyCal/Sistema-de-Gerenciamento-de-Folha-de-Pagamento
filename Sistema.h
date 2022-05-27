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
#include <vector>

class Sistema{
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

        void aniversariantes();
};