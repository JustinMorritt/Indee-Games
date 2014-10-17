#ifndef MARKET_H__
#define MARKET_H__

#include <map>
#include <vector>
#include <iostream>
#include "randgen.h"

using namespace std;

class Market
{
public:
	Market();
	~Market();
	void BuildMarket();
	void SetDrugMap(vector<pair<string, double>> map);
	void DisplayMarket();
	void GetPrice() const;
	vector<pair<string, double>>& GetMap();

private:
	//DRUG NAME   PRICE
	vector<pair<string, double>> m_Drugs;

};

#endif
