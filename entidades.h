#include "miniwin.h"
#include <stdbool.h> // 'bool'
//sound
#include <windows.h>
#include <stdio.h>


using namespace miniwin;


void dibujarProtagonista(int x, int y, int contadorVidaProtagonista){
    if (contadorVidaProtagonista == 3 ){
    // Las coordenadas (x, y) definen la esquina superior izquierda del área del Inca.
    // El tamaño general del Inca es aproximadamente 50x78 píxeles.

    // 1. Cabeza, Cabello y Mascapaicha
    color_rgb(150, 80, 50); // Color de piel
    rectangulo_lleno(15 + x, 10 + y, 40 + x, 25 + y);

    // Cabello negro
    color_rgb(0, 0, 0);
    rectangulo_lleno(13 + x, 10 + y, 42 + x, 15 + y);

    // Mascapaicha de Oro (Corona)
    color_rgb(255, 215, 0);
    rectangulo_lleno(15 + x, 8 + y, 40 + x, 10 + y);

    // Pluma central (detalle blanco)
    color_rgb(255, 255, 255);
    rectangulo_lleno(26 + x, 0 + y, 29 + x, 8 + y);


    // 2. Cuerpo Musculoso y Piel
    color_rgb(150, 80, 50); // Color de piel (Bronceado)
    // Torsó ancho y musculoso
    rectangulo_lleno(10 + x, 25 + y, 45 + x, 45 + y);


    // 3. Joyería de Oro (Pecho y Brazaletes)
    color_rgb(255, 215, 0); // DORADO INTENSO (Oro)

    // Pectoral/Escudo ceremonial de oro
    rectangulo_lleno(15 + x, 28 + y, 40 + x, 35 + y);

    // Brazaletes/Muñequeras de Oro
    // La muñeca derecha sostiene el arco, la izquierda se usa para tensar.
    rectangulo_lleno(45 + x, 38 + y, 50 + x, 41 + y); // Muñeca derecha (cerca de la mano del arco)
    rectangulo_lleno(5 + x, 38 + y, 10 + x, 41 + y); // Muñeca izquierda (cerca de la cuerda)


    // 4. Brazos y Arco (APUNTANDO A LA DERECHA)

    // Brazo derecho: Sosteniendo el arco
    color_rgb(150, 80, 50); // Piel
    rectangulo_lleno(40 + x, 30 + y, 45 + x, 40 + y);

    // Brazo izquierdo: Estirado y tensando la cuerda (más a la derecha)
    color_rgb(150, 80, 50); // Piel
    rectangulo_lleno(50 + x, 30 + y, 65 + x, 35 + y); // Brazo estirado horizontalmente

    // Arco (curvado hacia la derecha)
    color_rgb(100, 50, 0); // Arco de Madera
    // Palo curvo simulado a la DERECHA del cuerpo, sostenido por el brazo derecho.
    rectangulo_lleno(45 + x, 25 + y, 50 + x, 60 + y);

    // Cuerda estirada (desde el arco hasta la mano izquierda)
    color_rgb(200, 200, 200); // Gris claro (Cuerda)
    linea(50 + x, 32 + y, 65 + x, 32 + y); // Línea horizontal estirada


    // 5. Vestimenta Mínima y Piernas
    color_rgb(150, 0, 0); // Rojo imperial (Tela)
    rectangulo_lleno(10 + x, 45 + y, 45 + x, 50 + y);
    rectangulo_lleno(20 + x, 50 + y, 35 + x, 55 + y);

    color_rgb(150, 80, 50); // Piel
    rectangulo_lleno(15 + x, 55 + y, 25 + x, 75 + y);
    rectangulo_lleno(30 + x, 55 + y, 40 + x, 75 + y);

    // Sandalias de Oro
    color_rgb(255, 215, 0);
    rectangulo_lleno(15 + x, 75 + y, 25 + x, 78 + y);
    rectangulo_lleno(30 + x, 75 + y, 40 + x, 78 + y);
    texto(x-25, y+80, "Inca Atahualpa");
}
    if (contadorVidaProtagonista == 2) {
        // --- CÓDIGO BASE ---
    color_rgb(150, 80, 50); // Color de piel
    rectangulo_lleno(15 + x, 10 + y, 40 + x, 25 + y);
    color_rgb(0, 0, 0);
    rectangulo_lleno(13 + x, 10 + y, 42 + x, 15 + y);

    // ORO LIGERAMENTE DAÑADO
    color_rgb(150, 110, 0); // Oro oxidado (menos brillo)
    rectangulo_lleno(15 + x, 8 + y, 40 + x, 10 + y); // Mascapaicha
    color_rgb(255, 255, 255);
    rectangulo_lleno(26 + x, 0 + y, 29 + x, 8 + y);

    // Cuerpo Base
    color_rgb(170, 90, 60); // Piel ligeramente más pálida
    rectangulo_lleno(10 + x, 25 + y, 45 + x, 45 + y);

    // Joyería Opaca
    color_rgb(150, 110, 0);
    rectangulo_lleno(15 + x, 28 + y, 40 + x, 35 + y); // Pectoral opaco
    rectangulo_lleno(45 + x, 38 + y, 50 + x, 41 + y);
    rectangulo_lleno(5 + x, 38 + y, 10 + x, 41 + y);

    // Brazos y Arco (NORMAL)
    color_rgb(170, 90, 60); // Piel
    rectangulo_lleno(40 + x, 30 + y, 45 + x, 40 + y);
    rectangulo_lleno(50 + x, 30 + y, 65 + x, 35 + y);
    color_rgb(100, 50, 0);
    rectangulo_lleno(45 + x, 25 + y, 50 + x, 60 + y);
    color_rgb(200, 200, 200);
    linea(50 + x, 32 + y, 65 + x, 32 + y);

    // Vestimenta y Piernas
    color_rgb(150, 0, 0);
    rectangulo_lleno(10 + x, 45 + y, 45 + x, 50 + y);
    rectangulo_lleno(20 + x, 50 + y, 35 + x, 55 + y);
    color_rgb(170, 90, 60); // Piel
    rectangulo_lleno(15 + x, 55 + y, 25 + x, 75 + y);
    rectangulo_lleno(30 + x, 55 + y, 40 + x, 75 + y);
    color_rgb(150, 110, 0); // Sandalias opacas
    rectangulo_lleno(15 + x, 75 + y, 25 + x, 78 + y);
    rectangulo_lleno(30 + x, 75 + y, 40 + x, 78 + y);

    // --- EFECTO DE DAÑO (2 CORAZONES) ---
    // Mancha de sangre superficial cerca del torso.
    color_rgb(255, 0, 0); // Rojo sangre
    rectangulo_lleno(40 + x, 30 + y, 45 + x, 33 + y);
    rectangulo_lleno(20 + x, 40 + y, 22 + x, 43 + y); // Segunda mancha pequeña
    }
    if (contadorVidaProtagonista == 1) {
        // Piel MUY pálida/grisácea
    color_rgb(120, 70, 40);
    rectangulo_lleno(15 + x, 10 + y, 40 + x, 25 + y); // Cabeza
    color_rgb(0, 0, 0);
    rectangulo_lleno(13 + x, 10 + y, 42 + x, 15 + y);

    // Joyas rotas/oscuras
    color_rgb(80, 80, 80); // Gris oscuro
    rectangulo_lleno(15 + x, 8 + y, 40 + x, 10 + y); // Mascapaicha rota
    color_rgb(255, 255, 255);
    rectangulo_lleno(26 + x, 0 + y, 29 + x, 8 + y);

    // Cuerpo Base
    color_rgb(120, 70, 40); // Piel grisácea
    rectangulo_lleno(10 + x, 25 + y, 45 + x, 45 + y);

    // Joyería destruida
    color_rgb(80, 80, 80);
    rectangulo_lleno(15 + x, 28 + y, 40 + x, 35 + y); // Pectoral destruido
    rectangulo_lleno(45 + x, 38 + y, 50 + x, 41 + y);
    rectangulo_lleno(5 + x, 38 + y, 10 + x, 41 + y);

    // Brazos y Arco (POSTURA DEBILITADA)
    color_rgb(120, 70, 40); // Piel
    rectangulo_lleno(40 + x, 30 + y, 45 + x, 40 + y); // Brazo derecho

    // Brazo izquierdo CAÍDO (en lugar de estirado horizontalmente)
    rectangulo_lleno(50 + x, 40 + y, 65 + x, 45 + y);

    color_rgb(100, 50, 0);
    rectangulo_lleno(45 + x, 25 + y, 50 + x, 60 + y);
    // NOTA: No dibujamos la cuerda para simular que no puede tensar el arco

    // Vestimenta y Piernas
    color_rgb(150, 0, 0);
    rectangulo_lleno(10 + x, 45 + y, 45 + x, 50 + y);
    rectangulo_lleno(20 + x, 50 + y, 35 + x, 55 + y);
    color_rgb(120, 70, 40); // Piel
    rectangulo_lleno(15 + x, 55 + y, 25 + x, 75 + y);
    rectangulo_lleno(30 + x, 55 + y, 40 + x, 75 + y);
    color_rgb(80, 80, 80); // Sandalias rotas
    rectangulo_lleno(15 + x, 75 + y, 25 + x, 78 + y);
    rectangulo_lleno(30 + x, 75 + y, 40 + x, 78 + y);

    // --- EFECTO DE DAÑO (1 CORAZÓN) ---
    color_rgb(200, 0, 0); // Sangre oscura
    // Herida grande en el pecho
    rectangulo_lleno(20 + x, 30 + y, 35 + x, 38 + y);
    // Herida en la pierna
    rectangulo_lleno(32 + x, 60 + y, 35 + x, 65 + y);
    // Herida en la cabeza
    rectangulo_lleno(35 + x, 15 + y, 38 + x, 18 + y);
    }
}
void dibujarEnemigoPrincipal(int x, int y, int nivelActual){
    if (nivelActual == 1) {
        // Las coordenadas (x, y) definen la esquina superior izquierda del área del soldado.

    // 1. Armadura del Cuerpo (Coraza)
    color_rgb(100, 100, 100); // Gris metálico oscuro para el cuerpo
    rectangulo_lleno(10 + x, 15 + y, 35 + x, 40 + y);

    // Hombros/Hombreras
    color_rgb(120, 120, 120); // Gris metálico más claro
    rectangulo_lleno(35 + x, 18 + y, 40 + x, 25 + y); // Hombrera derecha
    rectangulo_lleno(5 + x, 18 + y, 10 + x, 25 + y); // Hombrera izquierda


    // 2. Casco (Morrión)
    color_rgb(120, 120, 120); // Gris metálico
    rectangulo_lleno(12 + x, 5 + y, 33 + x, 15 + y);
    color_rgb(140, 140, 140); // Brillo en la cresta
    rectangulo_lleno(20 + x, 0 + y, 25 + x, 5 + y);


    // 3. Brazos y Guanteletes (Ajustados para apuntar HORIZONTALMENTE a la IZQUIERDA)
    color_rgb(100, 100, 100); // Gris oscuro

    // Brazo izquierdo: Extendido hacia adelante, sosteniendo la parte frontal del arma
    rectangulo_lleno(0 + x, 30 + y, 10 + x, 35 + y);
    // Guantelete izquierdo
    color_rgb(130, 130, 130);
    rectangulo_lleno(0 + x, 35 + y, 10 + x, 38 + y);

    // Brazo derecho: Doblado, sosteniendo la culata cerca del cuerpo
    color_rgb(100, 100, 100); // Gris oscuro
    rectangulo_lleno(30 + x, 30 + y, 35 + x, 40 + y);
    // Guantelete derecho
    color_rgb(130, 130, 130);
    rectangulo_lleno(30 + x, 40 + y, 35 + x, 43 + y);


    // 4. Arcabuz (Rifle primitivo) - ¡Horizontal y apuntando a la IZQUIERDA!
    color_rgb(80, 40, 0); // Marrón oscuro (Madera del arma)
    // Culata (parte trasera, cerca del hombro)
    rectangulo_lleno(30 + x, 30 + y, 38 + x, 35 + y); // Ancha y corta

    // Cuerpo principal del arcabuz (horizontal)
    rectangulo_lleno(10 + x, 31 + y, 30 + x, 34 + y);

    color_rgb(50, 50, 50); // Negro/Gris muy oscuro (Cañón de metal)
    // Cañón del arcabuz (se extiende a la IZQUIERDA, más delgado)
    rectangulo_lleno(0 + x, 32 + y, 10 + x, 33 + y);

    // Mecanismo de disparo (pequeño detalle en el lado derecho de la culata)
    color_rgb(120, 120, 120);
    rectangulo_lleno(28 + x, 35 + y, 29 + x, 38 + y);


    // 5. Piernas y Botas (Grebas y Borceguíes)
    color_rgb(100, 100, 100); // Gris oscuro (Armadura de las piernas)
    rectangulo_lleno(10 + x, 40 + y, 20 + x, 65 + y);
    rectangulo_lleno(25 + x, 40 + y, 35 + x, 65 + y);

    color_rgb(60, 30, 0); // Marrón oscuro (Cuero)
    rectangulo_lleno(10 + x, 65 + y, 20 + x, 70 + y);
    rectangulo_lleno(25 + x, 65 + y, 35 + x, 70 + y);
    }

    if (nivelActual == 2) {
       // 1. Armadura del Cuerpo (Coraza)
    color_rgb(100, 100, 100); // Gris metálico oscuro para el cuerpo
    rectangulo_lleno(10 + x, 15 + y, 35 + x, 40 + y);

    // 🌟 DETALLE DE ORO en la Coraza (Rango/Ornamentación)
    color_rgb(255, 215, 0); // Dorado
    rectangulo_lleno(10 + x, 15 + y, 35 + x, 18 + y); // Borde superior dorado
    rectangulo_lleno(22 + x, 25 + y, 23 + x, 35 + y); // Línea central vertical dorada

    // Hombros/Hombreras
    color_rgb(120, 120, 120); // Gris metálico más claro
    rectangulo_lleno(35 + x, 18 + y, 40 + x, 25 + y); // Hombrera derecha
    rectangulo_lleno(5 + x, 18 + y, 10 + x, 25 + y); // Hombrera izquierda


    // 2. Casco (Morrión)
    color_rgb(120, 120, 120); // Gris metálico
    rectangulo_lleno(12 + x, 5 + y, 33 + x, 15 + y);
    color_rgb(140, 140, 140); // Brillo en la cresta

    // 🌟 CRESTA DEL CASCO DORADA
    color_rgb(255, 215, 0); // Dorado
    rectangulo_lleno(20 + x, 0 + y, 25 + x, 5 + y);


    // 3. Vestimenta del Uniforme (Nueva Capa de Color)
    color_rgb(0, 0, 128); // Azul marino/real (Debajo de la armadura)
    rectangulo_lleno(10 + x, 40 + y, 35 + x, 45 + y); // Falda o tela visible


    // 4. Brazos y Guanteletes (Ajustados para apuntar HORIZONTALMENTE a la IZQUIERDA)
    color_rgb(100, 100, 100); // Gris oscuro (Brazos)

    // Brazo izquierdo: Extendido
    rectangulo_lleno(0 + x, 30 + y, 10 + x, 35 + y);
    // Guantelete izquierdo
    color_rgb(130, 130, 130);
    rectangulo_lleno(0 + x, 35 + y, 10 + x, 38 + y);

    // Brazo derecho: Doblado
    color_rgb(100, 100, 100);
    rectangulo_lleno(30 + x, 30 + y, 35 + x, 40 + y);
    // Guantelete derecho
    color_rgb(130, 130, 130);
    rectangulo_lleno(30 + x, 40 + y, 35 + x, 43 + y);


    // 5. Arcabuz (Rifle primitivo) - ¡Horizontal y apuntando a la IZQUIERDA!
    color_rgb(80, 40, 0); // Marrón oscuro (Madera del arma)
    // Culata
    rectangulo_lleno(30 + x, 30 + y, 38 + x, 35 + y);

    // Cuerpo principal del arcabuz (horizontal)
    rectangulo_lleno(10 + x, 31 + y, 30 + x, 34 + y);

    color_rgb(50, 50, 50); // Negro/Gris muy oscuro (Cañón de metal)
    // Cañón del arcabuz
    rectangulo_lleno(0 + x, 32 + y, 10 + x, 33 + y);

    // 🌟 DETALLE DE METAL MEJORADO/BRILLANTE en el Cañón
    color_rgb(180, 180, 180); // Gris muy claro (Brillo)
    rectangulo_lleno(8 + x, 32 + y, 9 + x, 33 + y); // Punto de brillo en el cañón

    // Mecanismo de disparo
    color_rgb(120, 120, 120);
    rectangulo_lleno(28 + x, 35 + y, 29 + x, 38 + y);


    // 6. Piernas y Botas (Grebas y Borceguíes)
    color_rgb(100, 100, 100); // Gris oscuro (Armadura de las piernas)
    rectangulo_lleno(10 + x, 40 + y, 20 + x, 65 + y);
    rectangulo_lleno(25 + x, 40 + y, 35 + x, 65 + y);

    color_rgb(60, 30, 0); // Marrón oscuro (Cuero)
    rectangulo_lleno(10 + x, 65 + y, 20 + x, 70 + y);
    rectangulo_lleno(25 + x, 65 + y, 35 + x, 70 + y);
    }

}
void dibujarEnemigo2(int x, int y, int nivelActual) {
    if (nivelActual == 1) {
        // Las coordenadas (x, y) definen la esquina superior izquierda del área del soldado.

    // 1. Armadura del Cuerpo (Coraza)
    color_rgb(100, 100, 100); // Gris metálico oscuro para el cuerpo
    rectangulo_lleno(10 + x, 15 + y, 35 + x, 40 + y);

    // Hombros/Hombreras
    color_rgb(120, 120, 120); // Gris metálico más claro
    rectangulo_lleno(35 + x, 18 + y, 40 + x, 25 + y); // Hombrera derecha
    rectangulo_lleno(5 + x, 18 + y, 10 + x, 25 + y); // Hombrera izquierda


    // 2. Casco (Morrión)
    color_rgb(120, 120, 120); // Gris metálico
    rectangulo_lleno(12 + x, 5 + y, 33 + x, 15 + y);
    color_rgb(140, 140, 140); // Brillo en la cresta
    rectangulo_lleno(20 + x, 0 + y, 25 + x, 5 + y);


    // 3. Brazos y Guanteletes (Ajustados para apuntar HORIZONTALMENTE a la IZQUIERDA)
    color_rgb(100, 100, 100); // Gris oscuro

    // Brazo izquierdo: Extendido hacia adelante, sosteniendo la parte frontal del arma
    rectangulo_lleno(0 + x, 30 + y, 10 + x, 35 + y);
    // Guantelete izquierdo
    color_rgb(130, 130, 130);
    rectangulo_lleno(0 + x, 35 + y, 10 + x, 38 + y);

    // Brazo derecho: Doblado, sosteniendo la culata cerca del cuerpo
    color_rgb(100, 100, 100); // Gris oscuro
    rectangulo_lleno(30 + x, 30 + y, 35 + x, 40 + y);
    // Guantelete derecho
    color_rgb(130, 130, 130);
    rectangulo_lleno(30 + x, 40 + y, 35 + x, 43 + y);


    // 4. Arcabuz (Rifle primitivo) - ¡Horizontal y apuntando a la IZQUIERDA!
    color_rgb(80, 40, 0); // Marrón oscuro (Madera del arma)
    // Culata (parte trasera, cerca del hombro)
    rectangulo_lleno(30 + x, 30 + y, 38 + x, 35 + y); // Ancha y corta

    // Cuerpo principal del arcabuz (horizontal)
    rectangulo_lleno(10 + x, 31 + y, 30 + x, 34 + y);

    color_rgb(50, 50, 50); // Negro/Gris muy oscuro (Cañón de metal)
    // Cañón del arcabuz (se extiende a la IZQUIERDA, más delgado)
    rectangulo_lleno(0 + x, 32 + y, 10 + x, 33 + y);

    // Mecanismo de disparo (pequeño detalle en el lado derecho de la culata)
    color_rgb(120, 120, 120);
    rectangulo_lleno(28 + x, 35 + y, 29 + x, 38 + y);


    // 5. Piernas y Botas (Grebas y Borceguíes)
    color_rgb(100, 100, 100); // Gris oscuro (Armadura de las piernas)
    rectangulo_lleno(10 + x, 40 + y, 20 + x, 65 + y);
    rectangulo_lleno(25 + x, 40 + y, 35 + x, 65 + y);

    color_rgb(60, 30, 0); // Marrón oscuro (Cuero)
    rectangulo_lleno(10 + x, 65 + y, 20 + x, 70 + y);
    rectangulo_lleno(25 + x, 65 + y, 35 + x, 70 + y);
    }

    if (nivelActual == 2) {
      // 1. Armadura del Cuerpo (Coraza)
    color_rgb(100, 100, 100); // Gris metálico oscuro para el cuerpo
    rectangulo_lleno(10 + x, 15 + y, 35 + x, 40 + y);

    // 🌟 DETALLE DE ORO en la Coraza (Rango/Ornamentación)
    color_rgb(255, 215, 0); // Dorado
    rectangulo_lleno(10 + x, 15 + y, 35 + x, 18 + y); // Borde superior dorado
    rectangulo_lleno(22 + x, 25 + y, 23 + x, 35 + y); // Línea central vertical dorada

    // Hombros/Hombreras
    color_rgb(120, 120, 120); // Gris metálico más claro
    rectangulo_lleno(35 + x, 18 + y, 40 + x, 25 + y); // Hombrera derecha
    rectangulo_lleno(5 + x, 18 + y, 10 + x, 25 + y); // Hombrera izquierda


    // 2. Casco (Morrión)
    color_rgb(120, 120, 120); // Gris metálico
    rectangulo_lleno(12 + x, 5 + y, 33 + x, 15 + y);
    color_rgb(140, 140, 140); // Brillo en la cresta

    // 🌟 CRESTA DEL CASCO DORADA
    color_rgb(255, 215, 0); // Dorado
    rectangulo_lleno(20 + x, 0 + y, 25 + x, 5 + y);


    // 3. Vestimenta del Uniforme (Nueva Capa de Color)
    color_rgb(0, 0, 128); // Azul marino/real (Debajo de la armadura)
    rectangulo_lleno(10 + x, 40 + y, 35 + x, 45 + y); // Falda o tela visible


    // 4. Brazos y Guanteletes (Ajustados para apuntar HORIZONTALMENTE a la IZQUIERDA)
    color_rgb(100, 100, 100); // Gris oscuro (Brazos)

    // Brazo izquierdo: Extendido
    rectangulo_lleno(0 + x, 30 + y, 10 + x, 35 + y);
    // Guantelete izquierdo
    color_rgb(130, 130, 130);
    rectangulo_lleno(0 + x, 35 + y, 10 + x, 38 + y);

    // Brazo derecho: Doblado
    color_rgb(100, 100, 100);
    rectangulo_lleno(30 + x, 30 + y, 35 + x, 40 + y);
    // Guantelete derecho
    color_rgb(130, 130, 130);
    rectangulo_lleno(30 + x, 40 + y, 35 + x, 43 + y);


    // 5. Arcabuz (Rifle primitivo) - ¡Horizontal y apuntando a la IZQUIERDA!
    color_rgb(80, 40, 0); // Marrón oscuro (Madera del arma)
    // Culata
    rectangulo_lleno(30 + x, 30 + y, 38 + x, 35 + y);

    // Cuerpo principal del arcabuz (horizontal)
    rectangulo_lleno(10 + x, 31 + y, 30 + x, 34 + y);

    color_rgb(50, 50, 50); // Negro/Gris muy oscuro (Cañón de metal)
    // Cañón del arcabuz
    rectangulo_lleno(0 + x, 32 + y, 10 + x, 33 + y);

    // 🌟 DETALLE DE METAL MEJORADO/BRILLANTE en el Cañón
    color_rgb(180, 180, 180); // Gris muy claro (Brillo)
    rectangulo_lleno(8 + x, 32 + y, 9 + x, 33 + y); // Punto de brillo en el cañón

    // Mecanismo de disparo
    color_rgb(120, 120, 120);
    rectangulo_lleno(28 + x, 35 + y, 29 + x, 38 + y);


    // 6. Piernas y Botas (Grebas y Borceguíes)
    color_rgb(100, 100, 100); // Gris oscuro (Armadura de las piernas)
    rectangulo_lleno(10 + x, 40 + y, 20 + x, 65 + y);
    rectangulo_lleno(25 + x, 40 + y, 35 + x, 65 + y);

    color_rgb(60, 30, 0); // Marrón oscuro (Cuero)
    rectangulo_lleno(10 + x, 65 + y, 20 + x, 70 + y);
    rectangulo_lleno(25 + x, 65 + y, 35 + x, 70 + y);
    }

}

void dibujarEnemigo3(int x, int y, int nivelActual) {
    if (nivelActual == 1) {
        // Las coordenadas (x, y) definen la esquina superior izquierda del área del soldado.

    // 1. Armadura del Cuerpo (Coraza)
    color_rgb(100, 100, 100); // Gris metálico oscuro para el cuerpo
    rectangulo_lleno(10 + x, 15 + y, 35 + x, 40 + y);

    // Hombros/Hombreras
    color_rgb(120, 120, 120); // Gris metálico más claro
    rectangulo_lleno(35 + x, 18 + y, 40 + x, 25 + y); // Hombrera derecha
    rectangulo_lleno(5 + x, 18 + y, 10 + x, 25 + y); // Hombrera izquierda


    // 2. Casco (Morrión)
    color_rgb(120, 120, 120); // Gris metálico
    rectangulo_lleno(12 + x, 5 + y, 33 + x, 15 + y);
    color_rgb(140, 140, 140); // Brillo en la cresta
    rectangulo_lleno(20 + x, 0 + y, 25 + x, 5 + y);


    // 3. Brazos y Guanteletes (Ajustados para apuntar HORIZONTALMENTE a la IZQUIERDA)
    color_rgb(100, 100, 100); // Gris oscuro

    // Brazo izquierdo: Extendido hacia adelante, sosteniendo la parte frontal del arma
    rectangulo_lleno(0 + x, 30 + y, 10 + x, 35 + y);
    // Guantelete izquierdo
    color_rgb(130, 130, 130);
    rectangulo_lleno(0 + x, 35 + y, 10 + x, 38 + y);

    // Brazo derecho: Doblado, sosteniendo la culata cerca del cuerpo
    color_rgb(100, 100, 100); // Gris oscuro
    rectangulo_lleno(30 + x, 30 + y, 35 + x, 40 + y);
    // Guantelete derecho
    color_rgb(130, 130, 130);
    rectangulo_lleno(30 + x, 40 + y, 35 + x, 43 + y);


    // 4. Arcabuz (Rifle primitivo) - ¡Horizontal y apuntando a la IZQUIERDA!
    color_rgb(80, 40, 0); // Marrón oscuro (Madera del arma)
    // Culata (parte trasera, cerca del hombro)
    rectangulo_lleno(30 + x, 30 + y, 38 + x, 35 + y); // Ancha y corta

    // Cuerpo principal del arcabuz (horizontal)
    rectangulo_lleno(10 + x, 31 + y, 30 + x, 34 + y);

    color_rgb(50, 50, 50); // Negro/Gris muy oscuro (Cañón de metal)
    // Cañón del arcabuz (se extiende a la IZQUIERDA, más delgado)
    rectangulo_lleno(0 + x, 32 + y, 10 + x, 33 + y);

    // Mecanismo de disparo (pequeño detalle en el lado derecho de la culata)
    color_rgb(120, 120, 120);
    rectangulo_lleno(28 + x, 35 + y, 29 + x, 38 + y);


    // 5. Piernas y Botas (Grebas y Borceguíes)
    color_rgb(100, 100, 100); // Gris oscuro (Armadura de las piernas)
    rectangulo_lleno(10 + x, 40 + y, 20 + x, 65 + y);
    rectangulo_lleno(25 + x, 40 + y, 35 + x, 65 + y);

    color_rgb(60, 30, 0); // Marrón oscuro (Cuero)
    rectangulo_lleno(10 + x, 65 + y, 20 + x, 70 + y);
    rectangulo_lleno(25 + x, 65 + y, 35 + x, 70 + y);
    }

    if (nivelActual == 2) {
      // 1. Armadura del Cuerpo (Coraza)
    color_rgb(100, 100, 100); // Gris metálico oscuro para el cuerpo
    rectangulo_lleno(10 + x, 15 + y, 35 + x, 40 + y);

    // 🌟 DETALLE DE ORO en la Coraza (Rango/Ornamentación)
    color_rgb(255, 215, 0); // Dorado
    rectangulo_lleno(10 + x, 15 + y, 35 + x, 18 + y); // Borde superior dorado
    rectangulo_lleno(22 + x, 25 + y, 23 + x, 35 + y); // Línea central vertical dorada

    // Hombros/Hombreras
    color_rgb(120, 120, 120); // Gris metálico más claro
    rectangulo_lleno(35 + x, 18 + y, 40 + x, 25 + y); // Hombrera derecha
    rectangulo_lleno(5 + x, 18 + y, 10 + x, 25 + y); // Hombrera izquierda


    // 2. Casco (Morrión)
    color_rgb(120, 120, 120); // Gris metálico
    rectangulo_lleno(12 + x, 5 + y, 33 + x, 15 + y);
    color_rgb(140, 140, 140); // Brillo en la cresta

    // 🌟 CRESTA DEL CASCO DORADA
    color_rgb(255, 215, 0); // Dorado
    rectangulo_lleno(20 + x, 0 + y, 25 + x, 5 + y);


    // 3. Vestimenta del Uniforme (Nueva Capa de Color)
    color_rgb(0, 0, 128); // Azul marino/real (Debajo de la armadura)
    rectangulo_lleno(10 + x, 40 + y, 35 + x, 45 + y); // Falda o tela visible


    // 4. Brazos y Guanteletes (Ajustados para apuntar HORIZONTALMENTE a la IZQUIERDA)
    color_rgb(100, 100, 100); // Gris oscuro (Brazos)

    // Brazo izquierdo: Extendido
    rectangulo_lleno(0 + x, 30 + y, 10 + x, 35 + y);
    // Guantelete izquierdo
    color_rgb(130, 130, 130);
    rectangulo_lleno(0 + x, 35 + y, 10 + x, 38 + y);

    // Brazo derecho: Doblado
    color_rgb(100, 100, 100);
    rectangulo_lleno(30 + x, 30 + y, 35 + x, 40 + y);
    // Guantelete derecho
    color_rgb(130, 130, 130);
    rectangulo_lleno(30 + x, 40 + y, 35 + x, 43 + y);


    // 5. Arcabuz (Rifle primitivo) - ¡Horizontal y apuntando a la IZQUIERDA!
    color_rgb(80, 40, 0); // Marrón oscuro (Madera del arma)
    // Culata
    rectangulo_lleno(30 + x, 30 + y, 38 + x, 35 + y);

    // Cuerpo principal del arcabuz (horizontal)
    rectangulo_lleno(10 + x, 31 + y, 30 + x, 34 + y);

    color_rgb(50, 50, 50); // Negro/Gris muy oscuro (Cañón de metal)
    // Cañón del arcabuz
    rectangulo_lleno(0 + x, 32 + y, 10 + x, 33 + y);

    // 🌟 DETALLE DE METAL MEJORADO/BRILLANTE en el Cañón
    color_rgb(180, 180, 180); // Gris muy claro (Brillo)
    rectangulo_lleno(8 + x, 32 + y, 9 + x, 33 + y); // Punto de brillo en el cañón

    // Mecanismo de disparo
    color_rgb(120, 120, 120);
    rectangulo_lleno(28 + x, 35 + y, 29 + x, 38 + y);


    // 6. Piernas y Botas (Grebas y Borceguíes)
    color_rgb(100, 100, 100); // Gris oscuro (Armadura de las piernas)
    rectangulo_lleno(10 + x, 40 + y, 20 + x, 65 + y);
    rectangulo_lleno(25 + x, 40 + y, 35 + x, 65 + y);

    color_rgb(60, 30, 0); // Marrón oscuro (Cuero)
    rectangulo_lleno(10 + x, 65 + y, 20 + x, 70 + y);
    rectangulo_lleno(25 + x, 65 + y, 35 + x, 70 + y);
    }
}

void dibujarCorazon(int x, int y){
    color_rgb(255, 0, 0); // Rojo puro


    // Centro (El rectángulo principal)
    rectangulo_lleno(4 + x, 4 + y, 11 + x, 11 + y);

    // Punta (Parte de abajo)
    rectangulo_lleno(6 + x, 11 + y, 9 + x, 14 + y);


    // Lóbulo Izquierdo
    rectangulo_lleno(2 + x, 2 + y, 7 + x, 6 + y);

    // Lóbulo Derecho
    rectangulo_lleno(8 + x, 2 + y, 13 + x, 6 + y);
}

void dibujarMensajeDoubleKill(int sizeAncho, int sizeAlto, bool esContadorActivo) {
     if (esContadorActivo == true ){
        int x_centro = sizeAncho / 2;
        int y_centro = sizeAlto / 2;

        // 1. Fondo Oscuro
        color_rgb(20, 20, 20);
        rectangulo_lleno(x_centro - 100, y_centro - 275, x_centro + 100, y_centro -275);

        // 2. Borde Brillante
        color_rgb(255, 215, 0); // Dorado
        rectangulo(x_centro - 100, y_centro - 275, x_centro + 100, y_centro - 225);
        rectangulo(x_centro - 98, y_centro - 273, x_centro + 98, y_centro - 223);

        // 3. El Texto "DOUBLE KILL!!!!!"
        color_rgb(255, 255, 255); // Blanco
        // Posición del texto (ajustada para estar visualmente centrado dentro del banner)
        // El texto en miniwin se dibuja desde la esquina superior izquierda.
        // Usamos el centro (x_centro) y restamos 75px (ajuste manual para centrar el texto).
        texto(x_centro - 60, y_centro - 255, "DOUBLE KILL!!!!!");
     }

}

void dibujarCartelSegundoNivel (int sizeAncho, int sizeAlto, bool esCartelSegundoNivelActivo) {
    if (esCartelSegundoNivelActivo == true) {
        // 1. CALCULAR EL CENTRO DEL CARTEL
    // Asumimos que el cartel debe estar en el centro de la pantalla.
    int x_centro = sizeAncho / 2; // 500
    int y_centro = sizeAlto / 2;  // 325

    // 2. DIMENSIONES DEL CARTEL
    int ancho_banner = 300; // Ancho total del cartel
    int alto_banner = 150;  // Alto total del cartel

    // Coordenadas de las esquinas del cartel principal
    int x1 = x_centro - (ancho_banner / 2); // 500 - 150 = 350
    int y1 = y_centro - (alto_banner / 2);  // 325 - 75  = 250
    int x2 = x_centro + (ancho_banner / 2); // 500 + 150 = 650
    int y2 = y_centro + (alto_banner / 2);  // 325 + 75  = 400

    // --- DISEÑO BASE Y FONDO (Efecto de Profundidad) ---
    // Capa más oscura (fondo)
    color_rgb(10, 10, 30); // Azul oscuro casi negro
    rectangulo_lleno(x1, y1, x2, y2);

    // Capa ligeramente más clara (efecto de degradado/profundidad)
    color_rgb(20, 20, 50); // Azul más claro
    rectangulo_lleno(x1 + 5, y1 + 5, x2 - 5, y2 - 5);

    // --- BORDE DE ORO BRILLANTE (Detallado) ---
    color_rgb(255, 215, 0); // Oro
    // Borde exterior
    rectangulo(x1, y1, x2, y2);
    // Borde interior
    rectangulo(x1 + 2, y1 + 2, x2 - 2, y2 - 2);

    // Pequeños puntos de luz en las esquinas (brillo)
    color_rgb(255, 255, 150); // Amarillo pálido para brillo
    punto(x1 + 1, y1 + 1);
    punto(x2 - 1, y1 + 1);
    punto(x1 + 1, y2 - 1);
    punto(x2 - 1, y2 - 1);

    // --- DECORACIONES LATERALES (Estrellas/Laureles) ---
    color_rgb(255, 215, 0); // Oro
    int y_deco = y_centro; // Centro vertical para las decoraciones

    // Decoración Izquierda
    // Rectángulo vertical central
    rectangulo_lleno(x1 + 15, y_deco - 10, x1 + 25, y_deco + 10);
    // Líneas de cruce (simulando una estrella)
    linea(x1 + 10, y_deco, x1 + 30, y_deco);
    linea(x1 + 20, y_deco - 15, x1 + 20, y_deco + 15);

    // Decoración Derecha
    // Rectángulo vertical central
    rectangulo_lleno(x2 - 25, y_deco - 10, x2 - 15, y_deco + 10);
    // Líneas de cruce
    linea(x2 - 30, y_deco, x2 - 10, y_deco);
    linea(x2 - 20, y_deco - 15, x2 - 20, y_deco + 15);

    // --- TEXTO PRINCIPAL: "NIVEL 2 DESBLOQUEADO!" ---

    // Texto 1: Nivel y Desbloqueado
    color_rgb(255, 255, 255); // Blanco brillante
    // Se usa un ajuste manual de -120 en X para centrar el texto grande.
    // Se usa un ajuste de -40 en Y para colocarlo en la parte superior del banner.
    texto(x_centro - 120, y_centro - 40, "NIVEL 2 DESBLOQUEADO!");

    // Texto 2: Mensaje motivacional
    color_rgb(200, 200, 255); // Azul claro/plateado
    // Se usa un ajuste manual de -100 en X para centrar el texto secundario.
    // Se usa un ajuste de +20 en Y para colocarlo en la parte inferior del banner.
    texto(x_centro - 100, y_centro + 20, "¡NUEVOS DESAFÍOS ESPERAN!");
    }
}
