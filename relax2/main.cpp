#include <iostream>
#include <string>

using namespace std;

class Creature
{
    public:

    string name;
    int hp;
    int power;

    Creature (string name_creature, int hp_creature, int power_creature)
    : name(name_creature), hp(hp_creature), power(power_creature) {}

    void show_stats()
    {
        cout << "Name: " << name << endl
        << "HP: " << hp << endl
        << "Power: " << power << endl;
    }
};

int main()
{
    Creature player = Creature("player", 100, 100);
    Creature enemy = Creature("undead", 200, 200);

    player.show_stats();
    cout << endl;
    enemy.show_stats();

    return 0;
}