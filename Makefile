
CC = g++
NAME = abstract_vm

DEFAULT_CFLAGS = -std=c++11
ifeq ($(MAKE_CFLAGS),)
	MAKE_CFLAGS := -Wall -Wextra -Werror
endif

CFLAGS := $(MAKE_CFLAGS) $(DEFAULT_CFLAGS)

SOURCES = Operand.cpp \
						MyException.cpp \
						Lexer.cpp \
						Parser.cpp \
						Vm.cpp \
						OperandBuilder.cpp \

SOURCES_FOLDER = sources

TEST_FORDER = test
INCLUDES_FOLDER = includes
OBJECTS_FOLDER = .objects
MAIN = main.cpp
MAIN_OBJECT = $(OBJECTS_FOLDER)/$(MAIN:.cpp=.o)
INCLUDES = $(NAME).hpp \
			IOperand.hpp \
			Operand.hpp \
			MyException.hpp \
			Lexer.hpp \
			Parser.hpp \
			Vm.hpp \
			OperandBuilder.hpp \

SOURCES_DEPENDENCIES = $(foreach dep, $(DEPENDENCIES), libraries/$(dep)/$(dep).a)
INCLUDES_LIBRARIES = $(foreach dep,$(DEPENDENCIES),-I libraries/$(dep)/includes)
HEADERS_LIBRARIES = $(foreach dep,$(DEPENDENCIES),libraries/$(dep)/includes/$(dep).h)
MAKE_LIBRARIES = $(foreach dep,$(DEPENDENCIES),make -C libraries/$(dep);)
REBUILD_LIBRARIES = $(foreach dep,$(DEPENDENCIES),make re -C libraries/$(dep);)

OBJECTS = $(SOURCES:%.cpp=%.o)

all: init makelib $(NAME)

rebuild: fclean init rebuildlib $(NAME)

makelib:
	$(MAKE_LIBRARIES)

rebuildlib:
	$(REBUILD_LIBRARIES)

test: re test.cpp $(addprefix $(OBJECTS_FOLDER)/$(SOURCES_FOLDER)/, $(OBJECTS))
	$(CC) $(CFLAGS) -I $(INCLUDES_FOLDER) -o $(OBJECTS_FOLDER)/test.o -c test.cpp $(INCLUDES_LIBRARIES)
	$(CC) $(CFLAGS) -o out_test $(OBJECTS_FOLDER)/test.o $(addprefix $(OBJECTS_FOLDER)/$(SOURCES_FOLDER)/, $(OBJECTS)) $(SOURCES_DEPENDENCIES)
	@./out_test

start: all
	@./$(NAME)

init:
	@mkdir -p $(OBJECTS_FOLDER)/$(SOURCES_FOLDER)

$(NAME): $(MAIN_OBJECT) $(addprefix $(OBJECTS_FOLDER)/$(SOURCES_FOLDER)/, $(OBJECTS))
	$(CC) $(CFLAGS) -o $@ $(MAIN_OBJECT) $(addprefix $(OBJECTS_FOLDER)/$(SOURCES_FOLDER)/, $(OBJECTS)) $(SOURCES_DEPENDENCIES)

$(MAIN_OBJECT): $(MAIN)
	$(CC) $(CFLAGS) -I $(INCLUDES_FOLDER) -o $(MAIN_OBJECT) -c $(MAIN) $(INCLUDES_LIBRARIES)

$(addprefix $(OBJECTS_FOLDER)/$(SOURCES_FOLDER)/, %.o): $(SOURCES_FOLDER)/%.cpp $(addprefix $(INCLUDES_FOLDER)/, $(INCLUDES)) $(HEADERS_LIBRARIES)
	$(CC) $(CFLAGS) -I $(INCLUDES_FOLDER) -o $@ -c $< $(INCLUDES_LIBRARIES)

clean:
	rm -f $(addprefix $(OBJECTS_FOLDER)/$(SOURCES_FOLDER)/, $(OBJECTS))
	rm -f $(MAIN_OBJECT)
	rm -rf $(OBJECTS_FOLDER)

fclean: clean
	rm -f $(NAME)

re: fclean all
