#include <stdio.h>
#include "funciones.h"

int main() {
    Libro biblioteca[MAX_LIBROS];
    int contador = 0; // Contador de libros registrados
    int opcion;

    do {
        printf("\n--- Biblioteca ---\n");
        printf("1. Registrar libro\n");
        printf("2. Mostrar lista de libros\n");
        printf("3. Buscar libro\n");
        printf("4. Actualizar estado de un libro\n");
        printf("5. Eliminar libro\n");
        printf("6. Salir\n");
        printf("Seleccione una opcion: ");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1:
                registrarLibro(biblioteca, &contador);
                break;
            case 2:
                mostrarLibros(biblioteca, contador);
                break;
            case 3:
                buscarLibro(biblioteca, contador);
                break;
            case 4:
                actualizarEstado(biblioteca, contador);
                break;
            case 5:
                eliminarLibro(biblioteca, &contador);
                break;
            case 6:
                printf("Saliendo del programa...\n");
                break;
            default:
                printf("Opción invalida. Intente nuevamente.\n");
        }
    } while (opcion != 6);

    return 0;
}
