GPP = g++
OPT =  -std=c++11 -fopenmp

SOURCES = main.cpp ./utils/graph.cpp ./utils/validate.cpp ./utils/readfile.cpp
OBJ = bfs_serial bfs_omp bfs_test

all: $(OBJ)

bfs_serial: bfs_serial.cpp $(SOURCES)
	$(GPP) $(OPT) -o bfs_serial bfs_serial.cpp $(SOURCES)

bfs_omp: bfs_omp.cpp $(SOURCES)
	$(GPP) $(OPT) -o bfs_omp bfs_omp.cpp $(SOURCES)

bfs_test: bfs_test.cpp $(SOURCES)
	$(GPP) $(OPT) -o bfs_test bfs_test.cpp $(SOURCES)

clean:
	-rm -f $(OBJ)