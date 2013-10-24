#CXXFLAGS = -g -W -Wall -ansi -pedantic
#CXXFLAGS = -pg -g -W -Wall -ansi -pedantic
#CXXFLAGS = -O2 -W -Wall -ansi -pedantic -I. -I../d_cpp
CXXFLAGS = -O2 -W -Wall -ansi -pedantic
CFLAGS = -O2
LDFLAGS=
INCLUDES= -I. -I../d_cpp
OBJS = bulletmlparser-tinyxml.o bulletmlparser.o bulletmltree.o calc.o \
	formula-variables.o bulletmlrunner.o bulletmlrunnerimpl.o bulletml_d.o

MAJOR=0d2
MINOR=0

all: libbulletml.a libbulletml.so

libbulletml.so: tinyxml/tinyxml.o ../bulletml.d $(OBJS)
	$(CXX) $(LDFLAGS) -shared \
		-Wl,-soname,$@.$(MAJOR) \
		-o $@.$(MAJOR).$(MINOR) \
		*.o tinyxml/tiny*.o
	rm -f $@.$(MAJOR)
	ln -s $@.$(MAJOR).$(MINOR) $@.$(MAJOR)
	rm -f $@
	ln -s $@.$(MAJOR) $@

libbulletml.a: tinyxml/tinyxml.o ../bulletml.d $(OBJS)
	ar cru $@ *.o tinyxml/tiny*.o

../bulletml.d: bulletml_d.cpp
	perl ../d_cpp/create_d_import.pl bulletml_d.cpp bulletml.d

tinyxml/tinyxml.o:
	$(MAKE) -C tinyxml

clean:
	rm -f *.o *.a test_bulletml *.so *.so.*
	$(MAKE) -C tinyxml clean

calc.cpp: calc.yy
	bison -y   calc.yy && mv y.tab.c calc.cpp

$(OBJS): %.o: %.cpp
	$(CXX) -c $(CXXFLAGS) $(INCLUDES) $<

doxy:
	doxygen

distdir:

