# 2 mode available for the makefile 
# COMPILE_ONLY :  Simple compile of the Project without Test environnement (Compile without link )
# TEST_MODE : Compile and link all the file includes the Test module
MODE = TEST_MODE

#DEBUG mode is availble by setting the variable DEBUG = 1
DEBUG = 0


############" Activate the following TCASE by set it to 1
TCASE_1 = 1



####################### Project files 
BASE_SRC_PATH = Source
INCLUDE_PROJECT = Include
SOURCE_PROJECT =  $(wildcard $(BASE_SRC_PATH)/Common/*.cpp) $(wildcard $(BASE_SRC_PATH)/Map/*.cpp) $(wildcard $(BASE_SRC_PATH)/StateMachine/*.cpp)

SOURCE = $(SOURCE_PROJECT)
INCLUDE = $(INCLUDE_PROJECT)

######################## Test Files
#Global Path Test 
INCLUDE_TEST  := Test/Include
INCLUDE_TEST  += Test/Source/TestCase

SOURCE_TEST =  Test/Source/main.cpp  
PATH_TEST = Test/Source/TestCase


ifeq ($(TCASE_1),1)
SOURCE_TEST += $(wildcard $(PATH_TEST)/TCASE1/*.cpp)
INCLUDE_TEST += $(PATH_TEST)/TCASE1
CFLAG += -DTCASE1
endif 

ifeq ($(MODE),TEST_MODE)
SOURCE  += $(SOURCE_TEST)  
endif 

ifeq ($(MODE),TEST_MODE)
INCLUDE += $(INCLUDE_TEST)
endif

############################# Compilation Link 
BINARY_NAME = TestSuit.out
CC = g++

CFLAG += $(foreach param,$(INCLUDE), -I $(param))
ifeq ($(MODE),COMPILE_ONLY)
CFLAG += -c
else
CFLAG += -DDEBUG -o $(BINARY_NAME)
endif 




################################### Rule #########################""
all: compile

compile: clean    
	$(info ************ Building project ********* )
	$(CC) $(CFLAG) $(SOURCE)
	

clean:
	$(info ********** Clean WorkSpace *********** ) 
	@rm -rf *.o *.out