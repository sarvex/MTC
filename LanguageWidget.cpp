#include "DeamonSetting.h"
#include "LanguageWidget.h"

#include <QDebug>


LanguageWidget::LanguageWidget(QWidget *parent) :
    QWidget(parent)
{
    this->languageLabel = new QLabel(tr("Language"), this);
    this->languageLabel->setAlignment (Qt::AlignRight | Qt::AlignCenter);

    this->language = new QComboBox(this);

    this->language->addItem (tr ("English"));
    this->language->setItemData (0, "en_US");

    this->language->addItem (tr ("Russian"));
    this->language->setItemData (1, "ru_RU");

    this->language->addItem (tr ("Ukrainian"));
    this->language->setItemData (2, "uk_UA");

    if (DeamonSetting::getInstance ()->getLanguage () == "en_US") {
        this->language->setCurrentIndex (0);
    } else if (DeamonSetting::getInstance ()->getLanguage () == "ru_RU") {
        this->language->setCurrentIndex (1);
    } else if (DeamonSetting::getInstance ()->getLanguage () == "uk_UA") {
        this->language->setCurrentIndex (2);
    }

    this->save = new ImageButton(tr("Save"), ":/smallButtonDefault.png", ":/smallButtonHover.png", ":/smallButtonPress.png", "", this);
    this->save->setFixedWidth (80);
    this->save->setFixedHeight (21);
    QObject::connect (this->save, SIGNAL(clicked()), SLOT(onSaveClicked()));

    this->cancel = new ImageButton(tr("Cancel"), ":/smallButtonDefault.png", ":/smallButtonHover.png", ":/smallButtonPress.png", "", this);
    this->cancel->setFixedWidth (80);
    this->cancel->setFixedHeight (21);
    QObject::connect (this->cancel, SIGNAL(clicked()), SLOT(onCancelClicked()));

    this->grid = new QGridLayout;
    this->grid->setContentsMargins (20, 0, 20, 0);
    this->grid->setHorizontalSpacing (40);
    this->grid->addWidget (this->languageLabel, 0, 0);
    this->grid->addWidget (this->language, 0, 1);

    this->buttons = new QVBoxLayout;
    this->buttons->addWidget (this->save);
    this->buttons->addWidget (this->cancel);

    this->layout = new QHBoxLayout;
    this->layout->addLayout (this->grid);
    this->layout->addLayout (this->buttons);

    this->setLayout (this->layout);
}


bool LanguageWidget::onSaveClicked(){

    int index = this->language->currentIndex ();

    qDebug () << "Language Saving" << this->language->itemData (index).toString ();

    DeamonSetting::getInstance ()->setLanguage (this->language->itemData (index).toString ());

    emit this->languageChange (this->language->itemData (index).toString ());

    emit dismissAction ();

    return true;
}

bool LanguageWidget::onCancelClicked(){

    emit dismissAction ();
    return true;
}

bool LanguageWidget::onRetranslate(){

    this->languageLabel->setText (tr("Language"));
    this->language->setItemText (0,tr("English"));
    this->language->setItemText (1,tr("Russian"));
    this->language->setItemText (2,tr("Ukrainian"));

    this->save->setText (tr("Save"));
    this->cancel->setText (tr("Cancel"));

    return true;
}
