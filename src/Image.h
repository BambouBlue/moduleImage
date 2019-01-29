#ifndef IMAGE_H
#define IMAGE_H

#include "Pixel.h"

class Image {
private:
	int dimx;
	int dimy;
	Pixel *tab;

public:

	Image ();
   
	Image (int dimensionX, int dimensionY);

	~Image ();

	Pixel getPix (int x, int y);

	void setPix (int x, int y, Pixel couleur);

	void dessinerRectangle (int Xmin, int Ymin, int Xmax, int Ymax, Pixel couleur);

	void effacer (Pixel couleur);

	void testRegression ();
};

#endif
