#include "PC.h"

PC::PC()
{
    this->cards = new Card[5];
}

void PC::setCards(Card* cards)
{
    for (int i = 0; i < 5; ++i)
        this->cards[i] = cards[i];
}

void PC::setCstyle(int v)
{
    cStyle = v;
}

int PC::getCstyle()
{
    return cStyle;
}

Card* PC::getCards()
{
    return cards;
}