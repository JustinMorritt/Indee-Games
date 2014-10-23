#include <sstream> 
#include <iostream>
#include <iomanip>
#include <fstream>
#include "DopeWarz.h"
#include "Market.h"



DopeWarz::DopeWarz() : m_BankMoney(0)
{
	LoadUsers();

	//this->GameTitle();					//Display Title
	while (true)
	{
		int choice = MainMenu();			//Get Game Type 
		if (choice == 0){ break; };			//if 0 Quit
		if (choice == 1){ SetNewUser(); }; // HERE i will initiate the Game after the Set new player
		if (choice == 2){ LoadPlayer(); };
		if (choice == 3){ DisplayLeaderBoard(); };
	};
	//cout << " GOODBYE !" << endl;
	GoodBye();
}


DopeWarz::~DopeWarz()
{
}


int DopeWarz::MainMenu()
{
	int choice;
	while (true)
	{
		system("cls");
		GameTitle();
		cout << "\n(1) New Thug\n"
			<< "(2) Load Thug\n"
			<< "(3) LeaderBoards\n"
			<< "(0) Quit\n";

		choice = getLegitInt(0, 3);
			break;
	}
	return choice;
}


void DopeWarz::SetPlayersMap(map<string, pair<double, int>> playerMap)
{
	m_PlayerInfo = playerMap;
}

void DopeWarz::LoadUsers()
{
	ifstream inFile("Players");
	map<string, pair <double , int>> m;
	if (inFile.fail())
	{
		cerr << "Could not open Input File --->. ??\n\n";
		exit(1); // 1 indicates an error occurred
	}
	

	string str;
	while (inFile >> str)
	{
		string ret;
		for (unsigned int j = 0; j < str.length(); j++)
		{
			str[j] = toupper(str[j]);
			if (str[j] >= 'A' && str[j] <= 'Z')
			{
				ret.push_back(str[j]);
			}
		}
		pair<map<string, pair <double, int>>::iterator, bool> check;
		check = m.insert(pair<string, pair <double, int>>(ret,make_pair(10.00, 1)));
		if (check.second == false)
		{
			//check.first->second;
		}
		else
		{
			m.insert(pair<string, pair <double, int>>(ret, make_pair(10.00, 1)));
		}
	}

	SetPlayersMap(m);

}
void DopeWarz::SetNewUser()
{
	system("cls");
	GameTitle();
	cout << "\n\nEnter Your Name Playa:\n";
	string name = getLegitString();
	system("cls");
	GameTitle();
	cout << "\nOk, "<< name <<" What Kind of Thug are you?\n";
	cout << "\n(1) Smart\t (++ money from transactions)\n"
		 << "(2) Tanky \t (++ Health)\n"
	     << "(3) Quick \t (++ chance of running from cops)\n"
	 	 << "(4) Dangeous\t (++ gun damage)\n";
	int Class = getLegitInt(1, 4);
	string strClass;
	
	switch (Class)
	{
	case 1:	strClass = "Smart";	break;
	case 2:	strClass = "Tanky";	break;
	case 3:	strClass = "Quick";	break;
	case 4:	strClass = "Dangerous";	break;
	}
	system("cls");
	GameTitle();
	cout << "\nAlrighty " << name << " you " << strClass << " Motha Fugga,  How Many Days ?\n";
	cout << "\n(1) 20 \t (For the Wimps)\n"
		<< "(2) 40 \t (For The Buisness Men)\n"
		<< "(3) 80 \t (Semi Hardcore)\n"
		<< "(4) 160  (Hardcore Bloodshot Eyes!)\n";
	int Days = getLegitInt(1, 4);

	Play(name, Class, Days); //TAKES ColleCTED DATA PLAYS GAME

}
void DopeWarz::LoadPlayer()
{

}


void DopeWarz::DisplayLeaderBoard() const
{
	system("cls");
	GameTitle();
	cout << "\n\nBIG EXTRAVAGENT LEADERBOARDS ASCII ART";
	cout << "\n(1) 20 Days\n"
		<< "(2) 40 Days\n"
		<< "(3) 80 Days\n"
		<< "(4) 160 Days\n";
	int Days = getLegitInt(1, 4);

	switch (Days)
	{
	case 1:	
		cout << "\n<--Displaying LeaderBoard for 20 Days-->\n";
			break;
	case 2:
		cout << "\n<--Displaying LeaderBoard for 40 Days-->\n";
		break;
	case 3:
		cout << "\n<--Displaying LeaderBoard for 80 Days-->\n";
		break;
	case 4:
		cout << "\n<--Displaying LeaderBoard for 160 Days-->\n";
		break;
	}

}

Player* DopeWarz::SetPlayer(unsigned type) 
{
	switch (type)
	{
	case 1:	 m_Player = new SmartPlayer; break;
	case 2:	 m_Player = new TankyPlayer; break;
	case 3:	 m_Player = new QuickPlayer; break;
	case 4:	 m_Player = new DangerPlayer; break;
	}
	return m_Player;
}



void DopeWarz::Play(string name, unsigned Class, unsigned days)
{
	m_DaysLeft = days;
	switch (days)
	{
	case 1: m_DaysLeft = 20; break;
	case 2: m_DaysLeft = 40; break;
	case 3: m_DaysLeft = 80; break;
	case 4: m_DaysLeft = 160; break;
	}

	string pname = name;
	Player* p = SetPlayer(Class);
	system("cls");
	cout << "\n\nHey There " << name << " Welcome to the streets ! \n";


	bool quit = false;
	bool showedStats = false;
	bool changeLocation = false;
	int Location = 0; 
	while (p->GetHealth() != 0 && m_DaysLeft != 0 && quit == false)
	{
		int choice2 = 2; int choice = 2; int choice3 = 2; int choice4 = 2; int choice5 = 2; int choice6 = 2; int choice7 = 2;
		Market market;
		Market& m = market;
		switch (Location)
		{
//***************************HOME*****************************************************************************************************************
			case 0 :
				while (choice != 0 && choice != 4 && m_DaysLeft != 0 && p->GetHealth() > 0)
				{
					if (!showedStats){m.BuildMarket();}
					m.DisplayMarket();
					changeLocation = false;
					showedStats = false;
				
						cout << "\n\n*********************************************\n"
						<< "*   BackPack: " << p->GetUsedSpace() << "/" << p->GetBackpackSpace() << " "
						<< "    Health: " << p->GetHealth() << " / " << p->GetMaxHealth() << "   \n"
						<< "*   Money: $" << p->GetMoney() << "";
						
					if (p->GetDebt() != 0)
					{
						cout << "  -> Debt: $" << p->GetDebt() << "";
					}
					cout << "  Days: " << m_DaysLeft << "   "
						<< "\n*********************************************\n\n";
					cout << "(1) Buy !\n"
						<< "(2) Sell !\n"
						<< "(3) Show Stats\n"
						<< "(4) Move Location (Current: Home/SafeHouse)\n"
						<< "(0) Save & Quit\n";
					choice = getLegitInt(0, 4);
					switch (choice)
					{
						case 0:	quit = true; break;
						case 1:  p->Buy(m);  DDay(p); system("cls"); break;
						case 2: if (p->GetUsedSpace() == 0)
						{
									system("cls");
									showedStats = true;
									break;
						}
								else
								{
									p->Sell(m); DDay(p); system("cls"); break;
								}
							
						case 3: system("cls"); p->DisplayStats(pname); showedStats = true; break;
						case 4:  Location = MoveLoacation(); system("cls"); changeLocation = true;  DDay(p); break;
					}		
				}
				break;
//***************************LOANSHARK*****************************************************************************************************************
			case 1:
				while (choice2 != 0 && choice2 != 4 && m_DaysLeft != 0 && p->GetHealth() > 0)
				{
					if (!showedStats){ m.BuildMarket(); }
					m.DisplayMarket();
					showedStats = false;
					changeLocation = false;

					cout << "\n\n*********************************************\n"
						<< "*   BackPack: " << p->GetUsedSpace() << "/" << p->GetBackpackSpace() << " "
						<< "    Health: " << p->GetHealth() << " / " << p->GetMaxHealth() << "   \n"
						<< "*   Money: $" << p->GetMoney() << "";

					if (p->GetDebt() != 0)
					{
						cout << "  -> Debt: $" << p->GetDebt() << "";
					}
					cout << "  Days: " << m_DaysLeft << "   "
						<< "\n*********************************************\n\n";
					cout << "(1) Buy !\n"
						<< "(2) Sell !\n"
						<< "(3) Show Stats\n"
						<< "(4) Move Location (Current: Downtown Dundas)\n"
						<< "(5) Loan Shark " << "  (Debt: $" << p->GetDebt() << ")\n"
						<< "(0) Save & Quit\n";
					choice2 = getLegitInt(0, 5);
					switch (choice2)
					{
					case 0:	quit = true; break;
					case 1:  p->Buy(m);  DDay(p); system("cls"); break;
					case 2: if (p->GetUsedSpace() == 0)
					{
								system("cls");
								showedStats = true;
								break;
					}
							else
							{
								p->Sell(m); DDay(p); system("cls"); break;
							}

					case 3:  system("cls"); p->DisplayStats(pname); showedStats = true; break;
					case 4:  Location = MoveLoacation(); system("cls"); changeLocation = true; DDay(p); break;
					case 5: PayLoanShark(p); system("cls"); showedStats = true; break;
					}
				}
				break;
//***************************HOSPITAL*****************************************************************************************************************
			case 2:
				while (choice3 != 0 && choice3 != 4 && m_DaysLeft != 0 && p->GetHealth() > 0)
				{
					if (!showedStats){ m.BuildMarket(); }
					m.DisplayMarket();
					showedStats = false;
					changeLocation = false;

					cout << "\n\n*********************************************\n"
						<< "*   BackPack: " << p->GetUsedSpace() << "/" << p->GetBackpackSpace() << " "
						<< "    Health: " << p->GetHealth() << " / " << p->GetMaxHealth() << "   \n"
						<< "*   Money: $" << p->GetMoney() << "";

					if (p->GetDebt() != 0)
					{
						cout << "  -> Debt: $" << p->GetDebt() << "";
					}
					cout << "  Days: " << m_DaysLeft << "   "
						<< "\n*********************************************\n\n";
					cout << "(1) Buy !\n"
						<< "(2) Sell !\n"
						<< "(3) Show Stats\n"
						<< "(4) Move Location (Current: Wellington St)\n"
						<< "(5) Hospital\n"
						<< "(0) Save & Quit\n";
					choice3 = getLegitInt(0, 5);
					switch (choice3)
					{
					case 0:	quit = true; break;
					case 1:  p->Buy(m);  DDay(p); system("cls"); break;
					case 2: if (p->GetUsedSpace() == 0)
					{
								system("cls");
								showedStats = true;
								break;
					}
							else
							{
								p->Sell(m); DDay(p); system("cls"); break;
							}

					case 3:  system("cls"); p->DisplayStats(pname); showedStats = true; break;
					case 4:  Location = MoveLoacation(); system("cls"); changeLocation = true; DDay(p); break;
					case 5: GoToHospital(p); system("cls"); showedStats = true; break;
					}
				}
				break;
//****************************BANK****************************************************************************************************************
			case 3:
				while (choice4 != 0 && choice4 != 4 && m_DaysLeft != 0 && p->GetHealth() > 0)
				{
					if (!showedStats){ m.BuildMarket(); }
					m.DisplayMarket();
					showedStats = false;
					changeLocation = false;

					cout << "\n\n*********************************************\n"
						<< "*   BackPack: " << p->GetUsedSpace() << "/" << p->GetBackpackSpace() << " "
						<< "    Health: " << p->GetHealth() << " / " << p->GetMaxHealth() << "   \n"
						<< "*   Money: $" << p->GetMoney() << "";

					if (p->GetDebt() != 0)
					{
						cout << "  -> Debt: $" << p->GetDebt() << "";
					}
					cout << "  Days: " << m_DaysLeft << "   "
						<< "\n*********************************************\n\n";
					cout << "(1) Buy !\n"
						<< "(2) Sell !\n"
						<< "(3) Show Stats\n"
						<< "(4) Move Location (Current: Richmond Row)\n"
						<< "(5) Bank\n"
						<< "(0) Save & Quit\n";
					choice4 = getLegitInt(0, 5);
					switch (choice4)
					{
					case 0:	quit = true; break;
					case 1:  p->Buy(m);  DDay(p); system("cls"); break;
					case 2: if (p->GetUsedSpace() == 0)
					{
								system("cls");
								showedStats = true;
								break;
					}
							else
							{
								p->Sell(m); DDay(p); system("cls"); break;
							}

					case 3:  system("cls"); p->DisplayStats(pname); showedStats = true; break;
					case 4:  Location = MoveLoacation(); system("cls"); changeLocation = true; DDay(p); break;
					case 5: UseBank(p); system("cls"); showedStats = true; break;
					}
				}
				break;
//****************************GUNTRADER****************************************************************************************************************
			case 4:
				while (choice5 != 0 && choice5 != 4 && m_DaysLeft != 0 && p->GetHealth() > 0)
				{
					if (!showedStats){ m.BuildMarket(); }
					m.DisplayMarket();
					showedStats = false;
					changeLocation = false;

					cout << "\n\n*********************************************\n"
						<< "*   BackPack: " << p->GetUsedSpace() << "/" << p->GetBackpackSpace() << " "
						<< "    Health: " << p->GetHealth() << " / " << p->GetMaxHealth() << "   \n"
						<< "*   Money: $" << p->GetMoney() << "";

					if (p->GetDebt() != 0)
					{
						cout << "  -> Debt: $" << p->GetDebt() << "";
					}
					cout << "  Days: " << m_DaysLeft << "   "
						<< "\n*********************************************\n\n";
					cout << "(1) Buy !\n"
						<< "(2) Sell !\n"
						<< "(3) Show Stats\n"
						<< "(4) Move Location (Current: White Oaks Parking Lot)\n"
						<< "(5) Gun Trader\n"
						<< "(0) Save & Quit\n";
					choice5 = getLegitInt(0, 5);
					switch (choice5)
					{
					case 0:	quit = true; break;
					case 1:  p->Buy(m);  DDay(p); system("cls"); break;
					case 2: if (p->GetUsedSpace() == 0)
					{
								system("cls");
								showedStats = true;
								break;
					}
							else
							{
								p->Sell(m); DDay(p); system("cls"); break;
							}

					case 3:  system("cls"); p->DisplayStats(pname); showedStats = true; break;
					case 4:  Location = MoveLoacation(); system("cls"); changeLocation = true; DDay(p); break;
					}
				}
				break;
//****************************LIBRARY****************************************************************************************************************
			case 5:
while (choice6 != 0 && choice6 != 4 && m_DaysLeft != 0 && p->GetHealth() > 0)
				{
					if (!showedStats){ m.BuildMarket(); }
					m.DisplayMarket();
					showedStats = false;
					changeLocation = false;

					cout << "\n\n*********************************************\n"
						<< "*   BackPack: " << p->GetUsedSpace() << "/" << p->GetBackpackSpace() << " "
						<< "    Health: " << p->GetHealth() << " / " << p->GetMaxHealth() << "   \n"
						<< "*   Money: $" << p->GetMoney() << "";

					if (p->GetDebt() != 0)
					{
						cout << "  -> Debt: $" << p->GetDebt() << "";
					}
					cout << "  Days: " << m_DaysLeft << "   "
						<< "\n*********************************************\n\n";
					cout << "(1) Buy !\n"
						<< "(2) Sell !\n"
						<< "(3) Show Stats\n"
						<< "(4) Move Location (Current: Library)\n"
						<< "(5) Improve Stats\n"
						<< "(0) Save & Quit\n";
					choice6 = getLegitInt(0, 5);
					switch (choice6)
					{
					case 0:	quit = true; break;
					case 1:  p->Buy(m);  DDay(p); system("cls"); break;
					case 2: if (p->GetUsedSpace() == 0)
					{
								system("cls");
								showedStats = true;
								break;
					}
							else
							{
								p->Sell(m); DDay(p); system("cls"); break;
							}

					case 3:  system("cls"); p->DisplayStats(pname); showedStats = true; break;
					case 4:  Location = MoveLoacation(); system("cls"); changeLocation = true; DDay(p); break;
					}
				}
				break;
//****************************GYM****************************************************************************************************************
			case 6:
	while (choice7 != 0 && choice7 != 4 && m_DaysLeft != 0 && p->GetHealth() > 0)
				{
					if (!showedStats){ m.BuildMarket(); }
					m.DisplayMarket();
					showedStats = false;
					changeLocation = false;

					cout << "\n\n*********************************************\n"
						<< "*   BackPack: " << p->GetUsedSpace() << "/" << p->GetBackpackSpace() << " "
						<< "    Health: " << p->GetHealth() << " / " << p->GetMaxHealth() << "   \n"
						<< "*   Money: $" << p->GetMoney() << "";

					if (p->GetDebt() != 0)
					{
						cout << "  -> Debt: $" << p->GetDebt() << "";
					}
					cout << "  Days: " << m_DaysLeft << "   "
						<< "\n*********************************************\n\n";
					cout << "(1) Buy !\n"
						<< "(2) Sell !\n"
						<< "(3) Show Stats\n"
						<< "(4) Move Location (Current: GoodLife)\n"
						<< "(5) Hit the Gym!  (Get Ripped)\n"
						<< "(0) Save & Quit\n";
					choice7 = getLegitInt(0, 5);
					switch (choice7)
					{
					case 0:	quit = true; break;
					case 1:  p->Buy(m);  DDay(p); system("cls"); break;
					case 2: if (p->GetUsedSpace() == 0)
					{
								system("cls");
								showedStats = true;
								break;
					}
							else
							{
								p->Sell(m); DDay(p); system("cls"); break;
							}

					case 3:  system("cls"); p->DisplayStats(pname); showedStats = true; break;
					case 4:  Location = MoveLoacation(); system("cls"); changeLocation = true; DDay(p); break;
					}
				}
				break;
//********************************************************************************************************************************************
		}
	}
}


int DopeWarz::getLegitInt(int low, int high) const
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

string DopeWarz::getLegitString() const
{
	string ret;
	do
	{
		std::string str;
		std::getline(std::cin, str);
		std::stringstream ss(str);
		ss >> ret;
		if ((ss))
		{
			break;
		}
	} while (true);
	return ret;
}


int DopeWarz::MoveLoacation() const
{
	int choice;
	cout << "(1) Downtown Dundas		(LoanShark) \n"
		 << "(2) Wellington St		(Hospital)\n"
		 << "(3) Richmond Row		(Bank)\n"
		 << "(4) White Oaks Parking Lot	(Gun Trader) \n"
		 << "(5) Library			(Improve Stats)\n"
		 << "(6) GoodLife			(Get Buffer)\n"
		 << "(0) Go home			(Safe House)\n";
	choice = getLegitInt(0, 6);
	return choice;
}

void DopeWarz::PayLoanShark(Player * p)
{
	int choice;
	cout << "\nWhat u Gone do?\n"
		<< "(1) Pay Loan\n"
		<< "(2) Take Loan\n"
		<< "(3) Leave\n";
		choice = getLegitInt(1, 3);
		switch (choice)
		{
		case 1:
			if (p->GetDebt() == 0)
			{
				cout << "\nYou aint got a Loan!\n";
				system("pause");
				break;
			}
			if (p->GetDebt() > p->GetMoney())
			{
				cout << "\nYou aint got " << p->GetDebt() << " Moron! Get outtta Here!\n";
				system("pause");
			}
			else
			{
				cout << "\nThanks , you can keep your dog and your legs!\n";
				int ret = p->GetMoney();
				ret -= p->GetDebt();
				p->SetDebt(0);
				p->SetMoney(ret);
				system("pause");
			}
			
			break;
		case 2: 
			if (p->GetDebt() == 0)
			{
				cout << "\nYou Wanna Take a Loan Eh??\n"
					<< "(1) Yes ($20 000 Max)\n"
					<< "(2) Leave\n";
				int choice = getLegitInt(1,2);
				if (choice == 1)
				{
					cout << "\nHow Much? (no spaces)\n";
					int choice2 = getLegitInt(1, 20000);
					p->SetDebt(choice2);
					cout << "\nEnjoy The $\n" << choice2 << " ,Pay back soon or youll regret it! \n";
					system("pause");
					break;
				}
				else
				{
					break;
				}
		
			}
			else
			{
				cout << "\nYou Already Have a loan ..Pay me back first Foo!\n";
				system("pause");
				break;
			}
			
			
			break;
		case 3: break;
		}

}

void DopeWarz::GoToHospital(Player * p)
{
	//heal rate ....    20 / HP 20 * 100 =  2 Grand for full HP
	int choice;
	cout << "\nWelcome to the hospital!\n"
		<< "(1) Heal Up!\n"
		<< "(2) Leave\n";
	choice = getLegitInt(1, 2);
	switch (choice)
	{
	case 1:
		if (p->GetHealth() == p->GetMaxHealth())
		{
			cout << "\nYou Already Have full health !\n";
			system("pause");
			break;
		}
		else
		{
			int hpHealed = (p->GetMaxHealth() - p->GetHealth());
			unsigned cost = (hpHealed * 20);
			unsigned money = p->GetMoney();
			if((money - cost) < 0)
			{
				cout << "\nNot Enough Money...we arnt touching you ! \n"
					<< "Come back when you have $" << cost << " atleast! cheapskate!\n";
				system("pause");
				break;
			}
			else
			{
			unsigned totalcost = (money - cost);
			p->SetMoney(totalcost);
			p->SetHealth(p->GetMaxHealth());
			cout << "\nHealed you for " << hpHealed << " , costing you $" << cost << ". \n";
			system("pause");
			break;
			}
	
		}
		break;
	case 2: break;
	}




}

void DopeWarz::UseBank(Player * p)
{
	int choice;
	cout << "\nWelcome to the bank!\n"
		<< "(1) Deposit\n"
		<< "(2) Withdrawl\n"
		<< "(3) Leave\n";
	choice = getLegitInt(1, 3);
	switch (choice)
	{
	case 1: 
		if (p->GetMoney() == 0)
		{
			cout << "\nNo Money!\n";
			system("pause");
			break;
		}
		else
		{
			cout << "\nHow Much?\n";
			unsigned money = getLegitInt(1, p->GetMoney());
			unsigned bank = GetBank();
			unsigned ret = (money + bank);
			unsigned pmoney = p->GetMoney();
			unsigned pret = (pmoney - money);
			p->SetMoney(pret);
			SetBank(ret);
			cout << "\nDeposited $" << money << "\n";
			system("pause");
			break;
		}
		break;
	case 2:
		if (GetBank() == 0)
		{
			cout << "\nNothing in your Bank Stupid!\n";
			system("pause");
			break;
		}
		else
		{
			cout << "\nHow Much you want? (Currently $" << GetBank() << " )\n";
			unsigned money = getLegitInt(1, GetBank());
			unsigned bank = GetBank();
			unsigned ret = (bank - money);
			unsigned pmoney = p->GetMoney();
			unsigned pret = (pmoney + money);
			p->SetMoney(pret);
			SetBank(ret);
			cout << "\nWithdrew $" << money << "\n";
			system("pause");
			break;
		}
		
		
		break;
	case 3: break;
	}
}


void DopeWarz::GameTitle() const
{
	cout << " \n"
		<< "'||''|.                          '|| '||'  '|'                        \n"
		<< " ||   ||    ...  ... ...    ....  '|. '|.  .' ....  ... .. ...... \n"
		<< " ||    || .|  '|. ||'  || .|...||  ||  ||  | '' .||  ||' ' '  .|' \n"
		<< " ||    || ||   || ||    | ||        ||| |||  .|' ||  ||     .|'   \n"
		<< ".||...|'   '|..|' ||...'   '|...'    |   |   '|..'|'.||.   ||....|\n"
		<< "                  ||                                                \n"
		<< "                 ''''         \n";
}
void DopeWarz::GoodBye() const
{
	cout << " \n"
		<< "'||''|.                                     .|.\n"
		<< " ||   ||   ....   ....     ....    ....     |||\n"
		<< " ||...|' .|...|| '' .||  .|   '' .|...||    '|'\n"
		<< " ||      ||      .|' ||  ||      ||          | \n"
		<< ".||.      '|...' '|..'|'  '|...'  '|...'     . \n"
		<< "                                            '|'\n";
}