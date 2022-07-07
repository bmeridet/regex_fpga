CC = g++
LD = ld
TARGET = regex_nfa
LDFLAGS = -W -Xlinker -Map=$(TARGET).map
CFLAGS = -g -Wall

SDIR = src

SRC = $(wildcard $(SDIR)/*.cpp)
OBJ = $(SRC:.cpp=.o)
INCLUDE = -I./include

$(TARGET) : $(OBJ)
	$(CC) $(CFLAGS) $(INCLUDE) -o $@ $(OBJ) $(LDFLAGS)

.PHONY: clean

clean:
	rm -f $(OBJ) $(TARGET) $(TARGET).map