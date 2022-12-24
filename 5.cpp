// Вариант 6 задача 11

#include <iostream>
#include <time.h>


void data_out_less_than_average(int *array, const short *array_size, float *average_positive, float *average_negative, bool mode = true)
{
    if(mode == true)
    {
        for(short i = 0; i<*array_size; i++)
        {
            if(array[i]>0)
            {
                if(array[i] < *average_positive)
                {
                    std::cout << "less than average of positive: " << array[i] << " " << "index: " << i << "\n";
                }
            }
        }
    }
    else
    {
        for(short i = 0; i<*array_size; i++)
        {
            if(array[i]<0)
            {
                if(array[i] < *average_negative)
                {
                    std::cout << "less than average of negative: " << array[i] << " " << "index: " << i << "\n";
                }
            }
        }
    }
}


void data_out(short *positive_elements, short *negative_elements, float *average_positive, float *average_negative)
{
    std::cout << "count of positive elements:\t" << *positive_elements << "\n";
    std::cout << "count of negative elements:\t" << *negative_elements << "\n";
    std::cout << "average of negative elements:\t" << *average_negative << "\n";
    std::cout << "average of positive elements:\t" << *average_positive << "\n";
}

float average(int *array, const short *array_size, bool mode = true )
{
    float _average = 0;
    float sum = 0;
    
    if(mode == true)
    {
        for(short i = 0; i<*array_size; i++)
        {
            if(array[i]>0)
            {
                sum+=array[i];
            }
        }
    }
    else
    {
        for(short i = 0; i<*array_size; i++)
        {
            if(array[i]<0)
            {
                sum+=array[i];
            }
        }
    }
    _average = sum / *array_size;
    return _average;
}

short calculate(int *array, const short *array_size, bool mode = true)
{
    short counter = 0;
    if(mode == true)
    {
        for(short i = 0; i<*array_size; i++)
        {
            if (array[i]>0)
            {
                counter ++;
            }
        }
    }
    else
    {
        for(short i = 0; i<*array_size; i++)
        {
            if (array[i]<0)
            {
                counter ++;
            }
        }
    }
    return counter;
}

void fill_random(int *array, const short *array_size)
{
    const short min = -500;
    const short max = 500;
    for(short i = 0; i<*array_size; i++)
    {
        array[i] = min + rand() % (max-min);
    }
}


int main()
{
    srand(time(NULL));
    const short array_size = 20;
    static int array[array_size];
    fill_random(array, &array_size);
    short count_elements_positive = calculate(array, &array_size);
    short count_elements_negative = calculate(array, &array_size, false);
    float _average_positive = average(array, &array_size);
    float _average_negative = average(array, &array_size, false);
    data_out(&count_elements_positive, &count_elements_negative, &_average_positive, &_average_negative);
    data_out_less_than_average(array, &array_size, &_average_positive, &_average_negative);
    data_out_less_than_average(array, &array_size, &_average_positive, &_average_negative, false);
}
