#include "Operador.h"

Operador::Operador() : Funcionario("Operador"){
    codigo = "vazio";
    nome = "vazio";
    endereco = "vazio";
    telefone = "vazio";
    dataDeIngresso = "vazio";
    salario = 0;
    dataAniversario = "vazio";
}

void Operador::setDesignacao(){
    designacao = "Operador";
}