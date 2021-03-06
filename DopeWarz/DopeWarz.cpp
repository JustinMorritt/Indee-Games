﻿#include <sstream> 
#include <iostream>
#include <iomanip>
#include <fstream>
#include <utility>
#include "DopeWarz.h"
#include "Market.h"
#include "randgen.h"


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
		RandGen rNg;
		unsigned j = (rNg(10) + 1);
		if (j == 1 || j == 8)//INSERT RANDOM POLICE ENCOUNTER
		{
			PoliceEncounter(p);
		}
		if (j == 9 || j == 3)//INSERT RANDOM LOAN SHARK ENCOUNTER (IF dEBT != 0)
		{
			if (p->GetDebt() != 0)
			{
				LoanSharkEncounter(p);
			}
		}
		if (p->GetHealth() <= 0)//check HP
		{
			break;
		}
		
		
		
		
		
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
						<< "(3) Show Stats/(Gunz & Drugz)\n"
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
							
						case 3:  p->DisplayStats(pname); system("pause"); system("cls"); showedStats = true; break;
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
						<< "(3) Show Stats/(Gunz & Drugz)\n"
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

					case 3:  p->DisplayStats(pname); system("pause"); system("cls"); showedStats = true; break;
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
						<< "(3) Show Stats/(Gunz & Drugz)\n"
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

					case 3:  p->DisplayStats(pname); system("pause"); system("cls"); showedStats = true; break;
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
						<< "(3) Show Stats/(Gunz & Drugz)\n"
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

					case 3:  p->DisplayStats(pname); system("pause"); system("cls"); showedStats = true; break;
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
						<< "(3) Show Stats/(Gunz & Drugz)\n"
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

					case 3:  p->DisplayStats(pname); system("pause"); system("cls"); showedStats = true; break;
					case 4:  Location = MoveLoacation(); system("cls"); changeLocation = true; DDay(p); break;
					case 5: BuyGuns(p); system("cls"); showedStats = true; break;
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
						<< "(3) Show Stats/(Gunz & Drugz)\n"
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

					case 3:  p->DisplayStats(pname); system("pause"); system("cls"); showedStats = true; break;
					case 4:  Location = MoveLoacation(); system("cls"); changeLocation = true; DDay(p); break;
					case 5: UseLibrary(p); system("cls"); DDay(p); break;
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
						<< "(3) Show Stats/(Gunz & Drugz)\n"
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

					case 3:  p->DisplayStats(pname); system("pause"); system("cls"); showedStats = true; break;
					case 4:  Location = MoveLoacation(); system("cls"); changeLocation = true; DDay(p); break;
					case 5: UseGym(p); system("cls"); DDay(p); break;
					}
				}
				break;
//********************************************************************************************************************************************
		}
	}
}



void DopeWarz::PoliceEncounter(Player * p)
{
	RandGen rNg;
	unsigned policehp = (rNg(150) + 100);
	unsigned popohpleft = policehp;
	unsigned baserunaway = 2;
	
	bool ranAway = false;
	while (p->GetHealth() > 0 && popohpleft > 0 && !ranAway)
	{
		unsigned getaway = (rNg(10) + 1);
		unsigned copFire = (rNg(10) + 1);
		unsigned youFire = (rNg(10) + 1);
		unsigned copDmg = (rNg(20) + 1);
		system("cls");
		cout << "***********POLICE ENCOUNTER !*************\n"
			<< "            \n "
			<< "                       ________________   \n"
			<< "                       '      __      /         __\n"
			<< "                        '_____()_____/         /  )\n"
			<< "                        '============`        /  /\n"
			<< "                         #---`  `---#        /  /\n"
			<< "                        (# @`| |`@ #)       /  /\n"
			<< "                         |   (_)   /       /  /\n"
			<< "                         |, '---` /|      /  /\n"
			<< "                 _______/ `,_____// '____/ o_|\n"
			<< "                /       '  /     '  /   / o_|\n"
			<< "               / |           o|        / o_| ;\n"
			<< "              /  |  _____     |       / /   , ;\n"
			<< "             /   |  |===|    o|      / /,    , ;\n"
			<< "            |    |   '@/      |     / /  ,    , ;\n"
			<< "            |    |___________o|__/----)   ,    `/\n"
			<< "            |    '              ||  --)    ,     |\n"
			<< "            |___________________||  --)   __,    /\n"
			<< "                 |           o|   ''''   |   ,__/\n"
			<< "                 |            |          |\n"
			<< "*************************************************\n"
			<< "\tPOLICE HP : " << popohpleft << "/" <<  policehp << " \n"
			<< "\tYOUR HP : " << p->GetHealth() << "/" << p->GetMaxHealth() << " \n"
			<< "*************************************************\n"
			<< "What to Do ?\n"
			<< "(1) Run\n"
			<< "(2) Shoot\n";
			int choice = getLegitInt(1, 2);
			switch (choice)
			{
			case 1: 
				
				if(p->GetSpeed() > 0)
				{
					baserunaway = 5;
				}
			
				if (getaway <= baserunaway)
				{
					ranAway = true;
					break;
				}
				else
				{
					if (copFire > 5)
					{
						cout << "\n Cop Fires At you ! He hit you for " << copDmg << " damage !\n";
						p->TakeDamage(copDmg);
						system("pause");
					}
					else
					{
						cout << "\n Cop Fires At you ! He missed .... phew\n";
						system("pause");
					}
				}

				break;
			case 2: 

				if (youFire > 5)
				{
					if (copFire > 5)
					{
						cout << "\n Cop Fires At you ! He hit you for " << copDmg << " damage !\n";
						p->TakeDamage(copDmg);
						system("pause");
					}
					else
					{
						cout << "\n Cop Fires At you ! He missed .... phew\n";
						system("pause");
					}
				}
				break;
			}

		if (ranAway)
		{
			cout << "\n You Ran Away !  probably because of those 'Jays on your feet'!\n";
			system("pause");
			system("cls");
			break;
		}
	}
}

void DopeWarz::LoanSharkEncounter(Player * p)
{
	RandGen rNg;
	unsigned LShp = (rNg(150) + 100);
	unsigned LShpleft = LShp;
	unsigned baserunaway = 2;

	bool ranAway = false;
	while (p->GetHealth() > 0 && LShpleft > 0 && !ranAway)
	{
		unsigned getaway = (rNg(10) + 1);
		unsigned copFire = (rNg(10) + 1);
		unsigned youFire = (rNg(10) + 1);
		unsigned LSDmg = (rNg(20) + 1);
		system("cls");
		cout << "***********LOANSHARK ENCOUNTER !*************\n"
			<< "            \n "
			   << "                               /^;/^;	\n"
			   << "                              `---- |    \n"
			   << "                          _---'---~~~~-_\n"
			   << "                          ~~~|~~L~|~~~~\n"
			   << "                            (/_  /~~--\n"
			   << "                          `~ `  /  /~\n"
			   << "                        __~`  ~ /   ~~----,\n"
			   << "                        `    | |       /  `\n"
               << "						   `|   |/       |    |\n"
			   << "                        | | | o  o     /~   |\n"
			   << "                      _-~_  |        ||  `  /\n"
			   << "                     (// )) | o  o    ``---'\n"
			   << "                     //_- |  |          `\n"
			   << "                    //   |____|`______`__`\n"
			   << "                    ~      |   / |    |\n"
			   << "                            |_ /   ` _|\n"
			   << "                          /~___|  /____` \n"
			<< "*************************************************\n"
			<< "\tLOANSHARK HP : " << LShpleft << "/" << LShp << " \n"
			<< "\tYOUR HP : " << p->GetHealth() << "/" << p->GetMaxHealth() << " \n"
			<< "*************************************************\n"
			<< "What to Do ?\n"
			<< "(1) Run\n"
			<< "(2) Shoot\n";
		int choice = getLegitInt(1, 2);
		switch (choice)
		{
		case 1:

			if (p->GetSpeed() > 0)
			{
				baserunaway = 5;
			}

			if (getaway <= baserunaway)
			{
				ranAway = true;
				break;
			}
			else
			{
				if (copFire > 5)
				{
					cout << "\n Loanshark Fires At you ! He hit you for " << LSDmg << " damage !\n";
					p->TakeDamage(LSDmg);
					system("pause");
				}
				else
				{
					cout << "\n Loanshark Fires At you ! He missed .... phew\n";
					system("pause");
				}
			}

			break;
		case 2:

			if (youFire > 5)
			{
				if (copFire > 5)
				{
					cout << "\n Loanshark Fires At you ! He hit you for " << LSDmg << " damage !\n";
					p->TakeDamage(LSDmg);
					system("pause");
				}
				else
				{
					cout << "\n Loanshark Fires At you ! He missed .... phew\n";
					system("pause");
				}
			}
			break;
		}

		if (ranAway)
		{
			cout << "\n You Ran Away !  probably because of those 'Jays on your feet'!\n";
			system("pause");
			system("cls");
			break;
		}
	}
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
					unsigned pMoney = p->GetMoney();
					p->SetMoney(pMoney + choice2);
					p->SetDebt(choice2);
					cout << "\nEnjoy The $" << choice2 << " ,Pay back soon or youll regret it! \n";
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
	int hpHealed = (p->GetMaxHealth() - p->GetHealth());
	unsigned cost = (hpHealed * 20);
	unsigned money = p->GetMoney();
	int choice;
	cout << "\nWelcome to the hospital!\n"
		<< "(1) Heal Up! ($" << cost << ")\n"
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
			if((cost > money))
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
	unsigned inBank = GetBank();
	cout << "\nWelcome to the bank!\n"
		<< "(1) Deposit\n"
		<< "(2) Withdrawl ($" << inBank << ")\n"
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
			unsigned money = getLegitInt(0, p->GetMoney());
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
			cout << "\nHow Much you want? (Currently $" << GetBank() << ")\n";
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

void DopeWarz::BuyGuns(Player * p)
{
	int choice, choice2;
	cout << "\nLooking to buy a gun eh?!\n"
		<< "(1) Buy\n"
		<< "(2) Leave\n";
	choice = getLegitInt(1, 2);
	switch (choice)
	{
	case 1:
		if (p->GetMoney() < 500)
		{
			cout << "\nYou are too poor to even look at guns, \n get outta here ya bum! (atleast 500$ to ur name)\n";
			system("pause");
			break;
		}
		else
		{
			cout << "\nWhat Type?!\n"
				<< "(1) Pistols ($500 - $1000)\n"
				<< "(2) Machine Guns ($1250 - $3000)\n"
				<< "(3) Snipers ($3500 - $5000)\n";
			choice2 = getLegitInt(1, 3);

			switch (choice2)
			{
			case 1: 
				while (true)
				{
//***************************************************************************************************************************
					system("cls");
					cout << "\n\t PISTOL 1 !\n\n"
						"  |^`                      _________________/`|_\n"
						" |~~~|--------------~~~~~~~~~~~~~~~~,xx.~~~~~~~~| \n"
						" |___|-------++++==|___|~~~~~|_____(x@x),;'//  || \n"
						"                   |~~~||    |~~~~~~~~~~~ //   || \n"
						"                    ~`(_(=)~~ ,-~-;       ;  __/  \n"
						"                       ~~~~~\[  ; ]`       ;/     \n"
						"                             `:  |'()       `    \n"
						"                               ~~~~` `       `   \n"
						"                                    ` `       `   \n"
						"                                     ` `       `   \n"
						"                                      ` `       `   \n"
						"                                       ` `       ||   \n"
						"                                        | `       ||  \n"
						"                                        |  `_  ___|| \n"
						"                                        '____( )-=~  \n";

					cout << "\nBuy This?!\n"
						<< "(1) Yes ($500)\n"
						<< "(2) Next! \n"
						<< "(3) Leave \n";
					choice = getLegitInt(1, 3);
					if (choice == 3){ break; }
					if (choice == 1)
					{
						unsigned money = p->GetMoney();
						if (money >= 500)
						{
							unsigned ret = (money - 500);
							p->SetMoney(ret);
							pair<string, pair<unsigned, unsigned>> gun = make_pair("Luger", make_pair(1, 25));
							p->AddGun(gun);
							cout << "\nThanks for Buying The Luger \n";
							system("pause");
							break;
						}
						else
						{
							cout << "\nNot Enought Money!\n";
							system("pause");
							break;
						}
					}
//***************************************************************************************************************************
					system("cls");
					cout << "\n\t PISTOL 2 !\n\n"

						" .-""------------------------------------^--._\n"
						" |      |   BROWNING Mod. GPDA8   \|\|\|\|     |/)\n"
						" |------|______________/''\________\|\|\|\|__  |/\n"
						" |_______\             `-----------'    //__)|\n"
						"          ''''''''''\  /'''\ ('''\ ''''..     /\n"
						"                     ((    ))    )      ''. /\n"
						"                      \\   //    / ..       |\n"
						"                       ``=======(()::::..   L\n"
						"                                 T `::::::  T\n"
						"                                  L :::::::. L\n"
						"                                  T `:::::::.T\n"
						"                                   L :::::::::L\n"
						"                                   T `::::::::T\n"
						"                                    L :::::::::L\n"
						"                                    T `::::KSR:T\n"
						"                                    =========---\n";

					cout << "\nBuy This?!\n"
						<< "(1) Yes ($650)\n"
						<< "(2) Next! \n"
						<< "(3) Leave \n";
					choice = getLegitInt(1, 3);
					if (choice == 3){ break; }
					if (choice == 1)
					{
						unsigned money = p->GetMoney();
						if (money >= 650)
						{
							unsigned ret = (money - 650);
							p->SetMoney(ret);
							pair<string, pair<unsigned, unsigned>> gun = make_pair("USP", make_pair(1, 30));
							p->AddGun(gun);
							cout << "\nThanks for Buying The USP \n";
							system("pause");
							break;
						}
						else
						{
							cout << "\nNot Enought Money!\n";
							system("pause");
							break;
						}
			
					}
//***************************************************************************************************************************
					system("cls");
					cout << "\n\t PISTOL 3 !\n\n"

						"  ,--^----------,--------,-----,-------^--,\n"
						"  | |||||||||   `--------'     |          O\n"
						"  `+---------------------------^----------|\n"
						"    `\_,-------, _________________________|\n"
						"      / XXXXXX /`|     /\n"
						"     / XXXXXX /  `\   /\n"
						"    / XXXXXX /\______(\n"
						"   / XXXXXX /\n"
						"  / XXXXXX /\n"
						" (________(\n"
						"  `------' \n";

					cout << "\nBuy This?!\n"
						<< "(1) Yes ($750)\n"
						<< "(2) Next! \n"
						<< "(3) Leave \n";
					choice = getLegitInt(1, 3);
					if (choice == 3){ break; }
					if (choice == 1)
					{
						unsigned money = p->GetMoney();
						if (money >= 750)
						{
							unsigned ret = (money - 750);
							p->SetMoney(ret);
							pair<string, pair<unsigned, unsigned>> gun = make_pair("Glock", make_pair(1, 35));
							p->AddGun(gun);
							cout << "\nThanks for Buying The Glock \n";
							system("pause");
							break;
						}
						else
						{
							cout << "\nNot Enought Money!\n";
							system("pause");
							break;
						}
					}
//***************************************************************************************************************************
					system("cls");
					cout << "\n\t PISTOL 4 !\n\n"

				     	"           ,___________________________________________/|_ \n"
						"           |-_______------. `\                             |\n"
						"       _,/ | _______)     |___\____________________________|\n"
						"  .__/`((  | _______      | (/))_______________=.\n"
						"      `~) \ | _______)     |   /----------------_/\n"
						"       `__y|______________|  /\n"
						"       / ________ __________/\n"
						"      / /#####\(  \  /     ))\n"
						"     / /#######|\  \(     //\n"
						"    / /########|.\_______/`\n"
						"   / /###(\)###||`------``\n"
						"  / /##########||\n"
						" / /###########||\n"
						"( (############||\n"
						" \ '####(/)####))\n"
						"  \ '#########//\n"
						"   \ '#######//\n"
						"    `---|_|--`\n"
						"       ((_))\n"
						"        `-`\n";


					cout << "\nBuy This?!\n"
						<< "(1) Yes ($800)\n"
						<< "(2) Next! \n"
						<< "(3) Leave \n";
					choice = getLegitInt(1, 3);
					if (choice == 3){ break; }
					if (choice == 1)
					{
						unsigned money = p->GetMoney();
						if (money >= 800)
						{
							unsigned ret = (money - 800);
							p->SetMoney(ret);
							pair<string, pair<unsigned, unsigned>> gun = make_pair("Six Shooter", make_pair(1, 35));
							p->AddGun(gun);
							cout << "\nThanks for Buying The Six Shooter!\n";
							system("pause");
							break;
						}
						else
						{
							cout << "\nNot Enought Money!\n";
							system("pause");
							break;
						}
					}
//***************************************************************************************************************************
					system("cls");
					cout << "\n\t PISTOL 5 !\n\n"

						"  _ ____________.---------.    \n"
						"  \`'  __________|_________|   \n"
						"  /   (_)__]                    \n"
						" |    |                       \n"
						".'   .'                         \n"
						"|____]   \n";

					cout << "\nBuy This?!\n"
						<< "(1) Yes ($900)\n"
						<< "(2) Next! \n"
						<< "(3) Leave \n";
					choice = getLegitInt(1, 3);
					if (choice == 3){ break; }
					if (choice == 1)
					{
						unsigned money = p->GetMoney();
						if (money >= 900)
						{
							unsigned ret = (money - 900);
							p->SetMoney(ret);
							pair<string, pair<unsigned, unsigned>> gun = make_pair("Silenced PP7", make_pair(1, 40));
							p->AddGun(gun);
							cout << "\nThanks for Buying Silenced PP7 \n";
							system("pause");
							break;
						}
						else
						{
							cout << "\nNot Enought Money!\n";
							system("pause");
							break;
						}
					}
//***************************************************************************************************************************
					system("cls");
					cout << "\n\t PISTOL 6 !\n\n"

						"     ___)|____________________________________/|_\n"
						"    (/    )))))                                   `,\n"
						"     /   (((((                                      )\n"
						"    (______________________________________________/\n"
						"     \   ________ ______________________________/\n"
						"      ) /#######/ )', /     )/\n"
						"     / /##(')##/ /  |(     /\n"
						"    / /#######( (\______._/`\n"
						"   / /#########) )------``\n"
						"  / /#########/ /\n"
						" / /###(/)###/ /\n"
						"( (#########/ (\n"
						" \____/-------\)\n"
						"      |    |_)|\n"
						"      |    |_)|\n"
						"     ,|_______|\n";

					cout << "\nBuy This?!\n"
						<< "(1) Yes ($1000)\n"
						<< "(2) Next! \n"
						<< "(3) Leave \n";
					choice = getLegitInt(1, 3);
					if (choice == 3){ break; }
					if (choice == 1)
					{
						unsigned money = p->GetMoney();
						if (money >= 1000)
						{
							unsigned ret = (money - 1000);
							p->SetMoney(ret);
							pair<string, pair<unsigned, unsigned>> gun = make_pair("Desert Eagle", make_pair(1, 50));
							p->AddGun(gun);
							cout << "\nThanks for Buying The Desert Eagle! \n";
							system("pause");
							break;
						}
						else
						{
							cout << "\nNot Enought Money!\n";
							system("pause");
							break;
						}
					}
//***************************************************************************************************************************
				} // <---While loop end..
				break;

			case 2:
				while (true)
				{
//***************************************************************************************************************************
					system("cls");
					cout << "\n\t MachineGuns1 !\n\n"

						"  ||\n"
						"  ||_________________________/'|\n"
						" _| O======/                   |\n"
						"|_|              ============  |\n"
						"  |  __  ______________________|\n"
						"  |_/  )(     |___||     O-   /\n"
						"      (  )    /  / |_________/\n"
						"      (  )   /  /    | ) |   |\n"
						"      (__)  /  /     '___|__(\n"
						"           /  / BigFoot  )   '\n"
						"          /  /            )   '\n"
						"         /  /              )___'\n"
						"        /  /\n"
						"       /__/\n";

					cout << "\nBuy This?!\n"
						<< "(1) Yes ($1250)\n"
						<< "(2) Next! \n"
						<< "(3) Leave \n";
					choice = getLegitInt(1, 3);
					if (choice == 3){ break; }
					if (choice == 1)
					{
						unsigned money = p->GetMoney();
						if (money >= 1250)
						{
							unsigned ret = (money - 1250);
							p->SetMoney(ret);
							pair<string, pair<unsigned, unsigned>> gun = make_pair("MP5", make_pair(1, 60));
							p->AddGun(gun);
							cout << "\nThanks for Buying The MP5! \n";
							system("pause");
							break;
						}
						else
						{
							cout << "\nNot Enought Money!\n";
							system("pause");
							break;
						}
					}
//***************************************************************************************************************************
					system("cls");
					cout << "\n\t MachineGuns2 !\n\n"

						"                     ,1             ,-===========.\n"
						"                    /,| ___________((____________\\__\n"
						" ,========.________//_|/===========._#############L_Y_....-----====//\n"
						"(#######(==========\################\=======.______ --############((\n"
						" `=======`          '==============| ::::.___| [))[JM]#############'\n"
						"                                    |####|     ""'###|   :##########'\n"
						"                                   /####/         '##'  ```'' =, ,))\n"
						"                                  /####/           '##'\n"
						"                                 '===='             `=`\n";

					cout << "\nBuy This?!\n"
						<< "(1) Yes ($1500)\n"
						<< "(2) Next! \n"
						<< "(3) Leave \n";
					choice = getLegitInt(1, 3);
					if (choice == 3){ break; }
					if (choice == 1)
					{
						unsigned money = p->GetMoney();
						if (money >= 1500)
						{
							unsigned ret = (money - 1500);
							p->SetMoney(ret);
							pair<string, pair<unsigned, unsigned>> gun = make_pair("M4A1", make_pair(1, 70));
							p->AddGun(gun);
							cout << "\nThanks for Buying M4A1!\n";
							system("pause");
							break;
						}
						else
						{
							cout << "\nNot Enought Money!\n";
							system("pause");
							break;
						}
					}
//***************************************************************************************************************************
					system("cls");
					cout << "\n\t MachineGuns3 !\n\n"

						"                      ,--------------,\n"
						"                      L.,------, ,--'\n"
						"                ______'(______( (________,------==========.\n"
						"    (###========,_________--===-----=======================|\n"
						"                 ,',,,,,' ,-+-_   __,___,____,____,____,___|\n"
						"                 |=|     ' ' )_) (  )__,____,____,____,____|\n"
						"                 |=|      ' '  | |    )====)     `:__      |\n"
						"                 |__'      ' '_) |   ,====,          '     |\n"
						"                            `----'  ,====,            '[JM]|\n"
						"                                    `-._,             :____|\n";

					cout << "\nBuy This?!\n"
						<< "(1) Yes ($1750)\n"
						<< "(2) Next! \n"
						<< "(3) Leave \n";
					choice = getLegitInt(1, 3);
					if (choice == 3){ break; }
					if (choice == 1)
					{
						unsigned money = p->GetMoney();
						if (money >= 1750)
						{
							unsigned ret = (money - 1750);
							p->SetMoney(ret);
							pair<string, pair<unsigned, unsigned>> gun = make_pair("Steyr Aug", make_pair(1, 80));
							p->AddGun(gun);
							cout << "\nThanks for Buying The Steyr Aug \n";
							system("pause");
							break;
						}
						else
						{
							cout << "\nNot Enought Money!\n";
							system("pause");
							break;
						}
					}
//***************************************************************************************************************************
					system("cls");
					cout << "\n\t MachineGuns4 !\n\n"

						"                           .===;========.__, \n"
						"                           ('__)___________| \n"
						"     L__________________,--,--/ /-,-,-' '-,   ________   \n"
						"=====)o o o o ======== )) ____,===,___''' '7_/_,_,_,_,'---,-,\n"
						"     `--._,_,_,-,--,--'' (____| _ '___'oo ; ; ; ; ; ;_____ T|\n"
						"              `-'--'-/_,-------| ) ___--,__,------._ '__  |I|\n"
						"                       '==----/   '' )'--'_         `-._`-'I|\n"
						"                       /=[JM]/     `' -   --'           `-.L|\n"
						"                      /==---/           '- -'\n"
						"                      '-.__/             '__7 \n";
 


					cout << "\nBuy This?!\n"
						<< "(1) Yes ($2250)\n"
						<< "(2) Next! \n"
						<< "(3) Leave \n";
					choice = getLegitInt(1, 3);
					if (choice == 3){ break; }
					if (choice == 1)
					{
						unsigned money = p->GetMoney();
						if (money >= 2250)
						{
							unsigned ret = (money - 2250);
							p->SetMoney(ret);
							pair<string, pair<unsigned, unsigned>> gun = make_pair("Sig Commando", make_pair(1, 90));
							p->AddGun(gun);
							cout << "\nThanks for Buying The Sig Commando \n";
							system("pause");
							break;
						}
						else
						{
							cout << "\nNot Enought Money!\n";
							system("pause");
							break;
						}
					}
//***************************************************************************************************************************
					system("cls");
					cout << "\n\t MachineGuns5 !\n\n"

						"                          __,--.            \n"
						"       ,                 /_,__,_)        ,----. \n"
						"      /|________________/|__   __________|'##'|_____\n"
						"=====(  )_##################)==`)###################|\n"
						"     ,' |_)#################)===)#######__`__`__`___|____\n"
						"    =`--'._,_,_#############)===)######(_,_,_,_,_,_,_,_,_)\n"
						"               '--,_,__,__|.------.,--.,-.[JM],-----'\n"
						"                           |-##-| ||  )) |###( \n"
						"                           |-##-| '======|,###'\n"
						"                           '----'        ',####'\n"
						"                                          ',####)\n"
						"                                           '_,-'\n";


					cout << "\nBuy This?!\n"
						<< "(1) Yes ($2500)\n"
						<< "(2) Next! \n"
						<< "(3) Leave \n";
					choice = getLegitInt(1, 3);
					if (choice == 3){ break; }
					if (choice == 1)
					{
						unsigned money = p->GetMoney();
						if (money >= 2500)
						{
							unsigned ret = (money - 2500);
							p->SetMoney(ret);
							pair<string, pair<unsigned, unsigned>> gun = make_pair("LMG", make_pair(1, 100));
							p->AddGun(gun);
							cout << "\nThanks for Buying The LMG \n";
							system("pause");
							break;
						}
						else
						{
							cout << "\nNot Enought Money!\n";
							system("pause");
							break;
						}
					}
//***************************************************************************************************************************
					system("cls");
					cout << "\n\t MachineGuns6 !\n\n"

						"              _________\n"
						"            /'        /|\n"
						"           /         / |_\n"
						"          /         /  //|\n"
						"         /_________/  ////|\n"
						"        |   _ _    | 8o////|\n"
						"        | /'// )_  |   8///|\n"
						"        |/ // // ) |   8o///|\n"
						"        / // // //,|  /  8//|\n"
						"       / // // /// | /   8//|\n"
						"      / // // ///__|/    8//|\n"
						"     /.(_)// /// |       8///|\n"
						"    (_)'_`(_)//| |       8////|___________\n"
						"   (_) |'| (_)'| |        8///////////////\n"
						"   (_) |_| (_)'|_|         8/////////////\n"
						"    (_)._.(_) d' Hb         8oooooooopb'\n"
						"      `(_)'  d'  H`b\n"
						"            d'   `b`b\n"
						"           d'     H `b\n"
						"          d'      `b `b\n"
						"         d'           `b\n"
						"        d'             `b\n";

					cout << "\nBuy This?!\n"
						<< "(1) Yes ($3000)\n"
						<< "(2) Next! \n"
						<< "(3) Leave \n";
					choice = getLegitInt(1, 3);
					if (choice == 3){ break; }
					if (choice == 1)
					{
						unsigned money = p->GetMoney();
						if (money >= 3000)
						{
							unsigned ret = (money - 3000);
							p->SetMoney(ret);
							pair<string, pair<unsigned, unsigned>> gun = make_pair("Mini Gun", make_pair(1, 110));
							p->AddGun(gun);
							cout << "\nThanks for Buying Mini Gun \n";
							system("pause");
							break;
						}
						else
						{
							cout << "\nNot Enought Money!\n";
							system("pause");
							break;
						}
					}
//***************************************************************************************************************************
				} // <---While loop end..
				break;

			case 3:
				while (true)
				{
//***************************************************************************************************************************
					system("cls");
					cout << "\n\t Snipers 1 !\n\n"

						"                               ____________\n"
						"                              |            |\n"
						"                              |____________|\n"
						" ______________________________||________||___\n"
						"[_______________________,----------._ [====]o'''-,__....----=====\n"
						"                  [____(oooooooooooo)___________/__________     |\n"
						"                        |,'|''''''''  |====| [_)           ;    |\n"
						"                       // ''          |====|                ;   |\n"
						"                      //   ''         |====|                 ''''\n"
						"                     (_)   (_)        `----'\n";

					cout << "\nBuy This?!\n"
						<< "(1) Yes ($3500)\n"
						<< "(2) Next! \n"
						<< "(3) Leave \n";
					choice = getLegitInt(1, 3);
					if (choice == 3){ break; }
					if (choice == 1)
					{
						unsigned money = p->GetMoney();
						if (money >= 3500)
						{
							unsigned ret = (money - 3500);
							p->SetMoney(ret);
							pair<string, pair<unsigned, unsigned>> gun = make_pair("Interception", make_pair(1, 120));
							p->AddGun(gun);
							cout << "\nThanks for Buying The Interception \n";
							system("pause");
							break;
						}
						else
						{
							cout << "\nNot Enought Money!\n";
							system("pause");
							break;
						}
					}
//***************************************************************************************************************************
					system("cls");
					cout << "\n\t Snipers 2 !\n\n"

						"                                 /____________,\n"
						"     __                          |__________||\n"
						"     )|      _____________________/o(____)o(__                _\n"
						"   _/_|_____/  ,_____________.________________Y_....-----===='|\n"
						"  |==========;  , , , , , , , ;______________ --(  |(  |(  |((\n"
						"              `----------------|________|[ )) ad_'__)|  ||  ||| \n"
						"                                |      |  '' ,.__-'`-.|__)|__)||\n"
						"                                |______|      `''      ```---=,))\n";
 

					cout << "\nBuy This?!\n"
						<< "(1) Yes ($4000)\n"
						<< "(2) Next! \n"
						<< "(3) Leave \n";
					choice = getLegitInt(1, 3);
					if (choice == 3){ break; }
					if (choice == 1)
					{
						unsigned money = p->GetMoney();
						if (money >= 4000)
						{
							unsigned ret = (money - 4000);
							p->SetMoney(ret);
							pair<string, pair<unsigned, unsigned>> gun = make_pair("AK40Sniper", make_pair(1, 130));
							p->AddGun(gun);
							cout << "\nThanks for Buying The AK40Sniper \n";
							system("pause");
							break;
						}
						else
						{
							cout << "\nNot Enought Money!\n";
							system("pause");
							break;
						}
					}
//***************************************************************************************************************************
					system("cls");
					cout << "\n\t Snipers 3 !\n\n"


						"                                 ,----.___________,-,\n"
						"         ,__                    (________________|__|\n"
						"      __/()(_________________________/o(____)o(__  ``           _\n"
						"     (__________________________(_(_(_(_(________Y_....-----====;\n"
						"                   ( , , , , , , (______________)--            ((\n"
						"                    (_____________|________|[ )) JM  ____   __  ((\n"
						"                                   |____|    '' (.__-'`'. ((__) '((\n"
						"                                   |____|        `''      ```'''=,))\n"
						"                                   |    |\n"
						"                                   `===='\n";


					cout << "\nBuy This?!\n"
						<< "(1) Yes ($5000)\n"
						<< "(2) Next! \n"
						<< "(3) Leave \n";
					choice = getLegitInt(1, 3);
					if (choice == 3){ break; }
					if (choice == 1)
					{
						unsigned money = p->GetMoney();
						if (money >= 5000)
						{
							unsigned ret = (money - 5000);
							p->SetMoney(ret);
							pair<string, pair<unsigned, unsigned>> gun = make_pair("Auto Scope Sniper", make_pair(1, 150));
							p->AddGun(gun);
							cout << "\nThanks for Buying The Auto Scope Sniper! \n";
							system("pause");
							break;
						}
						else
						{
							cout << "\nNot Enought Money!\n";
							system("pause");
							break;
						}
					}
//***************************************************************************************************************************
					//if more snipers...
//***************************************************************************************************************************
				} // <---While loop end..
				break;


			}//<----End of Gun Type Switch

		}
		break;
	case 2: break;
	}



}

void DopeWarz::UseLibrary(Player * p)
{
	int choice;
	system("cls");
	cout << "\nWelcome to the Library!\n"
		<< "(1) Read a Book!\n"
		<< "(2) Leave\n";
	choice = getLegitInt(1, 2);
	RandGen rNg;
	unsigned i = (rNg(10) + 1);
	switch (choice)
	{
	case 1:
		cout << "\nWhat Book Would you like to read?!\n"
			<< "(1) 'Fear And Loathing In LasVegas'\n"
			<< "(2) '50 shades of grey'\n"
			<< "(3) 'The Hunger Games'\n"
			<< "(4) 'Harry PotHead'\n"
			<< "(5) 'Playboy Magazine'\n";
			choice = getLegitInt(1, 5);
		
			switch (choice)
			{
			case 1:
				if (unsigned j = (rNg(10) + 1) <= 5)
				{
					system("cls");
			   cout << "\n\nWe had two bags of grass, seventy - five pellets of mescaline,\n"
					<< "five sheets of high powered blotter acid, a salt shaker half full\n"
					<< "of cocaine, and a whole galaxy of multi - colored uppers, downers,\n"
					<< "screamers, laughers... and also a quart of tequila, a quart of rum,\n"
					<< "a case of Budweiser, a pint of raw ether and two dozen amyls.\n"
					<< " Not that we needed all that for the trip, but once you get locked \n"
					<< "into a serious drug collection, the tendency is to push it as far\n"
					<< "as you can. \n" "- Hunter S.Thompson, Fear and Loathing in Las Vegas\n";
					p->AddSmarts(i);
					cout << "\nAdded " << i << " Smarts...\n\n";
					system("pause");
				}
				else
				{
					system("cls");
					cout << "\n\nIn a closed society where everybody's guilty,the only crime is\n"
					<< "getting caught. In a world of thieves, the only final sin is stupidity.\n"
					<< " -Hunter S.Thompson, Fear and Loathing in Las Vegas\n";
					p->AddSmarts(i);
					cout << "\nAdded " << i << " Smarts...\n\n";
					system("pause");
				}
				break;
			case 2: 
				if (unsigned j = (rNg(10) + 1) <= 5)
				{
					system("cls");
					cout << "\n\nWhy don't you like to be touched?\n"
					 	 << "Because I'm fifty shades of fucked-up, Anastasia\n"
						 << "- E.L.James, Fifty Shades of Grey \n";
					p->AddSmarts(i);
					cout << "\nAdded " << i << " Smarts...\n\n";
					system("pause");
				}
				else
				{
					system("cls");
					cout << "\n\nDon't get your panties in such a twist... and give me back mine.\n"
						 << " ― E.L.James, Fifty Shades of Grey \n";
					p->AddSmarts(i);
					cout << "\nAdded " << i << " Smarts...\n\n";
					system("pause");
				}
				break;
			case 3:
				if (unsigned j = (rNg(10) + 1) <= 5)
				{
					system("cls");
					cout << "\n\nHappy Hunger Games! And may the odds be ever in your favor.\n"
						 << "― Suzanne Collins, The Hunger Games \n";
					p->AddSmarts(i);
					cout << "\nAdded " << i << " Smarts...\n\n";
					system("pause");
				}
				else
				{
					system("cls");
					cout << "\n\nThey'll either want to kill you, kiss you, or be you.\n"
						 << "― Suzanne Collins, Mockingjay \n";
					p->AddSmarts(i);
					cout << "\nAdded " << i << " Smarts...\n\n";
					system("pause");
				}
				break;
			case 4:
				if (unsigned j = (rNg(10) + 1) <= 5)
				{
					system("cls");
					cout << "\n\nHe must have known I'd want to leave you.\n"
						<< "No, he must have known you would always want to come back.\n"
						<< "― J.K.Rowling, Harry Potter and the Deathly Hallows \n";

					p->AddSmarts(i);
					cout << "\nAdded " << i << " Smarts...\n\n";
					system("pause");
				}
				else
				{
					system("cls");
					cout << "\n\n'Don't talk to me.''Why not?''Because I want to fix that\n"
						<< "in my memory for ever. Draco Malfoy, the amazing bouncing ferret...\n"
						<< "― J.K.Rowling, Harry Potter and the Goblet of Fire \n";

					p->AddSmarts(i);
					cout << "\nAdded " << i << " Smarts...\n\n";
					system("pause");
				}
				break;
			case 5: 
				if (unsigned j = (rNg(10) + 1) <= 5)
				{
					system("cls");
					cout << "\n\nIf you want to live your life in a creative way, \n"
						<< "as an artist, you have to not look back too much. \n"
						<< "You have to be willing to take whatever you’ve done \n"
						<< "and whoever you were and throw them away. The more \n"
						<< "the outside world tries to reinforce an image of you, \n"
						<< "the harder it is to continue to be an artist, which \n"
						<< "is why a lot of times, artists have to say, \n"
						<< "'Bye. I have to go. I’m going crazy and I’m getting out of here.'\n"
						<< "And they go and hibernate somewhere. Maybe later \n"
						<< "they re-emerge a little differently. \n\n"
						<< "― Walter Isaacson, Steve Jobs \n";
					
					p->AddSmarts(i);
					cout << "\nAdded " << i << " Smarts...\n\n";
					system("pause");
				}
				else
				{
					system("cls");
					cout << "\n\nThe playboy is not necessarily a man who has many girlfriends,\n"
						<< "or a man who has many women, or a man who has slept with many\n"
						<< "women. That is old. But there is a new breed of the playboy and \n"
						<< "he is the man who remains single in attempts to make every woman\n"
						<< "feel as if he belongs to her, he remains a virgin in order to make\n"
						<< "every woman feel like she will be the first one, and in the end he\n"
						<< "may choose a very unattractive woman to adorn his side, so that in\n"
						<< "all circumstances, he will shine as the more beautiful one. This is\n"
						<< "the new breed of playboy. And it is a very evil one.\n\n"
						<< "― C.JoyBell C.\n";

					p->AddSmarts(i);
					cout << "\nAdded " << i << " Smarts...\n\n";
					system("pause");
				}
				break;
			}

		break;
	case 2: break;
	}
}

void DopeWarz::UseGym(Player * p)
{
	//CREATE A 10% CHANCE  TO GET INJURED , CAUSEING A RANDOM 1-10 DAMAGE ....
	int choice;
	system("cls");
	cout << "\nWelcome to the Gym!\n"
		<< "(1) Pump Iron!\n"
		<< "(2) Leave\n";
	choice = getLegitInt(1, 2);
	RandGen rNg;
	unsigned i = (rNg(10) + 1);
	unsigned reps = (rNg(10) + 1);
	unsigned weight = (rNg(200) + 100);
	switch (choice)
	{
	case 1:
		cout << "\nHow you gunna prove your strong ?!\n"
			<< "(1) Bench Press\n"
			<< "(2) Barbell Shoulder Press\n"
			<< "(3) Leg Press\n"
			<< "(4) Squats\n"
			<< "(5) DeadLifts\n";
		choice = getLegitInt(1, 5);

		switch (choice)
		{
		case 1:
			if (unsigned j = (rNg(10) + 1) > 2)
			{
				system("cls");
				cout << "\n\nNice! , Benchpressed " << weight << " pounds for " << reps << " reps. \n";
	
				p->IncMaxHP(i);
				cout << "\nAdded " << i << " To MaxHealth...\n\n";
				system("pause");
			}
			else
			{
				system("cls");
				cout << "\n\nWhoa Buddy ! you pushed too hard and hurt yourself!\n";
				p->TakeDamage(i);
				cout << "\Dealt " << i << " Damage...\n\n";
				system("pause");
			}
			break;
		case 2:
			if (unsigned j = (rNg(10) + 1) > 2)
			{
				system("cls");
				cout << "\n\nNice! , Barbell Shoulder Pressed " << weight << " pounds for " << reps << " reps. \n";

				p->IncMaxHP(i);
				cout << "\nAdded " << i << " To MaxHealth...\n\n";
				system("pause");
			}
			else
			{
				system("cls");
				cout << "\n\nWhoa Buddy ! you pushed too hard and hurt yourself!\n";
				p->TakeDamage(i);
				cout << "\Dealt " << i << " Damage...\n\n";
				system("pause");
			}
			break;
		case 3:
			if (unsigned j = (rNg(10) + 1) > 2)
			{
				system("cls");
				cout << "\n\nNice! , Leg Pressed " << weight << " pounds for " << reps << " reps. \n";

				p->IncMaxHP(i);
				cout << "\nAdded " << i << " To MaxHealth...\n\n";
				system("pause");
			}
			else
			{
				system("cls");
				cout << "\n\nWhoa Buddy ! you pushed too hard and hurt yourself!\n";
				p->TakeDamage(i);
				cout << "\Dealt " << i << " Damage...\n\n";
				system("pause");
			}
			break;
		case 4:
			if (unsigned j = (rNg(10) + 1) > 2)
			{
				system("cls");
				cout << "\n\nNice! , Squat " << weight << " pounds for " << reps << " reps. \n";

				p->IncMaxHP(i);
				cout << "\nAdded " << i << " To MaxHealth...\n\n";
				system("pause");
			}
			else
			{
				system("cls");
				cout << "\n\nWhoa Buddy ! you pushed too hard and hurt yourself!\n";
				p->TakeDamage(i);
				cout << "\Dealt " << i << " Damage...\n\n";
				system("pause");
			}
			break;
		case 5:
			if (unsigned j = (rNg(10) + 1) > 2)
			{
				system("cls");
				cout << "\n\nNice! , DeadLifted " << weight << " pounds for" << reps << " reps. \n";

				p->IncMaxHP(i);
				cout << "\nAdded " << i << " To MaxHealth...\n\n";
				system("pause");
			}
			else
			{
				system("cls");
				cout << "\n\nWhoa Buddy ! you pushed too hard and hurt yourself!\n";
				p->TakeDamage(i);
				cout << "\Dealt " << i << " Damage...\n\n";
				system("pause");
			}
			break;
		}

		break;
	case 2: break;
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