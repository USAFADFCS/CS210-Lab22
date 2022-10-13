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
    int wlCounter = 0;

    //Go through each game and check whether it was these two exact teams.  If so, check who won and adjust wlCounter acccordingly
    //Two if statements are needed to check whether it was these two teams because it counts regardless of who was home or away.
    for(int i=0;i<num_games;i++){
        if (homeID == homeIDs[i] && awayID == awayIDs[i]){
            if (gameResults[i] == 1){
                wlCounter+=1;
            }else{
                wlCounter-=1;
            }
        }else if (awayID == homeIDs[i] && homeID == awayIDs[i]){
            if (gameResults[i] == 1){
                wlCounter-=1;
            }else{
                wlCounter+=1;
            }
        }
    }

    return wlCounter;
}