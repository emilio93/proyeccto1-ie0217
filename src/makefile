CC = g++
OBJS = nodeTest.cpp
DEBUG = -g
CFLAGS = -Wall -c $(DEBUG) -pedantic
LFLAGS = -Wall $(DEBUG) -pedantic
TARGET = nodeTest

$(TARGET) : $(OBJS)
	$(CC) $(LFLAGS) $(OBJS) -o $(TARGET)
docs :
	doxygen
clean :
	rm -f *.o $(TARGET)
cleanWin :
	del *.o *.exe $(TARGET) 2>nul
