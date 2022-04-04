NAME:=venagin_script
COMPILER:=g++
LINKER:=g++
SRC:=src
OBJ:=bin
SEP:=/
EXEC:=bin/unit.exe
SRCS:=$(wildcard $(SRC)/*.cpp)
OBJS:=$(patsubst $(SRC)/%.cpp,$(OBJ)/%.obj,$(SRCS))
CFLAGS:=-std=c++17
all: build start 
build:$(OBJS)
	$(LINKER) $(OBJS) -o $(EXEC) -lopengl32 -lgdi32
start:build
	$(EXEC)
print:
	$(info $(SRCS))
	$(info $(OBJS))
	dir
$(OBJ)/%.obj: $(SRC)/%.cpp
	$(COMPILER) -c $< -o $@ $(CFLAGS) 
# g++ -c <путь до main.cpp>(в нашем примере) "Вместо $< подставляется $(SRC)/%.cpp (т.е. то что справа)"
# -O <путь до соответсвующего объектного файла.obj> "Вместо $@ подставяется $(OBJ)/%.obj (т.е. то что слева)"
