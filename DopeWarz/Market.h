#ifndef MARKET_H__
#define MARKET_H__

#include <map>
#include <iostream>
#include "randgen.h"

using namespace std;

class Market
{
public:
	Market();
	~Market();
	void BuildMarket();
	void SetDrugMap(map<string, double> map);
	void DisplayMarket();
	void GetPrice() const;
	map<string, double>& GetMap();

private:
	//DRUG NAME   PRICE
	map<string, double> m_Drugs;

};

#endif
