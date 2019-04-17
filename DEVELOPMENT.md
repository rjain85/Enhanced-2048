# Development log

## April 6
I had a great deal of difficulty actually cloning the code from GitHub. Cloning directly into Visual Studio did not work. Here is what needed to be done:
First I cloned the given code into the folder where I always put my C++ projects using Git Bash. Next, I opened my openFrameworks folder and then opened the folder projectGenerator-vs. From there I opened the projectGenerator.exe GUI. 
I imported the project from where I cloned it and hit generate. I opened the project in the Visual Studio IDE. I changed the debug configuration from x32 to x6
. Then I closed visual studio and reran it as an administrator. Finally, the project built successfully.

## April 12
I set my window title and background color, and I also added music using ofSound. Elizabeth said I shoud focus on implementimg the game before adding the color palette feature, so I'll probably do that.

## April 14
I created files game_math.h and game.math.cpp. For some reason these weren't automatically created in the src folder, so the compiler couldn't find them. So, I had to use the folder view to drag them into the correct location. Somehow, references still existed which then had to be deleted. 
Currently, I'm implementing a version of the game that can be played via the console. I created a Board class. So far I have a method to initialize a new game by generating a new board with two random tiles. Currently, the winner is defined only when a player reaches 2048, but there is no way to define the loser.

## April 16
I added functionality to move the grid leftwards. This must be done in two steps. 
First, I have to move the tiles in each row leftwards so that there are no zeroes between them ("compress_left"). All zeroes should be pushed to the end of the row. 
Second, if one tile's value is x, and the tile immeadiately to the right has the value x, the left tile's becomes 2x, and the right tile's value becomes 0 ("merge_left"). Then I "compress" again.
I repeated this to implement compress_up and merge_up, which took very long due to some silly mistakes on my part. Right and down have yet to be implemented.
I also added a method to spawn new tiles after each turn.
Here are some links that were very helpful:
- https://gist.github.com/chandruscm/2481133c6f110ced6dd7. Some guy's implementation of 2048. He makes some choices that seem buggy and dubious but it helped me get started.
- https://steven.codes/blog/cs10/2048-merge/ These animations helped me visualize the compress and merge steps.
ToDos
- down and right methods (duh)
- check for loser
- check if a move actually changes anything. Sometimes, the board will be in such a state where moving it one direction does nothing.
- copy the board after each move. I will probably use the copy to see if the move actually changed anything. This will probably also be useful in animating the board.


