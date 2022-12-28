#include "piece.h"

//Return the link to the piece's image
String getImageLink(Piece piece){
    String link;
    //A faire : modifier le lien en fonction du type de sprite choisit (jap ou fr)
    link = concat(setString("sprites/japanese/"), piece.name);
    link = concat(link, setString(".png"));
    return link;
}