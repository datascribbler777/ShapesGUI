echo off

if exist "obj/shapes.o" del obj\shapes.o
g++ -I inc -c src/shapes.cpp -o obj/shapes.o -O1 -Wall
if exist "obj/shapes.o" echo Shapes Compilation Successful

if exist "obj/GWindow.o" del obj\GWindow.o
g++ -I inc -c src/GWindow.cpp -o obj/GWindow.o -O1 -Wall
if exist "obj/GWindow.o" echo GWindow Compilation Successful

if exist "obj/GLabel.o" del obj\GLabel.o
g++ -I inc -c src/GLabel.cpp -o obj/GLabel.o -O1 -Wall
if exist "obj/GLabel.o" echo GLabel Compilation Successful

if exist "obj/GTextBox.o" del obj\GTextBox.o
g++ -I inc -c src/GTextBox.cpp -o obj/GTextBox.o -O1 -Wall
if exist "obj/GTextBox.o" echo GTextBox Compilation Successful

if exist "bin/shapes.exe" del bin\shapes.exe
g++ obj/GWindow.o obj/GLabel.o obj/shapes.o obj/GTextBox.o -o bin/shapes -L lib -lraylib -lopengl32 -lgdi32 -lwinmm
if exist "bin/shapes.exe" echo Shapes Linking Successful