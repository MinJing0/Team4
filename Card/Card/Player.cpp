#include"Player.h"

Player::Player()
{
    this->cards = new Card[5];
}
void Player::setCards(Card* cards)
{
    this->cards = cards;
}
Card* Player::getCards()
{
    return cards;
}

