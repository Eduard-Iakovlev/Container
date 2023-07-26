#pragma once
#include <iostream>
#include <exception>
#include <string>

using namespace std;



class Badsize : public exception
{
public:
	virtual const char* what() const noexcept override;
};

class BadRange : public exception
{
public:
	virtual const char* what() const noexcept override;
};

class Conteiners
{
public:
	Conteiners() = default;
	Conteiners(int);
	Conteiners(const Conteiners&);

	int interLength();
	void interIndex(int*);
	void interIndexDel(int*);
	void completion();

	void reallocate(int);
	void resize(int);

	void incertElement(int);
	void deleteElement(bool*);
	void removeElement(int);
	void search();

	void showCont();

	int getLength() const;

	int& operator[](int);
	Conteiners& operator=(const Conteiners&);

	~Conteiners();
	void erace();
private:
	int _length{};
	int* _data{};
};