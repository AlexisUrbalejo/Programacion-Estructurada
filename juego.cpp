#include <stdio.h>
#include <iostream>
#include <string.h>
#include<allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_native_dialog.h>
#include <allegro5/allegro_color.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_audio.h>
#include <allegro5/allegro_acodec.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <Windows.h>

#define X 800
#define Y 500
typedef struct {
    ALLEGRO_BITMAP* pregunta;
    int boton_correcto;
}Tpreguntas;

int nivel1(ALLEGRO_EVENT_QUEUE* event_queue, ALLEGRO_EVENT Evento, ALLEGRO_DISPLAY* ventana);
int generarNumeroAleatorio(int min, int max);
int pcorrecto(ALLEGRO_EVENT_QUEUE* event_queue, ALLEGRO_EVENT Evento, Tpreguntas preguntas[]);
int pincorrecto(ALLEGRO_EVENT_QUEUE* event_queue, ALLEGRO_EVENT Evento, Tpreguntas preguntas[]);
int nivel2(ALLEGRO_EVENT_QUEUE* event_queue, ALLEGRO_EVENT Evento, ALLEGRO_DISPLAY* ventana);
int nivel3(ALLEGRO_EVENT_QUEUE* event_queue, ALLEGRO_EVENT Evento, ALLEGRO_DISPLAY* ventana);
int ppuntuacion(ALLEGRO_EVENT_QUEUE* event_queue, ALLEGRO_EVENT Evento, int puntuacion, int nivel, ALLEGRO_DISPLAY* ventana);
int menu(ALLEGRO_DISPLAY* ventana);
int reglas(ALLEGRO_EVENT_QUEUE* event_queue, ALLEGRO_EVENT Evento, ALLEGRO_DISPLAY* ventana);
int jugar_menu(ALLEGRO_EVENT_QUEUE* event_queue, ALLEGRO_EVENT Evento, ALLEGRO_DISPLAY* ventana);
int opciones(ALLEGRO_EVENT_QUEUE* event_queue, ALLEGRO_EVENT Evento, ALLEGRO_DISPLAY* ventana);
int creditos(ALLEGRO_EVENT_QUEUE* event_queue, ALLEGRO_EVENT Evento);

bool apagar = false;

ALLEGRO_SAMPLE* music = NULL;
ALLEGRO_SAMPLE_INSTANCE* musicInstance = NULL;


int main()
{
    al_init();
    al_init_image_addon();
    al_install_mouse();
    al_install_audio();
    al_init_acodec_addon();

    if (apagar == true)
    {
        exit(0);
    }

    srand(time(NULL));
    ALLEGRO_DISPLAY* ventana = al_create_display(X, Y);


    int ancho = GetSystemMetrics(SM_CXSCREEN);
    int alto = GetSystemMetrics(SM_CYSCREEN);

    al_set_window_title(ventana, "Matematicas Navideñas");
    al_set_window_position(ventana, (ancho / 2) - (X / 2), (alto / 2) - (Y / 2));
    ALLEGRO_SAMPLE* music = NULL;


    al_reserve_samples(1);

    music = al_load_sample("/Users/Alexis/source/repos/Project17/musica.mp3");

    // Reproducir música en bucle


    al_play_sample(music, 0.1, 0.0, 1.0, ALLEGRO_PLAYMODE_LOOP, NULL);




    menu(ventana);




    return 0;
}
int menu(ALLEGRO_DISPLAY* ventana)
{
    ALLEGRO_EVENT_QUEUE* event_queue = al_create_event_queue();

    al_register_event_source(event_queue, al_get_mouse_event_source());


    ALLEGRO_BITMAP* menu = al_load_bitmap("/Users/Alexis/source/repos/Project17/pinicio.png");
    ALLEGRO_BITMAP* jugar = al_load_bitmap("/Users/Alexis/source/repos/Project17/pjugar.png");
    ALLEGRO_BITMAP* opciones_boton = al_load_bitmap("/Users/Alexis/source/repos/Project17/popciones1.png");
    ALLEGRO_BITMAP* reglas_boton = al_load_bitmap("/Users/Alexis/source/repos/Project17/preglas.png");
    ALLEGRO_BITMAP* salir = al_load_bitmap("/Users/Alexis/source/repos/Project17/psalir.png");





    int botones[] = { 0 };

    while (true)
    {
        ALLEGRO_EVENT Evento;
        al_wait_for_event(event_queue, &Evento);

        if (botones[0] == 0)
        {
            al_draw_bitmap(menu, 0, 0, 0);

        }
        else if (botones[0] == 1)
        {
            al_draw_bitmap(jugar, 0, 0, 0);

        }
        else if (botones[0] == 2)
        {
            al_draw_bitmap(opciones_boton, 0, 0, 0);

        }
        else if (botones[0] == 3)
        {
            al_draw_bitmap(reglas_boton, 0, 0, 0);

        }
        else if (botones[0] == 4)
        {
            al_draw_bitmap(salir, 0, 0, 0);

        }

        if (Evento.type == ALLEGRO_EVENT_MOUSE_AXES || Evento.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN)
        {
            int x = Evento.mouse.x;
            int y = Evento.mouse.y;

            if (x >= 317 && x <= 491 && y >= 245 && y <= 293)
            {
                botones[0] = 1;
                if (Evento.mouse.button & 1)
                {
                    printf("Click en jugar\n");
                    jugar_menu(event_queue, Evento, ventana);
                }
            }
            else
            {
                if (x >= 317 && x <= 491 && y >= 310 && y <= 368)
                {
                    botones[0] = 2;
                    if (Evento.mouse.button & 1)
                    {
                        opciones(event_queue, Evento, ventana);

                    }
                }
                else
                {
                    if (x >= 317 && x <= 491 && y >= 375 && y <= 434)
                    {
                        botones[0] = 3;
                        if (Evento.mouse.button & 1)
                        {
                            reglas(event_queue, Evento, ventana);

                        }
                    }
                    else
                    {
                        if (x >= 331 && x <= 480 && y >= 439 && y <= 486)
                        {
                            botones[0] = 4;
                            if (Evento.mouse.button & 1)
                            {

                                apagar = true;
                                main();
                            }
                        }
                        else
                        {
                            botones[0] = 0;
                        }
                    }
                }
            }

        }

        al_flip_display();
    }


}
int reglas(ALLEGRO_EVENT_QUEUE* event_queue, ALLEGRO_EVENT Evento, ALLEGRO_DISPLAY* ventana)
{
    int botones[] = { 0 };
    ALLEGRO_BITMAP* pantalla_reglas = al_load_bitmap("/Users/Alexis/source/repos/Project17/reglas.png");
    ALLEGRO_BITMAP* pantalla_regresar = al_load_bitmap("/Users/Alexis/source/repos/Project17/regresar.png");
    while (true)
    {
        ALLEGRO_EVENT Evento;
        al_wait_for_event(event_queue, &Evento);
        if (botones[0] == 0)
        {
            al_draw_bitmap(pantalla_reglas, 0, 0, 0);
        }
        else if (botones[0] == 1)
        {

            al_draw_bitmap(pantalla_regresar, 0, 0, 0);

        }
        if (Evento.type == ALLEGRO_EVENT_MOUSE_AXES || Evento.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN)
        {
            int x = Evento.mouse.x;
            int y = Evento.mouse.y;

            if (x >= 16 && x <= 170 && y >= 425 && y <= 474)
            {
                botones[0] = 1;
                if (Evento.mouse.button & 1)
                {
                    //printf("Click en regresar");
                    menu(ventana);
                }
            }
            else
            {
                botones[0] = 0;
            }
        }
        al_flip_display();
    }
    return 1;
}
int jugar_menu(ALLEGRO_EVENT_QUEUE* event_queue, ALLEGRO_EVENT Evento, ALLEGRO_DISPLAY* ventana)
{
    int botones[] = { 0 };
    ALLEGRO_BITMAP* pantalla_jugar = al_load_bitmap("/Users/Alexis/source/repos/Project17/pniveles.png");
    ALLEGRO_BITMAP* pantalla_regresar = al_load_bitmap("/Users/Alexis/source/repos/Project17/rniveles.png");
    ALLEGRO_BITMAP* hover_nivel1 = al_load_bitmap("/Users/Alexis/source/repos/Project17/hovniv1.png");
    ALLEGRO_BITMAP* hover_nivel2 = al_load_bitmap("/Users/Alexis/source/repos/Project17/hovniv2.png");
    ALLEGRO_BITMAP* hover_nivel3 = al_load_bitmap("/Users/Alexis/source/repos/Project17/hovniv3.png");

    while (true)
    {
        ALLEGRO_EVENT Evento;
        al_wait_for_event(event_queue, &Evento);
        if (botones[0] == 0)
        {
            al_draw_bitmap(pantalla_jugar, 0, 0, 0);
        }
        else if (botones[0] == 1)
        {

            al_draw_bitmap(pantalla_regresar, 0, 0, 0);

        }
        else if (botones[0] == 2)
        {
            al_draw_bitmap(hover_nivel1, 0, 0, 0);
        }
        else if (botones[0] == 3)
        {
            al_draw_bitmap(hover_nivel2, 0, 0, 0);
        }
        else if (botones[0] == 4)
        {
            al_draw_bitmap(hover_nivel3, 0, 0, 0);
        }
        if (Evento.type == ALLEGRO_EVENT_MOUSE_AXES || Evento.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN)
        {
            int x = Evento.mouse.x;
            int y = Evento.mouse.y;

            if (x >= 82 && x <= 213 && y >= 431 && y <= 469)
            {
                botones[0] = 1;
                if (Evento.mouse.button & 1)
                {
                    //printf("Click en regresar");
                    menu(ventana);
                }
            }
            else if (x >= 91 && x <= 255 && y >= 106 && y <= 255)
            {
                botones[0] = 2;
                if (Evento.mouse.button & 1)
                {
                    nivel1(event_queue, Evento, ventana);
                }

            }
            else if (x >= 315 && x <= 476 && y >= 106 && y <= 255)
            {
                botones[0] = 3;
                if (Evento.mouse.button & 1)
                {
                    nivel2(event_queue, Evento, ventana);
                }

            }
            else if (x >= 547 && x <= 706 && y >= 106 && y <= 255)
            {
                botones[0] = 4;
                if (Evento.mouse.button & 1)
                {
                    nivel3(event_queue, Evento, ventana);
                }
            }
            else
            {
                botones[0] = 0;
            }
        }
        al_flip_display();
    }
    return 1;
}
int opciones(ALLEGRO_EVENT_QUEUE* event_queue, ALLEGRO_EVENT Evento, ALLEGRO_DISPLAY* ventana)
{
    int botones[] = { 0 };
    ALLEGRO_BITMAP* pantalla_opciones = al_load_bitmap("/Users/Alexis/source/repos/Project17/opciones.png");
    ALLEGRO_BITMAP* hover_creditos = al_load_bitmap("/Users/Alexis/source/repos/Project17/hovcredop.png");
    ALLEGRO_BITMAP* hover_regresarop = al_load_bitmap("/Users/Alexis/source/repos/Project17/hovregop.png");




    while (true)
    {
        ALLEGRO_EVENT Evento;
        al_wait_for_event(event_queue, &Evento);

        if (botones[0] == 0)
        {
            al_draw_bitmap(pantalla_opciones, 0, 0, 0);


        }
        else if (botones[0] == 1)
        {

            al_draw_bitmap(hover_creditos, 0, 0, 0);

        }
        else if (botones[0] == 2)
        {

            al_draw_bitmap(hover_regresarop, 0, 0, 0);

        }




        if (Evento.type == ALLEGRO_EVENT_MOUSE_AXES || Evento.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN)
        {
            int x = Evento.mouse.x;
            int y = Evento.mouse.y;

            if (x >= 340 && x <= 434 && y >= 324 && y <= 367)
            {
                botones[0] = 1;
                if (Evento.mouse.button & 1)
                {
                    creditos(event_queue, Evento);

                }
            }
            else if (x >= 630 && x <= 760 && y >= 431 && y <= 465)
            {
                botones[0] = 2;
                if (Evento.mouse.button & 1)
                {
                    //printf("Click en regresar");
                    menu(ventana);
                }
            }

            else
            {
                botones[0] = 0;
            }
        }
        al_flip_display();
    }
    return 1;
}
int creditos(ALLEGRO_EVENT_QUEUE* event_queue, ALLEGRO_EVENT Evento)
{
    int botones[] = { 0 };
    ALLEGRO_BITMAP* pantalla_creditos = al_load_bitmap("/Users/Alexis/source/repos/Project17/pcreditos.png");
    ALLEGRO_BITMAP* hover_regresarcred = al_load_bitmap("/Users/Alexis/source/repos/Project17/hovregcred.png");

    while (true)
    {
        ALLEGRO_EVENT Evento;
        al_wait_for_event(event_queue, &Evento);

        if (botones[0] == 0)
        {

            al_draw_bitmap(pantalla_creditos, 0, 0, 0);

        }
        else if (botones[0] == 1)
        {

            al_draw_bitmap(hover_regresarcred, 0, 0, 0);

        }
        if (Evento.type == ALLEGRO_EVENT_MOUSE_AXES || Evento.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN)
        {
            int x = Evento.mouse.x;
            int y = Evento.mouse.y;

            if (x >= 630 && x <= 760 && y >= 431 && y <= 465)
            {
                botones[0] = 1;
                if (Evento.mouse.button & 1)
                {
                    return 1;

                }
            }
            else
            {
                botones[0] = 0;
            }
        }
        al_flip_display();
    }
    return 1;
}
int nivel1(ALLEGRO_EVENT_QUEUE* event_queue, ALLEGRO_EVENT Evento, ALLEGRO_DISPLAY* ventana)
{
    int nivel = 1;

    int puntuacion = 0;
    ALLEGRO_BITMAP* preguntas_imagen[10] = {
        al_load_bitmap("/Users/Alexis/source/repos/Project17/p1.png"),
        al_load_bitmap("/Users/Alexis/source/repos/Project17/p2.png"),
        al_load_bitmap("/Users/Alexis/source/repos/Project17/p3.png"),
        al_load_bitmap("/Users/Alexis/source/repos/Project17/p4.png"),
        al_load_bitmap("/Users/Alexis/source/repos/Project17/p5.png"),
        al_load_bitmap("/Users/Alexis/source/repos/Project17/p6.png"),
        al_load_bitmap("/Users/Alexis/source/repos/Project17/p7.png"),
        al_load_bitmap("/Users/Alexis/source/repos/Project17/p8.png"),
        al_load_bitmap("/Users/Alexis/source/repos/Project17/p9.png"),
        al_load_bitmap("/Users/Alexis/source/repos/Project17/p10.png")
    };

    Tpreguntas preguntas[5];
    int j = 0, m = 10;
    for (int i = 0; i < 5; i++)
    {


        do {

            j = generarNumeroAleatorio(0, 9);
        } while (m == j);
        m = j;
        preguntas[i].pregunta = preguntas_imagen[j];

        if (preguntas[i].pregunta == preguntas_imagen[0])
        {
            preguntas[i].boton_correcto = 1;
        }
        else if (preguntas[i].pregunta == preguntas_imagen[1])
        {
            preguntas[i].boton_correcto = 1;
        }
        else if (preguntas[i].pregunta == preguntas_imagen[2])
        {
            preguntas[i].boton_correcto = 2;
        }
        else if (preguntas[i].pregunta == preguntas_imagen[3])
        {
            preguntas[i].boton_correcto = 4;
        }
        else if (preguntas[i].pregunta == preguntas_imagen[4])
        {
            preguntas[i].boton_correcto = 1;
        }
        else if (preguntas[i].pregunta == preguntas_imagen[5])
        {
            preguntas[i].boton_correcto = 2;
        }
        else if (preguntas[i].pregunta == preguntas_imagen[6])
        {
            preguntas[i].boton_correcto = 2;
        }
        else if (preguntas[i].pregunta == preguntas_imagen[7])
        {
            preguntas[i].boton_correcto = 1;
        }
        else if (preguntas[i].pregunta == preguntas_imagen[8])
        {
            preguntas[i].boton_correcto = 4;
        }
        else if (preguntas[i].pregunta == preguntas_imagen[9])
        {
            preguntas[i].boton_correcto = 4;
        }

    }

    int boton = 0;

    for (int i = 0; i < 5; i++)
    {

        while (true)
        {
            ALLEGRO_EVENT Evento;
            al_wait_for_event(event_queue, &Evento);

            if (boton == 0)
            {
                al_draw_bitmap(preguntas[i].pregunta, 0, 0, 0);
            }





            if (Evento.type == ALLEGRO_EVENT_MOUSE_AXES || Evento.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN)
            {
                int x = Evento.mouse.x;
                int y = Evento.mouse.y;

                if (x >= 257 && x <= 350 && y >= 152 && y <= 242)
                {
                    boton = 1;
                    if (Evento.mouse.button & 1)
                    {
                        printf("Click en Opcion AAAAAAAA\n");
                        printf("%d", preguntas[i].boton_correcto);
                        if (boton == preguntas[i].boton_correcto)
                        {
                            pcorrecto(event_queue, Evento, preguntas);
                            puntuacion++;
                            break;
                        }
                        else
                        {
                            pincorrecto(event_queue, Evento, preguntas);
                            break;
                        }
                    }
                }
                else if (x >= 448 && x <= 541 && y >= 148 && y <= 238)
                {
                    boton = 2;
                    if (Evento.mouse.button & 1)
                    {
                        printf("click en Opcion 2\n");
                        if (boton == preguntas[i].boton_correcto)
                        {
                            pcorrecto(event_queue, Evento, preguntas);
                            puntuacion++;
                            break;
                        }
                        else
                        {
                            pincorrecto(event_queue, Evento, preguntas);
                            break;
                        }
                    }
                }
                else if (x >= 257 && x <= 350 && y >= 261 && y <= 349)
                {
                    boton = 3;
                    if (Evento.mouse.button & 1)
                    {
                        printf("click en Opcion 3\n");
                        if (boton == preguntas[i].boton_correcto)
                        {
                            pcorrecto(event_queue, Evento, preguntas);
                            puntuacion++;
                            break;
                        }
                        else
                        {
                            pincorrecto(event_queue, Evento, preguntas);
                            break;
                        }
                    }
                }
                else if (x >= 442 && x <= 536 && y >= 252 && y <= 342)
                {
                    boton = 4;
                    if (Evento.mouse.button & 1)
                    {
                        printf("click en Opcion 4\n");
                        if (boton == preguntas[i].boton_correcto)
                        {
                            pcorrecto(event_queue, Evento, preguntas);
                            puntuacion++;
                            break;
                        }
                        else
                        {
                            pincorrecto(event_queue, Evento, preguntas);
                            break;
                        }
                    }
                }
                else
                {
                    boton = 0;
                }
            }

            al_flip_display();


        }
    }
    printf("%d", puntuacion);
    ppuntuacion(event_queue, Evento, puntuacion, nivel, ventana);
    return 1;

}


int nivel2(ALLEGRO_EVENT_QUEUE* event_queue, ALLEGRO_EVENT Evento, ALLEGRO_DISPLAY* ventana)
{
    int nivel = 2;

    int puntuacion = 0;
    ALLEGRO_BITMAP* preguntas_imagen[10] = {
        al_load_bitmap("/Users/Alexis/source/repos/Project17/Nivel2/p1.png"),
        al_load_bitmap("/Users/Alexis/source/repos/Project17/Nivel2/p2.png"),
        al_load_bitmap("/Users/Alexis/source/repos/Project17/Nivel2/p3.png"),
        al_load_bitmap("/Users/Alexis/source/repos/Project17/Nivel2/p4.png"),
        al_load_bitmap("/Users/Alexis/source/repos/Project17/Nivel2/p5.png"),
        al_load_bitmap("/Users/Alexis/source/repos/Project17/Nivel2/p6.png"),
        al_load_bitmap("/Users/Alexis/source/repos/Project17/Nivel2/p7.png"),
        al_load_bitmap("/Users/Alexis/source/repos/Project17/Nivel2/p8.png"),
        al_load_bitmap("/Users/Alexis/source/repos/Project17/Nivel2/p9.png"),
        al_load_bitmap("/Users/Alexis/source/repos/Project17/Nivel2/p10.png")
    };

    Tpreguntas preguntas[5];
    int j = 0, m = 10;
    for (int i = 0; i < 5; i++)
    {


        do {

            j = generarNumeroAleatorio(0, 9);
        } while (m == j);
        m = j;
        preguntas[i].pregunta = preguntas_imagen[j];

        if (preguntas[i].pregunta == preguntas_imagen[0])
        {
            preguntas[i].boton_correcto = 3;
        }
        else if (preguntas[i].pregunta == preguntas_imagen[1])
        {
            preguntas[i].boton_correcto = 1;
        }
        else if (preguntas[i].pregunta == preguntas_imagen[2])
        {
            preguntas[i].boton_correcto = 1;
        }
        else if (preguntas[i].pregunta == preguntas_imagen[3])
        {
            preguntas[i].boton_correcto = 4;
        }
        else if (preguntas[i].pregunta == preguntas_imagen[4])
        {
            preguntas[i].boton_correcto = 2;
        }
        else if (preguntas[i].pregunta == preguntas_imagen[5])
        {
            preguntas[i].boton_correcto = 3;
        }
        else if (preguntas[i].pregunta == preguntas_imagen[6])
        {
            preguntas[i].boton_correcto = 2;
        }
        else if (preguntas[i].pregunta == preguntas_imagen[7])
        {
            preguntas[i].boton_correcto = 4;
        }
        else if (preguntas[i].pregunta == preguntas_imagen[8])
        {
            preguntas[i].boton_correcto = 1;
        }
        else if (preguntas[i].pregunta == preguntas_imagen[9])
        {
            preguntas[i].boton_correcto = 1;
        }

    }

    int boton = 0;

    for (int i = 0; i < 5; i++)
    {

        while (true)
        {
            ALLEGRO_EVENT Evento;
            al_wait_for_event(event_queue, &Evento);

            if (boton == 0)
            {
                al_draw_bitmap(preguntas[i].pregunta, 0, 0, 0);
            }


            if (Evento.type == ALLEGRO_EVENT_MOUSE_AXES || Evento.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN)
            {
                int x = Evento.mouse.x;
                int y = Evento.mouse.y;

                if (x >= 257 && x <= 350 && y >= 152 && y <= 242)
                {
                    boton = 1;
                    if (Evento.mouse.button & 1)
                    {
                        printf("Click en Opcion AAAAAAAA\n");
                        printf("%d", preguntas[i].boton_correcto);
                        if (boton == preguntas[i].boton_correcto)
                        {
                            pcorrecto(event_queue, Evento, preguntas);
                            puntuacion++;
                            break;
                        }
                        else
                        {
                            pincorrecto(event_queue, Evento, preguntas);
                            break;
                        }
                    }
                }
                else if (x >= 448 && x <= 541 && y >= 148 && y <= 238)
                {
                    boton = 2;
                    if (Evento.mouse.button & 1)
                    {
                        printf("click en Opcion 2\n");
                        if (boton == preguntas[i].boton_correcto)
                        {
                            pcorrecto(event_queue, Evento, preguntas);
                            puntuacion++;
                            break;
                        }
                        else
                        {
                            pincorrecto(event_queue, Evento, preguntas);
                            break;
                        }
                    }
                }
                else if (x >= 257 && x <= 350 && y >= 261 && y <= 349)
                {
                    boton = 3;
                    if (Evento.mouse.button & 1)
                    {
                        printf("click en Opcion 3\n");
                        if (boton == preguntas[i].boton_correcto)
                        {
                            pcorrecto(event_queue, Evento, preguntas);
                            puntuacion++;
                            break;
                        }
                        else
                        {
                            pincorrecto(event_queue, Evento, preguntas);
                            break;
                        }
                    }
                }
                else if (x >= 442 && x <= 536 && y >= 252 && y <= 342)
                {
                    boton = 4;
                    if (Evento.mouse.button & 1)
                    {
                        printf("click en Opcion 4\n");
                        if (boton == preguntas[i].boton_correcto)
                        {
                            pcorrecto(event_queue, Evento, preguntas);
                            puntuacion++;
                            break;
                        }
                        else
                        {
                            pincorrecto(event_queue, Evento, preguntas);
                            break;
                        }
                    }
                }
                else
                {
                    boton = 0;
                }
            }

            al_flip_display();


        }
    }
    printf("%d", puntuacion);
    ppuntuacion(event_queue, Evento, puntuacion, nivel, ventana);
    return 1;

}
int generarNumeroAleatorio(int min, int max)
{




    int numero = rand() % (max - min + 1) + min;

    return numero;
}
int pcorrecto(ALLEGRO_EVENT_QUEUE* event_queue, ALLEGRO_EVENT Evento, Tpreguntas preguntas[])
{
    ALLEGRO_BITMAP* correcto = al_load_bitmap("/Users/Alexis/source/repos/Project17/correcto.png");
    ALLEGRO_BITMAP* hovercorrecto = al_load_bitmap("/Users/Alexis/source/repos/Project17/hovercorrecto.png");
    int boton = 0;
    while (true)
    {
        ALLEGRO_EVENT Evento;
        al_wait_for_event(event_queue, &Evento);
        if (boton == 0)
        {
            al_draw_bitmap(correcto, 0, 0, 0);
        }
        else if (boton == 1)
        {

            al_draw_bitmap(hovercorrecto, 0, 0, 0);

        }
        if (Evento.type == ALLEGRO_EVENT_MOUSE_AXES || Evento.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN)
        {
            int x = Evento.mouse.x;
            int y = Evento.mouse.y;

            if (x >= 520 && x <= 788 && y >= 373 && y <= 437)
            {
                boton = 1;
                if (Evento.mouse.button & 1)
                {
                    printf("hola");
                    return 1;
                }
            }
            else
            {
                boton = 0;
            }

        }
        al_flip_display();
    }
    return 1;





}
int nivel3(ALLEGRO_EVENT_QUEUE* event_queue, ALLEGRO_EVENT Evento, ALLEGRO_DISPLAY* ventana)
{
    int nivel = 3;

    int puntuacion = 0;
    ALLEGRO_BITMAP* preguntas_imagen[10] = {
        al_load_bitmap("/Users/Alexis/source/repos/Project17/Nivel3/p1.png"),
        al_load_bitmap("/Users/Alexis/source/repos/Project17/Nivel3/p2.png"),
        al_load_bitmap("/Users/Alexis/source/repos/Project17/Nivel3/p3.png"),
        al_load_bitmap("/Users/Alexis/source/repos/Project17/Nivel3/p4.png"),
        al_load_bitmap("/Users/Alexis/source/repos/Project17/Nivel3/p5.png"),
        al_load_bitmap("/Users/Alexis/source/repos/Project17/Nivel3/p6.png"),
        al_load_bitmap("/Users/Alexis/source/repos/Project17/Nivel3/p7.png"),
        al_load_bitmap("/Users/Alexis/source/repos/Project17/Nivel3/p8.png"),
        al_load_bitmap("/Users/Alexis/source/repos/Project17/Nivel3/p9.png"),
        al_load_bitmap("/Users/Alexis/source/repos/Project17/Nivel3/p10.png")
    };

    Tpreguntas preguntas[5];
    int j = 0, m = 10;
    for (int i = 0; i < 5; i++)
    {


        do {

            j = generarNumeroAleatorio(0, 9);
        } while (m == j);
        m = j;
        preguntas[i].pregunta = preguntas_imagen[j];

        if (preguntas[i].pregunta == preguntas_imagen[0])
        {
            preguntas[i].boton_correcto = 1;
        }
        else if (preguntas[i].pregunta == preguntas_imagen[1])
        {
            preguntas[i].boton_correcto = 3;
        }
        else if (preguntas[i].pregunta == preguntas_imagen[2])
        {
            preguntas[i].boton_correcto = 4;
        }
        else if (preguntas[i].pregunta == preguntas_imagen[3])
        {
            preguntas[i].boton_correcto = 3;
        }
        else if (preguntas[i].pregunta == preguntas_imagen[4])
        {
            preguntas[i].boton_correcto = 1;
        }
        else if (preguntas[i].pregunta == preguntas_imagen[5])
        {
            preguntas[i].boton_correcto = 2;
        }
        else if (preguntas[i].pregunta == preguntas_imagen[6])
        {
            preguntas[i].boton_correcto = 4;
        }
        else if (preguntas[i].pregunta == preguntas_imagen[7])
        {
            preguntas[i].boton_correcto = 3;
        }
        else if (preguntas[i].pregunta == preguntas_imagen[8])
        {
            preguntas[i].boton_correcto = 1;
        }
        else if (preguntas[i].pregunta == preguntas_imagen[9])
        {
            preguntas[i].boton_correcto = 4;
        }

    }

    int boton = 0;

    for (int i = 0; i < 5; i++)
    {

        while (true)
        {
            ALLEGRO_EVENT Evento;
            al_wait_for_event(event_queue, &Evento);

            if (boton == 0)
            {
                al_draw_bitmap(preguntas[i].pregunta, 0, 0, 0);
            }





            if (Evento.type == ALLEGRO_EVENT_MOUSE_AXES || Evento.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN)
            {
                int x = Evento.mouse.x;
                int y = Evento.mouse.y;

                if (x >= 257 && x <= 350 && y >= 152 && y <= 242)
                {
                    boton = 1;
                    if (Evento.mouse.button & 1)
                    {
                        printf("Click en Opcion AAAAAAAA\n");
                        printf("%d", preguntas[i].boton_correcto);
                        if (boton == preguntas[i].boton_correcto)
                        {
                            pcorrecto(event_queue, Evento, preguntas);
                            puntuacion++;
                            break;
                        }
                        else
                        {
                            pincorrecto(event_queue, Evento, preguntas);
                            break;
                        }
                    }
                }
                else if (x >= 448 && x <= 541 && y >= 148 && y <= 238)
                {
                    boton = 2;
                    if (Evento.mouse.button & 1)
                    {
                        printf("click en Opcion 2\n");
                        if (boton == preguntas[i].boton_correcto)
                        {
                            pcorrecto(event_queue, Evento, preguntas);
                            puntuacion++;
                            break;
                        }
                        else
                        {
                            pincorrecto(event_queue, Evento, preguntas);
                            break;
                        }
                    }
                }
                else if (x >= 257 && x <= 350 && y >= 261 && y <= 349)
                {
                    boton = 3;
                    if (Evento.mouse.button & 1)
                    {
                        printf("click en Opcion 3\n");
                        if (boton == preguntas[i].boton_correcto)
                        {
                            pcorrecto(event_queue, Evento, preguntas);
                            puntuacion++;
                            break;
                        }
                        else
                        {
                            pincorrecto(event_queue, Evento, preguntas);
                            break;
                        }
                    }
                }
                else if (x >= 442 && x <= 536 && y >= 252 && y <= 342)
                {
                    boton = 4;
                    if (Evento.mouse.button & 1)
                    {
                        printf("click en Opcion 4\n");
                        if (boton == preguntas[i].boton_correcto)
                        {
                            pcorrecto(event_queue, Evento, preguntas);
                            puntuacion++;
                            break;
                        }
                        else
                        {
                            pincorrecto(event_queue, Evento, preguntas);
                            break;
                        }
                    }
                }
                else
                {
                    boton = 0;
                }
            }

            al_flip_display();


        }
    }
    printf("%d", puntuacion);
    ppuntuacion(event_queue, Evento, puntuacion, nivel, ventana);
    return 1;
}
int pincorrecto(ALLEGRO_EVENT_QUEUE* event_queue, ALLEGRO_EVENT Evento, Tpreguntas preguntas[])
{
    ALLEGRO_BITMAP* incorrecto = al_load_bitmap("/Users/Alexis/source/repos/Project17/incorrecto.png");
    ALLEGRO_BITMAP* hoverincorrecto = al_load_bitmap("/Users/Alexis/source/repos/Project17/hoverincorrecto.png");
    int boton = 0;
    while (true)
    {
        ALLEGRO_EVENT Evento;
        al_wait_for_event(event_queue, &Evento);
        if (boton == 0)
        {
            al_draw_bitmap(incorrecto, 0, 0, 0);
        }
        else if (boton == 1)
        {

            al_draw_bitmap(hoverincorrecto, 0, 0, 0);

        }
        if (Evento.type == ALLEGRO_EVENT_MOUSE_AXES || Evento.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN)
        {
            int x = Evento.mouse.x;
            int y = Evento.mouse.y;

            if (x >= 520 && x <= 788 && y >= 373 && y <= 437)
            {
                boton = 1;
                if (Evento.mouse.button & 1)
                {
                    printf("hola");
                    return 1;
                }
            }
            else
            {
                boton = 0;
            }

        }
        al_flip_display();
    }
    return 1;
}
int ppuntuacion(ALLEGRO_EVENT_QUEUE* event_queue, ALLEGRO_EVENT Evento, int puntuacion, int nivel, ALLEGRO_DISPLAY* ventana)
{
    al_init_font_addon();
    al_init_ttf_addon();
    ALLEGRO_FONT* font = al_load_font("fonts/Socake.ttf", 70, 0);

    int boton = 0;
    char puntuacionTexto[10];
    snprintf(puntuacionTexto, sizeof(puntuacionTexto), "%d/5", puntuacion);
    ALLEGRO_BITMAP* pganaste = al_load_bitmap("/Users/Alexis/source/repos/Project17/pganaste.png");
    ALLEGRO_BITMAP* pperdiste = al_load_bitmap("/Users/Alexis/source/repos/Project17/pperdiste.png");
    ALLEGRO_BITMAP* hoversignivel = al_load_bitmap("/Users/Alexis/source/repos/Project17/hoversignivelganaste.png");
    ALLEGRO_BITMAP* hovermenuganaste = al_load_bitmap("/Users/Alexis/source/repos/Project17/hovermenuganaste.png");
    ALLEGRO_BITMAP* hoverintentar = al_load_bitmap("/Users/Alexis/source/repos/Project17/hoverintentarperdiste.png");
    ALLEGRO_BITMAP* hovermenuperdiste = al_load_bitmap("/Users/Alexis/source/repos/Project17/hovermenuperdiste.png");
    while (true)
    {
        ALLEGRO_EVENT Evento;
        al_wait_for_event(event_queue, &Evento);

        if (boton == 0)
        {
            if (puntuacion >= 4)
            {
                al_draw_bitmap(pganaste, 0, 0, 0);
                al_draw_text(font, al_map_rgb(255, 255, 255), 360, 223, NULL, puntuacionTexto);

            }
            else
            {
                al_draw_bitmap(pperdiste, 0, 0, 0);
                al_draw_text(font, al_map_rgb(255, 255, 255), 360, 223, NULL, puntuacionTexto);
            }


        }

        if (Evento.type == ALLEGRO_EVENT_MOUSE_AXES || Evento.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN)
        {
            int x = Evento.mouse.x;
            int y = Evento.mouse.y;

            if (x >= 323 && x <= 476 && y >= 320 && y <= 387 && puntuacion >= 4)
            {
                boton = 1;
                al_draw_bitmap(hoversignivel, 0, 0, 0);
                al_draw_text(font, al_map_rgb(255, 255, 255), 360, 223, NULL, puntuacionTexto);

                if (Evento.mouse.button & 1)
                {
                    printf("Click siguiente nivel\n");
                    if (nivel == 1)
                    {
                        nivel2(event_queue, Evento, ventana);
                    }
                    else if (nivel == 2)
                    {
                        nivel3(event_queue, Evento, ventana);
                    }
                    else
                    {
                        jugar_menu(event_queue, Evento, ventana);
                    }

                }
            }
            else if ((x >= 332 && x <= 468 && y >= 415 && y <= 470) && puntuacion >= 4)
            {
                boton = 2;
                al_draw_bitmap(hovermenuganaste, 0, 0, 0);
                al_draw_text(font, al_map_rgb(255, 255, 255), 360, 223, NULL, puntuacionTexto);
                if (Evento.mouse.button & 1)
                {
                    printf("Click  menu\n");
                    jugar_menu(event_queue, Evento, ventana);
                }
            }
            else if (x >= 312 && x <= 484 && y >= 344 && y <= 413 && puntuacion < 4)
            {
                boton = 3;
                al_draw_bitmap(hoverintentar, 0, 0, 0);
                al_draw_text(font, al_map_rgb(255, 255, 255), 360, 223, NULL, puntuacionTexto);
                if (Evento.mouse.button & 1)
                {
                    printf("Click  volver a intentar\n");
                    switch (nivel) {
                    case 1:
                        nivel1(event_queue, Evento, ventana);
                        break;
                    case 2:
                        nivel2(event_queue, Evento, ventana);
                        break;
                    case 3:
                        nivel3(event_queue, Evento, ventana);
                    }

                }
            }
            else if (x >= 327 && x <= 473 && y >= 428 && y <= 486 && puntuacion < 4)
            {
                boton = 4;
                al_draw_bitmap(hovermenuperdiste, 0, 0, 0);
                al_draw_text(font, al_map_rgb(255, 255, 255), 360, 223, NULL, puntuacionTexto);
                if (Evento.mouse.button & 1)
                {
                    printf("Click  menu\n");
                    jugar_menu(event_queue, Evento, ventana);
                }
            }
            else
            {
                boton = 0;
            }
        }
        al_flip_display();
    }
    return 1;
}