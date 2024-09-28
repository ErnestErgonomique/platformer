# Définir le compilateur et les options
CXX := g++
INCS := -Iinclude -ID:/Program\ Files/SFML-2.6.1/include
LIBS := -LD:/Program\ Files/SFML-2.6.1/lib -lsfml-graphics -lsfml-window -lsfml-system
CXXFLAGS := -Wall -g

# Définir les répertoires
SRC_DIR := src
BUILD_DIR := build

# Trouver tous les fichiers .cpp dans les sous-dossiers de src/
SOURCES := $(wildcard $(SRC_DIR)/**/*.cpp)

# Générer les fichiers objets en conservant le chemin du fichier source
OBJECTS := $(addprefix $(BUILD_DIR)/,$(notdir $(SOURCES:.cpp=.o)))

# Définir la cible de l'exécutable
TARGET := $(BUILD_DIR)/game.exe

# Cible par défaut
all: $(TARGET)

# Règle pour créer l'exécutable
$(TARGET): $(OBJECTS)
	@mkdir -p $(BUILD_DIR)  # Créer le répertoire de l'exécutable s'il n'existe pas
	$(CXX) $(CXXFLAGS) $(OBJECTS) $(LIBS) -o $@

# Règle pour compiler les fichiers .cpp en fichiers .o
$(BUILD_DIR)/%.o: $(SRC_DIR)/%/*.cpp
	@mkdir -p $(BUILD_DIR)  # S'assurer que le répertoire build existe
	$(CXX) $(CXXFLAGS) $(INCS) -c $< -o $@  # Compiler le fichier source

# Cible de nettoyage
clean:
	rm -rf $(BUILD_DIR)/*
