# Final Project
# README
 * Overview 
 * Requirements
 * Installation
 * Citations 

## Overview 
I created a version of 2048 in which the user can select one of two color themes and has the option to resurrect after they die.

## Requirements
* OpenFrameworks version 0.10.1 or higher. Install OpenFrameworks by following the instructions at http://openframeworks.cc/download/ 

You will also need to add ofxGui to the project using OpenFrameworks. To do so, open OpenFrameworks' projectGenerator exe, import this project, and select ofxGui under the drop-down menu in the Addons section.

## Installation
Installation is quite straightforward.
Steps:
1. git clone 
2. Open in Xcode or a similar IDE through OpenFramework's projectGenerator app.
3. Run.

## Code Style
I wrote this code in accordance with the Google C++ Style Guide (https://google.github.io/styleguide/cppguide.html). Note that methods required by OpenFrameworks deviate from this style.

## Demo
Below is a full demo of the photo-taking version of the Pacman. Notice that the user can change his or her setting selection; only the final selected settings go into setting up the game.
<p align="center">
  <img width="500" height="450" src="bin/data/demos/readme_demo.gif">
</p>

## Citations
I began by modifying the code from of-snake (https://github.com/uiuc-sp18-cs126/of-snake-ElizWang), which was not written by me. However, I only used of-snake as a starting point and added enough code to completely distinguish my projecft from of-snake.

I used OpenCv's facial detection haar cascade in detecting faces from photos taken (https://github.com/opencv/opencv/blob/master/data/haarcascades/haarcascade_frontalface_alt.xml). This was cloned and added to bin/data/haar_cascades.

I also used ofxCenteredTrueTypeFont (https://github.com/armadillu/ofxCenteredTrueTypeFont) to format the game instructions. I cloned this and added it in src/header_addons. 

Below are the citations to the images I used. Note that all images (except for the user headshots) were taken from google.
* Default pacman - https://findicons.com/search/pacman
* Food (fruit) - https://www.flaticon.com/free-icons/apple-fruit
* Ghost - http://iconbug.com/detail/icon/2508/floating-ghost/
* Coin - http://clipart-library.com/a-coin-cliparts.html

