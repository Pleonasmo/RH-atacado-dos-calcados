#include "Empresa.hpp"
#include <fstream>

using namespace std;

// Construtores:
Empresa::Empresa() {}
Empresa::Empresa(std::string nomeEmpresa, std::string cnpj, float faturamentoMensal)
{
    this->nomeEmpresa = nomeEmpresa;
    this->cnpj = cnpj;
    this->faturamentoMensal = faturamentoMensal;
};

// Getters e Setters:
float Empresa::getFaturamentoMensal() { return faturamentoMensal; }
void Empresa::setFaturamentoMensal(float faturamentoMensal) { this->faturamentoMensal = faturamentoMensal; }
std::string Empresa::getNomeEmpresa() { return nomeEmpresa; }
void Empresa::setNomeEmpresa(std::string nomeEmpresa) { this->nomeEmpresa = nomeEmpresa; }
std::string Empresa::getCnpj() { return cnpj; }
void Empresa::setCnpj(std::string cnpj) { this->cnpj = cnpj; }
Pessoa Empresa::getDono() { return dono; }
std::vector<Asg> Empresa::getAsg() { return asgs; }
std::vector<Vendedor> Empresa::getVendedores() { return vendedores; }
std::vector<Gerente> Empresa::getGerentes() { return gerentes; }

// Outros metodos:

string simplificadorMatricula(string matricula) // Função para tirar ponto e - da matricula
{
    string novaMatricula = "";
    for (int i = 0; i < matricula.length(); i++)
    {
        if (matricula[i] != '.' && matricula[i] != '-' && matricula[i] != '\n')
        {
            novaMatricula.push_back(matricula[i]); // Adiciona cada caracter ao final da string
        }
    }
    return novaMatricula;
}

void Empresa::carregarFuncoes()
{
    fstream arq;
    arq.open("./Arquivos/Leitura/funcoes.txt", ios::in);
    if (!arq.is_open()) // Se o arquivo de funções não for aberto, lança um error
        throw 0;
    vector<string> linhas;
    string linha;
    while (getline(arq, linha)) // Pega a linha do arquivo e armazena na string linha
    {
        linhas.push_back(linha);
    }
    for (int i = 0; i < linhas.size(); i++)
    {
        // Compara a linha com cada função e a chama
        if (linhas[i] == "carregarEmpresa()")
        {
            try
            {
                carregarEmpresa();
            }
            catch (int error) // Caso o error 0 (defini esse erro para abertura do arquivo) tenha sido lançado
            {
                if (error == 0)
                    cout << "Error ao abrir o arquivo da empresa" << endl;
            }
            catch (const std::exception &e)
            {
                std::cerr << e.what() << '\n';
            }
        }
        if (linhas[i] == "carregarAsg()")
        {
            try
            {
                carregarAsg();
            }
            catch (const std::exception &e)
            {
                std::cerr << e.what() << '\n';
            }
        }
        if (linhas[i] == "carregarVendedor()")
        {
            try
            {
                carregarVendedor();
            }
            catch (const std::exception &e)
            {
                std::cerr << e.what() << '\n';
            }
        }
        if (linhas[i] == "carregarGerente()")
        {
            try
            {
                carregarGerente();
            }
            catch (const std::exception &e)
            {
                std::cerr << e.what() << '\n';
            }
        };
        if (linhas[i] == "carregaDono()")
        {
            try
            {
                carregarDono();
            }
            catch (const std::exception &e)
            {
                std::cerr << e.what() << '\n';
            }
        };
        if (linhas[i] == "imprimeAsgs()")
        {
            try
            {
                imprimeAsgs();
            }
            catch (const std::exception &e)
            {
                std::cerr << e.what() << '\n';
            }
        };
        if (linhas[i] == "imprimeVendedores()")
            imprimeVendendores();
        if (linhas[i] == "imprimeGerentes()")
            imprimeGerentes();
        if (linhas[i] == "imprimeDono()")
            imprimeDono();
        if (linhas[i] == "buscaFuncionario()")
            buscaFuncionario(stoi(simplificadorMatricula(linhas[++i]))); // passa a matricula como inteiro pra função
        if (linhas[i] == "calculaSalarioFuncionario()")
            cacularSalarioFuncionario(stoi(simplificadorMatricula(linhas[++i])));
        if (linha == "calculaTodoOsSalarios()")
        {
            try
            {
                calcularTodoOsSalarios();
            }
            catch (int error)
            { // Como a função escreve e lê no arquivo, conferi os dois
                if (error == 0)
                    cout << "Error ao abrir o arquivo do relátorio" << endl;
                if (error == 1)
                    cout << "Error ao abrir o arquivo do relátorio para leitura" << endl;
                else
                    cout << error << endl;
            }
        };
        if (linha == "calcularRecisao()")
        {
            try
            {
                Data desligamento;
                desligamento.ano = stoi(linhas[++i]);
                desligamento.mes = stoi(linhas[++i]);
                desligamento.dia = stoi(linhas[++i]);
                calcularRecisao(stoi(simplificadorMatricula(linhas[++i])), desligamento);
            }
            catch (int e)
            {
                if (e == 1)
                    cout << "A data de desligamento é inferior a data de ingresso" << endl;
            }
            break;
        }
    }
}
void Empresa::carregarEmpresa()
{
    std::vector<std::string> dadosEmpresa(3);
    int iterador = 0;

    // Leitura das linhas de empresa.txt:
    fstream arquivo("dados/empresa.txt");
    if (!arquivo.is_open())
    {
        throw std::runtime_error("Erro ao abrir o arquivo.");
    }
    else
    {
        std::string linha;
        while (std::getline(arquivo, linha))
        {
            char primeiroChar = linha[0];
            // Ignorando linhas com #:
            if (primeiroChar != '#')
            {
                dadosEmpresa[iterador] = linha;
                iterador++;
            }
            else
            {
                continue;
            }
        }
    }
    arquivo.close();

    // Carregando os dados na empresa:
    setNomeEmpresa(dadosEmpresa[0]);
    setCnpj(dadosEmpresa[1]);
    setFaturamentoMensal(stof(dadosEmpresa[2]));

    std::cout << "Carregou empresa com sucesso." << std::endl;
}
void Empresa::carregarAsg()
{
    fstream arq;
    arq.open("./Arquivos/asg.txt", ios::in);
    if (!arq.is_open())
        throw std::runtime_error("Erro ao abrir o arquivo.");
    string linha;
    int contador = 0, posicao = 0;
    vector<string> palavras;
    while (getline(arq, linha))
    { // Utiliza o contador como indice para salvar somente as linhas com informações
        if (linha[0] != '#')
            palavras.push_back(linha); // Salva no vector palavras as linhas com as informações
        contador++;                    // Avança no contador
        if (contador == 25)            // Quando chega no fim do ASG, ele reinicia a contagem para salvar o próximo
        {
            contador = 0;
            try
            {
                Asg asg;
                asg.setNome(palavras[0]);
                asg.setCpf(palavras[1]);
                asg.setQuantFilhos(stoi(palavras[2]));
                asg.setEstadoCivil(palavras[3]);
                asg.setEnderecoPessoal(palavras[4], palavras[5], palavras[6], palavras[7], stoi(palavras[8]));
                asg.setDataNascimento(stoi(palavras[11]), stoi(palavras[10]), stoi(palavras[9]));
                asg.setMatricula(palavras[12]);
                asg.setSalario(palavras[13]);
                asg.setAdicionalInsalubridade(stof(palavras[14]));
                asg.setQuantFaltas(stoi(palavras[15]));
                asg.setIngressoEmpresa(stoi(palavras[18]), stoi(palavras[17]), stoi(palavras[16]));
                this->asgs.push_back(asg); // Cria o ASG, adiciona no fim do vector e depois limpa o vector, para armazenar o próximo ASG
            }
            catch (invalid_argument &e)
            {
                cout << "Não foi possivel carregar asg, erro ao converter um dos parametros para número" << endl;
            }
            palavras.clear();
        }
    }
}
void Empresa::carregarVendedor()
{
    fstream arq;
    arq.open("./Arquivos/vendedor.txt", ios::in);
    if (!arq.is_open())
        throw std::runtime_error("Erro ao abrir o arquivo.");
    string linha;
    int contador = 0;
    vector<string> palavras;
    char tipoVendedor;
    while (getline(arq, linha))
    {
        if (linha[0] != '#')
            palavras.push_back(linha);
        contador++;
        if (contador == 25)
        {
            contador = 0;
            tipoVendedor = (palavras[14])[0]; // Como a linha é uma string, ele pega apenas a primeira posição
                                              // ai fica um char
            try                               // Caso não consiga converter alguma linha, tive muito problema com isso ;)
            {
                Vendedor vendedor(palavras[0], palavras[1], palavras[3],
                                  stoi(palavras[11]), stoi(palavras[10]), stoi(palavras[9]), palavras[4],
                                  palavras[6], palavras[7], palavras[5],
                                  stoi(palavras[8]), stoi(palavras[2]), palavras[13],
                                  palavras[12], stoi(palavras[17]), stoi(palavras[16]),
                                  stoi(palavras[15]), tipoVendedor);
                this->vendedores.push_back(vendedor);
            }
            catch (invalid_argument &e)
            {
                cout << "Não foi possivel carregar vendedor, erro ao converter um dos parametros para número" << endl;
            }
            palavras.clear();
        }
    }
}
void Empresa::carregarGerente()
{
    fstream arq;
    arq.open("./Arquivos/Leitura/gerente.txt", ios::in);
    if (!arq.is_open())
        throw std::runtime_error("Erro ao abrir o arquivo.");
    string linha;
    int contador = 0;
    vector<string> palavras;
    while (getline(arq, linha))
    {
        if (linha[0] != '#')
            palavras.push_back(linha);

        contador++;

        if (contador == 25)
        {
            try
            {
                contador = 0;
                Gerente gerente;
                gerente.setNome(palavras[0]);
                gerente.setCpf(palavras[1]);
                gerente.setQuantFilhos(stoi(palavras[2]));
                gerente.setEstadoCivil(palavras[3]);
                gerente.setEnderecoPessoal(palavras[4], palavras[6], palavras[7], palavras[5], stoi(palavras[8]));
                gerente.setDataNascimento(stoi(palavras[11]), stoi(palavras[10]), stoi(palavras[9]));
                gerente.setMatricula(palavras[12]);
                gerente.setSalario(palavras[13]);
                gerente.setParticipacaoLucros(stof(palavras[14]));
                gerente.setIngressoEmpresa(stoi(palavras[17]), stoi(palavras[16]), stoi(palavras[15]));

                this->gerentes.push_back(gerente);
            }
            catch (invalid_argument &e)
            {
                cout << "Não foi possivel carregar gerente, erro ao converter um dos parametros para número" << endl;
            }
            palavras.clear();
        }
    }
}

void Empresa::carregarDono()
{
    std::vector<std::string> dadosDono(12);
    int iterador = 0;
    // Leitura das linhas de empresa.txt:
    fstream arquivo("./Arquivos/Leitura/dono.txt");
    if (!arquivo)
        throw std::runtime_error("Erro ao abrir o arquivo.");
    else
    {
        string linha;
        while (std::getline(arquivo, linha))
        {
            if (linha[0] != '#') // Ignorando linhas com # e *:
            {
                dadosDono[iterador] = linha;
                iterador++;
                if (iterador == 12)
                {
                    this->dono.setNome(dadosDono[0]);
                    this->dono.setCpf(dadosDono[1]);
                    this->dono.setQuantFilhos(std::stoi(dadosDono[2]));
                    this->dono.setEstadoCivil(dadosDono[3]);
                    this->dono.setEnderecoPessoal(dadosDono[4], dadosDono[6], dadosDono[7], dadosDono[5], stoi(dadosDono[8]));
                    this->dono.setDataNascimento(stoi(dadosDono[11]), stoi(dadosDono[10]), stoi(dadosDono[9]));
                    break;
                }
            }
        }
    }

    arquivo.close();

    std::cout << "Carregou Dono com sucesso." << std::endl;
}
void Empresa::imprimeAsgs() {}
void Empresa::imprimeVendendores() {}
void Empresa::imprimeGerentes() {}
void Empresa::imprimeDono() {}
void Empresa::buscaFuncionario(int matricula) {}
void Empresa::cacularSalarioFuncionario(int matricula) {}
void Empresa::calcularTodoOsSalarios() {}
void Empresa::calcularRecisao(int matricula, Data desligamento) {}