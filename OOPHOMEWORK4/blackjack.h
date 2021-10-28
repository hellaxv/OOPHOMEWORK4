#pragma once
#include <iostream>
#include <vector>

/*HOMEWORK3
Реализовать класс Hand, который представляет собой коллекцию карт. 
В классе будет одно поле: вектор указателей карт (удобно использовать вектор, т.к. это по сути динамический массив, 
а тип его элементов должен быть - указатель на объекты класса Card). 
Также в классе Hand должно быть 3 метода:
метод Add, который добавляет в коллекцию карт новую карту, соответственно он принимает в качестве параметра указатель на новую карту
метод Clear, который очищает руку от карт
метод GetValue, который возвращает сумму очков карт руки (здесь предусмотреть возможность того, что туз может быть равен 11).
*/

enum Suits
{
    CLUBS,
    DIAMONDS,
    HEARTS,
    SPADES
};

enum Ranks {
    ACE = 1,
    TWO,
    THREE,
    FOUR,
    FIVE,
    SIX,
    SEVEN,
    EIGHT,
    NINE,
    TEN,
    JACK,
    QUEEN,
    KING
};

class Card
{
private:
    Suits suit = CLUBS;
    Ranks rank = ACE;
    bool isFaceUp = false;
public:
    Card() {}
    Card(Ranks inputRank, Suits inputSuit)
        : suit(inputSuit), rank(inputRank)
    {

    }
    void Flip()
    {
        isFaceUp = !isFaceUp;
    }

    Ranks getValue()
    {
        return rank;
    }
};

class Hand
{
private:
    std::vector<Card*> hand;
public:
    void Add(Card* input)
    {
        hand.push_back(input);
    }

    void Clear()
    {
        hand.clear();
    }

    int GetValue()
    {
        int sum = 0;
        for (Card* card : hand)
        {
            sum += card->getValue();
        }
        return sum;
    }
}; 
