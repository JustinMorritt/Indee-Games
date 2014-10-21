#include <sstream> 
#include <iostream>
#include <iomanip>
#include <fstream>
#include "DopeWarz.h"
#include "Market.h"



DopeWarz::DopeWarz()
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
	int Location = 0; int choice2 = 2; int choice = 2;
	while (p->GetHealth() != 0 && m_DaysLeft != 0 && quit == false)
	{
		Market market;
		Market& m = market;
		switch (Location)
		{
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
						<< "(5) Loan Shark " << "Debt: $" << p->GetDebt() << "\n"
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

					case 3:  p->DisplayStats(pname); system("cls"); showedStats = true; break;
					case 4:  Location = MoveLoacation(); system("cls"); changeLocation = true; DDay(p); break;
					}
				}
				break;

				//INSERT LOCATIONS HERE
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
	switch (choice)
	{
	case 0:return 0; 
	case 1:return 1; 
	case 2:return 2; 
	case 3:return 3; 
	case 4:return 4;
	case 5:return 5;
	case 6:return 6; 
	}
	return 0;
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