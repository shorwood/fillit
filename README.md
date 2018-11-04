# Fillit

This is the story of a piece of Tetris, one little square and a dev walk into a bar.

# Introduction
- Fillit is a project that let you discover and/or familiarize yourself with a recurring problematic in programming: searching the optimal solution among a huge set of possibilities, in a respectable timing. In this particular project, you will have to find a way to assemble a given Tetriminos set altogether in the smallest possible square. 

- A Tetriminos is a 4-blocks geometric figure you probably already heard of, thanks to the popular game Tetris.

- Fillit is not about recoding Tetris, even if it’s still a variant of this game. Your program will take a file as parameter, which contains a list of Tetriminos, and arrange them in order to create the smallest square possible. 

- Obviously, your main goal is to find the smallest square in the minimal amount of time, despite an exponentially growing number of possibilities each time a piece is added.

- You should think carefully about how you will structure your data and how to solve this problem, if you want your program answers before the next millenium.

# Objectives
- Your executable must take only one parameter, a file which contains a list of Tetriminos to assemble. This file has a very specific format : every Tetrimino must exactly fit in a 4 by 4 chars square and all Tetrimino are separated by an newline each.

- If the number of parameters sent to your executable is not 1, your program must display its usage and exit properly. If you don’t know what a usage is, execute the command cp without arguments in your Shell. It will give you an idea. Your file should contain between 1 and 26 Tetriminos.