all: libothm_object.so

libothm_object.so: othm_object.o
	gcc -shared -o libothm_object.so othm_object.o
othm_object.o: othm_object.c othm_object.h
	gcc -c -Wall -Werror -fPIC othm_object.c -o othm_object.o

.PHONY : clean install uninstall test
clean :
	-rm  othm_object.o libothm_object.so test
install :
	cp othm_object.h /usr/include/
	cp libothm_object.so /usr/lib/
	ldconfig
uninstall :
	-rm  /usr/include/othm_object.h
	-rm  /usr/lib/libothm_object.so
	ldconfig
test :
	gcc -o test test.c -lothm_object -lothm_thread -lothm_symbols \
	-lothm_hashmap -lothm_base -lpthread
	./test
