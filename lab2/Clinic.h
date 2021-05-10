#pragma once
#include "Fio.h"
#include <stdio.h>

class Clinic
{
	int specialty;
	int qualification;
public:
	Fio fio;
	static int count;

	friend Clinic findDoctor(Clinic* m);
	friend void equate(Clinic& obj1, const Clinic& obj2);
	friend class Fio;

	Clinic();
	Clinic(char* surname, char* name, char* father, int spec, int qual);
	Clinic(Clinic& obj);
	~Clinic();
	
	int getSpecialtyId();
	int getQualificationId();
	int getCount();

	void setSpecialtyId(int spec);
	void inputSpecialtyId();

	void setQualificationId(int qual);
	void inputQualificationId();

	void addDoctor(Clinic*& m, FILE* data);
	void printAllDoctors();

	void doStandardObject(Clinic*& m);
	void sortData();
	void filterDoctor();

private:
	void printDoctor(int n);
};

