#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "ml6.h"
#include "display.h"
#include "draw.h"

int main() {

  screen s;
  color c;

  c.red = 1;
  c.green = 0;
  c.blue = 0;

  clear_screen(s);
  for (int a = 0; a < 501; a++){
    for (int b = 0; b < 501; b++){
      draw_line(a, b, a+1, 500, s, c);
      if (c.red != 256) c.red++;
      else c.red = 0;
    }
  } 

  display(s);
  save_extension(s, "lines.png");
}
