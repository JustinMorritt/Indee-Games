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
	void GameTitle() const;
	void GoodBye() const;
	void LoadUsers();
	void SetNewUser();
	Player* SetPlayer(unsigned type);
	void SetPlayersMap(map<string, pair<double, int>> playerMap);
	void LoadPlayer();
	void Play(string name, unsigned Class, unsigned days);
	void DDay(Player * p){ --m_DaysLeft; p->IncreaseDebt(); };
	int MoveLoacation() const;

	void PayLoanShark(Player * p);
	void GoToHospital(Player * p);
	void BuyGuns(Player * p);
	void UseBank(Player * p);
	void SetBank(unsigned money){ m_BankMoney = money; };
	unsigned GetBank() const{ return m_BankMoney; };


	int getLegitInt(int low, int high) const;
	string getLegitString() const;

private:
	unsigned m_BankMoney;
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