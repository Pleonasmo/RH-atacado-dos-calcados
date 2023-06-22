#include "Vendedor.hpp"

Vendedor::Vendedor() {}
Vendedor::Vendedor(std::string nome, std::string cpf, std::string estadoCivil, int diaN, int mesN, int anoN, std::string cidade, std::string bairro, std::string rua, std::string cep, int numero, int quantFilhos,
                   std::string salario, std::string matricula, int dia, int mes, int ano, char tipoVendedor)
    : Pessoa(nome, cpf, dia, mes, ano, estadoCivil, cidade, bairro, rua, cep, numero, quantFilhos)
{
    setSalario(salario);
    setMatricula(matricula);
    setIngressoEmpresa(dia, mes, ano);
    this->tipoVendedor = tipoVendedor;
}
char Vendedor::getTipoVendedor() { return tipoVendedor; }
void Vendedor::setTipoVendedor(char tipoVendedor) { this->tipoVendedor = tipoVendedor; }
float Vendedor::calcularSalario(int diasFaltas) {}
float Vendedor::calcularRecisao(Data desligamento) {}