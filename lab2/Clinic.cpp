#define _CRT_SECURE_NO_WARNINGS
#include "Clinic.h"
#include "Fio.h"
#include "functions.h"
#include <string.h>
#include <iostream>

Clinic::Clinic()
{
	this->count++;
	this->specialty = -1;
	this->qualification = -1;
}
Clinic::Clinic(char* surname, char* name, char* father, int spec, int qual)
{
	this->count++;
	this->fio.setFIO(surname, name, father);
	this->specialty = spec;
	this->qualification = qual;
}
Clinic::Clinic(Clinic& obj)
{
	this->count++;
	this->fio.setSurname(obj.fio.getSurname());
	this->fio.setName(obj.fio.getName());
	this->fio.setFather(obj.fio.getFather());
	this->specialty = obj.getSpecialtyId();
	this->qualification = obj.getQualificationId();
}
Clinic::~Clinic()
{
	count--;
}

int Clinic::getSpecialtyId()
{
	return this->specialty;
}
int Clinic::getQualificationId()
{
	return this->qualification;
}
int Clinic::getCount()
{
	return this->count;
}

void Clinic::setSpecialtyId(int spec)
{
	this->specialty = spec;
}
void Clinic::inputSpecialtyId()
{
	do
	{
		printf("Введите специальность (1-3): ");
		scanf("%1d", specialty);
		getchar();
	} while (checkInput(specialty, 0));
}

void Clinic::setQualificationId(int qual)
{
	this->qualification = qual;
}
void Clinic::inputQualificationId()
{
	do
	{
		printf("Введите квалификацию (0-2): ");
		scanf("%1d", qualification);
		getchar();
	} while (checkInput(qualification, 1));
}

void Clinic::addDoctor(Clinic*& m, FILE* data)
{
	int size = m->getCount();
	Clinic* temp = new Clinic[size + 1];
	for (int i = 0; i < size; i++)
	{
		equate(temp[i], m[i]);
	}

	delete[] m;
	m = temp;

	char bufName[20], bufSurname[20], bufFather[20], buf[60];
	int spec, qual;

	printf("Ввод фамилия: ");
	scanf("%[a-z,A-Z,а-я,А-Я,0-9]s", bufSurname);
	gets_s(buf);//?????

	printf("Ввод имя: ");
	scanf("%[a-z,A-Z,а-я,А-Я,0-9]s", bufName);
	gets_s(buf);//?????

	printf("Ввод отчество: ");
	scanf("%[a-z,A-Z,а-я,А-Я,0-9]s", bufFather);
	gets_s(buf);//?????

	int i = m->getCount() - 1;

	m[i].fio.setSurname(bufSurname);
	m[i].fio.setName(bufName);
	m[i].fio.setFather(bufFather);

	do
	{
		printf("Введите специальность (1-3): ");
		scanf("%1d", &spec);

		gets_s(buf);//?????

	} while (checkInput(spec, 0));

	m[i].setSpecialtyId(spec);

	do
	{
		printf("Введите квалификацию (0-2): ");
		scanf("%d", &qual);

		gets_s(buf);//?????

	} while (checkInput(qual, 1));

	m[i].setQualificationId(qual);

	if (i == 0)
	{
		fprintf(data, "%s %s %s %d %d", m[0].fio.getSurname(), m[0].fio.getName(), m[0].fio.getFather(), m[0].getSpecialtyId(), m[0].getQualificationId());
	}
	else
	{
		fprintf(data, "\n%s %s %s %d %d", m[i].fio.getSurname(), m[i].fio.getName(), m[i].fio.getFather(), m[i].getSpecialtyId(), m[i].getQualificationId());
	}
}

void Clinic::printDoctor(int n)
{
	char specialty[11], qualification[7];

	switch (this[n].getSpecialtyId())
	{
	case 1:
		strcpy(specialty, "Терапевт");
		break;
	case 2:
		strcpy(specialty, "Кардиолог");
		break;
	case 3:
		strcpy(specialty, "Стоматолог");
		break;
	default:
		strcpy(specialty, "NAN");
		break;
	}
	switch (this[n].getQualificationId())
	{
	case 0:
		strcpy(qualification, "Высшая");
		break;
	case 1:
		strcpy(qualification, "Первая");
		break;
	case 2:
		strcpy(qualification, "Вторая");
		break;
	default:
		strcpy(qualification, "NAN");
		break;
	}
	char buf[60];
	strcpy(buf, this[n].fio.getSurname());
	strcat(buf, " ");
	strcat(buf, this[n].fio.getName());
	strcat(buf, " ");
	strcat(buf, this[n].fio.getFather());
	printf("%40s %15s %15s\n", buf, specialty, qualification);
}
void Clinic::printAllDoctors()
{
	printHeader();
	for (int i = 0; i < this->getCount(); i++)
	{
		printDoctor(i);
	}
}

void Clinic::doStandardObject(Clinic*& m)
{
	char bufName[20], bufSurname[20], bufFather[20], buf[60];
	int spec, qual;

	printf("Ввод фамилия: ");
	scanf("%[a-z,A-Z,а-я,А-Я,0-9]s", bufSurname);
	gets_s(buf);//?????

	printf("Ввод имя: ");
	scanf("%[a-z,A-Z,а-я,А-Я,0-9]s", bufName);
	gets_s(buf);//?????

	printf("Ввод отчество: ");
	scanf("%[a-z,A-Z,а-я,А-Я,0-9]s", bufFather);
	gets_s(buf);//?????

	do
	{
		printf("Введите специальность (1-3): ");
		scanf("%1d", &spec);

		gets_s(buf);//?????

	} while (checkInput(spec, 0));

	do
	{
		printf("Введите квалификацию (0-2): ");
		scanf("%d", &qual);

		gets_s(buf);//?????

	} while (checkInput(qual, 1));

	Clinic standardObject(bufSurname, bufName, bufFather, spec, qual);

	int stdcount = 0;

	for (int i = 0; i < this->count - 1; i++)
	{
		if (strcmp(this[i].fio.getSurname(), standardObject.fio.getSurname()) == 0 &&
			strcmp(this[i].fio.getName(), standardObject.fio.getName()) == 0 &&
			strcmp(this[i].fio.getFather(), standardObject.fio.getFather()) == 0 &&
			this[i].getSpecialtyId() == standardObject.getQualificationId() &&
			this[i].getSpecialtyId() == standardObject.getSpecialtyId())
		{
			stdcount++;
		}
	}
	if (stdcount != 0)
	{
		printf("\nНайдено эталонных объектов: %d\n", stdcount);
	}
	else
	{
		int size = this->getCount() - 1;
		Clinic* temp = new Clinic[size + 1];
		for (int i = 0; i < size; i++)
		{
			equate(temp[i], m[i]);
		}

		delete[] m;
		m = temp;

		std::cout << m[size].getQualificationId();
		equate(m[size], standardObject);
		/*int size = this->getCount() - 1;
		Clinic* temp = new Clinic[size + 1];
		for (int i = 0; i < size; i++)
		{
			equate(temp[i], m[i]);
		}

		delete[] m;
		m = temp;




		int size = m->getCount() - 1;
		Clinic* temp = new Clinic[4];

		for (int i = 0; i < size; i++)
		{
			equate(temp[i], m[i]);
		}
		std::cout << temp[size + 1].getQualificationId();
		equate(temp[size + 1], standardObject);
		std::cout << temp[size + 1].getQualificationId();
		delete[] m;
		m = temp;*/

		
		printf("Т.к. эталонный объект не был найден, он создался!\n");
	}
}
void Clinic::sortData()
{
	Clinic* m = this;
	int min;
	int size = this->getCount();
	Clinic temp;

	char bufMin[60], bufJ[60];

	for (int i = 0; i < size; i++)
	{
		min = i;

		for (int j = i + 1; j < size; j++)
		{
			strcpy(bufMin, m[min].fio.getSurname());
			strcat(bufMin, " ");
			strcat(bufMin, m[min].fio.getName());
			strcat(bufMin, " ");
			strcat(bufMin, m[min].fio.getFather());

			strcpy(bufJ, m[j].fio.getSurname());
			strcat(bufJ, " ");
			strcat(bufJ, m[j].fio.getName());
			strcat(bufJ, " ");
			strcat(bufJ, m[j].fio.getFather());

			if (strcmp(bufMin, bufJ) > 0)
			{
				min = j;
			}
		}

		equate(temp, m[i]);
		equate(m[i], m[min]);
		equate(m[min], temp);
	}
}
void Clinic::filterDoctor()
{
	Clinic* m = this;
	char def[10];
	int spec = 0, qual = 0;
	int count = 0;

	do
	{
		printf("Введите специальность (1-3): ");
		scanf("%1d", &spec);
		gets_s(def); //?????
	} while (checkInput(spec, 0));

	do
	{
		printf("Введите квалификация (0-2): ");
		scanf("%1d", &qual);
		gets_s(def); //?????
	} while (checkInput(qual, 1));

	printHeader();
	for (int i = 0; i < this->getCount(); i++)
	{
		if ((spec == m[i].specialty) && (qual == m[i].qualification))
		{
			printDoctor(i);
			count++;
		}
	}
	if (count == 0) printf("Поиск не выдал результов\n");
}