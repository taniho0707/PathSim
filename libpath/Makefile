
all:
	g++ -fPIC -I../lib/ -I../ -c libpathbasic1.cpp -o libpathbasic1.lo
	g++ -shared -Wl,-soname,libpathbasic1.so libpathbasic1.lo -o libpathbasic1.so
	g++ -fPIC -I../lib/ -I../ -c libpathbasic2.cpp -o libpathbasic2.lo
	g++ -shared -Wl,-soname,libpathbasic2.so libpathbasic2.lo -o libpathbasic2.so
	rm *.lo

