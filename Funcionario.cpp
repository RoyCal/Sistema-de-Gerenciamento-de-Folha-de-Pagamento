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

string Funcionario::CEPtoEndereco(string CEP){
    int i;
    
    fstream arquivo;

    string linhas[12];
    string url = "https://viacep.com.br/ws/" + CEP + "/json/";
    string comando = "wget " + url;

    system(comando.c_str());

    arquivo.open("index.html", ios::in);

    for(i = 0; i < 12; i++){
        getline(arquivo, linhas[i]);
    }

    if(linhas[2] == "}"){
        arquivo.close();
        system("del index.html");
        system("cls");
        return "CEP nao encontrado. Tente novamente";
    }

    arquivo.close();

    system("del index.html");

    linhas[2].erase(0, 17);
    
    i = 0;

    while(1){
        if(linhas[2][i] == '"'){
            linhas[2].erase(i, 2);
            break;
        }

        i++;
    }

    linhas[4].erase(0, 13);
    
    i = 0;

    while(1){
        if(linhas[4][i] == '"'){
            linhas[4].erase(i, 2);
            break;
        }

        i++;
    }

    linhas[5].erase(0, 17);
    
    i = 0;

    while(1){
        if(linhas[5][i] == '"'){
            linhas[5].erase(i, 2);
            break;
        }

        i++;
    }

    linhas[6].erase(0, 9);
    
    i = 0;

    while(1){
        if(linhas[6][i] == '"'){
            linhas[6].erase(i, 2);
            break;
        }

        i++;
    }

    return linhas[2] + ", " + linhas[4] + ", " + linhas[5] + ", " + linhas[6] + ", numero ";
}

string Funcionario::atributosToString(){
    return codigo + " - " + nome + " - " + endereco + " - " + telefone + " - " + dataDeIngresso + " - " + designacao + " - " + to_string(salario).erase(to_string(salario).size()-4, 4) + " - " + dataAniversario;
}