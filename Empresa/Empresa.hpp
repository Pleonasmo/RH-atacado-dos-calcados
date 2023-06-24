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
    Data hoje;

public:
    Empresa();
    Empresa(std::string nomeEmpresa, std::string cnpj, float faturamentoMensal, Data dataHoje);
    float getFaturamentoMensal();
    void setFaturamentoMensal(float faturamento);
    std::string getNomeEmpresa();
    std::string escolherFuncionario();
    void setNomeEmpresa(std::string nomeEmpresa);
    std::string getCnpj();
    void setCnpj(std::string cnpj);
    Pessoa getDono();
    std::vector<Asg> getAsg();
    std::vector<Vendedor> getVendedores();
    std::vector<Gerente> getGerentes();
    void carregarFuncoes();
    void carregarEmpresa(int dia, int mes, int ano);
    void carregarAsg();
    void carregarVendedor();
    void carregarGerente();
    void carregarDono();
    void imprimeAsgs();
    void imprimeVendendores();
    void imprimeGerentes();
    void imprimeDono();
    void buscaFuncionario(int matricula);
    void cacularSalarioFuncionario(int matricula);
    void calcularTodoOsSalarios();
    void calcularRecisao(int matricula, Data desligamento);
};
#endif