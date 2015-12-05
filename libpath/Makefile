
all:
	g++ -fPIC -I../lib/ -I../ -c libpathbasic1.cpp -o libpathbasic1.lo
	g++ -shared -Wl,-soname,libpathbasic1.so libpathbasic1.lo -o libpathbasic1.so
	rm *.lo

