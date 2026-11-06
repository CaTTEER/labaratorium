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
#include <windows.h>

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

static void create_multiplication_table()
{
    cout << "Exercise 1:" << endl << endl;

    constexpr int max_table_size = 17;
    int const row = get_rows_table();

    if (row <= 0 || row > max_table_size)
    {
        cout << "Error: wrong input";
        return;
    }

    int const column = get_columns_table();
    if (column <= 0 || column > max_table_size)
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


static double get_eps()
{
    double eps;
    cout << "Enter the precision eps (eps < 0.1):" << endl;
    cin >> eps;

    cout << endl;

    return eps;
}

static double leibniz_series(double const eps)
{
    double number;
    double sum = 0;
    int k = 1;
    int sign = 1;

    do
    {
        number = sign * 1.0 / (2.0 * k - 1.0);
        sum += number;

        k++;
        sign *= -1;
    }
    while (fabs(number) >= eps);

    return 4.0 * sum;
}

static double taylor_series(double const eps)
{
    double number;
    double sum = 0;
    int k = 0;
    double factorial = 1;

    do
    {
        number = 1.0 / factorial;
        sum += number;

        k++;
        factorial *= k;
    }
    while (fabs(number) >= eps);

    return sum;
}

static void compute_series_sums()
{
    cout << "\nExercise 3:" << endl;

    double const eps = get_eps();

    if (eps >= 0.1 || eps <= 0)
    {
        cout << "Error: wrong input";
        return;
    }

    cout << "Sum with precision eps - S1:" << endl << leibniz_series(eps) << endl;
    cout << "Sum with precision eps - S2:" << endl << taylor_series(eps) << endl;
}

static void get_limit(int &min_range, int &max_range)
{
    cout << "Enter the min and max of the range of possible integers:" << endl
    << "min:" << endl;
    cin >> min_range;

    cout << "max:" << endl;
    cin >> max_range;
}

static int get_num_count()
{
    int num;

    cout << "Enter how many numbers to generate:" << endl;
    cin >> num;

    return num;
}

static void process_random_number()
{
    srand (time(NULL));

    int min_range, max_range;
    float negative_sum = 0;
    float positive_sum = 0;
    int negative_count = 0;
    int positive_count = 0;

    cout << "\nExercise 4:" << endl;

    get_limit(min_range, max_range);
    if (max_range < min_range)
    {
        cout << "Error: wrong input";
        return;
    }

    int num_count = get_num_count();
    if (num_count <= 0)
    {
        cout << "Error: wrong input";
        return;
    }

    for (int i = 0 ; i < num_count; i++)
    {
        int rand_num = min_range + rand()%(max_range - min_range + 1);
        cout << "rand_num " << "#" << i + 1 << ": " << rand_num << endl;

        if (rand_num > 0)
        {
            positive_sum += rand_num;
            positive_count++;
        }
        else if (rand_num < 0)
        {
            negative_sum += rand_num;
            negative_count++;
        }
    }

    cout << endl << "Count of positive: " << positive_count << endl;
    if (positive_count != 0)
    {
        cout << "Average of positive: " << positive_sum / positive_count << endl;
    }
    else
    {
        cout << "Average of positive: cant calculate" << endl;
    }

    cout << endl << "Count of negative: " << negative_count << endl;
    if (negative_count != 0)
    {
        cout << "Average of negative: " << negative_sum / negative_count << endl;
    }
    else
    {
        cout << "Average of negative: cant calculate" << endl;
    }
}

static void get_square_size(int &square_width, int &square_height)
{
    cout << "Input square size" << endl
    << "Square width: " << endl;
    cin >> square_width;

    cout << "Square height:" << endl;
    cin >> square_height;
}

static void get_board_size(int &board_width, int &board_height)
{
    cout << "Enter the board size" << endl
     << "Board width in squares:" << endl;
    cin >> board_width;

    cout << "Board height in squares" << endl;
    cin >> board_height;
}

void enableColors()
{
    HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    DWORD mode = 0;
    if (!GetConsoleMode(hOut, &mode) ||
        !SetConsoleMode(hOut, mode | ENABLE_VIRTUAL_TERMINAL_PROCESSING)) {
        cout << "Colors are not supported in this console" << endl;
        }
}

static void print_checker_board() {
    enableColors();

    const string RED = "\033[31m";
    const string GREEN = "\033[32m";
    const string CLEAR = "\033[0m";

    cout << "\nExercise 5:" << endl;

    int square_width, square_height, board_width, board_height;

    get_square_size(square_width, square_height);
    if (square_width <= 1 || square_height <= 1)
    {
        cout << "Error: Can't create a square";
        return;
    }

    get_board_size(board_width, board_height);
    if (board_width <= 1 || board_height <= 1)
    {
        cout << "Error: Can't create a board";
        return;
    }

    // string color = GREEN;

    int row_size = square_width * board_width;
    int column_size = square_height * board_height;
    int board = column_size * row_size;

    string structure_board = "";
    for (int i = 0; i < board; i++)
    {
        structure_board = structure_board + "#";
    }
    for (int i = 0; i < ; i++)
    {
        structure_board[i]
    }



    string row = "";
//мб проверить +/n
    // for (int i = 0; i < column_size; i++)
    // {
    //     for (int j = 0; j < row_size; j++)
    //     {
    //         row = row + "#";
    //     }

        cout << board;
    }








    //
    //     for (int i = 0; i < board_height; i++)
    //     {
    //         for (int j = 0; j < square_height; j++)
    //         {
    //             for (int k = 0; k < board_width; k++)
    //             {
    //                 for (int l = 0; l < square_width; l++)
    //                 {
    //                     if (color == GREEN)
    //                     {
    //                         cout << GREEN << "#";
    //                     }
    //                     else
    //                     {
    //                         cout << RED << "#";
    //                     }
    //                 }
    //
    //                 if (color == GREEN)
    //                 {
    //                     color = RED;
    //                 }
    //                 else
    //                 {
    //                     color = GREEN;
    //                 }
    //             }
    //             cout << endl;
    //         }
    //         if (color == GREEN)
    //         {
    //             color = RED;
    //         }
    //         else
    //         {
    //             color = GREEN;
    //         }
    //     }
    //     cout << CLEAR;
    //
}
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
                create_multiplication_table();
                break;

            case 2:
                calculate_digit_sum();
                break;

            case 3:
                compute_series_sums();
                break;

            case 4:
                process_random_number();
                break;

            case 5:
                print_checker_board();
                break;
        }
    }
    return 0;
}