#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "paciente.c"
#include <stdio.h>

void cadastro()
{
    struct Paciente paciente;
    int opcaoComorbidade;
    int opcaoPossuiComorbidade = 0;
    int comorbidades[5];
    int qtdComorbidades = 0;

    //-----inicio captura dados paciente ------
    //Nome
    printf("Nome do paciente:");
    scanf("%s", paciente.nome);

    //Idade
    printf("Idade do paciente:");
    scanf("%d", paciente.idade);

    //cpf
    printf("Digite o CPF:");
    scanf("%s", paciente.cpf);

    //telefone
    printf("Telefone:");
    scanf("%s", paciente.telefone);

    //endereco
    printf("Endereço completo paciente \n");
    printf("Rua:");
    scanf("%s", paciente.endereco.rua);

    printf("Numero:");
    scanf("%s", paciente.endereco.numero);

    printf("Bairro:");
    scanf("%s", paciente.endereco.bairro);

    printf("Cidade:");
    scanf("%s", paciente.endereco.cidade);

    printf("CEP:");
    scanf("%s", paciente.endereco.cep);

    //data nascimento
    printf("Data nascimento do paciente:");
    scanf("%s", paciente.dataNascimento);

    //email
    printf("Email:");
    scanf("%s", paciente.email);

    //data diagnostico
    printf("Diagnosticado em:");
    scanf("%s", paciente.dataDiagnostico);

    printf("Possui alguma comorbidade?");
    scanf("%d", &opcaoPossuiComorbidade);
    int i = 0;
    switch(opcaoPossuiComorbidade){
        //CASO SIM
        case 1:
            while(i < 5){
                printf("Digite qual: \n");
                printf("[1] - DIABETES \n");
                printf("[2] - OBESIDADE \n");
                printf("[3] - HIPERTENSAO \n");
                printf("[4] - TUBERCULOSE \n");
                printf("[5] - OUTROS \n");
                printf("[0] - SAIR \n");
                scanf("%d", &opcaoComorbidade);
                if(opcaoComorbidade > 0 && opcaoComorbidade <= 5){
                    comorbidades[i] = opcaoComorbidade;
                    qtdComorbidades++;
                }else if(opcaoComorbidade == 0){
                    break;
                }else{
                    printf("Opcao invalida: \n");
                    continue;
                }
                i++;
            }
            break;
        //CASO NAO
        case 2:
            break;
        //CASO INVALIDO
        default:
            printf("Opcao invalida: \n");
    }

    for(int i = 0; i < 5; i++){
        if(comorbidades[i] > 0){
            paciente.comorbidades[i] = comorbidades[i];
        }
    }
    //-----FIM captura dados paciente ------

    //-----INICIO GRAVA ARQUIVO PACIENTES REGULARES---------
    FILE * pFile;
    pFile = fopen("pacientesRegulares.txt", "a");

    fprintf(pFile, "%s \n", "-----------------------");
    fprintf(pFile, "NOME: %s \n", paciente.nome);
    fprintf(pFile, "IDADE: %d \n", paciente.idade);
    fprintf(pFile, "CPF: %s \n", paciente.cpf);
    fprintf(pFile, "TELEFONE:  %s \n", paciente.telefone);
    fprintf(pFile, "RUA: %s \n", paciente.endereco.rua);
    fprintf(pFile, "NUMERO: %s \n", paciente.endereco.numero);
    fprintf(pFile, "BAIRRO: %s \n", paciente.endereco.bairro);
    fprintf(pFile, "CIDADE: %s \n", paciente.endereco.cidade);
    fprintf(pFile, "CEP: %s \n", paciente.endereco.cep);
    fprintf(pFile, "DATA NASCIMENTO: %s \n", paciente.dataNascimento);
    fprintf(pFile, "EMAIL: %s \n", paciente.email);
    fprintf(pFile, "DIAGNOSTICADO EM: %s \n", paciente.dataDiagnostico);

    fprintf(pFile, "%s \n", "Comorbidades: ");
    for(int i = 0; i < sizeof(paciente.comorbidades); i++){
        switch(paciente.comorbidades[i]){
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
    if(paciente.idade > 65 || sizeof(paciente.comorbidades) > 0){
        FILE * grupoRiscoArquivo;
        grupoRiscoArquivo = fopen("pacientesRisco.txt", "a");

        fprintf(pFile, "%s \n", "-----------------------");
        fprintf(pFile, "CEP: %s \n", paciente.endereco.cep);
        fprintf(pFile, "IDADE: %d \n", paciente.idade);
        fprintf(pFile, "%s \n", "-----------------------");
        fclose(pFile);
    }

    printf("Paciente: %s cadastrado com sucesso! \n\n", paciente.nome);
    //-----FIM GRAVA ARQUIVO PACIENTES GRUPO DE RISCO---------
    return 0;
}
