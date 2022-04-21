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

int main(){ 
    int i, j, k, l, m, escolha, escolha1, count;
    int flag = 0;

    string numero, designacao, strAux1, strAux2;

    Operador operador;
    Gerente gerente;
    Diretor diretor;
    Presidente presidente;

    Arquivo arquivo;

    arquivo.criaArquivo();

    system("cls");

    k = 1;
    while(k){
        arquivo.scanArquivo();
        
        if(flag == 0){
            imprimeMenuPrincipal();

            cin >> escolha;
            getchar();
        }
    
        switch(escolha){
            case 1: //adicionar funcionario 
                system("cls");

                cout << "Digite o codigo do novo funcionario" << endl;

                numero = arquivo.verificaCodigoRepetido();

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
            case 2: //editar atributos 
                system("cls");

                l = 1;
                while(l){

                    if(flag == 0){
                        cout << "Informe o codigo do funcionario para editar seu registro" << endl;

                        getline(cin, numero);
                        numero = arquivo.completaNumero(numero);
                    } 

                    for(i = 0; i < NUMERO_LINHAS; i++){
                        flag = 0;

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

                                j = 1;
                                while(j){
                                    system("cls");

                                    operador.imprimeRegistro();

                                    cout << "\nQual elemento deseja editar do funcionario?" << endl;
                                    cout << "Codigo (1), data de ingresso (2), nome (3), endereco (4), telefone (5), designacao (6), salario (7)" << endl;

                                    cin >> escolha;
                                    getchar();

                                    switch(escolha){
                                        case 1:
                                            system("cls");

                                            strAux1 = operador.getCodigo();

                                            cout << "Informe o novo codigo" << endl;

                                            numero = arquivo.verificaCodigoRepetido();
                                            operador.setCodigo(numero);

                                            arquivo.substituiLinha(operador.atributosToString(), strAux1);

                                            arquivo.substituiArquivo();

                                            arquivo.scanArquivo();

                                            break;
                                        case 2:
                                            system("cls");

                                            strAux1 = operador.getCodigo();

                                            cout << "Informe a nova data de ingresso" << endl;

                                            getline(cin, strAux2);

                                            operador.setDataDeIngresso(strAux2);

                                            arquivo.substituiLinha(operador.atributosToString(), strAux1);

                                            arquivo.substituiArquivo();

                                            arquivo.scanArquivo();

                                            break;
                                        case 3:
                                            system("cls");

                                            strAux1 = operador.getCodigo();

                                            cout << "Informe o novo nome" << endl;

                                            getline(cin, strAux2);

                                            operador.setNome(strAux2);

                                            arquivo.substituiLinha(operador.atributosToString(), strAux1);

                                            arquivo.substituiArquivo();

                                            arquivo.scanArquivo();

                                            break;
                                        case 4:
                                            system("cls");

                                            strAux1 = operador.getCodigo();

                                            cout << "Informe o novo CEP" << endl;

                                            getline(cin, strAux2);

                                            operador.setEndereco(operador.CEPtoEndereco(strAux2));

                                            system("cls");

                                            cout << "Qual o numero da nova residencia?" << endl;

                                            getline(cin, strAux2);

                                            operador.setEndereco(operador.getEndereco() + strAux2);

                                            arquivo.substituiLinha(operador.atributosToString(), strAux1);

                                            arquivo.substituiArquivo();

                                            arquivo.scanArquivo();

                                            break;
                                        case 5:
                                            system("cls");

                                            strAux1 = operador.getCodigo();

                                            cout << "Informe o novo telefone" << endl;

                                            getline(cin, strAux2);

                                            operador.setTelefone(strAux2);

                                            arquivo.substituiLinha(operador.atributosToString(), strAux1);

                                            arquivo.substituiArquivo();

                                            arquivo.scanArquivo();

                                            break;
                                        case 6:
                                            system("cls");

                                            strAux1 = operador.getCodigo();

                                            m = 1;
                                            while(m){
                                                cout << "Qual sera sua nova designacao?" << endl;

                                                cout << "Gerente (1), diretor (2), presidente (3)" << endl;

                                                cin >> escolha1;
                                                getchar();

                                                switch(escolha1){
                                                    case 1:
                                                        system("cls");

                                                        arquivo.substituiLinha(operador.operadorToGerente(), strAux1);

                                                        arquivo.substituiArquivo();

                                                        m=0;

                                                        break;
                                                    case 2:
                                                    case 3:
                                                    default:
                                                        system("cls");

                                                        cout << "Escolha invalida" << endl;
                                                        continue;
                                                }
                                            }

                                            break;
                                        case 7:
                                            system("cls");

                                            strAux1 = operador.getCodigo();

                                            cout << "Informe o novo salario" << endl;

                                            getline(cin, strAux2);

                                            operador.setSalario(stof(strAux2));

                                            arquivo.substituiLinha(operador.atributosToString(), strAux1);

                                            arquivo.substituiArquivo();

                                            arquivo.scanArquivo();

                                            break;
                                        default: 
                                            system("cls");

                                            cout << "Escolha invalida" << endl;
                                            continue;
                                    }

                                    system("cls");

                                    operador.imprimeRegistro();
                                    cout << "\nDeseja editar mais algo?" << endl;
                                    cout << "Sim (1), nao (2)" << endl;

                                    cin >> escolha;
                                    getchar();

                                    switch(escolha){
                                        case 1:
                                            if(arquivo.getDesignacao(i) == "Operador"){
                                                continue;
                                            } else {
                                                l = 0;
                                                flag = 1;
                                                escolha = 2;
                                                arquivo.stringToCode(i);
                                                numero = arquivo.linhaAux;
                                            }
                                        case 2:
                                            j = 0;
                                            break;
                                        default:
                                            j = 0;
                                    }

                                }

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

                                j = 1;
                                while(j){
                                    system("cls");

                                    gerente.imprimeRegistro();

                                    cout << "\nQual elemento deseja editar do funcionario?" << endl;
                                    cout << "Codigo (1), data de ingresso (2), nome (3), endereco (4), telefone (5), designacao (6), salario (7), area de supervisao (8)" << endl;

                                    cin >> escolha;
                                    getchar();

                                    switch(escolha){
                                        case 1:
                                            system("cls");

                                            strAux1 = gerente.getCodigo();

                                            cout << "Informe o novo codigo" << endl;

                                            numero = arquivo.verificaCodigoRepetido();
                                            gerente.setCodigo(numero);

                                            arquivo.substituiLinha(gerente.atributosToString(), strAux1);

                                            arquivo.substituiArquivo();

                                            arquivo.scanArquivo();

                                            break;
                                        case 2:
                                            system("cls");

                                            strAux1 = gerente.getCodigo();

                                            cout << "Informe a nova data de ingresso" << endl;

                                            getline(cin, strAux2);

                                            gerente.setDataDeIngresso(strAux2);

                                            arquivo.substituiLinha(gerente.atributosToString(), strAux1);

                                            arquivo.substituiArquivo();

                                            arquivo.scanArquivo();

                                            break;
                                        case 3:
                                            system("cls");

                                            strAux1 = gerente.getCodigo();

                                            cout << "Informe o novo nome" << endl;

                                            getline(cin, strAux2);

                                            gerente.setNome(strAux2);

                                            arquivo.substituiLinha(gerente.atributosToString(), strAux1);

                                            arquivo.substituiArquivo();

                                            arquivo.scanArquivo();

                                            break;
                                        case 4:
                                            system("cls");

                                            strAux1 = gerente.getCodigo();

                                            cout << "Informe o novo CEP" << endl;

                                            getline(cin, strAux2);

                                            gerente.setEndereco(gerente.CEPtoEndereco(strAux2));

                                            system("cls");

                                            cout << "Qual o numero da nova residencia?" << endl;

                                            getline(cin, strAux2);

                                            gerente.setEndereco(gerente.getEndereco() + strAux2);

                                            arquivo.substituiLinha(gerente.atributosToString(), strAux1);

                                            arquivo.substituiArquivo();

                                            arquivo.scanArquivo();

                                            break;
                                        case 5:
                                            system("cls");

                                            strAux1 = gerente.getCodigo();

                                            cout << "Informe o novo telefone" << endl;

                                            getline(cin, strAux2);

                                            gerente.setTelefone(strAux2);

                                            arquivo.substituiLinha(gerente.atributosToString(), strAux1);

                                            arquivo.substituiArquivo();

                                            arquivo.scanArquivo();

                                            break;
                                        case 6:
                                        case 7:
                                            system("cls");

                                            strAux1 = gerente.getCodigo();

                                            cout << "Informe o novo salario" << endl;

                                            getline(cin, strAux2);

                                            gerente.setSalario(stof(strAux2));

                                            arquivo.substituiLinha(gerente.atributosToString(), strAux1);

                                            arquivo.substituiArquivo();

                                            arquivo.scanArquivo();

                                            break;
                                        case 8:
                                            system("cls");

                                            strAux1 = gerente.getCodigo();

                                            cout << "Informe a nova area de supervisao" << endl;

                                            getline(cin, strAux2);

                                            gerente.setAreaSupervisao(strAux2);

                                            arquivo.substituiLinha(gerente.atributosToString(), strAux1);

                                            arquivo.substituiArquivo();

                                            arquivo.scanArquivo();

                                            break;
                                        default: 
                                            system("cls");

                                            cout << "Escolha invalida" << endl;
                                            continue;
                                    }

                                    system("cls");

                                    gerente.imprimeRegistro();
                                    cout << "\nDeseja editar mais algo?" << endl;
                                    cout << "Sim (1), nao (2)" << endl;

                                    cin >> escolha;
                                    getchar();

                                    switch(escolha){
                                        case 1:
                                            continue;
                                        case 2:
                                            j = 0;
                                            break;
                                        default:
                                            j = 0;
                                    }

                                }

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

                                j = 1;
                                while(j){
                                    system("cls");

                                    diretor.imprimeRegistro();

                                    cout << "\nQual elemento deseja editar do funcionario?" << endl;
                                    cout << "Codigo (1), data de ingresso (2), nome (3), endereco (4), telefone (5), designacao (6), salario (7), area de supervisao (8), area de formacao (9)" << endl;

                                    cin >> escolha;
                                    getchar();

                                    switch(escolha){
                                        case 1:
                                            system("cls");

                                            strAux1 = diretor.getCodigo();

                                            cout << "Informe o novo codigo" << endl;

                                            numero = arquivo.verificaCodigoRepetido();
                                            diretor.setCodigo(numero);

                                            arquivo.substituiLinha(diretor.atributosToString(), strAux1);

                                            arquivo.substituiArquivo();

                                            arquivo.scanArquivo();

                                            break;
                                        case 2:
                                            system("cls");

                                            strAux1 = diretor.getCodigo();

                                            cout << "Informe a nova data de ingresso" << endl;

                                            getline(cin, strAux2);

                                            diretor.setDataDeIngresso(strAux2);

                                            arquivo.substituiLinha(diretor.atributosToString(), strAux1);

                                            arquivo.substituiArquivo();

                                            arquivo.scanArquivo();

                                            break;
                                        case 3:
                                            system("cls");

                                            strAux1 = diretor.getCodigo();

                                            cout << "Informe o novo nome" << endl;

                                            getline(cin, strAux2);

                                            diretor.setNome(strAux2);

                                            arquivo.substituiLinha(diretor.atributosToString(), strAux1);

                                            arquivo.substituiArquivo();

                                            arquivo.scanArquivo();

                                            break;
                                        case 4:
                                            system("cls");

                                            strAux1 = diretor.getCodigo();

                                            cout << "Informe o novo CEP" << endl;

                                            getline(cin, strAux2);

                                            diretor.setEndereco(diretor.CEPtoEndereco(strAux2));

                                            system("cls");

                                            cout << "Qual o numero da nova residencia?" << endl;

                                            getline(cin, strAux2);

                                            diretor.setEndereco(diretor.getEndereco() + strAux2);

                                            arquivo.substituiLinha(diretor.atributosToString(), strAux1);

                                            arquivo.substituiArquivo();

                                            arquivo.scanArquivo();

                                            break;
                                        case 5:
                                            system("cls");

                                            strAux1 = diretor.getCodigo();

                                            cout << "Informe o novo telefone" << endl;

                                            getline(cin, strAux2);

                                            diretor.setTelefone(strAux2);

                                            arquivo.substituiLinha(diretor.atributosToString(), strAux1);

                                            arquivo.substituiArquivo();

                                            arquivo.scanArquivo();

                                            break;
                                        case 6:
                                        case 7:
                                            system("cls");

                                            strAux1 = diretor.getCodigo();

                                            cout << "Informe o novo salario" << endl;

                                            getline(cin, strAux2);

                                            diretor.setSalario(stof(strAux2));

                                            arquivo.substituiLinha(diretor.atributosToString(), strAux1);

                                            arquivo.substituiArquivo();

                                            arquivo.scanArquivo();

                                            break;
                                        case 8:
                                            system("cls");

                                            strAux1 = diretor.getCodigo();

                                            cout << "Informe a nova area de supervisao" << endl;

                                            getline(cin, strAux2);

                                            diretor.setAreaSupervisao(strAux2);

                                            arquivo.substituiLinha(diretor.atributosToString(), strAux1);

                                            arquivo.substituiArquivo();

                                            arquivo.scanArquivo();

                                            break;
                                        case 9:
                                            system("cls");

                                            strAux1 = diretor.getCodigo();

                                            cout << "Informe a nova area de formacao" << endl;

                                            getline(cin, strAux2);

                                            diretor.setAreaDeFormacao(strAux2);

                                            arquivo.substituiLinha(diretor.atributosToString(), strAux1);

                                            arquivo.substituiArquivo();

                                            arquivo.scanArquivo();

                                            break;
                                        default: 
                                            system("cls");

                                            cout << "Escolha invalida" << endl;
                                            continue;
                                    }

                                    system("cls");

                                    diretor.imprimeRegistro();
                                    cout << "\nDeseja editar mais algo?" << endl;
                                    cout << "Sim (1), nao (2)" << endl;

                                    cin >> escolha;
                                    getchar();

                                    switch(escolha){
                                        case 1:
                                            continue;
                                        case 2:
                                            j = 0;
                                            break;
                                        default:
                                            j = 0;
                                    }

                                }

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

                                j = 1;
                                while(j){
                                    system("cls");

                                    presidente.imprimeRegistro();

                                    cout << "\nQual elemento deseja editar do funcionario?" << endl;
                                    cout << "Codigo (1), data de ingresso (2), nome (3), endereco (4), telefone (5), designacao (6), salario (7), area de formacao (8), formacao academica maxima (9)" << endl;

                                    cin >> escolha;
                                    getchar();

                                    switch(escolha){
                                        case 1:
                                            system("cls");

                                            strAux1 = presidente.getCodigo();

                                            cout << "Informe o novo codigo" << endl;

                                            numero = arquivo.verificaCodigoRepetido();
                                            presidente.setCodigo(numero);

                                            arquivo.substituiLinha(presidente.atributosToString(), strAux1);

                                            arquivo.substituiArquivo();

                                            arquivo.scanArquivo();

                                            break;
                                        case 2:
                                            system("cls");

                                            strAux1 = presidente.getCodigo();

                                            cout << "Informe a nova data de ingresso" << endl;

                                            getline(cin, strAux2);

                                            presidente.setDataDeIngresso(strAux2);

                                            arquivo.substituiLinha(presidente.atributosToString(), strAux1);

                                            arquivo.substituiArquivo();

                                            arquivo.scanArquivo();

                                            break;
                                        case 3:
                                            system("cls");

                                            strAux1 = presidente.getCodigo();

                                            cout << "Informe o novo nome" << endl;

                                            getline(cin, strAux2);

                                            presidente.setNome(strAux2);

                                            arquivo.substituiLinha(presidente.atributosToString(), strAux1);

                                            arquivo.substituiArquivo();

                                            arquivo.scanArquivo();

                                            break;
                                        case 4:
                                            system("cls");

                                            strAux1 = presidente.getCodigo();

                                            cout << "Informe o novo CEP" << endl;

                                            getline(cin, strAux2);

                                            presidente.setEndereco(presidente.CEPtoEndereco(strAux2));

                                            system("cls");

                                            cout << "Qual o numero da nova residencia?" << endl;

                                            getline(cin, strAux2);

                                            presidente.setEndereco(presidente.getEndereco() + strAux2);

                                            arquivo.substituiLinha(presidente.atributosToString(), strAux1);

                                            arquivo.substituiArquivo();

                                            arquivo.scanArquivo();

                                            break;
                                        case 5:
                                            system("cls");

                                            strAux1 = presidente.getCodigo();

                                            cout << "Informe o novo telefone" << endl;

                                            getline(cin, strAux2);

                                            presidente.setTelefone(strAux2);

                                            arquivo.substituiLinha(presidente.atributosToString(), strAux1);

                                            arquivo.substituiArquivo();

                                            arquivo.scanArquivo();

                                            break;
                                        case 6:
                                        case 7:
                                            system("cls");

                                            strAux1 = presidente.getCodigo();

                                            cout << "Informe o novo salario" << endl;

                                            getline(cin, strAux2);

                                            presidente.setSalario(stof(strAux2));

                                            arquivo.substituiLinha(presidente.atributosToString(), strAux1);

                                            arquivo.substituiArquivo();

                                            arquivo.scanArquivo();

                                            break;
                                        case 8:
                                            system("cls");

                                            strAux1 = presidente.getCodigo();

                                            cout << "Informe a nova area de formacao" << endl;

                                            getline(cin, strAux2);

                                            presidente.setAreaDeFormacao(strAux2);

                                            arquivo.substituiLinha(presidente.atributosToString(), strAux1);

                                            arquivo.substituiArquivo();

                                            arquivo.scanArquivo();

                                            break;
                                        case 9:
                                            system("cls");

                                            strAux1 = presidente.getCodigo();

                                            cout << "Informe a nova formacao academica maxima" << endl;

                                            getline(cin, strAux2);

                                            presidente.setFormacaoMaxima(strAux2);

                                            arquivo.substituiLinha(presidente.atributosToString(), strAux1);

                                            arquivo.substituiArquivo();

                                            arquivo.scanArquivo();

                                            break;
                                        default: 
                                            system("cls");

                                            cout << "Escolha invalida" << endl;
                                            continue;
                                    }

                                    system("cls");

                                    presidente.imprimeRegistro();
                                    cout << "\nDeseja editar mais algo?" << endl;
                                    cout << "Sim (1), nao (2)" << endl;

                                    cin >> escolha;
                                    getchar();

                                    switch(escolha){
                                        case 1:
                                            continue;
                                        case 2:
                                            j = 0;
                                            break;
                                        default:
                                            j = 0;
                                    }

                                }

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

                    system("cls");
                }
                
                break;
            case 3: //excluir registro
            /***            
              system("cls");

              cout << "Digite o codigo do funcionario que deseja excluir" << endl;

              while(1){           //verifica se o codigo digitado ja existe
                count = 0;
                int count2 = 0;

                for(i = 0; i < NUMERO_LINHAS; i++){
                  arquivo.stringToCode(i);

                  if(numero == arquivo.linhaAux){  //codigo encontrado.
                    arquivo.stringToCode(i);
                    
                    if(arquivo.getDesignacao(i) == "Operador"){

                    } else if(arquivo.getDesignacao(i) == "Gerente"){

                    } else if(arquivo.getDesignacao(i) == "Diretor"){
                      cout << "Nao e permitido excluir este funcionario!" << endl;  
                      count2++;                                                          //informa que nao e permitido excluir                                         
                    } else if(arquivo.getDesignacao(i) == "Presidente"){                 //funcionarios designados como "Diretor"
                      cout << "Nao e permitido excluir este funcionario!" << endl;       //ou "Presidente".
                      count2++;                                                                                               
                    }

                    count++;
                    break;
                  } else if(i == NUMERO_LINHAS-1){
                    system("cls");

                    cout << "Funcionario nao encontrado. Tente novamente" << endl;
                    count++;
                    break;
                  }
                }

                if(count == 0 || count2 == 0){       //caso o codigo inserido nao seja encontrado, o programa informara por 
                  system("cls");                     //uma mensagem e retornara para o inicio da opçao de excluir registro.
                                                                                  
                  cout << "Funcionario nao encontrado. Tente novamente" << endl; 
                }
              }
            ***/
            case 4:
            case 5:
            case 6:
            case 7:
            case 8:
            case 9:
            case 10:
            case 0:
                k = 0;
                break;
            break;
        }
    }

    return 0;
}