✨ Simulación de Estrellas en SFML ✨
¡Bienvenido a tu propio viaje por el espacio! 🚀
Este proyecto es una simulación visual de un campo de estrellas en movimiento, hecha en C++ usando la biblioteca gráfica SFML.
🌌 ¿Qué hace este programa?
Genera miles de estrellas que se mueven hacia ti, creando un efecto de profundidad y velocidad.
Cada estrella cambia de tamaño y brillo según su distancia, ¡como si volaras a través del espacio!
Puedes cerrar la ventana fácilmente con la tecla Escape o el botón de cerrar.
🛠️ ¿Cómo funciona?
Configuración
Todos los parámetros importantes (tamaño de ventana, cantidad de estrellas, velocidad, etc.) están en src/configuration.hpp.
Generación de estrellas
Al iniciar, el programa crea muchas estrellas con posiciones y profundidades aleatorias.
Renderizado
Cada estrella se dibuja como un pequeño círculo.
El tamaño y el color dependen de su profundidad: las más cercanas se ven más grandes y brillantes.
Se usa un sf::VertexArray para dibujar todo de forma eficiente.
Movimiento
En cada frame, las estrellas se acercan al espectador.
Si una estrella pasa el plano más cercano, ¡vuelve al fondo para que el viaje nunca termine!
Eventos
El programa escucha eventos de la ventana:
Si presionas Escape o cierras la ventana, el programa termina.
⚡ ¿Cómo compilar y ejecutar?
Requisitos
CMake
Un compilador C++ moderno (GCC, Clang, MSVC, MinGW, etc.)
SFML 3.x (ya viene como submódulo/dependencia en este proyecto)
Compilación
   mkdir build
   cd build
   cmake ..
   cmake --build .

Apply to events.cpp
Ejecución
Ejecuta el binario generado (por ejemplo, ./MyProject o desde tu IDE).
¡Disfruta del espectáculo estelar! 🌠
🗂️ Estructura del código
src/main.cpp — Lógica principal y renderizado.
src/star.hpp — Definición de una estrella.
src/configuration.hpp — Parámetros de configuración.
src/events.hpp y src/events.cpp — Manejo de eventos de la ventana.
🎨 Personaliza tu universo
Puedes cambiar fácilmente:
El número de estrellas (conf::count)
El tamaño de la ventana (conf::window_size)
La velocidad de las estrellas (conf::speed)
El radio de las estrellas (conf::radius)
Todo esto está en src/configuration.hpp.
🙌 Créditos
Hecho con SFML y mucha pasión por la simulación visual.
Inspirado en los clásicos efectos de "starfield" de la demoscene.
