#include <iostream>
#include <string>
#include <time.h>
#include <vector>

struct Constant
{
    const short min_height = 160;
    const short max_height = 190;
    const short min_age = 16;
    const short max_age = 20;
};

struct Player
{
    Constant constans;
    std::string lastname;
    short height;
    short age;
};

std::vector<std::string> _biggest_than_average(Player *players, const short array_size, float average, std::vector<std::string> *bigger_than_average)
{
    
    for(short i = 0; i<array_size; i++)
    {
        if(players[i].age > average)
        {
            bigger_than_average->push_back(players[i].lastname);
        }
    }
    return *bigger_than_average;
}

float calculate_average_age(Player *players, const short array_size)
{
    int sum = 0;
    for(short i = 0; i<array_size; i++)
    {
        sum+=players[i].age;
    }
    float average = sum/array_size;
    return average;
}

void data_out_tallest(short *some_variable, std::string message, std::string vector_message, std::vector<std::string> *_vector_players)
{
    std::cout<< "\n" << message << "\t" << *some_variable << "\n";
    for (auto i: *_vector_players)
        std::cout << "\n" << vector_message << "\t" << i << "\n";
}

short check_the_tallest(Player *players, const short array_size)
{
    short the_tallest = players[0].height;
    short index = 0;
    for(short i = 0; i<array_size; i++)
    {
        if(players[i].height>the_tallest)
        {
            the_tallest = players[i].height;
            index = i;
        }
    }
    return index;
}

std::string get_random_name()
{
    const short min = 1;
    const short max = 5;
    std::vector<std::string> players_names = {"Georgy", "Mihail", "Maksim", "Danil", "Alexander"};
    short randome_variable = min + rand() % (max-min);
    return players_names[randome_variable];
    players_names.clear();
}

void fill_random(Player *players, const short array_size)
{
    for(short i = 0; i<array_size; i++)
    {
        players[i].height = players[i].constans.min_height + rand() % (players[i].constans.max_height - players[i].constans.min_height);
        players[i].age = players[i].constans.min_age + rand() % (players[i].constans.max_age - players[i].constans.min_age);
        players[i].lastname = get_random_name();
    }
}

int main()
{
    srand(time(NULL));
    const short array_size = 20;
    Player *players = new Player[array_size];
    std::vector<std::string> bigger_than_average = {};
    float average = 0;
    fill_random(players, array_size);
    short the_tallest_index = check_the_tallest(players, array_size);
    average = calculate_average_age(players, array_size);
    bigger_than_average = _biggest_than_average(players, array_size,average, &bigger_than_average);
    data_out_tallest(&the_tallest_index, "The tallest player is:", "bigger than average age is:", &bigger_than_average);
    delete[] players;
    bigger_than_average.clear();
}
