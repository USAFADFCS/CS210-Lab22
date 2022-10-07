#include <stdio.h>
#define NUM_GAMES 1075


/** 
 * @brief combine field goal percentage 3-pt percentage, and free throw percentage into one shooting stat
 * @param fgPct the team's field goal percentage
 * @param threePtPct the team's 3-point field goal percentage
 * @param ftPct the team's free throw percentage
 * @return the team's shooting effectiveness - this will be a number between 0 and 1.
 */ 
double getShootingEffectivenessFromAverages(double fgPct, double fg3Pct, double ftPct){
    return 0.3 * fgPct + 0.5 * fg3Pct + 0.2 * ftPct;
}

/** 
 * @brief get point differential per game for one team
 * @param teamID the team being analyzed
 * @param homeIDs the homeIDs for all games
 * @param awayIDs the awayIDs for all games
 * @param homeScores the ptsHome values for all games
 * @param awayScores the ptsAway values for all games
 * @return the point differential per game across all game for the team
 * The differential will be positive if the team has gotten more points per game than their opponents, and vice versa
 */ 
double pointDifferentialPerGameOneTeam(int teamID, int* homeIDs, int* awayIDs, int* homeScores, int* awayScores){
    
    return 0.0;
}

/** 
 * @brief compare who won when the two teams we care about played each other previously
 * @param homeID the home team for the game being analyzed
 * @param awayID the away team for the game being analyzed
 * @param homeIDs the homeIDs for all games
 * @param awayIDs the awayIDs for all games
 * @param gameResults results of all games, 1 if home team won, and 0 otherwise
 * @return the win/loss differential - The differential will be positive if the home team has won more, and vice versa.
 * For example, if the home team has won 2 more games, then return 2.  if the away team has won 1 more game then return -1.
 */ 
int headToHeadWL(int homeID, int awayID, int* homeIDs, int* awayIDs, int* gameResults){
    
    return 0;
}

/** 
 * @brief get the shooting effectiveness of a team - this stat combines averages of field goal percentage, 3-point percentage, and free throw percentage
 * @param teamID the team to get the shooting effectiveness for
 * @param homeIDs the homeIDs for all games
 * @param awayIDs the awayIDs for all games
 * @param homeFgPcts the field goal percentages for the home teams for all games
 * @param awayFgPcts the field goal percentages for the away teams for all games
 * @param homeFg3Pcts the 3-point field goal percentages for the home teams for all games
 * @param awayFg3Pcts the 3-point field goal percentages for the away teams for all games
 * @param homeFtPcts the free throw percentages for the home teams for all games
 * @param awayFtPcts the free throw percentages for the away teams for all games
 * @return the shooting effectiveness of the team in question - 
 * The return value should be the result of the function getShootingEffectivenessFromAverages() given the team's fgPct, fg3Pct, and ftPct across all games
 */ 
double shootingEffectivenessOneTeam(int teamID, int* homeIDs, int* awayIDs, double* homeFgPcts, double* awayFgPcts, double* homeFg3Pcts, double* awayFg3Pcts, double* homeFtPcts, double* awayFtPcts){
    
    return 0.0;
}

/** 
 * @brief compare rebounds per game for two teams
 * @param homeID the home team for the game being analyzed
 * @param awayID the away team for the game being analyzed
 * @param homeIDs the homeIDs for all games
 * @param awayIDs the awayIDs for all games
 * @param homeRebounds the homeRebound values for all games
 * @param awayRebounds the awayRebound values for all games
 * @return the difference in rebounds per game between the home and away team
 * The differential will be positive if the home team averages more rebounds per game, and vice versa
 */ 
double reboundsPerGameComparison(int homeID, int awayID, int* homeIDs, int* awayIDs, int* homeRebounds, int* awayRebounds){
    
    return 0.0;
}

/** 
 * @brief compare assists per game for two teams
 * @param homeID the home team for the game being analyzed
 * @param awayID the away team for the game being analyzed
 * @param homeIDs the homeIDs for all games
 * @param awayIDs the awayIDs for all games
 * @param homeAssists the homeAssist values for all games
 * @param awayAssists the awayAssist values for all games
 * @return the difference in assists per game between the home and away team
 * The differential will be positive if the home team averages more assists per game, and vice versa
 */ 
double assistsPerGameComparison(int homeID, int awayID, int* homeIDs, int* awayIDs, int* homeAssists, int* awayAssists){
    
    return 0.0;
}


int main(){

    //These are the IDs for the teams for the game we are predicting
    int homeIDForPrediction = 41;
    int awayIDForPrediction = 39; 

    //Create blank parallel arrays that will be filled with data
    int homeIDs[NUM_GAMES];
    int awayIDs[NUM_GAMES];
    int homeScores[NUM_GAMES];
    int awayScores[NUM_GAMES];
    int homeWins[NUM_GAMES];
    double homeFgPcts[NUM_GAMES];
    double homeFg3Pcts[NUM_GAMES];
    double homeFtPcts[NUM_GAMES];
    double awayFgPcts[NUM_GAMES];
    double awayFg3Pcts[NUM_GAMES];
    double awayFtPcts[NUM_GAMES];
    int homeRebounds[NUM_GAMES];
    int awayRebounds[NUM_GAMES];
    int homeAssists[NUM_GAMES];
    int awayAssists[NUM_GAMES];

    //This is the final output that is required.  You will need to change prediction an teamPredictedToWin to the correct values.
    double prediction = 0.0;
    int teamPredictedToWin = 0;
    printf("The final output is %.2lf, which means team %d is predicted to win the game.\n",prediction,teamPredictedToWin);
  
    return 0;
}




