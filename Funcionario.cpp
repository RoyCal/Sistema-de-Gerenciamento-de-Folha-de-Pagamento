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

string Funcionario::calculaFolhaSalarial(int i){
    unsigned seed = (i+1)*time(0);

    srand(seed);

    int diasTrabalhados;

    while(1){
        diasTrabalhados = 1 + rand() % MAXIMO_DIAS_TRABALHADOS;

        if(diasTrabalhados < 17){
            continue;
        } else {
            break;
        }
    }

    int horaExtra = 1 + rand() % MAXIMO_HORA_EXTRA;
    
    float valorHora = salario / 160;

    float INSS;

    if(salario <= 1212){
        INSS = salario*0.075;
    } else if(salario > 1212 && salario <= 2427.35){
        INSS = 90.9 + (salario - 1212)*0.09;
    } else if(salario > 2427.35 && salario <= 3641.03){
        INSS = 90.9 + 109.38 + (salario - 2427.36)*0.12;
    } else if(salario > 3641.03 && salario <= 7087.22){
        INSS = 90.9 + 109.38 + 145.64 + (salario - 3641.03)*0.14;
    } else {
        INSS = 828.38;
    }

    float IRRF;

    if(salario <= 1903.98){
        IRRF = 0;
    } else if(salario > 1903.98 && salario <= 2826.65){
        IRRF = (salario - INSS)*0.075;
    } else if(salario > 2826.65 && salario <= 3751.05){
        IRRF = (salario - INSS)*0.15;
    } else if(salario > 3751.05 && salario <= 4664.68){
        IRRF = (salario - INSS)*0.225;
    } else {
        IRRF = (salario - INSS)*0.275;
    }

    float salarioLiquido = salario - INSS - IRRF + horaExtra*valorHora*2;

    this->salarioLiquido = salarioLiquido;

    string sal, prev, imp, hex, daysw, salal;

    sal = to_string(salario).erase(to_string(salario).size()-4, 4);
    prev = to_string(INSS).erase(to_string(INSS).size()-4, 4);
    imp = to_string(IRRF).erase(to_string(IRRF).size()-4, 4);
    hex = to_string(horaExtra*valorHora*2).erase(to_string(horaExtra*valorHora*2).size()-4, 4);
    daysw = to_string(diasTrabalhados);
    salal = to_string(salarioLiquido).erase(to_string(salarioLiquido).size()-4, 4);

    return codigo + " - " + nome + " - " + sal + " - " + prev + " - " + imp + " - " +  hex + " - " +  daysw + " - " + salal;
}

float Funcionario::getSalarioLiquido(){
    return salarioLiquido;
}

bool Funcionario::verificaIntervaloDatas(string data1, string data2, string dataRef){
    int aux;

    int dia1, mes1, ano1;
    int dia2, mes2, ano2;
    int diaRef, mesRef, anoRef;

    string strAux;

    strAux = data1;
    dia1 = stoi(strAux.erase(2, 8));
    strAux = data1;
    mes1 = stoi(strAux.erase(0, 3).erase(2, 5));
    strAux = data1;
    ano1 = stoi(strAux.erase(0, 6));

    strAux = data2;
    dia2 = stoi(strAux.erase(2, 8));
    strAux = data2;
    mes2 = stoi(strAux.erase(0, 3).erase(2, 5));
    strAux = data2;
    ano2 = stoi(strAux.erase(0, 6));

    strAux = dataRef;
    diaRef = stoi(strAux.erase(2, 8));
    strAux = dataRef;
    mesRef = stoi(strAux.erase(0, 3).erase(2, 5));
    strAux = dataRef;
    anoRef = stoi(strAux.erase(0, 6));

    if(ano1 > ano2){
        aux = ano1;
        ano1 = ano2;
        ano2 = aux;

        aux = mes1;
        mes1 = mes2;
        mes2 = aux;

        aux = dia1;
        dia1 = dia2;
        dia2 = aux;
    } else if(ano1 == ano2 && mes1 > mes2){
        aux = ano1;
        ano1 = ano2;
        ano2 = aux;

        aux = mes1;
        mes1 = mes2;
        mes2 = aux;

        aux = dia1;
        dia1 = dia2;
        dia2 = aux;
    } else if(mes1 == mes2 && dia1 > dia2){
        aux = ano1;
        ano1 = ano2;
        ano2 = aux;

        aux = mes1;
        mes1 = mes2;
        mes2 = aux;

        aux = dia1;
        dia1 = dia2;
        dia2 = aux;
    }

    double res1, res2, resRef;

    res1 = dia1 + mes1*30 + ano1*365;
    res2 = dia2 + mes2*30 + ano2*365;
    resRef = diaRef + mesRef*30 + anoRef*365;

    if(resRef >= res1 && resRef <= res2){
        return true;
    } else {
        return false;
    }
}