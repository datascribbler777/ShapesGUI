echo off

if exist "obj/shapes.o" del shapes.o
g++ -I inc -c src/shapes.cpp -o obj/shapes.o -O1 -Wall
if exist "obj/shapes.o" echo Shapes Compilation Successful

if exist "obj/GWindow.o" del GWindow.o
g++ -I inc -c src/GWindow.cpp -o obj/GWindow.o -O1 -Wall
if exist "obj/GWindow.o" echo GWindow Compilation Successful

if exist "obj/GLabel.o" del GLabel.o
g++ -I inc -c src/GLabel.cpp -o obj/GLabel.o -O1 -Wall
if exist "obj/GLabel.o" echo GLabel Compilation Successful

if exist "bin/shapes.exe" del "bin/shapes.exe"
g++ obj/GWindow.o obj/GLabel.o obj/shapes.o -o bin/shapes -L lib -lraylib -lopengl32 -lgdi32 -lwinmm
if exist "bin/shapes.exe" echo Shapes Linking Successful