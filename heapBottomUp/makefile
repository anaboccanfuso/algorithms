# Copyright 2022 Ana Boccanfuso
cpp = g++

flags = -std=c++17
flags += -Wall
flags += -g
#flags += -I... # add pwd directory to src include sun_path
#flags += -pthread # support for POSIX threads

link = $(cpp) $(flags) -o
compile = $(cpp) $(flags) -c

# heap
heap: heap.cpp
		$(link) $@ $^

heapEC: heapEC.cpp
		$(link) $@ $^
# clean up
clean:
		$(RM) heap output.txt heapEC
