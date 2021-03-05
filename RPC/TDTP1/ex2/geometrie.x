struct point { int x; int y; };
struct rectangle { struct point p1; struct point p2; };
struct coordonnees { int x1; int x2; int y1; int y2; };
struct param_inclus { struct rectangle rect; struct point p; }; 
typedef int booleen;
program GEOM_PROG {
    version GEOM_VERSION_1 {
        int SURFACE_RECTANGLE(rectangle) = 1; 
        rectangle CREER_RECTANGLE(coordonnees) = 2; 
        booleen INCLUS(param_inclus) = 3;
    } = 1;
} = 0x20000001;