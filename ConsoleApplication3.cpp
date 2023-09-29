#include <iostream>
#include <clocale>
#include <vector>
#include "arrayNoS.h"
//#include <ctime>
#include <windows.h>
using namespace std;

 size_t EnteringAnIndex(arrayNoS* arr)
{
	string indStr;//  <-/ INDEX
	size_t ind;//    <-/
	do
	{
		cout << "\nВведите индекс: ";
		cin >> indStr;
	} while (!(arr->CheckingForANumber(indStr) && (indStr != "0")));
	ind = atoi(indStr.c_str());
	return ind;
}

 char* copyArr_symb(arrayNoS* arr)
 {
	 char* arr2 = new char[arr->getSize()], * arrS = arr->getarrS();
	 *arr2 = *arrS;

	 return arr2;
 }

 int* copyArr_int(arrayNoS* arr)
 {
	 int* arr2 = new int[arr->getSize()], * arrN = arr->getarrN();
	 *arr2 = *arrN;
	 
	 return arr2;
 }

 vector<std::chrono::nanoseconds> timeProgram_num(arrayNoS* arr)
 {
	 vector<std::chrono::nanoseconds> result;
	 auto* arrToSort2 = new arrayNoS;
	 arrToSort2->setSize(arr->getSize());
	 arrToSort2->setArrN(copyArr_int(arr));
	 result.push_back(arr->SortingAnArrayOfNumbers_1());
	 result.push_back(arrToSort2->SortingAnArrayOfNumbers_2());
	 delete arrToSort2;
	 return result;
 }

 vector<std::chrono::nanoseconds> timeProgram_symb(arrayNoS* arr)
 {
	 vector<std::chrono::nanoseconds> result;
	 auto* arrToSort2 = new arrayNoS;
	 arrToSort2->setSize(arr->getSize());
	 arrToSort2->setArrS(copyArr_symb(arr));
	 result.push_back(arr->SortingAnArrayOfSymbols_1());
	 result.push_back(arrToSort2->SortingAnArrayOfSymbols_2());
	 delete arrToSort2;
	 return result;
 }

 void outputOfResults(vector<std::chrono::nanoseconds> result)
 {
	 printf("\nРезультат выполнения 1й сортировки: "); cout << result.at(0).count();
	 printf("\nРезультат выполнения 2й сортировки: "); cout << result.at(1).count();
 }

int main()
{
	setlocale(LC_ALL, "Russian");
	auto* arr = new arrayNoS;
	size_t ind;
	switch (arr->ArrayType())
	{
	case 1:
	{
		arr->CreatingAnIntegerArray();
		if (arr->getSize() == 0)
		{
			exit(0);
			break;
		}
		auto result = timeProgram_num(arr);
		ind = EnteringAnIndex(arr);
		printf("i-я статистика для числа %d: %d", ind, arr->getNumber(ind));
		outputOfResults(result);
		break;
	}
	case 2:
	{
		arr->CreatingALetterArray();
		if (arr->getSize() == 0)
		{
			exit(0);
			break;
		}
		auto result = timeProgram_symb(arr);
		ind = EnteringAnIndex(arr);
		printf("i-я статистика для числа %d: %c", ind, arr->getSymbol(ind));
		outputOfResults(result);
		break;
	}
	}
	delete arr;
	return 0;
}