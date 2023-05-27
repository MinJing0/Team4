#include"Boss.h"

Boss::Boss()
{
    this->cards = new Card[5];
}
void Boss::setCards(Card* cards)
{
    this->cards = cards;
}
Card* Boss::getCards()
{
    return cards;
}
