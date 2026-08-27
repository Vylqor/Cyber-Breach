# ==========================================
# Cyber Breach - Makefile
# ==========================================

CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -O2

TARGET = cyberbreach
SOURCE = main.cpp

# Compiler le jeu
all: $(TARGET)

$(TARGET): $(SOURCE)
	$(CXX) $(CXXFLAGS) $(SOURCE) -o $(TARGET)

# Compiler puis lancer le jeu
run: $(TARGET)
	./$(TARGET)

# Installer le jeu dans /usr/local/bin
install: $(TARGET)
	sudo install -m 755 $(TARGET) /usr/local/bin/$(TARGET)

# Désinstaller le jeu
uninstall:
	sudo rm -f /usr/local/bin/$(TARGET)

# Supprimer les fichiers compilés
clean:
	rm -f $(TARGET)

# Recompiler complètement
rebuild: clean all

# Afficher l'aide
help:
	@echo "Cyber Breach - Commandes disponibles :"
	@echo ""
	@echo "  make          - Compiler le jeu"
	@echo "  make run      - Compiler et lancer le jeu"
	@echo "  make install  - Installer le jeu sur le systeme"
	@echo "  make uninstall- Desinstaller le jeu"
	@echo "  make clean    - Supprimer le fichier compile"
	@echo "  make rebuild  - Recompiler completement"
