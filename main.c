#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "menu.c"

int main()
{
    const char USUARIO[6] = "admin";
    const char SENHA[6] = "admin";

    char usuario[6];
    char senha[6];
    int logado = 0;

    printf("#### Bem vindo! Faca o login por gentileza. #### \n\n");

    while(logado == 0){

        printf("USUARIO: ");
        scanf("%s", &usuario);
        printf("SENHA: ");
        scanf("%s", &senha);
        printf("\n");

        if(strcmp(usuario, USUARIO) == 0){
            printf("Login bem sucedido! \n\n");
            logado = 1;
            menu();
        }
        else{
            printf("Usuario ou Senha invalidos.\n\n");
        }

    }

    exit(0);

}
