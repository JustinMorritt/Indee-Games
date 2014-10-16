#ifndef MARKET_H__
#define MARKET_H__

#include <map>
#include <iostream>

using namespace std;

class Market
{
public:
	Market();
	~Market();
	void BuildMarket();
	void DisplayMarket() const;
	void GetPrice() const;

private:
	//DRUG NAME   PRICE
	map<string, double> m_Drugs;

};

#endif
