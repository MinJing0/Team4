#include"Game.h"
#include<ctime>
#include<iostream>
using namespace std;

int Game::round = 1;

void Game::swapByReference(Card& c1, Card& c2)
{
    Card buffer;
    buffer = c1;
    c1 = c2;
    c2 = buffer;
}
int Game::getRound()
{
	return round;
}

void Game::createDeck()
{
    cards = new Card[DECK_SIZE];
    for (int i = 1; i <= 13; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            cards[j + (i - 1) * 4] = Card(i + (j + 1) * 0.1);
        }
    }
}
void Game::Shuffle()
{
    srand(time(0));
    for (int i = 0; i < 52; ++i)
    {
        int j = rand() % 52;
        swapByReference(cards[i], cards[j]);
    }
}
void Game::distribute()
{
    Card* c = new Card[5];
    int k = 0;
    for (int j = 0; j < 3; ++j)
    {
        for (int i = 0; i < 5; ++i)
        {
            c[i] = cards[k];
            k++;
        }
        player[j].setCards(c);
    }
}
void Game::printCard(int n)
{
    cards[n].print();
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