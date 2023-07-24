all: derle bagla calisrir

derle:
	g++ -I "./include" -c ./src/YoneticiListesi.cpp -o ./lib/YoneticiListesi.o
	g++ -I "./include" -c ./src/SatirListe.cpp -o ./lib/SatirListe.o
	g++ -I "./include" -c ./src/main.cpp -o ./lib/main.o
bagla:
	g++ ./lib/main.o ./lib/YoneticiListesi.o ./lib/SatirListe.o -o ./bin/program
calisrir:
	./bin/program
