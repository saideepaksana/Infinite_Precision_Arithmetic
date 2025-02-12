CXX=g++
CXXFLAGS=-c -Wall
SOURCES=implementation.cpp
OBJECTS=$(SOURCES:.cpp=.o)
LIBRARY=lib_infinite_arithmetic.a
EXECUTABLE=my_inf_arith

all: $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CXX) $(OBJECTS) -o $@

.cpp.o:
	$(CXX) $(CXXFLAGS) $< -o $@

$(LIBRARY): $(OBJECTS)
	ar rcs $@ $(OBJECTS)

clean:
	rm -rf $(OBJECTS) $(EXECUTABLE) $(LIBRARY)