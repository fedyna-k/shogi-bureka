# Compilator's variables

CC 		= gcc
CFLAGS 	= -g -Wall -I include -I include/SDL2 -L lib -lmingw32 -lSDL2main -lSDL2 -lSDL2_image -lSDL2_ttf -mwindows # Add SDL support on the linker
RM	 	= del	# Windows = del // Unix = rm

SOURCEDIR = src
OBJECTDIR = obj
OUTPUTDIR = bin

FILES 	:= $(wildcard $(SOURCEDIR)/*.c)
OBJ 	:= $(FILES:$(SOURCEDIR)%.c=$(OBJECTDIR)%.o)

# Compiling

.PHONY: all
all: main

main: $(OBJ)
	$(CC) $^ -o $(OUTPUTDIR)/$@ $(CFLAGS)

# All files obj compilation

$(OBJECTDIR)/%.o: $(SOURCEDIR)/%.c
	$(CC) -c $< -o $@ $(CFLAGS)


# May come in handy

clear:
	$(RM) $(OUTPUTDIR)\main
	$(RM) $(OBJECTDIR)\*.o

# Recompile everthing

again:
	$(RM) $(OBJECTDIR)\*.o
	make