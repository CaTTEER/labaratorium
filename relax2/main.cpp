#include <iostream>
#include <string>
#include <windows.h>


using namespace std;

static void enableColors()
{
    HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    DWORD mode = 0;
    if (!GetConsoleMode(hOut, &mode) ||
        !SetConsoleMode(hOut, mode | ENABLE_VIRTUAL_TERMINAL_PROCESSING)) {
        cout << "Colors are not supported in this console" << endl;
        }
}

class Enemy
{
    public:

    string name;
    int hp;
    int max_hp;
    int power;

    Enemy() : name(""), hp(0), max_hp(0), power(0) {}

    Enemy(string name, int hp, int max_hp, int power)
    : name(name), hp(hp), max_hp(max_hp), power(power) {}

    string update_health_bar(int player_power)
    {
        hp -= player_power;

        int bar_width = 10;
        string update_health_bar = "";

        int filled = (hp * bar_width) / max_hp;

        if (filled < 0)
        {
            filled = 0;
        }

        if (hp < 0)
        {
            hp = 0;
        }

        for (int i = 0 ; i < bar_width; i++)
        {
            if (i < filled)
            {
                update_health_bar += "█";
            }
            else
            {
                update_health_bar += "░";
            }
        }

        return update_health_bar;
    }
};

class Player
{
    public:

    string name;
    int hp;
    int power;

    Player() : name("Hero"), hp(0), power(0){}

    Player (string name, int hp, int power)
    : name(name), hp(hp), power(power) {}

    void show_stats()
    {
        cout << "Name: " << name << endl
        << "HP: " << hp << endl
        << "Power: " << power << endl;
    }

    int attack(Enemy &enemy, Player player)
    {
        const string RED = "\033[31m";
        const string GREEN = "\033[32m";
        const string CLEAR = "\033[0m";

        if (enemy.hp > 0)
        {
            cout << RED << enemy.name << " took " << player.power << " damage!" << CLEAR << endl << endl
            << "Current " << enemy.name << " HP:" << endl;

            string current_hp_bar = enemy.update_health_bar(player.power);

            cout << "[" << GREEN << current_hp_bar << CLEAR << "]" << " " << GREEN << enemy.hp <<  "/" << enemy.max_hp << CLEAR;
        }
        else
        {
            cout << "Enemy defeated!" << endl;
            return 0;
        }

        return enemy.hp;
    }

    void character_creating()
    {
        cout << "Character Creating" << endl
        << "Input HP:" << endl;
        cin >> hp;
        cin.ignore();

        cout << "Input Power:" << endl;
        cin >> power;
        cin.ignore();
    }
};

Enemy enemy_choice()
{
    string choice;

    cout << "Choose the enemy:" << endl
    << "wolf" << endl
    << "undead" << endl
    << "boss" << endl;

    cin >> choice;

    if (choice == "wolf")
    {
        return Enemy("Wolf", 10, 10, 2);
    }

    if (choice == "undead")
    {
        return Enemy("Undead", 20, 20, 4);
    }

    if (choice == "boss")
    {
        return Enemy("Boss", 30, 30,6);
    }

    cin.ignore();
}

int main()
{
    enableColors();

    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);

    string choice;
    Player player;

    player.character_creating();

    Enemy enemy = enemy_choice();

    while (true)
    {
        cout << "\nAllowed commands : stats, attack, exit" << endl;
        cin >> choice;

        if (choice == "stats")
        {
            player.show_stats();
        }
        else if (choice == "attack")
        {
            enemy.hp = player.attack(enemy, player);

            if (enemy.hp <= 0)
            {
                cout <<  "\n\nEnemy defeated!";
                break;
            }
        }
        else if (choice == "exit")
        {
            break;
        }
    }

    return 0;
}