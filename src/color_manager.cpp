#include "color_manager.h"

#include <QtGui>
#include <QtCore>

ColoredArea::ColoredArea() 
{
    _posStart = 0;
    _posEnd = 0;
    _fontColor = QPen(QColor::fromRgba(qRgba(0, 0, 0, 0)));
    _areaColor = QColor::fromRgba(qRgba(0, 0, 0, 0));
}

ColoredArea::ColoredArea(QPen pen, QColor background)
{
    _posStart = 0;
    _posEnd = 0;
    _fontColor = pen;
    _areaColor = background;
}

ColoredArea::ColoredArea(qint64 posStart, qint64 posEnd, QPen pen, QColor background)
{
    _posStart = posStart;
    _posEnd = posEnd;
    _fontColor = pen;
    _areaColor = background;
}

QPen ColoredArea::fontPen()
{
    return _fontColor;
}

QColor ColoredArea::fontColor()
{
    return _fontColor.color();
}

void ColoredArea::setFontColor(QColor color)
{
    _fontColor = QPen(color);
}

QColor ColoredArea::areaColor()
{
    return _areaColor;
}

void ColoredArea::setAreaColor(QColor color)
{
    _areaColor = color;
}

qint64 ColoredArea::posStart()
{
    return _posStart;
};

qint64 ColoredArea::posEnd()
{
    return _posEnd;
};

void ColoredArea::setRange(qint64 posStart, qint64 posEnd)
{
    _posStart = posStart;
    _posEnd = posEnd;
};

void ColoredArea::clear() 
{
    _posStart = 0;
    _posEnd = 0;
}


/********************************************* */

ColorManager::ColorManager(QPalette palette)
{
    _selection = ColoredArea(QColor::fromRgb(255, 255, 255), palette.highlight().color());
    _highlighting = ColoredArea(QColor::fromRgb(0, 0, 0), QColor(0xff, 0xff, 0x99, 0xff));
    _address = ColoredArea(QColor(QPalette::WindowText), palette.alternateBase().color());
    _hex = ColoredArea(QColor::fromRgb(0, 0, 0), palette.base().color());
    _ascii = ColoredArea(QColor(QPalette::WindowText), palette.alternateBase().color());
};

ColoredArea ColorManager::markedArea(qint64 pos, Area area, Chunks *chunks)
{
    // prio 1 selection
    if (pos >= _selection.posStart() && pos < _selection.posEnd())
    {
        return _selection;
    }
    // prio 2 highlighting (changed data)
    if (chunks->dataChanged(pos))
    {
        return _highlighting;
    }
    // prio 3 user defined areas
    foreach (ColoredArea area, _userAreas)
    {
        if (pos >= area.posStart() && pos < area.posEnd())
        {
            return area;
        }
    }
    // nothing found -> standard colors
    return this->notMarked(area);
};

ColoredArea ColorManager::notMarked(Area area)
{
    switch (area) {
        case Area::Address:
            return _address;
            break;
        case Area::Ascii:
            return _ascii;
            break;
        case Area::Hex:
            return _hex;
            break;
    }
    return _hex; // should never happen
}

ColoredArea ColorManager::selection()
{
    return _selection;
};

ColoredArea ColorManager::highlighting()
{
    return _highlighting;
};

void ColorManager::addUserArea(qint64 posStart, qint64 posEnd, QColor fontColor, QColor areaColor)
{
    ColoredArea userArea = ColoredArea(posStart, posEnd, fontColor, areaColor);
    _userAreas.append(userArea);
}

void ColorManager::clearUserAreas()
{
    _userAreas.clear();
}