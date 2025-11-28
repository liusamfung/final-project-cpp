#ifndef ENTIDADES_H
#define ENTIDADES_H

#include "miniwin.h"
#include <stdbool.h>

using namespace miniwin;

// ====================== PROTAGONISTA ==========================
void dibujarProtagonista(int x, int y, int contadorVidaProtagonista) {
    // ---------- ESTADO 3 VIDAS (sano) ----------
    if (contadorVidaProtagonista == 3) {
        // Cabeza
        color_rgb(150, 80, 50);
        rectangulo_lleno(15 + x, 10 + y, 40 + x, 25 + y);

        // Cabello
        color_rgb(0, 0, 0);
        rectangulo_lleno(13 + x, 10 + y, 42 + x, 15 + y);

        // Corona de oro
        color_rgb(255, 215, 0);
        rectangulo_lleno(15 + x, 8 + y, 40 + x, 10 + y);

        // Pluma
        color_rgb(255, 255, 255);
        rectangulo_lleno(26 + x, 0 + y, 29 + x, 8 + y);

        // Torso
        color_rgb(150, 80, 50);
        rectangulo_lleno(10 + x, 25 + y, 45 + x, 45 + y);

        // Pectoral de oro
        color_rgb(255, 215, 0);
        rectangulo_lleno(15 + x, 28 + y, 40 + x, 35 + y);

        // Brazaletes
        rectangulo_lleno(45 + x, 38 + y, 50 + x, 41 + y);
        rectangulo_lleno(5 + x, 38 + y, 10 + x, 41 + y);

        // Brazos y arco
        color_rgb(150, 80, 50);
        rectangulo_lleno(40 + x, 30 + y, 45 + x, 40 + y);   // brazo derecho
        rectangulo_lleno(50 + x, 30 + y, 65 + x, 35 + y);   // brazo izquierdo

        // Arco
        color_rgb(100, 50, 0);
        rectangulo_lleno(45 + x, 25 + y, 50 + x, 60 + y);

        // Cuerda
        color_rgb(200, 200, 200);
        linea(50 + x, 32 + y, 65 + x, 32 + y);

        // Falda
        color_rgb(150, 0, 0);
        rectangulo_lleno(10 + x, 45 + y, 45 + x, 50 + y);
        rectangulo_lleno(20 + x, 50 + y, 35 + x, 55 + y);

        // Piernas
        color_rgb(150, 80, 50);
        rectangulo_lleno(15 + x, 55 + y, 25 + x, 75 + y);
        rectangulo_lleno(30 + x, 55 + y, 40 + x, 75 + y);

        // Sandalias
        color_rgb(255, 215, 0);
        rectangulo_lleno(15 + x, 75 + y, 25 + x, 78 + y);
        rectangulo_lleno(30 + x, 75 + y, 40 + x, 78 + y);

        // Nombre
        color_rgb(255, 255, 255);
        texto(x - 25, y + 80, "Inca Atahualpa");
        return;
    }

    // ---------- ESTADO 2 VIDAS (herido leve) ----------
    if (contadorVidaProtagonista == 2) {
        // Cabeza
        color_rgb(150, 80, 50);
        rectangulo_lleno(15 + x, 10 + y, 40 + x, 25 + y);

        // Cabello
        color_rgb(0, 0, 0);
        rectangulo_lleno(13 + x, 10 + y, 42 + x, 15 + y);

        // Oro más opaco
        color_rgb(150, 110, 0);
        rectangulo_lleno(15 + x, 8 + y, 40 + x, 10 + y);

        // Pluma
        color_rgb(255, 255, 255);
        rectangulo_lleno(26 + x, 0 + y, 29 + x, 8 + y);

        // Torso
        color_rgb(170, 90, 60);
        rectangulo_lleno(10 + x, 25 + y, 45 + x, 45 + y);

        // Pectoral opaco
        color_rgb(150, 110, 0);
        rectangulo_lleno(15 + x, 28 + y, 40 + x, 35 + y);
        rectangulo_lleno(45 + x, 38 + y, 50 + x, 41 + y);
        rectangulo_lleno(5 + x, 38 + y, 10 + x, 41 + y);

        // Brazos y arco
        color_rgb(170, 90, 60);
        rectangulo_lleno(40 + x, 30 + y, 45 + x, 40 + y);
        rectangulo_lleno(50 + x, 30 + y, 65 + x, 35 + y);
        color_rgb(100, 50, 0);
        rectangulo_lleno(45 + x, 25 + y, 50 + x, 60 + y);
        color_rgb(200, 200, 200);
        linea(50 + x, 32 + y, 65 + x, 32 + y);

        // Falda y piernas
        color_rgb(150, 0, 0);
        rectangulo_lleno(10 + x, 45 + y, 45 + x, 50 + y);
        rectangulo_lleno(20 + x, 50 + y, 35 + x, 55 + y);
        color_rgb(170, 90, 60);
        rectangulo_lleno(15 + x, 55 + y, 25 + x, 75 + y);
        rectangulo_lleno(30 + x, 55 + y, 40 + x, 75 + y);

        // Sandalias opacas
        color_rgb(150, 110, 0);
        rectangulo_lleno(15 + x, 75 + y, 25 + x, 78 + y);
        rectangulo_lleno(30 + x, 75 + y, 40 + x, 78 + y);

        // Heridas
        color_rgb(255, 0, 0);
        rectangulo_lleno(40 + x, 30 + y, 45 + x, 33 + y);
        rectangulo_lleno(20 + x, 40 + y, 22 + x, 43 + y);
         // Nombre
        color_rgb(255, 255, 255);
        texto(x - 25, y + 80, "Inca Atahualpa");
        return;
    }

    // ---------- ESTADO 1 VIDA (muy herido) ----------
    if (contadorVidaProtagonista == 1) {
        // Cabeza
        color_rgb(120, 70, 40);
        rectangulo_lleno(15 + x, 10 + y, 40 + x, 25 + y);

        // Cabello
        color_rgb(0, 0, 0);
        rectangulo_lleno(13 + x, 10 + y, 42 + x, 15 + y);

        // Corona rota gris
        color_rgb(80, 80, 80);
        rectangulo_lleno(15 + x, 8 + y, 40 + x, 10 + y);

        // Pluma
        color_rgb(255, 255, 255);
        rectangulo_lleno(26 + x, 0 + y, 29 + x, 8 + y);

        // Torso
        color_rgb(120, 70, 40);
        rectangulo_lleno(10 + x, 25 + y, 45 + x, 45 + y);

        // Pectoral destruido
        color_rgb(80, 80, 80);
        rectangulo_lleno(15 + x, 28 + y, 40 + x, 35 + y);
        rectangulo_lleno(45 + x, 38 + y, 50 + x, 41 + y);
        rectangulo_lleno(5 + x, 38 + y, 10 + x, 41 + y);

        // Brazos: uno caído
        color_rgb(120, 70, 40);
        rectangulo_lleno(40 + x, 30 + y, 45 + x, 40 + y);
        rectangulo_lleno(50 + x, 40 + y, 65 + x, 45 + y);

        // Arco sin cuerda
        color_rgb(100, 50, 0);
        rectangulo_lleno(45 + x, 25 + y, 50 + x, 60 + y);

        // Falda y piernas
        color_rgb(150, 0, 0);
        rectangulo_lleno(10 + x, 45 + y, 45 + x, 50 + y);
        rectangulo_lleno(20 + x, 50 + y, 35 + x, 55 + y);

        color_rgb(120, 70, 40);
        rectangulo_lleno(15 + x, 55 + y, 25 + x, 75 + y);
        rectangulo_lleno(30 + x, 55 + y, 40 + x, 75 + y);

        // Sandalias rotas
        color_rgb(80, 80, 80);
        rectangulo_lleno(15 + x, 75 + y, 25 + x, 78 + y);
        rectangulo_lleno(30 + x, 75 + y, 40 + x, 78 + y);

        // Heridas
        color_rgb(200, 0, 0);
        rectangulo_lleno(20 + x, 30 + y, 35 + x, 38 + y);
        rectangulo_lleno(32 + x, 60 + y, 35 + x, 65 + y);
        rectangulo_lleno(35 + x, 15 + y, 38 + x, 18 + y);
         // Nombre
        color_rgb(255, 255, 255);
        texto(x - 25, y + 80, "Inca Atahualpa");
    }
}

// ====================== ENEMIGOS (SOLDADOS) ==========================

static void dibujarSoldadoBasico(int x, int y) {
    // Cuerpo
    color_rgb(100, 100, 100);
    rectangulo_lleno(10 + x, 15 + y, 35 + x, 40 + y);

    // Hombros
    color_rgb(120, 120, 120);
    rectangulo_lleno(35 + x, 18 + y, 40 + x, 25 + y);
    rectangulo_lleno(5 + x, 18 + y, 10 + x, 25 + y);

    // Casco
    color_rgb(120, 120, 120);
    rectangulo_lleno(12 + x, 5 + y, 33 + x, 15 + y);
    color_rgb(140, 140, 140);
    rectangulo_lleno(20 + x, 0 + y, 25 + x, 5 + y);

    // Brazos
    color_rgb(100, 100, 100);
    rectangulo_lleno(0 + x, 30 + y, 10 + x, 35 + y);
    rectangulo_lleno(30 + x, 30 + y, 35 + x, 40 + y);

    // Guanteletes
    color_rgb(130, 130, 130);
    rectangulo_lleno(0 + x, 35 + y, 10 + x, 38 + y);
    rectangulo_lleno(30 + x, 40 + y, 35 + x, 43 + y);

    // Arcabuz
    color_rgb(80, 40, 0);
    rectangulo_lleno(30 + x, 30 + y, 38 + x, 35 + y); // culata
    rectangulo_lleno(10 + x, 31 + y, 30 + x, 34 + y); // cuerpo
    color_rgb(50, 50, 50);
    rectangulo_lleno(0 + x, 32 + y, 10 + x, 33 + y);  // cañón

    // Piernas
    color_rgb(100, 100, 100);
    rectangulo_lleno(10 + x, 40 + y, 20 + x, 65 + y);
    rectangulo_lleno(25 + x, 40 + y, 35 + x, 65 + y);

    // Botas
    color_rgb(60, 30, 0);
    rectangulo_lleno(10 + x, 65 + y, 20 + x, 70 + y);
    rectangulo_lleno(25 + x, 65 + y, 35 + x, 70 + y);
}

static void dibujarSoldadoCapitan(int x, int y) {
    dibujarSoldadoBasico(x, y);

    // Detalles dorados
    color_rgb(255, 215, 0);
    rectangulo_lleno(10 + x, 15 + y, 35 + x, 18 + y);
    rectangulo_lleno(22 + x, 25 + y, 23 + x, 35 + y);

    // Cresta dorada
    rectangulo_lleno(20 + x, 0 + y, 25 + x, 5 + y);

    // Falda azul
    color_rgb(0, 0, 128);
    rectangulo_lleno(10 + x, 40 + y, 35 + x, 45 + y);
}

// Enemigo principal: soldado en niveles 1-2, barco en nivel 3
void dibujarEnemigoPrincipal(int x, int y, int nivelActual) {
    if (nivelActual >= 3) {
        // ====== BARCO JEFE FINAL ======
        const int ANCHO_BARCO = 260;
        const int ALTO_CASCO  = 60;

        // Casco principal
        color_rgb(90, 60, 30);
        rectangulo_lleno(x + 0, y + 70, x + ANCHO_BARCO, y + 70 + ALTO_CASCO);

        // Cubierta
        color_rgb(130, 85, 40);
        rectangulo_lleno(x + 15, y + 60, x + ANCHO_BARCO - 15, y + 70);

        // Proa escalonada
        color_rgb(80, 50, 25);
        rectangulo_lleno(x - 20, y + 80, x + 0,   y + 105);
        rectangulo_lleno(x - 10, y + 75, x + 0,   y + 95);

        // Castillo de popa
        color_rgb(110, 75, 35);
        rectangulo_lleno(x + ANCHO_BARCO - 70, y + 40,
                         x + ANCHO_BARCO - 15, y + 70);

        // Mástil central
        int x_mastil = x + ANCHO_BARCO / 2;
        color_rgb(70, 40, 20);
        rectangulo_lleno(x_mastil - 4, y + 20, x_mastil + 4, y + 70);

        // Vela principal
        color_rgb(245, 245, 230);
        rectangulo_lleno(x + 40, y + 25, x + ANCHO_BARCO - 40, y + 65);

        // Cruz roja
        color_rgb(200, 0, 0);
        rectangulo_lleno(x_mastil - 2, y + 25, x_mastil + 2, y + 65);
        rectangulo_lleno(x + 60, y + 42, x + ANCHO_BARCO - 60, y + 46);

        // Vela frontal
        color_rgb(245, 245, 230);
        rectangulo_lleno(x + 10, y + 35, x + 45, y + 60);
        color_rgb(200, 0, 0);
        rectangulo_lleno(x + 25, y + 35, x + 29, y + 60);
        rectangulo_lleno(x + 15, y + 46, x + 40, y + 50);

        // Vela trasera
        color_rgb(245, 245, 230);
        rectangulo_lleno(x + ANCHO_BARCO - 60, y + 30,
                         x + ANCHO_BARCO - 20, y + 55);
        color_rgb(200, 0, 0);
        rectangulo_lleno(x + ANCHO_BARCO - 42, y + 30,
                         x + ANCHO_BARCO - 38, y + 55);
        rectangulo_lleno(x + ANCHO_BARCO - 55, y + 41,
                         x + ANCHO_BARCO - 25, y + 45);

        // Cañones inferiores
        color_rgb(30, 30, 30);
        for (int i = 30; i <= ANCHO_BARCO - 60; i += 50) {
            rectangulo_lleno(x + i, y + 95, x + i + 25, y + 110);
        }

        // Ventanas superiores
        color_rgb(45, 45, 45);
        for (int i = 45; i <= ANCHO_BARCO - 75; i += 50) {
            rectangulo_lleno(x + i, y + 85, x + i + 15, y + 92);
        }

        // Bandera superior
        color_rgb(70, 40, 20);
        rectangulo_lleno(x_mastil + 3, y + 10, x_mastil + 6, y + 25);
        color_rgb(180, 0, 0);
        rectangulo_lleno(x_mastil + 6, y + 10, x_mastil + 50, y + 20);

        // Olas
        color_rgb(0, 60, 130);
        rectangulo_lleno(x - 30, y + 130, x + ANCHO_BARCO + 30, y + 140);
        color_rgb(0, 90, 180);
        rectangulo_lleno(x - 20, y + 140, x + ANCHO_BARCO + 20, y + 150);

        // Texto JEFE FINAL
        color_rgb(255, 255, 0);
        texto(x + 80, y + 155, "JEFE FINAL");
        return;
    }

    // Niveles 1 y 2: soldados
    if (nivelActual == 1) {
        dibujarSoldadoBasico(x, y);
    } else if (nivelActual == 2) {
        dibujarSoldadoCapitan(x, y);
    }
}

void dibujarEnemigo2(int x, int y, int nivelActual) {
    if (nivelActual == 1) {
        dibujarSoldadoBasico(x, y);
    } else if (nivelActual == 2) {
        dibujarSoldadoCapitan(x, y);
    }
}

void dibujarEnemigo3(int x, int y, int nivelActual) {
    if (nivelActual == 1) {
        dibujarSoldadoBasico(x, y);
    } else if (nivelActual == 2) {
        dibujarSoldadoCapitan(x, y);
    }
}

// ====================== UI: CORAZONES Y CARTELES =====================

void dibujarCorazon(int x, int y) {
    color_rgb(255, 0, 0);
    rectangulo_lleno(4 + x, 4 + y, 11 + x, 11 + y);
    rectangulo_lleno(6 + x, 11 + y, 9 + x, 14 + y);
    rectangulo_lleno(2 + x, 2 + y, 7 + x, 6 + y);
    rectangulo_lleno(8 + x, 2 + y, 13 + x, 6 + y);
}

void dibujarMensajeDoubleKill(int sizeAncho, int sizeAlto, bool esContadorActivo) {
    if (!esContadorActivo) return;

    int x_centro = sizeAncho / 2;
    int y_centro = sizeAlto / 2;

    color_rgb(20, 20, 20);
    rectangulo_lleno(x_centro - 100, y_centro - 275,
                     x_centro + 100, y_centro - 225);

    color_rgb(255, 215, 0);
    rectangulo(x_centro - 100, y_centro - 275,
               x_centro + 100, y_centro - 225);
    rectangulo(x_centro - 98, y_centro - 273,
               x_centro + 98, y_centro - 223);

    color_rgb(255, 255, 255);
    texto(x_centro - 60, y_centro - 255, "DOUBLE KILL!!!!!");
}

void dibujarCartelSegundoNivel(int sizeAncho, int sizeAlto,
                               bool esCartelSegundoNivelActivo) {
    if (!esCartelSegundoNivelActivo) return;

    int x_centro = sizeAncho / 2;
    int y_centro = sizeAlto / 2;

    int ancho_banner = 300;
    int alto_banner  = 150;

    int x1 = x_centro - ancho_banner / 2;
    int y1 = y_centro - alto_banner / 2;
    int x2 = x_centro + ancho_banner / 2;
    int y2 = y_centro + alto_banner / 2;

    color_rgb(10, 10, 30);
    rectangulo_lleno(x1, y1, x2, y2);

    color_rgb(20, 20, 50);
    rectangulo_lleno(x1 + 5, y1 + 5, x2 - 5, y2 - 5);

    color_rgb(255, 215, 0);
    rectangulo(x1, y1, x2, y2);
    rectangulo(x1 + 2, y1 + 2, x2 - 2, y2 - 2);

    color_rgb(255, 255, 255);
    texto(x_centro - 120, y_centro - 40, "NIVEL 2 DESBLOQUEADO!");
    color_rgb(200, 200, 255);
    texto(x_centro - 100, y_centro + 10, "Los enemigos se mueven mas rapido");
    color_rgb(200, 200, 255);
    texto(x_centro - 100, y_centro + 30, "Y tienen mejores armas!!!");
}

void dibujarCartelVictora(int sizeAncho, int sizeAlto,
                              bool esCartelVictoriaActivo) {
    if (!esCartelVictoriaActivo) return;

    int x_centro = sizeAncho / 2;
    int y_centro = sizeAlto / 2;

    int ancho_banner = 300;
    int alto_banner  = 150;

    int x1 = x_centro - ancho_banner / 2;
    int y1 = y_centro - alto_banner / 2;
    int x2 = x_centro + ancho_banner / 2;
    int y2 = y_centro + alto_banner / 2;

    color_rgb(20, 20, 60);
    rectangulo_lleno(x1, y1, x2, y2);

    color_rgb(255, 215, 0);
    rectangulo(x1, y1, x2, y2);

    color_rgb(255, 255, 255);
    texto(x_centro - 120, y_centro - 40, "FELICIDADES ATAHUALPA!");
    color_rgb(200, 200, 255);
    texto(x_centro - 140, y_centro + 10, "EVISTASTE QUE ROBARAN EL ORO!");
    color_rgb(200, 200, 255);
    texto(x_centro - 140, y_centro + 30, "GRACIAs A ESTE CAMBIO EN LA HISTORIA");
    color_rgb(255, 0, 0);
    texto(x_centro - 140, y_centro + 50, "SEREMOS PERU POTENCIA MUNDIAL 2026");
}
void dibujarCartelDerrota(int sizeAncho, int sizeAlto,
                              bool esCartelDerrotaActivo) {
    if (!esCartelDerrotaActivo) return;

    int x_centro = sizeAncho / 2;
    int y_centro = sizeAlto / 2;

    int ancho_banner = 300;
    int alto_banner  = 150;

    int x1 = x_centro - ancho_banner / 2;
    int y1 = y_centro - alto_banner / 2;
    int x2 = x_centro + ancho_banner / 2;
    int y2 = y_centro + alto_banner / 2;

    color_rgb(20, 20, 60);
    rectangulo_lleno(x1, y1, x2, y2);

    color_rgb(255, 215, 0);
    rectangulo(x1, y1, x2, y2);

    color_rgb(255, 255, 255);
    texto(x_centro - 120, y_centro - 40, "PERDISTE!");
    color_rgb(200, 200, 255);
    texto(x_centro - 140, y_centro + 10, "PIZARRO SE ROBARA EL ORO!");


}
void dibujarCartelLevel1(int sizeAncho, int sizeAlto,
                              bool esCartelLevel1Activo) {
    if (!esCartelLevel1Activo) return;

    int x_centro = sizeAncho / 2;
    int y_centro = sizeAlto / 2;

    int ancho_banner = 300;
    int alto_banner  = 150;

    int x1 = x_centro - ancho_banner / 2;
    int y1 = y_centro - alto_banner / 2;
    int x2 = x_centro + ancho_banner / 2;
    int y2 = y_centro + alto_banner / 2;

    color_rgb(20, 20, 60);
    rectangulo_lleno(x1, y1, x2, y2);

    color_rgb(255, 215, 0);
    rectangulo(x1, y1, x2, y2);

    color_rgb(255, 255, 255);
    texto(x_centro - 120, y_centro - 40, "LAS TROPAS DE SPAIN LLEGARON!");
    color_rgb(200, 200, 255);
    texto(x_centro - 140, y_centro + 10, "AL TAHUANTISUYO!");
    color_rgb(255, 0, 0);
    texto(x_centro - 140, y_centro + 50, "PROTEGE TU TERRITORIO");

}
void dibujarCartelTercerNivel(int sizeAncho, int sizeAlto,
                              bool esCartelTercerNivelActivo) {
    if (!esCartelTercerNivelActivo) return;

    int x_centro = sizeAncho / 2;
    int y_centro = sizeAlto / 2;

    int ancho_banner = 300;
    int alto_banner  = 150;

    int x1 = x_centro - ancho_banner / 2;
    int y1 = y_centro - alto_banner / 2;
    int x2 = x_centro + ancho_banner / 2;
    int y2 = y_centro + alto_banner / 2;

    color_rgb(20, 20, 60);
    rectangulo_lleno(x1, y1, x2, y2);

    color_rgb(255, 215, 0);
    rectangulo(x1, y1, x2, y2);

    color_rgb(255, 255, 255);
    texto(x_centro - 120, y_centro - 40, "NIVEL 3 DESBLOQUEADO!");
    color_rgb(200, 200, 255);
    texto(x_centro - 140, y_centro + 10, "HAS LLEGADO AL JEFE FINAL!");
    color_rgb(255, 0, 0);
    texto(x_centro - 140, y_centro + 30, "FRANCISCO PIZARRO SE ESTA ESCAPANDO");
}

void dibujarBackground(int sizeAncho, int sizeAlto, int nivelActual) {

    if (nivelActual == 0) {
        int x_centro = sizeAncho / 2;
        int y_centro = sizeAlto / 2;

        // =========================
        //  CIELO CON DEGRADADO
        // =========================
        int alturaCielo = (sizeAlto * 3) / 5; // 60% de la pantalla
        int bandasCielo = 8;

        for (int i = 0; i < bandasCielo; i++) {
            int y1 = (alturaCielo * i) / bandasCielo;
            int y2 = (alturaCielo * (i + 1)) / bandasCielo;

            int azul   = 60  + i * 12;  // va aclarando
            int rojo   = 10  + i * 4;
            int verde  = 10  + i * 6;

            color_rgb(rojo, verde, azul);
            rectangulo_lleno(0, y1, sizeAncho, y2);
        }

        // Estrellas
        color_rgb(240, 240, 240);
        for (int i = 0; i < 35; i++) {
            int sx = rand() % sizeAncho;
            int sy = rand() % (alturaCielo - 40) + 20;
            punto(sx, sy);
        }

        // =========================
        //  MAR POR BANDAS
        // =========================
        int yMarInicio = alturaCielo;
        int marAltura  = sizeAlto - yMarInicio;
        int bandasMar  = 6;

        for (int i = 0; i < bandasMar; i++) {
            int y1 = yMarInicio + (marAltura * i) / bandasMar;
            int y2 = yMarInicio + (marAltura * (i + 1)) / bandasMar;

            int azulBase = 110 + i * 15;
            color_rgb(0, 40 + i * 10, azulBase);
            rectangulo_lleno(0, y1, sizeAncho, y2);
        }

        // Olas con líneas
        color_rgb(200, 230, 255);
        for (int y = yMarInicio + 20; y < sizeAlto; y += 40) {
            for (int x = 0; x < sizeAncho; x += 25) {
                linea(x, y, x + 15, y);
            }
        }

        // =========================
        //  COSTA / MUELLE IZQUIERDA
        // =========================
        int xCosta1 = 0;
        int yCosta1 = yMarInicio + 40;
        int xCosta2 = sizeAncho / 4;
        int yCosta2 = sizeAlto;

        color_rgb(80, 50, 25);
        rectangulo_lleno(xCosta1, yCosta1, xCosta2, yCosta2);

        // Tablas del muelle
        color_rgb(110, 70, 35);
        for (int y = yCosta1 + 20; y < yCosta2; y += 30) {
            linea(xCosta1 + 10, y, xCosta2 - 10, y);
        }

        // =========================
        //  BANNER DEL TITULO
        // =========================
        int anchoBannerTitulo = sizeAncho - 200;
        int altoBannerTitulo  = 90;
        int xBanner1 = (sizeAncho - anchoBannerTitulo) / 2;
        int yBanner1 = 35;
        int xBanner2 = xBanner1 + anchoBannerTitulo;
        int yBanner2 = yBanner1 + altoBannerTitulo;

        // Fondo oscuro
        color_rgb(15, 15, 45);
        rectangulo_lleno(xBanner1, yBanner1, xBanner2, yBanner2);

        // Marco dorado doble
        color_rgb(255, 215, 0);
        rectangulo(xBanner1, yBanner1, xBanner2, yBanner2);
        rectangulo(xBanner1 + 3, yBanner1 + 3, xBanner2 - 3, yBanner2 - 3);

        // TÍTULO (UNA SOLA VEZ, SIN DOBLE)
        color_rgb(255, 255, 0);
        texto(x_centro - 240, yBanner1 + 28, "INCA VS ESPANOLES: BATALLA FINAL");

        // Subtitulo
        color_rgb(220, 220, 230);
        texto(x_centro - 210, yBanner1 + 55, "Defiende al imperio Inca del gran galeon invasor");

        // =========================
        //  MINI INCA A LA IZQUIERDA
        // =========================
        int x_inca = xCosta2 - 120;
        int y_inca = yMarInicio + 10;

        // Piernas
        color_rgb(150, 80, 50);
        rectangulo_lleno(x_inca + 15, y_inca + 35, x_inca + 22, y_inca + 55);
        rectangulo_lleno(x_inca + 28, y_inca + 35, x_inca + 35, y_inca + 55);
        color_rgb(255, 215, 0);
        rectangulo_lleno(x_inca + 15, y_inca + 55, x_inca + 22, y_inca + 58);
        rectangulo_lleno(x_inca + 28, y_inca + 55, x_inca + 35, y_inca + 58);

        // Torsos
        color_rgb(150, 0, 0);
        rectangulo_lleno(x_inca + 10, y_inca + 22, x_inca + 40, y_inca + 35);
        color_rgb(150, 80, 50);
        rectangulo_lleno(x_inca + 14, y_inca + 10, x_inca + 36, y_inca + 22);

        // Cabello + corona
        color_rgb(0, 0, 0);
        rectangulo_lleno(x_inca + 12, y_inca + 8, x_inca + 38, y_inca + 12);
        color_rgb(255, 215, 0);
        rectangulo_lleno(x_inca + 14, y_inca + 5, x_inca + 36, y_inca + 8);
        color_rgb(255, 255, 255);
        rectangulo_lleno(x_inca + 23, y_inca - 4, x_inca + 27, y_inca + 5);

        // Arco
        color_rgb(100, 50, 0);
        rectangulo_lleno(x_inca + 40, y_inca + 15, x_inca + 43, y_inca + 45);
        // Cuerda
        color_rgb(220, 220, 220);
        linea(x_inca + 40, y_inca + 17, x_inca + 40, y_inca + 43);

        // Texto debajo del inca
        color_rgb(255, 255, 0);
        texto(x_inca - 10, y_inca + 65, "INCA ATahualpa");

        // =========================
        //  MINI GALEON A LA DERECHA
        // =========================
        int ANCHO_BARCO = 260;
        int x_barco = sizeAncho - ANCHO_BARCO - 80;
        int y_barco = yMarInicio + marAltura / 2 - 60;

        // Casco
        color_rgb(90, 60, 30);
        rectangulo_lleno(x_barco, y_barco + 40, x_barco + ANCHO_BARCO, y_barco + 90);
        color_rgb(120, 80, 40);
        rectangulo_lleno(x_barco + 20, y_barco + 30, x_barco + ANCHO_BARCO - 20, y_barco + 40);

        // Mástil y vela
        int x_mastil = x_barco + ANCHO_BARCO / 2;
        color_rgb(70, 40, 20);
        rectangulo_lleno(x_mastil - 3, y_barco + 5, x_mastil + 3, y_barco + 40);

        color_rgb(245, 245, 230);
        rectangulo_lleno(x_barco + 45, y_barco + 8, x_barco + ANCHO_BARCO - 45, y_barco + 35);

        color_rgb(200, 0, 0);
        rectangulo_lleno(x_mastil - 2, y_barco + 8, x_mastil + 2, y_barco + 35);
        rectangulo_lleno(x_barco + 55, y_barco + 20, x_barco + ANCHO_BARCO - 55, y_barco + 24);

        // Pequeñas ventanas / canones
        color_rgb(30, 30, 30);
        for (int i = 35; i <= ANCHO_BARCO - 70; i += 60) {
            rectangulo_lleno(x_barco + i, y_barco + 60, x_barco + i + 20, y_barco + 72);
        }

        // Texto debajo del barco
        color_rgb(255, 255, 0);
        texto(x_barco + 40, y_barco + 95, "Galeon Espanol");

        // =========================
        //  PANEL DE CONTROLES
        // =========================
        int anchoPanelControles = 380;
        int altoPanelControles  = 210;
        int xPC1 = 60;
        int yPC1 = yMarInicio + 40;
        int xPC2 = xPC1 + anchoPanelControles;
        int yPC2 = yPC1 + altoPanelControles;

        // Fondo
        color_rgb(15, 20, 45);
        rectangulo_lleno(xPC1, yPC1, xPC2, yPC2);
        // Borde
        color_rgb(255, 215, 0);
        rectangulo(xPC1, yPC1, xPC2, yPC2);

        // Texto de controles
        color_rgb(255, 255, 255);
        texto(xPC1 + 20, yPC1 + 30, "CONTROLES:");
        texto(xPC1 + 20, yPC1 + 70, "FLECHA ARRIBA : Mover arriba");
        texto(xPC1 + 20, yPC1 + 100,"FLECHA ABAJO  : Mover abajo");
        texto(xPC1 + 20, yPC1 + 130,"ESPACIO       : Disparar flecha");

        // =========================
        //  BANNER "PRESIONA ESPACIO"
        //  (MOVIDO MÁS ABAJO PARA NO TAPAR EL BARCO)
        // =========================
        int anchoBannerMsg = 520;
        int altoBannerMsg  = 40;
        int xMsg1 = x_centro - anchoBannerMsg / 2;
        int yMsg1 = sizeAlto - 70;          // estaba más arriba, ahora va casi al fondo
        int xMsg2 = xMsg1 + anchoBannerMsg;
        int yMsg2 = yMsg1 + altoBannerMsg;

        // Fondo
        color_rgb(15, 15, 40);
        rectangulo_lleno(xMsg1, yMsg1, xMsg2, yMsg2);

        // Borde
        color_rgb(255, 215, 0);
        rectangulo(xMsg1, yMsg1, xMsg2, yMsg2);
        rectangulo(xMsg1 + 3, yMsg1 + 3, xMsg2 - 3, yMsg2 - 3);

        // Texto centrado
        color_rgb(255, 255, 0);
        texto(x_centro - 190, yMsg1 + 15, "PRESIONA ESPACIO PARA EMPEZAR");

    }

    if (nivelActual == 1){
                // --- CIELO ANDINO (de azul oscuro a azul claro) ---
    for(int i = 0; i < sizeAlto*0.20; i++){
        int shade = 15 + i / 3;
        color_rgb(0, shade, 80 + shade/3);
        rectangulo_lleno(0, i, sizeAncho, i+1);
    }

    // --- SUELO ---
    color_rgb(70, 40, 20);
    rectangulo_lleno(0, sizeAlto*0.20, sizeAncho, sizeAlto);


    // --- PUEBLO INCA: muros de piedra poligonal ---
    int baseY = sizeAlto*0.68;
    color_rgb(120, 90, 60);

    for(int x = 20; x < sizeAncho - 40; x += 40){
        rectangulo_lleno(x, baseY, x+35, baseY+30);

        // patrón de piedras
        color_rgb(90, 70, 45);
        rectangulo_lleno(x+5, baseY+5, x+15, baseY+15);
        rectangulo_lleno(x+18, baseY+10, x+30, baseY+22);
        rectangulo_lleno(x+10, baseY+20, x+22, baseY+28);

        color_rgb(120, 90, 60);
    }

    // --- ESTANDARTE INCA (tipo wiphala simplificada) ---
    int bx = sizeAncho*0.15;
    int by = sizeAlto*0.40;
    color_rgb(160, 160, 160);
    rectangulo_lleno(bx-3, by-20, bx, by+60); // palo

    int c = 12; // tamaño de cuadritos
    int colores[7][3] = {
        {255, 0, 0}, {255,128,0}, {255,255,0},
        {0,255,0}, {0,0,255}, {128,0,255}, {255,0,255}
    };

    for(int i = 0; i < 7; i++){
        color_rgb(colores[i][0], colores[i][1], colores[i][2]);
        rectangulo_lleno(bx, by + i*c, bx + c, by + (i+1)*c);
    }

    // --- BANDERA ESPAÑOLA ---
    int ex = sizeAncho*0.80;
    int ey = sizeAlto*0.42;

    color_rgb(180, 180, 180);
    rectangulo_lleno(ex-3, ey-20, ex, ey+60); // palo

    // roja - amarilla - roja
    color_rgb(200, 0, 0);
    rectangulo_lleno(ex, ey, ex+40, ey+10);

    color_rgb(255, 215, 0);
    rectangulo_lleno(ex, ey+10, ex+40, ey+20);

    color_rgb(200, 0, 0);
    rectangulo_lleno(ex, ey+20, ex+40, ey+30);

    }

    if(nivelActual == 2) {
          // --- CIELO NOCTURNO ---
    for(int i = 0; i < sizeAlto*0.2; i++){
        int shade = 5 + i / 5;      // degradado muy oscuro
        color_rgb(0, 0, 20 + shade);
        rectangulo_lleno(0, i, sizeAncho, i+1);
    }

    // --- ESTRELLAS (puntos aleatorios suaves) ---
    color_rgb(230, 230, 255);
    for(int i = 0; i < 120; i++){
        int x = rand() % sizeAncho;
        int y = rand() % (sizeAlto*10/2 - 10);
        punto(x, y);
    }

    // --- SUELO OSCURO ---
    color_rgb(30, 20, 10);
    rectangulo_lleno(0, sizeAlto*0.2, sizeAncho, sizeAlto);

    // --- SILUETAS DE GUERREROS (Incas a la izquierda, españoles a la derecha) ---
    // Incas
    color_rgb(60, 40, 25);
    for(int i = 0; i < 4; i++){
        int px = 40 + i*60;
        int py = sizeAlto*0.60;

        rectangulo_lleno(px, py, px+8, py+25);       // cuerpo
        circulo_lleno(px+4, py-5, 6);                // cabeza
        rectangulo_lleno(px-6, py+10, px+14, py+13); // brazos
    }

    // Españoles (más rectos)
    color_rgb(45, 35, 20);
    for(int i = 0; i < 4; i++){
        int px = sizeAncho - 50 - i*60;
        int py = sizeAlto*0.60;

        rectangulo_lleno(px, py, px+10, py+30);
        circulo_lleno(px+5, py-6, 6);
        rectangulo_lleno(px-5, py+12, px+15, py+15);
    }

    // --- ANTORCHAS INCAS (izquierda) ---
    for(int i = 0; i < 3; i++){
        int tx = 70 + i*90;
        int ty = sizeAlto*0.72;

        // palo
        color_rgb(90, 60, 35);
        rectangulo_lleno(tx, ty, tx+5, ty+20);

        // fuego
        color_rgb(255, 120, 0);
        circulo_lleno(tx+2, ty-4, 6);
        color_rgb(255, 200, 40);
        circulo_lleno(tx+2, ty-8, 4);
    }

    // --- ANTORCHAS ESPAÑOLAS (derecha) ---
    for(int i = 0; i < 3; i++){
        int tx = sizeAncho - (70 + i*90);
        int ty = sizeAlto*0.72;

        color_rgb(90, 60, 35);
        rectangulo_lleno(tx, ty, tx+5, ty+20);

        color_rgb(255, 100, 0);
        circulo_lleno(tx+2, ty-4, 6);
        color_rgb(255, 180, 40);
        circulo_lleno(tx+2, ty-8, 4);
    }

    // --- ESTANDARTE INCA ---
    int bx = sizeAncho * 0.18;
    int by = sizeAlto * 0.40;

    color_rgb(150,150,150);
    rectangulo_lleno(bx-2, by-15, bx+1, by+65);

    int c = 10;
    int colores[7][3] = {
        {255, 0, 0}, {255,128,0}, {255,255,0},
        {0,255,0}, {0,0,255}, {128,0,255}, {255,0,255}
    };

    for(int i = 0; i < 7; i++){
        color_rgb(colores[i][0], colores[i][1], colores[i][2]);
        rectangulo_lleno(bx+1, by + i*c, bx+1 + c, by + (i+1)*c);
    }

    // --- ESTANDARTE CASTELLANO ---
    int ex = sizeAncho * 0.82;
    int ey = sizeAlto * 0.40;

    color_rgb(150,150,150);
    rectangulo_lleno(ex-2, ey-15, ex+1, ey+65);

    // rojo - amarillo - rojo
    color_rgb(200, 0, 0);
    rectangulo_lleno(ex, ey, ex+35, ey+10);

    color_rgb(255, 215, 0);
    rectangulo_lleno(ex, ey+10, ex+35, ey+20);

    color_rgb(200, 0, 0);
    rectangulo_lleno(ex, ey+20, ex+35, ey+30);
    }

    if(nivelActual == 3) {

    // ============================
    //  ALTURA DEL CIELO / SUELO
    // ============================
    int Y_SUELO = sizeAlto * 0.20;  // 20% cielo, 80% suelo/mar


    // ============================
    //  CIELO (0 → Y_SUELO)
    // ============================
    for (int i = 0; i < Y_SUELO; i++) {
        int shade = 40 + i / 2;
        color_rgb(20, 40 + shade/4, 80 + shade/3);
        rectangulo_lleno(0, i, sizeAncho, i+1);
    }

    // --- ESTRELLAS FIJAS ---
    color_rgb(240,240,255);
    int estrellas[][2] = {
        {50,20}, {120,15}, {200,40}, {300,10}, {420,25},
        {500,5}, {580,30}, {620,18}, {700,35}, {750,12},
        {150,50}, {250,30}, {350,45}, {550,22}
    };
    int n_est = sizeof(estrellas)/sizeof(estrellas[0]);
    for(int i=0; i<n_est; i++){
        punto(estrellas[i][0], estrellas[i][1]);
    }

    // --- NUBES OSCURAS FIJAS ---
    color_rgb(50,50,70);
    rectangulo_lleno(200, 40, 350, 60);
    rectangulo_lleno(240, 30, 380, 50);
    rectangulo_lleno(100, 50, 180, 70);


    // ============================
    //  TIERRA – MAR
    // ============================

    int mitad = sizeAncho * 0.45; // izquierda tierra, derecha mar

    // --- TIERRA IZQUIERDA ---
    color_rgb(60, 40, 20);
    rectangulo_lleno(0, Y_SUELO, mitad, sizeAlto);

    // --- PIEDRAS FIJAS ---
    color_rgb(90,70,40);
    int piedras[][2] = {
        {30, Y_SUELO+40}, {60, Y_SUELO+80}, {120, Y_SUELO+20},
        {180, Y_SUELO+60}, {220, Y_SUELO+100}, {260, Y_SUELO+30},
        {300, Y_SUELO+90}, {340, Y_SUELO+50}, {380, Y_SUELO+110}
    };
    int n_piedras = sizeof(piedras)/sizeof(piedras[0]);
    for(int i=0; i<n_piedras; i++){
        rectangulo_lleno(piedras[i][0], piedras[i][1],
                         piedras[i][0]+3, piedras[i][1]+3);
    }


    // --- MAR ESTÁTICO EN CAPAS ---
    for(int fila = Y_SUELO; fila < sizeAlto; fila++){
        int factor = (fila - Y_SUELO);
        int blue = 120 + factor/4;
        if(blue > 210) blue = 210;

        int green = 50 + (factor/8);
        if(green > 120) green = 120;

        color_rgb(0, green, blue);
        rectangulo_lleno(mitad, fila, sizeAncho, fila+1);
    }

    // --- OLAS ESTÁTICAS ---
    color_rgb(180, 200, 255); // azul claro
    rectangulo_lleno(mitad + 40, sizeAlto*0.70, mitad + 80, sizeAlto*0.70 + 4);
    rectangulo_lleno(mitad + 120, sizeAlto*0.73, mitad + 160, sizeAlto*0.73 + 4);
    rectangulo_lleno(mitad + 220, sizeAlto*0.68, mitad + 260, sizeAlto*0.68 + 4);

    // espuma
    color_rgb(255,255,255);
    rectangulo_lleno(mitad + 40, sizeAlto*0.70 - 2, mitad + 80, sizeAlto*0.70 - 1);
    rectangulo_lleno(mitad + 120, sizeAlto*0.73 - 2, mitad + 160, sizeAlto*0.73 - 1);
    rectangulo_lleno(mitad + 220, sizeAlto*0.68 - 2, mitad + 260, sizeAlto*0.68 - 1);


    // --- ESTACAS INCAS ---
    for (int i = 0; i < 4; i++){
        int x = mitad - 10 - i*20;
        int y = sizeAlto*0.75;
        color_rgb(90, 60, 35);
        rectangulo_lleno(x, y, x+5, y+30);
    }


    // ============================
    //  ESTANDARTE INCA
    // ============================
    int bx = sizeAncho * 0.12;
    int by = sizeAlto * 0.42;

    color_rgb(150,150,150);
    rectangulo_lleno(bx-2, by-20, bx+1, by+70);

    int c = 10;
    int colores[7][3] = {
        {255, 0, 0}, {255,128,0}, {255,255,0},
        {0,255,0}, {0,0,255}, {128,0,255}, {255,0,255}
    };
    for(int i = 0; i < 7; i++){
        color_rgb(colores[i][0], colores[i][1], colores[i][2]);
        rectangulo_lleno(bx+1, by + i*c, bx+1 + c, by + (i+1)*c);
    }

    }
    if (nivelActual == 4) {
        borra();  // por si quieres que no se vea nada del frame anterior

        // ----- CIELO EN DEGRADADO (AMANECER ANDINO) -----
        int alturaCielo = sizeAlto * 65 / 100; // 65% de la altura
        for (int y = 0; y < alturaCielo; y++) {
            int r = 20 + y / 4;
            int g = 40 + y / 6;
            int b = 100 + y / 10;
            if (r > 255) r = 255;
            if (g > 255) g = 255;
            if (b > 255) b = 255;

            color_rgb(r, g, b);
            rectangulo_lleno(0, y, sizeAncho, y + 1);
        }

        // ----- SUELO / ANDENES -----
        int ySuelo = alturaCielo;
        color_rgb(90, 60, 30);
        rectangulo_lleno(0, ySuelo, sizeAncho, sizeAlto);

        // Plataforma tipo templo inca
        int anchoTemplo = 260;
        int altoTemplo  = 70;
        int xTemplo = sizeAncho / 2 - anchoTemplo / 2;
        int yTemplo = ySuelo - altoTemplo;

        color_rgb(140, 110, 70);
        rectangulo_lleno(xTemplo, yTemplo, xTemplo + anchoTemplo, yTemplo + altoTemplo);

        // escalones
        color_rgb(110, 85, 55);
        for (int i = 0; i < 4; i++) {
            int escalonY = yTemplo + i * 10;
            rectangulo_lleno(xTemplo - i * 10, escalonY,
                             xTemplo + anchoTemplo + i * 10, escalonY + 10);
        }

        // ----- SOL INCA A LA DERECHA -----
        int xSol = sizeAncho - 140;
        int ySol = 110;
        color_rgb(255, 215, 0);
        circulo_lleno(xSol, ySol, 35);

        // ----- PROTAGONISTA CELEBRANDO (3 VIDAS) -----
        int protaX = sizeAncho / 2 - 25;
        int protaY = yTemplo - 80;
        dibujarProtagonista(protaX, protaY, 3);

        // ----- BANNER PRINCIPAL CON MENSAJE -----
        int anchoBannerTitulo = sizeAncho - 200;
        int altoBannerTitulo  = 90;
        int xBanner1 = (sizeAncho - anchoBannerTitulo) / 2;
        int yBanner1 = 35;
        int xBanner2 = xBanner1 + anchoBannerTitulo;
        int yBanner2 = yBanner1 + altoBannerTitulo;

        // Fondo oscuro
        color_rgb(15, 15, 45);
        rectangulo_lleno(xBanner1, yBanner1, xBanner2, yBanner2);

        // Marco dorado doble
        color_rgb(255, 215, 0);
        rectangulo(xBanner1, yBanner1, xBanner2, yBanner2);
        rectangulo(xBanner1 + 3, yBanner1 + 3, xBanner2 - 3, yBanner2 - 3);

        // Textos
        color_rgb(255, 255, 255);
        texto(xBanner1 + 90, yBanner1 + 20, "¡VICTORIA EN EL TAHUANTINSUYO!");
        color_rgb(230, 230, 230);
        texto(xBanner1 + 20, yBanner1 + 55, "Protegiste la riqueza cultural del Peru.");
        texto(xBanner1 + 20, yBanner1 + 75, "Cusco permanecera libre del saqueo espanol.");

        // Mensaje inferior para salir
        color_rgb(255, 255, 255);
        texto(sizeAncho / 2 - 200, sizeAlto - 40,
              "Presiona ESC para cerrar el juego");
    }
}



// Barra de vida del jefe (vidaActual de 0 a vidaMaxima)
void dibujarBarraVidaJefe(int vidaActual, int vidaMaxima,
                          int x_barco, int y_barco) {
    if (vidaActual <= 0) return;

    const int ANCHO_BARCO      = 260;
    const int ANCHO_BARRA_MAX  = 200;
    const int ALTO_BARRA       = 10;

    int x_centro_barco = x_barco + ANCHO_BARCO / 2;
    int x1 = x_centro_barco - ANCHO_BARRA_MAX / 2;
    int y1 = y_barco - 25;
    int x2 = x_centro_barco + ANCHO_BARRA_MAX / 2;
    int y2 = y1 + ALTO_BARRA;

    // Fondo y marco
    color_rgb(0, 0, 0);
    rectangulo_lleno(x1 - 2, y1 - 2, x2 + 2, y2 + 2);
    color_rgb(255, 215, 0);
    rectangulo(x1 - 2, y1 - 2, x2 + 2, y2 + 2);

    float proporcion = (float)vidaActual / (float)vidaMaxima;
    int anchoVida = (int)(ANCHO_BARRA_MAX * proporcion);

    if (proporcion > 0.6f) {
        color_rgb(0, 200, 0);
    } else if (proporcion > 0.3f) {
        color_rgb(255, 200, 0);
    } else {
        color_rgb(255, 0, 0);
    }

    rectangulo_lleno(x1, y1, x1 + anchoVida, y2);
}
void dibujarPantallaFinal(int sizeAncho, int sizeAlto, bool esVictoria, bool esDerrota) {
    // Limpiar cualquier resto del frame anterior
    borra();

    // Resolver modo final (evitar superposicion)
    bool modoVictoria = false;
    bool modoDerrota  = false;

    if (esVictoria && !esDerrota) {
        modoVictoria = true;
    } else if (esDerrota && !esVictoria) {
        modoDerrota = true;
    } else if (esVictoria && esDerrota) {
        // Si por error llegan las dos en true, damos prioridad a victoria
        modoVictoria = true;
    } else {
        // Si ninguna llega en true, mostramos una pantalla neutra de derrota
        modoDerrota = true;
    }

    if (modoVictoria) {
        // =========================
        //  FONDO: AMANECER ANDINO
        // =========================
        int alturaCielo = (sizeAlto * 3) / 5; // 60% de la pantalla
        for (int y = 0; y < alturaCielo; y++) {
            int r = 30 + (150 * y) / alturaCielo;   // de morado oscuro a naranja
            int g = 40 + (110 * y) / alturaCielo;
            int b = 80 + (70  * y) / alturaCielo;
            color_rgb(r, g, b);
            rectangulo_lleno(0, y, sizeAncho, y + 1);
        }

        // Linea de montanias suaves
        int yMontania = alturaCielo - 20;
        color_rgb(60, 40, 60);
        rectangulo_lleno(0, yMontania, sizeAncho, yMontania + 25);

        // Suelo / andenes
        int ySuelo = alturaCielo + 40;
        color_rgb(90, 60, 30);
        rectangulo_lleno(0, ySuelo, sizeAncho, sizeAlto);

        // Plataforma tipo templo inca centrada
        int anchoTemplo = 260;
        int altoTemplo  = 70;
        int xTemplo = sizeAncho / 2 - anchoTemplo / 2;
        int yTemplo = ySuelo - altoTemplo - 10;

        color_rgb(150, 110, 70);
        rectangulo_lleno(xTemplo, yTemplo, xTemplo + anchoTemplo, yTemplo + altoTemplo);

        // Escalones
        color_rgb(120, 90, 50);
        for (int i = 0; i < 3; i++) {
            int escalonY = yTemplo + i * 10;
            rectangulo_lleno(xTemplo - i * 12, escalonY,
                             xTemplo + anchoTemplo + i * 12, escalonY + 10);
        }

        // Sol inca a la derecha
        int xSol = sizeAncho - 120;
        int ySol = 90;
        color_rgb(255, 215, 0);
        circulo_lleno(xSol, ySol, 35);

        // Protagonista celebrando sobre el templo
        int protaX = sizeAncho / 2 - 30;
        int protaY = yTemplo - 80;
        dibujarProtagonista(protaX, protaY, 3);

        // ---------------------------
        // Banner superior (titulo)
        // ---------------------------
        int margenHorizontal = 60;
        int bannerAncho = sizeAncho - 2 * margenHorizontal;
        int bx1 = margenHorizontal;
        int bx2 = bx1 + bannerAncho;
        int by1 = 25;
        int by2 = by1 + 70;

        color_rgb(10, 10, 40);
        rectangulo_lleno(bx1, by1, bx2, by2);
        color_rgb(255, 215, 0);
        rectangulo(bx1, by1, bx2, by2);
        rectangulo(bx1 + 3, by1 + 3, bx2 - 3, by2 - 3);

        color_rgb(255, 255, 255);
        texto(bx1 + 120, by1 + 25, "VICTORIA EN EL TAHUANTINSUYO!");

        // ---------------------------
        // Mensaje central
        // ---------------------------
        int msgAncho = sizeAncho - 320;
        int mx1 = (sizeAncho - msgAncho) / 2;
        int mx2 = mx1 + msgAncho;
        int my1 = sizeAlto / 2 - 50;
        int my2 = my1 + 80;

        color_rgb(12, 12, 40);
        rectangulo_lleno(mx1, my1, mx2, my2);
        color_rgb(255, 215, 0);
        rectangulo(mx1, my1, mx2, my2);
        rectangulo(mx1 + 3, my1 + 3, mx2 - 3, my2 - 3);

        color_rgb(230, 230, 230);
        texto(mx1 + 20, my1 + 25, "Protegiste la riqueza cultural del Peru.");
        texto(mx1 + 20, my1 + 45, "Cusco permanecera libre del saqueo espanol.");

    } else if (modoDerrota) {
        // =========================
        //  FONDO: ATARDECER OSCURO
        // =========================
        int alturaCielo = (sizeAlto * 3) / 5; // 60% de la pantalla
        for (int y = 0; y < alturaCielo; y++) {
            int r = 5  + (40 * y) / alturaCielo;   // azul muy oscuro
            int g = 0  + (15 * y) / alturaCielo;
            int b = 25 + (70 * y) / alturaCielo;
            color_rgb(r, g, b);
            rectangulo_lleno(0, y, sizeAncho, y + 1);
        }

        int yHorizonte = alturaCielo + 5;

        // Mar profundo
        color_rgb(5, 10, 35);
        rectangulo_lleno(0, yHorizonte, sizeAncho, sizeAlto);

        // Reflejo rojizo en el mar
        color_rgb(40, 0, 0);
        rectangulo_lleno(0, yHorizonte, sizeAncho, yHorizonte + 40);

        // ---------------------------
        // Barco espanol dominante
        // ---------------------------
        int anchoBarco = 320;
        int altoBarco  = 60;
        int xBarco = sizeAncho / 2 - anchoBarco / 2;
        int yBarco = yHorizonte - altoBarco + 20;

        // Casco
        color_rgb(25, 25, 45);
        rectangulo_lleno(xBarco, yBarco + 20, xBarco + anchoBarco, yBarco + 20 + altoBarco);

        // Cubierta
        color_rgb(45, 45, 70);
        rectangulo_lleno(xBarco + 40, yBarco + 5, xBarco + anchoBarco - 40, yBarco + 25);

        // Mastil principal
        color_rgb(120, 120, 140);
        rectangulo_lleno(xBarco + anchoBarco / 2 - 5, yBarco - 40,
                         xBarco + anchoBarco / 2 + 5, yBarco + 20);

        // Vela
        color_rgb(230, 230, 240);
        rectangulo_lleno(xBarco + anchoBarco / 2 + 5, yBarco - 35,
                         xBarco + anchoBarco / 2 + 90, yBarco + 10);

        // Cruz roja en la vela
        color_rgb(200, 0, 0);
        rectangulo_lleno(xBarco + anchoBarco / 2 + 45, yBarco - 35,
                         xBarco + anchoBarco / 2 + 50, yBarco + 10);
        rectangulo_lleno(xBarco + anchoBarco / 2 + 25, yBarco - 10,
                         xBarco + anchoBarco / 2 + 70, yBarco - 5);

        // ---------------------------
        // Banner superior (titulo)
        // ---------------------------
        int margenHorizontal = 60;
        int bannerAncho = sizeAncho - 2 * margenHorizontal;
        int bx1 = margenHorizontal;
        int bx2 = bx1 + bannerAncho;
        int by1 = 25;
        int by2 = by1 + 70;

        color_rgb(5, 0, 0);
        rectangulo_lleno(bx1, by1, bx2, by2);
        color_rgb(255, 0, 0);
        rectangulo(bx1, by1, bx2, by2);
        rectangulo(bx1 + 3, by1 + 3, bx2 - 3, by2 - 3);

        color_rgb(255, 255, 255);
        texto(bx1 + 180, by1 + 25, "PERDISTE...");

        // ---------------------------
        // Mensaje central
        // ---------------------------
        int msgAncho = sizeAncho - 320;
        int mx1 = (sizeAncho - msgAncho) / 2;
        int mx2 = mx1 + msgAncho;
        int my1 = sizeAlto / 2 - 50;
        int my2 = my1 + 80;

        color_rgb(10, 0, 0);
        rectangulo_lleno(mx1, my1, mx2, my2);
        color_rgb(255, 0, 0);
        rectangulo(mx1, my1, mx2, my2);
        rectangulo(mx1 + 3, my1 + 3, mx2 - 3, my2 - 3);

        color_rgb(230, 230, 230);
        texto(mx1 + 20, my1 + 25, "Pizarro se llevo el oro.");
        texto(mx1 + 20, my1 + 45, "Intenta de nuevo para cambiar la historia.");
    }

    // =========================
    //  CREDITOS COMUNES
    // =========================
    color_rgb(255, 255, 255);
    int yCred1 = sizeAlto - 80;
    int yCred2 = sizeAlto - 60;
    int yInstr = sizeAlto - 40;

    texto(sizeAncho / 2 - 70,  yCred1, "Gracias por jugar");
    texto(sizeAncho / 2 - 220, yCred2, "Autores: Marco Matos, Liu Fung, Valentino Calderon");
    texto(sizeAncho / 2 - 190, yInstr, "Presiona ESC para cerrar el juego");
}


#endif // ENTIDADES_H
