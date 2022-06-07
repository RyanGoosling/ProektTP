#ifndef STATFORM_H
#define STATFORM_H
#include <QWidget>
#include "clientfunctions.h"
#include "Client.h"
namespace Ui {
class StatForm;
}

class StatForm : public QWidget
{
    Q_OBJECT

public:
    explicit StatForm(QWidget *parent = nullptr);
    ~StatForm();
public slots:
    void setstat();
private:
    Ui::StatForm *ui;
};

#endif // STATFORM_H
