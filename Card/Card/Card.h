#ifndef C_H
#define C_H
#include <vector>
#include <string>
using namespace std;

class Card
{
private:
    int suit;
    int symbol;
    double card;
public:
    Card(double);
    Card();
    int getSuit();
    int getSymbol();
    void setCard(double);
    double getCard();
};

#endif