# # ID: 319055430
# # Email: noa.fishman@gmail.com

# Compiler
CC = g++

# Compiler flags
CFLAGS = -Wall -Wextra -std=c++11 -Werror

# SFML library paths (update these paths to match your installation if necessary)
SFML_INCLUDE_DIR = /usr/include
SFML_LIB_DIR = /usr/lib/x86_64-linux-gnu

# Linker flags for SFML
LDFLAGS = -lsfml-graphics -lsfml-window -lsfml-system

# Source files
SRCS = Demo.cpp Ex4.cpp TestCounter.cpp test.cpp

# Object files
OBJS = $(SRCS:.cpp=.o)

# Executable files
DEMO = Demo
EX = Ex4
TEST = Test

# Targets
all: $(DEMO) $(EX) $(TEST)

Ex4: $(EX)

test_target: $(TEST)

demo_target: $(DEMO)

#do the run after make
ex4: Ex4
	./$(EX)

test: test_target
	./$(TEST)

demo: demo_target
	./$(DEMO)

$(DEMO): $(filter-out TestCounter.o test.o doctest.o Ex4.o, $(OBJS))
	$(CC) $(CFLAGS) $^ -o $@ -L$(SFML_LIB_DIR) $(LDFLAGS)

$(EX): $(filter-out TestCounter.o test.o doctest.o Demo.o, $(OBJS))
	$(CC) $(CFLAGS) $^ -o $@ -L$(SFML_LIB_DIR) $(LDFLAGS)

$(TEST): TestCounter.o test.o
	$(CC) $(CFLAGS) $^ -o $@ -L$(SFML_LIB_DIR) $(LDFLAGS)


# Rule to compile .cpp files to .o files
%.o: %.cpp
	$(CC) $(CFLAGS) -I$(SFML_INCLUDE_DIR) -c $< -o $@

# Clean
clean:
	rm -f $(OBJS) $(DEMO) $(EX) $(TEST)


