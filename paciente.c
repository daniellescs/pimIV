#include "endereco.c"
#include "data.c"

struct Paciente{
    char nome[50];
    char cpf[11];
    char telefone[11];
    struct Endereco endereco;
    struct Data dataNascimento;
    char email[50];
    struct Data dataDiagnostico;
    int comorbidades[5];
};
