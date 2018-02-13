#include <stdio.h>
#include <stdlib.h>

#include "ml6.h"
#include "display.h"
#include "draw.h"

//Insert your line algorithm here
int getOctant(int dx, int dy){
  if (dy > 0 && dy < dx) return 1;
  if (dy > 0 && dy > dx) return 2;
  if (dy < 0 && abs(dy) < dx) return 8;
  if (dy < 0 && abs(dy) > dx) return 7;
  return -1;
}

void draw_line(int x0, int y0, int x1, int y1, screen s, color c) {
  int dx = x1 - x0;
  int dy = y1 - y0;
  int d = (2*dy) - dx;

  if (x0 > x1){
    draw_line (x1, y1, x0, y0, s, c);
  }

  int oct = getOctant(dx, dy);
  if (oct == 1){
    while (x0 < x1){
      plot(s,c,x0,y0);
      if (d > 0){
	y0++;
	d-=2*dx;
      }
      x0++;
      d+=2*dy;
    }
  }
  else if (oct == 2){
    while (x0 < x1){
      plot(s,c,x0,y0);
      if (d > 0){
	x0++;
	d-=2*dy;
      }
      y0++;
      d+=2*dx;
    }
  }
  else if (oct == 8){
    while (x0 < x1){
      plot(s,c,x0,y0);
      if (d < 0){
	y0--;
	d+=2*dx;
      }
      x0++;
      d+=2*dy;
    }
  }
  else if (oct == 7){
    while (x0 < x1){
      plot(s,c,x0,y0);
      if (d < 0){
	x0++;
	d+=2*dy;
      }
      y0--;
      d+=2*dx;
    }
  }
  else printf("Invalid coords");		    
}
