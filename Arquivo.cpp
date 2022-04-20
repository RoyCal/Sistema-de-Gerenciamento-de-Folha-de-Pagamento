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