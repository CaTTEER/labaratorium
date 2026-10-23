#include <iostream>
#include <stdio.h>
#include <math.h>
#include <iomanip>

using namespace std;

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

static bool get_radii(double &max_radius, double &min_radius)
{
    cout << "\nEnter the minimum and maximum radii of the circle" << endl
    << "min_radius =" << endl;
    cin >> min_radius;
    cout << "max_radius =" << endl;
    cin >> max_radius;

    if (max_radius < min_radius)
    {
        return false;
    }

    return true;
}

static bool get_row_count(int &row_count)
{
    cout << "Enter the number of table rows " << endl
    << "row_count =" << endl;
    cin >> row_count;

    if (row_count < 1)
    {
        return false;
    }

    return true;
}

static void create_table_cykle(double radius_array[], double circumference_array[], double circle_area_array[], int const row_count)
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

static int create_tabel()
{
    cout << "Exercise 4: " << endl << endl;

    double max_radius, min_radius;
    int row_count;

    if (!get_row_count(row_count))
    {
        return 0;
    }

    if (!get_radii(max_radius, min_radius))
    {
        return 0;
    }

    double radius = min_radius;

    double radius_array[row_count];
    double circumference_array[row_count];
    double circle_area_array[row_count];

    double const radius_step = (max_radius - min_radius) / (row_count- 1);

    for (int i{0};i < row_count; i++)
    {
        radius_array[i] = radius;
        circumference_array[i] = 2.0 * M_PI * radius;
        circle_area_array[i] = M_PI * radius * radius;

        radius += radius_step;
    }

    create_table_cykle(radius_array, circumference_array, circle_area_array, row_count);
}

int main()
{
    create_tabel();
}