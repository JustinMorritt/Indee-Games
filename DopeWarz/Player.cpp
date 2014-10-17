#include "Player.h"
#include <iomanip>


Player::Player()
{
}


Player::~Player()
{
}


SmartPlayer::SmartPlayer() :
m_Health(100), m_Smarts(50), m_Armour(0), m_Money(5000.00), m_UsedSpace(0),
m_Damage(0), m_Speed(0), m_Backpack(100), m_Debt(5000.00), m_MaxHealth(100)
{

}
TankyPlayer::TankyPlayer():
m_Health(150), m_Smarts(0), m_Armour(0), m_Money(5000.00), m_UsedSpace(0),
m_Damage(0), m_Speed(0), m_Backpack(100), m_Debt(5000.00), m_MaxHealth(150)
{

}
QuickPlayer::QuickPlayer():
m_Health(100), m_Smarts(0), m_Armour(0), m_Money(5000.00), m_UsedSpace(0),
m_Damage(0), m_Speed(50), m_Backpack(100), m_Debt(5000.00), m_MaxHealth(100)
{

}
DangerPlayer::DangerPlayer():
m_Health(100), m_Smarts(0), m_Armour(0), m_Money(5000.00), m_UsedSpace(0),
m_Damage(50), m_Speed(0), m_Backpack(100), m_Debt(5000.00), m_MaxHealth(100)
{

}

void SmartPlayer::DisplayStats(string name)
{
	cout << "\n\t<--  " << name << "  -->\n"
		<< setw(10) << left << "Class " << setw(15) << "Smart" << "\n"
		<< setw(10) << left << "Health " << setw(15) << m_Health << "\n"
		<< setw(10) << left << "Money " << "$" << m_Money << "\n"
		<< setw(10) << left << "Debt " << "$" << m_Debt << "\n"
		<< setw(10) << left << "Smarts " << setw(15) << m_Smarts << "\n"
		<< setw(10) << left << "Armour " << setw(15) << m_Armour << "\n"
		<< setw(10) << left << "Damage " << setw(15) << m_Damage << "\n"
		<< setw(10) << left << "Speed " << setw(15) << m_Speed << "\n"
		<< setw(10) << left << "Backpack" << m_UsedSpace << " / " << m_Backpack << "\n";
}
void TankyPlayer::DisplayStats(string name)
{
	cout << "\n\t<--  " << name << "  -->\n"
		<< setw(10) << left << "Class " << setw(15) << "Smart" << "\n"
		<< setw(10) << left << "Health " << setw(15) << m_Health << "\n"
		<< setw(10) << left << "Money " << "$" << m_Money << "\n"
		<< setw(10) << left << "Debt " << "$" << m_Debt << "\n"
		<< setw(10) << left << "Smarts " << setw(15) << m_Smarts << "\n"
		<< setw(10) << left << "Armour " << setw(15) << m_Armour << "\n"
		<< setw(10) << left << "Damage " << setw(15) << m_Damage << "\n"
		<< setw(10) << left << "Speed " << setw(15) << m_Speed << "\n"
		<< setw(10) << left << "Backpack" << m_UsedSpace << " / " << m_Backpack << "\n";
}
void QuickPlayer::DisplayStats(string name)
{
	cout << "\n\t<--  " << name << "  -->\n"
		<< setw(10) << left << "Class " << setw(15) << "Smart" << "\n"
		<< setw(10) << left << "Health " << setw(15) << m_Health << "\n"
		<< setw(10) << left << "Money " << "$" << m_Money << "\n"
		<< setw(10) << left << "Debt " << "$" << m_Debt << "\n"
		<< setw(10) << left << "Smarts " << setw(15) << m_Smarts << "\n"
		<< setw(10) << left << "Armour " << setw(15) << m_Armour << "\n"
		<< setw(10) << left << "Damage " << setw(15) << m_Damage << "\n"
		<< setw(10) << left << "Speed " << setw(15) << m_Speed << "\n"
		<< setw(10) << left << "Backpack" << m_UsedSpace << " / " << m_Backpack << "\n";
}
void DangerPlayer::DisplayStats(string name)
{
	cout << "\n\t<--  " << name << "  -->\n"
		<< setw(10) << left << "Class " << setw(15) << "Smart" << "\n"
		<< setw(10) << left << "Health " << setw(15) << m_Health << "\n"
		<< setw(10) << left << "Money " << "$" << m_Money << "\n"
		<< setw(10) << left << "Debt " << "$" << m_Debt << "\n"
		<< setw(10) << left << "Smarts " << setw(15) << m_Smarts << "\n"
		<< setw(10) << left << "Armour " << setw(15) << m_Armour << "\n"
		<< setw(10) << left << "Damage " << setw(15) << m_Damage << "\n"
		<< setw(10) << left << "Speed " << setw(15) << m_Speed << "\n"
		<< setw(10) << left << "Backpack" << m_UsedSpace << " / " << m_Backpack << "\n";
}


unsigned SmartPlayer::GetBackpackSpace()
{
	return m_Backpack;
}
unsigned TankyPlayer::GetBackpackSpace()
{
	return m_Backpack;
}
unsigned QuickPlayer::GetBackpackSpace()
{
	return m_Backpack;
}
unsigned DangerPlayer::GetBackpackSpace()
{
	return m_Backpack;
}


unsigned SmartPlayer::GetUsedSpace()
{
	return m_UsedSpace;
}
unsigned TankyPlayer::GetUsedSpace()
{
	return m_UsedSpace;
}
unsigned QuickPlayer::GetUsedSpace()
{
	return m_UsedSpace;
}
unsigned DangerPlayer::GetUsedSpace()
{
	return m_UsedSpace;
}

void SmartPlayer::IncreaseDebt()
{
	if (m_Debt > 0)
	{
		m_Debt += (m_Debt * 0.05);
	}
}
void TankyPlayer::IncreaseDebt()
{
	if (m_Debt > 0)
	{
		m_Debt += (m_Debt * 0.05);
	}
}
void QuickPlayer::IncreaseDebt()
{
	if (m_Debt > 0)
	{
		m_Debt += (m_Debt * 0.05);
	}
}
void DangerPlayer::IncreaseDebt()
{
	if (m_Debt > 0)
	{
		m_Debt += (m_Debt * 0.05);
	}
}


void SmartPlayer::Buy()
{

}
void SmartPlayer::Sell()
{

}

void TankyPlayer::Buy()
{

}
void TankyPlayer::Sell()
{

}

void QuickPlayer::Buy()
{

}
void QuickPlayer::Sell()
{

}

void DangerPlayer::Buy()
{

}
void DangerPlayer::Sell()
{

}