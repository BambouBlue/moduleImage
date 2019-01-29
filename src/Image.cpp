#include "image.h"
#include "Pixel.h"
#include <iostream>


Image::Image () 
	:dimx(0), dimy(0), tab(nullptr) {	

}
   
Image::Image (int dimensionX, int dimensionY) {
	if(dimensionX < 0 || dimensionY < 0) {
		std::cerr << "Impossible de créer une image dont les dimensions sont négatives!" << std::endl;
		this->tab = nullptr;
	}
	else {
		this->tab = new Pixel[dimx*dimy];
	}
}

Image::~Image () {
	delete [] this->tab;
}

Pixel Image::getPix (int x, int y) {
	Pixel ret;
	if(x < 0 || x >= this->dimx || y < 0 || y >= this->dimy) {
		std::cerr << "Cannot get pixel at position (" << x << "," << y << ")." << std::endl;	
	}
	else {
		ret = this->tab[y*this->dimx + x];
	}
	return ret;
}

void Image::setPix (int x, int y, Pixel couleur) {
	if(x < 0 || x >= this->dimx || y < 0 || y >= this->dimy) {
		std::cerr << "Cannot set pixel at position (" << x << "," << y << ")." << std::endl;	
	}
	else {
		this->tab[y*this->dimx + x] = couleur;
	}
}
	
void Image::dessinerRectangle (int Xmin, int Ymin, int Xmax, int Ymax, Pixel couleur) {
	if(Xmin < 0 || Xmin >= Xmax || 
		Ymin < 0 || Ymin >= Ymax ||
		Xmax >= this->dimx ||
		Ymax >= this->dimy) 
	{
		std::cerr << "Impossible de dessiner le rectangle avec les coordonnées données" << std::endl;
	}
	else {
		for(int x = Xmin; x < Xmax; x++) {
			for(int y = Ymin; y < Ymax; y++) {
				setPix(x, y, couleur);
			}
		}
	}
}
	
void Image::effacer (Pixel couleur) {
	dessinerRectangle(0, 0, this->dimx-1, this->dimy-1, couleur);
}

void Image::testRegression () {
	Pixel couleur = getPix(-1, -1);
	Pixel couleur2 = getPix(dimx+1, dimy+1);
	setPix(-1, -1, couleur);
	setPix(dimx, dimy, couleur2);
	dessinerRectangle(-1, -1, dimx, dimy, couleur);
}

