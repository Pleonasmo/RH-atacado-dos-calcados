#include <iostream>
#ifndef UTIL
#define UTIL

typedef struct
{
    int dia,
        mes,
        ano;
} Data;

typedef struct{
    std::string bairro,
        cidade,
        rua,
        cep;
    int numero;
} Endereco;

#endif