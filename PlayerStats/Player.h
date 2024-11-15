#pragma once

// Include all necessary libraries.
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>

class Player
{
private:
	// Declare all private member variables.
	std::string name;
	std::string teamName;
	std::string nationality;
	std::string region;
	std::string achievement;

	int yearsPlayed;
	int selectionNumber;

	float totalMoneyWon;

public:
	// Create default and normal constructors.
	Player();
	Player(const std::string, const std::string, const std::string, const std::string, const std::string, const int, const int);

	// Define the equal operator to compare player objects.
	bool operator==(const Player&);

	// Declare all public memeber functions.
	std::string& GetName();
	void SetName(const std::string&);

	std::string& GetTeamName();
	void SetTeamName(const std::string&);

	std::string& GetNationality();
	void SetNationality(const std::string&);

	std::string& GetRegion();
	void SetRegion(const std::string&);

	std::string& GetAchievement();
	void SetAchievement(const std::string&);

	int GetYearsPlayed() const;
	void SetYearsPlayed(const int);

	float GetTotalMoneyWon() const;
	void SetTotalMoneyWon(const float);

	int GetSelectionNumber() const;
	void SetSelectionNumber(int);

	void DisplayStats() const;
	void WriteStatsToFile(std::ofstream&) const;
};
