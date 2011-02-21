CXX = g++
CXXFLAGS = -O2 -Wall -o
DEBUGFLAGS =
RM = rm -f

INCLUDES = $(wildcard src/*.h)
OBJECTS = $(patsubst src/%.cc,obj/%.o,$(wildcard src/*.cc))
TARGET = bin/langton

all:	$(TARGET)

clean:
	$(RM) $(TARGET) $(OBJECTS)

$(TARGET):	$(OBJECTS)
	$(CXX) $(DEBUGFLAGS) $(CXXFLAGS) $(TARGET) $(OBJECTS)

$(OBJECTS):	obj/%.o : src/%.cc $(INCLUDES)
	$(CXX) -c $(DEBUGFLAGS) $(CXXFLAGS) $@ $<

