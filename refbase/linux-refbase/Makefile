#for built in function
comma:= ,
empty:= 
space:= $(empty)$(empty)
foo = 'a b c'
bar:= $(subst $(space),$(comma),$(foo))

$(info ***************** )
$(warning kjkjkjkjk)
$(info $(shell pwd))

#first name a variable objects for all object files
objects = dd.o RefBase.o

#name a variable sources for all source files
sources = dd.cpp RefBase.cpp
#give target as refbase with objects as variable dependencies + command line
refbase: $(objects)
	g++ -o refbase $(objects)
	@echo $(bar)

#list the dependencies for object files ---those header files which help build objects
RefBase.o: RefBase.h
dd.o: RefBase.h

#how to build all object files from all dependent source files 

$(objects): $(sources)
	g++ -c -g $(sources)

clean:
	rm $(objects) refbase 
