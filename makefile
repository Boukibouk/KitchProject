#Makefile variable definition

# 2 mode available for the makefile 
# COMPILE_ONLY :  Simple compile of the Project without Test environnement (Compile without link )
# TEST_MODE : Compile and link all the file includes the Test module
MODE = TEST_MODE

#DEBUG mode is availble by setting the variable DEBUG = 1
DEBUG = 0

BINARY_NAME = TestSuit.out

BASE_SRC = Source

#Project files 
INCLUDE_PROJECT = Include
SOURCE_PROJECT =  $(wildcard $(BASE_SRC)/Common/*.cpp) $(wildcard $(BASE_SRC)/Map/*.cpp) $(wildcard $(BASE_SRC)/StateMachine/*.cpp)
SOURCE_PROJECT = $(wildcard $(BASE_SRC)/Common/*.cpp)  $(wildcard $(BASE_SRC)/Map/*.cpp) $(wildcard $(BASE_SRC)/StateMachine/*.cpp)
                    
<<<<<<< HEAD
INCLUDE_TEST =  Test/Include
SOURCE_TEST =   $(wildcard Test/Source/*.cpp)
=======
INCLUDE_TEST =  $(BASE_SRC)/Test/Include
SOURCE_TEST =   $(wildcard $(BASE_SRC)/Test/Source/*.cpp)
>>>>>>> master

# Further files can be added ...

#Test files
SOURCE = $(SOURCE_PROJECT)
<<<<<<< HEAD
=======


ifeq ($(MODE),TEST_MODE)
SOURCE  += $(SOURCE_TEST)  
endif 

CC = g++
CFLAG = -I $(INCLUDE_PROJECT)

ifeq ($(MODE),TEST_MODE)
CFLAG += -I $(INCLUDE_TEST)
endif

ifeq ($(MODE),COMPILE_ONLY)
CFLAG += -c
else
CFLAG += -DDEBUG -o $(BINARY_NAME)
endif 

clean:
	rm -rf *.o *.out

compile:   
	$(CC) $(CFLAG) $(SOURCE) 
>>>>>>> master


ifeq ($(MODE),TEST_MODE)
SOURCE  += $(SOURCE_TEST)  
endif 

CC = g++
CFLAG = -I $(INCLUDE_PROJECT)

ifeq ($(MODE),TEST_MODE)
CFLAG += -I $(INCLUDE_TEST)
endif

ifeq ($(MODE),COMPILE_ONLY)
CFLAG += -c
else
CFLAG += -DDEBUG -o $(BINARY_NAME)
endif 

all: compile

compile: clean   
	$(CC) $(CFLAG) $(SOURCE) 

clean:
	rm -rf *.o *.out