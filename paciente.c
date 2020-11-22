#include "endereco.c"

struct Paciente{
    char nome[50];
    char cpf[11];
    int idade[3];
    char telefone[11];
    struct Endereco endereco;
    char dataNascimento[8];
    char email[50];
    char dataDiagnostico[8];
    int comorbidades[5];
};
