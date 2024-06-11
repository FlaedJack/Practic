#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <chrono>

// Перечисления для рангов и мастей карт
enum Rank 
{ 
    two = 2, 
    three, 
    four,
    five, 
    six, 
    seven, 
    eight, 
    nine, 
    ten, 
    jack, 
    queen, 
    king, 
    ace 
};
enum Suit 
{ 
    clubs, 
    diamonds, 
    hearts, 
    spade 
};

// Структура для представления карты
struct Card {
    Rank rank;
    Suit suit;
};

// Функция для печати карты
void printCard(const Card& card) 
{
    std::string rankStr;
    switch (card.rank) 
    {
    case two: 
        rankStr = "2"; break;
    case three: 
        rankStr = "3"; break;
    case four: 
        rankStr = "4"; break;
    case five: 
        rankStr = "5"; break;
    case six: 
        rankStr = "6"; break;
    case seven: 
        rankStr = "7"; break;
    case eight: 
        rankStr = "8"; break;
    case nine: 
        rankStr = "9"; break;
    case ten: 
        rankStr = "10"; break;
    case jack:
        rankStr = "Валет"; break;
    case queen: 
        rankStr = "Дама"; break;
    case king: 
        rankStr = "Король"; break;
    case ace: 
        rankStr = "Туз"; break;
    }

    std::string suitStr;
    switch (card.suit) 
    {
    case clubs: suitStr = "Трефы"; break;
    case diamonds: suitStr = "Бубны"; break;
    case hearts: suitStr = "Червы"; break;
    case spade: suitStr = "Пики"; break;
    }

    std::cout << rankStr << " " << suitStr << std::endl;
}

// Функция для создания колоды карт
std::vector<Card> createDeck()
{
    std::vector<Card> deck;
    for (int rank = two; rank <= ace; ++rank)
    {
        for (int suit = clubs; suit <= spade; ++suit) 
        {
            deck.push_back({ static_cast<Rank>(rank), static_cast<Suit>(suit) });
        }
    }
    return deck;
}

// Функция для печати колоды карт
void printDeck(const std::vector<Card>& deck)
{
    for (const auto& card : deck)
    {
        printCard(card);
    }
}

// Функция для перетасовки колоды карт
void shuffleDeck(std::vector<Card>& deck) 
{
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::shuffle(deck.begin(), deck.end(), std::default_random_engine(seed));
}

// Функция для получения значения карты
int getCardValue(const Card& card) 
{
    switch (card.rank)
    {
    case two: case three: case four: case five:
    case six: case seven: case eight: case nine:
        return static_cast<int>(card.rank);
    case ten: case jack: case queen: case king:
        return 10;
    case ace
        :
        return 11;
    }
    return 0;
}

// Функция для игры в блэкджек
bool playBlackjack(const std::vector<Card>& deck) 
{
    // Создание стартовой колоды
    std::vector<Card> deckCopy = deck;

    // Дилер получает одну карту
    Card dealerCard = deckCopy.back();
    deckCopy.pop_back();

    // Игрок получает две карты
    Card playerCard1 = deckCopy.back();
    deckCopy.pop_back();
    Card playerCard2 = deckCopy.back();
    deckCopy.pop_back();

    // Игрок ходит
    int playerScore = getCardValue(playerCard1) + getCardValue(playerCard2);
    while (true) 
    {
        std::cout << "Ваш счет: " << playerScore << std::endl;
        std::cout << "Вы хотите взять еще карту или остановиться? ";
        char choice;
        std::cin >> choice;
        if (choice == 'Y' || choice == 'N') 
        {
            Card newCard = deckCopy.back();
            deckCopy.pop_back();
            playerScore += getCardValue(newCard);
            if (playerScore > 21) 
            {
                std::cout << "У вас перебор. Вы проиграли." << std::endl;
                return false;
            }
        }
        else if (choice == 's' || choice == 'S') 
        {
            break;
        }
        else 
        {
            std::cout << "Неверный выбор. Введите 'h' для взятия карты или 's' для остановки." << std::endl;
        }
    }

    // Дилер ходит
    int dealerScore = getCardValue(dealerCard);
    while (dealerScore < 17) 
    {
        Card newCard = deckCopy.back();
        deckCopy.pop_back();
        dealerScore += getCardValue(newCard);
        if (dealerScore > 21)
        {
            std::cout << "У дилера перебор. Вы выиграли." << std::endl;
            return true;
        }
    }

    // Результат
    if (playerScore > dealerScore) 
    {
        std::cout << "Ваш счет выше. Вы выиграли." << std::endl;
        return true;
    }
    else if (playerScore < dealerScore)
    {
        std::cout << "Счет дилера выше. Вы проиграли." << std::endl;
        return false;
    }
    else 
    {
        std::cout << "Ничья. Вы выиграли." << std::endl;
        return true;
    }
}

int main() 
{
    setlocale(LC_ALL, "RU");
    // Создание колоды
    auto deck = createDeck();
    shuffleDeck(deck);

    // Игра в блэкджек
    if (playBlackjack(deck)) 
    {
        std::cout << "Поздравляем, вы выиграли!" << std::endl;
    }
    else 
    {
        std::cout << "Извините, вы проиграли." << std::endl;
    }
    return 0;
}
