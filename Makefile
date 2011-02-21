include Makefile.inc

INCLUDES = $(wildcard src/*.h)
OBJECTS = $(patsubst src/%.cc,obj/%.o,$(wildcard src/*.cc))
TARGET = bin/langton

all:	$(TARGET)

clean:
	$(RM) $(TARGET) $(OBJECTS)

$(TARGET):	$(OBJECTS)
	$(LD) $(LDFLAGS) -o $(TARGET) $(OBJECTS)

$(OBJECTS):	obj/%.o : src/%.cc $(INCLUDES)
	$(CXX) -c -I. $(CXXFLAGS) -o $@ $<
