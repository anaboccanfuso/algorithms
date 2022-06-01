# Copyright 2022 Ana Boccanfuso
cpp = g++

flags = -std=c++17
flags += -Wall
flags += -g

link = $(cpp) $(flags) -o
compile = $(cpp) $(flags) -c

# horspool
horspool: horspool.cpp
		$(link) $@ $^


# clean up
clean:
		$(RM) horspool output.txt
