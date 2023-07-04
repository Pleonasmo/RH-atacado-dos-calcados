#ifndef ASG_HEADER
#define ASG_HEADER

#include "../Pessoa/Pessoa.hpp"
#include "../Funcionario/Funcionario.hpp"

class Asg : public Funcionario, public Pessoa
{

    float adicionalInsalubridade;

public:
    /**
     * @brief construtor vazio de ASG
     */
    Asg();

    /**
     * @brief Construtor parametrizado de ASG
     * @param nome O nome do asg
     * @param cpf O cpf do asg.
     * @param dia O dia de nascimento
     * @param mes O mês de nascimento
     * @param ano O ano de nascimento
     * @param estadoCivil O estado civil do asg
     * @param cidade A cidade do asg
     * @param bairro O bairro do asg
     * @param rua A rua do asg
     * @param cep O cep do asg
     * @param numero O numero da casa do asg
     * @param quantFilhos A quantidade de filhos do asg
     * @param adicionalInsalubridade o adicional de insalubridade do asg
     * @param salario O salario do asg
     * @param matricula a matricula do asg
     * @param dia dia de ingresso do asg
     * @param mes mes de ingresso do asg
     * @param ano ano de ingresso do asg
     * @param quantFaltas quantidade de faltas do asg
     */
    Asg(std::string nome, std::string cpf, std::string estadoCivil, int diaN, int mesN, int anoN, std::string cidade, std::string bairro, std::string rua, std::string cep, int numero, int quantFilhos,
        float adicionalInsalubridade, std::string salario, std::string matricula, int dia, int mes, int ano, int quantFaltas);

    /**
     * @brief Getter do adicional de insalubridade do asg
     * @return valor do adicional de insalubridade
     */
    float getAdicionalInsalubridade();

    /**
     * @brief Setter do adicional de insalubridade
     * @param adicionalInsalubridade adicional de insalubridade do asg
     */
    void setAdicionalInsalubridade(float adicionalInsalubridade);

    /**
     * @brief calculo de salario do asg
     * @param diasFaltas quantidade de faltas do asg
     * @return valor do salario do asg
     */
    float calcularSalario(int diasFaltas) override;

    /**
     * @brief calculo da recisão do asg
     * @param desligamento data de desligamento do asg
     * @return valor da recisão do asg
     */
    float calcularRecisao(Data desligamento) override;
};

#endif