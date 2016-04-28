#include<cairo.h>
#include<cairo-xlib.h>
#include<X11/Xlib.h>
#include<stdio.h>
int main(int ac,char**av){
	if(ac<2){
		puts("snap <png file name>\ni.e. snap scr.png");
		return -1;
	}
	*av++;
	const char*fn=*av++;
	puts(fn);
	Display*d=XOpenDisplay(NULL);
	const int s=DefaultScreen(d);
	const Window r=DefaultRootWindow(d);
	cairo_surface_t*cs=cairo_xlib_surface_create(d,r,DefaultVisual(d,s),DisplayWidth(d,s),DisplayHeight(d,s));
	cairo_surface_write_to_png(cs,fn);
	cairo_surface_destroy(cs);
	return 0;
}
