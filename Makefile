bin/testTableEntry: testTableEntry.cpp TableEntry.h
	mkdir -p bin
	g++ -std=c++11 -o bin/testTableEntry testTableEntry.cpp

bin/testHashTable: testHashTable.cpp Dict.h TableEntry.h
	mkdir -p bin
	g++ -std=c++11 -o bin/testHashTable testHashTable.cpp

clean:
	rm -rf *.o *.gch bin