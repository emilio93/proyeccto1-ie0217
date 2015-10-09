CC = g++
OBJS = main.cpp RBTree.cpp
DEBUG = -g
CFLAGS = -Wall -c $(DEBUG) -pedantic
LFLAGS = -Wall $(DEBUG) -pedantic
TARGET = main

$(TARGET) : $(OBJS)
	$(CC) $(LFLAGS) $(OBJS) -o $(TARGET)
clean :
	rm -f *.o $(TARGET)
cleanWin :
	del *.o *.exe $(TARGET) 2>nul
