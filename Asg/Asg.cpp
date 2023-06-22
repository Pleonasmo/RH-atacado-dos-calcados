#include "Asg.hpp"

Asg::Asg() {}
Asg::Asg(std::string nome, std::string cpf, std::string estadoCivil, int diaN, int mesN, int anoN, std::string cidade, std::string bairro, std::string rua, std::string cep, int numero, int quantFilhos,
         float adicionalInsalubridade, std::string salario, std::string matricula, int dia, int mes, int ano)
    : Pessoa(nome, cpf, dia, mes, ano, estadoCivil, cidade, bairro, rua, cep, numero, quantFilhos)
{
    setSalario(salario);
    setMatricula(matricula);
    setIngressoEmpresa(dia, mes, ano);
    this->adicionalInsalubridade = adicionalInsalubridade;
}
float Asg::getAdicionalInsalubridade() { return adicionalInsalubridade; }
void Asg::setAdicionalInsalubridade(float adicionalInsalubridade) { this->adicionalInsalubridade = adicionalInsalubridade; }
float Asg::calcularSalario(int diasFaltas) {}
float Asg::calcularRecisao(Data desligamento) {}