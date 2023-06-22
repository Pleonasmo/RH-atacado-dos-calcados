#include "Gerente.hpp"

Gerente::Gerente() {}
Gerente::Gerente(std::string nome, std::string cpf, std::string estadoCivil, int diaN, int mesN, int anoN, std::string cidade, std::string bairro, std::string rua, std::string cep, int numero, int quantFilhos,
                 std::string salario, std::string matricula, int dia, int mes, int ano, float participacaoLucros)
    : Pessoa(nome, cpf, dia, mes, ano, estadoCivil, cidade, bairro, rua, cep, numero, quantFilhos)
{
    setSalario(salario);
    setMatricula(matricula);
    setIngressoEmpresa(dia, mes, ano);
    this->participacaoLucros = participacaoLucros;
}

float Gerente::calcularSalario(int diasFaltas) {}
float Gerente::calcularRecisao(Data desligamento) {}
float Gerente::getParticipacaoLucros() { return participacaoLucros; }
void Gerente::setParticipacaoLucros(float participacaoLucros) { this->participacaoLucros = participacaoLucros; }
