#ifndef VENDEDOR_HEADER
#define VENDEDOR_HEADER

#include "../Pessoa/Pessoa.hpp"
#include "../Funcionario/Funcionario.hpp"

class Vendedor : public Pessoa, public Funcionario
{
    char tipoVendedor;

public:
    Vendedor();
    Vendedor(std::string nome, std::string cpf, std::string estadoCivil, int diaN, int mesN, int anoN, std::string cidade, std::string bairro, std::string rua, std::string cep, int numero, int quantFilhos,
             std::string salario, std::string matricula, int dia, int mes, int ano, char tipoVendedor, int quantFaltas);
    char getTipoVendedor();
    void setTipoVendedor(char tipoVendedor);
    float calcularSalario(int diasFaltas) override;
    float calcularRecisao(Data desligamento) override;
};

#endif