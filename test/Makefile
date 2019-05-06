#Makefile du projet othello - L2 Informatique UPVD 2018-2019
#Réaliser par BESSAI Sofiane

CC = gcc
LDFLAGS = `sdl2-config --libs --cflags` -lSDL_ttf -lcunit -lm
CFLAGS = -W -Wall
LINK = ../obj/othello_logic.o ../obj/othello_draw.o ../obj/othello_system.o ../obj/othello_IA.o
EXEC = test
INCLUDES =
SRC =
OBJ =

############################################################

# Cible
# Dépendances
# Actions
all : $(EXEC)
	@echo "DONE"

# Cible
# Dépendances
# Actions
$(EXEC) : ./obj/test_logic.o ./obj/test_draw.o ./obj/test_system.o ./obj/test_IA.o ./obj/main.o
	@echo "Création de l'éxecutable"
	@$(CC) -o $@ $^ $(LINK) $(LDFLAGS)
	@echo "Création de l'éxecutable : OK"

# Cible
# Dépendances
# Actions
./obj/main.o : ./src/main.c
	@echo Création de $*.o
	$(CC) -o $@ -c $< $(CFLAGS)
	@echo Création de $*.o : OK

# Cible
# Dépendances
# Actions
./obj/test_logic.o : ./src/test_logic.c
	@echo Création de $*.o
	$(CC) -o $@ -c $< $(CFLAGS)
	@echo Création de $*.o : OK

# Cible
# Dépendances
# Actions
./obj/test_draw.o : ./src/test_draw.c
	@echo Création de $*.o
	$(CC) -o $@ -c $< $(CFLAGS)
	@echo Création de $*.o : OK

# Cible
# Dépendances
# Actions
./obj/test_system.o : ./src/test_system.c
	@echo Création de $*.o
	$(CC) -o $@ -c $< $(CFLAGS)
	@echo Création de $*.o : OK

# Cible
# Dépendances
# Actions
./obj/test_IA.o : ./src/test_IA.c
	@echo Création de $*.o
	$(CC) -o $@ -c $< $(CFLAGS)
	@echo Création de $*.o : OK

############################################################

# Cible            : fictive (make clean)
# Dépendances      :
# Actions          : supprime l'ensemble des fichiers objets
clean	:
	rm -f ./obj/*.o

# Cible            : fictive (make mrproper)
# Dépendances      :
# Actions          : supprime l'executable
mrproper: clean
	rm -rf $(EXEC)
