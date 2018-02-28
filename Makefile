LDFLAGS = -lsfml-graphics -lsfml-window -lsfml-system -lsfml-network
EXEC = debug


all: $(EXEC)

debug: obj/interfaceDebian.o obj/FenetreJeu.o obj/Main.o obj/Entite.o obj/Unite.o obj/Batiment.o obj/Bouton.o obj/Menu.o obj/TileMap.o obj/VueNiveauEntier.o obj/VueNiveauRapproche.o obj/VuePanneauBatiment.o obj/VuePanneau.o obj/VuePanneauUnite.o
	mkdir bin
	g++ $^ -o bin/$@ $(LDFLAGS)

obj/interfaceDebian.o: systemes/interfaceDebian.cpp
	g++ -c $^ -o $@

obj/FenetreJeu.o: src/FenetreJeu.cpp
	g++ -c $^ -o $@

obj/Main.o: src/Main.cpp
	g++ -c $^ -o $@

obj/Entite.o: src/modele/Entite.cpp
	g++ -c $^ -o $@

obj/Unite.o: src/modele/Unite.cpp
	g++ -c $^ -o $@

obj/Batiment.o: src/modele/Batiment.cpp
	g++ -c $^ -o $@

obj/Bouton.o: src/views/Bouton.cpp
	g++ -c $^ -o $@

obj/Menu.o: src/views/Menu.cpp
	g++ -c $^ -o $@

obj/TileMap.o: src/views/TileMap.cpp
	g++ -c $^ -o $@

obj/VueNiveauEntier.o: src/views/VueNiveauEntier.cpp
	g++ -c $^ -o $@

obj/VueNiveauRapproche.o: src/views/VueNiveauRapproche.cpp
	g++ -c $^ -o $@

obj/VuePanneau.o: src/views/VuePanneau.cpp
	g++ -c $^ -o $@

obj/VuePanneauUnite.o: src/views/VuePanneauUnite.cpp
	g++ -c $^ -o $@

obj/VuePanneauBatiment.o: src/views/VuePanneauBatiment.cpp
	g++ -c $^ -o $@

clean:
	rm -rf obj/*.o
	rm -r bin/

mrproper: clean
	rm -rf bin/
