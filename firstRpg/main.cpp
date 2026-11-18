#include <iostream>
#include <string>
#include <windows.h>
#include <vector>


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
    int hp, max_hp, power, exp_gain;

    Enemy() : name(""), hp(0), max_hp(0), power(0), exp_gain(0) {}

    Enemy(string name, int hp, int max_hp, int power, int exp_gain)
        : name(name), hp(hp), max_hp(max_hp), power(power), exp_gain(exp_gain) {}

    void show_stats()
    {
        cout << "┌─────────────┐" << endl;
        cout << "  Name: " << name << endl
        << "  HP: " << hp << endl
        << "  Power: " << power << endl;
        cout << "└─────────────┘" << endl;
    }

    void take_damage(int player_power)
    {
        cout << endl << name << " took " << "\033[31m" << player_power << " damage!" << "\033[0m" << endl << endl;

        hp -= player_power;

        if (hp < 0)
        {
            hp = 0;
        }
    }

    string health_bar()
    {
        int bar_width = 10;
        string update_health_bar = "";

        int filled = (hp * bar_width) / max_hp;

        if (filled < 0)
        {
            filled = 0;
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

    void show_health_bar()
    {
        health_bar();
        cout << "Current " << name << " HP:" << endl
        << "[" << "\033[31m" << health_bar() << "\033[0m" << "]"
        << " " << "\033[31m" << hp <<  "/" << max_hp << "\033[0m" << endl << endl;
    }
};

class Item
{
public:

    string name;
    int heal, count;

    Item() : name(" "), heal(0), count(0) {}

    Item(string name, int heal, int count)
        : name(name), heal(heal), count(count) {}
};

class Player
{
    public:

    string name;
    int hp, max_hp, power, level, experience, max_experience;
    vector <Item> inventory;

    Player() : name("Hero"), hp(10), max_hp(10), power(4), level(1), experience(0), max_experience(10)
    {
        inventory.push_back(Item("Heal potion", 5, 3));
    }

    Player (string name, int hp, int max_hp, int power, int level, int experience, int max_experience)
        : name(name), hp(hp), max_hp(max_hp), power(power), level(level), experience(experience), max_experience(max_experience) {}

    void show_stats()
    {
        cout << "┌────────────┐" << endl;
        cout << "  Hero " << level << " lvl" << endl
        << "  HP: " << hp << "/" << max_hp << endl
        << "  Power: " << power << endl
        << "  Exp: " << experience << "/" << max_experience << endl;
        cout << "└────────────┘" << endl;
    }

    int attack(Enemy &enemy)
    {
        const string RED = "\033[31m";
        const string GREEN = "\033[32m";
        const string CLEAR = "\033[0m";

        if (enemy.hp > 0)
        {
            enemy.take_damage(power);

            enemy_counter_attack(enemy.power);

            enemy.show_health_bar();

            show_health_bar();
        }

        return enemy.hp;
    }

    void show_inventory()
    {
        cout << "\nYour inventory:" << endl;

        for (int i = 0 ; i < inventory.size() ; i++)
        {
            cout << inventory[i].count << "x " << inventory[i].name << endl;
        }
    }

    void enemy_counter_attack(int damage)
    {
        cout << "Enemy attack you " << "\033[31m" << damage << " damage!" << "\033[0m" << endl << endl;

        take_damage(damage);
    }

    void take_damage(int damage)
    {
        hp -= damage;

        if (hp < 0)
        {
            hp = 0;
        }
    }

    void gain_exp(int exp)
    {
        experience += exp;

        if (experience >= 10)
        {
            experience -= 10;
            level_up();
        }
    }

    void level_up()
    {
        cout << "\033[34m" << "New level " << level << " ─> " << level + 1 << endl << endl
        << "HP restored / +10 Max HP / +2 Power" << "\033[0m" << endl;

        level += 1;
        max_hp += 10;
        hp = max_hp;
        power += 2;
    }

    void heal()
    {
        cout << "\nYou gain " << "\033[32m" << "+" << inventory[0].heal << "HP" << "\033[0m" << endl;

        hp += inventory[0].heal;

        if (hp > max_hp)
        {
            hp = max_hp;
        }

        show_health_bar();

        inventory[0].count -= 1;
    }

    string health_bar()
    {
        int bar_width = 10;
        string update_health_bar = "";

        int filled = (hp * bar_width) / max_hp;

        if (filled < 0)
        {
            filled = 0;
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

    void show_health_bar()
    {
        health_bar();
        cout <<  "Current " << name << " HP:" << endl
        << "[" << "\033[32m" << health_bar() << "\033[0m" << "]"
        << " " << "\033[32m" << hp <<  "/" << max_hp << "\033[0m" << endl;

    }
};

static void help()
{
    cout << "\nAllowed commands: \n1) battle \n2) inventory(inv) \n3) stats(sts) \n4) enemystats(ests) \n5) help \n6) exit(ex)";
}

int main()
{
    const string YELLOW  = "\033[33m";
    const string MAGENTA = "\033[35m";
    const string CLEAR = "\033[0m";
    const string BLUE = "\033[34m";

    enableColors();

    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);

    int enemy_index = 0;

    vector <Enemy> enemies
    {
        Enemy("Wolf", 10, 10, 2, 5),
        Enemy("Undead", 20, 20, 4, 10),
        Enemy("Boss", 30, 30, 6, 20)
    };

    Enemy enemy = enemies[enemy_index];

    string choice;
    Player player;
    Item inventory;

    cout << "\nWelcome, in this game, you should win 3 enemy" << endl
    << "\nAllowed commands: \n1) battle \n2) inventory(inv) \n3) stats(sts) \n4) enemystats(ests) \n5) help \n6) exit(ex)"
    << endl << endl;

    while (true)
    {
        cin >> choice;

        if (choice == "battle")
        {
            cout << "\nBattle against the " << "\033[90m" << enemy.name << "\033[0m" << endl << endl
            << "Allowed commands: attack(atk), use name_item" << endl;

            while (player.hp > 0 || enemy.hp > 0)
            {
                cin >> choice;

                if (choice == "attack" || choice == "atk")
                {
                    enemy.hp = player.attack(enemy);
                }
                else if (choice == "heal")
                {
                    player.heal();
                }

                //here we add more option for battle

                if (enemy.hp <= 0)
                {
                    cout << "\n\nEnemy defeated!" << endl
                    << BLUE << "+" << enemy.exp_gain << " XP" << CLEAR << endl;

                    player.gain_exp(enemy.exp_gain);

                    enemy = enemies[++enemy_index];
                    cout << "\nYour next enemy: " << "\033[90m" << enemies[enemy_index].name << "\033[0m "<< endl;

                    help();
                    cout << endl;

                    break;
                }

                if (player.hp <= 0)
                {
                    cout << endl << "\033[31m" <<"You defeated!" << "\033[0m" << endl;
                    return 0;
                }
            }
        }

        else if (choice == "inventory" || choice == "inv")
        {
            player.show_inventory();
        }
        else if (choice == "stats" || choice == "sts")
        {
            player.show_stats();
        }

        else if (choice == "enemystats" || choice == "ests")
        {
            enemy.show_stats();
        }

        else if (choice == "help")
        {
            help();
            cout << endl;
        }

        else if (choice == "exit" || choice == "ex")
        {
            break;
        }
    }

    return 0;
}