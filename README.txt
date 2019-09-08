This program reads a file containing soccer players, their jersey number, and their position in the following format:

Thiago Silva, 2, Defender
Marquinhos, 5, Defender
Alphonse Areola, 16, Goalkeeper
Neymar, 10, Forward
Edinson Cavani, 9, Forward
Marco Verratti, 6, Midfielder

It then reads another file containing the names of players whose indicies in the list the user wants to find. This file is written in the following format:

Marquinhos
Thiago
Neymar

The program searches for the players on the list, then outputs the players name and index in a new file.
If the player is not found on the list, the index is listed as -1.
The output file is in the following format:

Marquinhos: 3
Thiago: -1
Neymar: 4


To access the files, the command line must contain: "input=[inputfile].txt command=[commandfile].txt output=[outputfile].txt
This way the ArgumentManager can parse the information and the files can be opened