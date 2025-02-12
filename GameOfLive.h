#ifndef LIFE_H
#define LIFE_H

// libs to use :0

#include <stdlib.h>
#include <assert.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

// predefinitions

#define WIDTH  100
#define HEIGHT 50
#define CLEAR "\e[1;1H\e[2J"
#define SET_CURSOR   "\x1b[H"
#define CELL '*'

#define F fflush(stdout)
#define Clear printf("%s %s",CLEAR, SET_CURSOR )
static int running = 1;

// function prototypes
//cleares the screen and resets the pointer
void clear(){

printf("");

}

int main(int,char**);
void loop(void);
void printScreen(char*);
int getNabers(int index);
void applyRules(void);


#endif
