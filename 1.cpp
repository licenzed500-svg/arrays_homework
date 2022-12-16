//Задача 1(f) вариант 6

#include <iostream>
#include <time.h>

void array_out(int* array, const int arr_size)
{
	for (int i = 0; i < arr_size; i++)
	{
		std::cout << array[i] << "\n";
	}
}

void fill_array(int* array, const int arr_size)
{
	int min = 0;
	int max = 20;
	for (int i = 0; i < arr_size; i++)
	{
		array[i] = min + rand() % (max - min);
	}
}

int main()
{
	srand(time(NULL));
	const int array_size = 20;
	static int array[array_size];
	fill_array(array, array_size);
	array_out(array, array_size);
}

