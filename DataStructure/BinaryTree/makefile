cc=g++
exe=contact
obj=Contact.o Tree.o Node.o
$(exe):$(obj)
	$(cc) -o $(exe) $(obj)
Contact.o:Contact.cpp Tree.h Node.h
	$(cc) -c Contact.cpp
Tree.o:Tree.cpp Tree.h Node.h
	$(cc) -c Tree.cpp
Node.o:Node.cpp Node.h
	$(cc) -c Node.cpp

.PHONY:clean 
clean:
	rm -rf *.o