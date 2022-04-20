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
    int i, j, k, l, escolha, count;

    string numero, designacao;

    Operador operador;
    Gerente gerente;
    Diretor diretor;
    Presidente presidente;

    Arquivo arquivo;

    arquivo.criaArquivo();

    system("cls");

    imprimeMenuPrincipal();

    k = 1;
    while(k){
        arquivo.scanArquivo();
        
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

                    operador = Operador();

                    break;
                } else if(designacao == "Gerente"){
                    system("cls");

                    gerente.getAtributos(numero);
                    arquivo.atualizaArquivo(gerente.atributosToString());

                    gerente = Gerente();

                    break;
                } else if(designacao == "Diretor"){
                    system("cls");

                    diretor.getAtributos(numero);
                    arquivo.atualizaArquivo(diretor.atributosToString());

                    diretor = Diretor();

                    break;
                } else if(designacao == "Presidente"){
                    system("cls");

                    presidente.getAtributos(numero);
                    arquivo.atualizaArquivo(presidente.atributosToString());

                    presidente = Presidente();

                    break;
                }
            case 2:
                system("cls");

                l = 1;
                while(l){
                    cout << "Informe o codigo do funcionario para editar seu registro" << endl;

                    getline(cin, numero);
                    numero = completaNumero(numero);

                    for(i = 0; i < NUMERO_LINHAS; i++){
                        arquivo.stringToCode(i);

                        if(numero == arquivo.linhaAux){
                            if(arquivo.getDesignacao(i) == "Operador"){
                                system("cls");

                                arquivo.stringToCode(i);
                                operador.setCodigo(arquivo.linhaAux);

                                arquivo.stringToNome(i);
                                operador.setNome(arquivo.linhaAux);

                                arquivo.stringToEndereco(i);
                                operador.setEndereco(arquivo.linhaAux); 

                                arquivo.stringTotelefone(i);
                                operador.setTelefone(arquivo.linhaAux);

                                arquivo.stringToDataIngresso(i);
                                operador.setDataDeIngresso(arquivo.linhaAux);

                                arquivo.stringToSalario(i);
                                operador.setSalario(stof(arquivo.linhaAux));

                                arquivo.stringToDataAniversario(i);
                                operador.setDataAniversario(arquivo.linhaAux);

                                operador.imprimeRegistro();

                                operador = Operador();

                                l = 0;
                                
                                break;
                            } else if(arquivo.getDesignacao(i) == "Gerente"){
                                system("cls");

                                arquivo.stringToCode(i);
                                gerente.setCodigo(arquivo.linhaAux);

                                arquivo.stringToNome(i);
                                gerente.setNome(arquivo.linhaAux);

                                arquivo.stringToEndereco(i);
                                gerente.setEndereco(arquivo.linhaAux); 

                                arquivo.stringTotelefone(i);
                                gerente.setTelefone(arquivo.linhaAux);

                                arquivo.stringToDataIngresso(i);
                                gerente.setDataDeIngresso(arquivo.linhaAux);

                                arquivo.stringToSalario(i);
                                gerente.setSalario(stof(arquivo.linhaAux));

                                arquivo.stringToDataAniversario(i);
                                gerente.setDataAniversario(arquivo.linhaAux);

                                arquivo.stringToAreaSupervisao(i);
                                gerente.setAreaSupervisao(arquivo.linhaAux);

                                gerente.imprimeRegistro();

                                gerente = Gerente();

                                l = 0;

                                break;
                            } else if(arquivo.getDesignacao(i) == "Diretor"){
                                system("cls");

                                arquivo.stringToCode(i);
                                diretor.setCodigo(arquivo.linhaAux);

                                arquivo.stringToNome(i);
                                diretor.setNome(arquivo.linhaAux);

                                arquivo.stringToEndereco(i);
                                diretor.setEndereco(arquivo.linhaAux); 

                                arquivo.stringTotelefone(i);
                                diretor.setTelefone(arquivo.linhaAux);

                                arquivo.stringToDataIngresso(i);
                                diretor.setDataDeIngresso(arquivo.linhaAux);

                                arquivo.stringToSalario(i);
                                diretor.setSalario(stof(arquivo.linhaAux));

                                arquivo.stringToDataAniversario(i);
                                diretor.setDataAniversario(arquivo.linhaAux);

                                arquivo.stringToAreaSupervisao(i);
                                diretor.setAreaSupervisao(arquivo.linhaAux);

                                arquivo.stringToAreaFormacaoDiretor(i);
                                diretor.setAreaDeFormacao(arquivo.linhaAux);

                                diretor.imprimeRegistro();

                                diretor = Diretor();

                                l = 0;
                                
                                break;
                            } else if(arquivo.getDesignacao(i) == "Presidente"){
                                system("cls");

                                arquivo.stringToCode(i);
                                presidente.setCodigo(arquivo.linhaAux);

                                arquivo.stringToNome(i);
                                presidente.setNome(arquivo.linhaAux);

                                arquivo.stringToEndereco(i);
                                presidente.setEndereco(arquivo.linhaAux); 

                                arquivo.stringTotelefone(i);
                                presidente.setTelefone(arquivo.linhaAux);

                                arquivo.stringToDataIngresso(i);
                                presidente.setDataDeIngresso(arquivo.linhaAux);

                                arquivo.stringToSalario(i);
                                presidente.setSalario(stof(arquivo.linhaAux));

                                arquivo.stringToDataAniversario(i);
                                presidente.setDataAniversario(arquivo.linhaAux);

                                arquivo.stringToAreaFormacaoPresidente(i);
                                presidente.setAreaDeFormacao(arquivo.linhaAux);

                                arquivo.stringToFormacaoAcadMax(i);
                                presidente.setFormacaoMaxima(arquivo.linhaAux);

                                presidente.imprimeRegistro();

                                presidente = Presidente();

                                l = 0;

                                break;
                            }

                        } else if(i == NUMERO_LINHAS-1){
                            system("cls");

                            cout << "Funcionario nao encontrado" << endl;

                            break;
                        }
                    }

                    cout << "\nPresione \"ENTER\" para voltar para o menu principal" << endl;

                    getchar();

                    system("cls");
                }
                
                break;
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

        arquivo.scanArquivo();
        
        imprimeMenuPrincipal();
    }

    return 0;
}