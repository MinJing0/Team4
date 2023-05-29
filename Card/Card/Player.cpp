#include"Player.h"

Player::Player()
{
    this->cards = new Card[5];
    win = 0;
}
void Player::setCards(Card* cards)
{
    for (int i = 0; i < 5; ++i)
        this->cards[i] = cards[i];
}

void Player::setCstyle(int v)
{
    cStyle = v;
}

int Player::getCstyle()
{
    return cStyle;
}

Card* Player::getCards()
{
    return cards;
}

bool Player::getWin()
{
    return win;
}

void Player::setWin(bool w)
{
    win = w;
}