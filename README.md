# snakes_n_ladders
A simple version of snakes and ladder
The game is played as follows:
1. The game is played iteratively. In every iteration, every player takes turn to roll a dice. The face
value of dice is added to the total score of the player.
2. The first player to reach 100 score gets 1st position. The second player to reach 100 score gets 2nd position.
3. When a player reaches 100, he no longer remains part of the play. If current score + face value is
greater than 100, then the player will retry in the next iteration, i.e., the score must exactly
become 100.
4. There are ladders at 20 and 60. If a player’s score becomes exactly 20, the score becomes 40. If a
player’s score is exactly 60, the score becomes 75. Similarly, there are snakes at 50 and 90. If a
player’s score is exactly 50, the score become 40. If a player’s score is exactly 90, the score
becomes 79.
5. When n-1 players have reached 100, the game ends and the position of all players that
participated in the game is displayed in ascending order.
