#include "ImageButton.h"
#include <QPainter>

ImageButton::ImageButton (
        const QString& text,
        const QString& normalImage,
        const QString& hoverImage,
        const QString& pressImage,
        const QString& disableImage,
        bool hyperlink,
        QWidget* parent) :
    QPushButton (parent),
    text (text),
    normalImage (normalImage),
    hoverImage (hoverImage),
    pressImage (pressImage),
    disableImage (disableImage),
    color (Qt::white),
    size (0),
    hyperlink (hyperlink),
    enable (true),
    hover (false),
    press (false),
    bold (true) {
}

ImageButton::ImageButton (
        const QString& text,
        const QString& normalImage,
        const QString& hoverImage,
        const QString& pressImage,
        bool hyperlink,
        QWidget* parent) :
    QPushButton (parent),
    text (text),
    normalImage (normalImage),
    hoverImage (hoverImage),
    pressImage (pressImage),
    disableImage (normalImage),
    color (Qt::white),
    size (0),
    hyperlink (hyperlink),
    enable (true),
    hover (false),
    press (false),
    bold (true) {
}

ImageButton::ImageButton (
        const QString& text,
        const QString& normalImage,
        const QString& hoverImage,
        bool hyperlink,
        QWidget* parent) :
    QPushButton(parent),
    text (text),
    normalImage (normalImage),
    hoverImage (hoverImage),
    pressImage (normalImage),
    disableImage (normalImage),
    color (Qt::white),
    size (0),
    hyperlink (hyperlink),
    enable (true),
    hover (false),
    press (false),
    bold (true) {
}

ImageButton::ImageButton (
        const QString& text,
        const QString& normalImage,
        bool hyperlink,
        QWidget* parent) :
    QPushButton(parent),
    text (text),
    normalImage (normalImage),
    hoverImage (normalImage),
    pressImage (normalImage),
    disableImage (normalImage),
    color (Qt::white),
    size (0),
    hyperlink (hyperlink),
    enable (true),
    hover (false),
    press (false),
    bold (true) {
}


void
ImageButton::paintEvent (
        QPaintEvent* event) {
    Q_UNUSED(event);

    QPainter painter(this);

    if (true == this->press  && this->isEnabled()) {

        painter.drawImage(QPoint(0,0), this->pressImage);

    } else if (true == this->hover && this->isEnabled()) {

        painter.drawImage(QPoint(0,0), this->hoverImage);

    } else if (true == this->isEnabled ()){

        painter.drawImage(QPoint(0,0), this->normalImage);

    } else {

        painter.drawImage (QPoint(0,0), this->disableImage);
    }

    if (false == this->text.isEmpty()) {

        painter.setRenderHint (QPainter::Antialiasing);
        painter.setPen (this->color);

        QFont font = painter.font ();
        font.setBold (this->bold);
        if ( 0 < this->size)
        {
            font.setPointSize (this->size);
        }

        painter.setFont (font);
        painter.drawText (QRect(0,0, this->width (), this->height ()),
                          Qt::AlignCenter,
                          this->text);
    }

    painter.end ();
}

void
ImageButton::enterEvent (
        QEvent * event) {

    if (this->hyperlink) {
        this->setCursor (Qt::PointingHandCursor);
    }

    this->hover = true;
    this->update();

    QPushButton::enterEvent(event);

}

void
ImageButton::leaveEvent(
        QEvent * event) {

    if (this->hyperlink) {
        this->setCursor (Qt::ArrowCursor);
    }

    this->hover = false;
    this->update();

    QPushButton::leaveEvent(event);
}

bool
ImageButton::setSelect (
        bool status) {

    this->press = status;
    this->update();

    return(true);
}

bool
ImageButton::setSelect () {

    this->press = !this->press;
    this->update();

    return(true);
}

bool ImageButton::setcolor(QColor &color)
{
    this->color = color;

    return true;
}

bool ImageButton::setBold(bool bold)
{
    this->bold = bold;

    return true;
}

bool ImageButton::setSize(int size)
{
    this->size = size;

    return true;
}

bool ImageButton::setText (QString text)
{
    this->text = text;

    return true;
}
