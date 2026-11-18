/*
Autor: Ihar Yafimau
Grupa: CZ/N 9:15
Temat: Laboratorium 3
Data: 16.11.2026
*/

#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <iostream>
#include <iomanip>
#include <time.h>
#include <conio.h>

using namespace std;

#define ROZMIAR 5

static void fill_array(float table[])
{
    cout << "Fill the array" << endl << endl;

    for (int i = 0; i < ROZMIAR; i++)
    {
        cout << "table[" << i << "] =";
        cin >> table[i];
    }

    cout << endl;
}

static void print_array(float table[])
{
    cout << fixed << setprecision(1);
    cout << "Tab = [  ";

    for (int i = 0; i < ROZMIAR; i++)
    {
        cout << table[i] << "  ";
    }
    cout << "]" << endl;
}

static void calculate_array(float table[])
{
    int pos_count = 0;
    int neg_count = 0;
    float pos_sum = 0;
    float neg_sum = 0;

    for (int i = 0; i < ROZMIAR; i++)
    {
        if (table[i] > 0)
        {
            pos_count += 1;
            pos_sum += table[i];
        }
        else if (table[i] < 0)
        {
            neg_count += 1;
            neg_sum += table[i];
        }
    }

    cout << "\nCalculated results:\n" << endl
        << "pos_count = " << pos_count << endl
        << "neg_count = " << neg_count << endl
        << "\npos_sum = " << pos_sum << endl
        << "neg_sum = " << neg_sum << endl;

    if (pos_count != 0)
    {
        cout << "\npos_average = " << pos_sum / pos_count << endl;
    }
    else
    {
        cout << "\npos_average = cant calculated" << endl;
    }

    if (neg_count != 0)
    {
        cout << "neg_average = " << neg_sum / neg_count << endl;
    }
    else
    {
        cout << "neg_average = cant calculated" << endl;
    }
}

static void check_array_order(float table[])
{
    int increasing = 0;
    int non_decreasing = 0;
    int non_increasing = 0;
    int decreasing = 0;
    int all_equal = 0;

    for (int i = 0; i < ROZMIAR - 1; i++)
    {
        if (table[i] < table[i + 1])
        {
            increasing += 1;
        }

        if (table[i] <= table[i + 1])
        {
            non_decreasing += 1;
        }

        if (table[i] > table[i + 1])
        {
            decreasing += 1;
        }

        if (table[i] >=  table[i + 1])
        {
            non_increasing += 1;
        }

        if (table[i] == table[i + 1])
        {
            all_equal += 1;
        }
    }

    if (all_equal == ROZMIAR - 1)
    {
        cout << "\nAll equal" << endl;
    }
    else if (increasing == ROZMIAR - 1)
    {
        cout << "\nIncreasing order" << endl;
    }
    else if (decreasing == ROZMIAR - 1)
    {
        cout << "\nDecreasing order" << endl;
    }
    else if (non_increasing == ROZMIAR - 1)
    {
        cout << "\nNon-increasing order" << endl;
    }
    else if (non_decreasing == ROZMIAR - 1)
    {
        cout << "\nNon-decreasing order" << endl;
    }
    else
    {
        cout << "\nNot ordered" << endl;
    }
}

//exercise 2
static void random_fill_array(float table[])
{
    float min, max;

    cout << "Input range of random numbers" << endl
    << "min = " << endl;
    cin >> min;

    cout << "max = " << endl;
    cin >> max;

    for (int i = 0; i < ROZMIAR; i++)
    {
        table[i] = min + (max - min) * (rand() / (double)RAND_MAX);
    }
}

//exercise 3
static void sort_array(float table[])
{
    for (int i = 0; i < ROZMIAR - 1; i++)
    {
        int min_index = i;

        for (int j = 1 + i; j < ROZMIAR; j++)
        {
            if (table[min_index] > table[j])
            {
                min_index = j;
            }
        }

        float tmp = table[min_index];
        table[min_index] = table[i];
        table[i] = tmp;
    }
}

static void get_letter_count()
{
    char table_letter[26][26] = {"a", "b", "c", "d", "e", "f", "g", "h", "i", "j", ""};

    while (true)
    {
        int key = getch();

        if (key == 27)
        {
            cout << "ok";
            break;
        }
    }
}
//Exercise 1
// static void process_array(float table[])
// {
//     int ex_num;
//
//
// }
// if (ex_num != 1)
// {
//     cout << "\nYou should at first fill the array!" << endl;
//     continue;
// }
// static bool ex_is_true(int ex_num)
// {
//     if (ex_num != 0)
//     {
//         return false;
//     }
// }

int main()
{
    cout << "Autor: Ihar Yafimau (CZ/N 9:15)" << endl;

    srand (time(NULL));

    float table[ROZMIAR];
    int ex_num;

    while (true)
    {
        cout << "\nMENU" << endl
        << "Input ex_num: 1, 4, or 0 for exit" << endl;

        cin >> ex_num;

        switch (ex_num)
        {
            case 1:
                while (ex_num != 0)
                {
                    
                    cout << "\nChoose option:" << endl
                    << "1 - Fill the array" << endl
                    << "2 - Fill the array randomly(ex2)" << endl
                    << "3 - Sort the array(ex3)" << endl
                    << "4 - Print the array" << endl
                    << "5 - Calculate the array" << endl
                    << "6 - Check array order" << endl
                    << "0 - Exit" << endl << endl;

                    cin >> ex_num;

                    switch (ex_num)
                    {
                        cin >> ex_num;

                        case 1:
                            fill_array(table);
                            continue;

                        case 2:
                            random_fill_array(table);
                            continue;

                        case 3:
                            sort_array(table);
                            continue;

                        case 4:
                            print_array(table);
                            continue;

                        case 5:
                            calculate_array(table);
                            continue;

                        case 6:
                            check_array_order(table);
                            continue;

                        case 0:
                            break;
                    }
                }

            case 4:
                get_letter_count();
                continue;

            case 0:
                return 0;
        }

    }
}