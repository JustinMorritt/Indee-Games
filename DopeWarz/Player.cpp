#include "Player.h"
#include <iomanip>


Player::Player()
{
}


Player::~Player()
{
}


SmartPlayer::SmartPlayer() :
m_Health(100), m_Smarts(50), m_Armour(0), m_Money(0),
m_Damage(0), m_Speed(0), m_Backpack(100), m_Debt(5000.00)
{

}
TankyPlayer::TankyPlayer():
m_Health(150), m_Smarts(0), m_Armour(0), m_Money(0),
m_Damage(0), m_Speed(0), m_Backpack(100), m_Debt(5000.00)
{

}
QuickPlayer::QuickPlayer():
m_Health(100), m_Smarts(0), m_Armour(0), m_Money(0),
m_Damage(0), m_Speed(50), m_Backpack(100), m_Debt(5000.00)
{

}
DangerPlayer::DangerPlayer():
m_Health(100), m_Smarts(0), m_Armour(0), m_Money(0),
m_Damage(50), m_Speed(0), m_Backpack(100), m_Debt(5000.00)
{

}

void SmartPlayer::DisplayStats(string name)
{
	cout << "\n\n<--  " << name << "  -->\n\n"
		<< setw(10) << "<-- Class -->\n" << setw(5) << "Smart" << "\n"
		<< setw(10) << "<-- Health -->\n" << setw(5) << m_Health << "\n"
		<< setw(10) << "<-- Money -->\n" << setw(5) << m_Money << "\n"
		<< setw(10) << "<-- Debt -->\n" << setw(5) << m_Debt << "\n"
		<< setw(10) << "<-- Smarts -->\n" << setw(5) << m_Smarts << "\n"
		<< setw(10) << "<-- Armour -->\n" << setw(5) << m_Armour << "\n"
		<< setw(10) << "<-- Damage -->\n" << setw(5) << m_Damage << "\n"
		<< setw(10) << "<-- Speed -->\n" << setw(5) << m_Speed << "\n"
		<< setw(10) << "<-- Backpack Space -->\n" << setw(5) << m_Backpack << "\n\n";
}
void TankyPlayer::DisplayStats(string name)
{
	cout << "\n\n<--  " << name << "  -->\n\n"
		<< setw(10) << "<-- Class -->\n" << setw(5) << "Tanky" << "\n"
		<< setw(10) << "<-- Health -->\n" << setw(5) << m_Health << "\n"
		<< setw(10) << "<-- Money -->\n" << setw(5) << m_Money << "\n"
		<< setw(10) << "<-- Debt -->\n" << setw(5) << m_Debt << "\n"
		<< setw(10) << "<-- Smarts -->\n" << setw(5) << m_Smarts << "\n"
		<< setw(10) << "<-- Armour -->\n" << setw(5) << m_Armour << "\n"
		<< setw(10) << "<-- Damage -->\n" << setw(5) << m_Damage << "\n"
		<< setw(10) << "<-- Speed -->\n" << setw(5) << m_Speed << "\n"
		<< setw(10) << "<-- Backpack Space -->\n" << setw(5) << m_Backpack << "\n\n";
}
void QuickPlayer::DisplayStats(string name)
{
	cout << "\n\n<--  " << name << "  -->\n\n"
		<< setw(10) << "<-- Class -->\n" << setw(5) << "Quick" << "\n"
		<< setw(10) << "<-- Health -->\n" << setw(5) << m_Health << "\n"
		<< setw(10) << "<-- Money -->\n" << setw(5) << m_Money << "\n"
		<< setw(10) << "<-- Debt -->\n" << setw(5) << m_Debt << "\n"
		<< setw(10) << "<-- Smarts -->\n" << setw(5) << m_Smarts << "\n"
		<< setw(10) << "<-- Armour -->\n" << setw(5) << m_Armour << "\n"
		<< setw(10) << "<-- Damage -->\n" << setw(5) << m_Damage << "\n"
		<< setw(10) << "<-- Speed -->\n" << setw(5) << m_Speed << "\n"
		<< setw(10) << "<-- Backpack Space -->\n" << setw(5) << m_Backpack << "\n\n";
}
void DangerPlayer::DisplayStats(string name)
{
	cout << "\n\n<--  " << name << "  -->\n\n"
		<< setw(10) << "<-- Class -->\n" << setw(5) << "Dangerous" << "\n"
		<< setw(10) << "<-- Health -->\n" << setw(5) << m_Health << "\n"
		<< setw(10) << "<-- Money -->\n" << setw(5) << m_Money << "\n"
		<< setw(10) << "<-- Debt -->\n" << setw(5) << m_Debt << "\n"
		<< setw(10) << "<-- Smarts -->\n" << setw(5) << m_Smarts << "\n"
		<< setw(10) << "<-- Armour -->\n" << setw(5) << m_Armour << "\n"
		<< setw(10) << "<-- Damage -->\n" << setw(5) << m_Damage << "\n"
		<< setw(10) << "<-- Speed -->\n" << setw(5) << m_Speed << "\n"
		<< setw(10) << "<-- Backpack Space -->\n" << setw(5) << m_Backpack << "\n\n";
}