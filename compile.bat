echo off

if exist "obj/shapes.o" del shapes.o
g++ -I inc -c src/shapes.cpp -o obj/shapes.o -O1 -Wall
if exist "obj/shapes.o" echo Shapes Compilation Successful

if exist "bin/shapes.exe" del "bin/shapes.exe"
g++ obj/shapes.o -o bin/shapes -L lib -lraylib -lopengl32 -lgdi32 -lwinmm
if exist "bin/shapes.exe" echo Shapes Linking Successful