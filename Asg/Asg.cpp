#include "Asg.hpp"
#include <math.h>

using namespace std;

// Construtores:
Asg::Asg() {}
Asg::Asg(std::string nome, std::string cpf, std::string estadoCivil, int diaN, int mesN, int anoN, std::string cidade, std::string bairro, std::string rua, std::string cep, int numero, int quantFilhos,
         float adicionalInsalubridade, std::string salario, std::string matricula, int dia, int mes, int ano, int quantFaltas)
    : Pessoa(nome, cpf, diaN, mesN, anoN, estadoCivil, cidade, bairro, rua, cep, numero, quantFilhos)
{
    setQuantFaltas(quantFaltas);
    setSalario(salario);
    setMatricula(matricula);
    setIngressoEmpresa(dia, mes, ano);
    this->adicionalInsalubridade = adicionalInsalubridade;
}

// Getters e Setters:
float Asg::getAdicionalInsalubridade() { return adicionalInsalubridade; }
void Asg::setAdicionalInsalubridade(float adicionalInsalubridade) { this->adicionalInsalubridade = adicionalInsalubridade; }

// Metodos virtuais sobrescritos de Funcionario:
float Asg::calcularSalario(int diasFaltas)
{
    float salario;
    try
    {
        salario = stof(getSalario());
    }
    catch (const invalid_argument e)
    {
        cout << "O salario passado é inválido!" << endl;
        salario = 0;
    }
    catch (const out_of_range e)
    {
        cout << "O salario passado é inválido!" << endl;
        salario = 0;
    }
    // Converte
    salario -= (salario / 30) * diasFaltas;                // Diminui as faltas
    salario += (this->adicionalInsalubridade * (salario)); // Soma o adicional de insalubridade
    salario += getQuantFilhos() * 100;
    return salario;
}

float Asg::calcularRecisao(Data desligamento)
{
    float ganhoRDia = stof(getSalario()) / 365;                            // Pega o valor ganho por dia no ano
    float ganhoPMes = stof(getSalario()) / 12;                             // Pega o valor ganho por mes no ano
    int quantAnos = fabs(getIngressoEmpresa().ano - desligamento.ano) - 1; // A quantidade de anos é o modulo do desligamento - ingresso
    int quantMes = getIngressoEmpresa().mes - desligamento.mes;            // Quantidade de mês
    int quantDias = fabs(getIngressoEmpresa().dia - desligamento.dia);     // Modulo da quantidade de dias
    if (desligamento.dia > getIngressoEmpresa().dia)
        quantMes = desligamento.dia - getIngressoEmpresa().dia;
    if (desligamento.dia < getIngressoEmpresa().dia)
        quantDias = 30 + (desligamento.dia - getIngressoEmpresa().dia);

    if (quantMes == 0 && quantAnos >= 1) // Se a quantidade de mês é 0, então tem um ano de diferença entre as datas
        quantMes = 12;
    if (quantMes > 0) // Se a quantidade de mês é maior que 0, então tem menos de ano
        quantMes = 12 - quantMes;
    if (quantMes < 0) // Se a quantidade é menor q 0, então tem mais de 1 ano
        quantMes = 12 + fabs(quantMes);
    if (quantAnos > 1) // Se tiver mais de 1, soma a quantidade de meses
        quantMes += 12 * (quantAnos - 1);
    return ((ganhoRDia * quantDias) + (ganhoPMes * quantMes)); // Soma o produto dos dias com o valor por dia e da quantidade de mes com o ganho por mes
}