all:derle bagla calistir
derle:
	g++ -c -I "./include" ./src/main.cpp -o ./lib/main.o
	g++ -c -I "./include" ./src/Queue.cpp -o ./lib/Queue.o
	g++ -c -I "./include" ./src/Dugum.cpp -o ./lib/Dugum.o
	g++ -c -I "./include" ./src/Radix.cpp -o ./lib/Radix.o	
	g++ -c -I "./include" ./src/ikiliAramaAgaci.cpp -o ./lib/ikiliAramaAgaci.o	
	g++ -c -I "./include" ./src/Kontrol.cpp -o ./lib/Kontrol.o	
	g++ -c -I "./include" ./src/Organ.cpp -o ./lib/Organ.o
	g++ -c -I "./include" ./src/Organizma.cpp -o ./lib/Organizma.o
	g++ -c -I "./include" ./src/TestProgram.cpp -o ./lib/TestProgram.o
	g++ -c -I "./include" ./src/Doku.cpp -o ./lib/Doku.o

bagla:
	 g++ ./lib/Dugum.o ./lib/Radix.o ./lib/Queue.o ./lib/main.o ./lib/Doku.o ./lib/ikiliAramaAgaci.o ./lib/Kontrol.o ./lib/Organ.o ./lib/Organizma.o ./lib/TestProgram.o -o ./bin/program
calistir:
	./bin/program.exe