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

void Presidente::getAtributos(string codigo){
    string CEP, numero;

    this->codigo = codigo;

    cout << "Qual o nome do funcionario?" << endl;
    getline(cin, nome);
    system("cls");

    cout << "Qual o CEP do funcionario?" << endl;
    getline(cin, CEP);
    system("cls");
    cout << "Qual o numero da residencia do funcionario?" << endl;
    getline(cin, numero);
    endereco = CEPtoEndereco(CEP) + numero;
    system("cls");

    cout << "Qual o telefone do funcionario?" << endl;
    getline(cin, telefone);
    system("cls");

    cout << "Qual a data de ingresso do funcionario? __/__/__" << endl;
    getline(cin, dataDeIngresso);
    system("cls");

    cout << "Qual sera o seu salario inicial?" << endl;
    cin >> salario;
    getchar();
    system("cls");

    cout << "Qual a data de aniversario do funcionario? __/__" << endl;
    getline(cin, dataAniversario);
    system("cls");

    cout << "Qual eh a sua area de formacao?" << endl;
    getline(cin, areaDeFormacao);
    system("cls");

    cout << "Qual a sua formacao academica maxima?" << endl;
    getline(cin, formacaoMaxima);
    system("cls");
}

string Presidente::atributosToString(){
    return codigo + " - " + nome + " - " + endereco + " - " + telefone + " - " + dataDeIngresso + " - " + designacao + " - " + to_string(salario) + " - " + dataAniversario + " - " + areaDeFormacao + " - " + formacaoMaxima;
}