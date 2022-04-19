#include "Presidente.h"

Presidente::Presidente() : Funcionario("Presidente"){

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