#include "playerinterface.h"

#define debug false

//
// CONSTRUCTEUR DE LA CLASSE EN CHARGE DE CREER L'INTERFACE GRAPHIQUE DU PLAYER
//
PlayerInterface::PlayerInterface()
    : QWidget(0, Qt::Window)
{
    //
    //	INITIALISATION DES POINTEURS SUR LES "IMAGES"
    //
    bufferIn   = NULL;
    bufferOut  = NULL;
    bufferTmp1 = NULL;
    bufferTmp2 = NULL;

    frameAverage = 0;
    seconds      = 0;

    // ON INITIALISE LES VARIABLES AFIN DE PROVOQUER UNE MISE A JOUR LORS DU
    // PREMIER AFFICHAGE DE LA VIDEO A L'ECRAN
    _inWidth  = -1;
    _inHeight = -1;
    _ouWidth  = -1;
    _ouHeight = -1;

    //
    //	CREATION DES OBJETS VISUELS (INTERFACE GRAPHIQUE)
    //
    _videoWidget   = new OpenglWidget(this);
    _listeFiltres  = new QComboBox(this);

    //
    // ON REALISE LA MISE EN FORME A L'ECRAN
    //
    QHBoxLayout *layout = new QHBoxLayout;
    QVBoxLayout *l4     = new QVBoxLayout;
    setLayout(layout);

    //
    // ON CREE LES FILTRES
    //
    filters = new FilterManager();

    NoFilter* nof = new NoFilter("None");
    InverseFilter *invf = new InverseFilter("Inverse");
    FilterR *cfilterR = new FilterR("Red");
    FilterG *cfilterG = new FilterG("Green");
    FilterB *cfilterB = new FilterB("Blue");
    UpSampleFilter *upsamplef = new UpSampleFilter("Up Sample");
    DownSampleFilterPick *dsfp = new DownSampleFilterPick("Down Sample (Pick)");
    DownSampleFilterLin *dsflin = new DownSampleFilterLin("Down Sample (Linear)");
    DownSampleFilterSqr *dsfsqr = new DownSampleFilterSqr("Down Sample (Square)");
    AutomaticColorLevelFilter *autocolor = new AutomaticColorLevelFilter("Automatic color leveling");

    SimpleGreyFilter* sgf = new SimpleGreyFilter("Simple Gray");
    LiableGreyFilter* lgf = new LiableGreyFilter("Liable Gray");

    MotionBlurFilter* mbf = new MotionBlurFilter("Motion Blur");

    ComplexFilterEx1* cmp1 = new ComplexFilterEx1("Complex Filter 1");
    ComplexFilterEx2* cmp2 = new ComplexFilterEx2("Complex Filter 2");
    ComplexFilterEx3* cmp3 = new ComplexFilterEx3("Complex Filter 3");
    ComplexFilterEx4* cmp4 = new ComplexFilterEx4("Complex Filter 4");

    DetectionM0* lecontourdupauvre0 = new DetectionM0("DetectionM0");
    DetectionM1* lecontourdupauvre1 = new DetectionM1("DetectionM1");
    DetectionM2* lecontourdupauvre2 = new DetectionM2("DetectionM2");
    DetectionM3* lecontourdupauvre3 = new DetectionM3("DetectionM3");
    DetectionM4* lecontourdupauvre4 = new DetectionM4("DetectionM4");
    DetectionM5* lecontourdupauvre5 = new DetectionM5("DetectionM5");
    DetectionM6* lecontourdupauvre6 = new DetectionM6("DetectionM6");
    DetectionM7* lecontourdupauvre7 = new DetectionM7("DetectionM7");
    DetectionM8* lecontourdupauvre8 = new DetectionM8("DetectionM8");
    DetectionM9* lecontourdupauvre9 = new DetectionM9("DetectionM9");

    BlurB0* lefloudupauvre0    = new BlurB0("BlurB0");
    BlurB1* lefloudupauvre1    = new BlurB1("BlurB1");
    BlurB2* lefloudupauvre2    = new BlurB2("BlurB2");
    BlurB3* lefloudupauvre3    = new BlurB3("BlurB3");

    filters->addFilter(nof);
    filters->addFilter(invf);
    filters->addFilter(sgf);
    filters->addFilter(lgf);
    filters->addFilter(cfilterR);
    filters->addFilter(cfilterG);
    filters->addFilter(cfilterB);
    filters->addFilter(upsamplef);
    filters->addFilter(dsfp);
    filters->addFilter(dsflin);
    filters->addFilter(dsfsqr);
    filters->addFilter(autocolor);

    filters->addFilter(lecontourdupauvre0);
    filters->addFilter(lecontourdupauvre1);
    filters->addFilter(lecontourdupauvre2);
    filters->addFilter(lecontourdupauvre3);
    filters->addFilter(lecontourdupauvre4);
    filters->addFilter(lecontourdupauvre5);
    filters->addFilter(lecontourdupauvre6);
    filters->addFilter(lecontourdupauvre7);
    filters->addFilter(lecontourdupauvre8);
    filters->addFilter(lecontourdupauvre9);

    filters->addFilter(lefloudupauvre0);
    filters->addFilter(lefloudupauvre1);
    filters->addFilter(lefloudupauvre2);
    filters->addFilter(lefloudupauvre3);

    filters->addFilter(mbf);
    filters->addFilter(cmp1);
    filters->addFilter(cmp2);
    filters->addFilter(cmp3);
    filters->addFilter(cmp4);


    //
    // DECLARATION DE TOUS LES PLUGINS DE TRAITEMENT VIDEO
    //

    for(int i = 0; i < filters->amount(); i++){
        _listeFiltres->addItem( filters->getFilterAt(i)->getFilterName());

    }

    _isPlaying = false;

    //
    // LE MODE WEBCAM EST DESACTIVE DANS CETTE VERSION DE L'OUTIL
    //
    isWebCam         = false;


    //
    // DECLARATION ET INSTANCIATION DES BOUTTONS
    //
    start       = new QPushButton( "Stop video", this );
    nextFrame   = new QPushButton( "Next Frame", this );
    pause       = new QPushButton( "Switch to camera", this );
    filterFrame = new QPushButton( "Limit 24fps", this );
    addFilter   = new QPushButton( "Add new filter", this);

    pause->setEnabled( false );
    start->setEnabled( false );
    nextFrame->setEnabled( false );
    filterFrame->setEnabled( false );

    // ON CREE UN REGROUPEMENT POUR L'ENSEMBLE DES ELEMENTS LIES AU FILTRAGE
    QGroupBox   *g1 = new QGroupBox(tr("Filter processing"));
    QVBoxLayout *fp = new QVBoxLayout;
    fp->addWidget(_listeFiltres);
    fp->addWidget(addFilter);
    g1->setLayout(fp);

    QGroupBox   *g2 = new QGroupBox(tr("Action commands"));
    QVBoxLayout *ac = new QVBoxLayout;
    ac->addWidget(pause);
    ac->addWidget(start);
    ac->addWidget(nextFrame);
    ac->addWidget(filterFrame);
    g2->setLayout(ac);

    QGroupBox   *g3 = new QGroupBox(tr("Input video informations"));
    QVBoxLayout *vi = new QVBoxLayout;
    inWidth  = new QLabel(tr("Video width"));
    inHeight = new QLabel(tr("Video width"));
    vi->addWidget( inWidth  );
    vi->addWidget( inHeight );
    g3->setLayout(vi);

    QGroupBox   *g4 = new QGroupBox(tr("Output video informations"));
    QVBoxLayout *pd = new QVBoxLayout;
    ouWidth  = new QLabel(tr("Video width"));
    ouHeight = new QLabel(tr("Video width"));
    pd->addWidget( ouWidth  );
    pd->addWidget( ouHeight );
    g4->setLayout(pd);

    QGroupBox   *pp = new QGroupBox(tr("Processing informations"));
    QVBoxLayout *pt = new QVBoxLayout;
    dTime  = new QLabel(tr("Video width"));
    pTime = new QLabel(tr("Video width"));
    sTime = new QLabel(tr("Video width"));
    pt->addWidget( dTime  );
    pt->addWidget( pTime );
    pt->addWidget( sTime );
    pp->setLayout(pt);

    l4->addWidget(g1);
    l4->addWidget(g2);
    l4->addWidget(g3);
    l4->addWidget(g4);
    l4->addWidget(pp);

    layout->addLayout(l4);

    //
    // GESTION DE L'AFFICHAGE DE L'IMAGE
    //
    QScrollArea *scrollArea = new QScrollArea;
    scrollArea->setBackgroundRole(QPalette::Dark);
    scrollArea->setWidget(_videoWidget);
    layout->addWidget(scrollArea);


    //
    // ON GENERE UNE INTERUPTION TOUTES LES 5MS AFIN DE LANCER LE DECODAGE D'UNE IMAGE,
    // CELA NOUS PERMET EN THEORIE DE MONTER A 200Hz
    //
    poller = new QTimer(this);
    connect(poller, SIGNAL(timeout()), this, SLOT(drawNextFrame()));
    poller->setInterval(1000/200);
    processing = false;

    //
    // ON CREE UN PROGRAMME AUTONOME DONT LE ROLE EST DE METTRE A JOUR LA BARRE
    // DES TITRES AVEC LE NOMBRE D'IMAGES TRAITEES PAR SECONDE
    //
    timerFPS = new QTimer(this);
    connect(timerFPS, SIGNAL(timeout()), this, SLOT(frameCounterMethod()));
    timerFPS->start(1000);

    decodedFrames = 0;

    //
    // ON CONNECTE LES EVENEMENTS PRODUITS PAR LES OBJETS A UN GESTIONNAIRE D'INTERRUPTION
    // LOGICIEL EN CHARGE DE LEUR TRAITEMENT (CHAQUE EVENEMENT EST TRAITE PAR UNE METHODE)
    //
    connect(poller,         SIGNAL(timeout()),       this, SLOT(updateInterface())  );
    connect(start,          SIGNAL(clicked()),       this, SLOT(startButton())      );
    connect(pause,          SIGNAL(clicked()),       this, SLOT(openFile())         );
    connect(nextFrame,      SIGNAL(clicked()),       this, SLOT(stepOneFrame())     );
    connect(filterFrame,    SIGNAL(clicked()),       this, SLOT(unlockFrameRate())  );
    connect(_listeFiltres,  SIGNAL(activated(int)),  this, SLOT(changePosition(int)));
    connect(addFilter,      SIGNAL(clicked()),       this, SLOT(actionAddFilter())  );

    setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
    updateGeometry();


    //
    // DECLARATION DES RACOURCIS CLAVIER
    //
    new QShortcut(Qt::CTRL + Qt::Key_Q, this, SLOT(close()));
    new QShortcut(Qt::Key_Space,        this, SLOT(startButton()));
    new QShortcut(Qt::Key_Escape,       this, SLOT(resetFilters()));
}


//
// DESTRUCTEUR DE L'OBJET QUI NE DEVRAIS PAS ETRE VIDE...
//
PlayerInterface::~PlayerInterface()
{
    delete timerFPS;
    delete poller;
    delete dTime;
    delete pTime;
    delete sTime;
    delete ouWidth;
    delete ouHeight;
    delete inWidth;
    delete inHeight;
    delete start;
    delete nextFrame;
    delete pause;
    delete filterFrame;
    delete addFilter;
    delete filters;
    delete _videoWidget;
    delete _listeFiltres;
    delete c;
    delete bufferIn;
    delete bufferTmp1;
    delete bufferTmp2;
    delete bufferOut;
}


void PlayerInterface::drawNextFrame()
{
    //
    // SI ON EST DEJA EN TRAIN DE TRAITER UNE IMAGE LORSQUE LE TIMER SE REVEILLE CELA SIGNIFIE
    // QUE L'ON EST A LA BOURRE DONC ON REPART POUR UN TOUR D'ATTENTE
    //
    if( processing == true ){
        cout << "OUPS we must wait a bit more because a frame is currently processed !" << endl;
        return;
    } processing = true;

    //
    // MESURE DU TEMPS...
    //
    long startC = clock();

    //
    // ON INCREMENTE LE NOMBRE D'IMAGES TRAITES
    //
    decodedFrames += 1;

    //
    // ON REGARDE SI L'ON EST EN COURS DE LECTURE DU FICHIER VIDEO, SINON ON RAFRAICHI UNQIUEMENT LE TRAITEMENT
    //
    if( _isPlaying == true ){

        //
        // CREATION DES BUFFERS TEMPORAIRES SI NECESSAIRE
        //
        if( bufferIn == NULL ){
            bufferIn  = new FastImage( 2, 2 );
            bufferOut = new FastImage( bufferIn );
            bufferTmp1 = new FastImage( bufferIn );
            bufferTmp2 = new FastImage( bufferIn );
        }

        c->getNextVideoFrame( bufferIn );

        //
        // ON GERE LE CAS OU LA VIDEO VIENT DE SE TERMINER... ON N'A PLUS RIEN A FAIRE
        // MAINTENANT !
        //
        if( c->isFinished() == true ){
            poller->stop();
            filterFrame->setEnabled( false );
            start->setEnabled( false );
            nextFrame->setEnabled( false );
            processing = false;
            return;
        }
    }

    //
    // AFFICHAGE DU TEMPS NECESSAIRE A L'EXTRATION DE l'IMAGE
    //
    _avgDecoding   += ( (double)(clock() - startC) ) / ( CLOCKS_PER_SEC ) * 1000.0;

    startC = clock(); // ON RELANCE LE COMPTEUR...


    //QString value = _listeFiltres->currentText();

    // EN FONCTION DU CHOIX FAIT DANS LA LISTE ON FAIT UN TRUC ?!
    /*if( _listeFiltres->currentIndex() == 0 ){

        if( bufferOut->width() != bufferIn->width() || bufferOut->height() != bufferIn->height() ){
            bufferOut->resize(bufferIn->height(), bufferIn->width());
        }
        bufferOut->FastCopyTo( bufferIn );

                // SINON ON FAIT AUTRECHOSE...
    }else{

        // REDIMENTIONNEMENT SI NECESSAIRE DU BUFFER DE SORTIE...
        if( bufferOut->width() != bufferIn->width() || bufferOut->height() != bufferIn->height() ){
            bufferOut->resize(bufferIn->height(), bufferIn->width());
        }

        for(int y=0; y<bufferIn->height(); y++){
                        for(int x=0; x<bufferIn->width(); x++){
                                bufferOut->Red  (y, x, 255 - bufferIn->Red(y,x) );
                                bufferOut->Green(y, x, 255 - bufferIn->Green(y,x) );
                                bufferOut->Blue (y, x, 255 - bufferIn->Blue(y,x) );
                        }
        }

    }*/
    filters->getFilterAt(_listeFiltres->currentIndex())->process(bufferIn, bufferOut);


    //
    // ON AFFICHE LE TEMPS NECESSAIRE A LA GESTION DU FILTRAGE
    //
    _avgProcessing += ( (double)(clock() - startC) ) / ( CLOCKS_PER_SEC ) * 1000.0;
    startC = clock(); // ON RELANCE LE COMPTEUR...

    //
    // ON REGARDE SI L'ON DOIT REDIMENSIONNER LA ZONE VISIBLE A L'ECRAN AFIN DE S'ADAPTER
    // AU RESULTAT DES DIFFERENTS FILTAGES
    //
    QSize cSize = _videoWidget->size();
    if( cSize.height() != bufferOut->height() || cSize.width() != bufferOut->width() ){
        //cout << "On a besoin d'un redimentionnement video (" << bufferOut->width() << "x" << bufferOut->height() << ")" << endl;
        cSize.setHeight( bufferOut->height() );
        cSize.setWidth ( bufferOut->width()  );
    }

    //
    // ON ENVOIE L'IMAGE VERS L'OBJET EN CHARGE DU TRAITEMENT OPENGL...
    //
    _videoWidget->DrawImage( bufferOut );
    _avgDrawing    += ( (double)(clock() - startC) ) / ( CLOCKS_PER_SEC ) * 1000.0;

    //
    // ON MET A JOURS LES DONNEES ISSUES DE L'INTERFACE GRAPHIQUE
    //
    if( bufferIn->width() != _inWidth || bufferIn->height() != _inHeight){
        _inWidth  = bufferIn->width();
        _inHeight = bufferIn->height();
        inWidth ->setText( tr("Video width  : ") + QVariant(_inWidth).toString()  + tr(" pixel(s)") );
        inHeight->setText( tr("Video height : ") + QVariant(_inHeight).toString() + tr(" pixel(s)") );
    }
    if( bufferOut->width() != _ouWidth || bufferOut->height() != _ouHeight){
        _ouWidth  = bufferOut->width();
        _ouHeight = bufferOut->height();
        ouWidth ->setText( tr("Video width  : ") + QVariant(_ouWidth).toString()  + tr(" pixel(s)") );
        ouHeight->setText( tr("Video height : ") + QVariant(_ouHeight).toString() + tr(" pixel(s)") );
    }

    // LE TRAITEMENT DE L'IMAGE EST TERMINE
    processing = false;
    if(debug) cout << "#################### FIN  PlayerInterface::drawNextFrame()  ####################" << endl;;
}



void PlayerInterface::openFile(QString* name)
{

    //
    // CREATION D'UNE BOITE DE DIALOGUE POUR L'OUVERTURE DU FICHIER VIDEO
    // UNIQUEMENT LORSQUE L'UTILISATEUR N'A PAS PRECISE DE FICHIER LORS
    // DU LANCEMENT DU PROGRAMME A L'AIDE DE LA LIGNE DE COMMANDE
    //
    if( name == NULL)
        fileName = QFileDialog::getOpenFileName(this,
                                                tr("Video files"), "",
                                                tr("Video files (*.avi *.mpg *.mkv *.mov);;All Files (*)"));
    else
        fileName = *name;

    // SI PAS DE NOM DE FICHIER ALORS ON QUITTE
    if(fileName.isEmpty()) exit( 0 );

    // ON CREE UN OBJET VIDEO ET ON PREFETCH LA PREMIERE IMAGE
    c = new CVideo( fileName.toStdString().c_str() );
    c->start();

    // ON ACTIVE LES BOUTONS EN CONSEQUENCE
    start->setEnabled( true );
    nextFrame->setEnabled( true );
    filterFrame->setEnabled( true );

    // ON AFFICHE LA PREMIERE IMAGE DE LA VIDEO
    _isPlaying = true;
    drawNextFrame();

    // ON DEMARRE LE PROCESSUS DE TRAITEMENT TEMPS REEL
    poller->start();
}


//
// METHODE INVOQUEE LORSQUE L'UTILISATEUR CHANGE UN FILTRE DANS LA LISTE. SI LA VIDEO
// EST EN COURS DE DECODAGE ALORS ON NE FAIT RIEN, SI ELLE EST ARRETEE ALORS ON CHOISI
//
void PlayerInterface::changePosition(int newPosition)
{
    cout << "(II) Un changement de filtre a ete enregistre... (" << newPosition << ")"  << endl;
    if( _isPlaying == true ) return;
    drawNextFrame();
}


//
// METHODE INVOQUEE PAR LE PROCESSUS PERIODIQUE (1 SECONDE) ET DONT LE ROLE EST DE
// RAFRAICHIR LE NOMBRE DE FPS INDIQUE DANS LA BARRE DES TITRES
//
void PlayerInterface::frameCounterMethod(){
    int nbre      = decodedFrames;

    if( decodedFrames != 0 ){
        double v0 = ((int)(100*((double)_avgDecoding  )/((double)decodedFrames)))/100.0;
        double v1 = ((int)(100*((double)_avgProcessing)/((double)decodedFrames)))/100.0;
        double v2 = ((int)(100*((double)_avgDrawing   )/((double)decodedFrames)))/100.0;

        dTime ->setText( tr("Avg decoding   time : ") + QVariant(v0).toString()  + tr(" ms") );
        pTime ->setText( tr("Avg processing time : ") + QVariant(v1).toString()  + tr(" ms") );
        sTime ->setText( tr("Avg drawing    time : ") + QVariant(v2).toString()  + tr(" ms") );
    }

    // ON REMET A ZERO LES COMPTEURS DE PERFORMANCE...
    _avgDecoding   = 0;
    _avgProcessing = 0;
    _avgDrawing    = 0;

    frameAverage += nbre;
    seconds      += 1;
    decodedFrames = 0;
    int nAvg = ((float)(floor(((float)frameAverage/(float)seconds)*10))/10);
    this->setWindowTitle("Processing speed : " + QVariant(nbre).toString()
                         + " (Average : " + QVariant(nAvg).toString() + ")" );
}


//
// METHODE INVOQUEE LORSQUE L'UTILISATEUR DEMANDE LE PASSAGE EN MODE WEBCAM. ON
// VERIFIE SI UNE WEBCAM EST DISPONIBLE, SI OUI ALORS ON L'ACTIVE...
//
void PlayerInterface::startButton(){
    if( poller->isActive() ){
        poller->stop();						// ARRET DU TIMER VIDEO
        start->setText("Start video");
        nextFrame->setEnabled( true );
    }else{
        poller->start();					// DEMARRAGE DU TIMER VIDEO
        start->setText("Stop video");
        nextFrame->setEnabled( false );
    }

    // ON MEMORISE L'ETAT D'ACTIVITE DE L'APPLICATION
    _isPlaying = poller->isActive();
}


//
// METHODE INVOQUEE LORSQUE L'UTILISATEUR DEMANDE DE BRIDER OU DEBRIDER LE FRAME
// RATE DU TRAITEMENT VIDEO.
//
void PlayerInterface::unlockFrameRate(){
    if( poller->interval() == (1000/25) ){
        filterFrame->setText("Limit to 24 fps");
        poller->setInterval( 5 );
    }else{
        filterFrame->setText("Unlock framerate");
        poller->setInterval( 1000/25 );
    }
}

//
// METHODE INVOQUEE LORSQUE L'UTILISATEUR DEMANDE LE PASSAGE EN MODE WEBCAM. ON
// VERIFIE SI UNE WEBCAM EST DISPONIBLE, SI OUI ALORS ON L'ACTIVE...
//
void PlayerInterface::switchToWebCam(){
    cout << "(II) Changement du comportement (1) : " << isWebCam << endl;
    isWebCam = ! isWebCam;
    if( isWebCam )
        pause       = new QPushButton( "Switch to file", this );
    else
        pause       = new QPushButton( "Switch to camera", this );
    cout << "(II) Changement du comportement (2) : " << isWebCam << endl;
}


//
// METHODE INVOQUEE LORSQUE L'UTILISATEUR DEMANDE L'AVANCEMENT MANUEL D'UNE IMAGE
//
void PlayerInterface::stepOneFrame(){
    cout << "(II) PlayerInterface::stepOneFrame()" << endl;
    if(_isPlaying == true){
        return;
    }
    _isPlaying = true;
    drawNextFrame();
    _isPlaying = false;
    cout << "(II) FIN PlayerInterface::stepOneFrame()" << endl;
}

//
// METHODE INVOQUEE LORSQUE L'UTILISATEUR DEMANDE L'AVANCEMENT MANUEL D'UNE IMAGE
//
void PlayerInterface::resetFilters(){
    _listeFiltres->setCurrentIndex(0);
}

void PlayerInterface::actionAddFilter(){
    QString* name = new QString;
    char filterstoadd[MAX_FILTERS];
    int n = 0;
    AddFilterDialog dialog(name, filterstoadd, &n, this);
    dialog.exec();
    cout << n << " Filters in : "<< name->toStdString() << " created" << endl;
    if( (n > 0) && (name->length() != 0)){
        ComplexFilter* cmpx = new ComplexFilter(*name);
        Filter* f;
        for(int i = 0; i < n; i++){
            switch(filterstoadd[i]){
                case 0:
                    f = new InverseFilter("Inverse");
                    cmpx->addFilter(f);
                    break;
                case 1:
                    f = new FilterR("Red");
                    cmpx->addFilter(f);
                    break;
                case 2:
                    f = new FilterG("Green");
                    cmpx->addFilter(f);
                    break;
                case 3:
                    f = new FilterB("Blue");
                    cmpx->addFilter(f);
                    break;
                case 4:
                    f = new UpSampleFilter("UpSample");
                    cmpx->addFilter(f);
                    break;
                case 5:
                    f = new DownSampleFilterPick("DownSample");
                    cmpx->addFilter(f);
                    break;
                case 6:
                    f = new DownSampleFilterLin("DownSample");
                    cmpx->addFilter(f);
                    break;
                case 7:
                    f = new DownSampleFilterSqr("DownSample");
                    cmpx->addFilter(f);
                    break;
                case 8:
                    f = new AutomaticColorLevelFilter("AutoColor");
                    cmpx->addFilter(f);
                    break;
                case 9:
                    f = new SimpleGreyFilter("SimpleGrey");
                    cmpx->addFilter(f);
                    break;
                case 10:
                    f = new LiableGreyFilter("LiableGrey");
                    cmpx->addFilter(f);
                    break;
                case 11:
                    f = new MotionBlurFilter("MotionBlur");
                    cmpx->addFilter(f);
                    break;
                case 12:
                    f = new DetectionM0("Detection M0");
                    cmpx->addFilter(f);
                    break;
                case 13:
                    f = new DetectionM1("Detection M1");
                    cmpx->addFilter(f);
                    break;
                case 14:
                    f = new DetectionM2("Detection M2");
                    cmpx->addFilter(f);
                    break;
                case 15:
                    f = new DetectionM3("Detection M3");
                    cmpx->addFilter(f);
                    break;
                case 16:
                    f = new DetectionM4("Detection M4");
                    cmpx->addFilter(f);
                    break;
                case 17:
                    f = new DetectionM5("Detection M5");
                    cmpx->addFilter(f);
                    break;
                case 18:
                    f = new DetectionM6("Detection M6");
                    cmpx->addFilter(f);
                    break;
                case 19:
                    f = new DetectionM7("Detection M7");
                    cmpx->addFilter(f);
                    break;
                case 20:
                    f = new DetectionM8("Detection M8");
                    cmpx->addFilter(f);
                    break;
                case 21:
                    f = new DetectionM9("Detection M9");
                    cmpx->addFilter(f);
                    break;
                case 22:
                    f = new BlurB0("Blur B0");
                    cmpx->addFilter(f);
                    break;
                case 23:
                    f = new BlurB1("Blur B1");
                    cmpx->addFilter(f);
                    break;
                case 24:
                    f = new BlurB2("Blur B2");
                    cmpx->addFilter(f);
                    break;
                case 25:
                    f = new BlurB3("Blur B3");
                    cmpx->addFilter(f);
                    break;

            }
        }
        filters->addFilter(cmpx);
        _listeFiltres->addItem(filters->getFilterAt(filters->amount()-1)->getFilterName());
    }
}
