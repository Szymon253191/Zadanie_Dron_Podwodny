CPPFLAGS= -c -g -Wall -pedantic -std=c++17 -iquote inc 
OBJ=./obj
TRGDIR=./

__start__: ${TRGDIR}/dron
		${TRGDIR}/dron
${TRGDIR}/dron: ${OBJ} ${OBJ}/main.o ${OBJ}/Dr3D_gnuplot_api.o ${OBJ}/Prostopadloscian.o ${OBJ}/WektorC.o ${OBJ}/MacierzC.o ${OBJ}/MacierzObr.o ${OBJ}/Dron.o ${OBJ}/Graniastoslup6.o ${OBJ}/Sruba.o ${OBJ}/Powierzchnia.o ${OBJ}/Dno.o
			g++ -o ${TRGDIR}/dron ${OBJ}/main.o ${OBJ}/Dr3D_gnuplot_api.o ${OBJ}/Prostopadloscian.o ${OBJ}/WektorC.o ${OBJ}/MacierzC.o ${OBJ}/MacierzObr.o ${OBJ}/Dron.o ${OBJ}/Graniastoslup6.o ${OBJ}/Sruba.o ${OBJ}/Powierzchnia.o ${OBJ}/Dno.o -lpthread
${OBJ}:
		mkdir ${OBJ}
${OBJ}/main.o: src/main.cpp inc/Obiekt3D.hh inc/Wektor.hh inc/Macierz.hh inc/Dr3D_gnuplot_api.hh inc/Draw3D_api_interface.hh inc/Prostopadloscian.hh inc/Interfejs.hh inc/MacierzObr.hh inc/Graniastoslup6.hh inc/Sruba.hh inc/Plaszczyzna.hh inc/Dno.hh inc/Powierzchnia.hh
		g++ ${CPPFLAGS} -o ${OBJ}/main.o src/main.cpp
${OBJ}/Dr3D_gnuplot_api.o: src/Dr3D_gnuplot_api.cpp inc/Dr3D_gnuplot_api.hh inc/Draw3D_api_interface.hh
		g++ ${CPPFLAGS} -o ${OBJ}/Dr3D_gnuplot_api.o src/Dr3D_gnuplot_api.cpp
${OBJ}/MacierzC.o: inc/Macierz.hh src/Macierz.cpp src/MacierzC.cpp inc/Wektor.hh                 
		g++ ${CPPFLAGS} -o ${OBJ}/MacierzC.o src/MacierzC.cpp
${OBJ}/WektorC.o: inc/Wektor.hh src/Wektor.cpp src/WektorC.cpp                            
		g++ ${CPPFLAGS} -o ${OBJ}/WektorC.o src/WektorC.cpp
${OBJ}/Prostopadloscian.o: inc/Prostopadloscian.hh src/Prostopadloscian.cpp inc/Wektor.hh inc/Macierz.hh inc/Dr3D_gnuplot_api.hh inc/Draw3D_api_interface.hh inc/Obiekt3D.hh inc/MacierzObr.hh
		g++ ${CPPFLAGS} -o ${OBJ}/Prostopadloscian.o src/Prostopadloscian.cpp
${OBJ}/Dron.o: inc/Dron.hh src/Dron.cpp inc/Obiekt3D.hh inc/Wektor.hh inc/Macierz.hh inc/Dr3D_gnuplot_api.hh inc/Draw3D_api_interface.hh inc/Prostopadloscian.hh inc/Interfejs.hh inc/MacierzObr.hh inc/Sruba.hh
		g++ ${CPPFLAGS} -o ${OBJ}/Dron.o src/Dron.cpp
${OBJ}/MacierzObr.o: inc/MacierzObr.hh src/MacierzObr.cpp inc/Macierz.hh inc/Wektor.hh
		g++ ${CPPFLAGS} -o ${OBJ}/MacierzObr.o src/MacierzObr.cpp
${OBJ}/Graniastoslup6.o: src/Graniastoslup6.cpp inc/Graniastoslup6.hh inc/Wektor.hh inc/Macierz.hh inc/Dr3D_gnuplot_api.hh inc/Draw3D_api_interface.hh inc/Obiekt3D.hh inc/MacierzObr.hh
		g++ ${CPPFLAGS} -o ${OBJ}/Graniastoslup6.o src/Graniastoslup6.cpp
${OBJ}/Sruba.o: src/Sruba.cpp inc/Sruba.hh inc/Graniastoslup6.hh inc/Wektor.hh inc/Macierz.hh inc/Dr3D_gnuplot_api.hh inc/Draw3D_api_interface.hh inc/Obiekt3D.hh inc/MacierzObr.hh
		g++ ${CPPFLAGS} -o ${OBJ}/Sruba.o src/Sruba.cpp
${OBJ}/Dno.o: src/Dno.cpp inc/Dno.hh inc/Plaszczyzna.hh inc/Wektor.hh inc/Macierz.hh inc/Dr3D_gnuplot_api.hh inc/Draw3D_api_interface.hh inc/Obiekt3D.hh inc/MacierzObr.hh
		g++ ${CPPFLAGS} -o ${OBJ}/Dno.o src/Dno.cpp
${OBJ}/Powierzchnia.o: src/Powierzchnia.cpp inc/Powierzchnia.hh inc/Plaszczyzna.hh inc/Wektor.hh inc/Macierz.hh inc/Dr3D_gnuplot_api.hh inc/Draw3D_api_interface.hh inc/Obiekt3D.hh inc/MacierzObr.hh
		g++ ${CPPFLAGS} -o ${OBJ}/Powierzchnia.o src/Powierzchnia.cpp
inc/Plaszczyzna.hh: inc/Obiekt3D.hh inc/MacierzObr.hh inc/Wektor.hh inc/Macierz.hh inc/Draw3D_api_interface.hh inc/Dr3D_gnuplot_api.hh
		touch inc/Plaszczyzna.hh
inc/Dr3D_gnuplot_api.hh: inc/Draw3D_api_interface.hh
		touch inc/Dr3D_gnuplot_api.hh
inc/Interfejs.hh: inc/Prostopadloscian.hh inc/Obiekt3D.hh inc/MacierzObr.hh inc/Wektor.hh inc/Macierz.hh inc/Draw3D_api_interface.hh inc/Dr3D_gnuplot_api.hh
		touch inc/Interfejs.hh
inc/Obiekt3D.hh: inc/MacierzObr.hh inc/Macierz.hh inc/Wektor.hh inc/Dr3D_gnuplot_api.hh inc/Draw3D_api_interface.hh
		touch inc/Obiekt3D.hh
clear:
		rm -f ${TRGDIR}/test ${OBJ}/*