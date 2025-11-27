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
    texto(x_centro - 100, y_centro + 20, "¡NUEVOS DESAFÍOS ESPERAN!");
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
    texto(x_centro - 140, y_centro + 20, "¡HAS LLEGADO AL JEFE FINAL!");
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

#endif // ENTIDADES_H
