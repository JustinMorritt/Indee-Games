#ifndef PLAYER_H__
#define PLAYER_H__
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include "Market.h"

using namespace std;

class Player //INTERFACE
{
public:
	virtual int GetHealth() = 0;
	virtual int GetMaxHealth() = 0;
	virtual void SetHealth(int health) = 0;
	virtual void TakeDamage(int dmg) = 0;
	virtual void IncMaxHP(int hp) = 0;
	virtual void DisplayStats(string name) = 0;
	virtual unsigned GetBackpackSpace() = 0;
	virtual unsigned GetUsedSpace() = 0;
	virtual unsigned GetMoney() = 0;
	virtual unsigned GetDebt() = 0;
	virtual unsigned GetSpeed() = 0;
	virtual void SetMoney(unsigned money) = 0;
	virtual void SetDebt(unsigned money) = 0;
	virtual void AddSmarts(unsigned smarts) = 0;
	virtual void IncreaseDebt() = 0;
	virtual void Buy(Market& m) = 0;
	virtual void Sell(Market& m) = 0;
	virtual void ShowBackpack() = 0;
	virtual void AddGun(pair<string, pair<unsigned, unsigned>> gun) = 0;
	Player();
	~Player();
};

/*
MAKE DIFFERENT CLASSES OF PLAYERS  ...
SMART		(makes more money from selling) ,
TANKY		(more hp) ,
QUICK		(higher chance to run away from cops) ,
DANGEROUS	(more damage with weapons)
*/


class SmartPlayer : public Player
{
public:
	SmartPlayer();
	~SmartPlayer();
	virtual int GetHealth(){ return m_Health; };
	virtual int GetMaxHealth(){ return m_MaxHealth; };
	virtual void TakeDamage(int dmg){ m_Health -= dmg; };
	virtual void SetHealth(int health){ m_Health = health; };
	virtual void IncMaxHP(int hp){ m_MaxHealth += hp; };
	virtual unsigned GetMoney(){ return m_Money; };
	virtual unsigned GetDebt() { return m_Debt; };
	virtual void SetMoney(unsigned money){ m_Money = money; };
	virtual void SetDebt(unsigned money){ m_Debt = money; };
	virtual void AddSmarts(unsigned smarts){ m_Smarts += smarts; };
	virtual void IncreaseDebt();
	virtual void DisplayStats(string name);
	virtual unsigned GetBackpackSpace(){ return m_Backpack; };
	virtual unsigned GetUsedSpace(){ return m_UsedSpace; };
	virtual unsigned GetSpeed(){ return m_Speed; };
	vector<pair<string, pair<unsigned, unsigned>>>& GetSack(){ return m_Product; };
	vector<pair<string, pair<unsigned, unsigned>>>& GetGuns(){ return m_Guns; };
	virtual void AddGun(pair<string, pair<unsigned, unsigned>> gun);
	void FillSack(int units){ m_UsedSpace += units; };
	void EmptySack(int units){ m_UsedSpace -= units; };
	virtual void Buy(Market& m);
	virtual void Sell(Market& m);
	virtual void ShowBackpack();

	friend int getLegitInt(int low, int high);

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
	//GUNS		NAME		#AMOUNT     DAMAGE 
	vector<pair<string, pair<unsigned, unsigned>>> m_Guns;

};

class TankyPlayer : public Player
{
public:
	TankyPlayer();
	~TankyPlayer();
	virtual int GetHealth(){ return m_Health; };
	virtual int GetMaxHealth(){ return m_MaxHealth; };
	virtual void SetHealth(int health){ m_Health = health; };
	virtual void TakeDamage(int dmg){ m_Health -= dmg; };
	virtual void IncMaxHP(int hp){ m_MaxHealth += hp; };
	virtual void DisplayStats(string name);
	virtual unsigned GetMoney(){ return m_Money; };
	virtual unsigned GetDebt() { return m_Debt; };
	virtual void SetMoney(unsigned money){ m_Money = money; };
	virtual void SetDebt(unsigned money){ m_Debt = money; };
	virtual void AddSmarts(unsigned smarts){ m_Smarts += smarts; };
	virtual void IncreaseDebt();
	virtual unsigned GetBackpackSpace(){ return m_Backpack; };
	virtual unsigned GetUsedSpace(){ return m_UsedSpace; };
	virtual unsigned GetSpeed(){ return m_Speed; };
	vector<pair<string, pair<unsigned, unsigned>>>& GetSack(){ return m_Product; };
	vector<pair<string, pair<unsigned, unsigned>>>& GetGuns(){ return m_Guns; };
	virtual void AddGun(pair<string, pair<unsigned, unsigned>> gun);
	void FillSack(int units){ m_UsedSpace += units; };
	void EmptySack(int units){ m_UsedSpace -= units; };
	virtual void Buy(Market& m);
	virtual void Sell(Market& m);
	virtual void ShowBackpack();

	friend int getLegitInt(int low, int high);
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
	//GUNS		NAME		#AMOUNT     DAMAGE 
	vector<pair<string, pair<unsigned, unsigned>>> m_Guns;
};

class QuickPlayer : public Player
{
public:
	QuickPlayer();
	~QuickPlayer();
	virtual int GetHealth(){ return m_Health; };
	virtual int GetMaxHealth(){ return m_MaxHealth; };
	virtual void SetHealth(int health){ m_Health = health; };
	virtual void TakeDamage(int dmg){ m_Health -= dmg; };
	virtual void IncMaxHP(int hp){ m_MaxHealth += hp; };
	virtual unsigned GetMoney(){ return m_Money; };
	virtual unsigned GetDebt() { return m_Debt; };
	virtual void SetDebt(unsigned money){ m_Debt = money; };
	virtual void SetMoney(unsigned money){ m_Money = money; };
	virtual void AddSmarts(unsigned smarts){ m_Smarts += smarts; };
	virtual void IncreaseDebt();
	virtual void DisplayStats(string name);
	virtual unsigned GetBackpackSpace(){ return m_Backpack; };
	virtual unsigned GetUsedSpace(){ return m_UsedSpace; };
	virtual unsigned GetSpeed(){ return m_Speed; };
	vector<pair<string, pair<unsigned, unsigned>>>& GetSack(){ return m_Product; };
	vector<pair<string, pair<unsigned, unsigned>>>& GetGuns(){ return m_Guns; };
	virtual void AddGun(pair<string, pair<unsigned, unsigned>> gun);
	void FillSack(int units){ m_UsedSpace += units; };
	void EmptySack(int units){ m_UsedSpace -= units; };
	virtual void Buy(Market& m);
	virtual void Sell(Market& m);
	virtual void ShowBackpack();

	friend int getLegitInt(int low, int high);
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
	//GUNS		NAME		#AMOUNT     DAMAGE 
	vector<pair<string, pair<unsigned, unsigned>>> m_Guns;
};

class DangerPlayer : public Player
{
public:
	DangerPlayer();
	~DangerPlayer();
	virtual int GetHealth(){ return m_Health; };
	virtual int GetMaxHealth(){ return m_MaxHealth; };
	virtual void SetHealth(int health){ m_Health = health; };
	virtual void TakeDamage(int dmg){ m_Health -= dmg; };
	virtual void IncMaxHP(int hp){ m_MaxHealth += hp; };
	virtual unsigned GetMoney(){ return m_Money; };
	virtual unsigned GetDebt() { return m_Debt; };
	virtual void SetMoney(unsigned money){ m_Money = money; };
	virtual void SetDebt(unsigned money){ m_Debt = money; };
	virtual void AddSmarts(unsigned smarts){ m_Smarts += smarts; };
	virtual void DisplayStats(string name);
	virtual void IncreaseDebt();
	virtual unsigned GetBackpackSpace(){ return m_Backpack; };
	virtual unsigned GetUsedSpace(){ return m_UsedSpace; };
	void FillSack(int units){ m_UsedSpace += units; };
	void EmptySack(int units){ m_UsedSpace -= units; };
	virtual unsigned GetSpeed(){ return m_Speed; };
	vector<pair<string, pair<unsigned, unsigned>>>& GetSack(){ return m_Product; };
	vector<pair<string, pair<unsigned, unsigned>>>& GetGuns(){ return m_Guns; };
	virtual void AddGun(pair<string, pair<unsigned, unsigned>> gun);
	virtual void Buy(Market& m);
	virtual void Sell(Market& m);
	virtual void ShowBackpack();

	friend int getLegitInt(int low, int high);
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
	//GUNS		NAME		#AMOUNT     DAMAGE 
	vector<pair<string, pair<unsigned, unsigned>>> m_Guns;
};













#endif