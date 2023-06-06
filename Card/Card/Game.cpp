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
void Game::giveCard()
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

    for (int i = 0; i < 5; ++i)
    {
        c[i] = cards[k];
        k++;
    }
    pc.setCards(c);
}

Player& Game::getPlayer(int index)
{
    return player[index];
}

PC& Game::getPC()
{
    return pc;
}

void Game::compare(Player& p)
{
    p.setWin(0);

    if (p.getCstyle() == 0)
        return;

    if (p.getCstyle() > pc.getCstyle())
    {
        p.setWin(1);
        return;
    }

    if (p.getCstyle() == pc.getCstyle() && p.getCstyle() == 2)
    {
        Card* cardp = new Card[5];
        Card* cardpc = new Card[5];
        cardp = p.getCards();
        cardpc = pc.getCards();

        int s1, s2;
        int a[4];
        a[0] = cardp[3].getCard();
        a[1] = cardp[4].getCard();
        a[2] = cardpc[3].getCard();
        a[3] = cardpc[4].getCard();

        for (int i = 0; i < 4; ++i)
            if (a[i] > 10)
                a[i] = 10;

        s1 = (a[0] + a[1]) % 10;
        s2 = (a[2] + a[3]) % 10;

        if (s1 > s2)
        {
            p.setWin(1);
            return;
        }
        else if (s1 < s2)
            return;
    }

    if (p.getCstyle() == pc.getCstyle())
    {
        Card* cardp = new Card[5];
        Card* cardpc = new Card[5];
        cardp = p.getCards();
        cardpc = pc.getCards();

        double maxp, maxpc;
        maxp = cardp[0].getCard();
        maxpc = cardpc[0].getCard();

        for (int i = 1; i < 5; ++i)
        {
            if (cardp[i].getCard() > maxp)
                maxp = cardp[i].getCard();
            if (cardpc[i].getCard() > maxpc)
                maxpc = cardpc[i].getCard();
        }
        if (maxp > maxpc)
            p.setWin(1);
    }
}