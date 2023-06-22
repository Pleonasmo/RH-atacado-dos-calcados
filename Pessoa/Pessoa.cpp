#include "Pessoa.hpp"

Pessoa::Pessoa() {}

Pessoa::Pessoa(std::string nome, std::string cpf, int dia, int mes, int ano, std::string estadoCivil, std::string cidade, std::string bairro, std::string rua, std::string cep, int numero, int quantFilhos)
{
    this->nome = nome;
    this->cpf = cpf;
    this->dataNascimento.dia = dia;
    this->dataNascimento.mes = mes;
    this->dataNascimento.ano = ano;
    this->enderecoPessoal.bairro = bairro;
    this->enderecoPessoal.cep = cep;
    this->enderecoPessoal.cidade = cidade;
    this->enderecoPessoal.numero = numero;
    this->enderecoPessoal.rua = rua;
}
std::string Pessoa::getNome() { return nome; }
void Pessoa::setNome(std::string nome) { this->nome = nome; }
std::string Pessoa::getCpf() { return cpf; }
void Pessoa::setCpf(std::string cpf) { this->cpf = cpf; }
Data Pessoa::getDataNascimento() { return dataNascimento; }
void Pessoa::setDataNascimento(int dia, int mes, int ano){
    this->dataNascimento.dia = dia;
    this->dataNascimento.mes = mes;
    this->dataNascimento.ano = ano;
};
std::string Pessoa::getEstadoCivil() { return estadoCivil; }
void Pessoa::setEstadoCivil(std::string estadoCivil) { this->estadoCivil = estadoCivil; }
Endereco Pessoa::getEnderecoPessoal() { return enderecoPessoal; }
void Pessoa::setEnderecoPessoal(std::string cidade, std::string bairro, std::string rua, std::string cep, int numero){
    this->enderecoPessoal.bairro = bairro;
    this->enderecoPessoal.cep = cep;
    this->enderecoPessoal.cidade = cidade;
    this->enderecoPessoal.numero = numero;
    this->enderecoPessoal.rua = rua;
};
int Pessoa::getQuantFilhos() { return quantFilhos; }
void Pessoa::setQuantFilhos(int quantFilhos) { this->quantFilhos = quantFilhos; }