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

bool Funcionario::verificaAnoBisexto(int ano){
    if(ano % 4 != 0){
        return false;
    }

    if(ano % 4 == 0 && ano % 100 != 0){
        return true;
    }

    if(ano % 4 == 0 && ano % 100 == 0 && ano % 400 == 0){
        return true;
    } else {
        return false;
    }
}

bool Funcionario::verificaValidadeData(string str){
    int dia, mes, ano;
    string aux;

    if(str.size() != 10){
        return false;
    }

    aux = str;
    dia = stoi(aux.erase(2, 8));

    aux = str;
    aux = aux.erase(0, 3);
    mes = stoi(aux.erase(2, 5));

    aux = str;
    ano = stoi(aux.erase(0, 6));

    if(str[2] != '/' || str[5] != '/'){
        return false;
    }

    if(dia < 1 || dia > 31){
        return false;
    }

    if(mes < 1 || mes > 12){
        return false;
    }

    if(ano < 1){
        return false;
    }

    switch(mes){
        case 2:
            if(verificaAnoBisexto(ano)){
                if(dia > 29){
                    return false;
                } else {
                    return true;
                }
            } else {
               if(dia > 28){
                    return false;
                } else {
                    return true;
                } 
            }
        case 4:
        case 6:
        case 9:
        case 11:
            if(dia > 30){
                return false;
            } else {
                return true;
            }
        default:
            return true;
    }
}

bool Funcionario::verificaValidadeDataAniversario(string str){
    int dia, mes;
    string aux;

    if(str.size() != 5){
        return false;
    }

    aux = str;
    dia = stoi(aux.erase(2, 3));

    aux = str;
    mes = stoi(aux.erase(0, 3));

    if(str[2] != '/'){
        return false;
    }

    if(dia < 1 || dia > 31){
        return false;
    }

    if(mes < 1 || mes > 12){
        return false;
    }

    switch(mes){
        case 2:
            if(dia > 29){
                return false;
            } else {
                return true;
            }
        case 4:
        case 6:
        case 9:
        case 11:
            if(dia > 30){
                return false;
            } else {
                return true;
            }
        default:
            return true;
    }   
}