#ifndef FUNCIONARIO_HEADER
#define FUNCIONARIO_HEADER
#include "../Util.hpp"
#include <iostream>

class Funcionario
{
    std::string salario, matricula;
    Data ingressoEmpresa;
    int quantFaltas;

public:
    /**
     * @brief função para calcular salario do funcionario
     * @param diasFaltas quantidade de faltas do funcionario
     * @return valor do salario do funciuonario
     */
    virtual float calcularSalario(int diasFaltas) = 0;

    /**
     * @brief função para calcular recisão do funcionario
     * @param desligamento data de desligamento do funcionario
     * @return valor da recisao do funcionario
     */
    virtual float calcularRecisao(Data desligamento) = 0;

    /**
     * @brief Getter de salario do funcionario
     * @return salario do funcionario
     */
    std::string getSalario();

    /**
     * @brief Setter de salario
     * @param salario salario do funcionario
     */
    void setSalario(std::string salario);

    /**
     * @brief Getter de matricula
     * @return matricula do funcionario
     */
    std::string getMatricula();

    /**
     * @brief Setter de matricula
     * @param matricula matricula do funcionario
     */
    void setMatricula(std::string matricula);

    /**
     * @brief Getter de data de ingresso na empresa
     * @return data de ingresso na empresa
     */
    Data getIngressoEmpresa();

    /**
     * @brief Setter de data de ingresso na empresa
     * @param dia dia de ingresso
     * @param mes mes de ingresso
     * @param ano ano de ingresso
     */
    void setIngressoEmpresa(int dia, int mes, int ano);

    /**
     * @brief Getter de quantidade de faltas
     * @return quantidade de faltas
     */
    int getQuantFaltas();

    /**
     * @brief Setter de quantidade de faltas
     * @param quantFaltas quantidade de faltas
     */
    void setQuantFaltas(int quantFaltas);
};

#endif