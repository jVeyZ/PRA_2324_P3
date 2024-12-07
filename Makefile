bin/testTableEntry: testTableEntry.cpp TableEntry.h
	mkdir -p bin
	g++ -std=c++11 -o bin/testTableEntry testTableEntry.cpp

bin/testHashTable: testHashTable.cpp Dict.h TableEntry.h
	mkdir -p bin
	g++ -std=c++11 -o bin/testHashTable testHashTable.cpp

bin/testBSTree: testBSTree.cpp BSTree.h BSNode.h 
	mkdir -p bin
	g++ -std=c++11 -o bin/testBSTree testBSTree.cpp

bin/testBSTreeDict: Dict.h BSTreeDict.h BSNode.h TableEntry.h testBSTreeDict.cpp
	mkdir -p bin
	g++ -std=c++11 -o bin/testBSTreeDict testBSTreeDict.cpp

clean:
	rm -rf *.o *.gch bin