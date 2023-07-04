#ifndef VENDEDOR_HEADER
#define VENDEDOR_HEADER

#include "../Pessoa/Pessoa.hpp"
#include "../Funcionario/Funcionario.hpp"

class Vendedor : public Pessoa, public Funcionario
{
    char tipoVendedor;

public:
    /**
     * @brief construtor vazio de vendedor
     */
    Vendedor();

    /**
     * @brief Construtor parametrizado de Vendedor
     * @param nome O nome do vendedor
     * @param cpf O cpf do vendedor
     * @param dia O dia de nascimento
     * @param mes O mês de nascimento
     * @param ano O ano de nascimento
     * @param estadoCivil O estado civil do vendedor
     * @param cidade A cidade do vendedor
     * @param bairro O bairro do vendedor
     * @param rua A rua do vendedor
     * @param cep O cep do vendedor
     * @param numero O numero da casa do vendedor
     * @param quantFilhos A quantidade de filhos do vendedor
     * @param tipoVendedor tipo do vendedor
     * @param salario O salario do vendedor
     * @param matricula a matricula do vendedor
     * @param dia dia de ingresso do vendedor
     * @param mes mes de ingresso do vendedor
     * @param ano ano de ingresso do vendedor
     * @param quantFaltas quantidade de faltas do vendedor
     */
    Vendedor(std::string nome, std::string cpf, std::string estadoCivil, int diaN, int mesN, int anoN, std::string cidade, std::string bairro, std::string rua, std::string cep, int numero, int quantFilhos,
             std::string salario, std::string matricula, int dia, int mes, int ano, char tipoVendedor, int quantFaltas);

    /**
     * @brief Getter do tipo do vendedor
     * @return tipo do vendedor
     */
    char getTipoVendedor();

    /**
     * @brief Setter do tipo do vendedor
     * @param tipoVendedor tipo do vendedor
     */
    void setTipoVendedor(char tipoVendedor);

    /**
     * @brief calculo do salario de vendedor
     * @param diasFaltas quantidade de faltas do vendedor
     * @return valor do salario do vendedor
     */
    float calcularSalario(int diasFaltas) override;

    /**
     * @brief calculo da recisao do vendedor
     * @param desligamento data de desligamento do vendedor
     * @return valor da recisao do vendedor
     */
    float calcularRecisao(Data desligamento) override;
};

#endif