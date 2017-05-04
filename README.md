# FILLIT

## Goals

Fillit does not consist of recoding Tetris, even if it’s still a variant of this game.
The program takes a file as parameter which contains a list of Tetriminos and
arrange them to create the smallest square possible. Main goal is to
find this smallest square in the minimal amount of time, despite a exponentially growing
number of possibilities each time a piece is added.


## Program entry

Executable takes as parameter one (and only one) file which contains a
list of Tetriminos to arrange. This file has a very specific format : every Tetriminos
description consists of 4 lines and each Tetriminos are separated by an empty line
If the number of parameters given to executable is different from 1, program
displays its usage and exit properly.

The description of a Tetriminos must respect the following rules :
* Precisely 4 lines of 4 characters followed by a new line.
* A Tetriminos is a classic piece of Tetris composed of 4 blocks.
* Each character must be either a ’#’ when the character is one of the 4 blocks of
a Tetriminos or a ’.’ if it’s empty.
* Each block of a Tetriminos must be in contact with at least one other block on
any of his 4 sides.

## Program output

Program displays the smallest square solution on the standard output. To
identify each Tetriminos in the square solution, its assign a capital letter (starting
with ’A’) to each Tetriminos in the order they appear in the file. A file will contain 26
Tetriminos maximum.
If the file contains at least one error, program displays error on the standard
output and will exit properly.
