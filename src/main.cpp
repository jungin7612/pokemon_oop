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
    Pokemon(std::string n, int m, std::string t, Skill s1, Skill s2, Skill s3, Skill s4)
    {
        name = n;
        max_hp = m;
        type = t;
        skill_list[0] = s1;
        skill_list[1] = s2;
        skill_list[2] = s3;
        skill_list[3] = s4;
    }

private:
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

        return 0;
}
