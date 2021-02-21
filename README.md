# Filler

![logo](/resources/screenshots/logo.png)

![Subject](/resources/filler.en.pdf)

Filler is a game, where two players / algorithm are fighting on a map

## Game rules
* In this game, two players fight each other. They play one after the other.
* The goal is to collect as many points as possible by placing the highest number of pieces on the the game board.
* The board is defined by X columns and N lines, it will then become X*N cells.
* At the beginning of each turn, player will receive their game piece.
* A game piece is defined by X columns and N lines, so it will be X*N cells. Inside each game piece, will be included a shape of one or many cells.
* To be able to place a piece on the board, it is mandatory that one, and only one cell of the shape (in his piece) covers the cell of a shape placed previously (his territory).
* The shape must not exceed the dimensions of the board
* When the game starts, the board already contains one shape.
* The game stops at the first error: either when a game piece cannot be placed anymore or it has been wrongly placed.
* Each successfully placed piece yields a number of points, and has only one player, the goal of the game could be to get the best score possible.

However, it is with two players that the filler takes all his interest. Each player has for the purpose of placing as many pieces as possible while attempting to prevent his opponent from doing the same.

At the end of the game, the one with the most points WIN the match...

- IA that play the filler game and WIN alot of players!!
- Bonus: An amazing Visualizer using SDL!

### game without visualizer
![without visual](https://github.com/Dude-Rocker/resources/blob/master/filler/vgladuhs_vs_carli.gif)

### game using visualizer

![menu](/resources/screenshots/menu.png)

![gameplay_carli](/resources/screenshots/gameplay_carli.png)

![gameplay_anas](/resources/screenshots/gameplay_anas.png)

![gameplay_win](/resources/screenshots/gameplay_win.png)

You can **Save Screenshots** in the game using: `s`

## Algorithm to play the game

The key to win this game is to make the opponent lose X) YES! wait let me explain, the game is over for you if you can't put the piece given sooo if i run fast at you then  make a quick border on your territory that mean that you can't pass it and all the rest is mine will you got out of the game for not given the right coordonate to place the piece ;)

I use 2 steps for that:

### I- Secure Area:
Depend on my spawn position i run fast to touch a point in the board to secure myself from **hug technique** technique.
 (clear in the first picture with carli)

### II- Use Heat Map Algorithm

On the begining of each turn, a Heat Map is created. It represents the Map of the game. 
Values are assigned on each case of the map. It starts from the position of the ennemy and is incremented until it reaches the board edges :

![alt text](https://github.com/mdubus/filler/blob/master/img/heat-map.png)

Then, the algorithm try to put the piece on each position of the map. One case of the piece has to overlap one of my previous. It calculates the score on each position. 
The smaller the score is, the best it is, because it will get closer of the ennemy and bother him to play.

I calculate the score for all possible places that i can put the piece provided by the VM, and i choose the lower score.

## Dependencies
- SDL2
- SDL2-TTF
- SDL2-IMAGE
- SDL2-MIXER
- FreeType

## Usage
- Run `make`
- Execute `<filler_vm> -f <map> -p1 <player.filler> -p2 <player.filler> | ./Displayer/ob_displayer`

(exemple: `./resources/filler_vm -f resources/maps/map01 -p1 ./obelouch.filler -p2 resources/players/carli.filler | ./Displayer/ob_displayer` )

The visualizer **./Display/ob_displayer** use the VM output to display the game!

## Owner
- Oussama Belouche 1337

#
[![forthebadge](https://forthebadge.com/images/badges/powered-by-electricity.svg)](https://forthebadge.com)
[![forthebadge](https://forthebadge.com/images/badges/built-with-love.svg)](https://forthebadge.com)

