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