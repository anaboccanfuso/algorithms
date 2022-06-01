# Copyright 2022 Ana Boccanfuso
cpp = g++

flags = -std=c++17
flags += -Wall
flags += -g
#flags += -I... # add pwd directory to src include sun_path
#flags += -pthread # support for POSIX threads

link = $(cpp) $(flags) -o
compile = $(cpp) $(flags) -c

# quicksort
quicksort: quicksort.cpp
		$(link) $@ $^

# clean up
clean:
		$(RM) quicksort
		$(RM) output.txt
