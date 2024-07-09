Snakes and Ladders Game was a semester project, compiled using C Language.
It is a two-player game. The goal is to reach the 100th square before the other player. The Ladders take you up several rows, while the Snakes bite, and make you drop several rows.

The graphics for this game are really elementary, with Ladders represented by " /-/ /-/ /-/ " and Snakes represented by " <@@ ", the arrow signifying the snake's mouth.

The characters are represented by: Player 1: " ( \o/ ) " (Praise the Sun lol), Player 2: " ( ^-^ ) ".

The Scoring System for the game is as follows: 
1) Initial Points: 500 Points
2) Every time you move up one row: 20 Points
3) Score Decay with every move: -5 Points
4) Ladder Move: 20 * (Number of Rows Climbed)
5) Snake Move: -20 * (Number of Rows Dropped)
6) First to reach 100th Square: 200 Points
7) Win Condition: Highest Score.

Possible Improvements in the Game could be:
1) Better visuals for the playing board, snakes and the ladders,
2) Animation for the dice roll,
3) Delay in displaying of the dice roll and board result, and
4) A 4-Player Mode.

Update 1.1:
Some compilers prefer "scanf" instead of "scanf_s", so try changing if your compiler gives an error.
All Rights Reserved
