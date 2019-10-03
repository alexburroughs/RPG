#OBJS specifies which files to compile as part of the project
OBJS = src/*

#CC specifies which compiler we're using
CC = g++

#COMPILER_FLAGS specifies the additional compilation options we're using
# -w suppresses all warnings
COMPILER_FLAGS = -w

#LINKER_FLAGS specifies the libraries we're linking against
LINKER_FLAGS = -lSDL2
W_FLAGS = -I "library\i686-w64-mingw32\include\SDL2" -L "library\i686-w64-mingw32\lib" -w -Wl,-subsystem,windows -lmingw32 -lSDL2main -lSDL2

#OBJ_NAME specifies the name of our exectuable
OBJ_NAME = game
W_OBJ_NAME = game.exe

#This is the target that compiles our executable
all : $(OBJS)
	$(CC) $(OBJS) $(COMPILER_FLAGS) $(LINKER_FLAGS) -o $(OBJ_NAME)

windows : $(OBJS)
	    $(CC) $(OBJS) $(W_FLAGS) -o $(W_OBJ_NAME)
