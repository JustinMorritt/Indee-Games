#include <sstream> 
#include <iostream>
#include "DopeWarz.h"
#include <fstream>

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
	cout << " GOODBYE !" << endl;
	//GoodBye();
}


DopeWarz::~DopeWarz()
{
}


int DopeWarz::MainMenu()
{
	int choice;
	while (true)
	{
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
	cout << "\n\nEnter Your Name Playa:\n";
	string name = getLegitString();
	cout << "\nOk, "<< name <<" What Kind of Thug are you?\n";
	cout << "\n(1) Smart\t (++ money from transactions)\n"
		 << "(2) Tanky \t (++ Health)\n"
	     << "(3) Quick \t (++ chance of running from cops)\n"
	 	 << "(4) Dangeous\t (++ gun damage)\n";
	int Class = getLegitInt(1, 4);
	string strClass;
	
	switch (Class)
	{
	case 1:	strClass = "Smart";
			break;
	case 2:	strClass = "Tanky";
		break;
	case 3:	strClass = "Quick";
		break;
	case 4:	strClass = "Dangerous";
		break;
	}
	cout << "\nAlrighty " << name << " you " << strClass << " Motha Fugga,  How Many Days ?\n";
	cout << "\n(1) 20 \t (For the Wimps)\n"
		<< "(2) 40 \t (For The Buisness Men)\n"
		<< "(3) 80 \t (Semi Hardcore)\n"
		<< "(4) 160  (Hardcore Bloodshot Eyes!)\n";
	int Days = getLegitInt(1, 4);

	Play(name, Class, Days);

}
void DopeWarz::LoadPlayer()
{

}


void DopeWarz::DisplayLeaderBoard() const
{
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
	case 1:	 m_Player = new SmartPlayer;
		break;
	case 2:	 m_Player = new TankyPlayer;
		break;
	case 3:	 m_Player = new QuickPlayer;
		break;
	case 4:	 m_Player = new DangerPlayer;
		break;
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

	cout << "\n\nHey There " << name << " Welcome to the streets !\n";
	bool quit = false;
	
	while (p->GetHealth() != 0 && m_DaysLeft != 0 && quit == false)
	{
		int Location = 0;

		switch (Location)
		{
			case 0 :
				int choice = 2;
				while (choice != 0 && choice != 4 && m_DaysLeft != 0 && p->GetHealth() != 0)
				{
					cout << "\n(1) Buy !\n"
						<< "(2) Sell !\n"
						<< "(3) Show Stats\n"
						<< "(4) Move Location\n"
						<< "(0) Save & Quit\n"
						<< "<--Days Left: " << m_DaysLeft << "-->\n";
						choice = getLegitInt(0, 4);
						switch (choice)
						{
							case 0:	quit = true; break;
							case 1: cout << "\n\nBUYS!\n\n"; DDay(); break;
							case 2: cout << "\n\nSELLS!\n\n"; DDay(); break;
							case 3: p->DisplayStats(pname); break;
							case 4: cout << "\n\nMOVING!\n\n"; DDay(); break;
						}
				}

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

void DopeWarz::GameTitle() const
{

}
void DopeWarz::GoodBye() const
{

}
