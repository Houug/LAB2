#pragma once
#include <cstdio>
#include <stdio.h>
#include "Clinic.h"

int checkInput(int n, int mode);
void printHeader();
void printMenu();
bool checkInput();
Clinic findDoctor(Clinic* m);
void equate(Clinic &obj1, Clinic &obj2);