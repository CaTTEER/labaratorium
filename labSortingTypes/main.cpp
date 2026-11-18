#include <iostream>

using namespace std;

static void insertion_sort(int table[], int num)
{
    for ( int i = 0; i < num; i++)
    {
        for (int j = i; j < num; j++)
        {
            int key = table[j];

            if (table[j] > table[j + 1])
            {
                table[j] = table[j + 1];
                table[j + 1] = key;
            }
        }
    }
}

static void buble_sort(int table[], int num)
{
    for (int i = 0; i < num - 1; i++)
    {
        int swapped = 0;

        for (int j = 0; j < num - 1 - i; j++)
        {
            if (table[j] > table[j + 1])
            {
                int tmp = table[j];

                table[j] = table[j + 1];
                table[j + 1] = tmp;
                swapped = 1;
            }
        }

        if (!swapped)
        {
            break;
        }
    }
}

static void selection_sort(int table[], int num)
{
    int min;
    int j;
    int two_num;

    for (int i = 0; i < num - 1; i++)
    {
        min = table[i + 1];

        for (int j = 0; j < num - 1; j++)
        {
            if (min < table[j])
            {
                min = table[j + 1];
            }
        }

        table[j] = table[i];
        table[i] = min;
    }
}

int main()
{
    int table[5] = {5, 1, 23, 6, 4};

    // insertion_sort(table, 5);
    // buble_sort(table, 5);
    selection_sort(table, 5);

    cout << "[ ";
    for (int i = 0; i < 5; i++)
    {
       cout << table[i] << " ";
    }
    cout << "]";

    return 0;
}
