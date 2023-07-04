#ifndef PESSOA_HEADER
#define PESSOA_HEADER
#include "../Util.hpp"
class Pessoa
{
    std::string nome, cpf, estadoCivil;
    Data dataNascimento;
    Endereco enderecoPessoal;
    int quantFilhos;

public:
    /**
     * @brief Construtor vazio de Pessoa
     */
    Pessoa();

    /**
     * @brief Construtor parametrizado de Pessoa
     * @param nome O nome da pessoa
     * @param cpf O cpf do tipo pessoa.
     * @param dia O dia de nascimento
     * @param mes O mês de nascimento
     * @param ano O ano de nascimento
     * @param estadoCivil O estado civil de pessoa
     * @param cidade A cidade da pessoa
     * @param bairro O bairro da pessoa
     * @param rua A rua da pessoa
     * @param cep O cep da pessoa
     * @param numero O numero da casa de pessoa
     * @param quantFilhos A quantidade de filhos da pessoa
     */
    Pessoa(std::string nome, std::string cpf, int dia, int mes, int ano, std::string estadoCivil, std::string cidade, std::string bairro, std::string rua, std::string cep, int numero, int quantFilhos);

    /**
     * @brief Getter de nome
     * @return nome
     **/
    std::string getNome();

    /**
     * @brief Setter de nome
     * @param nome O nome da pessoa
     **/
    void setNome(std::string nome);

    /**
     * @brief Getter de cpf
     * @return cpf
     **/
    std::string getCpf();
    /**
     * @brief Setter de cpf
     * @param nome O cpf da pessoa
     **/
    void setCpf(std::string cpf);

    /**
     * @brief Getter de data de nascimento
     * @return data de nascimento
     **/
    Data getDataNascimento();

    /**
     * @brief Setter de Data de nascimento
     * @param dia O dia de nascimento da pessoa
     * @param mes O mes de nascimento da pessoa
     * @param ano O ano de nascimento da pessoa
     **/
    void setDataNascimento(int dia, int mes, int ano);

    /**
     * @brief Getter de Estado Civil
     * @return estado civil
     */
    std::string getEstadoCivil();

    /**
     * @brief Setter de Estado Civil
     * @param estadoCivil estado civil de pessoa
     */
    void setEstadoCivil(std::string estadoCivil);
    /**
     * @brief Getter de Endereço pessoal
     * @return endereçoPessoal
     */
    Endereco getEnderecoPessoal();
    /**
     * @brief Setter de Endereço Pessoal
     * @param cidade a cidade da pessoa
     * @param cep o cep da pessoa
     * @param bairro o bairro da pessoa
     */
    void setEnderecoPessoal(std::string cidade, std::string cep, std::string bairro, std::string rua, int numero);

    /**
     * @brief Getter de Quantidade de filhos
     * @return quantFilhos
     */
    int getQuantFilhos();

    /**
     * @brief Setter de Quantidade de filhos
     * @param quantFilhos quantidade de filhos
     */
    void setQuantFilhos(int quantFilhos);
};
#endif