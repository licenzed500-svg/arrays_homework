//Вариант 6 задача 14(b)


#include <iostream>
#include <time.h>

void arrays_out(int *array_one, int *array_two, int *array_new, const short *array_size)
{
    std::cout << "\narray one:\n";
    for(short i = 0; i<*array_size; i++)
    {
        std::cout << array_one[i] << "\n";
    }
    std::cout << "\narray two:\n";
    for(short i = 0; i<*array_size; i++)
    {
        std::cout << array_two[i] << "\n";
    }
    std::cout << "\narray new:\n";
    for(short i = 0; i<*array_size; i++)
    {
        std::cout << array_new[i] << "\n";
    }
}

void make_new_array(int *array_one, int *array_two, int *array_new, const short *array_size)
{
    for(short i = 0; i<*array_size; i++)
    {
        if(array_one[i] > array_two[i])
        {
            array_new[i] = array_one[i] - array_two[i];
        }
        else if (array_one[i] < array_two[i])
        {
            array_new[i] = array_two[i] - array_one[i];
        }
        else
        {
            array_new[i] = 0;
        }
    }
}

void set_random(int *array_one, int *array_two, const short *array_size)
{
    const int min = -1000;
    const int max = 1000;
    for(short i = 0; i<*array_size; i++)
    {
        array_one[i] = min + rand() % (max-min);
        array_two[i] = min + rand() % (max-min);
    }
}

int main()
{
    srand(time(NULL));
    const short array_size = 20;
    int array_one[array_size];
    int array_two[array_size];
    int array_final[array_size];
    set_random(array_one, array_two, &array_size);
    make_new_array(array_one, array_two, array_final, &array_size);
    arrays_out(array_one, array_two, array_final, &array_size);
}
