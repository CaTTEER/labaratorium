#include <iostream>
#include <string>
#ifdef _WIN32
#include <windows.h>
#endif

// #ifdef _WIN32
//     SetConsoleOutputCP(CP_UTF8);
// SetConsoleCP(CP_UTF8);
// #endif

using namespace std;

class player
{
public:

    string name;
    int hp;
    int power;

    player(string name, int hp, int power) : name(name), hp(hp), power(power) {}

    void show_stats()
    {
        cout << "\nHero name: " << name << endl
        << "HP: " << hp << endl
        << "Power: " << power << endl;
    }

    void lvlup()
    {
        hp += 10;
        power += 5;
        cout << "\nCongratulations! You get +10 HP and +5 Power" << endl;
    }
};

static player character_creation()
{
    string name;
    int hp, power;

    cout << "Creating character" << endl
    << "Hero name: " << endl;
    cin >> name;

    cout << "HP: " << endl;
    cin >> hp;

    cout << "Power: " << endl;
    cin >> power;

    cin.ignore();

    return player(name, hp, power);
}

int main()
{
    string command;

    player hero = character_creation();

    while (true)
    {
        cout << "\nAllowed comands: stats, exit, lvlup" << endl;

        getline(cin, command);

        if (command == "stats")
        {
            hero.show_stats();
        }

        else if (command == "lvlup")
        {
            hero.lvlup();
        }

        else if (command == "exit")
        {
            break;
        }
    }

    return 0;
}

