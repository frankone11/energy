#include <iostream>
#include <sstream>
#include <fstream>
#include <ctime>
#include <string>
#define File_Name "001.csv"
using namespace std;


int main()
{
		
    ifstream file(File_Name);
    string line;
    char limit = ',';
    // Leemos la primer línea para descartarla, pues es el encabezado
    getline(file, line);
    // Leemos todas las líneas
    while (getline(file, line))
    {

        stringstream stream(line); // Convertir la cadena a un stream
        string battery_serial,timestamp,signal_name,signal_value;
        // Extraer todos los valores de esa fila
        getline(stream, battery_serial, limit);
        getline(stream, timestamp, limit);        
        getline(stream, signal_name, limit);
        getline(stream, signal_value, limit);
        
        std::string str = timestamp;
		int timeS = atol(str.c_str()) / 1000;
    	time_t unix_time = (time_t)timeS;
        tm* time_info = std::localtime(&unix_time);
        char buffer[80];
    	strftime(buffer, sizeof(buffer), "%Y-%m-%d %H:%M:%S", time_info);
      
        // Print
        cout << "==================" << endl;
        cout << "Date and time: " << buffer << endl;
        cout << "Battery Serial: " << battery_serial << endl;
        cout << "Signal Name: " << signal_name << endl;
        cout << "Signal Value: " << signal_value << endl;
    }

    file.close();
}
