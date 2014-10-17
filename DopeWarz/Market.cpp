#include <iostream>
#include <iomanip>
#include <string>
#include "Market.h"
#include "randgen.h"

using namespace std;

Market::Market()
{
	BuildMarket();
}


Market::~Market()
{
}

void Market::BuildMarket()
{
	RandGen rNg;
	vector<pair<string, double>> m;
	if (int i = (rNg(100) + 1) < 50)
	{
		m.push_back(make_pair("Peyote", rNg(900) + 150));
	}
	if (int i = (rNg(100) + 1) < 50)
	{
		m.push_back(make_pair("Hashish", rNg(2500) + 1000));
	}
	if (int i = (rNg(100) + 1) < 60)
	{
		m.push_back(make_pair("Acid", rNg(3000) + 1500));
	}
	if (int i = (rNg(100) + 1) < 70)
	{
		m.push_back(make_pair("Cocaine", rNg(30000) + 19000));
	}
	if (int i = (rNg(100) + 1) < 80)
	{
		m.push_back(make_pair("Crack", rNg(4000) + 2000));
	}
	if (int i = (rNg(100) + 1) < 50)
	{
		m.push_back(make_pair("Ectasy", rNg(100) + 20));
	}
	if (int i = (rNg(100) + 1) < 80)
	{
		m.push_back(make_pair("Heroin", rNg(18000) + 10000));
	}
	if (int i = (rNg(100) + 1) < 70)
	{
		m.push_back(make_pair("Opium", rNg(2000) + 800));
	}
	if (int i = (rNg(100) + 1) < 50)
	{
		m.push_back(make_pair("Shrooms", rNg(1700) + 900));
	}
	if (int i = (rNg(100) + 1) < 50)
	{
		m.push_back(make_pair("Smack", rNg(6000) + 3000));
	}
	if (int i = (rNg(100) + 1) < 50)
	{
		m.push_back(make_pair("Speed", rNg(500) + 100));
	}
	if (int i = (rNg(100) + 1) < 50)
	{
		m.push_back(make_pair("Weed", rNg(600) + 200));
	}
	
	SetDrugMap(m);
}
void Market::DisplayMarket() 
{
	cout << "\n\n<-----The Market Today----->\n\n";
	int i = 1;
	for (vector<pair<string, double>>::iterator it = m_Drugs.begin(); it != m_Drugs.end(); ++it)
	{	
		cout << "(" << i << ") "  << setw(10) << it->first << " $" << it->second << endl;
		++i;
	}
}
void Market::GetPrice() const
{

}

void Market::SetDrugMap(vector<pair<string, double>> map)
{
	m_Drugs = map;
}

vector<pair<string, double>>& Market::GetMap()
{
	return m_Drugs;
}