OUT = out
SRC = src
INCLUDE = include
TEST= test
FLAGS=-Wall -g

compila_test_nodo:
	g++$(FLAGS) $(TEST)/test_nodo.cpp -o $(OUT)/test_nodo

compila_test_lib:
	g++ -g  $(TEST)/test_lib.cpp -o $(OUT)/test_lib

compila_test_init_alberi:
	g++ $(FLAGS)  $(TEST)/test_init_alberi.cpp -o $(OUT)/test_init_alberi

complila_test_adiacenza_vector:
	g++ -g $(TEST)/test_adiacenza_vector.cpp -o $(OUT)/test_adiacenza_vector

compila_modifica:
	g++  $(TEST)/modifiche_simplesso.cpp -o $(OUT)/modifiche_simplesso

compila_disegna:
	g++ $(TEST)/disegna.cpp -o $(OUT)/disegna

compila_disegno_totale:
	g++ test/disegna_totale.cpp -o out/disegno_totale

test_nodo:compila_test_nodo
	./$(OUT)/test_nodo

test_lib:compila_test_lib
	./$(OUT)/test_lib

test_init_alberi:compila_test_init_alberi
	./$(OUT)/test_init_alberi

test_adiacenza_vector:complila_test_adiacenza_vector
	./$(OUT)/test_adiacenza_vector 

modifiche_simplesso:compila_modifica
	cd out; ./modifiche_simplesso;cd ..

disegna:compila_disegna
	./$(OUT)/disegna

disegna_totale:compila_disegno_totale
	./$(OUT)/disegno_totale
clean:
	rm -v $(OUT)/test
