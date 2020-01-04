Usage: ./CGOL fileName.seed <tick>

The overall purpose of this program is to run Conway's game of life.
Firstly, the program reads and displays in the seed file (initial) grid that the user inputs.
Using the 2-D array populated by the previous code,  the live cells are then represented by an X and the dead cells by a space.
Once the user compiles the file, they will view the inital seed grid and will be asked if they would like to start the game.
If yes, the program and the game will start to run and in the lower right corner of the frame there is an active count of the number representing the tick (number of times that the grid has been evaluated).
After the game stop, the user will be asked whether they would like to continue the game.
If yes, it will bring them back to the start question. If they choose no, it will end the game and output "Program Terminated".
