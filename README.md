# Pong SDL
The classic game of Pong ported to modern systems using the [SDL](https://www.libsdl.org/index.php).

<img src="https://media.giphy.com/media/hvShNDhzrxEl74r5Ev/giphy.gif">

# Intro

Main purpose of this project was to get familiar with practices such as :

* Processing input from various sources WASD and Arrow Keys for 2 players
* Implementing a basic collision systems
* User Interface creation and handling 
* Main menu and game over screen implementation

# Overview

* The game supports two real players via WASD and Arrow keys respectively. 
* First one to score 3 points wins !

# Building in Linux

1) Grab the dependencies using the following commands in terminal : 
`sudo apt-get install libsdl1.2-dev libsdl-image1.2-dev libsdl-mixer1.2-dev libsdl-ttf2.0-dev`
2) Clone the project's repository 
3) Open a terminal window inside the cloned folder
4) Use the following command : `make`
5) Run the executable : `./pong`
