#include "Empresa.hpp"
#include <math.h>
#include <string.h>
#include <cstring>
#include <fstream>
#include <cctype>

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
std::vector<Asg> Empresa::getAsgs() { return asgs; }
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
    { // Compara a linha com cada função e a chama
        if (linhas[i] == "carregarEmpresa()")
        {
            try
            {
                carregarEmpresa();
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
        if (linhas[i] == "calculaTodoOsSalarios()")
        {
            try
            {
                calcularTodoOsSalarios();
            }
            catch (const std::exception &e)
            {
                std::cerr << e.what() << '\n';
            }
        };
        if (linhas[i] == "calcularRescisao()")
        {
            try
            {
                int matricula = stoi(simplificadorMatricula(linhas[++i]));
                Data desligamento;
                desligamento.ano = stoi(linhas[++i]);
                desligamento.mes = stoi(linhas[++i]);
                desligamento.dia = stoi(linhas[++i]);
                calcularRecisao(matricula, desligamento);
            }
            catch (const std::exception &e)
            {
                std::cerr << e.what() << '\n';
            }
        }
        if (linhas[i] == "demitirFuncionario()")
        {
            try
            {
                int matricula = stoi(simplificadorMatricula(linhas[++i]));
                Data desligamento;
                desligamento.ano = stoi(linhas[++i]);
                desligamento.mes = stoi(linhas[++i]);
                desligamento.dia = stoi(linhas[++i]);
                demitirFuncionario(matricula, desligamento);
            }
            catch (const std::exception &e)
            {
                std::cerr << e.what() << '\n';
            }
        }
        if (linhas[i] == "contratarFuncionario()")
        {
            try
            {
                contratarFuncionario();
            }
            catch (const std::exception &e)
            {
                std::cerr << e.what() << '\n';
            }
        }
    }
}
void Empresa::carregarEmpresa()
{
    std::vector<std::string> dadosEmpresa(3);
    int iterador = 0;

    // Leitura das linhas de empresa.txt:
    fstream arquivo("./Arquivos/Leitura/empresa.txt");
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
    arq.open("./Arquivos/Leitura/asg.txt", ios::in);
    if (!arq.is_open())
        throw std::runtime_error("Erro ao abrir o arquivo.");
    string linha;
    int contador = 0, posicao = 0;
    vector<string> palavras;
    while (getline(arq, linha))
    { // Utiliza o contador como indice para salvar somente as linhas com informações
        if ((linha[0] != '#') && (linha[0] != '*') && contador >= 2)
            palavras.push_back(linha);

        // Salva no vector palavras as linhas com as informações
        contador++;
        // Avança no contador
        if (contador == 26) // Quando chega no fim do ASG, ele reinicia a contagem para salvar o próximo
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
    arq.open("./Arquivos/Leitura/vendedor.txt", ios::in);
    if (!arq.is_open())
        throw std::runtime_error("Erro ao abrir o arquivo.");
    string linha;
    int contador = 0;
    vector<string> palavras;
    char tipoVendedor;
    while (getline(arq, linha))
    {
        if ((linha[0] != '#') && (linha[0] != '*') && contador >= 2)
            palavras.push_back(linha);
        contador++;
        if (contador == 26)
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
                                  palavras[12], stoi(palavras[18]), stoi(palavras[17]),
                                  stoi(palavras[16]), tipoVendedor, stoi(palavras[15]));

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
        if ((linha[0] != '#') && (linha[0] != '*') && contador >= 2)
            palavras.push_back(linha);

        contador++;

        if (contador == 26)
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
    fstream arquivo;
    arquivo.open("./Arquivos/Leitura/dono.txt", ios::in);
    if (!arquivo)
        throw std::runtime_error("Erro ao abrir o arquivo.");
    else
    {
        string linha;
        while (getline(arquivo, linha))
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
void Empresa::imprimeAsgs()
{
    std::vector<Asg> listaAsgs = getAsgs();
    cout << "\n----- LISTA DE ASGS DA EMPRESA -----" << endl;
    for (int i = 0; i < listaAsgs.size(); i++)
    { // Lê cada posicao do vetor de Asgs e em seguida imprime todos os atributos:
        cout << "ASG numero: " << i + 1 << ":" << endl;
        cout << "Nome: " << listaAsgs[i].getNome() << endl;
        cout << "CPF: " << listaAsgs[i].getCpf() << endl;
        cout << "Data de nascimento: " << listaAsgs[i].getDataNascimento().dia << "/" << listaAsgs[i].getDataNascimento().mes << "/" << listaAsgs[i].getDataNascimento().ano << endl;
        cout << "Endereço: " << listaAsgs[i].getEnderecoPessoal().cidade << ", " << listaAsgs[i].getEnderecoPessoal().bairro << ", " << listaAsgs[i].getEnderecoPessoal().cep
             << ", Rua " << listaAsgs[i].getEnderecoPessoal().rua << ", " << listaAsgs[i].getEnderecoPessoal().numero << endl;
        cout << "Estado civil: " << listaAsgs[i].getEstadoCivil() << endl;
        cout << "Quantidade de filhos " << listaAsgs[i].getQuantFilhos() << endl;
        cout << "Matricula: " << listaAsgs[i].getMatricula() << endl;
        cout << "Salario: " << listaAsgs[i].getSalario() << endl;
        cout << "Data de ingresso: " << listaAsgs[i].getIngressoEmpresa().dia << "/" << listaAsgs[i].getIngressoEmpresa().mes << "/" << listaAsgs[i].getIngressoEmpresa().ano << endl;
        cout << "Adicional de insalubridade: " << listaAsgs[i].getAdicionalInsalubridade() << endl
             << endl;
    }
    cout << "----------------------------------------" << endl;
}
void Empresa::imprimeVendendores()
{
    std::vector<Vendedor> listaVendedores = getVendedores();
    cout << "\n----- LISTA DE VENDEDORES DA EMPRESA -----" << endl;
    for (int i = 0; i < listaVendedores.size(); i++)
    { // Lê cada posicao do vetor de Vendedores e em seguida imprime todos os atributos:
        cout << "Vendedor numero: " << i + 1 << ":" << endl;
        cout << "Nome: " << listaVendedores[i].getNome() << endl;
        cout << "CPF: " << listaVendedores[i].getCpf() << endl;
        cout << "Data de nascimento: " << listaVendedores[i].getDataNascimento().dia << "/" << listaVendedores[i].getDataNascimento().mes << "/" << listaVendedores[i].getDataNascimento().ano << endl;
        cout << "Endereço: " << listaVendedores[i].getEnderecoPessoal().cidade << ", " << listaVendedores[i].getEnderecoPessoal().bairro << ", " << listaVendedores[i].getEnderecoPessoal().cep
             << ", Rua " << listaVendedores[i].getEnderecoPessoal().rua << ", " << listaVendedores[i].getEnderecoPessoal().numero << endl;
        cout << "Estado civil: " << listaVendedores[i].getEstadoCivil() << endl;
        cout << "Quantidade de filhos " << listaVendedores[i].getQuantFilhos() << endl;
        cout << "Matricula: " << listaVendedores[i].getMatricula() << endl;
        cout << "Salario: " << listaVendedores[i].getSalario() << endl;
        cout << "Quantidade de faltas: " << listaVendedores[i].getQuantFaltas() << endl;
        cout << "Data de ingresso: " << listaVendedores[i].getIngressoEmpresa().dia << "/" << listaVendedores[i].getIngressoEmpresa().mes << "/" << listaVendedores[i].getIngressoEmpresa().ano << endl;
        cout << "Tipo de vendedor: " << listaVendedores[i].getTipoVendedor() << endl
             << endl;
    }
    cout << "----------------------------------------" << endl;
}
void Empresa::imprimeGerentes()
{
    std::vector<Gerente> listaGerentes = getGerentes();
    cout << "\n----- LISTA DE GERENTES DA EMPRESA -----" << endl;
    for (int i = 0; i < listaGerentes.size(); i++)
    { // Lê cada posicao do vetor de Gerentes e em seguida imprime todos os atributos:
        cout << "Gerente numero: " << i + 1 << ":" << endl;
        cout << "Nome: " << listaGerentes[i].getNome() << endl;
        cout << "CPF: " << listaGerentes[i].getCpf() << endl;
        cout << "Data de nascimento: " << listaGerentes[i].getDataNascimento().dia << "/" << listaGerentes[i].getDataNascimento().mes << "/" << listaGerentes[i].getDataNascimento().ano << endl;
        cout << "Endereço: " << listaGerentes[i].getEnderecoPessoal().cidade << ", " << listaGerentes[i].getEnderecoPessoal().bairro << ", " << listaGerentes[i].getEnderecoPessoal().cep
             << ", Rua " << listaGerentes[i].getEnderecoPessoal().rua << ", " << listaGerentes[i].getEnderecoPessoal().numero << endl;
        cout << "Estado civil: " << listaGerentes[i].getEstadoCivil() << endl;
        cout << "Quantidade de filhos " << listaGerentes[i].getQuantFilhos() << endl;
        cout << "Matricula: " << listaGerentes[i].getMatricula() << endl;
        cout << "Salario: " << listaGerentes[i].getSalario() << endl;
        cout << "Data de ingresso: " << listaGerentes[i].getIngressoEmpresa().dia << "/" << listaGerentes[i].getIngressoEmpresa().mes << "/" << listaGerentes[i].getIngressoEmpresa().ano << endl;
        cout << "Participação nos lucros: " << listaGerentes[i].getParticipacaoLucros() << endl
             << endl;
    }
    cout << "----------------------------------------" << endl;
}
void Empresa::imprimeDono()
{
    cout << "\n----- DONO DA EMPRESA -----" << endl;
    cout << "Nome: " << dono.getNome() << endl;
    cout << "CPF: " << dono.getCpf() << endl;
    cout << "Data de nascimento: " << dono.getDataNascimento().dia << "/" << dono.getDataNascimento().mes << "/" << dono.getDataNascimento().ano << endl;
    cout << "Endereço: " << dono.getEnderecoPessoal().cidade << ", " << dono.getEnderecoPessoal().bairro << ", " << dono.getEnderecoPessoal().cep
         << ", Rua " << dono.getEnderecoPessoal().rua << ", " << dono.getEnderecoPessoal().numero << endl;
    cout << "Estado civil: " << dono.getEstadoCivil() << endl;
    cout << "Quantidade de filhos " << dono.getQuantFilhos() << endl;
    cout << "\n"
         << endl;
    cout << "----------------------------------------" << endl;
}
void Empresa::buscaFuncionario(int matricula)
{
    bool encontrou = false;

    // Buscando funcionario nos vetores de Asgs, vendedores e gerentes:

    for (int i = 0; i < asgs.size(); i++)
    { // Comparando matricula dos asgs
        if (stoi(simplificadorMatricula(asgs[i].getMatricula())) == matricula)
        {
            encontrou = true;
            cout << "\nFuncionário encontrado!\n-------ASG-------"
                 << endl;
            cout << "\nNOME: " << asgs[i].getNome() << endl
                 << endl;
        }
    }

    if (!encontrou)
    {
        for (int i = 0; i < vendedores.size(); i++)
        { // Comparando matricula dos vendedores
            if (stoi(simplificadorMatricula(vendedores[i].getMatricula())) == matricula)
            {
                encontrou = true;
                cout << "\nFuncionário encontrado!\n----VENDEDORES----"
                     << endl;
                cout << "\nNOME: " << vendedores[i].getNome() << endl;
            }
        }
    }
    if (!encontrou)
    {
        for (int i = 0; i < gerentes.size(); i++)
        { // Comparando matricula dos gerentes
            if (stoi(simplificadorMatricula(gerentes[i].getMatricula())) == matricula)
            {
                encontrou = true;
                cout << "\nFuncionário encontrado!\n----GERENTES-----"
                     << endl;
                cout << "\nNOME: " << gerentes[i].getNome() << endl;
            }
        }
    }
    if (!encontrou)
    {
        cout << "\nFuncionário não encontrado no sistema!\n"
             << endl;
    }
}
void Empresa::cacularSalarioFuncionario(int matricula)
{

    cout << "\nEntrando em calcular salario..." << endl;
    bool encontrou = false;
    float salario = 0;
    // Buscando funcionario nos vetores de Asgs, vendedores e gerentes:

    for (int i = 0; i < asgs.size(); i++)
    { // Comparando matricula dos asgs
        if (stoi(simplificadorMatricula(asgs[i].getMatricula())) == matricula)
        {
            encontrou = true;
            cout << "\nFuncionário encontrado!\n-------ASG-------"
                 << endl;
            cout << "\nCalcular Salario\nNOME: " << asgs[i].getNome() << endl;
            salario = asgs[i].calcularSalario(asgs[i].getQuantFaltas());
        }
    }
    if (!encontrou)
    {
        for (int i = 0; i < vendedores.size(); i++)
        { // Comparando matricula dos vendedores
            if (stoi(simplificadorMatricula(vendedores[i].getMatricula())) == matricula)
            {
                encontrou = true;
                cout << "\nFuncionário encontrado!\n-----VENDEDOR-----"
                     << endl;
                cout << "\nNOME: " << vendedores[i].getNome() << endl;
                salario = vendedores[i].calcularSalario(vendedores[i].getQuantFaltas());
            }
        }
    }
    if (!encontrou)
    {
        for (int i = 0; i < gerentes.size(); i++)
        { // Comparando matricula dos gerentes
            if (stoi(simplificadorMatricula(gerentes[i].getMatricula())) == matricula)
            {
                encontrou = true;
                cout << "\nFuncionário encontrado!\n-----GERENTE-----"
                     << endl;
                cout << "\nNOME: " << gerentes[i].getNome() << endl;
                salario = gerentes[i].calcularSalario(gerentes[i].getQuantFaltas());
            }
        }
    }
    if (encontrou)
    {
        cout << "Salário: " << salario << endl;
    }
    if (!encontrou)
    {
        cout << "\nFuncionário não encontrado no sistema!\n"
             << endl;
    }
}
void Empresa::calcularTodoOsSalarios()
{
    cout << "Entrou em calcular todos os salarios" << endl;
    fstream arq;
    cout << "\n";
    arq.open("./Arquivos/Escrita/relatorio.txt", ios::out);
    if (!arq.is_open())
        throw std::runtime_error("Erro ao abrir o arquivo.");
    else
    {
        arq << "######### Relatório Financeiro ########\n"
            << endl; // Já começa a salva no arquivo
        double total = 0, totalGeral = 0;
        arq << "Cargo: ASG" << endl;
        for (int i = 0; i < asgs.size(); i++) // Aqui começa a gravar todos os dados dos ASGS
        {
            float salario = asgs[i].calcularSalario(0);
            arq << asgs[i].getMatricula() << " - " << asgs[i].getNome() << " - R$ " << salario << endl;
            total += salario;
            if (i == asgs.size() - 1) // Quando chegar no ultimo
            {
                arq << "Total ASG: R$ " << total << endl; // Grava o total
                totalGeral += total;                      // E adiciona no total geral
                total = 0;                                // Zera a variavel para o próximo tipo
            }
        }
        arq << "" << endl;
        arq << "Cargo: Vendedor" << endl;
        for (int i = 0; i < vendedores.size(); i++)
        {
            float salario = vendedores[i].calcularSalario(0);
            arq << vendedores[i].getMatricula() << " - " << vendedores[i].getNome() << " - R$ " << salario << endl;
            total += salario;
            if (i == vendedores.size() - 1)
            {
                arq << "Total Vendedores: R$ " << total << endl;
                totalGeral += total;
                total = 0;
            }
        }
        arq << "" << endl;
        arq << "Cargo: Gerente" << endl;
        for (int i = 0; i < gerentes.size(); i++)
        {
            float salario = gerentes[i].calcularSalario(0);
            arq << gerentes[i].getMatricula() << " - " << gerentes[i].getNome() << " - R$ " << salario << endl;
            total += salario;
            if (i == gerentes.size() - 1)
            {
                arq << "Total Gerentes: R$ " << total << endl;
                totalGeral += total;
                total = 0;
            }
        }
        arq << "" << endl;
        arq << "CUSTO TOTAL DE RH: R$ " << totalGeral << endl; // Grava o total geral
    }
    arq.close();
    arq.open("./Arquivos/Escrita/relatorio.txt", ios::in);
    if (!arq.is_open())
        throw std::runtime_error("Erro ao abrir o arquivo.");
    else
    {
        cout << "Lendo arquivo relatorio\n"
             << endl;
        string linha;
        while (getline(arq, linha)) // Lê todo o arquivo p imprimir pro usuario
            cout << linha << endl;
    }
}
void Empresa::calcularRecisao(int matricula, Data desligamento)
{
    cout << "Entrando em calcular recisão..." << endl;
    bool encontrou = false;
    Data ingresso;
    float recisao = 0;
    // Buscando funcionario nos vetores de Asgs, vendedores e gerentes:

    for (int i = 0; i < asgs.size(); i++)
    { // Comparando matricula dos asgs
        if (stoi(simplificadorMatricula(asgs[i].getMatricula())) == matricula)
        {
            encontrou = true;
            cout << "\nFuncionário encontrado!\n-------ASG-------"
                 << endl;
            cout << "\nNOME: " << asgs[i].getNome() << endl;
            recisao = asgs[i].calcularRecisao(desligamento);
            ingresso = asgs[i].getIngressoEmpresa();
        }
    }

    if (!encontrou)
    {
        for (int i = 0; i < vendedores.size(); i++)
        { // Comparando matricula dos vendedores
            if (stoi(simplificadorMatricula(vendedores[i].getMatricula())) == matricula)
            {
                encontrou = true;
                cout << "\nFuncionário encontrado!\n-----VENDEDOR-----"
                     << endl;
                cout << "\nNOME: " << vendedores[i].getNome() << endl;
                recisao = vendedores[i].calcularRecisao(desligamento);
                ingresso = vendedores[i].getIngressoEmpresa();
            }
        }
    }
    if (!encontrou)
    {
        for (int i = 0; i < gerentes.size(); i++)
        { // Comparando matricula dos gerentes
            if (stoi(simplificadorMatricula(gerentes[i].getMatricula())) == matricula)
            {
                encontrou = true;
                cout << "\nFuncionário encontrado!\n-----GERENTE-----"
                     << endl;
                cout << "\nNOME: " << gerentes[i].getNome() << endl;
                recisao = gerentes[i].calcularRecisao(desligamento);
                ingresso = gerentes[i].getIngressoEmpresa();
            }
        }
    }
    if (encontrou)
    {
        if ((ingresso.mes > desligamento.mes) && (ingresso.ano >= desligamento.ano) || (ingresso.mes >= desligamento.mes) && (ingresso.ano > desligamento.ano))
        {
            throw std::runtime_error("A data de desligamento é inferior a data de ingresso, não é possivel calcular recisão");
        }
        else
        {
            cout << "Recisão: " << recisao << endl;
        }
    }
    if (!encontrou)
    {
        cout << "\nFuncionário não encontrado no sistema!\n"
             << endl;
    }
}
void Empresa::demitirFuncionario(int matricula, Data desligamento)
{
    cout << "\nEntrou em demitir funcionario\n"
         << endl;
    bool encontrou = false;
    float recisao = 0;
    string cargo, matriculaFuncionario;
    Data ingresso;
    Pessoa funcionario;
    fstream arquivo;
    int anosTrabalhados = 0, mesesTrabalhados = 0, diasTrabalhados = 0, posicaoFuncionario;
    // Buscando funcionario nos vetores de Asgs, vendedores e gerentes:

    for (int i = 0; i < asgs.size(); i++)
    { // Comparando matricula dos asgs
        if (stoi(simplificadorMatricula(asgs[i].getMatricula())) == matricula)
        {
            encontrou = true;
            recisao = asgs[i].calcularRecisao(desligamento);
            cargo = "ASG";
            matriculaFuncionario = asgs[i].getMatricula();
            ingresso = asgs[i].getIngressoEmpresa();
            funcionario = asgs[i];
            posicaoFuncionario = i;
        }
    }
    if (!encontrou)
    {
        for (int i = 0; i < vendedores.size(); i++)
        { // Comparando matricula dos vendedores

            if (stoi(simplificadorMatricula(vendedores[i].getMatricula())) == matricula)
            {
                encontrou = true;
                recisao = vendedores[i].calcularRecisao(desligamento);
                cargo = "Vendedor";
                matriculaFuncionario = vendedores[i].getMatricula();
                ingresso = vendedores[i].getIngressoEmpresa();
                funcionario = vendedores[i];
                posicaoFuncionario = i;
            }
        }
    }
    if (!encontrou)
    {
        for (int i = 0; i < gerentes.size(); i++)
        { // Comparando matricula dos gerentes
            if (stoi(simplificadorMatricula(gerentes[i].getMatricula())) == matricula)
            {
                encontrou = true;
                recisao = gerentes[i].calcularRecisao(desligamento);
                cargo = "Gerente";
                matriculaFuncionario = gerentes[i].getMatricula();
                ingresso = gerentes[i].getIngressoEmpresa();
                funcionario = gerentes[i];
                posicaoFuncionario = i;
            }
        }
    }
    if (encontrou)
    {
        if ((ingresso.mes > desligamento.mes) && (ingresso.ano >= desligamento.ano) || (ingresso.mes >= desligamento.mes) && (ingresso.ano > desligamento.ano))
            throw std::runtime_error("A data de desligamento é inferior a data de ingresso, não é possivel calcular recisão");
    }
    if (!encontrou)
        throw std::runtime_error("Funcionario não encontrado");
    else
    {
        arquivo.open("./Arquivos/Escrita/relatorioDemissional.txt", ios::out);

        if (!arquivo)
            throw std::runtime_error("Erro ao abrir o arquivo.");
        else
        {
            string linha;
            arquivo << "##############################\n    Relatorio Demissional\n##############################\n";
            arquivo << "Cargo: " << cargo << "\n";
            arquivo << "Nome: " << funcionario.getNome() << "\n";
            arquivo << "CPF: " << funcionario.getCpf() << "\n";
            arquivo << "Matricula: " << matriculaFuncionario << "\n";
            arquivo << "Data de ingresso: " << ingresso.dia << "/" << ingresso.mes << "/" << ingresso.ano << "\n";
            arquivo << "Data de desligamento: " << desligamento.dia << "/" << desligamento.mes << "/" << desligamento.ano << "\n";
            arquivo << "******************************\nValor de rescisao: R$ " << recisao << "\n******************************\n";

            anosTrabalhados = fabs(ingresso.ano - desligamento.ano) - 1;
            mesesTrabalhados = ingresso.mes - desligamento.mes;
            if (desligamento.dia > ingresso.dia)
                diasTrabalhados = desligamento.dia - ingresso.dia;
            if (desligamento.dia < ingresso.dia)
                diasTrabalhados = 30 + (desligamento.dia - ingresso.dia);
            if (mesesTrabalhados == 0 && anosTrabalhados >= 1)
                mesesTrabalhados = 12;
            if (mesesTrabalhados > 0)
                mesesTrabalhados = 12 - mesesTrabalhados;
            if (mesesTrabalhados < 0)
                mesesTrabalhados = 12 + fabs(mesesTrabalhados);

            arquivo << "Tempo de trabalho: " << anosTrabalhados << " anos, " << mesesTrabalhados << " meses e " << diasTrabalhados << " dias";
        }
        arquivo.close();
        arquivo.open("./Arquivos/Escrita/relatorioDemissional.txt", ios::in);
        string linha;
        if (!arquivo)
            throw std::runtime_error("Erro ao abrir o arquivo.");
        else
        {
            while (getline(arquivo, linha))
                cout << linha << endl;
        }
        arquivo.close();
    }
    int contador = 0;

    if (cargo == "ASG")
    {
        arquivo.open("./Arquivos/Leitura/asg.txt", ios::out);
        if (!arquivo.is_open())
            throw std::runtime_error("Erro ao abrir o arquivo de ASG");
        for (int i = 0; i < asgs.size(); i++)
        {
            if (i != posicaoFuncionario)
            {
                arquivo << "#########################################################\nASG Nº : " << contador << "\n#####DADOS PESSOAIS#####\n";
                arquivo << asgs[i].getNome() << "\n"
                        << asgs[i].getCpf() << "\n"
                        << asgs[i].getQuantFilhos() << "\n"
                        << asgs[i].getEstadoCivil() << endl;
                arquivo << "*****Endereço(cidade, cep, bairro, rua e numero) *****\n";
                arquivo << asgs[i].getEnderecoPessoal().cidade << "\n"
                        << asgs[i].getEnderecoPessoal().cep << "\n"
                        << asgs[i].getEnderecoPessoal().bairro << "\n"
                        << asgs[i].getEnderecoPessoal().rua << "\n"
                        << asgs[i].getEnderecoPessoal().numero << endl;
                arquivo << "*****Data de nascimento(ano, mes, dia) ****\n";
                arquivo << asgs[i].getDataNascimento().ano << "\n"
                        << asgs[i].getDataNascimento().mes << "\n"
                        << asgs[i].getDataNascimento().dia << endl;
                arquivo << "##### DADOS FUNCIONAIS #####\n";
                arquivo << asgs[i].getMatricula() << "\n"
                        << asgs[i].getSalario() << "\n"
                        << asgs[i].getAdicionalInsalubridade() << "\n"
                        << asgs[i].getQuantFaltas() << endl;
                arquivo << "***** Data de ingresso (ano, mes, dia) ****\n";
                arquivo << asgs[i].getIngressoEmpresa().ano << "\n"
                        << asgs[i].getIngressoEmpresa().mes << "\n"
                        << asgs[i].getIngressoEmpresa().dia << endl;
                contador++;
            }
        }
        asgs.erase(asgs.begin() + posicaoFuncionario);
    }
    if (cargo == "Vendedor")
    {
        arquivo.open("./Arquivos/Leitura/vendedor.txt", ios::out);
        if (!arquivo.is_open())
            throw std::runtime_error("Erro ao abrir o arquivo de vendedor");
        for (int i = 0; i < vendedores.size(); i++)
        {
            if (i != posicaoFuncionario)
            {
                arquivo << "#########################################################\nVENDEDOR Nº :" << contador << "\n#####DADOS PESSOAIS#####\n";
                arquivo << vendedores[i].getNome() << endl;
                arquivo << vendedores[i].getCpf() << endl;
                arquivo << vendedores[i].getQuantFilhos() << endl;
                arquivo << vendedores[i].getEstadoCivil() << endl;
                arquivo << "*****Endereço(cidade, cep, bairro, rua e numero) *****\n";
                arquivo << vendedores[i].getEnderecoPessoal().cidade << endl;
                arquivo << vendedores[i].getEnderecoPessoal().cep << endl;
                arquivo << vendedores[i].getEnderecoPessoal().bairro << endl;
                arquivo << vendedores[i].getEnderecoPessoal().rua << endl;
                arquivo << vendedores[i].getEnderecoPessoal().numero << endl;
                arquivo << "*****Data de nascimento(ano, mes, dia) ****\n";
                arquivo << vendedores[i].getDataNascimento().ano << endl;
                arquivo << vendedores[i].getDataNascimento().mes << endl;
                arquivo << vendedores[i].getDataNascimento().dia << endl;
                arquivo << "##### DADOS FUNCIONAIS #####\n";
                arquivo << vendedores[i].getMatricula() << endl;
                arquivo << vendedores[i].getSalario() << endl;
                arquivo << vendedores[i].getTipoVendedor() << endl;
                arquivo << vendedores[i].getQuantFaltas() << endl;
                arquivo << "***** Data de ingresso (ano, mes, dia) ****\n";
                arquivo << vendedores[i].getIngressoEmpresa().ano << endl;
                arquivo << vendedores[i].getIngressoEmpresa().mes << endl;
                arquivo << vendedores[i].getIngressoEmpresa().dia << endl;

                contador++;
            }
        }
        vendedores.erase(vendedores.begin() + posicaoFuncionario);
    }

    if (cargo == "Gerente")
    {
        arquivo.open("./Arquivos/Leitura/gerente.txt", ios::out);
        if (!arquivo.is_open())
            throw std::runtime_error("Erro ao abrir o arquivo de gerente");
        for (int i = 0; i < gerentes.size(); i++)
        {
            if (i != posicaoFuncionario)
            {
                arquivo << "#########################################################\nVENDEDOR Nº : " << contador << "\n#####DADOS PESSOAIS#####\n";
                arquivo << gerentes[i].getNome() << endl;
                arquivo << gerentes[i].getCpf() << endl;
                arquivo << gerentes[i].getQuantFilhos() << endl;
                arquivo << gerentes[i].getEstadoCivil() << endl;
                arquivo << "*****Endereço(cidade, cep, bairro, rua e numero) *****\n";
                arquivo << gerentes[i].getEnderecoPessoal().cidade << endl;
                arquivo << gerentes[i].getEnderecoPessoal().cep << endl;
                arquivo << gerentes[i].getEnderecoPessoal().bairro << endl;
                arquivo << gerentes[i].getEnderecoPessoal().rua << endl;
                arquivo << gerentes[i].getEnderecoPessoal().numero << endl;
                arquivo << "*****Data de nascimento(ano, mes, dia) ****\n";
                arquivo << gerentes[i].getDataNascimento().ano << endl;
                arquivo << vendedores[i].getDataNascimento().mes << endl;
                arquivo << vendedores[i].getDataNascimento().dia << endl;
                arquivo << "##### DADOS FUNCIONAIS #####\n";
                arquivo << gerentes[i].getMatricula() << endl;
                arquivo << gerentes[i].getSalario() << endl;
                arquivo << gerentes[i].getParticipacaoLucros() << endl;
                arquivo << gerentes[i].getQuantFaltas() << endl;
                arquivo << "***** Data de ingresso (ano, mes, dia) ****\n";
                arquivo << gerentes[i].getIngressoEmpresa().ano << endl;
                arquivo << gerentes[i].getIngressoEmpresa().mes << endl;
                arquivo << gerentes[i].getIngressoEmpresa().dia << endl;

                contador++;
            }
        }
        gerentes.erase(gerentes.begin() + posicaoFuncionario);
    }
    arquivo.close();

    cout << "\nArquivo do funcionario atualizado com sucesso" << endl;
}
void Empresa::contratarFuncionario()
{

    cout << "Contratar Funcionario " << endl;
    string linha, cargo;
    int contador = 0;
    vector<string> palavras;

    fstream arq;
    arq.open("./Arquivos/Leitura/novoFuncionario.txt", ios::in);
    if (!arq.is_open())
        throw std::runtime_error("Erro ao abrir o arquivo de novo funcionario");
    while (getline(arq, linha))
    {
        if (contador == 0)
            cargo = linha;

        if ((linha[0] != '#') && (linha[0] != '*') && contador != 0)
            palavras.push_back(linha);

        contador++;

        for (int i = 0; i < cargo.length(); i++)
            cargo[i] = toupper(cargo[i]);

        if (contador == 24)
        {
            if (cargo == "ASG")
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

                int i = asgs.size() - 1;

                fstream arquivo;
                arquivo.open("./Arquivos/Leitura/asg.txt", ios::out | ios::app);
                arquivo << "#########################################################\nASG Nº : " << asgs.size() - 1 << "\n#####DADOS PESSOAIS#####\n";
                arquivo << asgs[i].getNome() << "\n"
                        << asgs[i].getCpf() << "\n"
                        << asgs[i].getQuantFilhos() << "\n"
                        << asgs[i].getEstadoCivil() << endl;
                arquivo << "*****Endereço(cidade, cep, bairro, rua e numero) *****\n";
                arquivo << asgs[i].getEnderecoPessoal().cidade << "\n"
                        << asgs[i].getEnderecoPessoal().cep << "\n"
                        << asgs[i].getEnderecoPessoal().bairro << "\n"
                        << asgs[i].getEnderecoPessoal().rua << "\n"
                        << asgs[i].getEnderecoPessoal().numero << endl;
                arquivo << "*****Data de nascimento(ano, mes, dia) ****\n";
                arquivo << asgs[i].getDataNascimento().ano << "\n"
                        << asgs[i].getDataNascimento().mes << "\n"
                        << asgs[i].getDataNascimento().dia << endl;
                arquivo << "##### DADOS FUNCIONAIS #####\n";
                arquivo << asgs[i].getMatricula() << "\n"
                        << asgs[i].getSalario() << "\n"
                        << asgs[i].getAdicionalInsalubridade() << "\n"
                        << asgs[i].getQuantFaltas() << endl;
                arquivo << "***** Data de ingresso (ano, mes, dia) ****\n";
                arquivo << asgs[i].getIngressoEmpresa().ano << "\n"
                        << asgs[i].getIngressoEmpresa().mes << "\n"
                        << asgs[i].getIngressoEmpresa().dia << endl;

                arquivo.close();

                cout << "\n#######################\nFuncionario contratado com sucesso!\n#######################\n";
                cout << "Nome: " << asgs[i].getNome() << endl;
                cout << "CPF: " << asgs[i].getCpf() << endl;
                cout << "Data de nascimento: " << asgs[i].getDataNascimento().dia << "/" << asgs[i].getDataNascimento().mes << "/" << asgs[i].getDataNascimento().ano << endl;
                cout << "Matricula: " << asgs[i].getMatricula() << endl;
                cout << "Salario: " << asgs[i].getSalario() << endl;
                cout << "########################################\n";
            }
            else if (cargo == "VENDEDOR")
            {
                char tipoVendedor = (palavras[14])[0]; // Como a linha é uma string, ele pega apenas a primeira posição
                                                       // ai fica um char
                try                                    // Caso não consiga converter alguma linha, tive muito problema com isso ;)
                {
                    Vendedor vendedor(palavras[0], palavras[1], palavras[3],
                                      stoi(palavras[11]), stoi(palavras[10]), stoi(palavras[9]), palavras[4],
                                      palavras[6], palavras[7], palavras[5],
                                      stoi(palavras[8]), stoi(palavras[2]), palavras[13],
                                      palavras[12], stoi(palavras[18]), stoi(palavras[17]),
                                      stoi(palavras[16]), tipoVendedor, stoi(palavras[15]));

                    this->vendedores.push_back(vendedor);
                }
                catch (invalid_argument &e)
                {
                    cout << "Não foi possivel carregar vendedor, erro ao converter um dos parametros para número" << endl;
                }

                palavras.clear();

                int i = vendedores.size() - 1;

                fstream arquivo;
                arquivo.open("./Arquivos/Leitura/vendedor.txt", ios::out | ios::app);
                if (!arquivo.is_open())
                    throw runtime_error("Erro ao abrir arquivo do Vendedor");

                arquivo << "#########################################################\nVENDEDOR Nº :" << i << "\n#####DADOS PESSOAIS#####\n";
                arquivo << vendedores[i].getNome() << endl;
                arquivo << vendedores[i].getCpf() << endl;
                arquivo << vendedores[i].getQuantFilhos() << endl;
                arquivo << vendedores[i].getEstadoCivil() << endl;
                arquivo << "*****Endereço(cidade, cep, bairro, rua e numero) *****\n";
                arquivo << vendedores[i].getEnderecoPessoal().cidade << endl;
                arquivo << vendedores[i].getEnderecoPessoal().cep << endl;
                arquivo << vendedores[i].getEnderecoPessoal().bairro << endl;
                arquivo << vendedores[i].getEnderecoPessoal().rua << endl;
                arquivo << vendedores[i].getEnderecoPessoal().numero << endl;
                arquivo << "*****Data de nascimento(ano, mes, dia) ****\n";
                arquivo << vendedores[i].getDataNascimento().ano << endl;
                arquivo << vendedores[i].getDataNascimento().mes << endl;
                arquivo << vendedores[i].getDataNascimento().dia << endl;
                arquivo << "##### DADOS FUNCIONAIS #####\n";
                arquivo << vendedores[i].getMatricula() << endl;
                arquivo << vendedores[i].getSalario() << endl;
                arquivo << vendedores[i].getTipoVendedor() << endl;
                arquivo << vendedores[i].getQuantFaltas() << endl;
                arquivo << "***** Data de ingresso (ano, mes, dia) ****\n";
                arquivo << vendedores[i].getIngressoEmpresa().ano << endl;
                arquivo << vendedores[i].getIngressoEmpresa().mes << endl;
                arquivo << vendedores[i].getIngressoEmpresa().dia << endl;

                arquivo.close();

                cout << "\n#######################\nFuncionario contratado com sucesso!\n#######################\n";
                cout << "Nome: " << vendedores[i].getNome() << endl;
                cout << "CPF: " << vendedores[i].getCpf() << endl;
                cout << "Data de nascimento: " << vendedores[i].getDataNascimento().dia << "/" << vendedores[i].getDataNascimento().mes << "/" << vendedores[i].getDataNascimento().ano << endl;
                cout << "Matricula: " << vendedores[i].getMatricula() << endl;
                cout << "Salario: " << vendedores[i].getSalario() << endl;
                cout << "########################################\n";
            }
            else if (cargo == "GERENTE")
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

                int i = gerentes.size() - 1;

                fstream arquivo;
                arquivo.open("./Arquivos/Leitura/gerente.txt", ios::out | ios::app);
                if (!arquivo.is_open())
                    throw runtime_error("Erro ao abrir arquivo dos Gerentes");

                arquivo << "#########################################################\nVENDEDOR Nº : " << contador << "\n#####DADOS PESSOAIS#####\n";
                arquivo << gerentes[i].getNome() << endl;
                arquivo << gerentes[i].getCpf() << endl;
                arquivo << gerentes[i].getQuantFilhos() << endl;
                arquivo << gerentes[i].getEstadoCivil() << endl;
                arquivo << "*****Endereço(cidade, cep, bairro, rua e numero) *****\n";
                arquivo << gerentes[i].getEnderecoPessoal().cidade << endl;
                arquivo << gerentes[i].getEnderecoPessoal().cep << endl;
                arquivo << gerentes[i].getEnderecoPessoal().bairro << endl;
                arquivo << gerentes[i].getEnderecoPessoal().rua << endl;
                arquivo << gerentes[i].getEnderecoPessoal().numero << endl;
                arquivo << "*****Data de nascimento(ano, mes, dia) ****\n";
                arquivo << gerentes[i].getDataNascimento().ano << endl;
                arquivo << vendedores[i].getDataNascimento().mes << endl;
                arquivo << vendedores[i].getDataNascimento().dia << endl;
                arquivo << "##### DADOS FUNCIONAIS #####\n";
                arquivo << gerentes[i].getMatricula() << endl;
                arquivo << gerentes[i].getSalario() << endl;
                arquivo << gerentes[i].getParticipacaoLucros() << endl;
                arquivo << gerentes[i].getQuantFaltas() << endl;
                arquivo << "***** Data de ingresso (ano, mes, dia) ****\n";
                arquivo << gerentes[i].getIngressoEmpresa().ano << endl;
                arquivo << gerentes[i].getIngressoEmpresa().mes << endl;
                arquivo << gerentes[i].getIngressoEmpresa().dia << endl;

                arquivo.close();
                cout << "\n#######################\nFuncionario contratado com sucesso!\n#######################\n";
                cout << "Nome: " << gerentes[i].getNome() << endl;
                cout << "CPF: " << gerentes[i].getCpf() << endl;
                cout << "Data de nascimento: " << gerentes[i].getDataNascimento().dia << "/" << gerentes[i].getDataNascimento().mes << "/" << gerentes[i].getDataNascimento().ano << endl;
                cout << "Matricula: " << gerentes[i].getMatricula() << endl;
                cout << "Salario: " << gerentes[i].getSalario() << endl;
                cout << "########################################\n";
            }
        }
    }
    arq.close();
}
