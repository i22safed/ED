/*! 
	\file gnuplot.hpp
	\brief Fichero con la definición de la clase gnuplot
*/


#ifndef GNUPLOT_H
#define GNUPLOT_H

#include <iostream>
#include <string>

using namespace std;

class gnuplot{
    
    public:
        gnuplot();
        ~gnuplot();
        void operator()(const string & command);
    
    protected:
        FILE * gnuplotpipe; 
};

gnuplot::gnuplot(){
    gnuplotpipe = popen("gnuplot -persist","w");
    if(!gnuplotpipe)
        cerr << ("Gnuplot no encontrado");
}

gnuplot::~gnuplot(){
    fprintf(gnuplotpipe,"exit\n");
    pclose(gnuplotpipe);
}

void gnuplot::operator() (const string & command){

    fprintf(gnuplotpipe, "%s\n", command.c_str());
    fflush(gnuplotpipe);

}

#endif