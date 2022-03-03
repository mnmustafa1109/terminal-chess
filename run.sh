cd source
g++ -c *.cpp  -lncurses
g++ *.o -o terminal-chess -lncurses
rm -r *.o
./terminal-chess
cd ..

