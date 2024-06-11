#include <iostream>
#include <array>
#include <algorithm>
#include <random>
#include <chrono>

using namespace std;

// Перечисления для рангов и мастей карт
enum Rank { two = 2, three, four, five, six, seven, eight, nine, ten, jack, queen, king, ace };
enum Suit { clubs, diamonds, hearts, spades };

// Структура для представления карты
struct Card {
    Rank rank;
    Suit suit;
};

// Функция для печати карты
void printCard(const Card& card) 
{
    string rankStr;
    switch (card.rank) 
    {
    case two: 
        rankStr = "2";  break;
    case three: 
        rankStr = "3";  break;
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
        rankStr = "J"; break;
    case queen:
        rankStr = "Q"; break;
    case king: 
        rankStr = "K"; break;
    case ace: 
        rankStr = "A"; break;
    }
    string suitStr;
    switch (card.suit) {
    case clubs: 
        suitStr = "C";  break;
    case diamonds: 
        suitStr = "D"; break;
    case hearts: 
        suitStr = "H";  break;
    case spades: 
        suitStr = "S"; break;
    }

    cout << rankStr << suitStr << " ";
}

// Функция для создания колоды карт
    array<Card, 52> createDeck() 
    {
    array<Card, 52> deck;
    int index = 0;
    for (int rank = two; rank <= ace; ++rank) 
    {
        for (int suit = clubs; suit <= spades; ++suit) 
        {
            deck[index++] = { static_cast<Rank>(rank), static_cast<Suit>(suit) };
        }
    }
    return deck;
}

// Функция для печати колоды карт
void printDeck(const std::array<Card, 52>& deck) 
{
    for (const auto& card : deck) 
    {
        printCard(card);
    }
    cout << std::endl;
}

// Функция для перетасовки колоды карт
void shuffleDeck( array<Card, 52>& deck) 
{
    unsigned seed = chrono::system_clock::now().time_since_epoch().count();
    shuffle(deck.begin(), deck.end(), default_random_engine(seed));
}

// Функция для получения значения карты
int getCardValue(const Card& card) 
{
    switch (card.rank) {
    case two: case three: case four: case five:
    case six: case seven: case eight: case nine:

        return static_cast<int>(card.rank);
    case ten: case jack: case queen: case king:
        return 10;
    case ace:
        return 11;
    }
    return 0;
}

int main() 
{

    setlocale(LC_ALL, "RU");
    // Создание колоды
    auto deck = createDeck();
    cout << "Оригинальная колода:\n";
    printDeck(deck);

    // Перетасовка колоды
    shuffleDeck(deck);
    cout << "\nПеретасованная колода:\n";
    printDeck(deck);

    return 0;
}
