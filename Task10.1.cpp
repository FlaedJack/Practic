#include <iostream>
#include <string>
#include <array>

using namespace std;

enum class ItemType
{
    HealthPotion,
    Torch,
    Arrow
};

struct Item
{
    ItemType type{};
    int count{};
};

string getItemTypeString(ItemType type)
{
    switch (type)
    {
    case ItemType::HealthPotion:
        return "Health Potion";

    case ItemType::Torch:
        return "Torch";

    case ItemType::Arrow:
        return "Arrow";

    default:
        return "Unknown";
    }
}
int countTotalItems(const std::array<int, 3>& items)
{
    int totalItems = 0;
    for (int i = 0; i < items.size(); i++)
    {
        totalItems += items[i];
    }
    return totalItems;
}

int main()
{
    std::array<int, 3> playerItems{ 2, 5, 10 };

    int totalItems = countTotalItems(playerItems);

    std::cout << "Total items: " << totalItems << std::endl;
    std::cout << "Number of torches: " << playerItems[1] << std::endl;

    return 0;
}
