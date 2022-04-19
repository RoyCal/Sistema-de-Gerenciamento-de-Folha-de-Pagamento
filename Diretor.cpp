#include "Diretor.h"

Diretor::Diretor() : Funcionario("Diretor"){

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