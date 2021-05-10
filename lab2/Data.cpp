#define _CRT_SECURE_NO_WARNINGS
#include "Data.h"
#include "functions.h"

void loadData(Clinic*& m, FILE* data)
{
	int i = 0;
	printf("‘айл успешно открыт!\n");
	for (int i = 0; !feof(data); i++)
	{
		char bufName[20], bufSurname[20], bufFather[20];
		int spec, qual;

		fscanf(data, "%s %s %s %d %d", bufSurname, bufName, bufFather, &spec, &qual);

		int size = m->getCount();
		Clinic* temp = new Clinic[size + 1];
		for (int j = 0; j < size; j++)
		{
			equate(temp[j], m[j]);
			/*temp[j].fio.setSurname(m[j].fio.getSurname());
			temp[j].fio.setName(m[j].fio.getName());
			temp[j].fio.setFather(m[j].fio.getFather());

			temp[j].setSpecialtyId(m[j].getSpecialtyId());
			temp[j].setQualificationId(m[j].getQualificationId());*/
		}

		delete[] m;
		m = temp;

		m[i].fio.setSurname(bufSurname);
		m[i].fio.setName(bufName);
		m[i].fio.setFather(bufFather);

		m[i].setSpecialtyId(spec);
		m[i].setQualificationId(qual);
	}
}
void createData(Clinic**& m, FILE** data)
{
	char prot[10];
	int n;
	Clinic* arr = *m;
	do
	{
		printf("¬ведите кол-во позиций в базе: ");
		scanf("%2d", &n);
		gets_s(prot);//?????

	} while (checkInput());

	for (int i = 0; i < n; i++)
	{
		printf("\n¬вод элемента базы номер %d:\n", i + 1);
		arr->addDoctor(*m, *data);
	}
}
void saveData(Clinic* m, FILE* data)
{
	fprintf(data, "%s %s %s %d %d", m[0].fio.getSurname(), m[0].fio.getName(), m[0].fio.getFather(), m[0].getSpecialtyId(), m[0].getQualificationId());
	for (int i = 1; i < m->getCount(); i++)
	{
		fprintf(data, "\n%s %s %s %d %d", m[i].fio.getSurname(), m[i].fio.getName(), m[i].fio.getFather(), m[i].getSpecialtyId(), m[i].getQualificationId());
	}
}