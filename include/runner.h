/*
** EPITECH PROJECT, 2020
** runner.h
** File description:
** runner header
*/

#ifndef RUNNER_H_
#define RUNNER_H_

#include <SFML/Audio.h>
#include <SFML/Graphics.h>
#include <SFML/Network.h>
#include <SFML/Window.h>
#include <SFML/System.h>
#include <stdbool.h>

#define BACKGROUND_index 0
#define BACKGROUND2_index 1
#define GROUND_index 2
#define GROUND2_index 3
#define PLAYER_index 4

#define NAME 0
#define PLAY 1
#define EXIT 2
#define SETTING 3
#define SOUND 5
#define FPS 6
#define NBR 7
#define PAUSE 9
#define UNPAUSE 10
#define PAUSE_SPRITE 11
#define PAUSE_SOUND 12

typedef struct game_object game_object;
typedef struct score score_t;
typedef enum type TYPE;
typedef struct menu_object menu_object;

enum type {OBSTACLE, PERSO, BACKGROUND, GROUND, BLOCK, BUTTON};

struct menu_object
{
    sfSprite *sprite;
    sfTexture *texture;
    sfVector2f pos;
    sfIntRect rect;
    bool exist;
};

struct game_object
{
    sfSprite *sprite;
    sfTexture *texture;
    sfVector2f position;
    sfVector2f initial_pos;
    sfVector2f speed;
    sfVector2f initial_speed;
    TYPE type;
    sfIntRect rect;
    int indic;
    int jump;
};

struct score
{
    sfText *text;
    sfFont *font;
    sfClock *clock;
    sfTime time;
    int seconds;
    int score;
};

typedef struct clock t_clock;

struct clock
{
    float seconds;
    sfTime time;
    sfClock *clock;
    sfClock *clock2;
    float seconds2;
    sfTime time2;
};

typedef struct framebuffer framebuffer_t;

struct framebuffer
{
    sfRenderWindow *window;
    sfEvent event;
    sfMusic *menu_music;
    sfMusic *game_music;
    sfSound *sound;
    sfSoundBuffer *sound_buffer_l;
    sfSoundBuffer *sound_buffer_w;
    int i;
    int fail;
};

//menu handler

void exit_handler(framebuffer_t *buffer, menu_object **menu, sfVector2i pos);
void setting_handler(framebuffer_t *buffer, menu_object **menu, sfVector2i pos);
void start_handler(menu_object **menu, framebuffer_t *buffer, \
score_t *score, sfVector2i pos);
void fps_handler(menu_object **menu, framebuffer_t *buffer, sfVector2i pos);
void pause_handler(menu_object **menu, framebuffer_t *buffer, sfVector2i pos);
void escape_pause(menu_object **menu, framebuffer_t *buffer);


//menu function

menu_object *create_menu_object(char *path, sfVector2f pos, sfVector2f scale, \
sfIntRect rect);
void destroy_menu(menu_object **menu_obj);
menu_object **init_menu(void);
void destroy_menu_object(menu_object *menu_obj);
void menuobject_draw(menu_object **menu, sfRenderWindow *window);
void display_pause(sfRenderWindow *window, menu_object **menu);


//init structure

game_object *create_object(const char *sprite_sheet, sfVector2f pos, \
sfIntRect rect);
sfIntRect init_rect(int width, int height);
framebuffer_t *init_buffer(void);
void reverse_bg(game_object **obj);
score_t *init_score(void);
t_clock *create_clock(void);
game_object **init_struct(void);
sfMusic *set_music(void);
void set_sound(sfSound *sound, sfSoundBuffer *sound_buffer);


//move function

void move_ground(game_object **obj);
void move_background(game_object **obj);
int jump(game_object **obj, sfClock *clock, int i, float seconds);
void move_rect(menu_object *menu, int left);


//display function

int display_window(framebuffer_t *buffer, game_object **obj, char *path);
void gameobject_draw(game_object **obj, framebuffer_t *buffer, sfText *text, \
menu_object **menu);
void print_error(int ac);
void print_usage(void);


//update function

int update_score(score_t *score, game_object **obj);
void update_menu(framebuffer_t *buffer, menu_object **menu, score_t *score, \
game_object **obj);


//destroy function

void destroy_clock(t_clock *clock);
void destroy_buffer(framebuffer_t *buffer);
void destroy_score(score_t *score);
void destroy_all(game_object **obj);


//other function

int analyse_param(int ac, char **av);
int read_map(char *path, game_object **obj);
int check_end_game(game_object **obj, framebuffer_t *buffer);
void check_collision(game_object **obj, framebuffer_t *buffer);
void stop_game(game_object **obj, framebuffer_t *buffer);
void end_game_handler(game_object **obj, framebuffer_t *buffer, \
score_t *score, sfVector2i pos);
void reverse_bg(game_object **obj);
int random_spawn(int pos);
int start_infinite(game_object **obj, framebuffer_t *buffer);
int add_random_enemy(game_object **obj, int count);

#endif /* !RUNNER_H_ */
