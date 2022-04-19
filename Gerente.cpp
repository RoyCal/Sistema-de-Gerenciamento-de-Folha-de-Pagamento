#include "Gerente.h"

Gerente::Gerente() : Funcionario("Gerente"){

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