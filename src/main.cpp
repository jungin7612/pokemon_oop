#include <iostream>
#include <string>

class Skill
{
public:
    Skill() {}
    Skill(std::string n, std::string t, int d, int m)
    {
        name = n;
        type = t;
        damage = d;
        maxTry = m;
    }

private:
    std::string name;
    std::string type;
    int damage;
    int maxTry;
};

class Pokemon
{
public:
    Pokemon(int no, std::string n, int m, std::string t, Skill s1, Skill s2, Skill s3, Skill s4)
    {
        number = no;
        name = n;
        max_hp = m;
        type = t;
        skill_list[0] = s1;
        skill_list[1] = s2;
        skill_list[2] = s3;
        skill_list[3] = s4;
    }

private:
    int number;
    std::string name;
    int max_hp;
    std::string type;
    Skill skill_list[4];
};

int main()
{
    Skill Tackle("Tackle", "Normal", 4, 5);
    Skill Grass_Knot("Grass_Knot", "Grass", 8, 5);
    Skill Thunderbolt("Thunderbolt", "Electric", 10, 5);
    Skill Megabolt("Megabolt", "Electric", 15, 3);

    Skill Wrap("Wrap", "Normal", 4, 10);
    Skill Aqua_Tail("Aqua_Tail", "Water", 3, 5);
    Skill Water_Pulse("Water_Pulse", "Water", 13, 2);
    Skill Hyper_Beam("Hyper_Beam", "Normal", 20, 1);

    Skill Sand_Attack("Sand_Attack", "Ground", 8, 3);
    Skill Bite("Bite", "Normal", 12, 3);
    Skill Rain_Dance("Rain_Dance", "Water", 15, 1);

    Skill Flamethrower("Flamethrower", "Fire", 11, 5);
    Skill Dig("Dig", "Ground", 7, 5);
    Skill Heat_Wave("Heat_Wave", "Fire", 14, 5);

    Skill Hydro_pump("Hydro_Pump", "Water", 12, 10);
    Skill Earth_Power("Earth_Power", "Ground", 15, 10);
    Skill Surf("Surf", "Water", 13, 10);
    Skill Spatial_Rend("Spatial_Rend", "Normal", 30, 10);

    Pokemon Pikachu(0, "Pikachu", 35, "Electric", Tackle, Grass_Knot, Thunderbolt, Megabolt);
    Pokemon Dratini(1, "Dratini", 41, "Water", Wrap, Aqua_Tail, Water_Pulse, Hyper_Beam);
    Pokemon Eevee(2, "Eevee", 55, "Normal", Tackle, Sand_Attack, Bite, Rain_Dance);
    Pokemon Charmander(3, "Charmander", 39, "Fire", Tackle, Flamethrower, Dig, Heat_Wave);
    Pokemon Palkia(4, "Palkia", 90, "Water", Hydro_pump, Earth_Power, Surf, Spatial_Rend);

    int Pokemon1;
    int Pokemon2;
    std::cout << "Choose a Pokemon(0~4): ";
    std::cin >> Pokemon1;
    std::cout << std::endl;
    std::cout << "Choose a Pokemon(0~4): ";
    std::cin >> Pokemon2;

    if (Pokemon1 == Pokemon2)
    {
        std::cout << "You have to choose Pokemons different from each other." << std::endl;
        exit(0);
    }

    return 0;
}
