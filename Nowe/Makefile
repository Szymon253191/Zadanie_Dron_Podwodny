CPPFLAGS= -c -g -Iinc -Wall -pedantic -std=c++17

__start__: dron
	./dron

dron: obj/main.o obj/Wektor.o obj/Macierz.o obj/Dr3D_gnuplot_api.o\
	 g++ -Wall -pedantic -o dron obj/main.o obj/Wektor.o obj/Macierz.o\
	  obj/Dr3D_gnuplot_api.o\
	  -lpthread

obj/main.o: src/main.cpp inc/Macierz.hh\
	 inc/Dr3D_gnuplot_api.hh 
	g++ ${CPPFLAGS} -o obj/main.o src/main.cpp

obj/Wektor.o: src/WektorC.cpp inc/Wektor.hh
	g++ ${CPPFLAGS} -o obj/Wektor.o src/WektorC.cpp

obj/Macierz.o: src/MacierzC.cpp inc/Macierz.hh
	g++ ${CPPFLAGS} -o obj/Macierz.o src/MacierzC.cpp

obj/Dr3D_gnuplot_api.o: src/Dr3D_gnuplot_api.cpp inc/Dr3D_gnuplot_api.hh
	g++ ${CPPFLAGS} -o obj/Dr3D_gnuplot_api.o src/Dr3D_gnuplot_api.cpp

inc/Dr3D_gnuplot_api.hh: inc/Draw3D_api_interface.hh
	touch inc/Dr3D_gnuplot_api.hh

clear:
	rm -f obj/*.o dron
