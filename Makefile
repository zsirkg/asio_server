CXX=g++
CXXFLAGS=-Wall -I.
LDFLAGS=
LIBS=-lboost_system

all: server

server: main.cc server.cc connection.cc
	$(CXX) -o $@ $^ $(CXXFLAGS) $(LDFLAGS) $(LIBS)

clean:
	rm *.o server -rf
