include ../../build_config.mk

all: lib
	${CXX} -o demo demo.cpp libssdb-client.a
	${CXX} -o hello-ssdb hello-ssdb.cpp libssdb-client.a
	${CXX} -g -o ssdb_example ssdb_example.cpp libssdb-client.a -lpthread

lib: SSDB_client.h SSDB_impl.h SSDB_impl.cpp
	${CXX} -I../ ${CFLAGS} -c SSDB_impl.cpp
	ar -cru libssdb-client.a\
		SSDB_impl.o\
		../util/bytes.o\
		../net/link.o
	cp SSDB_client.h libssdb-client.a ../../api/cpp

clean:
	rm -f demo hello-ssdb ssdb_example *.a *.o

