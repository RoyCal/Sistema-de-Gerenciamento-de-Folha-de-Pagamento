#include "Gerente.h"

Gerente::Gerente() : Funcionario("Gerente"){
    codigo = "vazio";
    nome = "vazio";
    endereco = "vazio";
    telefone = "vazio";
    dataDeIngresso = "vazio";
    salario = 0;
    dataAniversario = "vazio";
}

void Gerente::setDesignacao(){
    designacao = "Gerente";
}

void Gerente::setAreaSupervisao(string str){
    areaDeSupervisao = str;
}

string Gerente::getAreaSupervisao(){
    return areaDeSupervisao;
}