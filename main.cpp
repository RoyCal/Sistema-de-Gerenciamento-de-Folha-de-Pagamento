#include "Funcionario.h"
#include "Operador.h"
#include "Gerente.h"
#include "Diretor.h"
#include "Presidente.h"
#include "Arquivo.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void imprimeMenuPrincipal(){
    cout << "Menu principal\n" << endl;
    cout << "1 - Adicionar um funcionario" << endl;
    cout << "2 - Editar um registro" << endl;
    cout << "3 - Excluir um registro" << endl;
    cout << "4 - Exibir um registro" << endl;
    cout << "5 - Lista de funcionarios" << endl;
    cout << "6 - Conceder aumento" << endl;
    cout << "7 - Calcular folha salarial" << endl;
    cout << "8 - Consultar folha salarial do funcionario" << endl;
    cout << "9 - Consultar folha salarial da empresa" << endl;
    cout << "10 - Buscar funcionario" << endl;
    cout << "0 - Sair do Sistema" << endl;
}

string completaNumero(string numero){ //funcao que completa o numero caso o usuario digite 
    if(numero.size() == 3){           //um numero com menos de 4 digitos
        numero = "0" + numero;
    } else if(numero.size() == 2){
        numero = "00" + numero;
    } else if(numero.size() == 1){
        numero = "000" + numero;
    }

    return numero;
}

int main(){ 
    int i, j, k, escolha, count;

    string numero, designacao;

    Operador operador;
    Gerente gerente;
    Diretor diretor;
    Presidente presidente;
    Arquivo arquivo;

    arquivo.criaArquivo();

    arquivo.scanArquivo();

    system("cls");

    imprimeMenuPrincipal();

    k = 1;
    while(k){
        cin >> escolha;
        getchar();
    
        switch(escolha){
            case 1:
                system("cls");

                cout << "Digite o codigo do novo funcionario" << endl;

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
                        arquivo.stringToCode(i);

                        if(numero == arquivo.linhaAux){  
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

                system("cls");

                cout << "Qual sera a sua designacao na empresa?" << endl;

                getline(cin, designacao);

                if(designacao == "Operador"){
                    system("cls");

                    operador.getAtributos(numero);
                    arquivo.atualizaArquivo(operador.atributosToString());

                    return 0;
                } else if(designacao == "Gerente"){

                } else if(designacao == "Diretor"){

                } else if(designacao == "Presidente"){

                } else {

                }
            case 2:
            case 3:
            case 4:
            case 5:
            case 6:
            case 7:
            case 8:
            case 9:
            case 10:
            case 0:
            break;
        }
    }

    return 0;
}