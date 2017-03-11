
ifndef SILENCE
	SILENCE = @
endif

#--- Inputs ----#
PROJECT_HOME_DIR?=.
COMPONENT_NAME=tdd-base

LIB=../lib


CPPUTEST_HOME = cpputest
OUTPUT_DIR=$(PROJECT_HOME_DIR)/output
CPPUTEST_OBJS_DIR=$(OUTPUT_DIR)/build
CPPUTEST_LIB_DIR=$(CPPUTEST_OBJS_DIR)/lib

CPPUTEST_WARNINGFLAGS += -Wno-c++14-compat #no warning for the -Werror=c++14-compat#

CPPUTEST_USE_EXTENSIONS=Y
CPP_PLATFORM = Gcc
CPPUTEST_WARNINGFLAGS+= -Werror -Wall

SRC_DIRS = \
	$(LIB)/Gpio \
	$(LIB)/Interfaces \
	$(LIB)/SystemInclude \

TEST_SRC_DIRS = \
	Testing/ \
	Testing/Tests/Gpio/ \

INCLUDE_DIRS =\
	$(SRC_DIRS) \
	$(TEST_SRC_DIRS) \
	$(CPPUTEST_HOME)/include \

include $(CPPUTEST_HOME)/build/MakefileWorker.mk

$(CPPUTEST_HOME)/lib/libCppUTest.a:
	cd $(CPPUTEST_HOME) && ./autogen.sh && ./configure
	make -C $(CPPUTEST_HOME)

$(CPPUTEST_HOME)/lib/libCppUTestExt.a: $(CPPUTEST_HOME)/lib/libCppUTest.a
