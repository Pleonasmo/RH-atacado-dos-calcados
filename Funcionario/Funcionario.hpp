#ifndef FUNCIONARIO_HEADER
#define FUNCIONARIO_HEADER
#include "../Util.hpp"
#include <iostream>

class Funcionario
{
    std::string salario, matricula;
    Data ingressoEmpresa;

public:

    //Metodos virtuais:
    virtual float calcularSalario(int diasFaltas) = 0;
    virtual float calcularRecisao(Data desligamento) = 0;

    //Getters e Setters:
    std::string getSalario();
    void setSalario(std::string salario);
    std::string getMatricula();
    void setMatricula(std::string matricula);
    Data getIngressoEmpresa();
    void setIngressoEmpresa(int dia, int mes, int ano);
};

#endif