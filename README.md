# SpaceTravel
Este código es un juego sencillo en C donde controlas una nave espacial y debes recolectar orbes de plasma mientras evitas chocar con asteroides

Este código es un juego sencillo en C donde controlas una nave espacial y debes recolectar orbes de plasma mientras evitas chocar con asteroides. El juego incluye un menú de bienvenida y de instrucciones, así como una pantalla de victoria y derrota al finalizar la partida.

Explicación del juego:

NAVE: Es una estructura que almacena la información de la nave, como sus coordenadas (x, y), la cantidad de corazones que tiene (representando su salud), la cantidad de vidas restantes y el puntaje.

ASTEROIDE: Es una estructura que almacena la información de los asteroides, como sus coordenadas (x, y).

Función Bienvenida: Muestra un mensaje de bienvenida al inicio del juego.

Función instrucciones: Muestra las instrucciones del juego.

Función Winner: Muestra un mensaje de felicitaciones cuando el jugador gana.

Función Loser: Muestra un mensaje de derrota cuando el jugador pierde.

Funciones gotoxy y OcultarCursor: Son funciones auxiliares para manipular la posición del cursor y ocultarlo.

Función Pintar_Limites: Dibuja los límites del juego en la pantalla.

Funciones relacionadas a la nave: PintarNave, BorrarNave, MoverNave, PintarCorazones y QuitarCorazones. Estas funciones pintan y manejan el movimiento de la nave, así como su representación visual y la gestión de sus corazones y vidas.

Funciones relacionadas a los asteroides: PintarAsteroide, MoverAsteroide, PintarAsteroide_b, MoverAsteroide_b, ChoqueAsteroide y ChoqueAsteroide_b. Estas funciones pintan y manejan el movimiento de los asteroides, así como las colisiones con la nave y el conteo de puntaje.

Función Morir: Gestiona la lógica de pérdida de vidas y actualiza la representación visual de la nave en caso de colisión con un asteroide.

La función main contiene la lógica principal del juego. Inicia el juego, muestra la nave, los asteroides y entra en un bucle donde se mueven los asteroides y la nave, y se detectan las colisiones y eventos del juego. El juego termina cuando el jugador se queda sin vidas o alcanza un puntaje de 20.

En resumen, este código implementa un pequeño juego de nave espacial en la consola de Windows, donde el jugador debe recolectar orbes de plasma mientras esquiva asteroides. Es un juego sencillo pero entretenido, con mensajes de victoria y derrota para proporcionar una experiencia completa al usuario.

![Game](https://github.com/LuisRosado/SpaceTravel/assets/140114139/aee903f3-1e47-4d19-a686-f08ff127ad4a)

