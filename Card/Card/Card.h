#ifndef C_H
#define C_H
#include <vector>
#include <string>
using namespace std;

class Card
{
private:
    vector<string> St = { "Club", "Diamond", "Heart", "Spade" };
    vector<string> Sl = { "1", "2", "3", "4", "5", "6", "7", "8", "9", "10", "10", "10", "10" };
    int suit;
    int symbol;
    double card;
public:
    Card(double);
    Card();
    string getSuit();
    string getSymbol();
    void print();
    void setCard(double);
    double getCard();
    int getIntSymbol();
};

#endif