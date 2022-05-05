#include "Sistema.h"

void Sistema::imprimeMenuPrincipal(){
    system("cls");

    cout << "--------------------------" << endl;
    cout << "      Menu principal" << endl;
    cout << "--------------------------\n" << endl;
    cout << "1 - Adicionar um funcionario" << endl;
    cout << "2 - Editar um registro" << endl;
    cout << "3 - Excluir um registro" << endl;
    cout << "4 - Exibir um registro" << endl;
    cout << "5 - Lista de funcionarios" << endl;
    cout << "6 - Conceder aumento" << endl;
    cout << "7 - Calcular folha salarial" << endl;
    cout << "8 - Consultar folha salarial do funcionario" << endl;
    cout << "9 - Consultar folha salarial da empresa" << endl;
    cout << "10 - Limpar registro das folhas salariais" << endl;
    cout << "11 - Buscar funcionario" << endl;
    cout << "0 - Sair do Sistema" << endl;
}

void Sistema::adicionarFuncionario(){
    system("cls");

    cout << "Digite o codigo do novo funcionario" << endl;
    cout << "Sair(0)" << endl;

    numero = arquivo.verificaCodigoRepetido();

    if(numero == "0000"){
        j = 0;

        return;
    }
    
    system("cls");

    m = 1;
    while(m){
        cout << "Qual sera a sua designacao na empresa?" << endl;
        cout << "Operador(1) gerente(2) diretor (3) presidente(4)" << endl;

        cin >> escolha1;
        getchar();

        switch(escolha1){
            case 1:
                designacao = "Operador";

                m = 0;

                break;
            case 2:
                designacao = "Gerente";

                m = 0;

                break;
            case 3:
                designacao = "Diretor";

                m = 0;

                break;
            case 4:
                designacao = "Presidente";

                m = 0;

                break;
            default:
                system("cls");
        }
    }

    if(designacao == "Operador"){
        funcionario = new Operador();
        
    } else if(designacao == "Gerente"){
        funcionario = new Gerente();

    } else if(designacao == "Diretor"){
        funcionario = new Diretor();

    } else if(designacao == "Presidente"){
        funcionario = new Presidente();

    }

    system("cls");

    funcionario->getAtributos(numero);
    arquivo.atualizaArquivo(funcionario->atributosToString());
    funcionario->imprimeRegistro();

    cout << "\nFuncionario adicionado com sucesso!\n" << endl;

    cout << "Pressione ENTER para voltar para o menu principal" << endl;

    getchar();
}

void Sistema::editarAtributo(){
    system("cls");

    l = 1;
    while(l){

        if(flag == 0){
            cout << "Informe o codigo do funcionario para editar seu registro" << endl;
            cout << "Sair(0)" << endl;

            getline(cin, numero);

            if(numero == "0"){
                l = 0;

                continue;
            }

            numero = arquivo.completaNumero(numero);
        } 

        for(i = 0; i < NUMERO_LINHAS; i++){
            flag = 0;

            arquivo.stringToCode(i);

            if(numero == arquivo.linhaAux){
                if(arquivo.getDesignacao(i) == "Operador"){
                    system("cls");

                    operador = arquivo.stringToOperador(i);

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

                                system("cls");

                                operador.imprimeRegistro();

                                break;
                            case 2:
                                system("cls");

                                strAux1 = operador.getCodigo();
                                
                                while(1){
                                    cout << "Informe a nova data de ingresso" << endl;

                                    getline(cin, strAux2);

                                    if(operador.verificaValidadeData(strAux2)){
                                        break;
                                    } else {
                                        system("cls");

                                        cout << "Data invalida. Tente novamente\n" << endl;
                                    }
                                }

                                operador.setDataDeIngresso(strAux2);

                                arquivo.substituiLinha(operador.atributosToString(), strAux1);

                                arquivo.substituiArquivo();

                                arquivo.scanArquivo();

                                system("cls");

                                operador.imprimeRegistro();

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

                                system("cls");

                                operador.imprimeRegistro();

                                break;
                            case 4:
                                system("cls");

                                strAux1 = operador.getCodigo();

                                while(1){
                                    cout << "Informe o novo CEP" << endl;

                                    getline(cin, strAux2);

                                    if(strAux2.size() < 8 || strAux2.size() >
                                    8){
                                        system("cls");

                                        cout << "CEP invalido. Tente novamente" << endl;
                                        continue;
                                    }

                                    strAux2 = operador.CEPtoEndereco(strAux2);

                                    if(strAux2 == "CEP nao encontrado. Tente novamente"){
                                        system("cls");

                                        cout << strAux2 << endl;
                                        continue;
                                    }

                                    break;
                                }

                                operador.setEndereco(strAux2);

                                system("cls");

                                cout << "Qual o numero da nova residencia?" << endl;

                                getline(cin, strAux2);

                                operador.setEndereco(operador.getEndereco() + strAux2);

                                arquivo.substituiLinha(operador.atributosToString(), strAux1);

                                arquivo.substituiArquivo();

                                arquivo.scanArquivo();

                                system("cls");

                                operador.imprimeRegistro();

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

                                system("cls");

                                operador.imprimeRegistro();

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

                                            m = 0;

                                            system("cls");

                                            gerente = arquivo.stringToGerente(i);

                                            gerente.imprimeRegistro();

                                            gerente = Gerente();

                                            break;
                                        case 2:
                                            system("cls");

                                            arquivo.substituiLinha(operador.operadorToDiretor(), strAux1);

                                            arquivo.substituiArquivo();

                                            m = 0;

                                            diretor = arquivo.stringToDiretor(i);

                                            diretor.imprimeRegistro();

                                            diretor = Diretor();

                                            break;
                                        case 3:
                                            system("cls");

                                            arquivo.substituiLinha(operador.operadorToPresidente(), strAux1);

                                            arquivo.substituiArquivo();

                                            m = 0;

                                            presidente = arquivo.stringToPresidente(i);

                                            presidente.imprimeRegistro();

                                            presidente = Presidente();

                                            break;
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

                                system("cls");

                                operador.imprimeRegistro();

                                break;
                            default: 
                                system("cls");

                                cout << "Escolha invalida" << endl;
                                continue;
                        }

                        cout << "\nDeseja editar mais algo?" << endl;
                        cout << "Sim (1), nao (2)" << endl;

                        cin >> escolha;
                        getchar();

                        if(escolha == 1){
                            if(arquivo.getDesignacao(i) == "Operador"){
                                continue;
                            } else {
                                l = 0;
                                flag = 1;
                                escolha = 2;
                                arquivo.stringToCode(i);
                                numero = arquivo.linhaAux;
                            }
                        }   

                        j = 0;
                    }

                    operador = Operador();

                    l = 0;
                    
                    break;
                } else if(arquivo.getDesignacao(i) == "Gerente"){
                    system("cls");

                    gerente = arquivo.stringToGerente(i);

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

                                system("cls");

                                gerente.imprimeRegistro();

                                break;
                            case 2:
                                system("cls");

                                strAux1 = gerente.getCodigo();

                                while(1){
                                    cout << "Informe a nova data de ingresso" << endl;

                                    getline(cin, strAux2);

                                    if(gerente.verificaValidadeData(strAux2)){
                                        break;
                                    } else {
                                        system("cls");

                                        cout << "Data invalida. Tente novamente\n" << endl;
                                    }
                                }

                                gerente.setDataDeIngresso(strAux2);

                                arquivo.substituiLinha(gerente.atributosToString(), strAux1);

                                arquivo.substituiArquivo();

                                arquivo.scanArquivo();

                                system("cls");

                                gerente.imprimeRegistro();

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

                                system("cls");

                                gerente.imprimeRegistro();

                                break;
                            case 4:
                                system("cls");

                                strAux1 = gerente.getCodigo();

                                while(1){
                                    cout << "Informe o novo CEP" << endl;

                                    getline(cin, strAux2);

                                    if(strAux2.size() < 8 || strAux2.size() >
                                    8){
                                        system("cls");

                                        cout << "CEP invalido. Tente novamente" << endl;
                                        continue;
                                    }

                                    strAux2 = gerente.CEPtoEndereco(strAux2);

                                    if(strAux2 == "CEP nao encontrado. Tente novamente"){
                                        system("cls");

                                        cout << strAux2 << endl;
                                        continue;
                                    }

                                    break;
                                }

                                gerente.setEndereco(strAux2);

                                system("cls");

                                cout << "Qual o numero da nova residencia?" << endl;

                                getline(cin, strAux2);

                                gerente.setEndereco(gerente.getEndereco() + strAux2);

                                arquivo.substituiLinha(gerente.atributosToString(), strAux1);

                                arquivo.substituiArquivo();

                                arquivo.scanArquivo();

                                system("cls");

                                gerente.imprimeRegistro();

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

                                system("cls");

                                gerente.imprimeRegistro();

                                break;
                            case 6:
                                system("cls");

                                strAux1 = gerente.getCodigo();

                                m = 1;
                                while(m){
                                    cout << "Qual sera sua nova designacao?" << endl;

                                    cout << "Operador (1), diretor (2), presidente (3)" << endl;

                                    cin >> escolha1;
                                    getchar();

                                    switch(escolha1){
                                        case 1:
                                            system("cls");

                                            arquivo.substituiLinha(gerente.gerenteToOperador(), strAux1);

                                            arquivo.substituiArquivo();

                                            m = 0;

                                            system("cls");

                                            operador = arquivo.stringToOperador(i);

                                            operador.imprimeRegistro();

                                            operador = Operador();

                                            break;
                                        case 2:
                                            system("cls");

                                            arquivo.substituiLinha(gerente.gerenteToDiretor(), strAux1);

                                            arquivo.substituiArquivo();

                                            m = 0;

                                            diretor = arquivo.stringToDiretor(i);

                                            diretor.imprimeRegistro();

                                            diretor = Diretor();

                                            break;
                                        case 3:
                                            system("cls");

                                            arquivo.substituiLinha(gerente.gerenteToPresidente(), strAux1);

                                            arquivo.substituiArquivo();

                                            m = 0;

                                            presidente = arquivo.stringToPresidente(i);

                                            presidente.imprimeRegistro();

                                            presidente = Presidente();

                                            break;
                                        default:
                                            system("cls");

                                            cout << "Escolha invalida" << endl;
                                            continue;
                                    }
                                }

                                break;
                            case 7:
                                system("cls");

                                strAux1 = gerente.getCodigo();

                                cout << "Informe o novo salario" << endl;

                                getline(cin, strAux2);

                                gerente.setSalario(stof(strAux2));

                                arquivo.substituiLinha(gerente.atributosToString(), strAux1);

                                arquivo.substituiArquivo();

                                arquivo.scanArquivo();

                                system("cls");

                                gerente.imprimeRegistro();

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

                                system("cls");

                                gerente.imprimeRegistro();

                                break;
                            default: 
                                system("cls");

                                cout << "Escolha invalida" << endl;
                                continue;
                        }

                        cout << "\nDeseja editar mais algo?" << endl;
                        cout << "Sim (1), nao (2)" << endl;

                        cin >> escolha;
                        getchar();

                        if(escolha == 1){
                            if(arquivo.getDesignacao(i) == "Gerente"){
                                continue;
                            } else {
                                l = 0;
                                flag = 1;
                                escolha = 2;
                                arquivo.stringToCode(i);
                                numero = arquivo.linhaAux;
                            }
                        }   

                        j = 0;
                    }

                    gerente = Gerente();

                    l = 0;

                    break;
                } else if(arquivo.getDesignacao(i) == "Diretor"){
                    system("cls");

                    diretor = arquivo.stringToDiretor(i);

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

                                system("cls");

                                diretor.imprimeRegistro();

                                break;
                            case 2:
                                system("cls");

                                strAux1 = diretor.getCodigo();

                                while(1){
                                    cout << "Informe a nova data de ingresso" << endl;

                                    getline(cin, strAux2);

                                    if(diretor.verificaValidadeData(strAux2)){
                                        break;
                                    } else {
                                        system("cls");

                                        cout << "Data invalida. Tente novamente\n" << endl;
                                    }
                                }

                                diretor.setDataDeIngresso(strAux2);

                                arquivo.substituiLinha(diretor.atributosToString(), strAux1);

                                arquivo.substituiArquivo();

                                arquivo.scanArquivo();

                                system("cls");

                                diretor.imprimeRegistro();

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

                                system("cls");

                                diretor.imprimeRegistro();

                                break;
                            case 4:
                                system("cls");

                                strAux1 = diretor.getCodigo();

                                while(1){
                                    cout << "Informe o novo CEP" << endl;

                                    getline(cin, strAux2);

                                    if(strAux2.size() < 8 || strAux2.size() >
                                    8){
                                        system("cls");

                                        cout << "CEP invalido. Tente novamente" << endl;
                                        continue;
                                    }

                                    strAux2 = diretor.CEPtoEndereco(strAux2);

                                    if(strAux2 == "CEP nao encontrado. Tente novamente"){
                                        system("cls");

                                        cout << strAux2 << endl;
                                        continue;
                                    }

                                    break;
                                }

                                diretor.setEndereco(strAux2);

                                system("cls");

                                cout << "Qual o numero da nova residencia?" << endl;

                                getline(cin, strAux2);

                                diretor.setEndereco(diretor.getEndereco() + strAux2);

                                arquivo.substituiLinha(diretor.atributosToString(), strAux1);

                                arquivo.substituiArquivo();

                                arquivo.scanArquivo();

                                system("cls");

                                diretor.imprimeRegistro();

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

                                system("cls");

                                diretor.imprimeRegistro();

                                break;
                            case 6:
                                system("cls");

                                strAux1 = diretor.getCodigo();

                                m = 1;
                                while(m){
                                    cout << "Qual sera sua nova designacao?" << endl;

                                    cout << "Operador (1), gerente (2), presidente (3)" << endl;

                                    cin >> escolha1;
                                    getchar();

                                    switch(escolha1){
                                        case 1:
                                            system("cls");

                                            arquivo.substituiLinha(diretor.diretorToOperador(), strAux1);

                                            arquivo.substituiArquivo();

                                            m = 0;

                                            system("cls");

                                            operador = arquivo.stringToOperador(i);

                                            operador.imprimeRegistro();

                                            operador = Operador();

                                            break;
                                        case 2:
                                            system("cls");

                                            arquivo.substituiLinha(diretor.diretorToGerente(), strAux1);

                                            arquivo.substituiArquivo();

                                            m = 0;

                                            gerente = arquivo.stringToGerente(i);

                                            gerente.imprimeRegistro();

                                            gerente = Gerente();

                                            break;
                                        case 3:
                                            system("cls");

                                            arquivo.substituiLinha(diretor.diretorToPresidente(), strAux1);

                                            arquivo.substituiArquivo();

                                            m = 0;

                                            presidente = arquivo.stringToPresidente(i);

                                            presidente.imprimeRegistro();

                                            presidente = Presidente();

                                            break;
                                        default:
                                            system("cls");

                                            cout << "Escolha invalida" << endl;
                                            continue;
                                    }
                                }

                                break;
                            case 7:
                                system("cls");

                                strAux1 = diretor.getCodigo();

                                cout << "Informe o novo salario" << endl;

                                getline(cin, strAux2);

                                diretor.setSalario(stof(strAux2));

                                arquivo.substituiLinha(diretor.atributosToString(), strAux1);

                                arquivo.substituiArquivo();

                                arquivo.scanArquivo();

                                system("cls");

                                diretor.imprimeRegistro();

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

                                system("cls");

                                diretor.imprimeRegistro();

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

                                system("cls");
                                
                                diretor.imprimeRegistro();

                                break;
                            default: 
                                system("cls");

                                cout << "Escolha invalida" << endl;
                                continue;
                        }

                        cout << "\nDeseja editar mais algo?" << endl;
                        cout << "Sim (1), nao (2)" << endl;

                        cin >> escolha;
                        getchar();

                        if(escolha == 1){
                            if(arquivo.getDesignacao(i) == "Diretor"){
                                continue;
                            } else {
                                l = 0;
                                flag = 1;
                                escolha = 2;
                                arquivo.stringToCode(i);
                                numero = arquivo.linhaAux;
                            }
                        }   

                        j = 0;
                    }

                    diretor = Diretor();

                    l = 0;
                    
                    break;
                } else if(arquivo.getDesignacao(i) == "Presidente"){
                    system("cls");

                    presidente = arquivo.stringToPresidente(i);

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

                                system("cls");

                                presidente.imprimeRegistro();

                                break;
                            case 2:
                                system("cls");

                                strAux1 = presidente.getCodigo();

                                while(1){
                                    cout << "Informe a nova data de ingresso" << endl;

                                    getline(cin, strAux2);

                                    if(presidente.verificaValidadeData(strAux2)){
                                        break;
                                    } else {
                                        system("cls");

                                        cout << "Data invalida. Tente novamente\n" << endl;
                                    }
                                }

                                presidente.setDataDeIngresso(strAux2);

                                arquivo.substituiLinha(presidente.atributosToString(), strAux1);

                                arquivo.substituiArquivo();

                                arquivo.scanArquivo();

                                system("cls");

                                presidente.imprimeRegistro();

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

                                system("cls");

                                presidente.imprimeRegistro();

                                break;
                            case 4:
                                system("cls");

                                strAux1 = presidente.getCodigo();

                                while(1){
                                    cout << "Informe o novo CEP" << endl;

                                    getline(cin, strAux2);

                                    if(strAux2.size() < 8 || strAux2.size() >
                                    8){
                                        system("cls");

                                        cout << "CEP invalido. Tente novamente" << endl;
                                        continue;
                                    }

                                    strAux2 = presidente.CEPtoEndereco(strAux2);

                                    if(strAux2 == "CEP nao encontrado. Tente novamente"){
                                        system("cls");

                                        cout << strAux2 << endl;
                                        continue;
                                    }

                                    break;
                                }

                                presidente.setEndereco(strAux2);

                                system("cls");

                                cout << "Qual o numero da nova residencia?" << endl;

                                getline(cin, strAux2);

                                presidente.setEndereco(presidente.getEndereco() + strAux2);

                                arquivo.substituiLinha(presidente.atributosToString(), strAux1);

                                arquivo.substituiArquivo();

                                arquivo.scanArquivo();

                                system("cls");

                                presidente.imprimeRegistro();

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

                                system("cls");

                                presidente.imprimeRegistro();

                                break;
                            case 6:
                                system("cls");

                                strAux1 = presidente.getCodigo();

                                m = 1;
                                while(m){
                                    cout << "Qual sera sua nova designacao?" << endl;

                                    cout << "Operador (1), gerente (2), diretor (3)" << endl;

                                    cin >> escolha1;
                                    getchar();

                                    switch(escolha1){
                                        case 1:
                                            system("cls");

                                            arquivo.substituiLinha(presidente.presidenteToOperador(), strAux1);

                                            arquivo.substituiArquivo();

                                            m = 0;

                                            system("cls");

                                            operador = arquivo.stringToOperador(i);

                                            operador.imprimeRegistro();

                                            operador = Operador();

                                            break;
                                        case 2:
                                            system("cls");

                                            arquivo.substituiLinha(presidente.presidenteToGerente(), strAux1);

                                            arquivo.substituiArquivo();

                                            m = 0;

                                            gerente = arquivo.stringToGerente(i);

                                            gerente.imprimeRegistro();

                                            gerente = Gerente();

                                            break;
                                        case 3:
                                            system("cls");

                                            arquivo.substituiLinha(presidente.presidenteToDiretor(), strAux1);

                                            arquivo.substituiArquivo();

                                            m = 0;

                                            diretor = arquivo.stringToDiretor(i);

                                            diretor.imprimeRegistro();

                                            diretor = Diretor();

                                            break;
                                        default:
                                            system("cls");

                                            cout << "Escolha invalida" << endl;
                                            continue;
                                    }
                                }

                                break;
                            case 7:
                                system("cls");

                                strAux1 = presidente.getCodigo();

                                cout << "Informe o novo salario" << endl;

                                getline(cin, strAux2);

                                presidente.setSalario(stof(strAux2));

                                arquivo.substituiLinha(presidente.atributosToString(), strAux1);

                                arquivo.substituiArquivo();

                                arquivo.scanArquivo();
                                
                                system("cls");

                                presidente.imprimeRegistro();

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

                                system("cls");

                                presidente.imprimeRegistro();

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

                                system("cls");

                                presidente.imprimeRegistro();

                                break;
                            default: 
                                system("cls");

                                cout << "Escolha invalida" << endl;
                                continue;
                        }

                        cout << "\nDeseja editar mais algo?" << endl;
                        cout << "Sim (1), nao (2)" << endl;

                        cin >> escolha;
                        getchar();

                        if(escolha == 1){
                            if(arquivo.getDesignacao(i) == "Presidente"){
                                continue;
                            } else {
                                l = 0;
                                flag = 1;
                                escolha = 2;
                                arquivo.stringToCode(i);
                                numero = arquivo.linhaAux;
                            }
                        }   

                        j = 0;
                    }

                    presidente = Presidente();

                    l = 0;

                    break;
                }

            } else if(i == NUMERO_LINHAS-1){
                system("cls");

                cout << "Funcionario nao encontrado. Tente novamente\n" << endl;

                break;
            }
        }
    }
}

void Sistema::excluirRegistro(){
    system("cls");

    j = 1;
    while(j){           
        cout << "Digite o codigo do funcionario que deseja excluir" << endl;
        cout << "Sair(0)" << endl;

        getline(cin, numero);

        if(numero == "0"){
            j = 0;

            continue;
        }

        numero = arquivo.completaNumero(numero);

        count = count2 = count3 = 0;

        for(i = 0; i < NUMERO_LINHAS; i++){
            arquivo.stringToCode(i);

            if(numero == arquivo.linhaAux){  //codigo encontrado.
                if(arquivo.getDesignacao(i) == "Operador"){
                    system("cls");

                    operador = arquivo.stringToOperador(i);
                    operador.imprimeRegistro();
                    operador = Operador();
                    
                    m = 1;
                    while(m){
                        cout << "\nDeseja mesmo excluir esse funcionario?" << endl;
                        cout << "Sim (1) nao (2)" << endl;

                        cin >> escolha1;
                        getchar();

                        switch(escolha1){
                            case 1:
                                m = 0;

                                break;
                            case 2:
                                count3++;

                                count++;

                                m = 0;

                                j = 0;

                                cout << "\nPressione ENTER para voltar para o menu principal" << endl;

                                getchar();

                                break;
                            default:
                                continue;
                        }
                    } 

                    if(count3 != 0){
                        break;
                    }

                    arquivo.substituiLinha("", numero);
                    arquivo.substituiArquivo(); 

                    system("cls");

                    cout << "Funcionario excluido com sucesso!" << endl;

                    cout << "\nPressione ENTER para voltar para o menu principal" << endl;

                    getchar(); 

                    j = 0; 

                    count++;

                    break;
                } else if(arquivo.getDesignacao(i) == "Gerente"){
                    system("cls");

                    gerente = arquivo.stringToGerente(i);
                    gerente.imprimeRegistro();
                    gerente = Gerente();

                    m = 1;
                    while(m){
                        cout << "\nDeseja mesmo excluir esse funcionario?" << endl;
                        cout << "Sim (1) nao (2)" << endl;

                        cin >> escolha1;
                        getchar();

                        switch(escolha1){
                            case 1:
                                m = 0;

                                break;
                            case 2:
                                count3++;

                                count++;

                                m = 0;

                                j = 0;

                                cout << "\nPressione ENTER para voltar para o menu principal" << endl;

                                getchar();

                                break;
                            default:
                                continue;
                        }
                    }

                    if(count3 != 0){
                        break;
                    }

                    arquivo.substituiLinha("", numero);
                    arquivo.substituiArquivo();

                    system("cls");

                    cout << "Funcionario excluido com sucesso!" << endl;

                    cout << "\nPressione ENTER para voltar para o menu principal" << endl;

                    getchar(); 

                    j = 0;

                    count++;

                    break;
                } else if(arquivo.getDesignacao(i) == "Diretor" || arquivo.getDesignacao(i) == "Presidente"){
                    system("cls");

                    cout << "Nao e permitido excluir este funcionario, Ele eh um " << arquivo.getDesignacao(i) << "!" << endl;  
                    count2++; 

                    cout << "\nPressione ENTER para voltar para o menu principal" << endl;

                    getchar(); 

                    j = 0;

                    break;                                                                                            
                }

                count++;
                
                break;
            } else if(i == NUMERO_LINHAS-1){                                       
                system("cls");                                                      
                                        
                cout << "Funcionario nao encontrado. Tente novamente\n" << endl;
            }
        }

        if(count != 0 || count2 != 0){
            break;
        } else {                             //caso o codigo inserido nao seja encontrado, o programa informara por
            system("cls");                   //uma mensagem e retornara para o inicio da opçao de excluir registro.
                                                                            
            cout << "Funcionario nao encontrado. Tente novamente\n" << endl; 
        }
    }

    arquivo.scanArquivo();
}

void Sistema::exibirRegistro(){
    system("cls");

    l = 1;
    while(l){
        cout << "Informe o codigo do funcionario que deseja exibir o registro" << endl;
        cout << "Sair(0)" << endl;

        getline(cin, numero);

        if(numero == "0"){
            l = 0;

            continue;
        }
        
        numero = arquivo.completaNumero(numero);

        for(i = 0; i < NUMERO_LINHAS; i++){
            arquivo.stringToCode(i);

            if(arquivo.linhaAux == numero){
                strAux1 = arquivo.getDesignacao(i);

                if(strAux1 == "Operador"){
                    system("cls");

                    operador = arquivo.stringToOperador(i);
                    operador.imprimeRegistro();
                    operador = Operador();

                    break;
                } else if(strAux1 == "Gerente"){
                    system("cls");

                    gerente = arquivo.stringToGerente(i);
                    gerente.imprimeRegistro();
                    gerente = Gerente();

                    break;
                } else if(strAux1 == "Diretor"){
                    system("cls");

                    diretor = arquivo.stringToDiretor(i);
                    diretor.imprimeRegistro();
                    diretor = Diretor();

                    break;
                } else if(strAux1 == "Presidente"){
                    system("cls");

                    presidente = arquivo.stringToPresidente(i);
                    presidente.imprimeRegistro();
                    presidente = Presidente();

                    break;
                }
            } else if(i == NUMERO_LINHAS-1){
                system("cls");

                cout << "Funcionario nao encontrado, Tente novamente" << endl;
            }
        }

        cout << "\nDeseja exibir outro registro (1) ou voltar para o menu principal (2)?" << endl;

        cin >> escolha;
        getchar();

        switch(escolha){
            case 1:
                system("cls");

                continue;
                break;
            case 2:
                l = 0; 

                break;
            default:
                l = 0;
        }
    }
}

void Sistema::listaDeFuncionarios(){
    system("cls");

    m = 1;
    while(m){
        system("cls");
        
        cout << "Deseja filtrar a lista de funcionarios por tipo?" << endl;
        cout << "(1)Sim (2)Nao" << endl;

        cin >> escolha;
        getchar();

        switch(escolha){
        case 1:
            system("cls");
            
            j = 1;
            while(j){
                cout << "Qual o tipo dos funcionarios a serem filtrados?" << endl;
                cout << "(1)Operador (2)Gerente (3)Diretor (4)Presidente" << endl;
                cin >> escolha1;
                getchar();

                switch(escolha1){
                    case 1:
                        system("cls");

                        cout << "Operadores:" << endl;

                        for(i = 0; i < NUMERO_LINHAS; i++){
                            if(arquivo.linhas[i] == "#"){
                                break;
                            }

                            if(arquivo.getDesignacao(i) == "Operador"){
                                arquivo.stringToCode(i);
                                cout << "Codigo: " << arquivo.linhaAux << " - ";

                                arquivo.stringToNome(i);
                                cout << "Nome: " << arquivo.linhaAux << endl;
                            }
                        }

                        cout << "\nPressione ENTER para voltar para o menu principal" << endl;
                        getchar();

                        m = 0;

                        j = 0;
                    
                        break;
                    case 2:
                        system("cls");

                        cout << "Gerentes:" << endl;

                        for(i = 0; i < NUMERO_LINHAS; i++){
                            if(arquivo.linhas[i] == "#"){
                                break;
                            }

                            if(arquivo.getDesignacao(i) == "Gerente"){
                                arquivo.stringToCode(i);
                                cout << "Codigo: " << arquivo.linhaAux << " - ";

                                arquivo.stringToNome(i);
                                cout << "Nome: " << arquivo.linhaAux << endl;
                            }
                        }

                        cout << "\nPressione ENTER para voltar para o menu principal" << endl;
                        getchar();

                        m = 0;

                        j = 0;
                    
                        break;
                    case 3:
                        system("cls");

                        cout << "Diretores:" << endl;

                        for(i = 0; i < NUMERO_LINHAS; i++){
                            if(arquivo.linhas[i] == "#"){
                                break;
                            }

                            if(arquivo.getDesignacao(i) == "Diretor"){
                                arquivo.stringToCode(i);
                                cout << "Codigo: " << arquivo.linhaAux << " - ";

                                arquivo.stringToNome(i);
                                cout << "Nome: " << arquivo.linhaAux << endl;
                            }
                        }

                        cout << "\nPressione ENTER para voltar para o menu principal" << endl;
                        getchar();

                        m = 0;

                        j = 0;
                    
                        break;
                    case 4:
                        system("cls");

                        cout << "Presidentes:" << endl;

                        for(i = 0; i < NUMERO_LINHAS; i++){
                            if(arquivo.linhas[i] == "#"){
                                break;
                            }

                            if(arquivo.getDesignacao(i) == "Presidente"){
                                arquivo.stringToCode(i);
                                cout << "Codigo: " << arquivo.linhaAux << " - ";

                                arquivo.stringToNome(i);
                                cout << "Nome: " << arquivo.linhaAux << endl;
                            }
                        }

                        cout << "\nPressione ENTER para voltar para o menu principal" << endl;
                        getchar();

                        m = 0;

                        j = 0;
                    
                        break;
                    default:
                    system("cls");

                    cout << "Opcao invalida! Digite novamente." << endl;
                }
            }

            break;
        case 2:
            system("cls");

            for(i = 0; i < NUMERO_LINHAS; i++){
                if(arquivo.linhas[i] == "#"){
                    break;
                }

                arquivo.stringToCode(i);
                cout << "Codigo: " << arquivo.linhaAux << " - ";

                arquivo.stringToNome(i);
                cout << "Nome: " << arquivo.linhaAux << " - ";

                cout << "Designacao: " << arquivo.getDesignacao(i) << endl;
            }

            cout << "\nPressione ENTER para voltar para o menu principal" << endl;
            getchar();

            m = 0;
            
            break;
        default:
            system("cls");

            cout << "Opcao invalida! Digite novamente." << endl;
        }
    }
}

void Sistema::concederAumento(){
    system("cls");

    m = 1;
    while(m){
        count = 0;

        cout << "Deseja rodar a rotina de aumento?" << endl;
        cout << "Sim (1) nao(2)" << endl;

        cin >> escolha;
        getchar();

        switch(escolha){
            case 1:
                m = 0;
                break;
            case 2:
                m = 0;

                count++;

                break;
            default:
            system("cls");
        }
    }

    if(count != 0){
        return;
    } else {
        for(i = 0; i < NUMERO_LINHAS; i++){
            if(arquivo.linhas[i] == "#"){
                break;
            }

            if(arquivo.getDesignacao(i) == "Operador"){
                operador = arquivo.stringToOperador(i);
                operador.aumentaSalario();
                arquivo.substituiLinha(operador.atributosToString(), operador.getCodigo());

                operador = Operador();
            } else if(arquivo.getDesignacao(i) == "Gerente"){
                gerente = arquivo.stringToGerente(i);
                gerente.aumentaSalario();
                arquivo.substituiLinha(gerente.atributosToString(), gerente.getCodigo());

                gerente = Gerente();
            } else if(arquivo.getDesignacao(i) == "Diretor"){
                diretor = arquivo.stringToDiretor(i);
                diretor.aumentaSalario();
                arquivo.substituiLinha(diretor.atributosToString(), diretor.getCodigo());

                diretor = Diretor();
            } else if(arquivo.getDesignacao(i) == "Presidente"){
                presidente = arquivo.stringToPresidente(i);
                presidente.aumentaSalario();
                arquivo.substituiLinha(presidente.atributosToString(), presidente.getCodigo());

                presidente = Presidente();
            }
        }

        arquivo.substituiArquivo();
    }

    system("cls");

    cout << "Aumento concedido com sucesso!" << endl;
    cout << "\nPressione ENTER para voltar para o menu principal" << endl;

    getchar();
}

void Sistema::calcularFolhaSalarial(){
    count2 = 0;

    system("cls");

    cout << "Deseja calcular a folha salarial referente a qual mes?" << endl;
    
    j = 1;
    while(j){
        cout << "\nJaneiro(01), Fevereiro(02), Marco(03), Abril(04)" << endl;
        cout << "Maio(05), Junho(06), Julho(07), Agosto(08)" << endl;
        cout << "Setembro(09), Outubro(10), Novembro(11), Dezembro(12)" << endl;
        cout << "Sair(0)" << endl;

        cin >> escolha;
        getchar();

        switch(escolha){
            case 1:
                mes = "Janeiro";
                j = 0;
                break;
            case 2:
                if(arquivo.verificaCalculoFolha("Janeiro")){
                    mes = "Fevereiro";
                    j = 0;
                    break;
                } else {
                    system("cls");

                    cout << "Para calcular a folha de Fevereiro deve ser calculada antes a folha de Janeiro" << endl;

                    break;
                }
            case 3:
                if(arquivo.verificaCalculoFolha("Fevereiro")){
                    mes = "Marco";
                    j = 0;
                    break;
                } else {
                    system("cls");

                    cout << "Para calcular a folha de Marco deve ser calculada antes a folha de Fevereiro" << endl;

                    break;
                }
            case 4:
                if(arquivo.verificaCalculoFolha("Marco")){
                    mes = "Abril";
                    j = 0;
                    break;
                } else {
                    system("cls");

                    cout << "Para calcular a folha de Abril deve ser calculada antes a folha de Marco" << endl;

                    break;
                }
            case 5:
                if(arquivo.verificaCalculoFolha("Abril")){
                    mes = "Maio";
                    j = 0;
                    break;
                } else {
                    system("cls");

                    cout << "Para calcular a folha de Maio deve ser calculada antes a folha de Abril" << endl;

                    break;
                }
            case 6:
                if(arquivo.verificaCalculoFolha("Maio")){
                    mes = "Junho";
                    j = 0;
                    break;
                } else {
                    system("cls");

                    cout << "Para calcular a folha de Junho deve ser calculada antes a folha de Maio" << endl;

                    break;
                }
            case 7:
                if(arquivo.verificaCalculoFolha("Junho")){
                    mes = "Julho";
                    j = 0;
                    break;
                } else {
                    system("cls");

                    cout << "Para calcular a folha de Julho deve ser calculada antes a folha de Junho" << endl;

                    break;
                }
            case 8:
                if(arquivo.verificaCalculoFolha("Julho")){
                    mes = "Agosto";
                    j = 0;
                    break;
                } else {
                    system("cls");

                    cout << "Para calcular a folha de Agosto deve ser calculada antes a folha de Julho" << endl;

                    break;
                }
            case 9:
                if(arquivo.verificaCalculoFolha("Agosto")){
                    mes = "Setembro";
                    j = 0;
                    break;
                } else {
                    system("cls");

                    cout << "Para calcular a folha de Setembro deve ser calculada antes a folha de Agosto" << endl;

                    break;
                }
            case 10:
                if(arquivo.verificaCalculoFolha("Setembro")){
                    mes = "Outubro";
                    j = 0;
                    break;
                } else {
                    system("cls");

                    cout << "Para calcular a folha de Outubro deve ser calculada antes a folha de Setembro" << endl;

                    break;
                }
            case 11:
                if(arquivo.verificaCalculoFolha("Outubro")){
                    mes = "Novembro";
                    j = 0;
                    break;
                } else {
                    system("cls");

                    cout << "Para calcular a folha de Novembro deve ser calculada antes a folha de Outubro" << endl;

                    break;
                }
            case 12:
                if(arquivo.verificaCalculoFolha("Novembro")){
                    mes = "Dezembro";
                    j = 0;
                    break;
                } else {
                    system("cls");

                    cout << "Para calcular a folha de Dezembro deve ser calculada antes a folha de Novembro" << endl;

                    break;
                }
            case 0:
                j = 0;

                count2++;

                break;
            default:
                system("cls");

                cout << "Escolha invalida! Tente novamente" << endl;
        }
    }

    if(count2 != 0){
        return;
    }

    if(arquivo.verificaCalculoFolha(mes)){
        system("cls");

        cout << "A folha para esse mes ja foi calculada!" << endl;

        cout << "\nPressiona ENTER para voltar para o menu principal" << endl;

        getchar();

        return;
    } else {
        for(i = 0; i < NUMERO_LINHAS; i++){
            if(arquivo.linhas[i] == ""){
                arquivo.linhas[i] = "\\" + mes + "\\";

                m = i + 1;

                break;
            }
        }

        count = 0;
        somaSalarios = 0;

        for(i = 0, j = m; i < NUMERO_LINHAS; i++, j++){
            if(arquivo.linhas[i] != "#"){
                count++;


                if(arquivo.getDesignacao(i) == "Operador"){
                    operador = arquivo.stringToOperador(i);

                    arquivo.linhas[j] = operador.calculaFolhaSalarial(i);

                    somaSalarios += operador.getSalarioLiquido();

                    operador = Operador();
                } else if(arquivo.getDesignacao(i) == "Gerente"){
                    gerente = arquivo.stringToGerente(i);

                    arquivo.linhas[j] = gerente.calculaFolhaSalarial(i);

                    somaSalarios += gerente.getSalarioLiquido();

                    gerente = Gerente();
                } else if(arquivo.getDesignacao(i) == "Diretor"){
                    diretor = arquivo.stringToDiretor(i);

                    arquivo.linhas[j] = diretor.calculaFolhaSalarial(i);

                    somaSalarios += diretor.getSalarioLiquido();

                    diretor = Diretor();
                } else if(arquivo.getDesignacao(i) == "Presidente"){
                    presidente = arquivo.stringToPresidente(i);

                    arquivo.linhas[j] = presidente.calculaFolhaSalarial(i);

                    somaSalarios += presidente.getSalarioLiquido();

                    presidente = Presidente();
                }
            } else {
                try{
                    strAux1 = to_string(somaSalarios).erase(to_string(somaSalarios).size()-4, 4);
                    strAux2 = to_string(somaSalarios/count).erase(to_string(somaSalarios/count).size()-4, 4);

                    arquivo.linhas[j] = "++++ - " + strAux1 + " - " + to_string(count) + " - " + strAux2;
                    arquivo.linhas[j+1] = "/" + mes + "/";
                } catch(exception out_of_range){
                    system("cls");

                    arquivo.linhas[m-1] = "";

                    cout << "Nao existe nenhum funcionario para calcular a folha!" << endl;

                    cout << "\nPressione ENTER para voltar para o menu principal" << endl;

                    getchar();
                }
                
                break;
            }
        }
        
        arquivo.substituiArquivo();
    }
}

void Sistema::consultarFolhaFuncionario(){
    system("cls");

    count = 0;

    j = 1;
    while(j){
        cout << "Deseja exibir a folha salarial do funcionario para qual mes?" << endl;
        cout << "\nJaneiro(01), Fevereiro(02), Marco(03), Abril(04)" << endl;
        cout << "Maio(05), Junho(06), Julho(07), Agosto(08)" << endl;
        cout << "Setembro(09), Outubro(10), Novembro(11), Dezembro(12)" << endl;
        cout << "Sair(0)" << endl;

        cin >> escolha;
        getchar();

        switch(escolha){
            case 1:
                mes = "Janeiro";
                j = 0;
                break;
            case 2:
                mes = "Fevereiro";
                j = 0;
                break;
            case 3:
                mes = "Marco";
                j = 0;
                break;
            case 4:
                mes = "Abril";
                j = 0;
                break;
            case 5:
                mes = "Maio";
                j = 0;
                break;
            case 6:
                mes = "Junho";
                j = 0;
                break;
            case 7:
                mes = "Julho";
                j = 0;
                break;
            case 8:
                mes = "Agosto";
                j = 0;
                break;
            case 9:
                mes = "Setembro";
                j = 0;
                break;
            case 10:
                mes = "Outubro";
                j = 0;
                break;
            case 11:
                mes = "Novembro";
                j = 0;
                break;
            case 12:
                mes = "Dezembro";
                j = 0;
                break;
            case 0:
                j = 0;

                count++;

                break;
            default:
                system("cls");

                cout << "Escolha invalida. Tente novamente" << endl;
        }
    }

    if(count != 0){
        return;
    }

    if(!arquivo.verificaCalculoFolha(mes)){
        system("cls");

        cout << "A folha para " << mes << " ainda nao foi calculada!" << endl;
        cout << "\nPressione ENTER para voltar para o menu principal" << endl;

        getchar();

        return;
    }

    system("cls");
    
    j = 1;
    while(j){
        count = 0;

        cout << "Inserir o codigo (1) ou o nome (2) do funcionario que deseja exibir a folha salarial?" << endl;
        cout << "Voltar para o menu (0)" << endl;
        
        cin >> escolha;
        getchar();

        switch(escolha){
            case 1:
                system("cls");

                cout << "Informe o codigo do funcionario" << endl;

                getline(cin, numero);
                numero = arquivo.completaNumero(numero);

                for(i = 0; i < NUMERO_LINHAS; i++){
                    if(arquivo.linhas[i] == "\\" + mes + "\\"){
                        l = i + 1;
                        break;
                    }
                }

                for(i = l; i < NUMERO_LINHAS; i++){
                    arquivo.stringToCode(i);

                    if(arquivo.linhaAux == numero){
                        system("cls");

                        count++;

                        arquivo.imprimeFolhaFuncionario(i);
                        break;
                    }
                }

                if(count == 0){
                    system("cls");

                    cout << "Funcionario nao encontrado" << endl;
                }
                
                cout << "Deseja exibir outro registro (1) ou voltar para o menu (2)?" << endl;

                cin >> escolha;
                getchar();

                switch(escolha){
                    case 1:
                        system("cls");
                        j = 1;
                        break;
                    case 2:
                    default:
                        j = 0;
                        
                }

                break;
            case 2:
                system("cls");

                cout << "Informe o nome do funcionario" << endl;

                getline(cin, nome);

                for(i = 0; i < NUMERO_LINHAS; i++){
                    if(arquivo.linhas[i] == "\\" + mes + "\\"){
                        l = i + 1;
                        break;
                    }
                }

                for(i = l; i < NUMERO_LINHAS; i++){
                    arquivo.stringToNome(i);

                    if(arquivo.linhaAux == nome){
                        system("cls");

                        count++;

                        arquivo.imprimeFolhaFuncionario(i);
                        break;
                    }
                }

                if(count == 0){
                    system("cls");

                    cout << "Funcionario nao encontrado" << endl;
                }
                
                cout << "Deseja exibir outro registro (1) ou voltar para o menu (2)?" << endl;

                cin >> escolha;
                getchar();

                switch(escolha){
                    case 1:
                        system("cls");
                        j = 1;
                        break;
                    case 2:
                    default:
                        j = 0;
                        
                }

                break;
            case 0:
                j = 0;
                break;
            default:
                system("cls");

                cout << "Escolha invalida. Tente novamente" << endl;
        }
    }
}

void Sistema::consultarFolhaEmpresa(){
    system("cls");

    j= 1;
    while(j){
        cout << "Deseja exibir a folha salarial mensal ou anual da empresa?" << endl;
        cout << "Mensal(1) anual(2)" << endl;
        cout << "Sair(0)" << endl;

        cin >> escolha;
        getchar();

        switch(escolha){
        case 1:
            system("cls");

            j = 0;
            cout << "Para qual mes deseja exibir a folha salarial da empresa?" << endl;
            cout << "\nJaneiro(01), Fevereiro(02), Marco(03), Abril(04)" << endl;
            cout << "Maio(05), Junho(06), Julho(07), Agosto(08)" << endl;
            cout << "Setembro(09), Outubro(10), Novembro(11), Dezembro(12)" << endl;
            cout << "Sair(0)" << endl;

            cin >> escolha;
            getchar();

            i = 1;
            while(i){
                switch(escolha){
                    case 1:
                        mes = "Janeiro";
                        i = 0;
                        break;
                    case 2:
                        mes = "Fevereiro";
                        i = 0;
                        break;
                    case 3:
                        mes = "Marco";
                        i = 0;
                        break;
                    case 4:
                        mes = "Abril";
                        i = 0;
                        break;
                    case 5:
                        mes = "Maio";
                        i = 0;
                        break;
                    case 6:
                        mes = "Junho";
                        i = 0;
                        break;
                    case 7:
                        mes = "Julho";
                        i = 0;
                        break;
                    case 8:
                        mes = "Agosto";
                        i = 0;
                        break;
                    case 9:
                        mes = "Setembro";
                        i = 0;
                        break;
                    case 10:
                        mes = "Outubro";
                        i = 0;
                        break;
                    case 11:
                        mes = "Novembro";
                        i = 0;
                        break;
                    case 12:
                        mes = "Dezembro";
                        i = 0;
                        break;
                    case 0:
                        i = 0;
                        count++;

                        break;
                    default:
                        system("cls");

                        cout << "Escolha invalida. Tente novamente" << endl;
                }
            }

            if(!arquivo.verificaCalculoFolha(mes)){
                system("cls");
                
                cout << "A folha para " << mes << " ainda nao foi calculada!" << endl;
                cout << "\nPressione ENTER para voltar para o menu principal" << endl;
                getchar();

            } else {
                system("cls");

                for(i = 0; i < NUMERO_LINHAS; i++){
                    if(arquivo.linhas[i] == "\\" + mes + "\\"){
                        for(j = i; j < NUMERO_LINHAS; j++){
                            arquivo.stringToCode(j);

                            if(arquivo.linhaAux == "++++"){
                                cout << mes << ":" << endl;

                                arquivo.percorrerString(j, 1);
                                cout << "Total a pagar: " << arquivo.linhaAux << endl;

                                arquivo.percorrerString(j, 2);
                                cout << "Total de servidores: " << arquivo.linhaAux << endl;

                                arquivo.percorrerString(j, 3);
                                cout << "Media de salarios: " << arquivo.linhaAux << endl;

                                i = NUMERO_LINHAS;

                                break;
                            }
                        }
                    }
                }

                cout << "\nPressione ENTER para voltar para o menu principal" << endl;

                getchar();

                j = 0;
            }
            
            break;
        case 2:
            if(!arquivo.verificaCalculoFolha("Dezembro")){
                system("cls");
                
                cout << "Nao foi possivel calcular a folha anual da empresa!" << endl;
                cout << "A folha para Dezembro ainda nao foi calculada!" << endl;

                j = 0;
            
            } else {
                float somaSalarios = 0;

                i = 0;
                while(arquivo.linhas[i] != "/Dezembro/"){
                    arquivo.stringToCode(i);

                    if(arquivo.linhaAux == "++++"){
                        arquivo.percorrerString(i, 1);

                        somaSalarios += stof(arquivo.linhaAux);
                    }

                    i++;
                }

                system("cls");

                cout << "Total pago no ano: " << somaSalarios << endl;
                cout << "Media paga por mes: " << somaSalarios/12 << endl;
            }

            cout << "\nPressione ENTER para voltar para o menu principal" << endl;

            getchar();

            j = 0;

            break;
        case 0:
            j = 0;
            count++;
            
            break;
        default:
            system("cls");
            
            cout << "Escolha invalida. Tente novamente" << endl;
        }
    }
}

void Sistema::limparRegistroDasFolhas(){
    system("cls");

    j = 1;
    while(j){
        cout << "Deseja mesmo limpar os registros das folhas salariais?" << endl;
        cout << "Sim(1) nao(2)" << endl;

        cin >> escolha;
        getchar();
        
        switch(escolha){
            case 1:
                arquivo.limpaFolhas();
                arquivo.substituiArquivo();
                
                system("cls");
                cout << "Registro de folhas limpo!" << endl;
                cout << "\nPressione ENTER para voltar para o menu principal" << endl;

                j = 0;

                getchar();

                break;
            case 2:
                j = 0;

                break;
            default:
                system("cls");
        }
    }
}

void Sistema::buscarFuncionario(){
    system("cls");

    j = 1;
    while(j){
        cout << "Deseja buscar o funcionario pelo nome, pela data de ingresso ou endereco?" << endl;
        cout << "Nome(1) data(2) endereco(3)" << endl;
        cout << "Sair(0)" << endl;

        cin >> escolha;
        getchar();

        switch(escolha){
            case 1:
                count = 0;

                system("cls");

                cout << "Digite o nome do funcionario" << endl;

                getline(cin, nome);

                for(i = 0; i < NUMERO_LINHAS; i++){
                    arquivo.stringToNome(i);

                    if(arquivo.linhaAux == nome){
                        count++;

                        strAux1 = arquivo.getDesignacao(i);

                        if(strAux1 == "Operador"){
                            system("cls");

                            operador = arquivo.stringToOperador(i);
                            operador.imprimeRegistro();
                            operador = Operador();

                            break;
                        } else if(strAux1 == "Gerente"){
                            system("cls");

                            gerente = arquivo.stringToGerente(i);
                            gerente.imprimeRegistro();
                            gerente = Gerente();

                            break;
                        } else if(strAux1 == "Diretor"){
                            system("cls");

                            diretor = arquivo.stringToDiretor(i);
                            diretor.imprimeRegistro();
                            diretor = Diretor();

                            break;
                        } else if(strAux1 == "Presidente"){
                            system("cls");

                            presidente = arquivo.stringToPresidente(i);
                            presidente.imprimeRegistro();
                            presidente = Presidente();

                            break;
                        }
                    }
                }

                if(count == 0){
                    system("cls");

                    cout << "Funcionario nao encontrado" << endl;
                }

                cout << "\nPressione ENTER para voltar para o menu principal" << endl;

                getchar();

                j = 0;

                break;
            case 2:
                count = 0;

                system("cls");

                while(1){
                    cout << "Informe uma data __/__/__" << endl;
                    getline(cin, strAux1);
                    system("cls");

                    if(operador.verificaValidadeData(strAux1)){
                        break;
                    } else {
                        cout << "Data invalida. Tente novamente\n" << endl;
                    }
                }

                system("cls");

                while(1){
                    cout << "Informe outra data __/__/__" << endl;
                    getline(cin, strAux2);
                    system("cls");

                    if(operador.verificaValidadeData(strAux2)){
                        break;
                    } else {
                        cout << "Data invalida. Tente novamente\n" << endl;
                    }
                }

                system("cls");

                for(i = 0; i < NUMERO_LINHAS; i++){
                    if(arquivo.linhas[i] == "#"){
                        break;
                    }

                    arquivo.stringToDataIngresso(i);

                    if(verificaIntervaloDatas(strAux1, strAux2, arquivo.linhaAux)){
                        designacao = arquivo.getDesignacao(i);

                        count++;

                        if(designacao == "Operador"){
                            operador = arquivo.stringToOperador(i);
                            operador.imprimeRegistro();
                            operador = Operador();

                            cout << "\n";
                        } else if(designacao == "Gerente"){
                            gerente = arquivo.stringToGerente(i);
                            gerente.imprimeRegistro();
                            gerente = Gerente();

                            cout << "\n";
                        } else if(designacao == "Diretor"){
                            diretor = arquivo.stringToDiretor(i);
                            diretor.imprimeRegistro();
                            diretor = Diretor();

                            cout << "\n";
                        } else if(designacao == "Presidente"){
                            presidente = arquivo.stringToPresidente(i);
                            presidente.imprimeRegistro();
                            presidente = Presidente();

                            cout << "\n";
                        }
                    }
                }

                if(count != 0){
                    cout << count << " funcionario(s) encontrado(s) entre as datas " << strAux1 << " e " << strAux2 << endl;
                }

                if(count == 0){
                    system("cls");

                    cout << "Nenhum funcionario foi encontrado" << endl;
                }

                cout << "\nPressione ENTER para voltar para o menu principal" << endl;

                getchar();

                j = 0;

                break;
            case 3:
                count = 0;

                system("cls");

                while(1){
                    cout << "Informe o CEP" << endl;

                    getline(cin, strAux2);

                    if(strAux2.size() < 8 || strAux2.size() >
                        8){
                        system("cls");

                        cout << "CEP invalido. Tente novamente" << endl;
                        continue;
                    }

                    strAux2 = operador.CEPtoEndereco(strAux2);

                    if(strAux2 == "CEP nao encontrado. Tente novamente"){
                        system("cls");

                        cout << strAux2 << endl;
                        continue;
                    }

                    break;
                }

                system("cls");

                cout << "Informe o numero da residencia" << endl;

                getline(cin, numero);

                strAux2 += numero;

                system("cls");

                for(i = 0; i < NUMERO_LINHAS; i++){
                    if(arquivo.linhas[i] == "#"){
                        break;
                    }

                    arquivo.stringToEndereco(i);

                    if(arquivo.linhaAux == strAux2){
                        count++;

                        designacao = arquivo.getDesignacao(i);

                        if(designacao == "Operador"){
                            operador = arquivo.stringToOperador(i);
                            operador.imprimeRegistro();
                            operador = Operador();

                            cout << "\n";
                        } else if(designacao == "Gerente"){
                            gerente = arquivo.stringToGerente(i);
                            gerente.imprimeRegistro();
                            gerente = Gerente();

                            cout << "\n";
                        } else if(designacao == "Diretor"){
                            diretor = arquivo.stringToDiretor(i);
                            diretor.imprimeRegistro();
                            diretor = Diretor();

                            cout << "\n";
                        } else if(designacao == "Presidente"){
                            presidente = arquivo.stringToPresidente(i);
                            presidente.imprimeRegistro();
                            presidente = Presidente();

                            cout << "\n";
                        }
                    }
                }

                if(count == 0){
                    system("cls");

                    cout << "Nenhum funcionario encontrado" << endl;
                }

                cout << "Pressione ENTER para voltar para o menu principal" << endl;

                getchar();

                j = 0;

                break;
            case 0:
                j = 0;

                break;
            default:
                system("cls");

                cout << "Opcao invalida! Tente novamente" << endl;
        }
    }
}

void Sistema::finalizarSistema(){
    system("cls");

    cout << "--------------------------" << endl;
    cout << "    Sistema finalizado" << endl;
    cout << "--------------------------\n" << endl;

    k = 0;
}

bool Sistema::verificaIntervaloDatas(string data1, string data2, string dataRef){
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

void Sistema::rodarSistema(){
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
                adicionarFuncionario();

                break;
            case 2: //editar atributos 
                editarAtributo();
                
                break;
            case 3: //excluir registro
                excluirRegistro();

                break;
            case 4: //exibir um registro
                exibirRegistro();
                
                break;
            case 5: //exibe lista de funcionarios
                listaDeFuncionarios();
            
                break;
            case 6:  //conceder aumento
                concederAumento();

                break;
            case 7:  //calcular folha salarial
                calcularFolhaSalarial();

                break;
            case 8:  //consultar folha salarial de um funcionario
                consultarFolhaFuncionario();
                
                break;
            case 9:     //consultar folha salarial da empresa
                consultarFolhaEmpresa();

                break;
            case 10: //limpar registro das folhas
                limparRegistroDasFolhas();

                break;
            case 11:  //buscar funcionario
                buscarFuncionario();

                break;
            case 0:  //sair do sistema
                finalizarSistema();
                
                break;
        }
    }

    return;
}