CXX := g++
CXXFLAGS := -Wall

INCLUDE := include
BIN := bin
BUIDDIR := build
SRCDIR := src

SOURCES = $(shell find $(SRCDIR) -type f -name *.cpp)
OBJECTS = $(patsubst $(SRCDIR)/%.cpp,$(BUIDDIR)/%.o,$(SOURCES))
TARGET = AnimalShelter

$(TARGET): $(OBJECTS)
	@mkdir -p $(BIN)
	@echo ..............................
	@echo generating the executable in bin directory
	$(CXX) $(CXXFLAGS) -o $(BIN)/$@ $^

$(BUIDDIR)/%.o: $(SRCDIR)/%.cpp
	@mkdir -p $(BUIDDIR)
	@echo ..............................
	@echo generating object $@
	@echo depends on $^
	$(CXX) $(CXXFLAGS) -I $(INCLUDE) -c -o $@ $^

partial_clean: 
	@rm -rf $(BUIDDIR)
	@echo ..............................
	@echo Removing build directory, not removing bin directory
clean:
	@rm -rf $(BUIDDIR) $(BIN)
	@echo ..............................
	@echo Removing build and bin directories

