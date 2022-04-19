#include "Diretor.h"

Diretor::Diretor() : Funcionario("Diretor"){
    codigo = "vazio";
    nome = "vazio";
    endereco = "vazio";
    telefone = "vazio";
    dataDeIngresso = "vazio";
    salario = 0;
    dataAniversario = "vazio";
}

void Diretor::setDesignacao(){
    designacao = "Diretor";
}

void Diretor::setAreaSupervisao(string str){
    areaDeSupervisao = str;
}

string Diretor::getAreaSupervisao(){
    return areaDeSupervisao;
}

void Diretor::setAreaDeFormacao(string str){
    areaDeFormacao = str;
}

string Diretor::getAreaDeFormacao(){
    return areaDeFormacao;
}