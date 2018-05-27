#include "addfilterdialog.hpp"

AddFilterDialog::AddFilterDialog(QString* _name, char* _filterstoadd, int* _n, QWidget * parent, Qt::WindowFlags f) : QDialog(parent, f)
{
    newname = _name;
    nout = _n;
    *_n = 0;
    n = 0;
    filterstoadd = _filterstoadd;

    QVBoxLayout* layout = new QVBoxLayout;
    this->setLayout(layout);
    name = new QLineEdit();

    listesFiltres = new QComboBox();
    listesFiltres->addItem("Inverse");
    listesFiltres->addItem("Red");
    listesFiltres->addItem("Green");
    listesFiltres->addItem("Blue");
    listesFiltres->addItem("Up Sample");
    listesFiltres->addItem("Down Sample (Pick)");
    listesFiltres->addItem("Down Sample (Linear)");
    listesFiltres->addItem("Down Sample (Square)");
    listesFiltres->addItem("Automatic color leveling");
    listesFiltres->addItem("Simple Grey");
    listesFiltres->addItem("Liable Grey");
    listesFiltres->addItem("MotionBlur");

    listesFiltres->addItem("Detection M0");
    listesFiltres->addItem("Detection M1");
    listesFiltres->addItem("Detection M2");
    listesFiltres->addItem("Detection M3");
    listesFiltres->addItem("Detection M4");
    listesFiltres->addItem("Detection M5");
    listesFiltres->addItem("Detection M6");
    listesFiltres->addItem("Detection M7");
    listesFiltres->addItem("Detection M8");
    listesFiltres->addItem("Detection M9");

    listesFiltres->addItem("Blur B0");
    listesFiltres->addItem("Blur B1");
    listesFiltres->addItem("Blur B2");
    listesFiltres->addItem("Blur B3");


    add = new QPushButton("Add Filter");
    validate = new QPushButton("Create");
    dispFilters = new QTextEdit();
    dispFilters->setReadOnly(true);
    dispFilters->ensureCursorVisible();
    dispFilters->insertPlainText("Filters List :\n\n");

    layout->addWidget(name);
    layout->addWidget(listesFiltres);
    layout->addWidget(add);
    layout->addWidget(validate);
    layout->addWidget(dispFilters);

    connect(add, SIGNAL(clicked()), this, SLOT(addfilter()));
    connect(validate, SIGNAL(clicked()), this, SLOT(createfilter()));
}

AddFilterDialog::~AddFilterDialog(){
    delete dispFilters;
    delete add;
    delete validate;
    delete name;
    delete filterstoadd;
    delete nout;
    delete newname;
    delete name;
}

void AddFilterDialog::addfilter(){
    if(n <= MAX_FILTERS){
        dispFilters->insertPlainText(listesFiltres->currentText() + "\n");
        filterstoadd[n] = listesFiltres->currentIndex();
        n++;
    }
}

void AddFilterDialog::createfilter(){
    newname->append(name->text());
    *nout = n;
    close();
}
