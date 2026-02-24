#include<stdio.h>
#include<windows.h>
#include "utils.h"

void show_loading(const char* message, int duration_ms){
    char spinner[] = {'|','/','-','\\'};
    int spinner_index =0;

    //(10 frames/second)
    int frames = duration_ms/100;

    for(int i=0; i<frames; i++){

        printf("\r[%c] %s", spinner[spinner_index], message);
        fflush(stdout);

        spinner_index = (spinner_index +1) %4;

        Sleep(100);
    }

    printf("\r");

    for(int i=0;i<50;i++){
        printf(" ");
    }

    printf("\r");
    fflush(stdout);
}