#!/bin/bash
cd ./src
g++ -o ../bin/rlConnectFour main.cpp AI.cpp Board.cpp Console.cpp Game.cpp GameMaster.cpp Graphics.cpp Options.cpp Player.cpp Player_AI.cpp Player_Human.cpp
