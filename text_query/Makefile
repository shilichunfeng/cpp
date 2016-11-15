INC_DIR:= ./include
SRCS:=$(wildcard ./src/*.cc)
LIBS:= 

CXX:=g++

CXXFLAGS:= -w -std=c++11 $(addprefix -I, $(INC_DIR)) $(LIBS)

EXE:=./bin/main.exe

$(EXE):$(SRCS)
	$(CXX) $^ -o $@ $(CXXFLAGS)

clean:
	rm -rf $(EXE)
