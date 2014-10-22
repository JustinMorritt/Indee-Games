#include <sstream> 
#include "Player.h"
#include <iomanip>
#include <map>


Player::Player()
{
}


Player::~Player()
{
}


SmartPlayer::SmartPlayer() :
m_Health(100), m_Smarts(50), m_Armour(0), m_Money(5000), m_UsedSpace(0),
m_Damage(0), m_Speed(0), m_Backpack(100), m_Debt(5000), m_MaxHealth(100)
{

}
TankyPlayer::TankyPlayer():
m_Health(150), m_Smarts(0), m_Armour(0), m_Money(5000), m_UsedSpace(0),
m_Damage(0), m_Speed(0), m_Backpack(100), m_Debt(5000), m_MaxHealth(150)
{

}
QuickPlayer::QuickPlayer():
m_Health(100), m_Smarts(0), m_Armour(0), m_Money(5000), m_UsedSpace(0),
m_Damage(0), m_Speed(50), m_Backpack(100), m_Debt(5000), m_MaxHealth(100)
{

}
DangerPlayer::DangerPlayer():
m_Health(100), m_Smarts(0), m_Armour(0), m_Money(5000), m_UsedSpace(0),
m_Damage(50), m_Speed(0), m_Backpack(100), m_Debt(5000), m_MaxHealth(100)
{

}

void SmartPlayer::DisplayStats(string name)
{
	cout << "\n\t<--  " << name << "  -->\n"
		<< setw(10) << left << "Class " << setw(15) << "Smart" << "\n"
		<< setw(10) << left << "Health " << setw(15) << m_Health << "\n"
		<< setw(10) << left << "Money " << "$" << m_Money << "\n"
		<< setw(10) << left << "Debt " << "$" << m_Debt << "\n"
		<< setw(10) << left << "Smarts " << setw(15) << m_Smarts << "\n"
		<< setw(10) << left << "Armour " << setw(15) << m_Armour << "\n"
		<< setw(10) << left << "Damage " << setw(15) << m_Damage << "\n"
		<< setw(10) << left << "Speed " << setw(15) << m_Speed << "\n"
		<< setw(10) << left << "Backpack" << m_UsedSpace << " / " << m_Backpack << "\n";
		ShowBackpack();
}
void TankyPlayer::DisplayStats(string name)
{
	cout << "\n\t<--  " << name << "  -->\n"
		<< setw(10) << left << "Class " << setw(15) << "Smart" << "\n"
		<< setw(10) << left << "Health " << setw(15) << m_Health << "\n"
		<< setw(10) << left << "Money " << "$" << m_Money << "\n"
		<< setw(10) << left << "Debt " << "$" << m_Debt << "\n"
		<< setw(10) << left << "Smarts " << setw(15) << m_Smarts << "\n"
		<< setw(10) << left << "Armour " << setw(15) << m_Armour << "\n"
		<< setw(10) << left << "Damage " << setw(15) << m_Damage << "\n"
		<< setw(10) << left << "Speed " << setw(15) << m_Speed << "\n"
		<< setw(10) << left << "Backpack" << m_UsedSpace << " / " << m_Backpack << "\n";
		ShowBackpack();
}
void QuickPlayer::DisplayStats(string name)
{
	cout << "\n\t<--  " << name << "  -->\n"
		<< setw(10) << left << "Class " << setw(15) << "Smart" << "\n"
		<< setw(10) << left << "Health " << setw(15) << m_Health << "\n"
		<< setw(10) << left << "Money " << "$" << m_Money << "\n"
		<< setw(10) << left << "Debt " << "$" << m_Debt << "\n"
		<< setw(10) << left << "Smarts " << setw(15) << m_Smarts << "\n"
		<< setw(10) << left << "Armour " << setw(15) << m_Armour << "\n"
		<< setw(10) << left << "Damage " << setw(15) << m_Damage << "\n"
		<< setw(10) << left << "Speed " << setw(15) << m_Speed << "\n"
		<< setw(10) << left << "Backpack" << m_UsedSpace << " / " << m_Backpack << "\n";
		ShowBackpack();
}
void DangerPlayer::DisplayStats(string name)
{
	cout << "\n\t<--  " << name << "  -->\n"
		<< setw(10) << left << "Class " << setw(15) << "Smart" << "\n"
		<< setw(10) << left << "Health " << setw(15) << m_Health << "\n"
		<< setw(10) << left << "Money " << "$" << m_Money << "\n"
		<< setw(10) << left << "Debt " << "$" << m_Debt << "\n"
		<< setw(10) << left << "Smarts " << setw(15) << m_Smarts << "\n"
		<< setw(10) << left << "Armour " << setw(15) << m_Armour << "\n"
		<< setw(10) << left << "Damage " << setw(15) << m_Damage << "\n"
		<< setw(10) << left << "Speed " << setw(15) << m_Speed << "\n"
		<< setw(10) << left << "Backpack" << m_UsedSpace << " / " << m_Backpack << "\n";
		ShowBackpack();
}


void SmartPlayer::IncreaseDebt()
{
	if (m_Debt > 0)
	{
		m_Debt += (m_Debt * 0.05);
	}
}
void TankyPlayer::IncreaseDebt()
{
	if (m_Debt > 0)
	{
		m_Debt += (m_Debt * 0.05);
	}
}
void QuickPlayer::IncreaseDebt()
{
	if (m_Debt > 0)
	{
		m_Debt += (m_Debt * 0.05);
	}
}
void DangerPlayer::IncreaseDebt()
{
	if (m_Debt > 0)
	{
		m_Debt += (m_Debt * 0.05);
	}
}


void SmartPlayer::ShowBackpack()
{
	vector<pair<string, pair<unsigned, unsigned>>>& backpack = GetSack();
	if (backpack.size() != 0)
	{
		for (vector<pair<string, pair<unsigned, unsigned>>>::iterator it = backpack.begin(); it != backpack.end(); ++it)
		{
			unsigned totalVal = (it->second.first * it->second.second);
			cout << it->second.first << " " << it->first << " Units Bought at $" << it->second.second << " Total value:" << totalVal << endl;
		}
	}
}
void TankyPlayer::ShowBackpack()
{

}
void QuickPlayer::ShowBackpack()
{

}
void DangerPlayer::ShowBackpack()
{

}


void SmartPlayer::Buy(Market& m)
{
	vector<pair<string, unsigned>>& market = m.GetMap();
	cout << "\nWhat are you looking to buy? 'type (number) in'\n";
	int choice = getLegitInt(1, market.size());
	
	if (GetUsedSpace() != GetBackpackSpace())
	{
		cout << "How Many " << m.GetName(choice) << " Units Would you like to buy?  \n" << (GetBackpackSpace() - GetUsedSpace()) << " Backpack Space , (0) to go back.  \n";
		unsigned units = getLegitInt(0, (GetBackpackSpace() - GetUsedSpace()));
		unsigned purchaseVal = (units * m.GetPrice(choice));
		bool bought = false;
		while (!bought && units != 0)
		{
			if (units != 0 && units <= (GetBackpackSpace() - GetUsedSpace()))
			{
				
				while (!bought && units != 0)
				{
					if (purchaseVal <= GetMoney())
					{
						bought = true;
						FillSack(units);
						// pair<string, pair<unsigned, unsigned>>
						m_Product.push_back(make_pair(m.GetName(choice), make_pair(units, m.GetPrice(choice))));
						m_Money -= purchaseVal;
						cout << "\nBought " << units << " " << m.GetName(choice) << " Units .\n";
						system("pause");
						break;
					}
					else
					{
						cout << "\nYou Aint Got $" << purchaseVal << " try again or...(0) to go back fool\n";
						units = getLegitInt(0, (GetBackpackSpace() - GetUsedSpace()));
						purchaseVal = (units * m.GetPrice(choice));
					}
				}
			}
			else if(units > (GetBackpackSpace() - GetUsedSpace()))
			{
				cout << "\nNot enought space..\n";
				system("pause");
			}
		}
	}
	else if (GetUsedSpace() == GetBackpackSpace())
	{
		cout << "\n\n NO SPACE LEFT ! \n";
		system("pause");
	}
}
void SmartPlayer::Sell(Market& m)
{
	vector<pair<string, pair<unsigned, unsigned>>>& backpack = GetSack();
	if (backpack.size() != 0)
	{
		int i = 1;
		vector<pair<string, pair<unsigned, unsigned>>>::iterator it = backpack.begin();
		cout << "\n";
		for (it ; it != backpack.end(); ++it)
		{
			unsigned totalVal = (it->second.first * it->second.second);
			cout << "(" << i << ") " << it->second.first << " " << it->first << " Units Bought at $" << it->second.second << " Total value:" << totalVal << endl;
			++i;
		}
		vector<pair<string, unsigned>>& market = m.GetMap();
		cout << "\nWhat to Sell? 'type (number) in' (0) = Back\n";
		
		int choice = getLegitInt(0, backpack.size());
		while (choice != 0 && backpack.size() != 0)
		{
			bool IsOnMarket = m.MarketCompare(backpack[choice - 1].first);
			if (IsOnMarket)
			{
				EmptySack(backpack[choice - 1].second.first); //Empty
				m_Money += (backpack[choice - 1].second.first * m.MarketPrice(backpack[choice - 1].first));
				cout << "\n Sold " << backpack[choice - 1].second.first 
					 << " " << backpack[choice - 1].first << " at $" 
					 << m.MarketPrice(backpack[choice - 1].first) << endl;

				backpack.erase(backpack.begin()+ choice -1);

				if (backpack.size() != 0) //THIS WILLL FIX WHEN DELETING THE ITEM FROM BACKPACK
				{
					cout << "Sell Another?   (0) Back\n";
					choice = getLegitInt(0, backpack.size());
				}
				else break;
			}
			else
			{
				cout << "\nThats Not on The Market Right Now..\n";
				cout << "Sell Another?   (0) Back\n";
				choice = getLegitInt(0, backpack.size());
			}
		}
	}
	else
	{
		cout << "\nNo Drugz to Sell Dummeh!\n";
	}

}

void TankyPlayer::Buy(Market& m)
{

}
void TankyPlayer::Sell(Market& m)
{

}

void QuickPlayer::Buy(Market& m)
{

}
void QuickPlayer::Sell(Market& m)
{

}

void DangerPlayer::Buy(Market& m)
{

}
void DangerPlayer::Sell(Market& m)
{

}


int getLegitInt(int low, int high)
{
	int ret;
	do
	{
		std::string str;
		std::getline(std::cin, str);
		std::stringstream ss(str);
		ss >> ret;
		if ((ss) && (ret >= low && ret <= high))
		{
			break;
		}
		else
		{
			std::cout << "-<error>--wrong option--choose(" << low << " - " << high << ")--" << std::endl;
			continue;
		}
	} while (true);
	return ret;
};