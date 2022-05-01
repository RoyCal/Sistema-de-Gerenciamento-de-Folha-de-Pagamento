#include "Arquivo.h"

void Arquivo::imprimeArquivo(){
    int i;

    for(i = 0; i < NUMERO_LINHAS; i++){         //imprimindo as linhas
        if(linhas[i] != ""){
            cout << linhas[i] << endl;
        }
    }
}

void Arquivo::criaArquivo(){
    arquivo.open("dados.txt", ios::in);

    if(arquivo.is_open() == false){                 ///////////////////////////////////////////////
        arquivo.open("dados.txt", ios::out);        //se o arquivo nao existe, ele cria o arquivo//
        arquivo.close();                            ///////////////////////////////////////////////
    }

    arquivo.close();
}

void Arquivo::stringToCode(int i){
    if(linhas[i] != "" && linhas[i] != "#"){
        linhaAux = linhas[i];
        linhaAux.erase(4, linhaAux.size());
    }
}

void Arquivo::scanArquivo(){
    int i;

    arquivo.open("dados.txt", ios::in);
    
    i = 0;                              //Colocando todas as linhas do arquivo em um vetor de strings
    while(getline(arquivo, linhas[i])){
        i++;
    }

    arquivo.close();
}

void Arquivo::stringToNome(int i){
    int j;

    if(linhas[i] != "" && linhas[i] != "#"){
        linhaAux = linhas[i];
        linhaAux.erase(0, 7);
        for(j = 0; j < linhaAux.size(); j++){
            if(linhaAux[j] == '-'){
                linhaAux.erase(j-1, linhaAux.size());
            }
        }
    }
}

void Arquivo::stringToEndereco(int i){
    int j, count = 0;

    if(linhas[i] != "" && linhas[i] != "#"){
        linhaAux = linhas[i];
        
        for(j = 0; j < linhaAux.size(); j++){
            if(linhaAux[j] == '-'){
                count++;
            }

            if(count == 2){
                linhaAux.erase(0, j+2);
                break;
            }
        }

        for(j = 0; j < linhaAux.size(); j++){
            if(linhaAux[j] == '-'){
                linhaAux.erase(j-1, linhaAux.size());
                break;
            }
        }
    }
}

void Arquivo::stringTotelefone(int i){
    int j, count = 0;

    if(linhas[i] != "" && linhas[i] != "#"){
        linhaAux = linhas[i];
        
        for(j = 0; j < linhaAux.size(); j++){
            if(linhaAux[j] == '-'){
                count++;
            }

            if(count == 3){
                linhaAux.erase(0, j+2);
                break;
            }
        }

        for(j = 0; j < linhaAux.size(); j++){
            if(linhaAux[j] == '-'){
                linhaAux.erase(j-1, linhaAux.size());
                break;
            }
        }
    }
}

void Arquivo::stringToDataIngresso(int i){
    int j, count = 0;

    if(linhas[i] != "" && linhas[i] != "#"){
        linhaAux = linhas[i];
        
        for(j = 0; j < linhaAux.size(); j++){
            if(linhaAux[j] == '-'){
                count++;
            }

            if(count == 4){
                linhaAux.erase(0, j+2);
                break;
            }
        }

        for(j = 0; j < linhaAux.size(); j++){
            if(linhaAux[j] == '-'){
                linhaAux.erase(j-1, linhaAux.size());
                break;
            }
        }
    }
}

string Arquivo::getDesignacao(int i){
    int j, count = 0;

    if(linhas[i] != "" && linhas[i] != "#"){
        linhaAux = linhas[i];
        
        for(j = 0; j < linhaAux.size(); j++){
            if(linhaAux[j] == '-'){
                count++;
            }

            if(count == 5){
                linhaAux.erase(0, j+2);
                break;
            }
        }

        for(j = 0; j < linhaAux.size(); j++){
            if(linhaAux[j] == '-'){
                linhaAux.erase(j-1, linhaAux.size());
                break;
            }
        }
    }

    return linhaAux;
}

void Arquivo::stringToSalario(int i){
    int j, count = 0;

    if(linhas[i] != "" && linhas[i] != "#"){
        linhaAux = linhas[i];
        
        for(j = 0; j < linhaAux.size(); j++){
            if(linhaAux[j] == '-'){
                count++;
            }

            if(count == 6){
                linhaAux.erase(0, j+2);
                break;
            }
        }

        for(j = 0; j < linhaAux.size(); j++){
            if(linhaAux[j] == '-'){
                linhaAux.erase(j-1, linhaAux.size());
                break;
            }
        }
    }
}

void Arquivo::stringToDataAniversario(int i){
    int j, count = 0;

    if(linhas[i] != "" && linhas[i] != "#"){
        linhaAux = linhas[i];
        
        for(j = 0; j < linhaAux.size(); j++){
            if(linhaAux[j] == '-'){
                count++;
            }

            if(count == 7){
                linhaAux.erase(0, j+2);
                break;
            }
        }

        for(j = 0; j < linhaAux.size(); j++){
            if(linhaAux[j] == '-'){
                linhaAux.erase(j-1, linhaAux.size());
                break;
            }
        }
    }
}

void Arquivo::atualizaArquivo(string str){
    int i;

    arquivo.open("dados.txt", ios::out);
    arquivo.clear();
    arquivo.close();

    arquivo.open("dados.txt", ios::out | ios::app);

    for(i = 0; i < NUMERO_LINHAS; i++){
        if(linhas[i] != ""){
            if(linhas[i] == "#"){
                arquivo << str << endl;
                arquivo << linhas[i] << endl;
            } else {
                arquivo << linhas[i] << endl;
            }
        }
    }

    arquivo.close();
}

void Arquivo::stringToAreaSupervisao(int i){
    int j, count = 0;

    if(linhas[i] != "" && linhas[i] != "#"){
        linhaAux = linhas[i];
        
        for(j = 0; j < linhaAux.size(); j++){
            if(linhaAux[j] == '-'){
                count++;
            }

            if(count == 8){
                linhaAux.erase(0, j+2);
                break;
            }
        }

        for(j = 0; j < linhaAux.size(); j++){
            if(linhaAux[j] == '-'){
                linhaAux.erase(j-1, linhaAux.size());
                break;
            }
        }
    }
}

void Arquivo::stringToAreaFormacaoDiretor(int i){
    int j, count = 0;

    if(linhas[i] != "" && linhas[i] != "#"){
        linhaAux = linhas[i];
        
        for(j = 0; j < linhaAux.size(); j++){
            if(linhaAux[j] == '-'){
                count++;
            }

            if(count == 9){
                linhaAux.erase(0, j+2);
                break;
            }
        }

        for(j = 0; j < linhaAux.size(); j++){
            if(linhaAux[j] == '-'){
                linhaAux.erase(j-1, linhaAux.size());
                break;
            }
        }
    }
}

void Arquivo::stringToFormacaoAcadMax(int i){
    int j, count = 0;

    if(linhas[i] != "" && linhas[i] != "#"){
        linhaAux = linhas[i];
        
        for(j = 0; j < linhaAux.size(); j++){
            if(linhaAux[j] == '-'){
                count++;
            }

            if(count == 9){
                linhaAux.erase(0, j+2);
                break;
            }
        }

        for(j = 0; j < linhaAux.size(); j++){
            if(linhaAux[j] == '-'){
                linhaAux.erase(j-1, linhaAux.size());
                break;
            }
        }
    }
}

void Arquivo::stringToAreaFormacaoPresidente(int i){
    int j, count = 0;

    if(linhas[i] != "" && linhas[i] != "#"){
        linhaAux = linhas[i];
        
        for(j = 0; j < linhaAux.size(); j++){
            if(linhaAux[j] == '-'){
                count++;
            }

            if(count == 8){
                linhaAux.erase(0, j+2);
                break;
            }
        }

        for(j = 0; j < linhaAux.size(); j++){
            if(linhaAux[j] == '-'){
                linhaAux.erase(j-1, linhaAux.size());
                break;
            }
        }
    }
}

string Arquivo::completaNumero(string numero){ //funcao que completa o numero caso o usuario digite 
    if(numero.size() == 3){                    //um numero com menos de 4 digitos
        numero = "0" + numero;
    } else if(numero.size() == 2){
        numero = "00" + numero;
    } else if(numero.size() == 1){
        numero = "000" + numero;
    }

    return numero;
}

string Arquivo::verificaCodigoRepetido(){
    int count, i;
    string numero;

    while(1){           //verifica se o codigo digitado ja existe
        count = 0;

        while(1){
            getline(cin, numero);

            if(numero.size() > 4){
                system("cls");

                cout << "O codigo deve ter 4 digitos! Tente novamente" << endl;
            } else if(numero.size() == 4){
                break;
            } else {
                numero = completaNumero(numero);
                break;
            }
        }

        for(i = 0; i < NUMERO_LINHAS; i++){
            if(linhas[i] == "#"){
                break;
            }
            
            stringToCode(i);

            if(numero == linhaAux){  
                system("cls");

                cout << "Codigo ja existente. Tente novamente" << endl;
                count++;
                break;
            }
        }

        if(count == 0){ //se nenhum codigo igual for encontrado, o programa segue
            break;
        }
    }

    return numero;
}

void Arquivo::substituiLinha(string novaLinha, string numero){
    int i;

    for(i = 0; i < NUMERO_LINHAS; i++){
        stringToCode(i);

        if(numero == linhaAux){
            linhas[i] = "";
            linhas[i] = novaLinha;
            break;
        }
    }
}

void Arquivo::substituiArquivo(){
    int i;

    for(i = 0; i < NUMERO_LINHAS; i++){
        arquivo.open("dados.txt", ios::out);
        arquivo.clear();
        arquivo.close();

        arquivo.open("dados.txt", ios::out | ios::app);

        for(i = 0; i < NUMERO_LINHAS; i++){
            if(linhas[i] != ""){
                arquivo << linhas[i] << endl;
            }
        }
    }
}

Gerente Arquivo::stringToGerente(int i){
    Gerente gerente;

    stringToCode(i);
    gerente.setCodigo(linhaAux);

    stringToNome(i);
    gerente.setNome(linhaAux);

    stringToEndereco(i);
    gerente.setEndereco(linhaAux); 

    stringTotelefone(i);
    gerente.setTelefone(linhaAux);

    stringToDataIngresso(i);
    gerente.setDataDeIngresso(linhaAux);

    stringToSalario(i);
    gerente.setSalario(stof(linhaAux));

    stringToDataAniversario(i);
    gerente.setDataAniversario(linhaAux);

    stringToAreaSupervisao(i);
    gerente.setAreaSupervisao(linhaAux);

    return gerente;
}

Operador Arquivo::stringToOperador(int i){
    Operador operador;

    stringToCode(i);
    operador.setCodigo(linhaAux);

    stringToNome(i);
    operador.setNome(linhaAux);

    stringToEndereco(i);
    operador.setEndereco(linhaAux); 

    stringTotelefone(i);
    operador.setTelefone(linhaAux);

    stringToDataIngresso(i);
    operador.setDataDeIngresso(linhaAux);

    stringToSalario(i);
    operador.setSalario(stof(linhaAux));

    stringToDataAniversario(i);
    operador.setDataAniversario(linhaAux);

    return operador;
}

Diretor Arquivo::stringToDiretor(int i){
    Diretor diretor;

    stringToCode(i);
    diretor.setCodigo(linhaAux);

    stringToNome(i);
    diretor.setNome(linhaAux);

    stringToEndereco(i);
    diretor.setEndereco(linhaAux); 

    stringTotelefone(i);
    diretor.setTelefone(linhaAux);

    stringToDataIngresso(i);
    diretor.setDataDeIngresso(linhaAux);

    stringToSalario(i);
    diretor.setSalario(stof(linhaAux));

    stringToDataAniversario(i);
    diretor.setDataAniversario(linhaAux);

    stringToAreaSupervisao(i);
    diretor.setAreaSupervisao(linhaAux);

    stringToAreaFormacaoDiretor(i);
    diretor.setAreaDeFormacao(linhaAux);

    return diretor;
}

Presidente Arquivo::stringToPresidente(int i){
    Presidente presidente;

    stringToCode(i);
    presidente.setCodigo(linhaAux);

    stringToNome(i);
    presidente.setNome(linhaAux);

    stringToEndereco(i);
    presidente.setEndereco(linhaAux); 

    stringTotelefone(i);
    presidente.setTelefone(linhaAux);

    stringToDataIngresso(i);
    presidente.setDataDeIngresso(linhaAux);

    stringToSalario(i);
    presidente.setSalario(stof(linhaAux));

    stringToDataAniversario(i);
    presidente.setDataAniversario(linhaAux);

    stringToAreaFormacaoPresidente(i);
    presidente.setAreaDeFormacao(linhaAux);

    stringToFormacaoAcadMax(i);
    presidente.setFormacaoMaxima(linhaAux);

    return presidente;
}

bool Arquivo::verificaCalculoFolha(string str){
    int i;

    for(i = 0; i < NUMERO_LINHAS; i++){
        if(linhas[i] == "/" + str + "/"){
            return true;
        }
    }

    return false;
}