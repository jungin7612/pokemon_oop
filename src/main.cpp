#include <iostream>
#include <string>

// Skill 클래스: 포켓몬의 기술을 정의하는 클래스
class Skill
{
public:
    Skill() {} // 기본 생성자
    // 파라미터가 있는 생성자: 기술의 이름, 타입, 데미지, 최대 사용 횟수를 설정
    Skill(std::string n, std::string t, int d, int m)
    {
        name = n;
        type = t;
        damage = d;
        maxTry = m;
        currentTry = m;
    }

    // 기술 정보 반환 메서드
    std::string getName() const { return name; }
    std::string getType() const { return type; }
    int getDamage() const { return damage; }
    int getCurrentTry() const { return currentTry; }
    int getMaxTry() const { return maxTry; }

    // 기술 사용 시 남은 사용 횟수 감소
    void useSkill()
    {
        if (currentTry > 0)
            --currentTry;
    }

private:
    std::string name; // 기술 이름
    std::string type; // 기술 타입
    int damage;       // 기술 데미지
    int maxTry;       // 기술 최대 사용 횟수
    int currentTry;   // 기술 현재 남은 사용 횟수
};

// Pokemon 클래스: 포켓몬의 속성과 행동 정의
class Pokemon
{
public:
    Pokemon() {} // 기본 생성자

    // 파라미터가 있는 생성자: 포켓몬의 이름, HP, 타입, 기술 리스트 초기화
    Pokemon(int no, std::string n, int m, std::string t, Skill s1, Skill s2, Skill s3, Skill s4)
    {
        number = no;
        name = n;
        max_hp = m;
        current_hp = m;
        type = t;
        skill_list[0] = s1;
        skill_list[1] = s2;
        skill_list[2] = s3;
        skill_list[3] = s4;
        last_used_skill = -1;
        isSkillUsed = 0;
    }

    // 포켓몬 정보 반환 메서드
    std::string getName() const { return name; }
    std::string getType() const { return type; }
    int getHP() const { return current_hp; }
    const Skill *getSkills() const { return skill_list; }
    int getLastUsedSkill() const { return last_used_skill; }

    // 기술 사용 메서드: 상대방 포켓몬에 데미지를 입힘
    void useSkill(int skillIndex, Pokemon &defender)
    {
        if (skill_list[skillIndex].getCurrentTry() > 0)
        {
            skill_list[skillIndex].useSkill(); // 기술 사용
            last_used_skill = skillIndex;
            int damage = skill_list[skillIndex].getDamage();

            // 타입 상성 확인
            std::string attackType = skill_list[skillIndex].getType();
            std::string defenderType = defender.getType();
            if (isSuperEffective(attackType, defenderType))
            {
                damage += 5;
                effectiveness_message = "It was super effective.";
            }
            else if (isNotVeryEffective(attackType, defenderType))
            {
                damage -= 3;
                effectiveness_message = "It was not very effective.";
            }
            else
            {
                effectiveness_message = "It was effective.";
            }

            // 상대방 HP 감소
            defender.current_hp -= damage;
            if (defender.current_hp < 0)
            {
                defender.current_hp = 0;
            }

            // 사용된 스킬 메시지 설정
            skill_use_message = name + " used " + skill_list[skillIndex].getName() + ".";
            isSkillUsed = 0;
        }
        else
        {
            // 스킬 사용 실패 메시지 설정
            skill_use_message = name + " failed to perform " + skill_list[skillIndex].getName() + ".";
            isSkillUsed = 1;
        }
    }

    // 기술 사용 및 효과 메시지 반환 메서드
    std::string getSkillUseMessage() const { return skill_use_message; }
    std::string getEffectivenessMessage() const { return effectiveness_message; }
    int getIsSkillUsed() const { return isSkillUsed; }

private:
    int number;                        // 포켓몬 번호
    std::string name;                  // 포켓몬 이름
    int max_hp;                        // 최대 HP
    int current_hp;                    // 현재 HP
    std::string type;                  // 포켓몬 타입
    Skill skill_list[4];               // 기술 리스트
    int last_used_skill;               // 마지막 사용한 기술 인덱스
    std::string skill_use_message;     // 기술 사용 메시지
    std::string effectiveness_message; // 기술 효과 메시지
    int isSkillUsed;                   // 스킬 사용 성공 여부

    // 타입 상성이 "super effective"인지 확인
    bool isSuperEffective(const std::string &attackType, const std::string &defenderType)
    {
        if ((attackType == "Electric" && defenderType == "Water") ||
            (attackType == "Ground" && defenderType == "Electric") ||
            (attackType == "Water" && defenderType == "Fire") ||
            (attackType == "Grass" && defenderType == "Water") ||
            (attackType == "Fire" && defenderType == "Grass") ||
            (attackType == "Water" && defenderType == "Ground") ||
            (attackType == "Ground" && defenderType == "Fire"))
        {
            return true;
        }
        return false;
    }

    // 타입 상성이 "not very effective"인지 확인
    bool isNotVeryEffective(const std::string &attackType, const std::string &defenderType)
    {
        if ((attackType == "Electric" && defenderType == "Ground") ||
            (attackType == "Electric" && defenderType == "Electric") ||
            (attackType == "Electric" && defenderType == "Grass") ||
            (attackType == "Water" && defenderType == "Grass") ||
            (attackType == "Water" && defenderType == "Water") ||
            (attackType == "Grass" && defenderType == "Fire") ||
            (attackType == "Grass" && defenderType == "Ground") ||
            (attackType == "Grass" && defenderType == "Grass") ||
            (attackType == "Fire" && defenderType == "Water") ||
            (attackType == "Fire" && defenderType == "Fire") ||
            (attackType == "Ground" && defenderType == "Grass"))

        {
            return true;
        }
        return false;
    }
};

// 화면에 구분선 출력
void drawRowLine()
{
    std::cout << "+";
    for (int i = 0; i < 30; ++i)
    {
        std::cout << "-";
    }
    std::cout << "+";
    for (int i = 0; i < 30; ++i)
    {
        std::cout << "-";
    }
    std::cout << "+" << std::endl;
}

// 게임 타이틀 출력
void printTitle(const std::string &title)
{
    std::cout << "+";
    for (int i = 0; i < 61; ++i)
    {
        std::cout << "-";
    }
    std::cout << "+" << std::endl;
    std::cout << "| " << title;
    for (size_t i = 0; i < 61 - title.length() - 2; ++i)
    {
        std::cout << " ";
    }
    std::cout << " |" << std::endl;
    drawRowLine();
}

// 두 포켓몬의 상태를 화면에 출력
void printTwoColumnContent(const Pokemon &leftPokemon, const Pokemon &rightPokemon, int turn)
{
    auto printRow = [](const std::string &left, const std::string &right, size_t leftWidth, size_t rightWidth)
    {
        std::cout << "| " << left;
        for (size_t i = 0; i < leftWidth - left.length(); ++i)
        {
            std::cout << " ";
        }
        std::cout << " | " << right;
        for (size_t i = 0; i < rightWidth - right.length(); ++i)
        {
            std::cout << " ";
        }
        std::cout << " |" << std::endl;
    };

    // 포켓몬 기본 정보 출력
    std::string leftIndicator = (turn == 0) ? "(*)" : "";
    std::string rightIndicator = (turn == 1) ? "(*)" : "";
    printRow(leftPokemon.getName() + " " + leftIndicator, rightPokemon.getName() + " " + rightIndicator, 28, 28);
    printRow("Type: " + leftPokemon.getType(), "Type: " + rightPokemon.getType(), 28, 28);
    printRow("HP: " + std::to_string(leftPokemon.getHP()), "HP: " + std::to_string(rightPokemon.getHP()), 28, 28);

    // 최근 사용한 스킬 출력
    drawRowLine();
    std::string leftLastSkill = (leftPokemon.getLastUsedSkill() != -1) ? leftPokemon.getSkills()[leftPokemon.getLastUsedSkill()].getName() : "-";
    std::string rightLastSkill = (rightPokemon.getLastUsedSkill() != -1) ? rightPokemon.getSkills()[rightPokemon.getLastUsedSkill()].getName() : "-";
    printRow("Latest Skill: " + leftLastSkill, "Latest Skill: " + rightLastSkill, 28, 28);

    // 효과 메시지 출력
    std::string leftEffectivenessMessage = (leftPokemon.getLastUsedSkill() != -1) ? leftPokemon.getEffectivenessMessage() : "";
    std::string rightEffectivenessMessage = (rightPokemon.getLastUsedSkill() != -1) ? rightPokemon.getEffectivenessMessage() : "";
    printRow(leftEffectivenessMessage, rightEffectivenessMessage, 28, 28);
    drawRowLine();

    // 포켓몬 스킬 출력
    const Skill *leftSkills = leftPokemon.getSkills();
    const Skill *rightSkills = rightPokemon.getSkills();
    for (size_t i = 0; i < 4; ++i)
    {
        printRow("(" + std::to_string(i) + ") " + leftSkills[i].getName(), "(" + std::to_string(i) + ") " + rightSkills[i].getName(), 28, 28);
        printRow("    - Type: " + leftSkills[i].getType(), "    - Type: " + rightSkills[i].getType(), 28, 28);
        printRow("    - Damage: " + std::to_string(leftSkills[i].getDamage()), "    - Damage: " + std::to_string(rightSkills[i].getDamage()), 28, 28);
        printRow("    - Count: " + std::to_string(leftSkills[i].getCurrentTry()) + "(" + std::to_string(leftSkills[i].getMaxTry()) + ")",
                 "    - Count: " + std::to_string(rightSkills[i].getCurrentTry()) + "(" + std::to_string(rightSkills[i].getMaxTry()) + ")", 28, 28);
    }
}

// 메인 함수: 게임 실행
int main()
{
    // 기술 정의
    Skill Tackle("Tackle", "Normal", 4, 5);
    Skill Grass_Knot("Grass Knot", "Grass", 8, 5);
    Skill Thunderbolt("Thunderbolt", "Electric", 10, 5);
    Skill Megabolt("Megabolt", "Electric", 15, 3);

    Skill Wrap("Wrap", "Normal", 4, 10);
    Skill Aqua_Tail("Aqua Tail", "Water", 3, 5);
    Skill Water_Pulse("Water Pulse", "Water", 13, 2);
    Skill Hyper_Beam("Hyper Beam", "Normal", 20, 1);

    Skill Sand_Attack("Sand Attack", "Ground", 8, 3);
    Skill Bite("Bite", "Normal", 12, 3);
    Skill Rain_Dance("Rain Dance", "Water", 15, 1);

    Skill Flamethrower("Flamethrower", "Fire", 11, 5);
    Skill Dig("Dig", "Ground", 7, 5);
    Skill Heat_Wave("Heat Wave", "Fire", 14, 5);

    Skill Hydro_pump("Hydro Pump", "Water", 12, 10);
    Skill Earth_Power("Earth Power", "Ground", 15, 10);
    Skill Surf("Surf", "Water", 13, 10);
    Skill Spatial_Rend("Spatial Rend", "Normal", 30, 10);

    // 포켓몬 정의
    Pokemon Pikachu(0, "Pikachu", 35, "Electric", Tackle, Grass_Knot, Thunderbolt, Megabolt);
    Pokemon Dratini(1, "Dratini", 41, "Water", Wrap, Aqua_Tail, Water_Pulse, Hyper_Beam);
    Pokemon Eevee(2, "Eevee", 55, "Normal", Tackle, Sand_Attack, Bite, Rain_Dance);
    Pokemon Charmander(3, "Charmander", 39, "Fire", Tackle, Flamethrower, Dig, Heat_Wave);
    Pokemon Palkia(4, "Palkia", 90, "Water", Hydro_pump, Earth_Power, Surf, Spatial_Rend);

    Pokemon pokemons[] = {Pikachu, Dratini, Eevee, Charmander, Palkia};

    int Pokemon1;
    int Pokemon2;

    // 포켓몬 선택
    std::cout << "Choose a Pokemon(0~4): ";
    std::cin >> Pokemon1;
    std::cout << "Choose a Pokemon(0~4): ";
    std::cin >> Pokemon2;

    if (Pokemon1 == Pokemon2)
    {
        std::cout << "You have to choose Pokemons different from each other." << std::endl;
        return 0;
    }

    int turn = 0; // 0: 왼쪽 포켓몬, 1: 오른쪽 포켓몬
    std::string title = "2024-02 Object-Oriented Programming Pokemon Master";
    printTitle(title);
    printTwoColumnContent(pokemons[Pokemon1], pokemons[Pokemon2], turn);
    drawRowLine();

    // 게임 루프
    while (true)
    {
        int skillChoice;
        std::cout << "Choose a skill (0~3): ";
        std::cin >> skillChoice;

        if (turn == 0)
        {
            pokemons[Pokemon1].useSkill(skillChoice, pokemons[Pokemon2]);
            std::cout << pokemons[Pokemon1].getSkillUseMessage() << std::endl;
            if (pokemons[Pokemon1].getIsSkillUsed() == 0)
            {
                std::cout << pokemons[Pokemon1].getEffectivenessMessage() << std::endl;
            }
            std::cout << std::endl;
            if (pokemons[Pokemon2].getHP() == 0)
            {
                std::cout << "===============================================================" << std::endl;
                std::cout << "Match Result: " << pokemons[Pokemon1].getName() << " defeats " << pokemons[Pokemon2].getName() << std::endl;
                break;
            }

            turn = 1;
        }
        else
        {
            pokemons[Pokemon2].useSkill(skillChoice, pokemons[Pokemon1]);
            std::cout << pokemons[Pokemon2].getSkillUseMessage() << std::endl;
            if (pokemons[Pokemon2].getIsSkillUsed() == 0)
            {
                std::cout << pokemons[Pokemon2].getEffectivenessMessage() << std::endl;
            }
            std::cout << std::endl;
            if (pokemons[Pokemon1].getHP() == 0)
            {
                std::cout << "===============================================================" << std::endl;
                std::cout << "Match Result: " << pokemons[Pokemon2].getName() << " defeats " << pokemons[Pokemon1].getName() << std::endl;
                break;
            }

            turn = 0;
        }

        printTitle(title);
        printTwoColumnContent(pokemons[Pokemon1], pokemons[Pokemon2], turn);
        drawRowLine();
    }

    return 0;
}
