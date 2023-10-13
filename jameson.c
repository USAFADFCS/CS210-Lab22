/** 
 * @brief compare rebounds per game for two teams
 * @param team1 the ID for team1 for the game being analyzed
 * @param team2 the ID for team2 for the game being analyzed
 * @param homeIDs the homeIDs for all games
 * @param awayIDs the awayIDs for all games
 * @param homeRebounds the homeRebound values for all games
 * @param awayRebounds the awayRebound values for all games
 * @param num_games the number of games being analyzed (the length of the parallel arrays)
 * @return the difference in rebounds per game between the home and away team
 * The differential will be positive if team 1 averages more rebounds per game, and vice versa
 */ 
double reboundsPerGameComparison(int team1, int team2, int* homeIDs, int* awayIDs, int* homeRebounds, int* awayRebounds, int num_games){
    double avg1Rbds = 0;
    double avg2Rbds = 0;
    int sum1Rbds = 0;
    int sum2Rbds = 0;
    int num1Games = 0;
    int num2Games = 0;

    for (int i = 0; i < num_games; i++){
        if (team1 == homeIDs[i]){
            sum1Rbds += homeRebounds[i];
            num1Games++;
        }
        else if(team1 == awayIDs[i]){
            sum1Rbds += awayRebounds[i];
            num1Games++;
        }
        if (team2 == homeIDs[i]){
            sum2Rbds += homeRebounds[i];
            num2Games++;
        }
        else if(team2 == awayIDs[i]){
            sum2Rbds += awayRebounds[i];
            num2Games++;
        }

    }

    avg1Rbds = (double) sum1Rbds / (double) num1Games;
    avg2Rbds = (double) sum2Rbds / (double) num2Games;
    
    //diff avg rbds
    return avg1Rbds - avg2Rbds;
}
