#pragma once
#include <stdio.h>
#include "Clinic.h"

void loadData(Clinic*& m, FILE* data);
void createData(Clinic**& m, FILE** data);
void saveData(Clinic* m, FILE* data);