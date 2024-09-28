# Définir le compilateur et les options
CXX := g++
CXXFLAGS := -Wall -g -Iinclude

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
	$(CXX) $(CXXFLAGS) -o $@ $^

# Règle pour compiler les fichiers .cpp en fichiers .o
# Notez que nous devons extraire le nom du fichier de source de la variable $< pour cette règle.
$(BUILD_DIR)/%.o: $(SRC_DIR)/%/*.cpp
	@mkdir -p $(BUILD_DIR)  # S'assurer que le répertoire build existe
	$(CXX) $(CXXFLAGS) -c $< -o $@  # Compiler le fichier source

# Cible de nettoyage
clean:
	rm -rf $(BUILD_DIR)/*
