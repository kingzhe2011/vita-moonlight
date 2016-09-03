#include <stdbool.h>
#include <vita2d.h>

#define WIDTH 960
#define HEIGHT 544

struct menu_entry {
  int id;
  char *name, subname[1024];
  bool disabled, separator;
};

struct menu_geom {
  int x, y, width, height, el, total_y;
};

vita2d_pgf *gui_font;

struct menu_geom make_geom_centered(int w, int h);

typedef int (*gui_loop_callback) (int, void *);
typedef int (*gui_back_callback) (void *);

bool was_button_pressed(short id);
bool is_button_down(short id);

int display_menu(
        struct menu_entry menu[],
        int total_elements,
        gui_loop_callback loop_callback,
        gui_back_callback back_callback,
        void *context
        );

void display_alert(
        char *message,
        char *button_captions[],
        int buttons_count,
        gui_loop_callback cb,
        void *context
        );

void display_error(char *format, ...);

void flash_message(char *format, ...);

void guilib_init();
