# Définir le compilateur et les options
CXX := g++
INCS := -Iinclude -Iinclude/SFML
LIBS := -Llib/SFML -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio
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
all: $(TARGET) copy-assets

# Règle pour créer l'exécutable
$(TARGET): $(OBJECTS)
	@echo "Linking $(notdir $@)"
	@mkdir -p $(BUILD_DIR)
	@$(CXX) $(CXXFLAGS) $(OBJECTS) $(LIBS) -o $@
	@rm $(OBJECTS)

# Règle pour compiler les fichiers .cpp en fichiers .o
$(BUILD_DIR)/%.o: $(SRC_DIR)/**/%.cpp
	@echo "Compiling file : $(notdir $<)"
	@mkdir -p $(BUILD_DIR)
	@$(CXX) $(CXXFLAGS) $(INCS) -c $< -o $@

# Règle pour copier les assets dans build/assets
copy-assets:
	@if [ -d assets ]; then \
        mkdir -p $(BUILD_DIR)/assets; \
        echo "Copying assets..."; \
        cp -r assets/* $(BUILD_DIR)/assets; \
    else \
        echo "No assets directory found. Skipping."; \
    fi

# Cible de nettoyage
clean:
	rm -rf $(BUILD_DIR)/*
