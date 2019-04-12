IDIR =include 
CXX=g++ 
CC=gcc
CXXFLAGS= -I$(IDIR) -I./lib  -std=c++11 -w -fpermissive 
SRCDIR=src
ODIR=build
TARGET1=bin/binary_search
TARGET2=bin/insertion
TARGET3=bin/merge_sort
# TARGET4=bin/kmeans

LDIR=-L../lib

LIBS=-lm 


_DEPS1= buffer_manager.h constants.h error.h file_manager.h  

_DEPS2= buffer_manager.h constants.h error.h file_manager.h 

_DEPS3= buffer_manager.h constants.h error.h file_manager.h 
	
# _DEPS4= kmeans.h cluster.h point.h 

DEPS1 = $(patsubst %,$(IDIR)/%,$(_DEPS1))
DEPS2 = $(patsubst %,$(IDIR)/%,$(_DEPS2))
DEPS3 = $(patsubst %,$(IDIR)/%,$(_DEPS3))
DEPS4 = $(patsubst %,$(IDIR)/%,$(_DEPS4))

_OBJ1 =  buffer_manager.o file_manager.o binary_search.o

_OBJ2 =  buffer_manager.o file_manager.o binary.o

_OBJ3 =  buffer_manager.o file_manager.o binary.o

# _OBJ4 = kmeans.o cluster.o point.o 

OBJ1 = $(patsubst %,$(ODIR)/%,$(_OBJ1))
OBJ2 = $(patsubst %,$(ODIR)/%,$(_OBJ2))
OBJ3 = $(patsubst %,$(ODIR)/%,$(_OBJ3))
OBJ4 = $(patsubst %,$(ODIR)/%,$(_OBJ4))


$(ODIR)/%.o: $(SRCDIR)/%.cpp 
	@mkdir -p $(ODIR)
	$(CXX) -c -o $@ $< $(CXXFLAGS)
$(ODIR)/%.o: $(SRCDIR)/%.c
	@mkdir -p $(ODIR)
	$(CC) -c -o $@ $< $(CXXFLAGS)

all:   $(TARGET1) $(TARGET2) $(TARGET3) 

$(TARGET1): $(OBJ1)
	@echo "\n\n\n Linking ...." 
	g++ -o $@ $^ $(CXXFLAGS) $(LIBS) 

$(TARGET2): $(OBJ2)
	@echo "\n\n\n Linking ...." 
	g++ -o $@ $^ $(CXXFLAGS) $(LIBS) 

$(TARGET3): $(OBJ3)
	@echo "\n\n\n Linking ...." 
	g++ -o $@ $^ $(CXXFLAGS) $(LIBS) 

$(TARGET4): $(OBJ4)
	@echo "\n\n\n Linking ...." 
	g++ -o $@ $^ $(CXXFLAGS) $(LIBS) 

.PHONY: clean

clean:
	@echo " Cleaning ....";
	rm -rf $(ODIR) bin/*
