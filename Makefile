# Compilator's variables

CC 		= gcc
CFLAGS 	= -Iinclude -Iinclude\SDL2 -L lib -lmingw32 -lSDL2main -lSDL2 # Add SDL support on the linker
RM	 	= del	# Windows = del // Unix = rm

SOURCEDIR = src
OUTPUTDIR = bin

FILES 	= $(wildcard $(SOURCEDIR)/*.c)
OBJ 	= $(FILES:.c=.o)

all: main

# Compiling

main: $(OBJ)
	$(CC) $(CFLAGS) $^ -o $(OUTPUTDIR)/$@
	$(RM) $(SOURCEDIR)\*.o
	$(OUTPUTDIR)/main

# All files obj compilation

$(SOURCEDIR)/%.o: $(SOURCEDIR)/%.c $(SOURCEDIR)/%.h
	$(CC) $(CFLAGS) -o $@ -c $<

# May come in handy

clear:
	$(RM) $(SOURCEDIR)\*.o ; $(RM) $(OUTPUTDIR)\main