# Development log

## April 6
- I had a great deal of difficulty actually cloning the code from GitHub. Cloning directly into Visual Studio did not work
- Here is what needed to be done:
	- First I cloned the given code into the folder where I always put my C++ projects using Git Bash
	- Next, I opened my openFrameworks folder and then opened the folder projectGenerator-vs 
	- From there I opened the projectGenerator.exe GUI
	- I imported the project from where I cloned it and hit generate. 
	- I opened the project in the Visual Studio IDE. I changed the debug configuration from x32 to x64
	- Then I closed visual studio and reran it as an administrator. Finally, the project built successfully

## April 12
- Set my window title and background color
- Added music using ofSound
- Elizabeth said I shoud focus on implementimg the game before adding the color palette feature, so I'll probably do that

## April 14
- I created files game_math.h and game.math.cpp 
	- For some reason these weren't automatically created in the src folder, so the compiler couldn't find them. 
	- Had to use the folder view to drag them into the correct location
	- Somehow, references still existed which then had to be deleted. 
- Currently, I'm implementing a version of the game that can be played via the console
- I created a Board class 
- So far I have a method to initialize a new game by generating a new board with two random tiles 
- Currently, the winner is defined only when a player reaches 2048, but there is no way to define the loser

## April 16
- Added functionality to move the grid leftwards. This must be done in two steps
	- First, I have to move the tiles in each row leftwards so that there are no zeroes between them ("compress_left"). All zeroes should be pushed to the end of the row 
	- Second, if one tile's value is x, and the tile immeadiately to the right has the value x, the left tile's becomes 2x, and the right tile's value becomes 0 ("merge_left")
	- Then I "compress" again
- Repeated this to implement compress_up and merge_up, which took very long due to some silly mistakes on my part 
- Right and down have yet to be implemented
- I also added a method to spawn new tiles after each turn
- Here are some links that were very helpful:
	- https://gist.github.com/chandruscm/2481133c6f110ced6dd7. Some guy's implementation of 2048. He makes some choices that seem buggy and dubious but it helped me get started
	- https://steven.codes/blog/cs10/2048-merge/ These animations helped me visualize the compress and merge steps
- ToDos
	- down and right methods (duh)
	- check for loser
	- check if a move actually changes anything. Sometimes, the board will be in such a state where moving it one direction does nothing.
	- copy the board after each move. I will probably use the copy to see if the move actually changed anything. This will probably also be useful in animating the board.

## April 17
- Completed the methods to swipe right and downwards, so now all four directions are complete.
- Also created "board_copy_". I wrote a method called copy_board where after each swipe, the state of the board is copied to the copy_board_. 
- Wrote a method to compare if two boards have equals values in each tile. These methods are implemented such that if a swipe does not change the board at all, new tiles are not spawned.
- Wrote a method that returns a boolean indicating whether or not the player has lost. 
	- This calls the FindEmptyPositions method, and if any of the tiles are empty, it automatically returns that the player hasn't lost.
	- Then it goes through each each tile in the board and checks that no tile has the same value as a tile adjacent to it
	- This method might be buggy so I will test it further.
- Also, a weird bug I've noticed is that the window doesn't open unless I comment out the board methods in ofApp, or if I end the game. However, the music continues to play.
- Overall, the backend is mostly complete.
- ToDos
	- inspect and possibly change the check for loser method.
	- figure out why the window won't open.
	- Begin GUI work.

## April 18 
- Some thoughts:
	- I might consider adding catch2 testing. Obviously a whole game cannot be simulated due to the random spawning of tiles, but individual methods like compress, merge, and especially checking for loser seem worth testing.
	- The formula for calculating score looks a bit off. I'll do some more research to see if it is correct.

## April 25
- Began working on changes to backend suggested by Elizabeth:
	- Changed ints to size_t's
	- Simplified if statements in hasLost method
	- Created a simpler method to check for winner by using a global boolean variable that is modified when a player reaches the winning value.
	- Unfortunately, these changes "broke" the code, causing a null pointer problem in the board_copy method. It was not clear on why this occurred but I ended up reverting my commits and redoing some code.
	- During the "re-do," I used less size_t's and stuck to ints in for loops, which seemingly solved the problem.
- Finally, I moved my method calls into ofApp.cpp:
	- Created a should_update boolean and check_game_over method to check if the game is over and update it.
	- Ran methods via a board object in the class.
- Began working on graphics:
	- created a white rectangle that can move across the screen in a pre determined way.
- Notes:
	- Some code in game_math.cpp is now deprectated and will have to be removed.

## April 26 - 27
- Created enums for GameState: BEGIN, SETUP, PLAY, WIN, LOSS.
- Apart from using a GameState object, I use two booleans, should_update and should_move_board to determine what should happen to the UI
- Wrote draw methods to design the UI for each state
- Display the score on the window as it is changed
- For the drawBoard method, I draw one large 450 * 450 square centered on the screen, with 16 smaller 100 * 100 squares within it
- I decided to load images for the tiles. I used the following resources to design the tiles:
	- https://www.canva.com/;
	- https://www.colorhexa.com/
	- https://meyerweb.com/eric/tools/color-blend/#87ADF1:FFCCFF:2:hex
- Used a map to match tiles (ofImage objects) to their corresponding values
- Used a map to match tile postions (1 - 16) to float coordinates that are calculated based off of the size of the window
- Added sound effects for clicking and winning using ofSound
- Draw tiles method now takes the values of the board and displays the corresponding tiles in the correct places
- ToDos
	- Create sliding motions for the tiles
	- Add option to restart the game or play again
	- Glam up the UI

## April 29th
- Spent all day trying to animate the tiles sliding but with no luck
	- original plan was to store the tiles that merged into another in a vector called contributors, but this led to various issues:
	- tracking tiles through both compress and merge methods, as well as the compress call in merge
	- sliding tiles that have to move different lengths at roughly the same speed
- Fixed a bug in the HasLost() method that sometimes caused it to ignore tiles on the edge of the board
- Cleaned up board.h files
- Problems:
	- tried to move methods in board.h to private but this limited accessibility everywhere
- ToDos:
	- Add restart option and beautify UI
	- clean up code
	- possibly add some customizability to UI... maybe another set of tiles

## April 29th
- Decided to scrap sliding tiles in favor of some new features instead
- Fixed a few bugs in the backend:
	- One bug was causing new two's to occasionally spawn over prexxisting tiles due a small error in the initBoard method when positions were indexed
	- Another bug was occasionally resulting a in a divide by 0 in the SpawnNewTwo method
- Added ofxGui addon to the project to be on the safe side
- Added option to restart the game at anytime by pressing 'N'
- Added option to "resurrect" after your first loss (preserve your score and highest tile value)
	- Added ResurrectPlayer method and highest value and highest value position varaiables to board class, as well as functionality to track these variables
- Whether or not the player has "a life" available is stored in a boolean
- Added a small heart graphic to be displayed when the player has a life available
- Changed font to "Pixel Mix"
- Imported song "All Star" by Smash Mouth, to be played when a player loses the game (to provide encouragement!)
- Created a new theme class to store tile themes. This includes "Candy" (original theme) and "Earthy" (new theme)
	- Originally, I did not plan on creating a new class, I wanted to create vectors of filenames and import based off of user selection
	- Unfotunately, because importing has to be done in setup, it was very difficult to do this without user input first
- Moved tilemap and ofImage to theme class and created Theme object in ofApp
- Allowed users to select theme choice in Begin stage using buttons made in ofxGui
- Examined each header file and moved as much code as possible to private
- Removed code related to printing and other deprecated code

## April 30th 
- Broke setup in ofApp.cpp into smaller methods
- Added background music to play during BEGIN stage
- Made updateScore and updateHighestNumber in board.cpp their own smaller methods
- Made colors in ofApp constants
- Made all filenames in ofApp constant strings
- Tried changing code in compress methods to eliminate nesting, but it made the code feel less intuitive and straightforward so I changed it back
- Began documenting code. Wrote java style documentation in all files, but I will have to add more
- Began working on README.md and tried to insert a gif of my demo
	- Unfortunately my bin is not part of my repo so currently the gif cannot be displayed on the README.md
- Added a few test cases for compress and merge methods using Catch2
	- Unfortunately you need to comment out the main to run the test cases