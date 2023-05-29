#include"Player.h"

Player::Player()
{
    this->cards = new Card[5];
}
void Player::setCards(Card* cards)
{
    for(int i = 0; i < 5; ++i)
        this->cards[i] = cards[i];
}
Card* Player::getCards()
{
    return cards;
}

