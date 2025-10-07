//COMSC 210 | Lab 20 | Anisha Rayapudi
//IDE used: VS 2022

#include <iostream>
#include <iomanip>
using namespace std;
const int SIZE = 3;
class Chair {
private:
int legs;
double * prices;
public:
// constructors
Chair() {
prices = new double[SIZE];
legs = 3 + rand() % 2;
for (int i = 0; i < SIZE; i++){
    double dollars = 100 + rand() % 900;
    double cents = (rand() % 100) / 100.0;
    prices[i] = dollars + cents;
}
}
Chair(int l, double p[]) {
prices = new double[SIZE];
legs = l;
for (int i = 0; i < SIZE; i++)
prices[i] = p[i];
}
// setters and getters
void setLegs(int l) { legs = l; }
int getLegs() { return legs; }
void setPrices(double p1, double p2, double p3) {
prices[0] = p1; prices[1] = p2; prices[2] = p3;
}
double getAveragePrices() {
double sum = 0;
for (int i = 0; i < SIZE; i++)
sum += prices[i];
return sum / SIZE;
}
void print() {
cout << "CHAIR DATA - legs: " << legs << endl;
cout << "Price history: " ;
for (int i = 0; i < SIZE; i++)
cout << prices[i] << " ";
cout << endl << "Historical avg price: " << getAveragePrices();
cout << endl << endl;
}
};
int main() {
cout << fixed << setprecision(2);
//creating pointer to first chair object
cout << "First block with default constructor" << endl;
Chair *chairPtr = new Chair;
chairPtr->print();
//creating dynamic chair object with constructor
cout << "Second block with parameter constructor" << endl;
double pprices[SIZE] = {100.0, 200.0, 300.0};
Chair *livingChair = new Chair(3, pprices);
livingChair->print();
delete livingChair;
livingChair = nullptr;
//creating dynamic array of chair objects
cout << "Third block with defualt constructor" << endl;
Chair *collection = new Chair[SIZE];
for (int i = 0; i < SIZE; i++)
collection[i].print();
return 0;
}