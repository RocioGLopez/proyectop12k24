#ifndef ESTUDIANTE_H
#define ESTUDIANTE_H

#include <iostream>
#include <vector>
#include <string>

struct Estudiante {
std::string nombre;
int edad;
double promedio;
};

class GestorEstudiantes {
private:
std::vector<Estudiante> estudiantes;

public:
void menu();
void mostrarEstudiantes();
void ingresarEstudiante();
void modificarEstudiante();
void eliminarEstudiante();
};

#endif // ESTUDIANTES_H

