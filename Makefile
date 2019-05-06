#Makefile du projet othello - L2 Informatique UPVD 2018-2019
#Réaliser par BESSAI Sofiane

#include
include_dir = include
SDL2_dir = $(include_dir)/SDL2-2.0.9
TTF_dir = $(include_dir)/SDL2_ttf-2.0.15
FT_dir = $(include_dir)/freetype-2.9

#library
lib_dir = lib

#source
src_dir = src

#objet
obj_dir = obj

#global
CC = gcc
LDFLAGS = `sdl2-config --libs --cflags` -lSDL_ttf -lm
CFLAGS = -W -Wall
EXEC = othello
INCLUDES = $(wildcard $(include_dir)/*.h)
SRC = $(wildcard $(src_dir)/*.c)
OBJ = $(SRC:$(src_dir)/%.c=$(obj_dir)/%.o)

######################################################################

# Cible            : fictive (make VARIABLE)
# Dépendances      : la cible $(EXEC) (othello)
# Actions          : affiche le contenu de la variable
print-%  : ; @echo $* = $($*)

# Cible            : defaut (make)
# Dépendances      : la cible $(EXEC) (othello)
# Actions          : lance la création de l'éxecutable
all	: $(EXEC)
	@echo "DONE"

# Cible            : fictive (make othello)
# Dépendances      : main.o
# Actions          : construit l'executable a partir des fichiers objets
$(EXEC)	: $(OBJ)
	@echo "Création de l'éxecutable"
	@$(CC) -o $@ $^ $(LDFLAGS)
	@echo "Création de l'éxecutable : OK"

# Cible            : fictive (make )
# Dépendances      : les fichier inclus
# Actions          : crée le .o du fichier principal
main.o	: $(INCLUDES)

# Cible            : fictive (make )
# Dépendances      : le .c associé
# Actions          : crée chaque .o à partir d'un .c
$(obj_dir)/%.o : $(src_dir)/%.c
	@echo Création de $*.o
	@$(CC) -o $@ -c $< $(CFLAGS)
	@echo Création de $*.o : OK

# Cible            : fictive (make clean)
# Dépendances      :
# Actions          : supprime l'ensemble des fichiers objets
clean	:
	rm -f $(obj_dir)/*.o

# Cible            : fictive (make mrproper)
# Dépendances      :
# Actions          : supprime l'executable
mrproper: clean
	rm -rf $(EXEC)

# Cible            : fictive (make .PHONY)
# Dépendances      :
# Actions          : execution de clean et mrproper
.PHONY	: clean mrproper
