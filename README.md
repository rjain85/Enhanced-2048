## README
 * Overview 
 * Requirements
 * Installation
 * Citations 

## Overview 
I created a version of 2048 in which the user can select one of two color themes and has the option to resurrect after they die.

## Requirements
* OpenFrameworks version 0.10.1 or higher. Install OpenFrameworks by following the instructions at http://openframeworks.cc/download/ 

You will also need to add ofxGui to the project using OpenFrameworks. To do so, open OpenFrameworks' projectGenerator.exe, import this project, and select ofxGui under the drop-down menu in the Addons section.

## Installation
Steps:
1. git clone 
2. Open in Visual Studio (run as administrator) or a similar IDE through OpenFrameworks' projectGenerator.exe. 
3. Run.

## Code Style
I wrote this code in accordance with the Google C++ Style Guide (https://google.github.io/styleguide/cppguide.html). Note that methods required by OpenFrameworks deviate from this style.

## Demo
Below is a full demo of the Enhanced 2048 Game. Note that the user can change the tile theme and can resurrect after their first loss.
<p align="center">
  <img width="500" height="450" src="final-project-rjain85\finalProject\bin\data\Enhanced-2048.gif">
</p>

## Citations
* This README, and some methods are adapted from Elizabeth Wang: 
	- https://github.com/ElizWang/Enhanced_Pacman
* Some sources that helped me with the compress and merge methods in the board.cpp class
	- https://steven.codes/blog/cs10/2048-merge/ 
	- https://gist.github.com/chandruscm/2481133c6f110ced6dd7
* I used the following websites to generate color palettes for the themes:
	- https://www.colorhexa.com/
	- https://meyerweb.com/eric/tools/color-blend/#87ADF1:FFCCFF:2:hex
* I created the tile images using this website:
	- https://www.canva.com/;
* I found the PixelMix font on this website:
	- https://www.dafont.com/bitmap.php
* The heart graphic:
	- https://www.google.com/url?sa=i&source=images&cd=&cad=rja&uact=8&ved=2ahUKEwitjqPNtvjhAhXh01kKHZpODEwQjhx6BAgBEAM&url=https%3A%2F%2Fwww.pinterest.ca%2Fpin%2F558516791280955477%2F&psig=AOvVaw3b9etDZIBtStH0TUEKtW9p&ust=1556734632853184

 ## Erratum