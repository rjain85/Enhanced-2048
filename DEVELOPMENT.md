# Development log

## April 6
I had a great deal of difficulty actually cloning the code from GitHub. Cloning directly into Visual Studio did not work. Here is what needed to be done:
First I cloned the given code into the folder where I always put my C++ projects using Git Bash. Next, I opened my openFrameworks folder and then opened the folder projectGenerator-vs. From there I opened the projectGenerator.exe GUI. 
I imported the project from where I cloned it and hit generate. I opened the project in the Visual Studio IDE. I changed the debug configuration from x32 to x64. Then I closed visual studio and reran it as an administrator. Finally, the project built successfully.

## April 12
I set my window title and background color, and I also added music using ofSound. Elizabeth said I shoud focus on implementimg the game before adding the color palette feature, so I'll probably do that.