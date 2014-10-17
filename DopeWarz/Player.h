#ifndef PLAYER_H__
#define PLAYER_H__
#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;

class Player
{
public:
	virtual int GetHealth() = 0;
	virtual int GetMaxHealth() = 0;
	virtual void DisplayStats(string name) = 0;
	virtual unsigned GetBackpackSpace() = 0;
	virtual unsigned GetUsedSpace() = 0;
	virtual unsigned GetMoney() = 0;
	virtual unsigned GetDebt() = 0;
	virtual void IncreaseDebt() = 0;
	Player();
	~Player();
};

//MAKE DIFFERENT CLASSES OF PLAYERS  ...  SMART(makes more money from selling) , TANKY(more hp) , QUICK(higher chance to run away from cops) ,
									//... DANGEROUS (more damage with weapons)



class SmartPlayer : public Player
{
public:
	SmartPlayer();
	~SmartPlayer();
	virtual int GetHealth(){ return m_Health; };
	virtual int GetMaxHealth(){ return m_MaxHealth; };
	virtual unsigned GetMoney(){ return m_Money; };
	virtual unsigned GetDebt() { return m_Debt; };
	virtual void IncreaseDebt();
	virtual void DisplayStats(string name);
	virtual unsigned GetBackpackSpace();
	virtual unsigned GetUsedSpace();
private:
	unsigned m_Money;
	unsigned m_Debt;
	int m_Health;
	int m_MaxHealth;
	unsigned m_Smarts;
	unsigned m_Armour;
	unsigned m_Damage;
	unsigned m_Speed;
	unsigned m_UsedSpace;
	unsigned m_Backpack;
	//0 INDEX   NAME        #UNITS   $PRICE BOUGHT AT		   
	vector<pair<string, pair<unsigned, unsigned>>> m_Product;
};

class TankyPlayer : public Player
{
public:
	TankyPlayer();
	~TankyPlayer();
	virtual int GetHealth(){ return m_Health; };
	virtual int GetMaxHealth(){ return m_MaxHealth; };
	virtual void DisplayStats(string name);
	virtual unsigned GetMoney(){ return m_Money; };
	virtual unsigned GetDebt() { return m_Debt; };
	virtual void IncreaseDebt();
	virtual unsigned GetBackpackSpace();
	virtual unsigned GetUsedSpace();
private:
	unsigned m_Money;
	unsigned m_Debt;
	int m_Health;
	int m_MaxHealth;
	unsigned m_Smarts;
	unsigned m_Armour;
	unsigned m_Damage;
	unsigned m_Speed;
	unsigned m_UsedSpace;
	unsigned m_Backpack;	
	//0 INDEX   NAME        #UNITS   $PRICE BOUGHT AT		   
	vector<pair<string, pair<unsigned, unsigned>>> m_Product;
};

class QuickPlayer : public Player
{
public:
	QuickPlayer();
	~QuickPlayer();
	virtual int GetHealth(){ return m_Health; };
	virtual int GetMaxHealth(){ return m_MaxHealth; };
	virtual unsigned GetMoney(){ return m_Money; };
	virtual unsigned GetDebt() { return m_Debt; };
	virtual void IncreaseDebt();
	virtual void DisplayStats(string name);
	virtual unsigned GetBackpackSpace();
	virtual unsigned GetUsedSpace();
private:
	unsigned m_Money;
	unsigned m_Debt;
	int m_Health;
	int m_MaxHealth;
	unsigned m_Smarts;
	unsigned m_Armour;
	unsigned m_Damage;
	unsigned m_Speed;
	unsigned m_UsedSpace;
	unsigned m_Backpack;
	//0 INDEX   NAME        #UNITS   $PRICE BOUGHT AT		   
	vector<pair<string, pair<unsigned, unsigned>>> m_Product;
};

class DangerPlayer : public Player
{
public:
	DangerPlayer();
	~DangerPlayer();
	virtual int GetHealth(){ return m_Health; };
	virtual int GetMaxHealth(){ return m_MaxHealth; };
	virtual unsigned GetMoney(){ return m_Money; };
	virtual unsigned GetDebt() { return m_Debt; };
	virtual void DisplayStats(string name);
	virtual void IncreaseDebt();
	virtual unsigned GetBackpackSpace();
	virtual unsigned GetUsedSpace();
private:
	unsigned m_Money;
	unsigned m_Debt;
	int m_Health;
	int m_MaxHealth;
	unsigned m_Smarts;
	unsigned m_Armour;
	unsigned m_Damage;
	unsigned m_Speed;
	unsigned m_UsedSpace;
	unsigned m_Backpack;
	//0 INDEX   NAME        #UNITS   $PRICE BOUGHT AT		   
	vector<pair<string, pair<unsigned, unsigned>>> m_Product;

};













#endif