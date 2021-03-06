// lab_3.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>

using namespace std;

int main()
{
	int N;
	cout << "Enter massive size: ";
	cin >> N;
	cout << endl;

	// Размер масива должен быть положитлеьным
	if (N <= 0) {
		cerr << "Invalid size" << endl;
		return 1;
	}

	int *mas = new int[N];
	int new_item;
	
	// заполнение массива элементами
	cout << "Enter " << N << " items:" << endl;
	for (int i = 0; i < N; i++)
	{
		cin >> new_item;
		mas[i] = new_item;
	}
	cout << endl;

	//	поиск суммы отрицательных элементов
	int sum_neg = 0;

	for (int i = 0; i < N; i++)
	{
		if (mas[i] < 0)
		{
			sum_neg += mas[i];
		}
	}

	if (sum_neg != 0)
	{
		cout << "Negative items sum = " << sum_neg << endl;
	}
	else {
		cout << "No negative elements in massive" << endl;
	}
	cout << endl;

	// поиск id максимального и минимального элементов
	int max_id, min_id;

	max_id = 0;
	min_id = 0;

	for (int i = 1; i < N; i++)
	{
		if (mas[i] > mas[max_id])
		{
			max_id = i;
		}
		if (mas[i] < mas[min_id])
		{
			min_id = i;
		}
	}

	int mult = 1;
	if (min_id < max_id)
	{
		for (int i = min_id+1; i < max_id; i++)
		{
			mult = mult * mas[i];
		}
	} else {
		for (int i = max_id + 1; i < min_id; i++)
		{
			mult = mult * mas[i];
		}
	}
	
	if (mult == 1)
	{
		cout << "There are no items beetwen max and min elements" << endl;
	}
	else {
		cout << "Multiplication of items beetwen max and min elements is equal to: " << mult << endl;
	}
	cout << endl;
	
	// сортировка по возрастанию
	int temp;
	for (int i = 0; i < N-1; i++)
	{
		for (int j = 0; j < N-i-1; j++)
		{
			if (mas[j] > mas[j + 1])
			{
				temp = mas[j];
				mas[j] = mas[j + 1];
				mas[j + 1] = temp;
			}
		}
	}
	
	// вывод массива
	cout << "New massive sorted by increasing:" << endl;
	for (int i = 0; i < N; i++)
	{
		cout << mas[i] << " ";
	}
	cout << endl;

	delete [] mas;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
