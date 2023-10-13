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
    int num1Games = 0;
    int num2Games = 0;
    int sum1Rbds = 0;
    int sum2Rbds = 0;

    for (int i = 0; i < num_games; i++){
        if(homeIDs[i] == team1){
            num1Games++;
            sum1Rbds += homeRebounds[i];
        }
        else if(awayIDs[i] == team1){
            num1Games++;
            sum1Rbds += awayRebounds[i];
        }
        if(homeIDs[i] == team2){
            num2Games++;
            sum2Rbds += homeRebounds[i];
        }
        else if(awayIDs[i] == team2){
            num2Games++;
            sum2Rbds += awayRebounds[i];
        }


    }

    avg1Rbds = (double) sum1Rbds / (double) num1Games;
    avg2Rbds = (double) sum2Rbds / (double) num2Games;

    //diff avg rbds
    return avg1Rbds - avg2Rbds;
}
