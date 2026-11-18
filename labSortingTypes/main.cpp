#include <iostream>

using namespace std;

static void insertion_sort(int table[], int num)
{
    int j;
    int key;

    for (int i = 1; i < num; i++)
    {
        key = table[i];

        for (j = i - 1; j >= 0; j--)
        {
            if (table[j] > key)
            {
                table[j + 1] = table[j];
            }
            else if (table[j] <= key)
            {
                break;
            }
        }

        table[j + 1] = key;
    }
}

static void bubble_sort(int table[], int num)
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
    int min_index;

    for (int i = 0; i < num - 1; i++)
    {
        min_index = i;

        for (int j = 1 + i; j < num; j++)
        {
            if (table[min_index] > table [j])
            {
                min_index = j;
            }
        }

        int test = table[min_index];

        table[min_index] = table[i];
        table[i] = test;
    }
}


int main()
{
    int table[5] = {5, 1, 23, 6, 4};

    insertion_sort(table, 5);
    // bubble_sort(table, 5);
    //selection_sort(table, 5);

    cout << "[ ";
    for (int i = 0; i < 5; i++)
    {
       cout << table[i] << " ";
    }
    cout << "]";

    return 0;
}
