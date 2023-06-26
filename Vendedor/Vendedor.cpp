#include "Vendedor.hpp"
#include <math.h>

using namespace std;

//Construtores:
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

//Getters e Setters:
char Vendedor::getTipoVendedor() { return tipoVendedor; }
void Vendedor::setTipoVendedor(char tipoVendedor) { this->tipoVendedor = tipoVendedor; }

//Metodos virtuais sobrescritos de Funcionario:
float Vendedor::calcularSalario(int diasFaltas)
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
    float gratificacao; // calculo da gratificacao do vendedor com base no tipo:

    if (getTipoVendedor() == 'A')
    {
        gratificacao = (25 / 100) * salario;
    }
    else if (getTipoVendedor() == 'B')
    {
        gratificacao = (10 / 100) * salario;
    }
    else if (getTipoVendedor() == 'C')
    {
        gratificacao = (5 / 100) * salario;
    }

    salario -= ((stof(getSalario()) / 30) * diasFaltas); // Pega o salario e diminui as faltas
    salario += gratificacao;                             // Adiciona a participação nos lucros
    salario += getQuantFilhos() * 100;                   // E adiciona o valor pela quantidade de filhos

    return salario;
}

float Vendedor::calcularRecisao(Data desligamento)
{
    float ganhoRDia = stof(getSalario()) / 365;                        // Pega o valor ganho por dia no ano
    float ganhoPMes = stof(getSalario()) / 12;                         // Pega o valor ganho por mes no ano
    int quantAnos = fabs(getIngressoEmpresa().ano - desligamento.ano); // A quantidade de anos é o modulo do desligamento - ingresso
    int quantMes = getIngressoEmpresa().mes - desligamento.mes;        // Quantidade de mês
    int quantDias = fabs(getIngressoEmpresa().dia - desligamento.dia); // Modulo da quantidade de dias
    if (quantMes == 0 && quantAnos >= 1)                               // Se a quantidade de mês é 0, então tem um ano de diferença entre as datas
        quantMes = 12;
    if (quantMes > 0) // Se a quantidade de mês é maior que 0, então tem menos de ano
        quantMes = 12 - quantMes;
    if (quantMes < 0) // Se a quantidade é menor q 0, então tem mais de 1 ano
        quantMes = 12 + fabs(quantMes);
    if (quantAnos > 1) // Se tiver mais de 1, soma a quantidade de meses
        quantMes += 12 * (quantAnos - 1);
    return ((ganhoRDia * quantDias) + (ganhoPMes * quantMes)); // Soma o produto dos dias com o valor por dia e da quantidade de mes com o ganho por mes
}