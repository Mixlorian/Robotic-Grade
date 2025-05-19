// b12_00: test constructor 

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

int main() {
    get_high_temp_signal().connect(alert_high_temp);
    get_low_temp_signal().connect(alert_low_temp);
    get_inactive_sensor_signal().connect(alert_inactive);

    std::cout << std::fixed << std::setprecision(1); // Formateo global para poner 1 decimal en los decimales.

// rows, cols, low_threshold, high_threshold, max_idle, default_temp

    Grid grid_empty0 = createGrid(3, 2, 30.0f, 100.1f, 2, 22.0f); // h > 100
    Grid grid_empty1 = createGrid(3, 2, 30.0f, 35.0f, 2, 100.1f); // t > 100

    Grid grid0 = createGrid(0, 3, 30.0f, 35.0f, 2, 22.0f);
    
    
    Grid grid1 = createGrid(3, 3, 30.0f, 30.0f, 2, 22.0f); // l >= h
    Grid grid2 = createGrid(3, 3, 30.01f, 30.0f, 2, 22.0f); // l >= h
    Grid grid3 = createGrid(3, 3, -100.1f, 100.0f, 2, 22.0f); // l < -100
    Grid grid4 = createGrid(3, 3, 100.0f, 100.0f, 51, 22.0f); // c > 50
    Grid ok_limits1 = createGrid(3, 5, -100.0f, 100.0f, 50, 100); // ok limits

    Grid ok_limits2 = createGrid(1, 2, -99.0f, 99.0f, 0, 100); // ok limits


    cout << "grid_empty0" << endl;
    displayGrid(grid_empty0);
    cout << "grid_empty1" << endl;
    displayGrid(grid_empty1);
    cout << "grid0" << endl;
    displayGrid(grid0);
    cout << "grid1" << endl;
    displayGrid(grid1);
    cout << "grid2" << endl;
    displayGrid(grid2);
    cout << "grid3" << endl;
    displayGrid(grid3);
    cout << "grid4" << endl;
    displayGrid(grid4);

    cout << "ok_limits1" << endl;
    displayGrid(ok_limits1);

    cout << "ok_limits2" << endl;
    displayGrid(ok_limits2);

    freeGrid(grid_empty0);
    freeGrid(grid_empty1);
    
    freeGrid(grid0);
    freeGrid(grid1);
    freeGrid(grid2);
    freeGrid(grid3);
    freeGrid(grid4);
    freeGrid(ok_limits1);
    freeGrid(ok_limits2);

    return 0;
}

