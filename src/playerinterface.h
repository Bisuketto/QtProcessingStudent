#ifndef PLAYERINTERFACE_H
#define PLAYERINTERFACE_H

#include <QtCore/QCoreApplication>
#include <QApplication>
#include <QProcess>
#include <QVBoxLayout>
#include <QWidget>
#include <QSizePolicy>
#include <QPushButton>
#include <QTextEdit>
#include <QComboBox>
#include <QCloseEvent>
#include <QTimer>
#include <QDebug>
#include <QVector>
#include <QFileDialog>
#include <QScrollArea>
#include <QShortcut>
#include <QGroupBox>
#include <QLabel>


#include "./Image/CVideo.h"
#include "openglwidget.h"

#include "src/Filter/filtermanager.hpp"
#include "src/Filter/nofilter.hpp"
#include "src/Filter/inversefilter.hpp"
#include "src/Filter/canalfilter.hpp"
#include "src/Filter/greyfilter.hpp"
#include "src/Filter/liablegreyfilter.hpp"
#include "src/Filter/simplegreyfilter.hpp"
#include "src/Filter/filterr.hpp"
#include "src/Filter/filterg.hpp"
#include "src/Filter/filterb.hpp"
#include "src/Filter/upsamplefilter.hpp"
#include "src/Filter/downsamplefilterpick.hpp"
#include "src/Filter/downsamplefilterlin.hpp"
#include "src/Filter/downsamplefiltersqr.hpp"
#include "src/Filter/automaticcolorlevelfilter.hpp"
#include "src/Filter/convolutionfilter.hpp"
#include "src/Filter/detectionfilter3p3.hpp"
#include "src/Filter/detectionfilter3p1.hpp"
#include "src/Filter/detectionfilter2p1.hpp"
#include "src/Filter/pow2normblurfilter.hpp"
#include "src/Filter/notpow2normblurfilter.hpp"
#include "src/Filter/motionblurfilter.hpp"
#include "src/Filter/complexfilter.hpp"
#include "src/Filter/complexfilterex1.hpp"
#include "src/Filter/complexfilterex2.hpp"
#include "src/Filter/complexfilterex3.hpp"
#include "src/Filter/complexfilterex4.hpp"
#include "src/addfilterdialog.hpp"


#define POSITION_RESOLUTION 10000


class PlayerInterface : public QWidget
{
    Q_OBJECT
    QComboBox *_listeFiltres;

    QPushButton *start;
    QPushButton *pause;
    QPushButton *nextFrame;
    QPushButton *filterFrame;
    QPushButton *addFilter;

    // LABELS UTILISES DANS L'INTERFACE AFIN DE FOURNIR DES INFORMATIONS
    // SUR LES FLUX VIDEO MANIPULES
    QLabel *inWidth;
    QLabel *inHeight;
    QLabel *ouWidth;
    QLabel *ouHeight;

    // LABLES UTILISES DANS L'INTERFACE AFIN DE FOURNIR UNE MESURE DU TEMPS
    // DES DIFFERENTS TRAITEMENTS (DECODAGE, PROCESSING, AFFICHAGE)
    QLabel *dTime;
    QLabel *pTime;
    QLabel *sTime;

    // VARIABLE UTILISEE AFIN DE MINIMISER LE NOMBRE DE MISES A JOUR DE
    // L'INTERFACE GRAPHIQUE.
    int _inWidth;
    int _inHeight;
    int _ouWidth;
    int _ouHeight;

    //
    // VARIABLE UTILISEE AFIN DE MINIMISER LE NOMBRE DE MISES A JOUR DE
    // L'INTERFACE GRAPHIQUE.
    //
    int _avgDecoding;
    int _avgProcessing;
    int _avgDrawing;

    // MUTEX POUR GERER LE TRAITEMENT DE L'INFORMATION
    bool processing;

    bool isWebCam; // GESTION DU PASSAGE FLUX VIDEO / WebCam

    OpenglWidget *_videoWidget;
    QTimer *poller;

    int decodedFrames;
    int frameAverage;
    int seconds;
    QTimer *timerFPS;

    bool _isPlaying;
    CVideo *c;

    QString fileName;

    FastImage *bufferIn;
    FastImage *bufferTmp1;
    FastImage *bufferTmp2;
    FastImage *bufferOut;

    FilterManager* filters;

public:
    PlayerInterface();
    ~PlayerInterface();

public slots:
    void actionAddFilter();
    //void playFile();
    void openFile(QString* name);
    //void updateInterface();
    //void changeVolume(int newVolume);

    // METHODE SERVANT A GERER LE FILTRE EN MODE PAUSE
    void changePosition(int newPosition);

    void drawNextFrame();
    void frameCounterMethod();

    void startButton();
    void switchToWebCam();

    void unlockFrameRate();

    void stepOneFrame();
    void resetFilters();
};

#endif // PLAYERINTERFACE_H
