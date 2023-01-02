# Compilator's variables

CC 		= gcc
CFLAGS 	= -I include -I include/SDL2 -L lib -lmingw32 -lSDL2main -lSDL2 -mwindows # Add SDL support on the linker
RM	 	= del	# Windows = del // Unix = rm

SOURCEDIR = src
OUTPUTDIR = bin

FILES 	= $(wildcard $(SOURCEDIR)/*.c)
OBJ 	= $(FILES:.c=.o)

all: main

# Compiling

main: $(OBJ)
	$(CC) $^ -o $(OUTPUTDIR)/$@ $(CFLAGS)
	$(RM) $(SOURCEDIR)\*.o
	$(OUTPUTDIR)/main

# All files obj compilation

$(SOURCEDIR)/%.o: $(SOURCEDIR)/%.c $(SOURCEDIR)/%.h
	$(CC) -c $< -o $@ $(CFLAGS)

# May come in handy

clear:
	$(RM) $(SOURCEDIR)\*.o ; $(RM) $(OUTPUTDIR)\main