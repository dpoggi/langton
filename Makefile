CXXFLAGS = -I. -O2 -Wall
RM = rm -f

OBJECTS = $(patsubst src/%.cc,obj/%.o,$(wildcard src/*.cc))
TARGET = bin/langton

all:	$(TARGET)

clean:
	$(RM) $(TARGET) $(OBJECTS)

$(TARGET):	$(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $@ $^

obj/%.o:	src/%.cc
	$(CXX) $(CXXFLAGS) -c -o $@ $^
