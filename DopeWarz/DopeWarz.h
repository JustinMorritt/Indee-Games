#ifndef DOPEWARZ_H__
#define DOPEWARZ_H__

#include <map>
#include "Player.h"

using namespace std;


class DopeWarz
{
public:
	DopeWarz();
	~DopeWarz();
	int MainMenu();
	void DisplayLeaderBoard() const;
	void DisplayMarket() const;
	void GameTitle() const;
	void GoodBye() const;
	void LoadUsers();
	void SetNewUser();
	Player* SetPlayer(unsigned type);
	void SetPlayersMap(map<string, pair<double, int>> playerMap);
	void LoadPlayer();
	void Play(string name, unsigned Class, unsigned days);
	void DDay(){ --m_DaysLeft; };
	int getLegitInt(int low, int high) const;
	string getLegitString() const;

private:
	unsigned m_DaysLeft;
	Player * m_Player;

	// Name , Money , Health.
	map<string, pair<double, int>> m_PlayerInfo;
	//  MONEY       DAYS    NAME
	map<double, pair<int, string>> m_LB20;
	map<double, pair<int, string>> m_LB40;
	map<double, pair<int, string>> m_LB80;
	map<double, pair<int, string>> m_LB160;

};





#endif