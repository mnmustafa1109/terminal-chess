cd source
g++ -lncurses -c *.cpp 
g++ -lncurses *.o -o terminal-chess 
rm -r *.o
./terminal-chess
cd ..
