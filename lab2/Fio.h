#pragma once
class Fio
{
	char* surname;
	char* name;
	char* father;
public:
	friend class Clinic;

	Fio();
	~Fio();

	char* getSurname();
	char* getName();
	char* getFather();

	void setSurname(char* surname);
	void setName(char* name);
	void setFather(char* father);
	
private:
	void setFIO(char* surname, char* name, char* father);
};