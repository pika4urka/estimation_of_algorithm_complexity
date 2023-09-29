#pragma once
#include <iostream>
#include <chrono>

class arrayNoS
{
	size_t sizeArr;
	int* arrN;
	char* arrS;
	bool CheckingTheSize(std::string str);
	bool CheckingWithTheHelpOfAscii(char symb);
	
public:
	
	bool CheckingTheSymbol(std::string str);
	bool CheckingForANumber(std::string str);

	std::chrono::nanoseconds SortingAnArrayOfNumbers_1();
	std::chrono::nanoseconds SortingAnArrayOfSymbols_1();
	std::chrono::nanoseconds SortingAnArrayOfNumbers_2();
	std::chrono::nanoseconds SortingAnArrayOfSymbols_2();

	void CreatingAnIntegerArray();
	void CreatingALetterArray();
	void ErrorMessage();
	void setSize(size_t n);
	void setArrN(int* arr);
	void setArrS(char* arr);

	size_t ArrayType();
	size_t getSize();

	int getNumber(size_t ind);
	char getSymbol(size_t ind);
	int* getarrN();
	char* getarrS();

	arrayNoS()
	{
		arrN = NULL;
		arrS = NULL;
		sizeArr = 0;
	}

	~arrayNoS()
	{
		delete[] arrN;
		delete[] arrS;
	}
};