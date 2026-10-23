/*
 *Autor: Ihar Yafimau
 *Grupa: CZ/N 9:15
 *Temat: Laboratorium 0
 *Data: 12.10.2026
 */

#include <iostream>
#include <stdio.h>
#include <math.h>

using namespace std;

static void display_contact_info_1a()
{
    cout << "Exercise 1a:" << endl
    << "Name: Ihar Yafimau" << endl
    << "Address: Wroclaw 21" << endl
    << "Phone: +48576462483" << endl
    << "Email: ihar.yafimau@gmail.com" << endl;
}

static void display_contact_info_1b()
{
    printf("\nExercise 1b:\n"
        "Name: Albert Lindemann\n"
        "Address: Wroclaw 20\n"
        "Phone: +48643654128\n"
        "Email: albert.lindemann@gmail.com\n");
}

static void calculate_math_operations_2a()
{
    int a, b, c;
    constexpr float NUMBER_OF_VARIABLES {3.0};

    cout << "\nExercise 2a:" << endl
        << "Enter the numbers one by one" << endl
        << "a, b, c ="<< endl;
    cin >> a >> b >> c;

    const float sum_result = a + b + c;
    cout << "Sum of values: " << sum_result << endl;

    const float multiply_result = a * b * c;
    cout << "Product of values: " << multiply_result << endl;

    const float average_result = (a + b + c) / NUMBER_OF_VARIABLES;
    cout << "Arithmetic mean of values: " << average_result << endl;
}

static void calculate_math_operations_2b()
{
    int a, b, c;
    float math_result;
    const float number_of_variables {3.0};

    printf("\nExercise 2b:\n"
        "Enter the numbers one by one\na, b, c =\n");
    scanf("%d%d%d", &a, &b, &c);

    math_result = a + b + c;
    printf("Sum of values: %.1f ", math_result);

    math_result = a * b * c;
    printf("\nProduct of values: %.1f", math_result);

    math_result = (a + b + c) / number_of_variables;
    printf("\nArithmetic mean of values: %.1f\n", math_result);
}

static void calculate_circle_properties_3a()
{
    float radius;

    printf("\nExercise 3a:\n"
        "Enter radius in metres:\n");
    scanf("%f", &radius);

    const float circle_area = M_PI * radius * radius;
    const float circumference = 2.0 * M_PI * radius;

    printf("Circle area: %.2f (m^2)\n"
        "Circumference: %.2f (m)\n",
        circle_area, circumference);
}

static void calculate_circle_properties_3b()
{
    float radius;

    cout << "\nExercise 3b:" << endl
    << "Enter radius in metres: " << endl;
    cin >> radius;

    const float circle_area = M_PI * radius * radius;
    const float circumference = 2.0 * M_PI * radius;

    cout << "Circle area = " << circle_area << " (m^2)" << endl
        << "Circumference = " << circumference << " (m)" << endl;
}

int main()
{
    cout << "Autor: Ihar Yafimau (CZ/N 9:15)" << endl << endl;

    display_contact_info_1a();
    display_contact_info_1b();

    calculate_math_operations_2a();
    calculate_math_operations_2b();

    calculate_circle_properties_3a();
    calculate_circle_properties_3b();

    return 0;
}
