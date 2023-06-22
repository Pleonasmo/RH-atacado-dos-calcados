#ifndef GERENTE_HEADER
#define GERENTE_HEADER
#include "../Pessoa/Pessoa.hpp"
#include "../Funcionario/Funcionario.hpp"

class Gerente : public Pessoa, public Funcionario
{
    float participacaoLucros;

public:
    Gerente();
    Gerente(std::string nome, std::string cpf, std::string estadoCivil, int diaN, int mesN, int anoN, std::string cidade, std::string bairro, std::string rua, std::string cep, int numero, int quantFilhos,
                 std::string salario, std::string matricula, int dia, int mes, int ano, float participacaoLucros);

    float getParticipacaoLucros();
    void setParticipacaoLucros(float participacaoLucros);
    float calcularSalario(int diasFaltas);
    float calcularRecisao(Data desligamento);
};

#endif