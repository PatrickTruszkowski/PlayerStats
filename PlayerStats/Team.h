#pragma once

// Include vector class.
#include <vector>

// Include player header to access the player class.
#include "Player.h"

class Team
{
private:
	// Declare all private member variables.
	std::string teamName;

	std::vector<Player> playerVector;

public:
	// Create default and normal constructors.
	Team();
	Team(const std::string&);

	// Define the equal operator to compare team objects.
	bool operator==(const Team&);

	// Declare all public member functions.
	std::string GetTeamName();
	std::vector<Player>& GetPlayerVector();
	void SetTeamName(const std::string&);
	void AddPlayer(const std::string&, const std::string&, const std::string&, const std::string&, const int, const int);
	void RemovePlayer(Player&);
	void DisplayAllPlayers();
	bool HasPlayers();
	void ExportAllPlayersToFile(std::ofstream&);
};
