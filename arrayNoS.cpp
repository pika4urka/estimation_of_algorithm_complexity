#include "arrayNoS.h"


void arrayNoS::ErrorMessage()
{
	std::cout << "\n¬ведены некорректные данные, попробуйте ещЄ раз.\n\n";
}

std::chrono::nanoseconds arrayNoS::SortingAnArrayOfNumbers_1()
{
	auto begin_time = std::chrono::steady_clock::now();
	bool l = true;
	while (l)
	{
		l = false;
		for (int i = 1; i < sizeArr; i++)
		{
			if (*(arrN + i - 1) > *(arrN + i))
			{
				std::swap(*(arrN + i - 1), *(arrN + i));
				l = true;
			}
		}
	}
	auto end_time = std::chrono::steady_clock::now();
	return std::chrono::duration_cast<std::chrono::nanoseconds>(end_time - begin_time);
}

std::chrono::nanoseconds arrayNoS::SortingAnArrayOfNumbers_2()
{
	auto begin_time = std::chrono::steady_clock::now();
	int buf = sizeArr;
	buf = (buf - 1) / 1.4 + 1;

	bool l = true;
	while (l)
	{
		l = false;
		if (buf != 0)
			buf = (buf - 1) / 1.4 + 1;
		for (int i = 1; i < sizeArr - buf; i++)
		{
			if (*(arrN + i - 1) > *(arrN + i))
			{
				std::swap(*(arrN + i - 1), *(arrN + i));
				l = true;
			}
			if (*(arrN + i + buf - 1) > *(arrN + i + buf))
			{
				std::swap(*(arrN + i + buf - 1), *(arrN + i + buf));
				l = true;
			}
		}
	}
	auto end_time = std::chrono::steady_clock::now();
	return std::chrono::duration_cast<std::chrono::nanoseconds>(end_time - begin_time);
}

std::chrono::nanoseconds arrayNoS::SortingAnArrayOfSymbols_1()
{
	auto begin_time = std::chrono::steady_clock::now();
	bool l = true;
	while (l)
	{
		l = false;
		for (int i = 1; i < sizeArr; i++)
		{
			if (*(arrS + i - 1) > *(arrS + i))
			{
				std::swap(*(arrS + i - 1), *(arrS + i));
				l = true;
			}
		}
	}
	auto end_time = std::chrono::steady_clock::now();
	return std::chrono::duration_cast<std::chrono::nanoseconds>(end_time - begin_time);
}

std::chrono::nanoseconds arrayNoS::SortingAnArrayOfSymbols_2()
{
	auto begin_time = std::chrono::steady_clock::now();
	int buf = (sizeArr - 1) / (1.4 + 1);
	bool l = true;
	while (l)
	{
		l = false;
		if (buf != 0)
			buf = (buf - 1) / (1.4 + 1);
		for (int i = 1; i < sizeArr - buf; i++)
		{
			if (*(arrS + i - 1) > *(arrS + i))
			{
				std::swap(*(arrS + i - 1), *(arrS + i));
				l = true;
			}
			if (*(arrS + i + buf - 1) > *(arrS + i + buf))
			{
				std::swap(*(arrS + i + buf - 1), *(arrS + i + buf));
				l = true;
			}
		}
	}
	auto end_time = std::chrono::steady_clock::now();
	return std::chrono::duration_cast<std::chrono::nanoseconds>(end_time - begin_time);
}

bool arrayNoS::CheckingTheSize(std::string str)
{
	if (CheckingForANumber(str) && (atoi(str.c_str()) >= 0))
		return true;
	else
		return false;
}

bool arrayNoS::CheckingForANumber(std::string str)
{
	if (str == "0")
		return true;
	else
		if (0 == atoi(str.c_str()))
		{
			ErrorMessage();
			return false;
		}
		else
			return true;
}

bool arrayNoS::CheckingWithTheHelpOfAscii(char symb)
{
	int c = static_cast<int>(symb); //symbol code
	if (((c > 64) && (c < 91)) ||
		((c > 96) && (c < 123)) ||
		((c > 127) && (c < 176)) ||
		((c > 223) && (c < 242)))
		return true;
	else
	{
		ErrorMessage();
		return false;
	}
}

bool arrayNoS::CheckingTheSymbol(std::string str)
{
	char symb;
	if (str.size() == 1)
	{
		symb = str[0];
		if (CheckingWithTheHelpOfAscii(symb))
			return true;
		else
			return false;
	}
	else
	{
		ErrorMessage();
		return false;
	}
}

void arrayNoS::CreatingAnIntegerArray()
{
	int arrSize, number;
	std::string bufstr;
	do
	{
		std::cout << "\n ¬ведите размер массива: ";
		std::cin >> bufstr;
	} while (!CheckingTheSize(bufstr));
	arrSize = atoi(bufstr.c_str());
	int* arr = new int[arrSize];
	std::cout << "¬вод массива:\n";
	for (int i = 0; i < arrSize; i++)
	{
		do
		{
			printf("%d)", i+1);
			std::cin >> bufstr;
		} while (!CheckingForANumber(bufstr));
		*(arr + i) = atoi(bufstr.c_str());
	}
	sizeArr = arrSize;
	arrN = arr;
}

void arrayNoS::CreatingALetterArray()
{
	int arrSize;
	std::string bufstr;
	do
	{
		std::cout << "\n ¬ведите размер массива: ";
		std::cin >> bufstr;
	} while (!CheckingTheSize(bufstr));
	arrSize = atoi(bufstr.c_str());
	char* arr = new char[arrSize];
	std::cout << "¬вод массива:\n";
	for (int i = 0; i < arrSize; i++)
	{
		do
		{
			printf("%d)", i+1);
			std::cin >> bufstr;
		} while (!CheckingTheSymbol(bufstr));
		*(arr + i) = bufstr[0];
	}
	sizeArr = arrSize;
	arrS = arr;
}


size_t arrayNoS::ArrayType()
{
	std::string buf;
replay:
	std::cout << "¬ведите \"1\", если вы хотите создать целочисленный массив";
	std::cout << "\n\"2\", если хотите создать массив, состо€щий из букв: ";
	std::cin >> buf;
	if (CheckingForANumber(buf))
		if ((atoi(buf.c_str()) != 1) and (atoi(buf.c_str()) != 2))
		{
			ErrorMessage();
			goto replay;
		}
		else
			return atoi(buf.c_str());
	else
		goto replay;
}

int arrayNoS::getNumber(size_t ind)
{
	return *(arrN + ind - 1);
}

char arrayNoS::getSymbol(size_t ind)
{
	return *(arrS + ind - 1);
}

size_t arrayNoS::getSize()
{
	return sizeArr;
}

void arrayNoS::setSize(size_t n)
{
	sizeArr = n;
}
void arrayNoS::setArrN(int* arr)
{
	arrN = arr;
}
void arrayNoS::setArrS(char* arr)
{
	arrS = arr;
}

int* arrayNoS::getarrN()
{
	return arrN;
}
char* arrayNoS::getarrS()
{
	return arrS;
}



