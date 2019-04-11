#include "mappingwidget.h"

MappingWidget::MappingWidget()
{
    ui.setupUi(this);

    // legacy style signal mapping
    mapper = new QSignalMapper(this);
    QVector<QPushButton *> foobarButtons({
        ui.fooButton,
        ui.barButton,
        ui.foobarButton,
    });
    for (auto const &button : foobarButtons)
    {
        connect(button, SIGNAL(clicked()), mapper, SLOT(map()));
        mapper->setMapping(button, button->text());
    }
    connect(mapper, SIGNAL(mapped(QString)), this, SLOT(foobarLabelUpdate(QString)));

    // qt5 style signal mapping
    QVector<QPushButton *> fizzbuzzButtons({
        ui.fizzButton,
        ui.buzzButton,
        ui.fizzbuzzButton,
    });
    for (auto const &button : fizzbuzzButtons)
    {
        auto const &text = button->text();
        connect(button, &QPushButton::clicked, [=] { ui.fizzbuzzLabel->setText(text); });
    }
}

MappingWidget::~MappingWidget()
{
    delete mapper;
}

void MappingWidget::foobarLabelUpdate(const QString &text)
{
    ui.foobarLabel->setText(text);
}
