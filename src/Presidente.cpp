#include "Presidente.h"

Presidente::Presidente() : Funcionario("Presidente"){
    codigo = "vazio";
    nome = "vazio";
    endereco = "vazio";
    telefone = "vazio";
    dataDeIngresso = "vazio";
    salario = 0;
    dataAniversario = "vazio";
}

void Presidente::setDesignacao(){
    designacao = "Presidente";
}

void Presidente::setAreaDeFormacao(string str){
    areaDeFormacao = str;
}

string Presidente::getAreaDeFormacao(){
    return areaDeFormacao;
}

void Presidente::setFormacaoMaxima(string str){
    formacaoMaxima = str;
}

string Presidente::getFormacaoMaxima(){
    return formacaoMaxima;
}

void Presidente::getAtributos(string codigo){
    string CEP, numero;

    this->codigo = codigo;

    cout << "Qual o nome do funcionario?" << endl;
    getline(cin, nome);
    system("cls");

    cout << "Qual o CEP do funcionario?" << endl;
    
    while(1){
        getline(cin, CEP);

        if(CEP.size() < 8 || CEP.size() > 8){
            system("cls");
            cout << "CEP invalido. Tente novamente" << endl;
            continue;
        }

        endereco = CEPtoEndereco(CEP);

        if(endereco == "CEP nao encontrado. Tente novamente"){
            cout << endereco << endl;
            continue;
        }

        system("cls");

        cout << "Qual o numero da residencia do funcionario?" << endl;
        getline(cin, numero);
        endereco += numero;

        system("cls");

        break;
    }

    cout << "Qual o telefone do funcionario?" << endl;
    getline(cin, telefone);
    system("cls");

    while(1){
        cout << "Qual a data de ingresso do funcionario? __/__/__" << endl;
        getline(cin, dataDeIngresso);
        system("cls");

        if(verificaValidadeData(dataDeIngresso)){
            break;
        } else {
            cout << "Data invalida. Tente novamente\n" << endl;
        }
    }

    cout << "Qual sera o seu salario inicial?" << endl;
    cin >> salario;
    getchar();
    system("cls");

    while(1){
        cout << "Qual a data de aniversario do funcionario? __/__" << endl;
        getline(cin, dataAniversario);
        system("cls");

        if(verificaValidadeDataAniversario(dataAniversario)){
            break;
        } else {
            cout << "Data invalida. Tente novamente\n" << endl;
        }
    }

    cout << "Qual eh a sua area de formacao?" << endl;
    getline(cin, areaDeFormacao);
    system("cls");

    cout << "Qual a sua formacao academica maxima?" << endl;
    getline(cin, formacaoMaxima);
    system("cls");
}

string Presidente::atributosToString(){
    return codigo + " - " + nome + " - " + endereco + " - " + telefone + " - " + dataDeIngresso + " - " + designacao + " - " + to_string(salario).erase(to_string(salario).size()-4, 4) + " - " + dataAniversario + " - " + areaDeFormacao + " - " + formacaoMaxima;
}

void Presidente::imprimeRegistro(){
    cout << "Codigo: " << codigo << endl;
    cout << "Nome: " << nome << endl;
    cout << "Endereco: " << endereco << endl;
    cout << "Telefone: " << telefone << endl;
    cout << "Data de ingresso: " << dataDeIngresso << endl;
    cout << "Designacao: " << designacao << endl;
    cout << "Salario: " << salario << endl;
    cout << "Aniversario: " << dataAniversario << endl;
    cout << "Area de formacao: " << areaDeFormacao << endl;
    cout << "Formacao academica maxima: " << formacaoMaxima << endl;
}

string Presidente::presidenteToOperador(){
    string str;

    Operador operador;

    operador.setCodigo(getCodigo());
    operador.setNome(getNome());
    operador.setEndereco(getEndereco());
    operador.setTelefone(getTelefone());
    operador.setDataDeIngresso(getDataDeIngresso());
    operador.setSalario(getSalario());
    operador.setDataAniversario(getDataAniversario());

    return operador.atributosToString();
}

string Presidente::presidenteToGerente(){
    string str;

    Gerente gerente;

    gerente.setCodigo(getCodigo());
    gerente.setNome(getNome());
    gerente.setEndereco(getEndereco());
    gerente.setTelefone(getTelefone());
    gerente.setDataDeIngresso(getDataDeIngresso());
    gerente.setSalario(getSalario());
    gerente.setDataAniversario(getDataAniversario());
    
    cout << "Qual sera a area de supervisao?" << endl;

    getline(cin, str);
    gerente.setAreaSupervisao(str);

    return gerente.atributosToString();
}

string Presidente::presidenteToDiretor(){
    string str;

    Diretor diretor;

    diretor.setCodigo(getCodigo());
    diretor.setNome(getNome());
    diretor.setEndereco(getEndereco());
    diretor.setTelefone(getTelefone());
    diretor.setDataDeIngresso(getDataDeIngresso());
    diretor.setSalario(getSalario());
    diretor.setDataAniversario(getDataAniversario());
    diretor.setAreaDeFormacao(getAreaDeFormacao());

    system("cls");

    cout << "Qual sersa sua area de supervisao?" << endl;

    getline(cin, str);
    diretor.setAreaSupervisao(str);

    return diretor.atributosToString();
}

void Presidente::aumentaSalario(){
    salario *= 1.30;
}