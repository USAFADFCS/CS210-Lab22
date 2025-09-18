#include <stdio.h>

//For now, you'll test your function using the 10 games listed in main().  This will need to change to 1075 when you read from the file.
#define NUM_GAMES 1075
#include "lab22.h"

int main(){
    //These are the IDs for the teams for the game we are predicting
    int team1 = 48;
    int team2 = 39;

    // ----------------------------------------------------------------------------------
    // Step 1:  Read the the contents of games.csv into the parallel arrays above
    // ----------------------------------------------------------------------------------

    FILE* inFile = NULL;
    inFile = fopen("games.csv","r");
    if(inFile == NULL){
        printf("Could not open file myfile.txt.\n");
        return -1;
    }

    //Ignore the first line - the line with headers
    fscanf(inFile, "%*[^\n]\n");
    

    // These parallel arrays contain SOME game information to test your function
    // Later the lab, you will replace this with the contents of the file games.csv
    int homeIDs[NUM_GAMES]        = {48,    37,    38,    48,    45,    38,    51,    61,    59,    39};
    int awayIDs[NUM_GAMES]        = {50,    46,    65,    39,    42,    63,    48,    65,    58,    66};
    int homeScores[NUM_GAMES]     = {104,   112,   114,   117,   100,   120,   107,   106,   112,   98};
    double homeFgPcts[NUM_GAMES]  = {0.398, 0.478, 0.467, 0.477, 0.477, 0.517, 0.47,  0.434, 0.495, 0.468};
    double homeFtPcts[NUM_GAMES]  = {0.76,  0.895, 0.8,   0.889, 0.632, 0.8,   0.773, 0.75,  0.5,   0.667};
    double homeFg3Pcts[NUM_GAMES] = {0.333, 0.29,  0.188, 0.314, 0.2,   0.432, 0.387, 0.269, 0.375, 0.323};
    int homeAssists[NUM_GAMES]    = {23,    28,    23,    28,    29,    33,    24,    12,    28,    21};
    int homeRebounds[NUM_GAMES]   = {53,    47,    47,    42,    39,    51,    30,    41,    40,    37};
    int awayScores[NUM_GAMES]     = {113,   106,   103,   105,   113,   107,   113,   108,   115,   119};
    double awayFgPcts[NUM_GAMES]  = {0.422, 0.488, 0.422, 0.443, 0.455, 0.424, 0.519, 0.452, 0.459, 0.506};
    double awayFtPcts[NUM_GAMES]  = {0.875, 0.824, 0.958, 0.931, 0.786, 0.769, 0.821, 0.75,  0.844, 0.727};
    double awayFg3Pcts[NUM_GAMES] = {0.357, 0.375, 0.294, 0.32,  0.306, 0.325, 0.333, 0.297, 0.313, 0.447};
    int awayAssists[NUM_GAMES]    = {21,    22,    21,    25,    20,    24,    27,    25,    26,    32};
    int awayRebounds[NUM_GAMES]   = {46,    36,    42,    40,    47,    44,    35,    42,    49,    45};
    int homeTeamWins[NUM_GAMES]   = {0,     1,     1,     1,     0,     1,     0,     0,     0,     0};


    //Actually parse through the file and gather the info into the arrays
    for (int i=0;i<NUM_GAMES;i++){
        fscanf(inFile, "%d,%d,%d,",&homeIDs[i],&awayIDs[i],&homeScores[i]);
        fscanf(inFile, "%lf,%lf,%lf,%d,%d,%d,",&homeFgPcts[i],&homeFtPcts[i],&homeFg3Pcts[i],&homeAssists[i],&homeRebounds[i],&awayScores[i]);
        fscanf(inFile, "%lf,%lf,%lf,%d,%d,%d\n",&awayFgPcts[i],&awayFtPcts[i],&awayFg3Pcts[i],&awayAssists[i],&awayRebounds[i],&homeTeamWins[i]);
    }
    
    fclose(inFile);

    // ----------------------------------------------------------------------------------
    // Step 2:  Call the 5 functions and gather their data
    // ----------------------------------------------------------------------------------

    // Call pointDifferentialPerGameOneTeam 2x – once for the home team and once for the away time
    double homePointDiffCompare = pointDifferentialPerGameOneTeam(team1, homeIDs, awayIDs, homeScores, awayScores,NUM_GAMES);
    double awayPointDiffCompare = pointDifferentialPerGameOneTeam(team2, homeIDs, awayIDs, homeScores, awayScores,NUM_GAMES);
    
    // Subtract the home team from the away team to get the pointDifferentialStat
    double pointDiffCompare = homePointDiffCompare - awayPointDiffCompare;
    
    // Call shootingEffectivenessOneTeam 2x – once for the home team and once for the away time
    double homeShooting = shootingEffectivenessOneTeam(team1, homeIDs, awayIDs, homeFgPcts, awayFgPcts, homeFg3Pcts, awayFg3Pcts, homeFtPcts, awayFtPcts, NUM_GAMES);
    double awayShooting = shootingEffectivenessOneTeam(team2, homeIDs, awayIDs, homeFgPcts, awayFgPcts, homeFg3Pcts, awayFg3Pcts, homeFtPcts, awayFtPcts, NUM_GAMES);

    // Subtract the home team from the away team to get the shootingDifferentialStat
    double shootingDifferential = homeShooting - awayShooting;

    // Call reboundsPerGameComparison once to get the reboundingStat
    double reboundDifferential = reboundsPerGameComparison(team1, team2, homeIDs, awayIDs, homeRebounds, awayRebounds, NUM_GAMES);

    // Call assistsPerGameComparison once to get the assistStat
    double assistDifferential = assistsPerGameComparison(team1, team2, homeIDs, awayIDs, homeAssists, awayAssists, NUM_GAMES);

    // Call headToHeadWL once to get the headToHeadStat
    int h2h = headToHeadWL(team1, team2, homeIDs, awayIDs, homeTeamWins, NUM_GAMES);


    // ----------------------------------------------------------------------------------
    // Step 3:  Use the following formula to predict the winner
    // (pointDifferentialStat * 0.6) + headToHeadStat + (shootingDifferentialStat * 120) + reboundingStat + (assistStat * 0.75)
    // ----------------------------------------------------------------------------------    
    
    double prediction = pointDiffCompare*0.6 + (double)h2h + shootingDifferential*120.0 + reboundDifferential + assistDifferential*0.75;
    
    // ----------------------------------------------------------------------------------
    // Print out the output
    // ----------------------------------------------------------------------------------
    // If the value is > 0, then the home team is predicted to win; if the value is <= 0, then the away team is predicted to win

    int teamPredictedToWin = 0;

    if (prediction > 0){
        teamPredictedToWin = team1;
    }else{
        teamPredictedToWin = team2;
    }
    printf("The final output is %.2lf, which means team %d is predicted to win the game.\n",prediction,teamPredictedToWin);

    return 0;

}