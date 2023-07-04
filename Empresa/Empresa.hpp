#ifndef EMPRESA_HEADER
#define EMPRESA_HEADER

#include "../Vendedor/Vendedor.hpp"
#include "../Asg/Asg.hpp"
#include "../Gerente/Gerente.hpp"
#include "../Pessoa/Pessoa.hpp"
#include <vector>

class Empresa
{
    float faturamentoMensal;
    std::string nomeEmpresa, cnpj;
    Pessoa dono;
    std::vector<Asg> asgs;
    std::vector<Vendedor> vendedores;
    std::vector<Gerente> gerentes;

public:
    /**
     * @brief Construtor vazio de empresa
     */
    Empresa();
    /**
     * @brief Construtor parametrizado de empresa
     * @param nomeEmpresa nome da empresa
     * @param cnpj cnpj da empresa
     * @param faturamentoMensal Faturamento mensal da empresa
     */
    Empresa(std::string nomeEmpresa, std::string cnpj, float faturamentoMensal);

    /**
     * @brief Getter do faturamento mensal
     * @return Faturamento mensal da empresa
     */
    float getFaturamentoMensal();
    /**
     * @brief Setter de faturamento mensal
     * @param faturamento O faturamento mensal da empresa
     */
    void setFaturamentoMensal(float faturamento);

    /**
     * @brief Getter do nome da empresa
     * @return nome da empresa
     */
    std::string getNomeEmpresa();

    /**
     * @brief Setter do nome da empresa
     * @param nomeEmpresa nome da empresa
     */
    void setNomeEmpresa(std::string nomeEmpresa);

    /**
     * @brief Getter de CNPJ
     * return CNPJ da empresa
     */
    std::string getCnpj();

    /**
     * @brief Setter de CNPJ
     * @param CNPJ da empresa
     */
    void setCnpj(std::string cnpj);

    /**
     * @brief Getter do dono da empresa
     * @return Dados do dono da empresa
     */
    Pessoa getDono();

    /**
     * @brief Getter dos ASGs
     * @return dados de todos os ASGs da empresa
     */

    std::vector<Asg> getAsgs();

    /**
     * @brief Getter dos Vendedores
     * @return dados de todos os vendedores da empresa
     */
    std::vector<Vendedor> getVendedores();

    /**
     * @brief Getter do gerente
     * @return dados do gerente da empresa
     */
    std::vector<Gerente> getGerentes();

    /**
     * @brief Função que carrega funções do arquivo
     */

    void carregarFuncoes();
    /**
     * @brief Função para remover "." e "-" da matricula
     * @param matricula A matricula do funcionario
     */
    std::string simplificadorMatricula(std::string matricula);
    /**
     * @brief Função que carrega empresa a partir do arquivo
     */
    void carregarEmpresa();

    /**
     * @brief Função que carrega ASG a partir do arquivo
     */
    void carregarAsg();

    /**
     * @brief Função que carrega vendedor a partir do arquivo
     */
    void carregarVendedor();

    /**
     * @brief Função que carrega gerente a partir do arquivo
     */
    void carregarGerente();

    /**
     * @brief Função que carrega o dono a partir do arquivo
     */
    void carregarDono();

    /**
     * @brief Função que imprime os ASG
     */
    void imprimeAsgs();

    /**
     * @brief Função que imprime os vendedores
     */
    void imprimeVendendores();

    /**
     * @brief Função que imprime os gerentes
     */
    void imprimeGerentes();

    /**
     * @brief Função que imprime o dono
     */
    void imprimeDono();

    /**
     * @brief Função que busca o funcionario
     * @param matricula A matricula do funcionario
     */
    void buscaFuncionario(int matricula);

    /**
     * @brief Função que calcula o salario do funcionario
     * @param matricula A matricula do funcionario
     */
    void cacularSalarioFuncionario(int matricula);

    /**
     * @brief Função que calcula o salario de todos os funcionarios
     */
    void calcularTodoOsSalarios();

    /**
     * @brief Função que calcula a recisão do funcionario
     * @param matricula A matricula do funcionario
     * @param desligamento A data de desligamento do funcionario
     */
    void calcularRecisao(int matricula, Data desligamento);

    /**
     * @brief Função para demitir um funcionario
     * @param matricula A matricula do funcionario
     * @param desligamento A data de desligamento do funcionario
     */
    void demitirFuncionario(int matricula, Data desligamento);

    /**
     * @brief Função para contratar um novo funcionario
     */
    void contratarFuncionario();
};
#endif