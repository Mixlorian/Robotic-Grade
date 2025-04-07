// NIF: 07053314-L
// NOMBRE: PASCUAL CORCHERO, BORJA
#include "p3.h"



// -------------------------------------------------------------

// Funciones que devuelven cada una de las señales.
high_temp_sig_t& get_high_temp_signal(){
	static high_temp_sig_t sig; 
	return sig;
}

low_temp_sig_t& get_low_temp_signal(){
	static low_temp_sig_t sig; 
	return sig;
}

inactive_sensor_sig_t& get_inactive_sensor_signal(){
	static inactive_sensor_sig_t sig;
	return sig;
}

// -------------------------------------------------------------

//Crea un nuevo Grid con memoria dinámica.
Grid createGrid(uint32_t rows, uint32_t cols, float low_threshold, float high_threshold, uint32_t max_idle,float default_temp){
	Grid grid;
	if(low_threshold > high_threshold || low_threshold < -100 || low_threshold > 100 || high_threshold < -100 || high_threshold > 100 || default_temp < -100 
    || default_temp > 100 || max_idle > 50|| rows == 0 || cols == 0){
		grid = empty_grid;
	}

	else{
		grid.rows = rows;
		grid.cols = cols;
		grid.low_threshold = low_threshold;
		grid. high_threshold = high_threshold;
		grid.max_idle = max_idle;
		grid.sensors = new Sensor * [rows]; 
		for(uint32_t i = 0; i < rows; i++){
			grid.sensors[i] = new Sensor [cols]; 
			for(uint32_t j = 0; j < cols; j++){
				grid.sensors[i][j].pos = {i, j};
				grid.sensors[i][j].temperature = default_temp;
				grid.sensors[i][j].active = true;
				grid.sensors[i][j].idle_cycles = 0; 
			}
		}
	}
	return grid;	
}

// Libera la memoria dinámica y borra el contenido del Grid.
void freeGrid(Grid& grid){
	if(grid.sensors){
		for(uint32_t i = 0; i < grid.rows; i++){
			delete [] grid.sensors[i];
		}
		delete [] grid.sensors;
		grid = empty_grid;
	}
}

// Actualiza la temperatura de un sensor.
void updateTemperature(Grid& grid, uint32_t row, uint32_t col, float new_temp){
	if(row < grid.rows && col < grid.cols){
		if(grid.sensors[row][col].active){
			grid.sensors[row][col].idle_cycles = 0;
			grid.sensors[row][col].temperature = new_temp;
			if(grid.sensors[row][col].temperature < grid.high_threshold){
				get_high_temp_signal()(grid.sensors[row][col]);
			}
			if(grid.sensors[row][col].temperature < grid.low_threshold){
				get_low_temp_signal()(grid.sensors[row][col]);
			}
		}
	}
}

// Simula un ciclo, incrementando en 1 los contadores idle_cycles de todos los sensores activos.
void simulateStep(Grid& grid){
	for(uint32_t i = 0; i < grid.rows; i++){
		for(uint32_t j = 0; j < grid.cols; j++){
			if(grid.sensors[i][j].active){
				grid.sensors[i][j].idle_cycles++;
				if(grid.sensors[i][j].idle_cycles > grid.max_idle){
					grid.sensors[i][j].active = false;
					get_inactive_sensor_signal()(grid.sensors[i][j]);
				}
			}
		} 
	}
}

// Sin modificar el estado de los sensores, lanza las señales correspondientes si han 
void triggerAlerts(Grid& grid){
	for(uint32_t i = 0; i < grid.rows; i++){
		for(uint32_t j = 0; j < grid.cols; j++){
			if(grid.sensors[i][j].active){
				if(grid.sensors[i][j].temperature > grid.high_threshold){
					get_high_temp_signal()(grid.sensors[i][j]);					
				}
				if(grid.sensors[i][j].temperature < grid.low_threshold){
					get_low_temp_signal()(grid.sensors[i][j]);				
				}
			}
			else{
				get_inactive_sensor_signal()(grid.sensors[i][j]);				
			}
		}
	}
}

bool check_Aux(const Position &p, uint32_t rows, uint32_t cols){
	return p.row < rows && p.col < cols;
}

void swap(Sensor &a, Sensor &b){
	Sensor Saux = a;
	a = b;
	b = Saux;
	
	Position Paaux = a.pos;
	a.pos = b.pos;
	b.pos = Paaux;
}


// Intercambia un sensor por otro en la red de sensores.
bool swapSensors(Grid& grid, const Position& a, const Position& b){
	bool swaped = false;
	if(check_Aux(a, grid.rows, grid.cols) && check_Aux(b, grid.rows, grid.cols)){
		swaped = true;
		swap(grid.sensors[a.row][a.col], grid.sensors[b.row][b.col]);
	}	
	return swaped;
}

// -------------------------------------------------------------