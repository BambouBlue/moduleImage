#ifndef PIXEL_H_INCLUDED
#define PIXEL_H_INCLUDED



#endif // PIXEL_H_INCLUDED

class Pixel{
    private:
        int r,g,b;
    public:
        Pixel (){
        r=g=b=0;
        }

        ~Pixel ()

        Pixel (int nr, int ng, int nb){
            r=nr;
            g=ng;
            b=nb;
        }

        setRouge(nr){
            r=nr;
        }

        setVert(ng){
            g=ng;
        }

        setBleu(nb){
            b=nb;
        }

};
