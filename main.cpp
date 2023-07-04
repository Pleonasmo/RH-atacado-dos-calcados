/**
 * @author Maria Clara Fernandes de Oliveira
 * @author Pedro Rian Araújo da Silva
 * @details Repositório dedicado ao desenvolvimento de um sistema de RH para a empresa Atacado dos Calçados;
Projeto final da disciplina de Linguagem de Programação 1.
 * @date 2023-06-23
 */

#include <iostream>
#include "Empresa/Empresa.hpp"
#include "Util.hpp"

using namespace std;
int main(int argc, char const *argv[])
{

    Empresa *atacadoDosCalcado = new Empresa();
    try
    {
        atacadoDosCalcado->carregarFuncoes();
    }
    catch (int error)
    {
        if (error == 0)
        {
            cout << "Error ao abrir o arquivo funções." << endl;
        }
        else
        {
            std::cerr << error << '\n';
        }
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }

    return 0;
}