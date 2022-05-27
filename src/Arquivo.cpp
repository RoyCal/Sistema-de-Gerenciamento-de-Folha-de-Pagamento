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
    arquivo.open("../data/dados.txt", ios::in);

    if(arquivo.is_open() == false){                 ///////////////////////////////////////////////
        arquivo.open("../data/dados.txt", ios::out);        //se o arquivo nao existe, ele cria o arquivo//
        arquivo << "#";                             ///////////////////////////////////////////////
        arquivo.close();                            
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

    arquivo.open("../data/dados.txt", ios::in);
    
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

void Arquivo::percorrerString(int i, int cont){
    int j, count = 0;

    if(linhas[i] != "" && linhas[i] != "#"){
        linhaAux = linhas[i];
        
        for(j = 0; j < linhaAux.size(); j++){
            if(linhaAux[j] == '-'){
                count++;
            }

            if(count == cont){
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

void Arquivo::stringToEndereco(int i){
    percorrerString(i, 2);
}

void Arquivo::stringTotelefone(int i){
    percorrerString(i, 3);
}

void Arquivo::stringToDataIngresso(int i){
    percorrerString(i, 4);
}

string Arquivo::getDesignacao(int i){
    percorrerString(i, 5);

    return linhaAux;
}

void Arquivo::stringToSalario(int i){
    percorrerString(i, 6);
}

void Arquivo::stringToDataAniversario(int i){
    percorrerString(i, 7);
}

void Arquivo::atualizaArquivo(string str){
    int i;

    arquivo.open("../data/dados.txt", ios::out);
    arquivo.clear();
    arquivo.close();

    arquivo.open("../data/dados.txt", ios::out | ios::app);

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
    percorrerString(i, 8);
}

void Arquivo::stringToAreaFormacaoDiretor(int i){
    percorrerString(i, 9);
}

void Arquivo::stringToFormacaoAcadMax(int i){
    percorrerString(i, 9);
}

void Arquivo::stringToAreaFormacaoPresidente(int i){
    percorrerString(i, 8);
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
        arquivo.open("../data/dados.txt", ios::out);
        arquivo.clear();
        arquivo.close();

        arquivo.open("../data/dados.txt", ios::out | ios::app);

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

void Arquivo::limpaFolhas(){
    int i, j;

    for(i = 0; i < NUMERO_LINHAS; i++){
        if(linhas[i] == "#"){
            j = i + 1;
            break;
        }   
    } 

    while(1){
        if(linhas[j] != ""){
            linhas[j] = "";
            j++;
        } else {
            break;
        }
    }
}
void Arquivo::imprimeFolhaFuncionario(int i){
    string codigo, nome, salarioBase, INSS, IRRF, horasExtra, diasTrab, salarioLiquido;

    stringToCode(i);
    codigo = linhaAux;

    stringToNome(i);
    nome = linhaAux;

    percorrerString(i, 2);
    salarioBase = linhaAux;

    percorrerString(i, 3);
    INSS = linhaAux;

    percorrerString(i, 4);
    IRRF = linhaAux;

    percorrerString(i, 5);
    horasExtra = linhaAux;

    percorrerString(i, 6);
    diasTrab = linhaAux;

    percorrerString(i, 7);
    salarioLiquido = linhaAux;

    cout << "Codigo: " << codigo << endl;
    cout << "Nome: " << nome << endl;
    cout << "Salario bruto: " << salarioBase << endl;
    cout << "Desconto INSS: -" << INSS << endl;
    cout << "Desconto IRRF: -" << IRRF << endl;
    cout << "Bonus de horas extras: +" << horasExtra << endl;
    cout << "Dias trabalhados: " << diasTrab << endl;
    cout << "Salario liquido: " << salarioLiquido << endl;
    cout << "\n";
}