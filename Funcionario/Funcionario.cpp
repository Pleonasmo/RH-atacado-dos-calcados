#include "Funcionario.hpp"

std::string Funcionario::getSalario() { return salario; }
void Funcionario::setSalario(std::string salario) { this->salario = salario; }
std::string Funcionario::getMatricula() { return matricula; }
void Funcionario::setMatricula(std::string matricula) { this->matricula = matricula; }
Data Funcionario::getIngressoEmpresa() { return ingressoEmpresa; }
void Funcionario::setIngressoEmpresa(int dia, int mes, int ano)
{
    this->ingressoEmpresa.dia = dia;
    this->ingressoEmpresa.mes = mes;
    this->ingressoEmpresa.ano = ano;
}
int Funcionario::getQuantFaltas() { return quantFaltas; }
void Funcionario::setQuantFaltas(int quantFaltas) { this->quantFaltas = quantFaltas; }