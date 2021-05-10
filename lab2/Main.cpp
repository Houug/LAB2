#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <Windows.h>
#include "Clinic.h"
#include "functions.h"
#include "Data.h"

#define path "data.txt"
using namespace std;

int Clinic::count = 0;

int main()
{
	setlocale(LC_ALL, "Russian");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	FILE* data;
	Clinic* arr = new Clinic[0];
	Clinic** parr = &arr;
	char prot[10];

	// Load/create database
	if ((data = fopen(path, "r")) == 0)
	{
		printf("Файл не открылся!\n");
		if (!(data = fopen(path, "a")) == 0)
		{
			printf("Создание нового файла!\n");
			createData(parr, &data);
			fclose(data);
		}
		else
		{
			printf("Обратитесь к администратору!\n");
			return 0;
		}
	}
	else
	{
		data = fopen(path, "r");
		loadData(arr, data);
		fclose(data);
	}

	// Menu
	do
	{
		int menu;
		printf("%d\n", arr->getCount());
		printMenu();
		printf("Выберите пункт меню: ");
		scanf("%1d", &menu);

		gets_s(prot);//??????

		switch (menu)
		{
		case 1:
			data = fopen(path, "a");
			arr->addDoctor(arr, data);
			fclose(data);
			break;
		case 2:
			findDoctor(arr);
			break;
		case 3:
			arr->filterDoctor();
			break;
		case 4:
			arr->sortData();
			break;
		case 5:
			arr->printAllDoctors();
			break;
		case 6:
			arr->doStandardObject(arr);
			break;
		case 7:
			data = fopen(path, "w");
			saveData(arr, data);
			fclose(data);
			delete[] arr;
			return 0;
		default:
			printf("Введенный вами пункт меню не существует\n");
			break;
		}
	} while (TRUE);
}