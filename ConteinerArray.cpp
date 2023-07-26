#include "ConteinerArray.h"

const char* Badsize::what() const noexcept
{
	return " Не корректный размер!!!";
}

const char* BadRange::what() const noexcept
{
	return " Не существующий индекс контейнера!!! \n размер контейнера: ";
}

Conteiners::Conteiners(int length) : _length{ length }
{
	_length = interLength();

	_data = new int[_length] {};
}
Conteiners::Conteiners(const Conteiners& c)
{
	reallocate(c.getLength());
	for (int i = 0; i < _length; ++i)
		_data[i] = c._data[i];
}

int Conteiners::interLength()
{
	int length;
	while (true)
	{
		try
		{
			cout << " введите размер контейнера в диапазоне 1 - 20: ";
			cin >> length;
			if ((length <= 0) || (length > 20)) throw Badsize();
			break;
		}

		catch (exception& e)
		{
			cout << e.what() << "\n";
			continue;
		}

	}
	return length;
}
void Conteiners::interIndex(int* i)
{
	while (true)
	{
		try
		{
			cout << " введите индекс 1-" << _length + 1 << ": ";
			cin >> *i;
			if ((*i <= 0) || (*i > _length + 1)) throw BadRange();
			break;
		}

		catch (exception& e)
		{
			cout << e.what() << "\n";
			continue;
		}
	}
	*i -= 1 ;
}
void Conteiners::interIndexDel(int* i)
{
	while (true)
	{
		try
		{
			cout << " введите индекс 1-" << _length << ": ";
			cin >> *i;
			if ((*i <= 0) || (*i > _length + 1)) throw BadRange();
			break;
		}

		catch (exception& e)
		{
			cout << e.what() << "\n";
			continue;
		}
	}
	*i -= 1 ;
}

void Conteiners::completion()
{
	for (int i = 0; i < _length; ++i)  _data[i] = rand() % 99;
}

void Conteiners::reallocate(int newLength)
{
	erace();
	_data = new int[newLength];
	_length = newLength;
}

void Conteiners::resize(int newLength)
{
	if (newLength == _length) return;
	int* data{ new int[newLength] };
	int elementsToCopy{ (newLength > _length) ? _length : newLength };
	for (int i = 0; i < elementsToCopy; ++i)

	data[i] = _data[i];
	delete[] _data;

	if (newLength > _length)
	{
		for (int i = _length; i < newLength; ++i) data[i] = 0;

	}

	_data = data;
	_length = newLength;

}

void Conteiners::incertElement(int element)
{
	int i{ 0 };
	interIndex(&i);
	int* data{ new int[_length + 1] };
	for (int before = 0; before < i; ++before) data[before] = _data[before];
	data[i] = element;

	for (int after = i; after < _length; ++after) data[after + 1] = _data[after];
	delete[] _data;
	_data = data;
	++_length;
}

void Conteiners::showCont()
{
	cout << "\n";
		for (int i = 0; i < _length; ++i)
		{
			cout << " " << i + 1 << ": " << _data[i];
			if (i < _length) cout << " | ";
			else cout << "\n\n";
		}

}

void Conteiners::deleteElement(bool* lenght)
{
	int i;
	interIndexDel(&i);
	if (_length == 1)
	{
		*lenght = false;
		erace();
		return;
	}
	int* data{ new int[_length - 1] };
	for (int before = 0; before < i ; ++before) data[before] = _data[before];
	for (int after{ i + 1 }; after < _length; ++after)	data[after - 1] = _data[after];

	delete[] _data;
	_data = data;
	--_length;
}

void Conteiners::removeElement(int element)
{
	int i{ 0 };
	interIndexDel(&i);
	int* data{ new int[_length + 1] };
	for (int before = 0; before < i; ++before) data[before] = _data[before];
	data[i] = element;

	for (int after = i + 1; after < _length; ++after) data[after] = _data[after];

	delete[] _data;
	_data = data;
}

void Conteiners::search()
{
	cout << " Введите искомое: ";
	bool search = false;
	int num;
	int i;
	cin >> num;

	for (int i = 0; i < _length; ++i)
	{
		if (num == _data[i])
		{
			cout << " Искомое " << num << " в ячейке " << i + 1 << "\n";
			search = true;
			break;
		}
	}
	if (search == false) cout << " Искомого значения нет в контейнере \n";
}

int Conteiners::getLength() const
{
	return _length;
}

int& Conteiners::operator[](int i)
{
	return _data[i];
}

Conteiners& Conteiners::operator=(const Conteiners& c)
{
	if (&c == this)
		return *this;

	reallocate(c.getLength());

	for (int i = 0; i < _length; ++i)
		_data[i] = c._data[i];

	return *this;
}

Conteiners::~Conteiners()
{
	delete[] _data;
}

void Conteiners::erace()
{
	delete[] _data;
	_data = nullptr;
	_length = 0;
}
