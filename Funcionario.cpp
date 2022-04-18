#include "Funcionario.h"

Funcionario::Funcionario(string designacao){
    this->designacao = designacao;
}

void Funcionario::setCodigo(string str){
    codigo = str;
}

string Funcionario::getCodigo(){
    return codigo;
}

void Funcionario::setEndereco(string str){
    endereco = str;
}

string Funcionario::getEndereco(){
    return endereco;
}

void Funcionario::setTelefone(string str){
    telefone = str;
}

string Funcionario::getTelefone(){
    return telefone;
}

string Funcionario::getDesignacao(){
    return designacao;
}

void Funcionario::setSalario(float x){
    salario = x;
}

float Funcionario::getSalario(){
    return salario;
}

void Funcionario::setNome(string str){
    nome = str;
}

void Funcionario::setDataDeIngresso(string str){
    dataDeIngresso = str;
}

void Funcionario::setDataAniversario(string str){
    dataAniversario = str;
}

string Funcionario::getNome(){
    return nome;
}

string Funcionario::getDataDeIngresso(){
    return dataDeIngresso;
}

string Funcionario::getDataAniversario(){
    return dataAniversario;
}