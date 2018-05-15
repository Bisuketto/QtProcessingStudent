#ifndef ADDFILTERDIALOG_HPP
#define ADDFILTERDIALOG_HPP

#include <QObject>
#include <QDialog>
#include <QPushButton>
#include <QVBoxLayout>
#include <QComboBox>
#include <QLineEdit>
#include <QTextEdit>

#define MAX_FILTERS 10

class AddFilterDialog : public QDialog
{
    Q_OBJECT
public:
    AddFilterDialog(QString* _name, char* _filterstoadd, int* _n, QWidget * parent = 0, Qt::WindowFlags f = 0);
public slots:
    void addfilter();
    void createfilter();
private:
    QString* newname;
    char* filterstoadd;
    int n;
    int* nout;
    QLineEdit* name;
    QComboBox* listesFiltres;
    QPushButton* add;
    QPushButton* validate;
    QTextEdit* dispFilters;
};

#endif // ADDFILTERDIALOG_HPP
