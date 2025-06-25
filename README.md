                                                               Proyecto: Simulación de Estrellas en SFML
Este proyecto es una simulación visual de estrellas en movimiento, desarrollada en C++ usando la biblioteca gráfica SFML. El objetivo es mostrar un campo de estrellas en 3D que se mueven hacia el espectador, generando un efecto de profundidad y velocidad.


                                                                  ¿Qué hace este programa?
Genera miles de estrellas con posiciones y profundidades aleatorias.
Simula el movimiento de las estrellas acercándose al espectador, como si viajaras a través del espacio.
Ajusta el brillo y tamaño de cada estrella según su profundidad, para dar un efecto realista.
Permite cerrar la ventana fácilmente con la tecla Escape o el botón de cerrar.

                                                                     ¿Cómo funciona internamente?
                                                                           Configuración
Todos los parámetros importantes (tamaño de ventana, cantidad de estrellas, velocidad, etc.) están en src/configuration.hpp.
Generación de estrellas
En el arranque, el programa crea un vector de estrellas (Star), cada una con una posición y una profundidad (z) aleatoria.
Renderizado
Cada estrella se dibuja como un pequeño círculo.
El tamaño y el color de cada estrella dependen de su profundidad: las más cercanas se ven más grandes y brillantes.
Se usa un sf::VertexArray para renderizar eficientemente todas las estrellas.
Movimiento
En cada frame, la profundidad (z) de cada estrella disminuye, simulando que se acercan al espectador.
Si una estrella pasa el plano más cercano, se reinicia al fondo para mantener el flujo constante.
Eventos
El programa escucha eventos de la ventana:
Si presionas Escape o cierras la ventana, el programa termina.

                                                                        ¿Cómo compilar y ejecutar?
                                                                        Requisitos
CMake
Un compilador C++ compatible (GCC, Clang, MSVC, MinGW, etc.)
SFML 3.x (ya viene como submódulo/dependencia en este proyecto)

                                                                        Compilación
   mkdir build
   cd build
   cmake ..
   cmake --build .
Apply to events.cpp

                                                                        Ejecución
Ejecuta el binario generado (por ejemplo, ./MyProject o desde tu IDE).
Disfruta del viaje estelar.
Estructura del código
src/main.cpp — Lógica principal, renderizado y bucle de simulación.
src/star.hpp — Definición de la estructura de una estrella.
src/configuration.hpp — Parámetros de configuración globales.
src/events.hpp y src/events.cpp — Manejo de eventos de la ventana.

                                                                     Personalización
Puedes modificar fácilmente:
El número de estrellas (conf::count)
El tamaño de la ventana (conf::window_size)
La velocidad de las estrellas (conf::speed)
El radio de las estrellas (conf::radius)
Todo esto está en src/configuration.hpp.

