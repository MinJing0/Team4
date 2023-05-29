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
};

#endif
