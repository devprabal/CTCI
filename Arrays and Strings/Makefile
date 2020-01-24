# my first makefile
CXX =	g++
CXXFLAGS = -Wall
zero: zeroMatrix.o printMatrix.o createSqrMatrix.o 
	$(CXX) $(CXXFLAGS) build/zeroMatrix.o build/printMatrix.o build/createSqrMatrix.o -o bin/zero
zeroMatrix.o: printMatrix.h createSqrMatrix.h
	$(CXX) $(CXXFLAGS) -I include -c zeroMatrix.cpp -o build/zeroMatrix.o
printMatrix.o: printMatrix.h
	$(CXX) $(CXXFLAGS) -I include -c printMatrix.cpp -o build/printMatrix.o
createSqrMatrix.o: createSqrMatrix.h
	$(CXX) $(CXXFLAGS) -I include -c createSqrMatrix.cpp -o build/createSqrMatrix.o
printMatrix.h:

createSqrMatrix.h:

clean:
	rm build/*.o bin/zero

