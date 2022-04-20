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