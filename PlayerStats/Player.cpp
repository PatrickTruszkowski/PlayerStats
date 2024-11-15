#include "Player.h"

using namespace std;

Player::Player()
{
	// Set default values for the fields.
	name = "?";
	teamName = "?";
	nationality = "?";
	region = "?";
	achievement = "?";
	yearsPlayed = 0;
	totalMoneyWon = 0;
	selectionNumber = 0;
}

Player::Player(const string name, const string teamName, const string nationality, const string region, const string achievement, const int yearsPlayed, const int totalMoneyWon)
{
	// Construct player object.
	this->name = name;
	this->teamName = teamName;
	this->nationality = nationality;
	this->region = region;
	this->achievement = achievement;
	this->yearsPlayed = yearsPlayed;
	this->totalMoneyWon = totalMoneyWon;
	selectionNumber = 0;
}

bool Player::operator==(const Player& otherPlayer)
{
	// Return true if the name of this player is the same as the name of the other player.
	return this->name == otherPlayer.name;
}

string& Player::GetName()
{
	return name;
}

void Player::SetName(const string& name)
{
	this->name = name;
	cout << "\tNew name set.\n\n";
}

string& Player::GetTeamName()
{
	return teamName;
}

void Player::SetTeamName(const string& teamName)
{
	this->teamName = teamName;
}

string& Player::GetNationality()
{
	return nationality;
}

void Player::SetNationality(const string& nationality)
{
	this->nationality = nationality;

	cout << "\tNew nationality set.\n\n";
}

string& Player::GetRegion()
{
	return region;
}

void Player::SetRegion(const string& region)
{
	this->region = region;

	cout << "\tNew region set.\n\n";
}

string& Player::GetAchievement()
{
	return achievement;
}

void Player::SetAchievement(const string& achievement)
{
	this->achievement = achievement;

	cout << "\tNew achievement set.\n\n";
}

int Player::GetYearsPlayed() const
{
	return yearsPlayed;
}

void Player::SetYearsPlayed(const int yearsPlayed)
{
	this->yearsPlayed = yearsPlayed;

	cout << "\tNew years played set.\n\n";
}

float Player::GetTotalMoneyWon() const
{
	return totalMoneyWon;
}

void Player::SetTotalMoneyWon(const float totalMoneyWon)
{
	this->totalMoneyWon = totalMoneyWon;

	cout << "\tNew total money won set.\n\n";
}

int Player::GetSelectionNumber() const
{
	return selectionNumber;
}

void Player::SetSelectionNumber(const int selectionNumber)
{
	this->selectionNumber = selectionNumber;
}

void Player::DisplayStats() const
{
	// Show all stats with decimal precision set to 2 digits for money and setw for alignment.
	cout << "\t\t------------------------------------------------\n";
	cout << fixed << setprecision(2);
	cout << left;
	cout << "\t\t" << setw(20) << "Player Name:" << name << "\n\n";
	cout << "\t\t" << setw(20) << "Team:" << teamName << "\n\n";
	cout << "\t\t" << setw(20) << "Nationality:" << nationality << "\n\n";
	cout << "\t\t" << setw(20) << "Region:" << region << "\n\n";
	cout << "\t\t" << setw(20) << "Achievement:" << achievement << "\n\n";
	cout << "\t\t" << setw(20) << "Years Played:" << yearsPlayed << "\n\n";
	cout << "\t\t" << setw(20) << "Total Money Won:" << "$" << totalMoneyWon << "\n";
	cout << "\t\t------------------------------------------------\n\n\n\n";
}

void Player::WriteStatsToFile(ofstream& outputFile) const
{
	// Write all stats with decimal precision set to 2 digits for money and setw for alignment into .txt file.
	outputFile << "\t\t------------------------------------------------\n";
	outputFile << fixed << setprecision(2);
	outputFile << left;
	outputFile << "\t\t" << setw(20) << "Player Name:" << name << "\n\n";
	outputFile << "\t\t" << setw(20) << "Team:" << teamName << "\n\n";
	outputFile << "\t\t" << setw(20) << "Nationality:" << nationality << "\n\n";
	outputFile << "\t\t" << setw(20) << "Region:" << region << "\n\n";
	outputFile << "\t\t" << setw(20) << "Achievement:" << achievement << "\n\n";
	outputFile << "\t\t" << setw(20) << "Years Played:" << yearsPlayed << "\n\n";
	outputFile << "\t\t" << setw(20) << "Total Money Won:" << "$" << totalMoneyWon << "\n";
	outputFile << "\t\t------------------------------------------------\n\n\n\n";
}
