#include "miniwin.h"
#include <stdbool.h>   // 'bool' en C, aunque en C++ ya existe
#include <windows.h>   // PlaySound
#include <stdio.h>
#include <cstdlib>
#include <ctime>
#include <string>
#include "entidades.h"

using namespace miniwin;

void reproducirEfecto(const std::string& rutaArchivo) {
    // Solo SND_ASYNC. Esto interrumpe brevemente el loop de fondo,
    // pero el fondo debería reanudarse inmediatamente.
    PlaySound(rutaArchivo.c_str(), NULL, SND_ASYNC | SND_NODEFAULT);
}


// ==================== BALAS NORMALES (PROTA Y SOLDADOS) ====================

// Dibuja la flecha del protagonista y las balas de los enemigos normales
void dibujarBalaSi(bool en_vuelo,
                   int x_Bala,
                   int y_Bala,
                   const std::string &whatEntidad,
                   int nivelActual) {
    if (!en_vuelo) return;

    // Protagonista: flecha hacia la derecha
    if (whatEntidad == "PROTAGONISTA") {
        int x_Flecha = x_Bala;
        int y_Flecha = y_Bala;

        // Palo principal de la flecha
        color_rgb(139, 69, 19);
        rectangulo_lleno(
            x_Flecha + 10,
            y_Flecha + 23,
            x_Flecha + 40,
            y_Flecha + 27
        );

        // Punta de la flecha
        color_rgb(255, 242, 0);
        rectangulo_lleno(
            x_Flecha + 40,
            y_Flecha + 23,
            x_Flecha + 46,
            y_Flecha + 27
        );
        rectangulo_lleno(
            x_Flecha + 38,
            y_Flecha + 20,
            x_Flecha + 40,
            y_Flecha + 30
        );

        // Plumas traseras
        color_rgb(200, 200, 200);
        rectangulo_lleno(x_Flecha + 5, y_Flecha + 22,
                          x_Flecha + 8, y_Flecha + 23);
        rectangulo_lleno(x_Flecha + 5, y_Flecha + 27,
                          x_Flecha + 8, y_Flecha + 28);
        return;
    }

    // Enemigos normales
    if (whatEntidad == "ENEMIGO") {
        int x_b = x_Bala;
        int y_b = y_Bala;

        if (nivelActual == 1) {
            // Bala simple metálica
            color_rgb(120, 120, 120);
            rectangulo_lleno(x_b + 5, y_b + 8, x_b + 25, y_b + 12);

            color_rgb(150, 150, 150);
            rectangulo_lleno(x_b + 0, y_b + 9, x_b + 5, y_b + 11);
            rectangulo_lleno(x_b + 5, y_b + 7, x_b + 8, y_b + 13);

            color_rgb(180, 180, 180);
            punto(x_b + 15, y_b + 10);
            punto(x_b + 20, y_b + 10);
        } else if (nivelActual == 2) {
            // Bala con fuego detrás
            color_rgb(255, 255, 102);
            rectangulo_lleno(x_b + 25, y_b + 6, x_b + 35, y_b + 14);
            color_rgb(255, 140, 0);
            rectangulo_lleno(x_b + 25, y_b + 7, x_b + 30, y_b + 13);
            color_rgb(255, 0, 0);
            rectangulo_lleno(x_b + 25, y_b + 9, x_b + 28, y_b + 11);

            color_rgb(120, 120, 120);
            rectangulo_lleno(x_b + 5, y_b + 8, x_b + 25, y_b + 12);

            color_rgb(150, 150, 150);
            rectangulo_lleno(x_b + 0, y_b + 9, x_b + 5, y_b + 11);
            rectangulo_lleno(x_b + 5, y_b + 7, x_b + 8, y_b + 13);

            color_rgb(180, 180, 180);
            punto(x_b + 15, y_b + 10);
            punto(x_b + 20, y_b + 10);
        }
    }
}

// ==================== UTILIDADES GENERALES ====================

void botarEntidadDelMapa(int &x_entidad, int &y_entidad) {
    x_entidad = -5000;
    y_entidad = -1000;
}

void disparar(int x_entidad, int y_entidad, int &x_bala, int &y_bala) {
    x_bala = x_entidad;
    y_bala = y_entidad;
}

void moverBalaDerecha(int &x_bala) {
    x_bala = x_bala + 20;
}

void moverBalaIzquierda(int &x_bala, int nivelActual) {
    if (nivelActual == 1) {
        x_bala = x_bala - 8;
    } else if (nivelActual == 2) {
        x_bala = x_bala - 15;
    } else {
        x_bala = x_bala - 10;
    }
}

// Colisión simple usando una hitbox de 30x45 alrededor de la entidad
bool hayColision(int x_bala, int y_bala, int &x_entidad, int &y_entidad) {
    bool colision_x = (x_bala >= x_entidad - 30 && x_bala <= x_entidad + 30);
    bool colision_y = (y_bala >= y_entidad - 45 && y_bala <= y_entidad + 45);
    return colision_x && colision_y;
}

bool existeEntidadDentroMapa(int &x_entidad, int &y_entidad) {
    bool existeEn_x = (x_entidad >= 0 && x_entidad < 1000);
    bool existeEn_y = (y_entidad >= 0 && y_entidad < 650);
    return existeEn_x && existeEn_y;
}

int marcarTiempoActual(int tiempoJuegoActual) {
    return tiempoJuegoActual;
}

// ==================== BALAS DEL JEFE FINAL ====================

struct BalaJefe {
    bool activa;
    int x;
    int y;
    int vx;
    int vy;
    int tipoAtaque; // 1: cañón simple, 2: abanico, 3: mortero
};

const int MAX_BALAS_JEFE = 40;

void inicializarBalasJefe(BalaJefe balas[], int n) {
    for (int i = 0; i < n; ++i) {
        balas[i].activa = false;
    }
}

int buscarSlotLibreBalaJefe(BalaJefe balas[], int n) {
    for (int i = 0; i < n; ++i) {
        if (!balas[i].activa) return i;
    }
    return -1;
}

void dibujarBalaJefe(const BalaJefe &b) {
    if (!b.activa) return;

    int x = b.x;
    int y = b.y;

    // Núcleo de hierro
    color_rgb(50, 50, 50);
    rectangulo_lleno(x - 6, y - 6, x + 6, y + 6);

    color_rgb(20, 20, 20);
    rectangulo(x - 6, y - 6, x + 6, y + 6);

    // Fuego / humo según tipo
    if (b.tipoAtaque == 1) {
        // Cañón simple
        color_rgb(255, 200, 0);
        rectangulo_lleno(x + 6, y - 4, x + 18, y + 4);
        color_rgb(255, 120, 0);
        rectangulo_lleno(x + 18, y - 3, x + 24, y + 3);
        color_rgb(255, 255, 255);
        punto(x + 10, y);
        punto(x + 14, y - 1);
        punto(x + 14, y + 1);
    } else if (b.tipoAtaque == 2) {
        // Ráfaga en abanico
        color_rgb(255, 255, 120);
        rectangulo_lleno(x + 6, y - 5, x + 22, y + 5);
        color_rgb(255, 150, 0);
        rectangulo_lleno(x + 22, y - 4, x + 30, y + 4);
        color_rgb(255, 255, 255);
        punto(x + 12, y - 1);
        punto(x + 16, y + 1);
        punto(x + 20, y);
    } else if (b.tipoAtaque == 3) {
        // Mortero: más humo vertical
        color_rgb(180, 180, 180);
        rectangulo_lleno(x + 3, y - 10, x + 9, y);
        color_rgb(120, 120, 120);
        rectangulo_lleno(x + 6, y - 14, x + 12, y - 4);
        color_rgb(255, 200, 100);
        rectangulo_lleno(x - 4, y - 4, x + 4, y + 4);
    }
}

void lanzarAtaqueJefe(BalaJefe balas[],
                      int n,
                      int x_jefe,
                      int y_jefe,
                      int tipoAtaque) {
    if (tipoAtaque == 1) {
        // Un solo cañón frontal
        int idx = buscarSlotLibreBalaJefe(balas, n);
        if (idx == -1) return;

        balas[idx].activa = true;
        balas[idx].tipoAtaque = 1;
        balas[idx].x = x_jefe;
        balas[idx].y = y_jefe + 100;   // altura aprox. de cañones
        balas[idx].vx = -12;
        balas[idx].vy = 0;
    } else if (tipoAtaque == 2) {
        // Ráfaga en abanico: 3 balas
        for (int i = -1; i <= 1; ++i) {
            int idx = buscarSlotLibreBalaJefe(balas, n);
            if (idx == -1) return;

            balas[idx].activa = true;
            balas[idx].tipoAtaque = 2;
            balas[idx].x = x_jefe;
            balas[idx].y = y_jefe + 90;
            balas[idx].vx = -10;
            balas[idx].vy = i * 3; // una sube, una baja, una recta
        }
    } else if (tipoAtaque == 3) {
        // Lluvia de morteros: varios proyectiles diagonales
        for (int i = 0; i < 4; ++i) {
            int idx = buscarSlotLibreBalaJefe(balas, n);
            if (idx == -1) return;

            balas[idx].activa = true;
            balas[idx].tipoAtaque = 3;
            balas[idx].x = x_jefe - 50 - (i * 30);
            balas[idx].y = y_jefe - 30;
            balas[idx].vx = -6;
            balas[idx].vy = 3;
        }
    }
}

void moverBalasJefe(BalaJefe balas[], int n,
                    int bordeIzquierdoMapa,
                    int bordeInferiorMapa) {
    for (int i = 0; i < n; ++i) {
        if (!balas[i].activa) continue;

        balas[i].x += balas[i].vx;
        balas[i].y += balas[i].vy;

        if (balas[i].x < bordeIzquierdoMapa - 50 ||
            balas[i].y > bordeInferiorMapa + 50 ||
            balas[i].y < -50) {
            balas[i].activa = false;
        }
    }
}

void dibujarBalasJefe(BalaJefe balas[], int n) {
    for (int i = 0; i < n; ++i) {
        if (balas[i].activa) {
            dibujarBalaJefe(balas[i]);
        }
    }
}

// ==================== MAIN ====================

int main() {
    const int FPS_IDEAL = 65;
    int contadorDeFrames = 0;
    int tiempoJuegoActual = 0;

    bool esCartelSegundoNivelActivo = false;
    bool esCartelTercerNivelActivo  = false;
    bool esCartelComboActivo        = false;
    bool esCarteVictoriaActivo      = false;
    bool esCartelDerrotaActivo      = false;
    bool esCartelLevel1Activo       = true; // Cuando apenas comieze el juego, se lancge
    int tiempoMarcado = 0;

    int sizeAncho = 1000;
    int sizeAlto  = 650;
    vredimensiona(sizeAncho, sizeAlto);

    const int VIDA_JEFE_FINAL_MAX = 5;
    int vidaJefeFinal = VIDA_JEFE_FINAL_MAX;

    int bordeIzquierdoMapa  = 20;
    int bordeDerechoMapa    = 950;
    int bordeSuperiorMapa   = 150;
    int bordeInferiorMapa   = 550;

    int contadorEnemigosEliminados = 0;
    int contadorComboKill = 0;
    int puntaje = 0;

    int nivelActual = 0;
    //int nivelActual = 1;

    int prota_X = 100, prota_Y = 300;
    int balaProta_X = 0, balaProta_Y = 0;
    bool balaProtaVolando = false;
    int contadorVidaProtagonista = 3;

    int enemigoPrincipal_X = 900, enemigoPrincipal_Y = 200;
    int enemigo2_X = 800, enemigo2_Y = 100;
    int enemigo3_X = 700, enemigo3_Y = 150;

    int dirEnemigoPrincipal = ARRIBA;
    int dirEnemigo2 = ARRIBA;
    int dirEnemigo3 = ARRIBA;

    int balaEnemigo1_X = 0, balaEnemigo1_Y = 0;
    bool balaEnemigo1Volando = false;
    int balaEnemigo2_X = 0, balaEnemigo2_Y = 0;
    bool balaEnemigo2Volando = false;
    int balaEnemigo3_X = 0, balaEnemigo3_Y = 0;
    bool balaEnemigo3Volando = false;

    // Balas del jefe
    BalaJefe balasJefe[MAX_BALAS_JEFE];
    inicializarBalasJefe(balasJefe, MAX_BALAS_JEFE);

    std::srand((unsigned)std::time(nullptr));

    int t = tecla();

    mciSendString("open sonidos/background-sound-level1.WAV type mpegvideo alias background-level1", NULL, 0, 0); //Libreria de windos para reproducir sonido.
    mciSendString("open sonidos/background-sound-level2.WAV type mpegvideo alias background-level2", NULL, 0, 0); //Libreria de windos para reproducir sonido.
    mciSendString("open sonidos/background-sound-level3.WAV type mpegvideo alias background-level3", NULL, 0, 0); //Libreria de windos para reproducir sonido.

    mciSendString("open sonidos/lose-sound.WAV type mpegvideo alias lose-sound", NULL, 0, 0); //Libreria de windos para reproducir sonido.
    mciSendString("open sonidos/win-victory.WAV type mpegvideo alias win-victory", NULL, 0, 0); //Libreria de windos para reproducir sonido.

    mciSendString("open sonidos/hahaha.WAV type mpegvideo alias hahaha", NULL, 0, 0); //Libreria de windos para reproducir sonido.
    mciSendString("open sonidos/inca-dead.WAV type mpegvideo alias inca-dead", NULL, 0, 0); //Libreria de windos para reproducir sonido.


    mciSendString("open sonidos/round1-fight.WAV type mpegvideo alias round-one", NULL, 0, 0);
    mciSendString("open sonidos/round2-fight.WAV type mpegvideo alias round-two", NULL, 0, 0);
    mciSendString("open sonidos/finalround-fight.WAV type mpegvideo alias round-three", NULL, 0, 0);


    while (t != ESCAPE) {
            if (nivelActual == 0) {
        borra();
        dibujarBackground(sizeAncho, sizeAlto, nivelActual); // dibuja el nivel 0
        refresca();

        // Si el jugador presiona ESPACIO, empieza el juego real
        if (t == ESPACIO) {
            nivelActual = 1;   // pasamos al nivel 1

            // (opcional) Reinicio de variables si quieres empezar "limpio"
            prota_X = 100; prota_Y = 300;
            contadorEnemigosEliminados = 0;
            contadorVidaProtagonista   = 3;
            vidaJefeFinal              = VIDA_JEFE_FINAL_MAX;
        }

        espera(10);
        t = tecla();
        continue;
        }

        mciSendString("play round-one", NULL, 0, 0);  //no Repetir
        mciSendString("play background-level1 repeat notify", NULL, 0, 0); //repetir es sonido de fondo de lvl 1

        // ================= ENTRADA PROTAGONISTA =================
        if (t == ARRIBA && prota_Y >= bordeSuperiorMapa) {
            prota_Y -= 30;
        } else if (t == ABAJO && prota_Y < bordeInferiorMapa) {
            prota_Y += 30;
        }

        // ================= MOVIMIENTO ENEMIGOS =================
        int aux = std::rand() % 100;
        if (aux == 0) dirEnemigoPrincipal = ARRIBA;
        if (aux == 1) dirEnemigoPrincipal = ABAJO;

        if (dirEnemigoPrincipal == ARRIBA) {
            if (enemigoPrincipal_Y >= bordeSuperiorMapa) {
                enemigoPrincipal_Y -= 5;
            }
        } else if (dirEnemigoPrincipal == ABAJO) {
            if (enemigoPrincipal_Y < bordeInferiorMapa) {
                enemigoPrincipal_Y += 5;
            }
        }

        int aux2 = std::rand() % 100;
        if (aux2 == 0) dirEnemigo2 = ARRIBA;
        if (aux2 == 1) dirEnemigo2 = ABAJO;
        if (dirEnemigo2 == ARRIBA) {
            if (enemigo2_Y >= bordeSuperiorMapa) {
                enemigo2_Y -= 5;
            }
        } else if (dirEnemigo2 == ABAJO) {
            if (enemigo2_Y < bordeInferiorMapa) {
                enemigo2_Y += 5;
            }
        }

        int aux3 = std::rand() % 100;
        if (aux3 == 0) dirEnemigo3 = ARRIBA;
        if (aux3 == 1) dirEnemigo3 = ABAJO;
        if (dirEnemigo3 == ARRIBA) {
            if (enemigo3_Y >= bordeSuperiorMapa) {
                enemigo3_Y -= 5;
            }
        } else if (dirEnemigo3 == ABAJO) {
            if (enemigo3_Y < bordeInferiorMapa) {
                enemigo3_Y += 5;
            }
        }

        // ================= DISPARO PROTAGONISTA =================
        if (t == ESPACIO && !balaProtaVolando) {
            disparar(prota_X, prota_Y, balaProta_X, balaProta_Y);
            balaProtaVolando = true;
            PlaySound("sonidos/lance.WAV", NULL, SND_ASYNC);

        }

        // ================= LÓGICA BALA PROTAGONISTA =================
        if (balaProtaVolando) {
            moverBalaDerecha(balaProta_X);

            if (nivelActual < 3) {
                // Enemigos normales
                if (hayColision(balaProta_X, balaProta_Y,
                                enemigoPrincipal_X, enemigoPrincipal_Y)) {
                    botarEntidadDelMapa(enemigoPrincipal_X, enemigoPrincipal_Y);
                    contadorEnemigosEliminados++;
                    contadorComboKill++;
                    puntaje += 50;
                    reproducirEfecto("sonidos/espa-dead.WAV");
                }

                if (hayColision(balaProta_X, balaProta_Y,
                                enemigo2_X, enemigo2_Y)) {
                    botarEntidadDelMapa(enemigo2_X, enemigo2_Y);
                    contadorEnemigosEliminados++;
                    contadorComboKill++;
                    puntaje += 50;
                    reproducirEfecto("sonidos/espa-dead.WAV");
                }

                if (hayColision(balaProta_X, balaProta_Y,
                                enemigo3_X, enemigo3_Y)) {
                    botarEntidadDelMapa(enemigo3_X, enemigo3_Y);
                    contadorEnemigosEliminados++;
                    contadorComboKill++;
                    puntaje += 50;
                    reproducirEfecto("sonidos/espa-dead.WAV");
                }
            } else {
                // Nivel 3: colisión con el barco jefe
                int xCentroBarco = enemigoPrincipal_X + 130;
                int yCentroBarco = enemigoPrincipal_Y + 90;
                if (hayColision(balaProta_X, balaProta_Y,
                                xCentroBarco, yCentroBarco)) {
                    balaProtaVolando = false;
                    balaProta_X = 2000;

                    if (vidaJefeFinal > 0) {
                        vidaJefeFinal--;
                        reproducirEfecto("sonidos/damage-finalboss.WAV");
                    }
                    if (vidaJefeFinal <= 0) {
                        botarEntidadDelMapa(enemigoPrincipal_X, enemigoPrincipal_Y);
                        contadorEnemigosEliminados++;
                        contadorComboKill++;
                        puntaje += 200;
                        espera(100);
                        mciSendString("close background-level3", NULL, 0, 0);  //Paramos la musica del lvl 2
                        esCarteVictoriaActivo = true;
                        mciSendString("play win-victory repeat notify", NULL, 0, 0); //Empieza la musica lvl 3
                        mensaje("Autores: Marco Matos, Liu Fung, Valentino Calderon");
                        t = ESCAPE;
                    }
                }

                // Por si quedara algún soldado vivo
                if (hayColision(balaProta_X, balaProta_Y,
                                enemigo2_X, enemigo2_Y)) {
                    botarEntidadDelMapa(enemigo2_X, enemigo2_Y);
                    contadorEnemigosEliminados++;
                    contadorComboKill++;
                    reproducirEfecto("sonidos/espa-dead.WAV");
                }
                if (hayColision(balaProta_X, balaProta_Y,
                                enemigo3_X, enemigo3_Y)) {
                    botarEntidadDelMapa(enemigo3_X, enemigo3_Y);
                    contadorEnemigosEliminados++;
                    contadorComboKill++;
                    reproducirEfecto("sonidos/espa-dead.WAV");

                }
            }

            // Activar DOUBLE KILL
            if (contadorComboKill >= 2) {
                esCartelComboActivo = true;
                reproducirEfecto("sonidos/double-kill.WAV");
                tiempoMarcado = marcarTiempoActual(tiempoJuegoActual);
            }

            // Si se sale de la pantalla, apagamos bala y combo
            if (balaProta_X > sizeAncho) {
                balaProtaVolando = false;
                contadorComboKill = 0;
            }
        }

        // ================= DISPAROS ENEMIGOS NORMALES =================
        if (nivelActual <= 2) {
            // Enemigo 1
            if (aux == 0 && !balaEnemigo1Volando && existeEntidadDentroMapa(enemigoPrincipal_X, enemigoPrincipal_Y)) {
                disparar(enemigoPrincipal_X, enemigoPrincipal_Y,
                         balaEnemigo1_X, balaEnemigo1_Y);
                balaEnemigo1Volando = true;
                reproducirEfecto("sonidos/shootgun-espa.WAV");
            }
            if (balaEnemigo1Volando) {
                moverBalaIzquierda(balaEnemigo1_X, nivelActual);
                if (balaEnemigo1_X < bordeIzquierdoMapa) {
                    balaEnemigo1Volando = false;
                }
                if (hayColision(balaEnemigo1_X, balaEnemigo1_Y,
                                prota_X, prota_Y)) {
                    balaEnemigo1Volando = false;
                    balaEnemigo1_X = balaEnemigo1_Y = 2000;
                    contadorVidaProtagonista--;
                    reproducirEfecto("sonidos/inca-hurt.WAV");
                }
            }

            // Enemigo 2
            if (aux2 == 0 && !balaEnemigo2Volando && existeEntidadDentroMapa(enemigo2_X, enemigo3_Y)) {
                disparar(enemigo2_X, enemigo2_Y,
                         balaEnemigo2_X, balaEnemigo2_Y);
                reproducirEfecto("sonidos/shootgun-espa.WAV");
                balaEnemigo2Volando = true;

            }
            if (balaEnemigo2Volando) {
                moverBalaIzquierda(balaEnemigo2_X, nivelActual);
                if (balaEnemigo2_X < bordeIzquierdoMapa) {
                    balaEnemigo2Volando = false;
                }
                if (hayColision(balaEnemigo2_X, balaEnemigo2_Y,
                                prota_X, prota_Y)) {
                    balaEnemigo2Volando = false;
                    balaEnemigo2_X = balaEnemigo2_Y = 5000;
                    contadorVidaProtagonista--;
                    reproducirEfecto("sonidos/inca-hurt.WAV");
                }
            }

            // Enemigo 3
            if (aux3 == 0 && !balaEnemigo3Volando && existeEntidadDentroMapa(enemigo3_X, enemigo3_Y)) {
                disparar(enemigo3_X, enemigo3_Y,
                         balaEnemigo3_X, balaEnemigo3_Y);
                reproducirEfecto("sonidos/shootgun-espa.WAV");
                balaEnemigo3Volando = true;
            }
            if (balaEnemigo3Volando) {
                moverBalaIzquierda(balaEnemigo3_X, nivelActual);
                if (balaEnemigo3_X < bordeIzquierdoMapa) {
                    balaEnemigo3Volando = false;
                }
                if (hayColision(balaEnemigo3_X, balaEnemigo3_Y,
                                prota_X, prota_Y)) {
                    balaEnemigo3Volando = false;
                    balaEnemigo3_X = balaEnemigo3_Y = 5000;
                    contadorVidaProtagonista--;
                    reproducirEfecto("sonidos/inca-hurt.WAV");
                }
            }
        } else {
            // ================= ATAQUES DEL JEFE (NIVEL 3) =================
            int prob = std::rand() % 200;
            if (prob == 0) {
                lanzarAtaqueJefe(balasJefe, MAX_BALAS_JEFE,
                                 enemigoPrincipal_X, enemigoPrincipal_Y, 1); //Un solo canon
                                 reproducirEfecto("sonidos/basic-atack-finalboss.WAV");

            } else if (prob == 1) {
                lanzarAtaqueJefe(balasJefe, MAX_BALAS_JEFE,
                                 enemigoPrincipal_X, enemigoPrincipal_Y, 2); // 3 canon
                                 reproducirEfecto("sonidos/multi-canon-finalboss.WAV");
            } else if (prob == 2) {
                lanzarAtaqueJefe(balasJefe, MAX_BALAS_JEFE,
                                 enemigoPrincipal_X, enemigoPrincipal_Y, 3); // Lluvia de morteros: varios proyectiles diagonales
                                 reproducirEfecto("sonidos/special-atack-finalboss.WAV");
            }

            moverBalasJefe(balasJefe, MAX_BALAS_JEFE,
                           bordeIzquierdoMapa, bordeInferiorMapa);

            // Colisión balas jefe con protagonista
            for (int i = 0; i < MAX_BALAS_JEFE; ++i) {
                if (!balasJefe[i].activa) continue;
                if (hayColision(balasJefe[i].x, balasJefe[i].y,
                                prota_X, prota_Y)) {
                    balasJefe[i].activa = false;
                    contadorVidaProtagonista--;
                    reproducirEfecto("sonidos/inca-hurt.WAV");
                }
            }
        }

        // ================= CAMBIO DE NIVEL =================
        if (contadorEnemigosEliminados >= 3 && nivelActual == 1) {
            balaProtaVolando = false;
            contadorEnemigosEliminados = 0;

            nivelActual = 2;
            mciSendString("close background-level1", NULL, 0, 0);  //Paramos la musica del lvl 1
            esCartelSegundoNivelActivo = true;

            mciSendString("play round-two", NULL, 0, 0);  //no Repetir
            mciSendString("play background-level2 repeat notify", NULL, 0, 0); //Empieza la musica lvl 2

            tiempoMarcado = marcarTiempoActual(tiempoJuegoActual);

            prota_X = 100; prota_Y = 300;
            enemigoPrincipal_X = 900; enemigoPrincipal_Y = 10;
            enemigo2_X = 800; enemigo2_Y = 100;
            enemigo3_X = 700; enemigo3_Y = 150;
        }

        if (contadorEnemigosEliminados >= 3 && nivelActual == 2) {
            balaProtaVolando = false;
            contadorEnemigosEliminados = 0;
            mciSendString("close background-level2", NULL, 0, 0);  //Paramos la musica del lvl 2

            nivelActual = 3;
            mciSendString("play round-three", NULL, 0, 0);  //no Repetir
            mciSendString("play background-level3 repeat notify", NULL, 0, 0); //Empieza la musica lvl 3


            esCartelSegundoNivelActivo = false;
            esCartelTercerNivelActivo  = true;
            tiempoMarcado = marcarTiempoActual(tiempoJuegoActual);

            prota_X = 100;
            prota_Y = 300;

            // Posicionar barco a la derecha
            enemigoPrincipal_X = sizeAncho - 260 - 20;
            enemigoPrincipal_Y = 120;

            // Quitar soldados
            enemigo2_X = enemigo3_X = -5000;
            enemigo2_Y = enemigo3_Y = -1000;

            vidaJefeFinal = VIDA_JEFE_FINAL_MAX;
        }

        // ================= CARTEL DOUBLE KILL =================
        if (esCartelComboActivo) {
            if (!(tiempoJuegoActual >= tiempoMarcado &&
                  tiempoJuegoActual <= tiempoMarcado + 2)) {
                esCartelComboActivo = false;
                tiempoMarcado = 0;
                contadorComboKill = 0;
            }
        }

        // ================= CARTELES DE NIVELES =================
        if (esCartelSegundoNivelActivo) {
            if (!(tiempoJuegoActual >= tiempoMarcado &&
                  tiempoJuegoActual <= tiempoMarcado + 8)) {
                esCartelSegundoNivelActivo = false;
                tiempoMarcado = 0;
            }
        }

        if (esCartelTercerNivelActivo) {
            if (!(tiempoJuegoActual >= tiempoMarcado &&
                  tiempoJuegoActual <= tiempoMarcado + 8)) {
                esCartelTercerNivelActivo = false;
                tiempoMarcado = 0;
            }
        }
        if (esCartelLevel1Activo) {
            if (tiempoJuegoActual == 8) {
                esCartelLevel1Activo = false;
            }
        }

        // ================= GAME OVER =================
        if (contadorVidaProtagonista <= 0) {
            if(nivelActual ==3 ){
                mciSendString("close background-level3", NULL, 0, 0);  //Paramos la musica del lvl 2
                mciSendString("play lose-sound repeat notify", NULL, 0, 0); //Empieza musica de perdida
                mciSendString("play hahaha repeat", NULL, 0, 0);  //no Repetir BURLA POR  CASI LOGRARLO

            }
            if (nivelActual ==2 || nivelActual ==1){
                mciSendString("close background-level1", NULL, 0, 0);  //Paramos la musica del lvl 2
                mciSendString("close background-level2", NULL, 0, 0);  //Paramos la musica del lvl 2

                mciSendString("play lose-sound repeat notify", NULL, 0, 0); //Empieza musica de perdida
                mciSendString("play inca-dead", NULL, 0, 0);  //no Repetir
            }
            esCartelDerrotaActivo = true;
            botarEntidadDelMapa(prota_X, prota_Y);
            espera(1000);
            t = ESCAPE;
        }

        // ================= DIBUJO EN PANTALLA =================
        borra();
        dibujarBackground(sizeAncho,sizeAlto, nivelActual);
        dibujarMensajeDoubleKill(sizeAncho, sizeAlto, esCartelComboActivo);
        dibujarCartelLevel1(sizeAncho, sizeAlto, esCartelLevel1Activo);
        dibujarCartelSegundoNivel(sizeAncho, sizeAlto, esCartelSegundoNivelActivo);
        dibujarCartelTercerNivel(sizeAncho, sizeAlto, esCartelTercerNivelActivo);

        dibujarCartelVictora(sizeAncho,sizeAlto, esCarteVictoriaActivo);
        dibujarCartelDerrota(sizeAncho, sizeAlto, esCartelDerrotaActivo);

        dibujarEnemigoPrincipal(enemigoPrincipal_X, enemigoPrincipal_Y, nivelActual);
        dibujarEnemigo2(enemigo2_X, enemigo2_Y, nivelActual);
        dibujarEnemigo3(enemigo3_X, enemigo3_Y, nivelActual);

        if (nivelActual == 3 && vidaJefeFinal > 0) {
            dibujarBarraVidaJefe(vidaJefeFinal, VIDA_JEFE_FINAL_MAX,
                                 enemigoPrincipal_X, enemigoPrincipal_Y);
        }

        // Balas enemigos normales
        dibujarBalaSi(balaEnemigo1Volando, balaEnemigo1_X, balaEnemigo1_Y,
                      "ENEMIGO", nivelActual);
        dibujarBalaSi(balaEnemigo2Volando, balaEnemigo2_X, balaEnemigo2_Y,
                      "ENEMIGO", nivelActual);
        dibujarBalaSi(balaEnemigo3Volando, balaEnemigo3_X, balaEnemigo3_Y,
                      "ENEMIGO", nivelActual);
        std::cout << "valor: " << tiempoJuegoActual << std::endl;
        // Balas del jefe
        dibujarBalasJefe(balasJefe, MAX_BALAS_JEFE);

        // Protagonista y vidas
        dibujarProtagonista(prota_X, prota_Y, contadorVidaProtagonista);

        if (contadorVidaProtagonista >= 1) dibujarCorazon(10, 600);
        if (contadorVidaProtagonista >= 2) dibujarCorazon(30, 600);
        if (contadorVidaProtagonista >= 3) dibujarCorazon(50, 600);

        // Texto de puntaje
        {
            std::string textoPuntaje = "Puntos: " + std::to_string(puntaje);
            color_rgb(255, 255, 255);
            texto(20, 20, textoPuntaje.c_str());
        }

        // Bala del protagonista
        dibujarBalaSi(balaProtaVolando, balaProta_X, balaProta_Y,
                      "PROTAGONISTA", nivelActual);

        // ================= CONTROL DEL "RELOJ" =================
        contadorDeFrames++;
        if (contadorDeFrames >= FPS_IDEAL) {
            tiempoJuegoActual++;
            contadorDeFrames = 0;
        }

        refresca();
        espera(10);
        t = tecla();
    }

    if (esCarteVictoriaActivo || esCartelDerrotaActivo) {
    // Nueva pantalla final unificada
    dibujarPantallaFinal(sizeAncho, sizeAlto,
                         esCarteVictoriaActivo,
                         esCartelDerrotaActivo);

    refresca();

    // Mantener la pantalla final hasta que el jugador presione ESC
    int teclaFinal = 0;
    while (teclaFinal != ESCAPE) {
        espera(10);
        teclaFinal = tecla();
    }
}


    return 0;
}
