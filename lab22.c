#include <stdio.h>

//For now, you'll test your function using the 10 games listed in main().  This will need to change to 1075 when you read from the file.
#define NUM_GAMES 10

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
 * @param num_games the number of games being analyzed (the length of the parallel arrays)
 * @return the point differential per game across all game for the team
 * The differential will be positive if the team has gotten more points per game than their opponents, and vice versa
 */ 
double pointDifferentialPerGameOneTeam(int teamID, int* homeIDs, int* awayIDs, int* homeScores, int* awayScores, int num_games){
    int pointDiff = 0;
    int gamesCounted = 0;

    for(int i=0;i<num_games;i++){
        if (teamID == homeIDs[i]){
            pointDiff += (homeScores[i]-awayScores[i]);
            gamesCounted++;
        }else if (teamID == awayIDs[i]){
            pointDiff += (awayScores[i]-homeScores[i]);
            gamesCounted++;
        }
    }

    double diffPerGame = (double)pointDiff/(double)gamesCounted;

    return diffPerGame;
}

/** 
 * @brief compare who won when the two teams we care about played each other previously
 * @param homeID the home team for the game being analyzed
 * @param awayID the away team for the game being analyzed
 * @param homeIDs the homeIDs for all games
 * @param awayIDs the awayIDs for all games
 * @param gameResults results of all games, 1 if home team won, and 0 otherwise
 * @param num_games the number of games being analyzed (the length of the parallel arrays)
 * @return the win/loss differential - The differential will be positive if the home team has won more, and vice versa.
 * For example, if the home team has won 2 more games, then return 2.  if the away team has won 1 more game then return -1.
 */ 
int headToHeadWL(int homeID, int awayID, int* homeIDs, int* awayIDs, int* gameResults, int num_games){
    // Fagin should write this
    return 0.0;
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
 * @param num_games the number of games being analyzed (the length of the parallel arrays)
 * @return the shooting effectiveness of the team in question - 
 * The return value should be the result of the function getShootingEffectivenessFromAverages() given the team's fgPct, fg3Pct, and ftPct across all games
 */ 
double shootingEffectivenessOneTeam(int teamID, int* homeIDs, int* awayIDs, double* homeFgPcts, double* awayFgPcts, double* homeFg3Pcts, double* awayFg3Pcts, double* homeFtPcts, double* awayFtPcts, int num_games){
    double fgSum = 0;
    double fg3Sum = 0;
    double ftSum = 0;
    int gamesCounted = 0;

    for(int i=0;i<num_games;i++){
        if (teamID == homeIDs[i]){
            fgSum += homeFgPcts[i];
            fg3Sum += homeFg3Pcts[i];
            ftSum += homeFtPcts[i];
            gamesCounted++;
        }else if (teamID == awayIDs[i]){
            fgSum += awayFgPcts[i];
            fg3Sum += awayFg3Pcts[i];
            ftSum += awayFtPcts[i];
            gamesCounted++;
        }
    }

    double avgFgPct = fgSum/(double)gamesCounted;
    double avgFg3Pct = fg3Sum/(double)gamesCounted;
    double avgFtPct = ftSum/(double)gamesCounted;

    return getShootingEffectivenessFromAverages(avgFgPct,avgFg3Pct,avgFtPct);
}

/** 
 * @brief compare rebounds per game for two teams
 * @param homeID the home team for the game being analyzed
 * @param awayID the away team for the game being analyzed
 * @param homeIDs the homeIDs for all games
 * @param awayIDs the awayIDs for all games
 * @param homeRebounds the homeRebound values for all games
 * @param awayRebounds the awayRebound values for all games
 * @param num_games the number of games being analyzed (the length of the parallel arrays)
 * @return the difference in rebounds per game between the home and away team
 * The differential will be positive if the home team averages more rebounds per game, and vice versa
 */ 
double reboundsPerGameComparison(int homeID, int awayID, int* homeIDs, int* awayIDs, int* homeRebounds, int* awayRebounds, int num_games){
    
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
 * @param num_games the number of games being analyzed (the length of the parallel arrays)
 * @return the difference in assists per game between the home and away team
 * The differential will be positive if the home team averages more assists per game, and vice versa
 */ 

double assistsPerGameComparison(int homeID, int awayID, int* homeIDs, int* awayIDs, int* homeAssists, int* awayAssists){
    
    return 0.0;
}


int main(){

    //These are the IDs for the teams for the game we are predicting
    int homeID = 48;
    int awayID = 39;

    // These parallel arrays contain SOME game information to test your function
    // Later the lab, you will replace this with the contents of the file games.csv
    int homeIDs[NUM_GAMES]        = {48,    37,    38,    48,    45,    38,    51,    61,    59,    39};
    int awayIDs[NUM_GAMES]        = {50,    46,    65,    39,    42,    63,    48,    65,    58,    66};
    int homeScores[NUM_GAMES]     = {104,   112,   114,   117,   100,   120,   107,   106,   112,   98};
    int awayScores[NUM_GAMES]     = {113,   106,   103,   105,   113,   107,   113,   108,   115,   119};
    int homeAssists[NUM_GAMES]    = {23,    28,    23,    28,    29,    33,    24,    12,    28,    21};
    int awayAssists[NUM_GAMES]    = {21,    22,    21,    25,    20,    24,    27,    25,    26,    32};
    int homeRebounds[NUM_GAMES]   = {53,    47,    47,    42,    39,    51,    30,    41,    40,    37};
    int awayRebounds[NUM_GAMES]   = {46,    36,    42,    40,    47,    44,    35,    42,    49,    45};
    int homeTeamWins[NUM_GAMES]   = {0,     1,     1,     1,     0,     1,     0,     0,     0,     0};
    double homeFgPcts[NUM_GAMES]  = {0.398, 0.478, 0.467, 0.477, 0.477, 0.517, 0.47,  0.434, 0.495, 0.468};
    double awayFgPcts[NUM_GAMES]  = {0.422, 0.488, 0.422, 0.443, 0.455, 0.424, 0.519, 0.452, 0.459, 0.506};
    double homeFg3Pcts[NUM_GAMES] = {0.333, 0.29,  0.188, 0.314, 0.2,   0.432, 0.387, 0.269, 0.375, 0.323};
    double awayFg3Pcts[NUM_GAMES] = {0.357, 0.375, 0.294, 0.32,  0.306, 0.325, 0.333, 0.297, 0.313, 0.447};
    double homeFtPcts[NUM_GAMES]  = {0.76,  0.895, 0.8,   0.889, 0.632, 0.8,   0.773, 0.75,  0.5,   0.667};
    double awayFtPcts[NUM_GAMES]  = {0.875, 0.824, 0.958, 0.931, 0.786, 0.769, 0.821, 0.75,  0.844, 0.727};

    // ----------------------------------------------------------------------------------
    // Step 1:  Read the the contents of games.csv into the parallel arrays above
    // ----------------------------------------------------------------------------------
    

    // ----------------------------------------------------------------------------------
    // Step 2:  Call the 5 functions and gather their data
    // ----------------------------------------------------------------------------------
    // Call pointDifferentialPerGameOneTeam 2x – once for the home team and once for the away time

    // Subtract the home team from the away team to get the pointDifferentialStat

    // Call shootingEffectivenessOneTeam 2x – once for the home team and once for the away time
    
    // Subtract the home team from the away team to get the shootingDifferentialStat

    // Call reboundsPerGameComparison once to get the reboundingStat

    // Call assistsPerGameComparison once to get the assistStat
   
    
    // Call headToHeadWL once to get the headToHeadStat


    // ----------------------------------------------------------------------------------
    // Step 3:  Use the following formula to predict the winner
    // (pointDifferentialStat * 0.6) + headToHeadStat + (shootingDifferentialStat * 120) + reboundingStat + (assistStat * 0.75)
    // ----------------------------------------------------------------------------------


    // ----------------------------------------------------------------------------------
    // Print out the output
    // ----------------------------------------------------------------------------------
    // If the value is > 0, then the home team is predicted to win; if the value is <= 0, then the away team is predicted to win
  
    return 0;

}