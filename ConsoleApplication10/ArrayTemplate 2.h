#pragma once
#include <iostream>
#include <cstdlib>
using namespace std;

template <typename T>
void randArray(T arr[], int size, int a = 1, int b = 10)
{
	for (int i=0; i < size; i++) {
		arr[i] = rand() % (b - a + 1) + a;
	}
}

template <typename T>
void printArray(T arr[], int size, int w_cout = 5)
{
	for (int i=0; i < size; i++) {
		cout.width(w_cout);
		cout << arr[i];
	}
	cout << endl;
}



template <typename T>
int indexMinElement(T arr[], int size)
{
	T min = arr[0];
	int index = 0;
	for (int i = 0; i < size; i++) {
		if (min < arr[i]) {
			min = arr[i];
			index = i;
		}
	}
	return index;
}

template <typename T>
int indexMaxElement(T arr[], int size)
{
	T max = arr[0];
	int index = 0;
	for (int i = 0; i < size; i++) {
		if (max > arr[i]) {
			max = arr[i];
			index = i;
		}
	}
	return index;
}



template <typename T>
T sumArray(T arr[], int size)
{
	T sum = 0;
	for (int i = 0; i < size; i++) {
		sum += arr[i];
	}
	return sum;
}

template <typename T>
int searchNum(T arr[], const int size, T key)
{
	
	for (int i = 0; i < size; i++) {
		if (arr[i] == key) {
			return i;
		}
	}
	return -1;
}

template <typename T>
void mySort(T arr[], const int size)
{
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size - i - 1; j++) {
			if (arr[j + 1] < arr[j]) {
				T temp = arr[j];
				arr[j] = arr[j+1];
				arr[j + 1] = temp;
			}
		}
	}
}

template <typename T>
T sumEl(T arr[], int size, int K, int L) {
	if (K < 0 || L >= size) {
		return -1;
	}
	T sum = 0;
	for (int i = K; i <= L; i++) {
		sum += arr[i];
	}
	return sum;
}

void calc_time(int hours, int minutes) {

	minutes += hours * 60;
	cout << "Minutes: " << minutes << endl;

}
void calc_time(int minutes) {
	int hours = minutes / 60;
	minutes = minutes % 60;
	cout << "Hours: " << hours << " Minutes: " << minutes << endl;
}

float addFractions(float a, float b) {
	return a + b;
}
float addFractions(int a1, int b1, int a2, int b2) {
	return (float)a1 / b1 + (float)a2 / b2;
}

int day_of_week(int julian_day) {
	if (julian_day <= 365 && julian_day > 0) {
		return julian_day % 7;
	}
	else { return -1; }
}
int day_of_week(int month, int day, int year) {
	int sum = 0;
	for (int i = 0; i < month; i++) {
		if (i == 1 || i == 3 || i == 5 || i == 7 || i == 8 || i == 10 || i == 12) {
			sum += 31;
		}
		else if (i == 4 ||i==6||i==9||i==11) {
			sum += 30;
		}
		else {
			if (year % 4 == 0) {
				sum += 29;
			}
			else {
				sum += 28;
			}
		}

	}
	sum += day;
	return sum % 7;
}

template <typename T>
int oddEl(T arr[], int size) {
	int odd = 0;
	for (int i = 0; i < size; i++) {
		if (arr[i] % 2 == 0) {
			odd++;
		}
	}
	return odd;
}


template <typename T>
int my_count_if(T* arr, int size, bool(*func)(T value)) {
	int amount = 0;
	for (int i = 0; i < size; i++) {
		if (func(arr[i]) == true) {
			amount++;
		}

	}
	return amount;
}


template <typename T>
int my_sum_if(T* arr, int size, bool(*func)(T value)) {
	T sum = 0;
	for (int i = 0; i < size; i++) {
		if (func(arr[i])) sum += arr[i];
	}
	return sum;
}

template <typename T>
int my_find_if(T* arr, int size, bool(*func)(T value)) {
	for (int i = 0; i < size; i++) {
		if (func(arr[i])) return i;
	}
	return -1;
}


template <typename T>
void my_replace_if(T*& arr, int& size, bool (*fP)(T), T value) {
	for (int i = 0; i < size; i++) {
		if (fP(arr[i])) arr[i] = value;
	}
}

template <typename T>
void my_remove_if(T*& arr, int& size, bool (*fP)(T)) {
	int amount = my_count_if(arr, size, fP);
	if (amount == 0) return;
	T* tmp = new T[size - amount]{ 0 };
	for (int i = 0, j =0; i < size; i++) {
		if (fP(arr[i]) == false) {
			tmp[j] = arr[i];
			j++;
		}
	}
	if (arr != nullptr) delete[] arr;
	arr = tmp;
	size -= amount;
}

template <typename T>
void my_copy_if(T* arr, int size, T*& arr_copy, int& size_copy, bool (*fP)(T)) {
	size_copy = my_count_if(arr, size, fP);
	arr_copy = new T[size_copy]{ 0 };
	for (int i = 0, j = 0; i < size; i++) {
		if (fP(arr[i])) {
			arr_copy[j] = arr[i];
			j++;
		}
	}
}





template<typename T>
void addItemBack(T*& arr, int& size,T item)
{
	//1. Запитуємо нову ділянку в памяті на 1 ел-т більше
	T* tmp = new T[size + 1];

	//2. Переносимо дані зі старого масиву до нового
	for (int i = 0; i < size; i++) {
		tmp[i] = arr[i];
	}

	//3. Вносимо нове значення в кінець массиву
	tmp[size] = item;

	//4. Видаляємо старий масив
	if (arr != nullptr) delete[] arr;

	//5. Переприв'язуємо покажчик на нову адресу
	arr = tmp;

	//6. Оновлюємо кіль-ть ел-тів
	size++;
}




template <typename T>
void my_sort_if(T* arr, int size, bool (*cmp)(T, T)) {
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size - i - 1; j++) {
			if (cmp(arr[j + 1], arr[j])) {
				T temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
}