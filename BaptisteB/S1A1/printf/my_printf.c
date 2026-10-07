#include <stdbool.h>
#include <unistd.h>
#include <string.h>
#include <stdarg.h>
#include <stdlib.h>
#include <stdio.h>

char * decTo(long valeur, int base){
    char * str = malloc(11);
    int index = 0;
    while (valeur!=0){
        str[index] = valeur%base + '0';
        if (str[index] > '9'){
            str[index] += 39;
        }
        valeur/=base;
        index++;
    }
    int t;
    for (int i = 0, j = strlen(str)-1; j>i;i++,j--){
        t = str[i];
        str[i] = str[j];
        str[j] = t;
    }
    return str;
}

int print(char* str){
    int compteur = 0;
    for (int i = 0; i<strlen(str);i++){
        write(1, &(char){str[i]}, 1);
        compteur++;
    };
    return compteur;    
}

int my_printf(char* restrict str, ...){
    va_list arguments;
    va_start(arguments,str);
    bool pourcent = false;
    int compteur = 0;
    for (int i = 0; i<strlen(str); i++){
        if (pourcent){
            pourcent = false;
            if (str[i] == '%'){
                write(1, &(char){'%'}, 1);
                compteur++;
            } else {
                if (str[i] == 'd'||str[i] == 'i'){
                    int argumentInt = va_arg(arguments, int);
                    if (argumentInt<0){
                        write(1, &(char){'-'}, 1);
                        compteur++;
                        argumentInt *= -1;
                    }
                    compteur += print(decTo(argumentInt,10));
                } else if (str[i] == 'u'){
                    compteur += print(decTo((unsigned int)va_arg(arguments, int),10));
                } else if (str[i] == 'o'){
                    compteur += print(decTo((unsigned int)va_arg(arguments, int),8));
                } else if (str[i] == 'x'){
                    compteur += print(decTo((unsigned int)va_arg(arguments, int),16));
                } else if (str[i] == 'c'){
                    write(1, &(char){va_arg(arguments, int)}, 1);
                    compteur++;
                } else if (str[i] == 's'){
                    compteur += print(va_arg(arguments, char*));
                } else if (str[i] == 'p'){
                    write(1, &(char){'0'}, 1);
                    write(1, &(char){'x'}, 1);
                    compteur += print(decTo((uintptr_t)va_arg(arguments, char*),16)) + 2;
                } else {
                    char * erreur = "\nErreur argument\n";
                    for (int j = 0; j<strlen(erreur);j++){
                        write(1, &(char){erreur[j]}, 1);
                    }
                    return 0;
                }
            }
        }else{
            if (str[i] == '%'){
                pourcent = true;
            } else {
                write(1, &str[i], 1);
                compteur++;
            }
        }
    }
    return compteur;
}

int main(){
    char* p;
    printf("%d",my_printf("%sefezf","-134"));
}