// Задача 8 вариант 6


#include <iostream>
#include <time.h>

void data_out(short *positive_elements, short *negative_elements)
{
    std::cout << "count of positive elements:\t" << *positive_elements << "\n";
    std::cout << "count of negative elements:\t" << *negative_elements << "\n";
}

short calculate(int *array, const short array_size, bool mode = true)
{
    short counter = 0;
    if(mode == true)
    {
        for(short i = 0; i<array_size; i++)
        {
            if (array[i]>0)
            {
                counter ++;
            }
        }
    }
    else
    {
        for(short i = 0; i<array_size; i++)
        {
            if (array[i]<0)
            {
                counter ++;
            }
        }
    }
    return counter;
}

void fill_random(int *array, const short array_size)
{
    const short min = -20;
    const short max = 20;
    for(short i = 0; i<array_size; i++)
    {
        array[i] = min + rand() % (max-min);
    }
}


int main()
{
    srand(time(NULL));
    const short array_size = 20;
    static int array[array_size];
    fill_random(array, array_size);
    short count_elements_positive = calculate(array, array_size);
    short count_elements_negative = calculate(array, array_size, false);
    data_out(&count_elements_positive, &count_elements_negative);
}
