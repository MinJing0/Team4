#include "Card.h"
#include "Player.h"
#include "PC.h"

#ifndef Pr_H
#define Pr_H

class Print
{
public:
    void welcome();
    void gamePlay();
    void rule();
    void playerHandCard(Player&, int, Card*);
    void pcHandCard(PC&, Card*);
    void win(Player&, int);
    void stakeMoney(Player&);
    void showStakeMoney(Player&);
    void notHaveMoney(int);
    void isExit(int);
    void lastMoney(Player&);
    void rank(Player&, Player&, Player&);
};

#endif