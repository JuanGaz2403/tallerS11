#ifndef FUNCIONES_H
#define FUNCIONES_H

#define MAX_LIBROS 10

// Estructura para representar un libro
typedef struct {
    int id;
    char titulo[100];
    char autor[50];
    int anio_publicacion;
    char estado[15]; // "Disponible" o "Prestado"
} Libro;

// Prototipos de funciones
int registrarLibro(Libro biblioteca[], int *contador);
void mostrarLibros(Libro biblioteca[], int contador);
void buscarLibro(Libro biblioteca[], int contador);
void actualizarEstado(Libro biblioteca[], int contador);
void eliminarLibro(Libro biblioteca[], int *contador);

#endif // FUNCIONES_H
