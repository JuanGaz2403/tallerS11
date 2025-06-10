#include <stdio.h>
#include <string.h>

#define MAX_LIBROS 10

// Estructura para representar un libro
typedef struct {
    int id;
    char titulo[100];
    char autor[50];
    int anio_publicacion;
    char estado[15]; // "Disponible" o "Prestado"
} Libro;

// Función para registrar un libro
int registrarLibro(Libro biblioteca[], int *contador) {
    if (*contador >= MAX_LIBROS) {
        printf("No se pueden agregar mas libros. Limite alcanzado.\n");
        return 0;
    }

    Libro nuevoLibro;
    printf("Ingrese el ID del libro: ");
    scanf("%d", &nuevoLibro.id);

    // Validar que el ID sea único
    for (int i = 0; i < *contador; i++) {
        if (biblioteca[i].id == nuevoLibro.id) {
            printf("El ID ya existe. Intente nuevamente.\n");
            return 0;
        }
    }

    printf("Ingrese el titulo del libro: ");
    getchar(); // Limpiar el buffer
    fgets(nuevoLibro.titulo, sizeof(nuevoLibro.titulo), stdin);
    nuevoLibro.titulo[strcspn(nuevoLibro.titulo, "\n")] = '\0'; // Eliminar salto de línea

    printf("Ingrese el autor del libro: ");
    fgets(nuevoLibro.autor, sizeof(nuevoLibro.autor), stdin);
    nuevoLibro.autor[strcspn(nuevoLibro.autor, "\n")] = '\0';

    printf("Ingrese el año de publicacion: ");
    scanf("%d", &nuevoLibro.anio_publicacion);

    strcpy(nuevoLibro.estado, "Disponible");

    biblioteca[*contador] = nuevoLibro;
    (*contador)++;
    printf("Libro registrado exitosamente.\n");
    return 1;
}

// Función para mostrar la lista completa de libros
void mostrarLibros(Libro biblioteca[], int contador) {
    printf("ID\tTitulo\t\t\tAutor\t\t\tAño\tEstado\n");
    printf("---------------------------------------------------------------\n");
    for (int i = 0; i < contador; i++) {
        printf("%d\t%-20s\t%-10s\t%d\t%s\n",
               biblioteca[i].id,
               biblioteca[i].titulo,
               biblioteca[i].autor,
               biblioteca[i].anio_publicacion,
               biblioteca[i].estado);
    }
}

// Función para buscar un libro por título o ID
void buscarLibro(Libro biblioteca[], int contador) {
    int opcion;
    printf("Buscar por: 1. ID, 2. Titulo: ");
    scanf("%d", &opcion);

    if (opcion == 1) {
        int id;
        printf("Ingrese el ID del libro: ");
        scanf("%d", &id);

        for (int i = 0; i < contador; i++) {
            if (biblioteca[i].id == id) {
                printf("ID: %d\nTitulo: %s\nAutor: %s\nAño: %d\nEstado: %s\n",
                       biblioteca[i].id,
                       biblioteca[i].titulo,
                       biblioteca[i].autor,
                       biblioteca[i].anio_publicacion,
                       biblioteca[i].estado);
                return;
            }
        }
        printf("Libro no encontrado.\n");
    } else if (opcion == 2) {
        char titulo[100];
        printf("Ingrese el titulo del libro: ");
        getchar(); // Limpiar el buffer
        fgets(titulo, sizeof(titulo), stdin);
        titulo[strcspn(titulo, "\n")] = '\0';

        for (int i = 0; i < contador; i++) {
            if (strcmp(biblioteca[i].titulo, titulo) == 0) {
                printf("ID: %d\nTitulo: %s\nAutor: %s\nAño: %d\nEstado: %s\n",
                       biblioteca[i].id,
                       biblioteca[i].titulo,
                       biblioteca[i].autor,
                       biblioteca[i].anio_publicacion,
                       biblioteca[i].estado);
                return;
            }
        }
        printf("Libro no encontrado.\n");
    } else {
        printf("Opcion inválida.\n");
    }
}

// Función para actualizar el estado de un libro
void actualizarEstado(Libro biblioteca[], int contador) {
    int id;
    printf("Ingrese el ID del libro: ");
    scanf("%d", &id);

    for (int i = 0; i < contador; i++) {
        if (biblioteca[i].id == id) {
            printf("Estado actual: %s\n", biblioteca[i].estado);
            if (strcmp(biblioteca[i].estado, "Disponible") == 0) {
                strcpy(biblioteca[i].estado, "Prestado");
            } else {
                strcpy(biblioteca[i].estado, "Disponible");
            }
            printf("Estado actualizado a: %s\n", biblioteca[i].estado);
            return;
        }
    }
    printf("Libro no encontrado.\n");
}

// Función para eliminar un libro
void eliminarLibro(Libro biblioteca[], int *contador) {
    int id;
    printf("Ingrese el ID del libro a eliminar: ");
    scanf("%d", &id);

    for (int i = 0; i < *contador; i++) {
        if (biblioteca[i].id == id) {
            for (int j = i; j < *contador - 1; j++) {
                biblioteca[j] = biblioteca[j + 1];
            }
            (*contador)--;
            printf("Libro eliminado exitosamente.\n");
            return;
        }
    }
    printf("Libro no encontrado.\n");
}
