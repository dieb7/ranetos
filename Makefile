#Set this to @ to keep the makefile quiet
SILENCE = @

#---- Outputs ----#
COMPONENT_NAME = ranetos
#Set this to @ to keep the makefile quiet
SILENCE = @

#--- Inputs ----#
PROJECT_HOME_DIR = .
ifeq "$(CPPUTEST_HOME)" ""
    CPPUTEST_HOME = ../CppUTest
endif
CPP_PLATFORM = Gcc

SRC_DIRS = .
# to pick specific files (rather than directories) use this:    
SRC_FILES = 

TEST_SRC_DIRS = tests

MOCKS_SRC_DIRS = mocks

INCLUDE_DIRS =\
  .\
  $(CPPUTEST_HOME)/include/ \
  $(CPPUTEST_HOME)/include/Platforms/Gcc\
  mocks

CPPUTEST_WARNINGFLAGS = -Wall -Werror -Wswitch-default 
CPPUTEST_WARNINGFLAGS += -Wconversion -Wswitch-enum 
CPPUTEST_CXXFLAGS += -std=gnu++11 -Wno-c++14-compat

include $(CPPUTEST_HOME)/build/MakefileWorker.mk

