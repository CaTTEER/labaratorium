/*
Autor: Ihar Yafimau
Grupa: CZ/N 9:15
Temat: Laboratorium 1
Data: 21.10.2026
*/

#include <iostream>
#include <cstdio>
#include <cmath>
#include <iomanip>


using namespace std;

static float get_true_delta(float const a, float const b, float const c)
{
    float const delta = b * b - 4 * a * c;

    return delta;

}

static float find_quadratic_roots()
{
    float a, b, c, root_1, root_2;

    cout << "Exercise 1: " << endl
    << "Enter the numbers one by one\na, b, c =\n";

    cin >> a >> b >> c;

    if (a == 0)
    {
        cout << "Error: Roots cannot be calculated";
        return 0;
    }

    float const delta = get_true_delta(a, b, c);

    if (delta > 0)
    {
        root_1 = (-b - sqrt(delta)) / (2 * a);
        root_2 = (-b + sqrt(delta)) / (2 * a);
    }
    else if (delta == 0)
    {
        root_1 = -b / (2 * a);
        root_2 = root_1;
    }
    else
    {
        cout << "Error: No real roots";
        return 0;
    }

    cout << "Roots: " << endl
    << "Root_1: " << root_1 << endl
    << "Root_2: " << root_2 << endl;

    return 0;
}

static bool is_valid_date(int day, int month, int year)
{
     return year > 0 || month <= 12 || month >= 1 || day <= 31 || day >= 0;
}

static void input_date(int &day, int &month, int &year)
{
   cout << "Enter date like 00/00/0000" << endl
   << "Day:" << endl;
    cin >> day;
    cout << "Month: " << endl;
    cin >> month;
    cout << "Year: " << endl;
    cin >> year;
}

static void check_date()
{
    int days_in_months_normal[12]{31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int days_in_months_leap[12]{31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    int day, month, year;
    cout << "Exercise 2: " << endl;

    input_date(day, month, year);

    if (!is_valid_date(day, month, year))
    {
        cout << "Error: non-existent date";
        return;
    }

    if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0)
    {
        if (day <= days_in_months_leap[month-1])
        {
            cout << day << "/" << month << "/" << year << endl << endl;
        }
        else
        {
            cout << "Error: non-existent date" << endl;
        }
    }
    else
    {
        if (day <= days_in_months_normal[month-1])
        {
            cout << day << "/" << month << "/" << year << endl << endl;
        }
        else
        {
            cout << "Error: non-existent date" << endl;
        }
    }
}

static bool is_valid_triangle(float a, float b, float c)
{
    return a > 0 && b > 0 && c > 0 &&
        b + c > a && a + c > b && a + b > c;
}

static const char *get_triangle_type_by_sides(float a, float b, float c)
{
    if (a == b && b == c && a == c)
    {
        return "Equilateral triangle";
    }

    if (a == b || b == c || a == c)
    {
        return "Isosceles triangle";
    }

    return "Scalene triangle";
}

static const char *get_triangle_angles(float const longest_side, float const shorter_side_1, float const shorter_side_2)
{
    if (shorter_side_1 * shorter_side_1 + shorter_side_2 * shorter_side_2 > longest_side * longest_side)
    {
        return "Acute triangle";
    }

    if (shorter_side_1 * shorter_side_1 + shorter_side_2 * shorter_side_2 < longest_side * longest_side)
    {
        return "Obtuse triangle";
    }

    return "Right triangle";
}

static const char *determine_triangle_angles(float a, float b, float c)
{
    float longest_side, shorter_side_1, shorter_side_2;

    if (a >= b && a >= c)
    {
        longest_side = a;
        shorter_side_1 = b;
        shorter_side_2 = c;
    }
    else if (b >= a && b >= c)
    {
        longest_side = b;
        shorter_side_1 = a;
        shorter_side_2 = c;
    }
    else
    {
        longest_side = c;
        shorter_side_1 = a;
        shorter_side_2 = b;
    }

    return(get_triangle_angles(longest_side, shorter_side_1, shorter_side_2));
}

static void classify_triangle()
{
    float a, b, c;

    cout << "Exercise 3: " << endl
    << "Input the sides of the triangle one by one\na, b, c =" << endl;
    cin >> a >> b >> c;

    if (is_valid_triangle(a, b, c))
    {
        cout << "\nA triangle can be formed" << endl << endl;
    }
    else
    {
        cout << "\nError: non-existent triangle";
        return;
    }

    cout << get_triangle_type_by_sides(a, b, c) << endl;

    cout << determine_triangle_angles(a, b, c) << endl;
}

static void print_the_table_header()
{
    cout << setfill('=') << setw(52) << "" << setfill(' ') << endl;

    cout << "|" << setw(5) << "No. " << "|"
    << setw(8) << "radius " << " |"
    << setw(15) << "circumference " << " |"
    << setw(16) << "area of circle " << " |" << endl;

    cout << setfill('=') << setw(52) << "" << setfill(' ') << endl;
}

static void print_the_table_bottom()
{
    cout << setfill('=') << setw(52) << "" << setfill(' ') << endl;
}

static void get_radii(double &max_radius, double &min_radius)
{
    cout << "\nEnter the minimum and maximum radii of the circle" << endl
    << "min_radius =" << endl;
    cin >> min_radius;
    cout << "max_radius =" << endl;
    cin >> max_radius;
}

static int get_row_count()
{
    int row_count;

    cout << "Enter the number of table rows " << endl
    << "row_count =" << endl;
    cin >> row_count;

    return row_count;
}

static void print_properties_table(double radius_array[], double circumference_array[], double circle_area_array[], int const row_count)
{
    print_the_table_header();

    for (int i{0}; i < row_count; i++)
    {
        cout << "|" << setw(4) << i + 1 << " |"
        << setw(8) << fixed << setprecision(2) << radius_array[i] << " |"
        << setw(15) << fixed << setprecision(2) << circumference_array[i] << " |"
        << setw(16) << fixed << setprecision(2) << circle_area_array[i] << " |" << endl;
    }

    print_the_table_bottom();
}

static int create_table()
{
    cout << "Exercise 4: " << endl << endl;

    double max_radius, min_radius;

    int row_count = get_row_count();

    if (row_count <= 0)
    {
        cout << "Error: wrong input" << endl << endl;
        return 0;
    }

    get_radii(max_radius, min_radius);

    if (max_radius < min_radius || max_radius < 0 || min_radius < 0)
    {
        cout << "Error: wrong input" << endl << endl;
        return 0;
    }

    double radius = min_radius;

    double radius_array[row_count];
    double circumference_array[row_count];
    double circle_area_array[row_count];

    double const radius_step = (max_radius - min_radius) / (row_count - 1);

    for (int i{0}; i < row_count; i++)
    {
        radius_array[i] = radius;
        circumference_array[i] = 2.0 * M_PI * radius;
        circle_area_array[i] = M_PI * radius * radius;

        radius += radius_step;
    }

    print_properties_table(radius_array, circumference_array, circle_area_array, row_count);

    return 0;
}

int main()
{
    cout << "Autor: Ihar Yafimau (CZ/N 9:15)" << endl << endl;

    find_quadratic_roots();
    //check_date();
    //classify_triangle();
    //create_table();

    return 0;
}