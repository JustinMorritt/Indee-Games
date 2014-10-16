#ifndef PLAYER_H__
#define PLAYER_H__
#include <iostream>
#include <string>
using namespace std;

class Player
{
public:
	virtual int GetHealth() = 0;
	virtual void DisplayStats(string name) = 0;
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
	virtual void DisplayStats(string name);
private:
	double m_Money;
	double m_Debt;
	int m_Health;
	unsigned m_Smarts;
	unsigned m_Armour;
	unsigned m_Damage;
	unsigned m_Speed;
	unsigned m_UsedSpace;
	unsigned m_Backpack;
};

class TankyPlayer : public Player
{
public:
	TankyPlayer();
	~TankyPlayer();
	virtual int GetHealth(){ return m_Health; };
	virtual void DisplayStats(string name);
private:
	double m_Money;
	double m_Debt;
	int m_Health;
	unsigned m_Smarts;
	unsigned m_Armour;
	unsigned m_Damage;
	unsigned m_Speed;
	unsigned m_UsedSpace;
	unsigned m_Backpack;
};

class QuickPlayer : public Player
{
public:
	QuickPlayer();
	~QuickPlayer();
	virtual int GetHealth(){ return m_Health; };
	virtual void DisplayStats(string name);
private:
	double m_Money;
	double m_Debt;
	int m_Health;
	unsigned m_Smarts;
	unsigned m_Armour;
	unsigned m_Damage;
	unsigned m_Speed;
	unsigned m_UsedSpace;
	unsigned m_Backpack;
};

class DangerPlayer : public Player
{
public:
	DangerPlayer();
	~DangerPlayer();
	virtual int GetHealth(){ return m_Health; };
	virtual void DisplayStats(string name);
private:
	double m_Money;
	double m_Debt;
	int m_Health;
	unsigned m_Smarts;
	unsigned m_Armour;
	unsigned m_Damage;
	unsigned m_Speed;
	unsigned m_UsedSpace;
	unsigned m_Backpack;
};













#endif