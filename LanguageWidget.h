#ifndef LANGUAGE_WIDGET
#define LANGUAGE_WIDGET

#include "ImageButton.h"

#include <QGridLayout>
#include <QHBoxLayout>
#include <QComboBox>
#include <QLabel>
#include <QVBoxLayout>
#include <QWidget>

class LanguageWidget : public QWidget
{
    Q_OBJECT

public:
    explicit LanguageWidget(QWidget *parent = 0);

signals:
    bool languageChange (QString language);
    bool dismissAction ();

public slots:
    bool onSaveClicked();
    bool onCancelClicked();

    bool onRetranslate();

private:
    QLabel * languageLabel;
    QComboBox * language;

    ImageButton * save;
    ImageButton * cancel;

    QGridLayout * grid;
    QVBoxLayout * buttons;
    QHBoxLayout * layout;
};

#endif // LANGUAGE_WIDGET
