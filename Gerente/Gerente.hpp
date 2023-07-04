#ifndef GERENTE_HEADER
#define GERENTE_HEADER
#include "../Pessoa/Pessoa.hpp"
#include "../Funcionario/Funcionario.hpp"

class Gerente : public Pessoa, public Funcionario
{
    float participacaoLucros;

public:
    /**
     * @brief Construtor vazio de Gerente
     */
    Gerente();

    /**
     * @brief Construtor parametrizado de Gerente
     * @param nome O nome do Gerente
     * @param cpf O cpf do Gerente.
     * @param dia O dia de nascimento
     * @param mes O mês de nascimento
     * @param ano O ano de nascimento
     * @param estadoCivil O estado civil do gerente
     * @param cidade A cidade do gerente
     * @param bairro O bairro do gerente
     * @param rua A rua do gerente
     * @param cep O cep do gerente
     * @param numero O numero da casa do gerente
     * @param quantFilhos A quantidade de filhos do gerente
     * @param participacaoLucros o percentual de participacao nos lucros do gerente
     * @param salario O salario do gerente
     * @param matricula a matricula do gerente
     * @param dia dia de ingresso do gerente
     * @param mes mes de ingresso do gerente
     * @param ano ano de ingresso do gerente
     * @param quantFaltas quantidade de faltas do gerente
     */
    Gerente(std::string nome, std::string cpf, std::string estadoCivil, int diaN, int mesN, int anoN, std::string cidade, std::string bairro, std::string rua, std::string cep, int numero, int quantFilhos,
            std::string salario, std::string matricula, int dia, int mes, int ano, float participacaoLucros, int quantFaltas);

    /**
     * @brief Getter da participacao nos lucros
     * @return percentual de participacao nos lucros
     */
    float getParticipacaoLucros();

    /**
     * @brief Setter da participacao nos lucros
     * @param participacaoLucros percentual de participacao nos lucros
     */
    void setParticipacaoLucros(float participacaoLucros);

    /**
     * @brief calculo do salario do Gerente
     * @param diasFaltas quantidade de faltas do gerente
     * @return valor do salario do gerente
     */
    float calcularSalario(int diasFaltas) override;

    /**
     * @brief calculo da recisao do gerente
     * @param desligamento data de desligamento do gerente
     * @return valor da recisao do gerente
     */
    float calcularRecisao(Data desligamento) override;
};

#endif