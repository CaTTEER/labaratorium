/*
Autor: Ihar Yafimau
Grupa: CZ/N 9:15
Temat: Laboratorium 2
Data: 28.10.2026
*/

#include <iostream>
#include <stdio.h>
#include <iomanip>
#include <cmath>
#include <algorithm>
#include <string>
#include <sstream>
#include <format>

using namespace std;

static int get_rows_table()
{
    int row;
    cout << "Enter number of rows" << endl
    << "Rows = " << endl;
    cin >> row;

    return row;
}

static int get_columns_table()
{
    int column;

    cout << "Enter number of columns" << endl
    << "Columns = " << endl;
    cin >> column;

    return column;
}

static void first_row(int const row)
{

    cout << setw(4) << " " << "|";

    for (int i = 1; i < row + 1; i++)
    {
        cout << right << setw(4) << i;
    }
    cout << endl;
}

static void horizontal_line(int const row)
{

    cout << setw(5) << "----|";

    for (int i = 1; i < row + 1; i++)
    {
        cout << setw(4) << "----";
    }
    cout << endl;
}

static void vertical_line(int const column, int const row)
 {
    for (int i = 1; i < column + 1; i++ )
    {
        cout << right << setw(3) << i << " |";

        for (int j = 1; j < row + 1; j++)
        {
            cout << right << setw(4) << i * j;
        }
        cout << endl;
    }
}

static void multiplication_table()
{
    cout << "Exercise 1:" << endl << endl;

    int const row = get_rows_table();
    if (row <= 0 || row > 17)
    {
        cout << "Error: wrong input";
        return;
    }

    int const column = get_columns_table();
    if (column <= 0 || column > 17)
    {
        cout << "Error: wrong input";
        return;
    }

    first_row(row);
    horizontal_line(row);
    vertical_line(column, row);
}

static long double get_number()
{
    long double number;

    cout << "Enter positive integer" << endl
    << "Number = " << endl;
    cin >> number;

    return number;
}

static int get_digit_sum(unsigned long long number)
{
    int sum_result = 0;

    while (number > 0)
    {
        int const result = number % 10;
        sum_result += result;

        number = (number - result) / 10;
    }

    cout << endl;
    return sum_result;
}

static unsigned long long get_binary_number(unsigned long long integer_number)
{
    string str_binary_number = "";

    while (integer_number > 0)
    {
        if (integer_number % 2 == 0)
        {
            str_binary_number += "0";
        }
        else
        {
            str_binary_number += "1";
        }
        integer_number /= 2;
    }
    reverse(str_binary_number.begin(), str_binary_number.end());

    return stoull(str_binary_number);
}

static unsigned long long digit_sum_in_base(unsigned long long integer_number, int base)
{
    unsigned long long number = 0;

    while (integer_number > 0)
    {
        number += integer_number % base;
        integer_number /= base;
    }

    return number;
}

static void calculate_digit_sum()
{
    cout << "\nExercise 2:" << endl;

    long double number = get_number();

    if (number <= 0 || number != floorl(number))
{
        cout << "Error: wrong input";
        return;
}
    auto const integer_number = static_cast<unsigned long long>(number);
    cout << endl << "Sum of digits of " << integer_number << ":" << get_digit_sum(integer_number) << endl;

    unsigned long long binary_number = get_binary_number(integer_number);
    cout << endl << "Sum of binary digits of " <<  binary_number << ":" << get_digit_sum(binary_number) << endl;

    unsigned long long sum_octal_digit = digit_sum_in_base(integer_number,8);
    cout << endl << "Sum of octagon digits of " << oct << integer_number << dec << ":" << endl << sum_octal_digit << endl;

    unsigned long long sum_hex_digit = digit_sum_in_base(integer_number, 16);
    cout << endl << "Sum of hexagon digits of " << hex << uppercase << integer_number << dec << ":" << endl << sum_hex_digit << endl;
}

//zad3
//do while
//na początku liczymy, a potem sprawdzamy wyrazy ich warunek

//zad 4
//srand tylko jeden raz, na początku programu

//zad 5
// program pyta rozmiar klatki no i potem pyta o row or columns

int main()
{
    int exercise_num = 6;

    cout << "Autor: Ihar Yafimau (CZ/N 9:15)" << endl;

    while (exercise_num != 0)
    {
        cout << "\n\nMENU" << endl << "Please enter number of exercise - 1, 2, 3, 4, 5 or Exit - 0" << endl
        << "Number of exercise: " << endl;
        cin >> exercise_num;

        switch (exercise_num)
        {
            case 1:
                multiplication_table();
                break;

            case 2:
                calculate_digit_sum();
                break;
        }
    }
    return 0;
}