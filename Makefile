#
#  Version 1.0
#
PROJECT=cplusutil
VERSION=1.0

OS=Linux
CXX=g++
CXXFLAGS=-std=c++11 -m64

TARGET=build
BIN=bin
LIB=lib
EXT=ext

SRC= $(PROJECT)/src
TARGETSHARED = $(PROJECT).so.1.0
TARGETSTATIC = $(PROJECT).$(VERSION).a

SOURCES=$(wildcard $(SRC)/*.cpp)
OBJECTS=$(patsubst $(SRC)/%.cpp,$(TARGET)/$(EXT)/%.o,$(SOURCES))

LDLIBSOPTIONS=-L/usr/local/lib -lboost_filesystem -lboost_system

# all:
# 	# @echo $(SOURCES) "\n"
# 	# @echo "Object files:"
# 	# @echo $(OBJECTS)
#
# all: clean directories demo staticlib
all: clean directories demo shared static

directories:
	mkdir -p $(TARGET)/$(BIN)
	mkdir -p $(TARGET)/$(LIB)
	mkdir -p $(TARGET)/$(EXT)

demo: $(OBJECTS)
	$(CXX) $(CXXFLAGS) $(OBJECTS) -o $(TARGET)/$(BIN)/demo$(PROJECT).$(VERSION) $(LDLIBSOPTIONS)

shared: $(OBJECTS)
	$(CXX) $(CXXFLAGS) $(LDLIBSOPTIONS) -Wall -shared -Wl,-soname, $(TARGET)/$(EXT)/*.o -o $(TARGET)/$(LIB)/lib$(TARGETSHARED)

$(TARGET)/$(EXT)/%.o: $(SRC)/%.cpp
	   $(CXX) $(CXXFLAGS) -fPIC -c $< -o $@

static: $(OBJECTS)
	ar -rv $(TARGET)/$(LIB)/lib$(TARGETSTATIC) $(OBJECTS)


clean:
	rm -rf build
