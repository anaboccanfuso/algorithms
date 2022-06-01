# Copyright 2022 Ana Boccanfuso
cpp = g++

flags = -std=c++17
flags += -Wall
flags += -g

link = $(cpp) $(flags) -o
compile = $(cpp) $(flags) -c

# floyd
floyd: floyd.cpp
		$(link) $@ $^


# clean up
clean:
		$(RM) floyd output.txt
