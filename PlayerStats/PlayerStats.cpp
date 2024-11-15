// Include team header file to be able to access the team class.
#include "Team.h"

using namespace std;

void CreateTeamsFromFile();
void DisplayMainMenu();
void HandleMainMenuSelection();
void AddNewPlayer();
void DeletePlayer(Player&);
void AddNewTeam();
void DeleteTeam(Team&);
void DeleteAllTeamsAndPlayers();
void DisplayPlayerStats(Player&);
void DisplayAllPlayers();
void DisplayAllPlayersInTeam(Team&);
void DisplayAllPlayerStats();
Player& HandlePlayerSelection();
void HandlePlayerStatsUpdate(Player&);
void HandleTeamChange(Player&);
void DisplayAllTeams();
void DisplayAllTeams(Player&);
Team& HandleTeamSelection();
void ExportToFile();
int GetValidChoice(int, int);
bool FinalizeChoice(string);

// Create constants for the files names to prevent typos.
const string INPUT_FILE_NAME = "PlayerStats.txt";
const string OUTPUT_FILE_NAME = "PlayerStatsFile.txt";

// Declare a team vector to hold all team objects.
vector<Team> teamVector;

int main()
{
	// Create teams and players from data from a .txt file.
	CreateTeamsFromFile();

	// Display the menu and prompt user for input.
	DisplayMainMenu();
	HandleMainMenuSelection();

	return 0;
}

void CreateTeamsFromFile()
{
	// Create and open the file using the constant name.
	ifstream inputFile;
	inputFile.open(INPUT_FILE_NAME);

	// Use all information from file to create team and player objects.
	if (inputFile) 
	{
		// Repeat until end of file.
		while (!inputFile.eof())
		{
			string teamName;

			getline(inputFile, teamName, ',');

			// Create new team object passing in the name from the file.
			Team team(teamName);

			// Repeat creating and adding a new player twice as the file has two players per team.
			for (int i = 0; i < 2; i++)
			{
				string name;
				string nationality;
				string region;
				string achievement;
				int yearsPlayed;
				int totalMoneyWon;

				getline(inputFile, name, ',');
				getline(inputFile, nationality, ',');
				getline(inputFile, region, ',');
				getline(inputFile, achievement, ',');

				inputFile >> yearsPlayed >> totalMoneyWon;

				inputFile.ignore();

				// Add playe to the team by passing in player objects parameters.
				team.AddPlayer(name, nationality, region, achievement, yearsPlayed, totalMoneyWon);
			}

			// Push new team to the end of the team vector.
			teamVector.push_back(team);
		}
	}
	else
	{
		// If file cannot be found, let user know.
		cout << "\n\t!! Error opening " << INPUT_FILE_NAME << " !!\n";
		cout << "\t************************************\n";
	}

	// Ensure to close the file.
	inputFile.close();
}

void DisplayMainMenu()
{
	// Displays menu options.
	cout << "\n\tRocket League Player Stats\n";
	cout << "\n\t************************************************\n";
	cout << "\t1 -> \tDisplay All Player Stats" << "\n";
	cout << "\t2 -> \tDisplay Stats For Specific Player" << "\n";
	cout << "\t3 -> \tDisplay All Player Stats From Specific Team" << "\n";
	cout << "\t4 -> \tUpdate Specific Player Stats" << "\n";
	cout << "\t5 -> \tAdd New Player" << "\n";
	cout << "\t6 -> \tDelete Player" << "\n";
	cout << "\t7 -> \tAdd New Team" << "\n";
	cout << "\t8 -> \tDelete Team" << "\n";
	cout << "\t9 -> \tDelete All Teams and Players" << "\n";
	cout << "\t10 ->\tExport Player Stats to File" << "\n";
	cout << "\t11 ->\tQuit" << "\n";
	cout << "\t************************************************" << "\n\n";
}

void HandleMainMenuSelection()
{
	int choice;

	// Get a valid choice between 1 and 11.
	choice = GetValidChoice(1, 11);

	switch (choice)
	{
	case 1: // Display All Player Stats

		system("CLS"); // Clear current display.

		// Handle no teams.
		if (teamVector.empty())
		{
			cout << "\n\t********************\n";
			cout << "\tNo teams exist.\n\n";
			cout << "\t********************\n\n";
		}
		else
		{
			DisplayAllPlayerStats();
		}

		system("Pause"); // Wait for user input to continue.
		system("CLS");

		// Display main menu and promt for input again.
		DisplayMainMenu();
		HandleMainMenuSelection();

		break;
	case 2: // Display Stats For Specific Player

		system("CLS");

		if (teamVector.empty())
		{
			cout << "\n\t********************\n";
			cout << "\tNo teams exist.\n\n";
			cout << "\t********************\n\n";
		}
		else
		{
			// Show all players and pass in the selected player to display their stats.
			DisplayAllPlayers();
			DisplayPlayerStats(HandlePlayerSelection());
		}

		system("Pause");
		system("CLS");

		DisplayMainMenu();
		HandleMainMenuSelection();

		break;
	case 3: // Display All Player Stats From Specific Team

		system("CLS");

		if (teamVector.empty())
		{
			cout << "\n\t********************\n";
			cout << "\tNo teams exist.\n\n";
			cout << "\t********************\n\n";
		}
		else
		{
			// Show all teams and pass in selected team to display all players in it.
			DisplayAllTeams();
			DisplayAllPlayersInTeam(HandleTeamSelection());
		}

		system("Pause");
		system("CLS");

		DisplayMainMenu();
		HandleMainMenuSelection();

		break;
	case 4: // Update Specific Player Stats

		system("CLS");

		if (teamVector.empty())
		{
			cout << "\n\t********************\n";
			cout << "\tNo teams exist.\n\n";
			cout << "\t********************\n\n";
		}
		else
		{
			// Show all players and store a reference to the selected player.
			DisplayAllPlayers();
			Player& player = HandlePlayerSelection();

			// Show the player's current stats and then handle selecting what stat to update.
			DisplayPlayerStats(player);
			HandlePlayerStatsUpdate(player);
		}

		system("Pause");
		system("CLS");

		DisplayMainMenu();
		HandleMainMenuSelection();

		break;
	case 5: // Add New Player

		system("CLS");

		AddNewPlayer();

		system("Pause");
		system("CLS");

		DisplayMainMenu();
		HandleMainMenuSelection();

		break;
	case 6: // Delete Player

		system("CLS");

		if (teamVector.empty())
		{
			cout << "\n\t********************\n";
			cout << "\tNo teams exist.\n\n";
			cout << "\t********************\n\n";
		}
		else
		{
			// Show all players and then pass in selected player to get deleted.
			DisplayAllPlayers();
			DeletePlayer(HandlePlayerSelection());
		}

		system("Pause");
		system("CLS");

		DisplayMainMenu();
		HandleMainMenuSelection();

		break;
	case 7: // Add New Team

		system("CLS");

		AddNewTeam();

		system("Pause");
		system("CLS");

		DisplayMainMenu();
		HandleMainMenuSelection();

		break;
	case 8: // Delete Team

		system("CLS");

		if (teamVector.empty())
		{
			cout << "\n\t********************\n";
			cout << "\tNo teams exist.\n\n";
			cout << "\t********************\n\n";
		}
		else
		{
			// Show all teams and then pass in selected team to get deleted.
			DisplayAllTeams();
			DeleteTeam(HandleTeamSelection());
		}

		system("Pause");
		system("CLS");

		DisplayMainMenu();
		HandleMainMenuSelection();

		break;
	case 9: // Delete All Teams and Players

		system("CLS");

		if (teamVector.empty())
		{
			cout << "\n\t********************\n";
			cout << "\tNo teams exist.\n\n";
			cout << "\t********************\n\n";
		}
		else
		{
			DeleteAllTeamsAndPlayers();
		}

		system("Pause");
		system("CLS");

		DisplayMainMenu();
		HandleMainMenuSelection();

		break;
	case 10: // Export Player Stats to File

		system("CLS");

		if (teamVector.empty())
		{
			cout << "\n\t************************************\n";
			cout << "\tNothing to export. No teams exist.\n\n";
			cout << "\t************************************\n\n";
		}
		else
		{
			// Print out all teams and players onto a .txt file.
			ExportToFile();
		}

		system("Pause");
		system("CLS");

		DisplayMainMenu();
		HandleMainMenuSelection();

		break;
	case 11: // Quit

		cout << "\tQuiting...\n";

		break;
	}
}

void AddNewPlayer()
{
	// Declare all fields of a player object.
	string name;
	string nationality;
	string region;
	string achievement;
	int yearsPlayed;
	int totalMoneyWon;

	cout << "\n\tAdd New Player\n\n";
	cout << "\t************************************************\n\n";

	cin.ignore();

	// Prevent user from creating a player with no name.
	do
	{
		cout << "\tEnter Player Name: ";
		getline(cin, name);

		if (name == "")
		{
			cout << "\tCannot have empty name.\n\n";
		}

	} while (name == "");

	// Check to see if player being added already exists.
	for (Team& team : teamVector)
	{
		for (Player& player : team.GetPlayerVector())
		{
			if (name == player.GetName())
			{
				cout << "\t" << player.GetName() << " already exists.\n\n";

				return;
			}
		}
	}

	cout << "\n";

	// Prevent user from entering nothing.
	do
	{
		cout << "\tEnter Player Nationality: ";
		getline(cin, nationality);

		if (nationality == "")
		{
			cout << "\tCannot have empty nationality.\n\n";
		}

	} while (nationality == "");

	cout << "\n";

	// Prevent user from entering nothing.
	do
	{
		cout << "\tEnter Player Region: ";
		getline(cin, region);

		if (region == "")
		{
			cout << "\tCannot have empty region.\n\n";
		}

	} while (region == "");

	cout << "\n";

	// Prevent user from entering nothing.
	do
	{
		cout << "\tEnter Player achievement: ";
		getline(cin, achievement);

		if (achievement == "")
		{
			cout << "\tCannot have empty achievement.\n\n";
		}

	} while (achievement == "");

	cout << "\n";

	cout << "\tEnter Player Years Played: ";

	// Ensure that this stat gets a positive numeric value assigned to it.
	while (!(cin >> yearsPlayed) || yearsPlayed < 0)
	{
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');

		if (yearsPlayed < 0)
		{
			cout << "\tThis stat cannot have a negative value.\n\n";
			cout << "\tEnter Player's Years Played: ";
		}
		else
		{
			cout << "\tInvalid input! This stat requires a numeric value.\n\n";
			cout << "\tEnter Player Years Played: ";
		}
	}

	cout << "\n";

	cout << "\tEnter Player's Total Money Won: ";

	// Ensure that this stat gets a positive numeric value assigned to it.
	while (!(cin >> totalMoneyWon) || totalMoneyWon < 0)
	{
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');

		if (totalMoneyWon < 0)
		{
			cout << "\tThis stat cannot have a negative value.\n\n";
			cout << "\tEnter Player's Total Money Won: ";
		}
		else
		{
			cout << "\tInvalid input! This stat requires a numeric value.\n\n";
			cout << "\tEnter Player's Total Money Won: ";
		}
	}

	cout << "\n\t************************************************\n\n";

	// If adding player when no teams exist, prompt user to create a team first and add the player to it.
	if (teamVector.empty())
	{
		cout << "\n\tNo teams exist, add new team...\n\n";

		AddNewTeam();

		Team& team = teamVector.at(0);

		team.AddPlayer(name, nationality, region, achievement, yearsPlayed, totalMoneyWon);

		cout << "\n\tPlayer Added!\n\n";

		team.DisplayAllPlayers();
	}
	else // If team(s) already exists, prompt team selection and add the player to it.
	{
		cout << "\n\n\tSelect Team to Add New Player\n";

		DisplayAllTeams();

		Team& team = HandleTeamSelection();

		team.AddPlayer(name, nationality, region, achievement, yearsPlayed, totalMoneyWon);

		cout << "\n\tPlayer Added!\n\n";

		team.DisplayAllPlayers();
	}
}

void DeletePlayer(Player& player)
{
	string playerName = player.GetName();

	// Ensure the user really wants to delete the selected player.
	if (!FinalizeChoice("Are you sure you want to delete " + playerName + "?"))
	{
		cout << "\n";

		return;
	}

	// Cycle through each team and each player on that team to find the player and remove it.
	for (Team& team : teamVector)
	{
		for (Player& currentPlayer : team.GetPlayerVector())
		{
			if (currentPlayer == player)
			{
				team.RemovePlayer(player);
			}
		}
	}

	cout << "\t" << playerName << " deleted.\n\n";
}

void AddNewTeam()
{
	cout << "\n\tAdd New Team\n\n";
	cout << "\t************************************************\n\n";

	cin.ignore();

	string teamName;

	// Prevent user from creating a team with no name.
	do
	{
		cout << "\tEnter Team Name: ";
		getline(cin, teamName);

		if (teamName == "")
		{
			cout << "\tCannot have empty team name.\n\n";
		}

	} while (teamName == "");

	// Cycle through each team and ensure it doesn't already exist.
	for (Team& team : teamVector)
	{
		if (team.GetTeamName() == teamName)
		{
			cout << "\t" << team.GetTeamName() << " already exists.\n\n";

			return;
		}
	}

	// Construct new team object in the vector by passing constructor parmeter.
	teamVector.emplace_back(teamName);

	cout << "\tNew team added!\n\n";
}

void DeleteTeam(Team& team)
{
	string teamName = team.GetTeamName();

	// Ensure the user really wants to delete the selected team.
	if (!FinalizeChoice("Are you sure you want to delete " + teamName + "?"))
	{
		cout << "\n";

		return;
	}

	// Cycle through each team to find the team the user wants to remove and remove it.
	for (Team& currentTeam : teamVector)
	{
		if (currentTeam == team)
		{
			teamVector.erase(remove(teamVector.begin(), teamVector.end(), team), teamVector.end());
		}
	}

	cout << "\t" << teamName << " deleted.\n\n";
}

void DeleteAllTeamsAndPlayers()
{
	// Ensure the user really wants to delete all teams and players.
	if (!FinalizeChoice("Are you sure you want to delete all players and teams?"))
	{
		cout << "\n";

		return;
	}

	cout << "\n\t************************************\n";
	cout << "\tDeleting All Teams and Players...\n\n";

	// Remove all team objects from team vector.
	teamVector.clear();

	cout << "\tAll Teams and Players Deleted.\n\n";
	cout << "\t************************************\n\n";
}

void DisplayPlayerStats(Player& player)
{
	cout << "\n\n";

	// Call the function to display the player's stats.
	player.DisplayStats();
}

void DisplayAllPlayers()
{
	cout << "\n\tAll Players\n";

	cout << "\n\t****************************\n";

	int playerCount = 1;

	// Display all players in the program with a selection number.
	for (Team& team : teamVector)
	{
		for (Player& player : team.GetPlayerVector())
		{
			player.SetSelectionNumber(playerCount);

			cout << "\t" << playerCount << " -> \t" << player.GetName() << "\n";

			playerCount++;
		}
	}

	cout << "\t****************************\n\n";
}

void DisplayAllPlayersInTeam(Team& team)
{
	// Handle empty team case.
	if (!team.HasPlayers())
	{
		cout << "\tTeam has no players.\n\n";

		return;
	}

	cout << "\n\n";

	// Show all players on this team object.
	team.DisplayAllPlayers();
}

void DisplayAllPlayerStats()
{
	cout << "\n\tAll Player Stats\n";

	// Show all teams and players on each team.
	for (Team& team : teamVector)
	{
		cout << "\n\t****************************************************************************************\n";
		cout << "\tTeam: " << team.GetTeamName() << "\n\n";

		team.DisplayAllPlayers();

		cout << "\t****************************************************************************************\n\n\n\n\n\n";
	}
}

Player& HandlePlayerSelection()
{
	int choice;

	// Prompt user to input player selection number and keep prompting until valid number is input.
	do
	{
		cout << "\tEnter the corresponding number for the player: ";
		cin >> choice;

		// If user inputs text instead of digits, clear input buffer and prompt user to enter a valid menu option number.
		if (cin.fail())
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');

			cout << "\tInvalid input! Please enter a valid menu player number.\n\n";
		}
		else
		{
			// Cycle through each player in each team to match player's selection number and return the player if found.
			for (Team& team : teamVector)
			{
				for (Player& player : team.GetPlayerVector())
				{
					if (player.GetSelectionNumber() == choice)
					{
						return player;
					}
				}
			}

			cout << "\tPlayer not found.\n\n";
		}

	} while (true);
}

void HandlePlayerStatsUpdate(Player& player)
{
	// Show option menu.
	cout << "\n\n\tSelect Player Stat to Update\n\n";
	cout << "\t****************************\n";
	cout << "\t1 -> \tName" << "\n";
	cout << "\t2 -> \tTeam" << "\n";
	cout << "\t3 -> \tNationality" << "\n";
	cout << "\t4 -> \tRegion" << "\n";
	cout << "\t5 -> \tAchievement" << "\n";
	cout << "\t6 -> \tYears Played" << "\n";
	cout << "\t7 -> \tTotal Money Won" << "\n";
	cout << "\t****************************" << "\n\n";

	int choice;

	// Validate choice between 1 and 7.
	choice = GetValidChoice(1, 7);

	cin.ignore();

	// Declare all fields of the player objects that can be modified to store new value.
	string name;
	string nationality;
	string region;
	string achievement;
	int yearsPlayed;
	int totalMoneyWon;

	switch (choice)
	{
	case 1: // Change name.

		cout << "\n\tEnter new name: ";
		getline(cin, name);

		player.SetName(name);

		break;
	case 2: // Change team.

		cout << "\n";

		// Pass in a player reference to tag the team that the player is already on.
		DisplayAllTeams(player);
		HandleTeamChange(player);

		break;
	case 3: // Change nationality.

		cout << "\n\tEnter new nationality: ";
		getline(cin, nationality);

		player.SetNationality(nationality);

		break;
	case 4: // Change region.

		cout << "\n\tEnter new region: ";
		getline(cin, region);

		player.SetRegion(region);

		break;
	case 5: // Change achievement.

		cout << "\n\tEnter new achievement: ";
		getline(cin, achievement);

		player.SetAchievement(achievement);

		break;
	case 6: // Change years played.

		cout << "\n\tEnter new years played: ";

		// Ensure this stats is a positive number.
		while (!(cin >> yearsPlayed) || yearsPlayed < 0)
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');

			if (yearsPlayed < 0)
			{
				cout << "\tThis stat cannot have a negative value.\n\n";
				cout << "\tEnter Player's Years Played: ";
			}
			else
			{
				cout << "\tInvalid input! This stat requires a numeric value.\n\n";
				cout << "\tEnter Player Years Played: ";
			}
		}

		player.SetYearsPlayed(yearsPlayed);

		break;
	case 7: // Change total money won.

		cout << "\n\tEnter new total money won: ";

		// Ensure this stats is a positive number.
		while (!(cin >> totalMoneyWon) || totalMoneyWon < 0)
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');

			if (totalMoneyWon < 0)
			{
				cout << "\tThis stat cannot have a negative value.\n\n";
				cout << "\tEnter Player's Total Money Won: ";
			}
			else
			{
				cout << "\tInvalid input! This stat requires a numeric value.\n\n";
				cout << "\tEnter Player's Total Money Won: ";
			}
		}

		player.SetTotalMoneyWon(totalMoneyWon);

		break;
	}
}

void HandleTeamChange(Player& player)
{
	// Store reference to selected new team.
	Team& newTeam = HandleTeamSelection();

	// Ensure that the user cannot add the player to the same team.
	for (Team& team : teamVector)
	{
		if (player.GetTeamName() == newTeam.GetTeamName())
		{
			cout << "\tCannot add to same team.\n\n";

			return;
		}
	}

	// Copy the player to the new team.
	newTeam.AddPlayer(player.GetName(), player.GetNationality(), player.GetRegion(), player.GetAchievement(), player.GetYearsPlayed(), player.GetTotalMoneyWon());

	// Cycle through each team and remove the player from the old team.
	for (Team& team : teamVector)
	{
		if (player.GetTeamName() == team.GetTeamName())
		{
			team.RemovePlayer(player);
		}
	}

	cout << "\tNew team set.\n\n";
}

void DisplayAllTeams()
{
	cout << "\n\tAll Teams\n";

	int optionNumber = 1;

	cout << "\n\t****************************\n";

	// Shows all team with selection number.
	for (Team& team : teamVector)
	{
		cout << "\t" << optionNumber << " -> \t" << team.GetTeamName() << "\n";

		optionNumber++;
	}

	cout << "\t****************************\n\n";
}

void DisplayAllTeams(Player& player) // Overloaded function for tagging the team the player is already on.
{
	cout << "\n\tAll Teams\n";

	int optionNumber = 1;

	cout << "\n\t****************************\n";

	for (Team& team : teamVector)
	{
		// Check if the current team is the same as the current team the player is on.
		if (player.GetTeamName() == team.GetTeamName())
		{
			// Add a tag to show that the player is already on this team.
			cout << "\t" << optionNumber << " -> \t" << team.GetTeamName() << " (Current Team)\n";
		}
		else
		{
			cout << "\t" << optionNumber << " -> \t" << team.GetTeamName() << "\n";
		}

		optionNumber++;
	}

	cout << "\t****************************\n\n";
}

Team& HandleTeamSelection()
{
	int choice;

	// Get a valid choice between 1 and the amount of teams that exist.
	choice = GetValidChoice(1, teamVector.size());

	// Return the team reference ensuring to subtract by 1 to pass in the proper index.
	return teamVector.at(choice - 1);
}

void ExportToFile() // The same as DisplayAllPlayerStats() functions except writing all data to a .txt file.
{
	// Create and open the output file.
	ofstream outputFile;
	outputFile.open(OUTPUT_FILE_NAME);

	cout << "\n\t********************************************************************************\n";
	cout << "\tExporting...\n\n";

	// Cycle through each team and call the function to write player stats to output file.
	for (Team& team : teamVector)
	{
		outputFile << "\n\t************************************************************************************\n";
		outputFile << "\tTeam: " << team.GetTeamName() << "\n\n";

		// Print all player stats to the output file passed in.
		team.ExportAllPlayersToFile(outputFile);

		outputFile << "\t************************************************************************************\n\n\n\n";
	}

	// Ensure closing the file.
	outputFile.close();

	// Telling user where to find the file.
	cout << "\tCheck \"" << OUTPUT_FILE_NAME << "\" in project solution folder for exported stats.\n\n";
	cout << "\t********************************************************************************\n\n";
}

int GetValidChoice(int minimum, int maximum)
{
	int choice;

	// Loop prompting the user for a valid menu option between the minimum and maximum value passed in.
	do
	{
		cout << "\tEnter the corresponding number for the menu option: ";
		cin >> choice;

		// Clear buffer if text was input and prompt user again.
		if (cin.fail())
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');

			cout << "\tInvalid input! Please enter a valid menu option number.\n\n";

			choice = -1;
		}
		else if (choice < minimum || choice > maximum)
		{
			cout << "\tInvalid choice! Please enter a number between " << minimum << " and " << maximum << ".\n\n";
		}

	} while (choice < minimum || choice > maximum);

	// Return choice when valid.
	return choice;
}

bool FinalizeChoice(string confirmationText)
{
	// Display confirmation of action.
	cout << "\n\t!! " << confirmationText << " !!\n";
	cout << "\n\t********************************************************************\n";
	cout << "\t1 -> \tNo\n";
	cout << "\t2 -> \tYes\n";
	cout << "\t********************************************************************\n\n";

	int choice;

	// Get valid choice between 1 and 2.
	choice = GetValidChoice(1, 2);

	// If choice is no return false.
	if (choice == 1)
	{
		return false;
	}

	// Return true if yes.
	return true;
}
