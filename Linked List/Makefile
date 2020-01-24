loopDetection: loopDetection.o Node.o printLinkedList.o makeCyclicLinkedList.o random_x_y.o
	g++ build/loopDetection.o build/Node.o build/printLinkedList.o build/makeCyclicLinkedList.o build/random_x_y.o -o bin/loopDetection
loopDetection.o: Node.h printLinkedList.h makeCyclicLinkedList.h
	g++ -I include -c loopDetection.cpp -o build/loopDetection.o
Node.o: Node.h
	g++ -I include -c Node.cpp -o build/Node.o
printLinkedList.o: printLinkedList.h Node.h
	g++ -I include -c printLinkedList.cpp -o build/printLinkedList.o
makeCyclicLinkedList.o: makeCyclicLinkedList.h Node.h random_x_y.h
	g++ -I include -c makeCyclicLinkedList.cpp -o build/makeCyclicLinkedList.o
random_x_y.o: random_x_y.h
	g++ -I include -c random_x_y.cpp -o build/random_x_y.o
printLinkedList.h: Node.h
makeCyclicLinkedList.h: Node.h
Node.h:
random_x_y.h:
clean:
	rm build/*.o bin/loopDetection
