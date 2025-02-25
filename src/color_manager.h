#ifndef COLOR_MANAGER_H
#define COLOR_MANAGER_H

/** \cond docNever */

/*! The ColorManager class is responsible for color management
 *
 * Color management is combined in this class. The definitions for pen and background colors 
 * are stored here.
 * 
 * This includes the standard colors for the address, hex data and ASCII data areas as well as 
 * the colors for the marking information. The areas for selection and highlighting are defined 
 * in advance. In addition, any number of user areas can be defined. 
 * 
 * The colors for a single area are provided by the ColoredArea class.
 */

#include <QtCore>
#include <QtGui>

#include "chunks.h"

enum Area {
    Address,
    Hex,
    Ascii,
};

class ColoredArea
{
public:
    // Cunstructors
    ColoredArea();
    ColoredArea(QPen pen, QBrush background);
    ColoredArea(qint64 posStart, qint64 posEnd, QPen pen, QBrush background);

    // Property to set/get font color
    QColor fontColor();
    void setFontColor(QColor color);

    // Property to set/get area style
    QColor areaColor();
    QBrush areaStyle();
    void setAreaColor(QColor color);
    void setAreaStyle(QBrush background);

    // other Methods to acces and set internal data
    QPen fontPen();
    qint64 posStart();
    qint64 posEnd();
    void setRange(qint64 posStart, qint64 posEnd);
    void clear();

private:
    qint64 _posStart;
    qint64 _posEnd;
    QPen _fontColor;
    QBrush _areaStyle;
};


class ColorManager
{
public:
    // Constructor including the definition of standard colors
    ColorManager();

    // reload the palette and adapt the apeareance
    void setPalette(const QPalette &palette);

    // Method returns color definitions for data at position pos in area area
    ColoredArea markedArea(qint64 pos, Area area, Chunks *chunks);

    // Method returns standard collors (without marking)
    ColoredArea& notMarked(Area);

    // Get the selection color definitions
    ColoredArea& selection();

    // Get the highlighting color definitions
    ColoredArea& highlighting();

    // Add a user defined area
    void addUserArea(qint64 posStart, qint64 posEnd, QColor fontColor, QBrush areaStyle);

    // Clear all user defined areas
    void clearUserAreas();

private:
    ColoredArea _highlighting;
    ColoredArea _selection;
    ColoredArea _address;
    ColoredArea _hex;
    ColoredArea _ascii;

    QList<ColoredArea> _userAreas;
};

#endif // COLOR_MANAGER_H