#include"Game.h"
#include<ctime>
#include<iostream>
using namespace std;

int Game::getRound()
{
	return round;
}
Card* Game::createDeck()
{
    cards = new Card[DECK_SIZE];
    player1 = new Card[5];
    player2 = new Card[5];
    player3 = new Card[5];
    winner = new Card[5];
    for (int i = 1; i <= 13; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            cards[j + (i - 1) * 4] = Card(i + (j + 1) * 0.1);
        }
    }
    return cards;
}
void Game::Shuffle(int r)
{
    srand(r);
    for (int i = 0; i < 52; ++i)
    {
        int j = rand() % 52;
        swapByReference(cards[i], cards[j]);
    }
}
void Game::distribute()
{
    for (int i = 0; i < 20; i++)
    {
        if (i < 5)
            player1[i] = cards[i];
        else if (i >= 5 && i < 10)
            player2[i - 5] = cards[i];
        else if (i >= 10 && i < 15)
            player3[i - 10] = cards[i];
        else
            winner[i - 15] = cards[i];
    }
}
void Game::printCard(int n)
{
    cards[n].print();
}
Card* Game::getPlayer1()
{
    return player1;
}
Card* Game::getPlayer2()
{
    return player2;
}
Card* Game::getPlayer3()
{
    return player3;
}
Card* Game::getWinner()
{
    return winner;
}
void Game::show(Card* player)
{
    for (int i = 0; i < 3; i++)
    {
        cout << "Symbol: " << player[i].getSymbol() << endl;
        cout << "Suit: " << player[i].getSuit() << endl;
    }
    cout << "----------" << endl;
}
void Game::compare()
{

}