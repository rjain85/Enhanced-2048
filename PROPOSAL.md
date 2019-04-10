# CS 126 Final Project Proposal
## Riya Jain

### Overview
My final project will be a version of the popular game 2048 in which users can generate a custom color palette for the tiles of the game.
Users will select 3 colors from an interface. Based off of this, an algorithm will generate a palette of eleven colors; one for each tile.

### Main Objectives
- Create a board interface with 16 tiles 
- Generate a set of rules for the game
- Generate a method of keeping score
- Communicate game state (win or loss) to user
- Allow the user to play the game using arrow keys
- Create a color palette interface to which allows users to select (and delete) up to 3 colors
- Develop an algorithm to generate a palette of eleven colors which will serve as the background colors of the tiles. 

### Potential Extensions
- Save a user generated color palette (to a .JSON file) so that it can be resused in the future
- Maintain a list of highest scores
- Add background music!

### OpenFrameworks Addons
- ofxGui: generate a board, and potentially also use to generate a color palette

### Additional Resources
- [2048 explanatory website](http://2048game.com/tips-and-tricks/)
- [2048 game implementation](http://flothesof.github.io/2048-game.html)