using namespace std;

#include "Team.h"

Team::Team()
{
	// Set default field value.
	this->teamName = "Team";
}

Team::Team(const string& teamName)
{
	// Construct team object.
	this->teamName = teamName;
}

bool Team::operator==(const Team& otherTeam)
{
	// Return true if other team name is equal to this team name.
	return teamName == otherTeam.teamName;
}

string Team::GetTeamName()
{
	return teamName;
}

vector<Player>& Team::GetPlayerVector()
{
	return playerVector;
}

void Team::SetTeamName(const string& teamName)
{
	this->teamName = teamName;
}

void Team::AddPlayer(const string& name, const string& nationality, const string& region, const string& achievement, const int yearsPlayed, const int totalMoneyWon)
{
	// Construct new player object inside the vector by passing in constructor parameters.
	playerVector.emplace_back(name, teamName, nationality, region, achievement, yearsPlayed, totalMoneyWon);
}

void Team::RemovePlayer(Player& player)
{
	// Cycle through each player in player vector and remove player passed in the function.
	for (Player& currentPlayer : playerVector)
	{
		if (currentPlayer == player)
		{
			playerVector.erase(remove(playerVector.begin(), playerVector.end(), player), playerVector.end());
		}
	}
}

void Team::DisplayAllPlayers()
{
	// Handle if the team has no players.
	if (!HasPlayers())
	{
		cout << "\t\tNo players on team.\n\n";

		return;
	}

	// Show all player stats of players in team.
	for (Player& player : playerVector)
	{
		player.DisplayStats();
	}
}

bool Team::HasPlayers()
{
	// Return true is the player vector is not empty.
	return !playerVector.empty();
}

void Team::ExportAllPlayersToFile(ofstream& outputFile)
{
	// Make all players in player vector write their stats to the output file passed in.
	for (Player& player : playerVector)
	{
		player.WriteStatsToFile(outputFile);
	}
}
