#include <iostream>
#include <string>

using namespace std;

enum class MonstersType
{ 
    Ogre, 
    Slime, 
    Dragon, 
    GianSpider,
	Orc
};
    
struct Monster
{   
    MonstersType type{};
    string name {};
    int health{};
};
    
	string getMonsterTypeString(MonstersType type)
{
	switch (type)
	{
	case MonstersType::Ogre:
		return "Ogre";

	case MonstersType::Dragon:
		return "Dragon";

	case MonstersType::Orc:
		return "Orc";

	case MonstersType::GianSpider:
		return "Giant Spider";

	case MonstersType::Slime:
		return "Slime";

	default: return "Unknown";
	}
}


void printMonster(Monster monster)
{
		cout << "Это " << getMonsterTypeString(monster.type) <<
		" eго имя " << monster.name <<
		" и у него" << monster.health << " health.\n";
}

int main()
{
	setlocale(LC_ALL, "RU");

	Monster ogre{ MonstersType::Ogre, "Torg", 145 };
	Monster slime{ MonstersType::Slime, "Blurp", 23 };

	printMonster(ogre);
	printMonster(slime);

	return 0;
}
