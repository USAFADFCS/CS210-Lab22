/** 
 * @brief compare who won when the two teams we care about played each other previously
 * @param team1 the ID for team1 for the game being analyzed
 * @param team2 the ID for team2 for the game being analyzed
 * @param homeIDs the homeIDs for all games
 * @param awayIDs the awayIDs for all games
 * @param gameResults results of all games, 1 if home team won, and 0 otherwise
 * @param num_games the number of games being analyzed (the length of the parallel arrays)
 * @return the win/loss differential - The differential will be positive if the team 1 has won more, and vice versa.
 * For example, if team 1 has won 2 more games, then return 2.  if the team 2 has won 1 more game then return -1.
 */ 
int headToHeadWL(int team1, int team2, int* homeIDs, int* awayIDs, int* gameResults, int num_games){
    int team1Counter = 0;
    int team2Counter = 0;

    for (int i = 0; i < num_games; ++i) {
        if ((gameResults[i] == 1) && (homeIDs[i] == team1) && (awayIDs[i] == team2)) {
            team1Counter++;
        }
        else if ((gameResults[i] == 0) && (homeIDs[i] == team1) && (awayIDs[i] == team2)) {
            team2Counter++;
        }
        else if ((gameResults[i] == 1) && (homeIDs[i] == team2) && (awayIDs[i] == team1)) {
            team2Counter++;
        }
        else if ((gameResults[i] == 0) && (homeIDs[i] == team2) && (awayIDs[i] == team1)) {
            team1Counter++;
        }
    }
    return team1Counter - team2Counter;
}
