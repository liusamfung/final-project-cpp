#include "miniwin.h"
#include <stdbool.h> // 'bool'
//sound
#include <windows.h>
#include <stdio.h>
#include "entidades.h"

using namespace miniwin;
void dibujarBalaSi(bool en_vuelo, int x_BalaProta, int y_BalaProta, std::string whatEntidad, int nivelActual) {
    if (!en_vuelo) {
        return;
    }
    if (whatEntidad == "PROTAGONISTA"){
        int x_Flecha = x_BalaProta;
        int y_Flecha = y_BalaProta;

        // 🏹 Palo principal de la flecha (Madera) - ¡Ahora horizontal!
        color_rgb(139, 69, 19); // Marrón
        rectangulo_lleno(
            x_Flecha + 10,  // X_inicio (izquierda)
            y_Flecha + 23,  // Y_inicio (centro)
            x_Flecha + 40,  // X_fin (derecha)
            y_Flecha + 27   // Y_fin (centro)
        );

        // 💛 Punta de la flecha (Oro/Metal Inca) - ¡A la derecha del palo!
        color_rgb(255, 242, 0); // Amarillo brillante

        // Parte superior de la punta (la más afilada, X más a la derecha)
        rectangulo_lleno(
            x_Flecha + 40,  // X_inicio
            y_Flecha + 23,  // Y_inicio
            x_Flecha + 46,  // X_fin (¡Punta final!)
            y_Flecha + 27   // Y_fin
        );

        // Parte media de la punta (se ensancha)
        rectangulo_lleno(
            x_Flecha + 38,  // X_inicio
            y_Flecha + 20,  // Y_inicio
            x_Flecha + 40,  // X_fin
            y_Flecha + 30   // Y_fin
        );

        // Parte inferior de la punta (la más ancha, uniendo con el palo)
        rectangulo_lleno(
            x_Flecha + 35,  // X_inicio
            y_Flecha + 19,  // Y_inicio
            x_Flecha + 38,  // X_fin
            y_Flecha + 31   // Y_fin
        );

        // ⚪ Plumas de la flecha (detalle en la parte trasera) - ¡A la izquierda!
        color_rgb(200, 200, 200); // Gris claro
        // Pluma superior
        rectangulo_lleno(
            x_Flecha + 5,   // X_inicio (más a la izquierda)
            y_Flecha + 22,  // Y_inicio
            x_Flecha + 8,   // X_fin
            y_Flecha + 23   // Y_fin
        );
        // Pluma inferior
        rectangulo_lleno(
            x_Flecha + 5,   // X_inicio
            y_Flecha + 27,  // Y_inicio
            x_Flecha + 8,   // X_fin
            y_Flecha + 28   // Y_fin
        );
    }
    if (whatEntidad == "ENEMIGO"){
    int x_Bala = x_BalaProta;
    int y_Bala = y_BalaProta;
        if (nivelActual == 1){
            // Cuerpo de la bala (rectángulo principal) - ¡Ahora horizontal!
            color_rgb(120, 120, 120); // Gris metálico
            // Eje horizontal, centrado en Y (de y_Bala+8 a y_Bala+12)
            rectangulo_lleno(x_Bala + 5, y_Bala + 8, x_Bala + 25, y_Bala + 12);

            // Punta de la bala (simulada con un rectángulo más pequeño que se estrecha)
            // La punta va hacia la IZQUIERDA (X decreciente)
            color_rgb(150, 150, 150); // Gris más claro para la punta
            // Punta final (más a la izquierda, x_Bala+0 a x_Bala+5)
            rectangulo_lleno(x_Bala + 0, y_Bala + 9, x_Bala + 5, y_Bala + 11);

            // Base de la punta (para darle grosor)
            color_rgb(150, 150, 150);
            rectangulo_lleno(x_Bala + 5, y_Bala + 7, x_Bala + 8, y_Bala + 13);


            // Un pequeño detalle para simular el brillo o relieve de la bala
            color_rgb(180, 180, 180); // Gris claro
            // Puntos de brillo a lo largo del eje X
            punto(x_Bala + 15, y_Bala + 10);
            punto(x_Bala + 20, y_Bala + 10);
        }
        if (nivelActual == 2){
        // 💥 Efecto de Destello/Fuego (simula velocidad o humo de pólvora)

        // Fuego Exterior (Amarillo claro, más largo)
        color_rgb(255, 255, 102); // Amarillo pálido
        rectangulo_lleno(x_Bala + 25, y_Bala + 6, x_Bala + 35, y_Bala + 14);

        // Fuego Medio (Naranja/Rojo, más corto y oscuro)
        color_rgb(255, 140, 0); // Naranja
        rectangulo_lleno(x_Bala + 25, y_Bala + 7, x_Bala + 30, y_Bala + 13);

        // Centro (Rojo intenso o chispa)
        color_rgb(255, 0, 0); // Rojo puro
        rectangulo_lleno(x_Bala + 25, y_Bala + 9, x_Bala + 28, y_Bala + 11);


        // Cuerpo de la bala (rectángulo principal)
        color_rgb(120, 120, 120); // Gris metálico
        // Eje horizontal, centrado en Y (de y_Bala+8 a y_Bala+12)
        rectangulo_lleno(x_Bala + 5, y_Bala + 8, x_Bala + 25, y_Bala + 12);

        // Punta de la bala (simulada con un rectángulo más pequeño que se estrecha)
        // La punta va hacia la IZQUIERDA (X decreciente)
        color_rgb(150, 150, 150); // Gris más claro para la punta
        // Punta final (más a la izquierda, x_Bala+0 a x_Bala+5)
        rectangulo_lleno(x_Bala + 0, y_Bala + 9, x_Bala + 5, y_Bala + 11);

        // Base de la punta (para darle grosor)
        color_rgb(150, 150, 150);
        rectangulo_lleno(x_Bala + 5, y_Bala + 7, x_Bala + 8, y_Bala + 13);

        // Un pequeño detalle para simular el brillo o relieve de la bala
        color_rgb(180, 180, 180); // Gris claro
        // Puntos de brillo a lo largo del eje X
        punto(x_Bala + 15, y_Bala + 10);
        punto(x_Bala + 20, y_Bala + 10);
        }

    }
}

void botarEntidadDelMapa(int &x_entidad, int &y_entidad) {
    x_entidad = -5000;
    y_entidad = -1000;
}

// Inicia el disparo si la tecla es ESPACIO y no hay bala en vuelo.
void disparar(int x_avion, int y_avion, int &x_bala, int &y_bala) {
        x_bala = x_avion;
        y_bala = y_avion;
}

// Mueve la bala y la recicla si sale de pantalla.
void moverBalaDerecha(int &x_bala) {
    x_bala = x_bala + 20; // Mueve la bal
}

void moverBalaIzquierda(int &x_bala, int nivelActual, std::string whatEntidad) {
    if (nivelActual == 1){
        x_bala = x_bala - 8; // Mueve la bala hacia izquierda
    }
    if (nivelActual == 2){
        x_bala = x_bala - 15; // Mueve la bala hacia izquierda
    }
}

// Verifica si hay impacto y maneja las consecuencias.
bool hayColision(int x_bala, int y_bala, int &x_entidad, int &y_entidad) {
    //Aqui  nuestra hitbox sera de 30x45. Como en minecraft jjaaeuoaja
    bool colision_x = (x_bala >= x_entidad - 30 && x_bala <= x_entidad + 30); // Ajuste de rango
    bool colision_y = (y_bala >= y_entidad - 45 && y_bala <= y_entidad + 45);     // Ajuste de rango

    if (colision_x && colision_y) {
         return true;
    } else {
        return false;
    }

}

bool estaDentroDelMapa(int entidad_X){
    int bordeIzquierdoMapa = 50;
    int bordeDerechoMapa = 410;

    if (entidad_X >= bordeIzquierdoMapa && entidad_X <= bordeDerechoMapa){
        return true;
    } else {
        return false;
    }
}

int marcarTiempoActual(int tiempoJuegoActual){
    return tiempoJuegoActual;
}
//int tiempoCarteles(int duracionSeg){
//    if(tiempoJuegoActual >= tiempoMarcado && tiempoJuegoActual <= tiempoMarcado + 5){
//
//    }
//}

int main(){
    const int FPS_IDEAL = 65; // Tratemos de simular los segundos
    int contadorDeFrames = 0;
    int tiempoJuegoActual = 0; // Se incrementa cada segundo real

    bool esCartelSegundoNivelActivo = false;
    int tiempoMarcado = 0;

    int sizeAncho = 1000;
    int sizeAlto = 650;
    vredimensiona(sizeAncho, sizeAlto);

    int bordeIzquierdoMapa = 20;
    int bordeDerechoMapa = 950;
    int bordeSuperiorMapa = 20;
    int bordeInferiorMapa = 600;
    int contadorEnemigosEliminados = 0;

    int nivelActual = 1;

    int prota_X = 100, prota_Y = 300;
    int balaProta_X = 0, balaProta_Y = 0;
    bool balaProtaVolando = false;
    bool estaMuertoProta = false;
    int contadorVidaProtagonista = 3;
    int contadorComboKill = 0;
    bool esCartelComboActivo = false;


    int enemigoPrincipal_X = 900, enemigoPrincipal_Y = 100;
    int balaEnemigo1_X = 0, balaEnemigo1_Y = 0;
    int balaEnemigo1Volando = false;
    int dirEnemigoPrincipal = ARRIBA;
    bool estaMuertoEnemigoPri = false;



    int enemigo2_X = 800, enemigo2_Y = 100;
    int balaEnemigo2_X = 0, balaEnemigo2_Y = 0;
    int balaEnemigo2Volando = false;
    int dirEnemigo2 = ARRIBA;


    int enemigo3_X = 700, enemigo3_Y =150;
    int balaEnemigo3_X = 0, balaEnemigo3_Y = 0;
    int balaEnemigo3Volando = false;
    int dirEnemigo3 = ARRIBA;



    int t = tecla();

    // BUCLE DEL nuestro jueguito
    while(t != ESCAPE){

        // Movimiento del protaprotagoni
        if(t == ARRIBA && prota_Y >= bordeSuperiorMapa){ //LOGICA PARA EVITAR QUE SE SALGA DEL MAPA
            prota_Y = prota_Y - 30; // VELOCIDAD
        } else if(t == ABAJO && prota_Y < bordeInferiorMapa){ //LOGICA PARA EVITAR QUE SE SALGA DEL MAPA
            prota_Y = prota_Y + 30; //VELOCIDAD
        }


         //movimiento nave enemiga Principal
        int aux = rand()%100;
        if(aux==0){
        dirEnemigoPrincipal = ARRIBA;
        }
        if(aux==1){
        dirEnemigoPrincipal = ABAJO;
        }
        if(dirEnemigoPrincipal == ARRIBA){
              if(enemigoPrincipal_Y>=bordeSuperiorMapa){//LOGICA PARA EVITAR QUE SE SALGA DEL MAPA
            enemigoPrincipal_Y = enemigoPrincipal_Y - 5; // Este NUMERO EQUIVALE A LA VELOCIDAD QUE QUIERES QUE SE MUEVA
            }
        } else if(dirEnemigoPrincipal == ABAJO){
               if(enemigoPrincipal_Y < bordeInferiorMapa){//LOGICA PARA EVITAR QUE SE SALGA DEL MAPA
            enemigoPrincipal_Y = enemigoPrincipal_Y + 5; // Este NUMERO EQUIVALE A LA VELOCIDAD QUE QUIERES QUE SE MUEVA
            }
        }

        //movimiento enemiga 3
        int aux2 = rand()%100;
        if(aux2==0){
        dirEnemigo2 = ARRIBA;
        }
        if(aux2==1){
        dirEnemigo2 = ABAJO;
        }
        if(dirEnemigo2 == ARRIBA){
              if(enemigo2_Y>=bordeSuperiorMapa){//LOGICA PARA EVITAR QUE SE SALGA DEL MAPA
            enemigo2_Y = enemigo2_Y-5; // Este NUMERO EQUIVALE A LA VELOCIDAD QUE QUIERES QUE SE MUEVA
            }
        } else if(dirEnemigo2 == ABAJO){
               if(enemigo2_Y<bordeInferiorMapa){ //LOGICA PARA EVITAR QUE SE SALGA DEL MAPA
            enemigo2_Y = enemigo2_Y+5; // Este NUMERO EQUIVALE A LA VELOCIDAD QUE QUIERES QUE SE MUEVA
            }
        }

        //movimiento enemiga 3
        int aux3 = rand()%100;
        if(aux3==0){
        dirEnemigo3 = ARRIBA;
        }
        if(aux3==1){
        dirEnemigo3 = ABAJO;
        }
        if(dirEnemigo3 == ARRIBA){
              if(enemigo3_Y>=bordeSuperiorMapa){ //LOGICA PARA EVITAR QUE SE SALGA DEL MAPA
            enemigo3_Y = enemigo3_Y-5; // Este NUMERO EQUIVALE A LA VELOCIDAD QUE QUIERES QUE SE MUEVA
            }
        } else if(dirEnemigo3 == ABAJO){
               if(enemigo3_Y<bordeInferiorMapa){ //LOGICA PARA EVITAR QUE SE SALGA DEL MAPA
            enemigo3_Y = enemigo3_Y+5; // Este NUMERO EQUIVALE A LA VELOCIDAD QUE QUIERES QUE SE MUEVA
            }
        }


        // Disparamos protaprotagoni
        if (t == ESPACIO && !balaProtaVolando) {
           disparar(prota_X,prota_Y,balaProta_X, balaProta_Y);
           balaProtaVolando = true;
           PlaySound("sonidos/disparo-prota-sound.WAV", NULL, SND_ASYNC);

        }
        //Logica de colision del de las balas del protagoninini
        if (balaProtaVolando) {
            moverBalaDerecha(balaProta_X);

            // chequeamos si hay choque con enemigo principal.
            if (hayColision(balaProta_X, balaProta_Y, enemigoPrincipal_X, enemigoPrincipal_Y)){
                botarEntidadDelMapa(enemigoPrincipal_X, enemigoPrincipal_Y);
                contadorEnemigosEliminados = contadorEnemigosEliminados + 1;
                contadorComboKill++;
                PlaySound("sonidos/any-nav-explosion.WAV", NULL, SND_ASYNC);

            }
            // chequeamos si hay choque con enemigo2.
            if (hayColision(balaProta_X, balaProta_Y, enemigo2_X, enemigo2_Y)){
                botarEntidadDelMapa(enemigo2_X, enemigo2_Y);
                contadorEnemigosEliminados = contadorEnemigosEliminados + 1;
                contadorComboKill ++;
                PlaySound("sonidos/any-nav-explosion.WAV", NULL, SND_ASYNC);


            }
             // chequeamos si hay choque con enemigo3.
            if (hayColision(balaProta_X, balaProta_Y, enemigo3_X, enemigo3_Y)){
                botarEntidadDelMapa(enemigo3_X, enemigo3_Y);
                contadorEnemigosEliminados = contadorEnemigosEliminados + 1;
                contadorComboKill ++;
                PlaySound("sonidos/any-nav-explosion.WAV", NULL, SND_ASYNC);


            }

            if (contadorComboKill >= 2) {
                esCartelComboActivo = true;
                tiempoMarcado = marcarTiempoActual(tiempoJuegoActual);
            }
            // Reciclaje: Si la bala llega al l�mite superior, desactiva la bandera.
            //Es decir, dejamos de dibujar.
            if (balaProta_X > 1000) {
                balaProtaVolando = false;
                contadorComboKill = 0; // Cuando la flecha se desactive. El contador de combo se reinicia
            }

        }

        /// Logica de disparo y colision del enemigo 1
        if(aux == 0 && !balaEnemigo1Volando){ //Disparo random Y la bala no esta en el mapa
            disparar(enemigoPrincipal_X,enemigoPrincipal_Y, balaEnemigo1_X, balaEnemigo1_Y);
            balaEnemigo1Volando = true;
        }

        if (balaEnemigo1Volando){
            moverBalaIzquierda(balaEnemigo1_X, nivelActual, "ENEMIGO_PRINCIPAL");
        }
        if (balaEnemigo1_X < bordeIzquierdoMapa) {
                balaEnemigo1Volando = false;
            }
        if (hayColision(balaEnemigo1_X, balaEnemigo1_Y, prota_X, prota_Y)){
                balaEnemigo1Volando = false;
                balaEnemigo1_Y = 2000;
                balaEnemigo1_X = 2000;
                contadorVidaProtagonista--;
                PlaySound("sonidos/any-nav-explosion.WAV", NULL, SND_ASYNC);

            }

         /// Logica de disparo y colision del enemigo 2
        if(aux2 == 0 && !balaEnemigo2Volando){ //Y la bala no esta en el mapa
            disparar(enemigo2_X,enemigo2_Y, balaEnemigo2_X, balaEnemigo2_Y);
            balaEnemigo2Volando = true;
        }
        if (balaEnemigo2Volando){
            moverBalaIzquierda(balaEnemigo2_X, nivelActual, "ENEMIGO");
        }
        if (balaEnemigo2_X < bordeIzquierdoMapa) {
                balaEnemigo2Volando = false;
            }
        if (hayColision(balaEnemigo2_X, balaEnemigo2_Y, prota_X, prota_Y)){
                balaEnemigo2Volando = false;
                balaEnemigo2_X = 5000;
                balaEnemigo2_Y = 5000;
                contadorVidaProtagonista--;
                PlaySound("sonidos/any-nav-explosion.WAV", NULL, SND_ASYNC);

            }

         /// Logica de disparo y colision del enemigo 3
        if(aux3 == 0 && !balaEnemigo3Volando){ //Y la bala no esta en el mapa
            disparar(enemigo3_X,enemigo2_Y, balaEnemigo3_X, balaEnemigo3_Y);
            balaEnemigo3Volando = true;
        }
        if (balaEnemigo3Volando){
            moverBalaIzquierda(balaEnemigo3_X, nivelActual, "ENEMIGO");
        }
        if (balaEnemigo3_X < bordeIzquierdoMapa) {
                balaEnemigo3Volando = false;
            }
        if (hayColision(balaEnemigo3_X, balaEnemigo3_Y, prota_X, prota_Y)){
                balaEnemigo3Volando = false;
                balaEnemigo3_X = 5000;
                balaEnemigo3_Y = 5000;
                contadorVidaProtagonista--;
                PlaySound("sonidos/any-nav-explosion.WAV", NULL, SND_ASYNC);
        }


        /// Condicionales de partida
        if (contadorEnemigosEliminados >=3 && nivelActual == 1){
            balaProtaVolando = false;  //Elinamos la bala en vuelo
            contadorEnemigosEliminados =0;  // reseteamos para que no se quede atascado

            nivelActual = 2;
            esCartelSegundoNivelActivo = true;
            tiempoMarcado = marcarTiempoActual(tiempoJuegoActual);


            prota_X = 100, prota_Y = 300;
            enemigoPrincipal_X = 900, enemigoPrincipal_Y = 10;
            enemigo2_X = 800, enemigo2_Y = 100;
            enemigo3_X = 700, enemigo3_Y =150;
        }
        //CARTEL DE BIENVENIDA AL SEGUNDO NIVEL//////////////////////////////////////
        if (esCartelSegundoNivelActivo){
            if(tiempoJuegoActual >= tiempoMarcado && tiempoJuegoActual <= tiempoMarcado + 2){  // los numeros aqui equivalen a los segundos que quieres que dure el cartel en pantalla
                esCartelSegundoNivelActivo;
            } else {
              esCartelSegundoNivelActivo = false;
              tiempoMarcado = 0; //Regresamos el auxiliar de marcado al estado inicial
            }
        }
/////////////////////////////////////////////

        if (contadorVidaProtagonista == 0){
            botarEntidadDelMapa(prota_X, prota_Y);
            espera(100);
            mensaje(" PERDISTE JJJAAJAJAJAJ");
            t = ESCAPE; // Cerramon la condicional del While
        }

//// CARTEL DE DOUBLE KILL///////////////////////////////////////////////////////////////
        if (esCartelComboActivo){
            if(tiempoJuegoActual >= tiempoMarcado && tiempoJuegoActual <= tiempoMarcado + 2){  // los numeros aqui equivalen a los segundos que quieres que dure el cartel en pantalla
                esCartelComboActivo;
            } else {
              esCartelComboActivo = false;
              tiempoMarcado = 0; //Regresamos el auxiliar de marcado al estado inicial
            }
        }









        borra(); // Limpiamos

        dibujarMensajeDoubleKill(sizeAncho, sizeAlto, esCartelComboActivo);
        dibujarCartelSegundoNivel(sizeAncho, sizeAlto, esCartelSegundoNivelActivo);


        dibujarEnemigoPrincipal(enemigoPrincipal_X,enemigoPrincipal_Y, nivelActual);
        dibujarBalaSi(balaEnemigo1Volando, balaEnemigo1_X, balaEnemigo1_Y, "ENEMIGO", nivelActual);

        dibujarEnemigo3(enemigo3_X, enemigo3_Y, nivelActual);
        dibujarBalaSi(balaEnemigo3Volando, balaEnemigo3_X, balaEnemigo3_Y, "ENEMIGO", nivelActual);

        dibujarEnemigo2(enemigo2_X, enemigo2_Y, nivelActual);
        dibujarBalaSi(balaEnemigo2Volando, balaEnemigo2_X, balaEnemigo2_Y, "ENEMIGO", nivelActual);

        dibujarProtagonista(prota_X,prota_Y, contadorVidaProtagonista);
         if(contadorVidaProtagonista ==3){
            dibujarCorazon(10, 50 + 550);
            dibujarCorazon(20 + 10, 50 + 550);
            dibujarCorazon(40 + 10, 50 + 550);
        } else if (contadorVidaProtagonista == 2){
            dibujarCorazon(10, 50 + 550);
            dibujarCorazon(20 + 10, 50 + 550);
        } else if (contadorVidaProtagonista == 1){
        dibujarCorazon(10, 50 + 550);
        }
        dibujarBalaSi(balaProtaVolando, balaProta_X, balaProta_Y,"PROTAGONISTA", nivelActual);
////////////////////////////LOGICA PARA TENER UN CONTEO DE SEGUNDOS EN EL JUEGO////////////////////
        contadorDeFrames++;
        if (contadorDeFrames >= FPS_IDEAL) {
            tiempoJuegoActual++; /// Almacena el contador de segundos que el juego esta corriendo (Comieza de 0 a ++)
            contadorDeFrames = 0;
        }
        ////////////////////////////////////////////////////////////////////////
//                std::cout << " " << contadorComboKill << std::endl;

//        std::cout << "Tiempo de Juego Actual: " << tiempoJuegoActual << std::endl;

        refresca();


        espera(10); // velocidad de recarga del while, Si no ponemos
        // se llamaria el while tan rapido que saturaria la memoria ram
        // (En programas mas pesados), acabo de probar que no xD.


        t = tecla();
    }
    return 0;
}
