#include "PC.h"

PC::PC()
{
	this->cards = new Card[5];
}

void PC::setCards(Card* cards)
{
    this->cards = cards;
}

Card* PC::getCards()
{
    return cards;
}