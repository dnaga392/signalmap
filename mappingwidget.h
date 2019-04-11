#include <QtCore/QSignalMapper>
#include <QtCore/QVector>
#include <QtWidgets/QWidget>
#include "ui_mappingwidget.h"

class MappingWidget : public QWidget
{
    Q_OBJECT

public:
    MappingWidget();
    ~MappingWidget();

private:
    Ui::MappingWidget ui;
    QSignalMapper *mapper;

private slots:
    void foobarLabelUpdate(const QString &text);
};
