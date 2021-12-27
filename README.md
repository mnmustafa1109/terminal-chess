<!--  Noman Mustafa Mehar
      Section : SE-Q 2021
      PF   PROJECT   2021
      ROll No : 21I -1235  -->

# Terminal-Chess :chess_pawn:

A terminal chess
Made using cpp and ncurses

## To compile 

`g++ -g main.cpp init_win.cpp init_colours.cpp calc.cpp piece.cpp piece_man.cpp write.cpp move_rule.cpp move_piece.cpp movement.cpp obs_rec.cpp score.cpp history.cpp -o terminal_chess -lncurses`

## To run

`./terminal_chess`

## To compile and run 

Just run the script run.sh which will compile and run automatically on your terminal

## Pre requisite 

Before compiling make sure you have ncurses install if you are on windows. If you are on linux you can compile straight away compile 

## Sugesstions

Before running make sure your terminal is in full screen mode to avoid cutting of of the chess board from the end

## Features

- intelligent obsatcle recognition
- user friendly error feedback
- score analytic of both side
- en passont move support
- pawn promotion move support
- colored turn banner for ease
- history of all move played
- outputting history to a text file

## Planned Features

- mouse based movement
- castling move support
- player timer support
- arrow key based movement
- last move highlight
- intelligent legal move highlight for beginners

## Bugs 
 none ... contact me if you find any
 or submit an issue at [Issues](https://github.com/mnmustafa1109/terminal-chess/issues)
