/*
** EPITECH PROJECT, 2020
** B-MUL-100-LIL-1-1-myrunner-yannis.alouache [WSL: Ubuntu]
** File description:
** my_runner
*/
#include "SFML/Graphics.h"
#include "SFML/Audio.h"

typedef enum {
    MENU,
    PLAY,
    PAUSE,
    WIN,
    LOOSE,
} gs_t;

typedef struct
{
    sfSprite *sprite;
    sfImage *img;
    int x;
    int y;
    sfFloatRect *hitbox;
    sfClock *clock;
} element_t;

typedef struct
{
    sfSprite *sprite;
    sfImage *img;
    int x;
    int y;
    int vel_x;
    int vel_y;
    int life;
    int fs;
    sfClock *clock;
    sfBool jumping;
    int jump_count;
    int jump_count2;
    float gravity;
    sfFloatRect *hitbox;
    int running;
} player_t;

typedef struct
{
    element_t *title;
    sfText *text;
    sfClock *text_clock;
} menu_t;

typedef struct
{
    int loose;
    int win;
    sfText *final_txt;
    element_t *play_again;
    element_t *quit;
} final_screen_t;

typedef struct
{
    element_t *mountain1[3];
    element_t *mountain2[3];
    element_t *graveyard[3];
} parralax_t;

typedef struct
{
    sfRenderWindow *window;
    sfSprite *background;
    int grass_nb;
    int tomb_nb;
    int spike_nb;
    int ghost_nb;
    int gato_nb;
    parralax_t *para;
    player_t *player;
    sfView *camera;
    sfMusic *music;
    sfSound *win_sound;
    int win_sound_counter;
    sfClock *win_sound_clock;
    sfSoundBuffer *sound_buffer;
    int ground_height;
    sfText *score_txt[2];
    int score;
    element_t **grass;
    element_t **tomb;
    element_t **spike;
    element_t **ghost;
    element_t **gato;
    int won;
    int loose;
    gs_t GAME_STATE;
    menu_t *menu;
    final_screen_t *final_screen;
    element_t *cursor;
    int read_size;
    int fps;
} app_t;

typedef struct
{
    int grass;
    int tomb;
    int spike;
    int ghost;
    int gato;
} counter_t;

app_t *init_app(char *fps);
sfRenderWindow *create_window(app_t *app);
sfSprite *create_background(void);
element_t *init_mountain1(app_t *app, int i);
element_t *init_mountain2(app_t *app, int i);
sfSprite *create_graveyard(element_t *graveyard);
void draw_graveyard(app_t *app);
element_t *init_graveyard(app_t *app, int i);
void draw_mountain1(app_t *app);
void draw_mountain2(app_t *app);
sfSprite *create_mountain(element_t *mountain);
void draw_background(app_t *app);
element_t *init_grass(app_t *app, int i);
player_t *init_player(app_t *app);
void draw_player(app_t *app);
void draw_grass(app_t *app);
void print_h(int ac, char **av);
sfView *init_camera(app_t *app);
void camera(app_t *app);
sfMusic *init_music();
sfText *init_score(int i);
counter_t *init_counter();
int read_map(app_t *app, char *path);
sfFloatRect *camera_bound(sfView *camera);
void malloc_game_obj(app_t *app);
void get_elem_nb(app_t *app, char *path);
sfFloatRect *get_bound(sfSprite *sprite);
sfFloatRect *get_player_hitbox(player_t *player);
void manage_jump(app_t *app);
void draw_obstacle(app_t *app);
void draw_score(app_t *app);
void draw_player_hitbox(app_t *app);
sfBool check_collide_obstacle(app_t *app);
element_t *custom_init_grass(int x, int y);
element_t *create_object(char *path_to_sprite, int x, int y);
void jump(app_t *app);
void apply_gravity(app_t *app);
element_t *init_title(void);
void draw_title(app_t *app, menu_t *menu);
sfSound *init_sound();
void play_win_sound(app_t *app);
void move_rect(sfIntRect *player_rect);
void menu(app_t *app);
sfText *init_text(void);
void draw_title(app_t *app, menu_t *menu);
void draw_text(app_t *app, menu_t *menu);
void animation(app_t *app);
void final_screen(app_t *app);
void win_or_loose(app_t *app);
final_screen_t *init_final_screen(app_t *app);
void handle_score_nb(app_t *app, int i);
void draw_final_score(app_t *app);
void draw_win_text(app_t *app, final_screen_t *screen);
sfText *init_final_text(app_t *app);
menu_t *init_menu(void);
void draw_btn(app_t *app, final_screen_t *screen);
void draw_cursor(app_t *app);
void draw_final_text(app_t *app, final_screen_t *screen);
element_t *create_object_spe(char *path_to_sprite, app_t *app);
void check_quit_btn(app_t *app, final_screen_t *screen);
void draw_spike(app_t *app);
void draw_gato(app_t *app);
void draw_tomb(app_t *app);
void draw_ghost(app_t *app);
int check_collide_spike(app_t *app);
int check_collide_tomb(app_t *app);
int check_collide_ghost(app_t *app);
int check_collide_gato(app_t *app);
sfBool check_collide_obstacle2(app_t *app);
void spawn_grass(char c, app_t *app, counter_t *count, sfVector2i pos);
void spawn_spike(char c, app_t *app, counter_t *count, sfVector2i pos);
void spawn_tomb(char c, app_t *app, counter_t *count, sfVector2i pos);
void spawn_ghost(app_t *app, counter_t *count, sfVector2i pos);
void spawn_gato(app_t *app, counter_t *count, sfVector2i pos);
int random_between(int min, int max);
element_t *create_object_ghost(char *path_to_sprite, int x, int y);
element_t *create_object_gato(char *path_to_sprite, int x, int y);
parralax_t *init_parralax(app_t *app);
void game_manager(app_t *app);
void menu_manager(app_t *app);
void loose_manager(app_t *app);
void win_manager(app_t *app);
void state_manager(app_t *app);
void draw_parralax(app_t *app);
int check_map_error(char *path, app_t *app);