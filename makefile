name=123 $(CXX)
sep=\\
exec:=bin$(sep)unit.exe
sep=/
srcs=$(wildcard src/*.cpp)
all: print build start 
build:
	$(CXX) $(srcs) -o $(exec)
start:$(exec)
	$(exec)
print:
	$(info $(name))
	echo $(exec)
clean:
	del $(exec)