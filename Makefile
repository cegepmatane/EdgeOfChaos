LDFLAGS = -lsfml-graphics -lsfml-window -lsfml-system -lsfml-network -pthread
EXEC = debug


all: init $(EXEC)

debug: obj/ActionClic.o obj/Niveau.o obj/interfaceDebian.o obj/FenetreJeu.o obj/Main.o obj/Entite.o obj/Unite.o obj/Batiment.o obj/Bouton.o obj/Menu.o obj/Carte.o obj/VueNiveauEntier.o obj/VueNiveauRapproche.o obj/VuePanneauBatiment.o obj/VuePanneau.o obj/VuePanneauUnite.o
	g++ -g $^ -o bin/$@ $(LDFLAGS)

obj/interfaceDebian.o: systemes/interfaceDebian.cpp
	g++ -c $^ -o $@

obj/%.o: src/%.cpp
	g++ -c $< -o $@

obj/%.o: src/views/%.cpp
	g++ -c $< -o $@

obj/%.o: src/modele/%.cpp
	g++ -c $< -o $@

clean:
	rm -rf obj/*.o
	rm -rf bin/

mrproper: clean
	rm -rf obj/

init:
	mkdir bin/
	mkdir obj/
