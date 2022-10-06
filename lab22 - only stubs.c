#include <stdio.h>
#define NUM_GAMES 1075


/** 
 * @brief normalizes a value to a new range - for example, if you normalized a percentage of 0.67 to a range between 0 and 20 it would return 13.4.
 * @param valueToNormalize the value you want to normalize
 * @param initialRangeMin the minimum value for the range you want to normalize, for example if the value is currently a percentage then this would be 0.0.
 * @param initialRangeMax the minimum value for the range you want to normalize, for example if the value is currently a percentage then this would be 1.0 (or 100.0).
 * @param normalizedMin the minimum value for the new range you are normalizing to.  for example, if you want the normalized values to be between 3.0 and 5.0, this would be 3.0
 * @param normalizedMax the maximum value for the new range you are normalizing to.  for example, if you want the normalized values to be between 3.0 and 5.0, this would be 5.0
 * @return the new normalized value
 */ 
double normalizeValue(double valueToNormalize, double initialRangeMin, double initialRangeMax, double normalizedMin, double normalizedMax){
    return (valueToNormalize - initialRangeMin)/(initialRangeMax - initialRangeMin)*(normalizedMax-normalizedMin) + normalizedMin;
}

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
 * @param ptsHomes the ptsHome values for all games
 * @param ptsAways the ptsAway values for all games
 * @param len the size of all of the array parameters
 * @return the difference in point differentials per game between the home and away team
 * The differential will be positive if the home team has a greater point differential, and vice versa
 */ 
double pointDifferentialPerGameOneTeam(int teamID, int* homeIDs, int* awayIDs, int* ptsHomes, int* ptsAways, int len){

    return 0.0;
}

/** 
 * @brief compare who won when the two teams we care about played each other previously
 * @param homeID the home team for the game being analyzed
 * @param awayID the away team for the game being analyzed
 * @param homeIDs the homeIDs for all games
 * @param awayIDs the awayIDs for all games
 * @param gameResults results of all games, 1 if home team won, and 0 otherwise
 * @param len the size of all of the array parameters
 * @return the win/loss differential - The differential will be positive if the home team has won more, and vice versa.
 * For example, if the home team has won 2 more games, then return 2.  if the away team has won 1 more game then return -1.
 */ 
int headToHeadWL(int homeID, int awayID, int* homeIDs, int* awayIDs, int* gameResults, int len){
    
    return 0;
}

/** 
 * @brief get the shooting effectiveness of a team - this stat combines averages of field goal percentage, 3-point percentage, and free throw percentage
 * @param homeID the team to get the shooting effectiveness for
 * @param homeIDs the homeIDs for all games
 * @param awayIDs the awayIDs for all games
 * @param homeFgPcts the field goal percentages for the home teams for all games
 * @param awayFgPcts the field goal percentages for the away teams for all games
 * @param homeFg3Pcts the 3-point field goal percentages for the home teams for all games
 * @param awayFg3Pcts the 3-point field goal percentages for the away teams for all games
 * @param homeFtPcts the free throw percentages for the home teams for all games
 * @param homeFtPcts the free throw percentages for the away teams for all games
 * @param len the size of all of the array parameters
 * @return the shooting effectiveness of the team in question - 
 * The return value should be the result of the function getShootingEffectivenessFromAverages() given the team's fgPct, fg3Pct, and ftPct across all games
 */ 
double shootingEffectivenessOneTeam(int teamID, int* homeIDs, int* awayIDs, double* homeFgPcts, double* awayFgPcts, double* homeFg3Pcts, double* awayFg3Pcts, double* homeFtPcts, double* awayFtPcts, int len){
    
    return 0.0;
}

/** 
 * @brief compare rebounds per game for two teams
 * @param homeID the home team for the game being analyzed
 * @param awayID the away team for the game being analyzed
 * @param homeIDs the homeIDs for all games
 * @param awayIDs the awayIDs for all games
 * @param rbsHomes the rbsHome values for all games
 * @param rbsAways the rbsAway values for all games
 * @param len the size of all of the array parameters
 * @return the difference in rebounds per game between the home and away team
 * The differential will be positive if the home team averages more rebounds per game, and vice versa
 */ 
double reboundsPerGameComparison(int homeID, int awayID, int* homeIDs, int* awayIDs, int* reboundsHomes, int* reboundsAways, int len){
    
    return 0.0;
}

/** 
 * @brief compare assists per game for two teams
 * @param homeID the home team for the game being analyzed
 * @param awayID the away team for the game being analyzed
 * @param homeIDs the homeIDs for all games
 * @param awayIDs the awayIDs for all games
 * @param assistsHomes the assistsHome values for all games
 * @param assistsAways the assistsAway values for all games
 * @param len the size of all of the array parameters
 * @return the difference in assists per game between the home and away team
 * The differential will be positive if the home team averages more assists per game, and vice versa
 */ 
double assistsPerGameComparison(int homeID, int awayID, int* homeIDs, int* awayIDs, int* assistsHomes, int* assistsAways, int len){


    return 0.0;
}

/** 
 * @brief takes the 5 calculated comparison values, normalizes them to ranges between -20.0 and 20.0, and adds them all up to return a final comparison
 * @param pointDiffComparison the comparison in point differential between the two teams
 * @param h2hResult the result of head-to-head games between the two teams
 * @param shootingDifferential the shooting differential between the two teams
 * @param reboundDifferential the differential in rebounds per game between the two teams
 * @param assistDifferential the differential in assists per game between the two teams
 * @return the overall normalized comparison (which will range from -100.0 to 100.0)
 */ 
double teamComparison(double pointDiffComparison, int h2hResult, double shootingDifferential, double reboundDifferential, double assistDifferential){

    return 0.0;
}


int main(){

    return 0;
}