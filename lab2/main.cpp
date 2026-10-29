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

using namespace std;

static int get_rows_table() {

    int row;
    cout << "\nEnter number of rows" << endl
    << "Rows = " << endl;
    cin >> row;

    return row;
}

static int get_columns_table() {
    int column;

    cout << "Enter number of columns" << endl
    << "Columns = " << endl;
    cin >> column;

    return column;
}

static void first_row(int const row) {

    cout << setw(4) << " " << "|";

    for (int i = 1; i < row + 1; i++) {
            cout << right << setw(4) << i;
    }
    cout << endl;
}

static void horizontal_line(int const row) {

    cout << setw(5) << "----|";

    for (int i = 1; i < row + 1; i++) {
        cout << setw(4) << "----";
    }
    cout << endl;
}

static void vertical_line(int const column, int const row) {
    for (int i = 1; i < column + 1; i++ ) {
        cout << right << setw(3) << i << " |";

        for (int i_1 = 1; i_1 < row + 1; i_1++) {
            cout << right << setw(4) << i * i_1;
        }
        cout << endl;
    }
}

static void multiplication_table() {

    cout << "Exercise 1:" << endl
    << "Max size of table (17x17)";

    int const row = get_rows_table();
    if (row <= 0 || row > 17) {
        cout << "Error: wrong input";
        return;
    }

    int const column = get_columns_table();
    if (column <= 0 || column > 17) {
        cout << "Error: wrong input";
        return;
    }

    first_row(row);
    horizontal_line(row);
    vertical_line(column, row);
}

static int get_number() {
    int number;

    cout << "Enter number" << endl
    << "Number = ";
    cin >> number;

    return number;
}

static int get_digit_count(int number) {
    int digit_count = 0;

    for (; number >= 1; digit_count++) {
        number /= 10;
    }
    return digit_count;
}

static int get_digit_sum(int number, int digit_count) {
    int sum = 0;
    for (int i = 0; i < digit_count; digit_count--)
    {
        int result = number / pow(10, digit_count - 1);
        number = number - result * pow(10, digit_count - 1);

        sum += result;
    }
    return sum;
}

static void calculate_digit_sum() {
    cout << "Exercise 2:" << endl;
//
    unsigned long number = get_number();
    int digit_count = get_digit_count(number);
    cout << get_digit_sum(number, digit_count);
}


//zad3
//do while
//na początku liczymy, a potem sprawdzamy wyrazy ich warunek

//zad 4
//srand tylko jeden raz, na początku programu

//zad 5
// program pyta rozmiar klatki no i potem pyta o row or columns
int main() {
    int exercise_num = 5;

    cout << "Autor: Ihar Yafimau (CZ/N 9:15)" << endl;

    while (exercise_num != 0) {
        cout << "\nMENU" << endl << "Please enter number of exercise - 1, 2, 3, 4, or Exit - 0" << endl
        << "Number of exercise: ";
        cin >> exercise_num;

        switch (exercise_num) {
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