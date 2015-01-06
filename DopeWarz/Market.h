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
	void SetDrugMap(vector<pair<string, unsigned>> map);
	void DisplayMarket();
	unsigned GetPrice(int choice) const;
	bool MarketCompare(string drug);
	unsigned MarketPrice(string drug);
	string GetName(int choice) const;
	vector<pair<string, unsigned>>& GetMap();
	void SetMarketShown(bool shown);
	bool GetMarketShown();


private:
	//DRUG NAME   PRICE
	vector<pair<string, unsigned>> m_Drugs;
	bool MarketShown;

};

#endif
