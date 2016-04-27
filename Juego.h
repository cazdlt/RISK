#ifndef __JUEGO__H__
#define __JUEGO__H__

#include "Jugador.h"
#include "Tablero.h"

#include <time.h>
#include <stdlib.h>
#include <vector>
#include <stack>
#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <algorithm>

class Juego{
	protected:
		std::vector<Jugador> jugadores;
		Tablero *tablero;
		int estado; //0. jugando -- 1. no iniciado -- 2. finalizado

	public:
	    static unsigned int turno;
		
		//CONSTRUCTORES
	    Juego();
	    ~Juego();
		
		//ACCESO
		int getEstado();
        std::vector<Jugador> getJugadores();
		Tablero* getTablero();
		
		//FUNCIONES		
        bool inicializar();
		bool inicializar(std::string);
        int jugarTurno(int player); //0. turno completado -- 1.no es el turno -- 2. no existe player        
        Jugador* searchJugador(int id);
        Jugador* searchJugador(std::string nombre);
        void printJugadores();
        void help();
        void help(std::string input);        
        void ver(std::string input);
		void print();
		bool save(std::string input);
};

//UTILS
std::vector<std::string> splitstring(const std::string &s, char token);
std::string pickColor(std::vector<std::string>& disp);
std::stack<Tarjeta> fillTarjetas(Tablero* t0);
int updateTurno(Juego* j0);
bool guardarPartida(std::ofstream& file,std::vector<Jugador> jugadores);
bool comprimir(std::string input);

#include "Juego.hxx"
#endif
