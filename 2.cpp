// Задача 2(c) вариант 6 

#include <iostream>
#include <time.h>


void some_out(int something)
{
	std::cout << "\n" << something << "\n";
}

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

int less_than_five(int* array, const int arr_size)
{
	int summ = 0;

	for (int i = 0; i < arr_size; i++)
	{
		if (array[i] < 5)
		{
			summ += array[i];
		}
	}

	return summ;
}

int bigger_than_six(int* array, const int arr_size)
{
	int summ = 0;

	for (int i = 0; i < arr_size; i++)
	{
		if (array[i] > 6)
		{
			summ += array[i];
		}
	}
	return summ;
}

int less_than_four(int* array, const int arr_size)
{
	int summ = 0;

	for (int i = 0; i < arr_size; i++)
	{
		if (array[i] < 4)
		{
			summ += array[i];
		}
	}
	return summ;
}

int main()
{
	int _less_than_four;
	int _bigger_than_six;
	int _less_than_five;
	srand(time(NULL));
	const int array_size = 20;
	static int array[array_size];
	fill_array(array, array_size);
	array_out(array, array_size);
	_less_than_four = less_than_four(array, array_size);
	_bigger_than_six = bigger_than_six(array, array_size);
	_less_than_five = less_than_five(array, array_size);
	some_out(_less_than_five);
	some_out(_bigger_than_six);
	some_out(_less_than_four);
}
