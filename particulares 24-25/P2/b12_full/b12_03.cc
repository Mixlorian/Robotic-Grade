// b12_01: simulate_step update_temperature (restart idle_cycles)

#include "p3.h"
#include <iostream>
#include <iomanip> // para std::fixed y std::setprecision

void alert_high_temp(const Sensor& s) {
    std::cout << "[HIGH TEMP] Sensor at (" << s.pos.row << "," << s.pos.col 
              << ") reads " << s.temperature << "°C\n";
}

void alert_low_temp(const Sensor& s) {
    std::cout << "[LOW TEMP] Sensor at (" << s.pos.row << "," << s.pos.col 
              << ") reads " << s.temperature << "°C\n";
}

void alert_inactive(const Sensor& s) {
    std::cout << "[INACTIVE] Sensor at (" << s.pos.row << "," << s.pos.col 
              << ") is inactive after " << s.idle_cycles << " cycles\n";
}

void show_all_cycles(const Grid &grid){
	for(uint32_t i = 0; i < grid.rows; i++){
		for(uint32_t j = 0; j < grid.cols; j++){
			cout << " " << grid.sensors[i][j].idle_cycles;
		}
		cout << endl;
	}
}

int main() {
	get_high_temp_signal().connect(alert_high_temp);
	get_low_temp_signal().connect(alert_low_temp);
	get_inactive_sensor_signal().connect(alert_inactive);

	// Formateo global para poner 1 decimal en los decimales.
	std::cout << std::fixed << std::setprecision(1); 

	// rows, cols, low_threshold, high_threshold, max_idle, default_temp
	Grid grid = createGrid(2, 3, 30.0f, 50.00f, 2, 22.0f); 
	cout << "Initial state" << endl;
	displayGrid(grid);


	cout << "\nSimulate one step (2 cycles max), all active" << endl;
	simulateStep(grid);
	show_all_cycles(grid);
	
	cout << "\nSimulate one step (2 cycles max), all active" << endl;
	simulateStep(grid);
	show_all_cycles(grid);

	cout << "\nNew temperature in range, restarting idle_cycles" << endl;
	updateTemperature(grid, 0, 0, 7.0f);
	updateTemperature(grid, 1, 2, 8.0f);
	displayGrid(grid);
	show_all_cycles(grid);


	cout << "\nSimulate one step (2 cycles max),  2 actives" << endl;
	simulateStep(grid);
	displayGrid(grid);
	show_all_cycles(grid);
	
	cout << "\nSimulate one step (2 cycles max), 2 active (nothing to done)" << endl;
	simulateStep(grid);
	displayGrid(grid);
	show_all_cycles(grid);


	cout << "\nSimulate one step (2 cycles max), all inactive" << endl;
	simulateStep(grid);
	displayGrid(grid);
	show_all_cycles(grid);

	cout << "\nUpdating temperature inactive sensors (nothing to done)" << endl;
	updateTemperature(grid, 0, 0, 12);
	
	cout << "Freeing the allocated memory.." << endl;
	freeGrid(grid);
	return 0;
}


