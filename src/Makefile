CXX      = g++

.DEFAULT_GOAL := all

BINOME=11409933_11512256

SOURCES = 
SOURCES += melangeur.cpp
SOURCES += case.cpp
SOURCES += mur.cpp
SOURCES += couleurs.cpp
SOURCES += tuile.cpp
SOURCES += direction.cpp
SOURCES += site.cpp
SOURCES += graphe.cpp
SOURCES += noeud.cpp
SOURCES += arete.cpp
SOURCES += unionfind.cpp
SOURCES += cellule.cpp
SOURCES += liste.cpp
SOURCES += plateau.cpp
SOURCES += cell.cpp
SOURCES += file-prio.cpp
SOURCES += skip-list.cpp

OBJECTS = $(SOURCES:.cpp=.o)

CXXFLAGS  += -g -Wall -std=c++11 -pedantic
LDFLAGS +=

$(OBJECTS) : %.o : %.cpp
	$(CXX) -MMD $(CXXFLAGS) -c $< -o $@

CLEAN_OBJECTS = $(OBJECTS)
TARGETS = 

########## test_melangeur ##########

MELANGEUR_SOURCES = test_melangeur.cpp
MELANGEUR_OBJECTS = $(MELANGEUR_SOURCES:.cpp=.o)

test_melangeur : $(MELANGEUR_OBJECTS) $(OBJECTS) $(HEADERS)
	$(CXX) $(MELANGEUR_OBJECTS) $(OBJECTS) -o $@ $(LDFLAGS)
	
$(MELANGEUR_OBJECTS): %.o : %.cpp
	$(CXX) -MMD $(CXXFLAGS) -c $< -o $@

all : test_melangeur
TARGETS += test_melangeur
CLEAN_OBJECTS += $(MELANGEUR_OBJECTS)

########## test_tuile ##########

TUILE_SOURCES = test_tuile.cpp
TUILE_OBJECTS = $(TUILE_SOURCES:.cpp=.o)

test_tuile : $(TUILE_OBJECTS) $(OBJECTS) $(HEADERS)
	$(CXX) $(TUILE_OBJECTS) $(OBJECTS) -o $@ $(LDFLAGS)
	
$(TUILE_OBJECTS): %.o : %.cpp
	$(CXX) -MMD $(CXXFLAGS) -c $< -o $@

all : test_tuile
TARGETS += test_tuile
CLEAN_OBJECTS += $(TUILE_OBJECTS)

########## test_plateau ##########

PLATEAU_SOURCES = test_plateau.cpp
PLATEAU_OBJECTS = $(PLATEAU_SOURCES:.cpp=.o)

test_plateau : $(PLATEAU_OBJECTS) $(OBJECTS) $(HEADERS)
	$(CXX) $(PLATEAU_OBJECTS) $(OBJECTS) -o $@ $(LDFLAGS)
	
$(PLATEAU_OBJECTS): %.o : %.cpp
	$(CXX) -MMD $(CXXFLAGS) -c $< -o $@

all : test_plateau
TARGETS += test_plateau
CLEAN_OBJECTS += $(PLATEAU_OBJECTS)

########## test_liste ##########

LISTE_SOURCES = test_liste.cpp
LISTE_OBJECTS = $(LISTE_SOURCES:.cpp=.o)

test_liste : $(LISTE_OBJECTS) $(OBJECTS) $(HEADERS)
	$(CXX) $(LISTE_OBJECTS) $(OBJECTS) -o $@ $(LDFLAGS)
	
$(LISTE_OBJECTS): %.o : %.cpp
	$(CXX) -MMD $(CXXFLAGS) -c $< -o $@

all : test_liste
TARGETS += test_liste
CLEAN_OBJECTS += $(LISTE_OBJECTS)

########## cleanup ##########
DEPS = $(CLEAN_OBJECTS:.o=.d)

clean:
	@rm -f $(DEPS) $(TARGETS) $(CLEAN_OBJECTS)

-include $(DEPS)

archive:
	mkdir ../rendu
	cp -r ../assets ../src ../README.md ../rendu
	tar -cvf ../rendu_$(BINOME).tar ../rendu
	gzip ../rendu_$(BINOME).tar
	rm -r ../rendu