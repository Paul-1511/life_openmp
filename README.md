# life_openmp
Proyecto game of life


# Documentación

# Juego de la Vida

Este repositorio contiene una implementación del "Juego de la Vida" de John Conway utilizando la biblioteca gráfica Raylib para la visualización. El proyecto está diseñado para aprovechar la paralelización a través de OpenMP y proporciona una interfaz gráfica basada en `raygui`.

## Estructura del Proyecto

- **game.c**: Archivo principal del proyecto que inicializa la ventana, configura la interfaz gráfica y controla el bucle principal del juego.
- **hashlife.c**: Contiene la implementación de las funciones relacionadas con el cálculo del estado de las celdas, utilizando técnicas de paralelización.
- **interface.h**: Define y gestiona la interfaz gráfica de usuario, incluyendo botones, cuadros de valores y barras de progreso.
- **life.h**: Describe las estructuras y algoritmos relacionados con la simulación del Juego de la Vida, incluyendo la configuración de reglas y la evolución de la simulación.
- **parse.c**: Se encarga de la lectura y el análisis de patrones desde archivos, permitiendo cargar configuraciones iniciales para la simulación.
- **parse.h**: Declaración de funciones para la manipulación de patrones (lectura, escritura, renombrado, eliminación).

## Dependencias

- **Raylib**: Una biblioteca gráfica en C para el desarrollo de juegos.
- **raygui**: Biblioteca para crear interfaces gráficas simples en aplicaciones desarrolladas con Raylib.
- **OpenMP**: Biblioteca para paralelización de tareas en sistemas multi-core.

## Compilación e Instalación

### Requisitos

- `gcc` o cualquier compilador de C compatible.
- Raylib y raygui deben estar instalados en el sistema.
- OpenMP debe estar habilitado en el compilador.

### Instrucciones de Compilación

1. Clona el repositorio:

   ```bash
   git clone https://github.com/Paul-1511/life_openmp.git
   cd juego-de-la-vida
   ```

2. Compila el proyecto:

   ```bash
   gcc -o juego game.c hashlife.c parse.c -lraylib -lGL -lm -lpthread -ldl -lrt -lX11 -fopenmp
   ```

3. Ejecuta el programa:

   ```bash
   ./juego
   ```

## Uso

Al iniciar el programa, se abrirá una ventana que muestra el estado actual de la simulación del Juego de la Vida. La interfaz gráfica permite controlar la velocidad de la simulación, avanzar o retroceder entre generaciones, y reproducir/pausar la simulación.

### Controles Principales

- **Spinner (Speed)**: Ajusta la velocidad de la simulación.
- **Button (Next/Prev)**: Avanza o retrocede una generación.
- **Button (Play)**: Inicia o pausa la simulación.
- **ValueBox (X/Y/Zcord, Cells, Grids)**: Permite editar las coordenadas y los valores específicos dentro de la simulación.

## Funcionalidades Adicionales

### Carga y Almacenamiento de Patrones

Puedes cargar patrones personalizados desde archivos de texto para inicializar el estado del juego. La función `getpattern` en `parse.c` se encarga de leer estos archivos y traducirlos en configuraciones del tablero.

## Contribución

Si deseas contribuir al proyecto:

1. Haz un fork del repositorio.
2. Crea una rama con tu característica (`git checkout -b caracteristica-nueva`).
3. Haz commit de tus cambios (`git commit -m 'Agrega nueva característica'`).
4. Haz push a la rama (`git push origin caracteristica-nueva`).
5. Abre un Pull Request.

## Autor

Desarrollado por Diego Reyes usando Raylib, raygui y OpenMP.

---
