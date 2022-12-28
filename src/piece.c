/**
 * ----------------------------------------------
 *                     piece.c
 * ----------------------------------------------
 * 
 * Encoding for the piece.
 */


#include "piece.h"
#include "constants.h"


/**
 * Return the link to the piece's image
 * @param _piece The piece in play
 * @param _option The sprite type choice
 * @return A string containing the piece image link
 */
String getImageLink(Piece _piece, char _option) {
    String link;
    
    link = setString(SPRITE_DIRECTORY);
    link = concat(link, setString(_option ? CHESS_SPRITES : JAPANESE_SPRITES));
    link = concat(link, _piece.name);
    link = concat(link, setString(".png"));

    return link;
}