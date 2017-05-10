
#
#  Version 1.0
#
OS=Linux
VERSION=1_0
CXX=g++
CXXFLAGS=-std=c++11 -m64
TARGET=build
BIN=bin
STATICLIB=lib
EXT=ext

SRC= cplusutil/src
SOURCES=$(wildcard $(SRC)/*.cpp)
OBJECTS=$(patsubst $(SRC)/%.cpp,$(TARGET)/$(EXT)/%.o,$(SOURCES))

LDLIBSOPTIONS=-L/usr/local/lib -lboost_filesystem -lboost_system

# all:
# 	# @echo $(SOURCES) "\n"
# 	# @echo "Object files:"
# 	# @echo $(OBJECTS)
#
# all: clean directories demo staticlib
all: clean directories demo staticlib

directories:
	mkdir -p $(TARGET)/$(BIN)
	mkdir -p $(TARGET)/$(STATICLIB)
	mkdir -p $(TARGET)/$(EXT)

demo: $(OBJECTS)
	$(CXX) $(CXXFLAGS) $(OBJECTS) -o $(TARGET)/$(BIN)/demo $(LDLIBSOPTIONS)

$(TARGET)/$(EXT)/%.o: $(SRC)/%.cpp
	   $(CXX) $(CXXFLAGS) -c $< -o $@

staticlib: $(OBJECTS)
	ar -rv $(TARGET)/$(STATICLIB)/cplusutil_$(VERSION).a $(OBJECTS)

clean:
	rm -rf build
