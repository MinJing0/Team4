#ifndef C_H
#define C_H
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
    string get_str_suit();
    string get_str_symbol();
};

#endif
