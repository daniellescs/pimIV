#include <stdlib.h>

int validaCaracteresAlfa(char texto[50]){
    int i;

    for (i = 0; texto[i] != '\0'; i++) {
        if (isalpha(texto[i])) {
            continue;
        }
        else if(isspace(texto[i])){
            continue;
        }
        else{
            return 0;
        }
    }

    //Passou nos testes
    return 1;

}

int validaNumerico(char texto[50]){
    int i;

    for (i = 0; texto[i] != '\0'; i++) {
        if (isdigit(texto[i])) {
            continue;
        }
        else{
            return 0;
        }
    }

    //Passou nos testes
    return 1;

}
