CC = g++
CFLAGS = -g
TARGET = oss
OBJS = main.o
.SUFFIXES: .c .o

.DEFAULT_GOAL : $(TARGET)
$(TARGET): $(OBJS)
	$(CC) -o $@ $(OBJS)

.cpp.o:
	$(CC) $(CFLAGS) -c $<

.PHONY: clean
clean:
	/bin/rm -f *.o *.log $(TARGET)
