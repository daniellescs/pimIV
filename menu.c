#include <stdio.h>
#include <stdlib.h>
#include "cadastro.c"

void menu()
{
    int opcao = 0;

    while(opcao == 0){
        printf("### MENU ### \n\n");
        printf("## ESCOLHA UMA OPCAO: ## \n\n");

        printf("#1 Cadastrar paciente# \n");
        //printf("#3 Listar pacientes# \n");
        printf("#9 SAIR# \n");

        scanf("%d", &opcao);

        switch(opcao){
            case 1 :
                cadastro();
                break;
            //case 3 :
              //  printf("Lista.");
                //break;
            case 9 :
                exit(0);
                break;
        }

        opcao = 0;
    }

    return 0;
}
