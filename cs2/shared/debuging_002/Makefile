###############################################################
# Population Growth
#
# CS 23001 Kent State University
# Make file for Debubbing 2 Lab
#
#
#

###############################################################
# Variables
CPP  = clang++
OPTS = -g -Wall -W -Wunused -Wuninitialized -Wshadow -std=c++11

###############################################################
# The first rule is run if only make is typed
msg:
	@echo 'Targets are:'
	@echo 'pop'

pop: pop_growth.cpp
	$(CPP) $(OPTS) pop_growth.cpp -o pop

###############################################################
clean:
	rm pop

