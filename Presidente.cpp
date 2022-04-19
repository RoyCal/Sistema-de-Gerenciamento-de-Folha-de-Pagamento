#include "Presidente.h"

Presidente::Presidente() : Funcionario("Presidente"){
    codigo = "vazio";
    nome = "vazio";
    endereco = "vazio";
    telefone = "vazio";
    dataDeIngresso = "vazio";
    salario = 0;
    dataAniversario = "vazio";
}

void Presidente::setDesignacao(){
    designacao = "Presidente";
}

void Presidente::setAreaDeFormacao(string str){
    areaDeFormacao = str;
}

string Presidente::getAreaDeFormacao(){
    return areaDeFormacao;
}

void Presidente::setFormacaoMaxima(string str){
    formacaoMaxima = str;
}

string Presidente::getFormacaoMaxima(){
    return formacaoMaxima;
}