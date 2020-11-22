#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "paciente.c"
#include "validador.c"

void cadastro()
{
    struct Paciente paciente;
    int opcaoComorbidade;
    int opcaoPossuiComorbidade = 0;
    int comorbidades[5];
    int qtdComorbidades = 0;
    int anoBase = 2020;

    //-----inicio captura dados paciente ------

    do
    {
        //Nome
        fflush(stdin);
        printf("Nome do paciente:");
        gets(paciente.nome);

        if(validaCaracteresAlfa(paciente.nome) == 0){
            printf("Nome do paciente nao pode conter numeros ou caracteres especiais!\n");
        }
    }
    while(validaCaracteresAlfa(paciente.nome) == 0);


    do
    {
        //cpf
        fflush(stdin);
        printf("Digite o CPF:");
        gets(paciente.cpf);

        if(validaNumerico(paciente.cpf) == 0){
            printf("Insira somente numeros no CPF!\n");
        }
    }
    while(validaNumerico(paciente.cpf) == 0);

    //telefone
    fflush(stdin);
    printf("Telefone:");
    gets(paciente.telefone);

    //endereco
    fflush(stdin);
    printf("Endereco completo paciente \n");
    printf("Rua:");
    gets(paciente.endereco.rua);

    fflush(stdin);
    printf("Numero:");
    gets(paciente.endereco.numero);

    fflush(stdin);
    printf("Bairro:");
    gets(paciente.endereco.bairro);

    fflush(stdin);
    printf("Cidade:");
    gets(paciente.endereco.cidade);

    fflush(stdin);
    printf("CEP:");
    gets(paciente.endereco.cep);

    //data nascimento
    fflush(stdin);
    printf("Data nascimento do paciente \n");

    printf("Dia:");
    scanf("%d", &paciente.dataNascimento.dia);

    printf("Mes:");
    scanf("%d", &paciente.dataNascimento.mes);

    printf("Ano:");
    scanf("%d", &paciente.dataNascimento.ano);

    //email
    fflush(stdin);
    printf("Email:");
    gets(paciente.email);

    //data diagnostico
    fflush(stdin);
    printf("Data do diagnostico \n");

    printf("Dia:");
    scanf("%d", &paciente.dataDiagnostico.dia);

    printf("Mes:");
    scanf("%d", &paciente.dataDiagnostico.mes);

    printf("Ano:");
    scanf("%d", &paciente.dataDiagnostico.ano);

    fflush(stdin);
    printf("Possui alguma comorbidade? Digite 1 para SIM e 0 para NAO: ");
    scanf("%d", &opcaoPossuiComorbidade);


    int i = 0;
    if (opcaoPossuiComorbidade == 1)
    {
        while (i < 5)
        {
            printf("Digite qual: \n");
            printf("[1] - DIABETES \n");
            printf("[2] - OBESIDADE \n");
            printf("[3] - HIPERTENSAO \n");
            printf("[4] - TUBERCULOSE \n");
            printf("[5] - OUTROS \n");
            printf("[0] - SAIR \n");

            scanf("%d", &opcaoComorbidade);
            if (opcaoComorbidade > 0 && opcaoComorbidade <= 5)
            {
                comorbidades[i] = opcaoComorbidade;
                qtdComorbidades++;
                i++;
            }
            else if (opcaoComorbidade == 0)
            {
                break;
            }
            else
            {
                printf("Opcao invalida: \n");
                continue;
            }

        }
    }
    else if (opcaoPossuiComorbidade != 0){
        printf("Opcao invalida: \n");
    }

    for (int i = 0; i < 5; i++)
    {
        if (comorbidades[i] > 0)
        {
            paciente.comorbidades[i] = comorbidades[i];
        }
    }
    //-----FIM captura dados paciente ------

    //-----INICIO GRAVA ARQUIVO PACIENTES REGULARES---------
    FILE *pFile;
    pFile = fopen("pacientesRegulares.txt", "a");

    fprintf(pFile, "%s \n", "-----------------------");
    fprintf(pFile, "NOME: %s \n", paciente.nome);
    fprintf(pFile, "CPF: %s \n", paciente.cpf);
    fprintf(pFile, "TELEFONE:  %s \n", paciente.telefone);
    fprintf(pFile, "RUA: %s \n", paciente.endereco.rua);
    fprintf(pFile, "NUMERO: %s \n", paciente.endereco.numero);
    fprintf(pFile, "BAIRRO: %s \n", paciente.endereco.bairro);
    fprintf(pFile, "CIDADE: %s \n", paciente.endereco.cidade);
    fprintf(pFile, "CEP: %s \n", paciente.endereco.cep);
    fprintf(pFile, "DATA NASCIMENTO: %d/%d/%d \n", paciente.dataNascimento.dia, paciente.dataNascimento.mes, paciente.dataNascimento.ano);
    fprintf(pFile, "EMAIL: %s \n", paciente.email);
    fprintf(pFile, "DIAGNOSTICADO EM: %d/%d/%d \n", paciente.dataDiagnostico.dia, paciente.dataDiagnostico.mes, paciente.dataDiagnostico.ano);

    fprintf(pFile, "%s \n", "Comorbidades: ");
    for (int i = 0; i < sizeof(paciente.comorbidades); i++)
    {
        switch (paciente.comorbidades[i])
        {
        case 1:
            fprintf(pFile, "%s \n", "DIABETES");
            break;
        case 2:
            fprintf(pFile, "%s \n", "OBESIDADE");
            break;
        case 3:
            fprintf(pFile, "%s \n", "HIPERTENSAO");
            break;
        case 4:
            fprintf(pFile, "%s \n", "TUBERCULOSE");
            break;
        case 5:
            fprintf(pFile, "%s \n", "OUTROS");
            break;
        }
    }
    fprintf(pFile, "%s \n", "-----------------------");

    fclose(pFile);

    //-----FIM GRAVA ARQUIVO PACIENTES REGULARES---------


    //-----INICIO GRAVA ARQUIVO PACIENTES GRUPO DE RISCO---------
    if (anoBase - paciente.dataNascimento.ano > 65 || sizeof(paciente.comorbidades) > 0)
    {
        FILE *grupoRiscoArquivo;
        grupoRiscoArquivo = fopen("pacientesRisco.txt", "a");

        fprintf(pFile, "%s \n", "-----------------------");
        fprintf(pFile, "CEP: %s \n", paciente.endereco.cep);
        fprintf(pFile, "IDADE: %d \n", anoBase - paciente.dataNascimento.ano);
        fprintf(pFile, "%s \n", "-----------------------");
        fclose(pFile);
    }

    printf("Paciente: %s cadastrado com sucesso! \n\n", paciente.nome);
    //-----FIM GRAVA ARQUIVO PACIENTES GRUPO DE RISCO---------
    return 0;
}
