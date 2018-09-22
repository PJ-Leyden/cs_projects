#============================================================================
# Make file for Profiler
#
# CS II Kent State University
#
# J. Maletic 
# Copyright 2015 Kent State University. All rights reserved.2015


###############################################################
# Variables
CPP      = clang++
CPP_OPTS = -g -Wall -W -Wunused -Wuninitialized -Wshadow -std=c++11

###############################################################
# The first rule is run if only make is typed
msg:
	@echo 'Targets are:'
	@echo '  profiler:'
	@echo '  sort:'
	@echo '  p-sort:'
	@echo '  clean:'

###############################################################
profiler : main.o ASTree.o 
	$(CPP) $(CPP_OPTS) -o profiler main.o ASTree.o 
  
main.o : main.cpp ASTree.hpp
	$(CPP) $(CPP_OPTS) -c main.cpp

ASTree.o   : ASTree.hpp ASTree.cpp
	$(CPP) $(CPP_OPTS) -c ASTree.cpp

#==============================================================
# sort
sort : sort.o sort_lib.o
	$(CPP) $(CPP_OPTS) -o sort sort.o sort_lib.o

sort.o: sort_lib.h sort.cpp
	$(CPP) $(CPP_OPTS) -c sort.cpp

sort_lib.o: sort_lib.h sort_lib.cpp
	$(CPP) $(CPP_OPTS) -c sort_lib.cpp

#==============================================================
# p-sort
# p-sort.cpp
# p-sort_lib.cpp

p-sort : profile.o p-sort.o p-sort_lib.o
	$(CPP) $(CPP_OPTS) -o p-sort profile.o p-sort.o p-sort_lib.o

p-sort.o: profile.hpp sort_lib.h p-sort.cpp
	$(CPP) $(CPP_OPTS) -c p-sort.cpp

p-sort_lib.o: profile.hpp sort_lib.h p-sort_lib.cpp
	$(CPP) $(CPP_OPTS) -c p-sort_lib.cpp

profile.o: profile.hpp profile.cpp
	$(CPP) $(CPP_OPTS) -c profile.cpp


###############################################################
#This will clean up everything via "make clean"
clean:
	rm -f profiler
	rm -f sort
	rm -f *.o
	rm -f p-*

