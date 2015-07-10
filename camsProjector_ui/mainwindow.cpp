#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "stdafx.h"
#include <iostream>
#include <sstream>
#include "FlyCapture2.h"
#include "opencv2/objdetect/objdetect.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include <iostream>
#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>

using namespace std;
using namespace cv;
using namespace FlyCapture2;
using namespace std;

#define debug(args...) {dbg,args; cerr<<endl;}
struct debugger
{
    template<typename T> debugger& operator , (const T& v)
    {
        cerr<<v<<" ";
        return *this;
    }
} dbg;

int NUM_IMAGES = 30;         // Number of Images to be taken can be changed from here.

// Variables to adjust projecting position. By trial and error we can adjust these parameters to get slit exactly on eye
int LEFTSLITLIM = 100;      // Position (in pixels) from which slit is going to be projected        1<leftSlitLim<WIDTH
int RIGHTSLITLIM = 500;     // Position (in pixels) at which slit projection is ended               1<rightSlitLim<WIDTH and rightSlitLim>leftSlitLim
int HEIGHT = 1080;
int WIDTH = 1920;
int WAIT_TIME = 500;
float SLIT_THICKNESS = 0.8;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    // Set default parameters here.
    // Lable names can be found from Forms -> mainwindow.ui
    ui->noImagesLineEdit->setText("100");
    ui->heightLineEdit->setText("480");
    ui->widthLineEdit->setText("640");
    ui->leftSlitLimLineEdit->setText("200");
    ui->rightSlitLimLineEdit->setText("640");
    ui->slitThicknessLineEdit->setText("0.8");
    ui->waitTimeLineEdit->setText("500");

    ui->captureNameLineEdit->setText("Sample");
    ui->captureFormatLineEdit->setText("png");

    ui->brightnessLineEdit->setText("1.367");
    ui->autoExposureLineEdit->setText("0.459");
    ui->sharpnessLineEdit->setText("1024");
    ui->shutterLineEdit->setText("32.471");
    ui->gainLineEdit->setText("3.010");
    ui->frameRateLineEdit->setText("30");

}

MainWindow::~MainWindow()
{
    delete ui;
}

//IplImage* ConvertImageToOpenCV(Image* pImage)
//{
//    IplImage* cvImage = NULL;
//    bool bColor = true;
//    CvSize mySize;
//    mySize.height = pImage->GetRows();
//    mySize.width = pImage->GetCols();

//    switch ( pImage->GetPixelFormat() )
//    {
//        case PIXEL_FORMAT_MONO8:     cvImage = cvCreateImageHeader(mySize, 8, 1 );
//                                     cvImage->depth = IPL_DEPTH_8U;
//                                     cvImage->nChannels = 1;
//                                     bColor = false;
//                                     break;
//        case PIXEL_FORMAT_411YUV8:   cvImage = cvCreateImageHeader(mySize, 8, 3 );
//                                     cvImage->depth = IPL_DEPTH_8U;
//                                     cvImage->nChannels = 3;
//                                     break;
//        case PIXEL_FORMAT_422YUV8:   cvImage = cvCreateImageHeader(mySize, 8, 3 );
//                                     cvImage->depth = IPL_DEPTH_8U;
//                                     cvImage->nChannels = 3;
//                                     break;
//        case PIXEL_FORMAT_444YUV8:   cvImage = cvCreateImageHeader(mySize, 8, 3 );
//                                     cvImage->depth = IPL_DEPTH_8U;
//                                     cvImage->nChannels = 3;
//                                     break;
//        case PIXEL_FORMAT_RGB8:      cvImage = cvCreateImageHeader(mySize, 8, 3 );
//                                     cvImage->depth = IPL_DEPTH_8U;
//                                     cvImage->nChannels = 3;
//                                     break;
//        case PIXEL_FORMAT_MONO16:    cvImage = cvCreateImageHeader(mySize, 16, 1 );
//                                     cvImage->depth = IPL_DEPTH_16U;
//                                     cvImage->nChannels = 1;
//                                     bColor = false;
//                                     break;
//        case PIXEL_FORMAT_RGB16:     cvImage = cvCreateImageHeader(mySize, 16, 3 );
//                                     cvImage->depth = IPL_DEPTH_16U;
//                                     cvImage->nChannels = 3;
//                                     break;
//        case PIXEL_FORMAT_S_MONO16:  cvImage = cvCreateImageHeader(mySize, 16, 1 );
//                                     cvImage->depth = IPL_DEPTH_16U;
//                                     cvImage->nChannels = 1;
//                                     bColor = false;
//                                     break;
//        case PIXEL_FORMAT_S_RGB16:   cvImage = cvCreateImageHeader(mySize, 16, 3 );
//                                     cvImage->depth = IPL_DEPTH_16U;
//                                     cvImage->nChannels = 3;
//                                     break;
//        case PIXEL_FORMAT_RAW8:      cvImage = cvCreateImageHeader(mySize, 8, 3 );
//                                     cvImage->depth = IPL_DEPTH_8U;
//                                     cvImage->nChannels = 3;
//                                     break;
//        case PIXEL_FORMAT_RAW16:     cvImage = cvCreateImageHeader(mySize, 8, 3 );
//                                     cvImage->depth = IPL_DEPTH_8U;
//                                     cvImage->nChannels = 3;
//                                     break;
//        case PIXEL_FORMAT_MONO12:    printf("Not supported by OpenCV");
//                                     bColor = false;
//                                     break;
//        case PIXEL_FORMAT_RAW12:     printf("Not supported by OpenCV");
//                                     break;
//        case PIXEL_FORMAT_BGR:       cvImage = cvCreateImageHeader(mySize, 8, 3 );
//                                     cvImage->depth = IPL_DEPTH_8U;
//                                     cvImage->nChannels = 3;
//                                     break;
//        case PIXEL_FORMAT_BGRU:      cvImage = cvCreateImageHeader(mySize, 8, 4 );
//                                     cvImage->depth = IPL_DEPTH_8U;
//                                     cvImage->nChannels = 4;
//                                     break;
//        case PIXEL_FORMAT_RGBU:      cvImage = cvCreateImageHeader(mySize, 8, 4 );
//                                     cvImage->depth = IPL_DEPTH_8U;
//                                     cvImage->nChannels = 4;
//                                     break;
//        default: printf("Some error occured...\n");
//                 return NULL;
//    }

//    if(bColor) {
//        if(!bInitialized)
//        {
//            colorImage.SetData(new unsigned char[pImage->GetCols() * pImage->GetRows()*3], pImage->GetCols() * pImage->GetRows()*3);
//            bInitialized = true;
//        }

//        pImage->Convert(PIXEL_FORMAT_BGR, &colorImage); //needs to be as BGR to be saved

//        cvImage->width = colorImage.GetCols();
//        cvImage->height = colorImage.GetRows();
//        cvImage->widthStep = colorImage.GetStride();

//        cvImage->origin = 0; //interleaved color channels

//        cvImage->imageDataOrigin = (char*)colorImage.GetData(); //DataOrigin and Data same pointer, no ROI
//        cvImage->imageData         = (char*)(colorImage.GetData());
//        cvImage->widthStep      = colorImage.GetStride();
//        cvImage->nSize = sizeof (IplImage);
//        cvImage->imageSize = cvImage->height * cvImage->widthStep;
//    }
//    else
//    {
//        cvImage->imageDataOrigin = (char*)(pImage->GetData());
//        cvImage->imageData         = (char*)(pImage->GetData());
//        cvImage->widthStep         = pImage->GetStride();
//        cvImage->nSize             = sizeof (IplImage);
//        cvImage->imageSize         = cvImage->height * cvImage->widthStep;

//        //at this point cvImage contains a valid IplImage
//     }
//    return cvImage;
//}

void GetPixelFormat(Image* pImage)
{
    IplImage* cvImage = NULL;
    bool bColor = true;
    CvSize mySize;
    mySize.height = pImage->GetRows();
    mySize.width = pImage->GetCols();

    switch ( pImage->GetPixelFormat() )
    {
        case PIXEL_FORMAT_MONO8:     cout << "PIXEL_FORMAT_MONO8" << endl;
                                     break;
        case PIXEL_FORMAT_411YUV8:   cout << "PIXEL_FORMAT_MONO8" << endl;
                                     break;
        case PIXEL_FORMAT_422YUV8:   cout << "PIXEL_FORMAT_MONO8" << endl;
                                     break;
        case PIXEL_FORMAT_444YUV8:   cout << "PIXEL_FORMAT_MONO8" << endl;
                                     break;
        case PIXEL_FORMAT_RGB8:      cout << "PIXEL_FORMAT_RGB8" << endl;
                                     break;
        case PIXEL_FORMAT_MONO16:    cout << "PIXEL_FORMAT_MONO16" << endl;
                                     break;
        case PIXEL_FORMAT_RGB16:     cout << "PIXEL_FORMAT_RGB16" << endl;
                                     break;
        case PIXEL_FORMAT_S_MONO16:  cout << "PIXEL_FORMAT_MONO8" << endl;
                                     break;
        case PIXEL_FORMAT_S_RGB16:   cout << "PIXEL_FORMAT_MONO8" << endl;
                                     break;
        case PIXEL_FORMAT_RAW8:      cout << "PIXEL_FORMAT_RAW8" << endl;
                                     break;
        case PIXEL_FORMAT_RAW16:     cout << "PIXEL_FORMAT_RAW16" << endl;
                                     break;
        case PIXEL_FORMAT_MONO12:    printf("Not supported by OpenCV");
                                     bColor = false;
                                     break;
        case PIXEL_FORMAT_RAW12:     printf("Not supported by OpenCV");
                                     break;
        case PIXEL_FORMAT_BGR:       cout << "PIXEL_FORMAT_BGR" << endl;
                                     break;
        case PIXEL_FORMAT_BGRU:      cout << "PIXEL_FORMAT_MONO8" << endl;
                                     break;
        case PIXEL_FORMAT_RGBU:      cout << "PIXEL_FORMAT_MONO8" << endl;
                                     break;
        default: printf("Some error occured...\n");
    }
}

void GetPixelFormat2(int pImage)
{
    IplImage* cvImage = NULL;
    bool bColor = true;
    CvSize mySize;

    switch ( pImage )
    {
        case PIXEL_FORMAT_MONO8:     cout << "PIXEL_FORMAT_MONO8" << endl;
                                     break;
        case PIXEL_FORMAT_411YUV8:   cout << "PIXEL_FORMAT_MONO8" << endl;
                                     break;
        case PIXEL_FORMAT_422YUV8:   cout << "PIXEL_FORMAT_MONO8" << endl;
                                     break;
        case PIXEL_FORMAT_444YUV8:   cout << "PIXEL_FORMAT_MONO8" << endl;
                                     break;
        case PIXEL_FORMAT_RGB8:      cout << "PIXEL_FORMAT_RGB8" << endl;
                                     break;
        case PIXEL_FORMAT_MONO16:    cout << "PIXEL_FORMAT_MONO16" << endl;
                                     break;
        case PIXEL_FORMAT_RGB16:     cout << "PIXEL_FORMAT_RGB16" << endl;
                                     break;
        case PIXEL_FORMAT_S_MONO16:  cout << "PIXEL_FORMAT_MONO8" << endl;
                                     break;
        case PIXEL_FORMAT_S_RGB16:   cout << "PIXEL_FORMAT_MONO8" << endl;
                                     break;
        case PIXEL_FORMAT_RAW8:      cout << "PIXEL_FORMAT_RAW8" << endl;
                                     break;
        case PIXEL_FORMAT_RAW16:     cout << "PIXEL_FORMAT_RAW16" << endl;
                                     break;
        case PIXEL_FORMAT_MONO12:    printf("Not supported by OpenCV");
                                     bColor = false;
                                     break;
        case PIXEL_FORMAT_RAW12:     printf("Not supported by OpenCV");
                                     break;
        case PIXEL_FORMAT_BGR:       cout << "PIXEL_FORMAT_BGR" << endl;
                                     break;
        case PIXEL_FORMAT_BGRU:      cout << "PIXEL_FORMAT_MONO8" << endl;
                                     break;
        case PIXEL_FORMAT_RGBU:      cout << "PIXEL_FORMAT_MONO8" << endl;
                                     break;
        default: printf("Some error occured...\n");
    }
}

void PrintBuildInfo()
{
    FC2Version fc2Version;
    Utilities::GetLibraryVersion( &fc2Version );

    ostringstream version;
    version << "FlyCapture2 library version: " << fc2Version.major << "." << fc2Version.minor << "." << fc2Version.type << "." << fc2Version.build;
    cout << version.str() << endl;

    ostringstream timeStamp;
    timeStamp <<"Application build date: " << __DATE__ << " " << __TIME__;
    cout << timeStamp.str() << endl << endl;
}

void PrintCameraInfo( CameraInfo* pCamInfo )   // Function to print camera information
{
    cout << endl;
    cout << "*** CAMERA INFORMATION ***" << endl;
    cout << "Serial number -" << pCamInfo->serialNumber << endl;
    cout << "Camera model - " << pCamInfo->modelName << endl;
    cout << "Camera vendor - " << pCamInfo->vendorName << endl;
    cout << "Sensor - " << pCamInfo->sensorInfo << endl;
    cout << "Resolution - " << pCamInfo->sensorResolution << endl;
    cout << "Firmware version - " << pCamInfo->firmwareVersion << endl;
    cout << "Firmware build time - " << pCamInfo->firmwareBuildTime << endl << endl;

}

void PrintError( Error error )   // to handle errors
{
    error.PrintErrorTrace();
}

int calPos(int j)  // function to calculate the pixel row which is to be made bright
{
    int p = ( LEFTSLITLIM ) + ( ( j* (RIGHTSLITLIM -LEFTSLITLIM) ) /NUM_IMAGES );
//    if(p > HEIGHT)p = HEIGHT;
    return p;
}

void myline(Mat slit, Point start, Point end){

    float thickness = SLIT_THICKNESS;
    int lineType = 8;


    line(slit,
         start,
         end,
         Scalar(0, 255, 0),
         thickness,
         lineType);

}
void mylineblack(Mat slit, Point start, Point end){

    float thickness = SLIT_THICKNESS;
    int lineType = 8;
    line(slit,
         start,
         end,
         Scalar(0, 0, 0),
         thickness,
         lineType);

}

int SetProperties(Camera& cam, float propValues[]) {
    // Function to set various parameters.
    // The propValues array should contain values corresponding to their propTypes conterparts.
    Error error;

    PropertyType propTypes[7];
    propTypes[0] = BRIGHTNESS;
    propTypes[1] = AUTO_EXPOSURE;
    propTypes[2] = SHARPNESS;
//    propTypes[3] = GAMMA;
    propTypes[4] = SHUTTER;
    propTypes[5] = GAIN;
    propTypes[6] = FRAME_RATE;

    // See this
    // http://bytedeco.org/javacpp-presets/flycapture/apidocs/org/bytedeco/javacpp/FlyCapture2.Property.html

    PropertyType propType;
    Property prop;
    for(int i=0; i < 7; i++) {
        if(i == 3)continue;
        propType = propTypes[i];
        prop.type = propType;
        error = cam.GetProperty( &prop );

        if (error != PGRERROR_OK)
        {
            PrintError( error );
            return -1;
        }

        prop.autoManualMode = false;
        prop.onOff = true;

        error = cam.SetProperty( &prop );

        if (error != PGRERROR_OK)
        {
            PrintError( error );
            return -1;
        }
    }

    // Set various property values.
    for(int i=0; i < 7; i++) {
        if(i == 3)continue;
        propType = propTypes[i];
        prop.type = propType;
        error = cam.GetProperty( &prop );

        if (error != PGRERROR_OK)
        {
            PrintError( error );
            return -1;
        }
        cout << i << "th property before:" << prop.absValue << endl;
//        prop.autoManualMode = false;
//        prop.onOff = true;
        prop.absValue = propValues[i];

        error = cam.SetProperty( &prop );

        if (error != PGRERROR_OK)
        {
            PrintError( error );
            return -1;
        }
        cout << i << "th property after:" << prop.absValue << endl;


    }

    // Retrieve shutter property
//    Property shutter;
//    shutter.type = SHUTTER;
//    error = cam.GetProperty( &shutter );

//    if (error != PGRERROR_OK)
//    {
//        PrintError( error );
//        return -1;
//    }

//    cout << "Shutter before:" << shutter.absValue << endl;

//    shutter.absValue = ms;
//    error = cam.SetProperty( &shutter );

//    if (error != PGRERROR_OK)
//    {
//        PrintError( error );
//        return -1;
//    }

//    cout << "Shutter after:" << shutter.absValue << endl;

    // Let it update...it takes a while...
    // Otherwise the first pictures comes out
    //with the same shutter value as the old value
    sleep(5);
}


void MainWindow::on_startButton_clicked()
{
    PrintBuildInfo();

    Error error;

    bool ok;
    int noImages = ui->noImagesLineEdit->text().toInt(&ok, 10);
    int height = ui->heightLineEdit->text().toInt(&ok, 10);
    int width = ui->widthLineEdit->text().toInt(&ok, 10);
    int leftSlitLim = ui->leftSlitLimLineEdit->text().toInt(&ok, 10);
    int rightSlitLim = ui->rightSlitLimLineEdit->text().toInt(&ok, 10);
    float slitThickness = ui->slitThicknessLineEdit->text().toFloat(&ok);
    int waitTime = ui->waitTimeLineEdit->text().toInt(&ok, 10);

    QString captureName = ui->captureNameLineEdit->text();
    QString captureFormat = ui->captureFormatLineEdit->text();

    float brightness = ui->brightnessLineEdit->text().toFloat(&ok);
    float autoExposure =  ui->autoExposureLineEdit->text().toFloat(&ok);
    float sharpness =  ui->sharpnessLineEdit->text().toFloat(&ok);
    float shutter = ui->shutterLineEdit->text().toFloat(&ok);
    float gain = ui->gainLineEdit->text().toFloat(&ok);
    float frameRate = ui->frameRateLineEdit->text().toFloat(&ok);


    NUM_IMAGES = noImages;
    HEIGHT = height;
    WIDTH = width;
    LEFTSLITLIM = leftSlitLim;
    RIGHTSLITLIM = rightSlitLim;
    SLIT_THICKNESS = slitThickness;
    WAIT_TIME = waitTime;

    mkdir(captureName.toStdString().c_str(), S_IRWXU | S_IRWXG | S_IROTH | S_IXOTH);

    // Since this application saves images in the current folder
    // we must ensure that we have permission to write to this folder.
    // If we do not have permission, fail right away.

    FILE* tempFile = fopen("test.txt", "w+");
    if (tempFile == NULL)
    {
        cout << "Failed to create file in current folder.  Please check permissions." << endl;
        return;
    }
    fclose(tempFile);
    remove("test.txt");

    BusManager busMgr;
    unsigned int numCameras;
    error = busMgr.GetNumOfCameras(&numCameras);
    if (error != PGRERROR_OK)
    {
        PrintError( error );
        return;
    }

    cout << "Number of cameras detected: " << numCameras << endl;

    // Initialization for projecting the slit
    Camera cam[numCameras];

  //Mat slit(HEIGHT, WIDTH, DataType<unsigned char>::type);  // Slit Matrix

    Mat slit = Mat::zeros( HEIGHT, WIDTH, CV_8UC3);
    Mat whiteBg = Mat( HEIGHT, WIDTH, CV_8UC3, Scalar(255, 255, 255));

    cvNamedWindow("Display window", CV_WINDOW_NORMAL);
    cvSetWindowProperty("Display window", CV_WND_PROP_FULLSCREEN, CV_WINDOW_FULLSCREEN);

    for (int j=1; j < NUM_IMAGES+1; j++){   // loop for multiple images


        // Slit Display
//        for (int q=0;q<WIDTH;q++){
//            slit.at<uchar>(calPos(j-1),q) = 0;        // remove the last white rows from the images
//            slit.at<uchar>(calPos(j),q) = 255;        // insert white rows in the image
//        }
        mylineblack(slit, Point(calPos(j-1),0), Point(calPos(j-1),HEIGHT));
        myline(slit, Point(calPos(j),0), Point(calPos(j),HEIGHT));
//        for (int q=0;q<HEIGHT;q++){
//            slit.at<uchar>(q, calPos(j-1)) = 0;        // remove the last white rows from the images
//            slit.at<uchar>(q, calPos(j)) = 255;        // insert white rows in the image
//        }

        if(j == 1){
            imshow("Display window", whiteBg);
        } else {
            imshow( "Display window", slit );  // this call projects the slit
        }
        if(j == 2){
            waitKey(WAIT_TIME);
            waitKey(WAIT_TIME);
        }

        // wait time after projecting a slit (in miliseconds)
        // Press any key to exit
        if(waitKey(WAIT_TIME) != -1){
            destroyWindow("Display window");
            cout << "Window closed\n";
            return;
        }

        for (unsigned int i=0; i < numCameras; i++)    // loop for multiple cameras
        {
            cout << "\n" << i << endl;
            unsigned int camNo = i;
            unsigned int ImgNo = j;

            // Initialization of cameras
            PGRGuid guid[numCameras];
            error = busMgr.GetCameraFromIndex(i, &guid[i]);
            if (error != PGRERROR_OK)
            {
                PrintError( error );
                cout << "\nError 1 From camera" << i << "\n";
                return;
            }
            CameraInfo camInfo[numCameras];


            const int k_numImages = 1;



            // Connect to a camera

            error = cam[i].Connect(&guid[i]);
            if (error != PGRERROR_OK)
            {
                PrintError( error );
                 cout << "\nError 2 From camera" << i << "\n";
                return;
            }

            // Get the camera information

            error = cam[i].GetCameraInfo(&camInfo[i]);
            if (error != PGRERROR_OK)
            {
                PrintError( error );
                 cout << "\nError 3 From camera" << i << "\n";
                return;
            }
            //PrintCameraInfo(&camInfo);

            // Start capturing images
            error = cam[i].StartCapture();
            if (error != PGRERROR_OK)
            {
                PrintError( error );
                     cout << "\nError 4 From camera" << i << "\n";
                return;
            }

            // set various camera properties
            if(j == 1){
                float propValues[7];
                propValues[0] = brightness;
                propValues[1] = autoExposure;
                propValues[2] = sharpness;
//                propValues[3] = gamma;
                propValues[4] = shutter;
                propValues[5] = gain;
                propValues[6] = frameRate;
                int err = 0;
                err = SetProperties(cam[i], propValues);
                if(err == -1)
                {
                    cout<<"SetProperties Error\n";
                }
            }
            // Retrieve shutter property
            Property shutter;
            shutter.type = AUTO_EXPOSURE;
            error = cam[i].GetProperty( &shutter );

            if (error != PGRERROR_OK)
            {
                PrintError( error );
                return;
            }

            cout << "test some property normal:" << shutter.absValue << endl;

            Image rawImage;
//            rawImage.SetDefaultOutputFormat(PIXEL_FORMAT_RAW8);
            for ( int imageCnt=0; imageCnt < k_numImages; imageCnt++ )
            {
                // Retrieve an image
                error = cam[i].RetrieveBuffer( &rawImage );
                waitKey(100);
                if (error != PGRERROR_OK)
                {
                    PrintError( error );
                     cout << "\nError 5 From camera" << i << "\n";
                    destroyWindow("Display window");
                    return;
                }

                cout << "Grabbed: Camera " << camNo+1 << ",    Image Number" << ImgNo << endl;

                // Save image as raw
                // convert to OpenCV Mat
                Image convertedImage1;
                error = rawImage.Convert( PIXEL_FORMAT_RAW8, &convertedImage1 );
                if (error != PGRERROR_OK)
                {
                    PrintError( error );
                     cout << "\nError 10 From camera" << i << "\n";
                    return;
                }

                ostringstream filename1;
                filename1 << "./" << captureName.toStdString().c_str() << "/";
                filename1 << captureName.toStdString().c_str() << "-camNo" << camNo+1 << "-ImgNo" << ImgNo << ".tiff";  //<< camInfo.serialNumber

                vector<int> compression_params;
                compression_params.push_back(CV_IMWRITE_PXM_BINARY);

                unsigned int rowBytes = (double)convertedImage1.GetReceivedDataSize()/(double)convertedImage1.GetRows();
                cv::Mat image_raw = cv::Mat(convertedImage1.GetRows(), convertedImage1.GetCols(), CV_8UC3, convertedImage1.GetData(), rowBytes);
//                imwrite(filename1.str().c_str(), image_raw);


                // Create a converted image
                Image convertedImage;

                // Get pixel format,etc...
//                cout << "Default Output Format " << rawImage.GetDefaultOutputFormat() << endl;
                cout << "BitsPerPixel " << rawImage.DetermineBitsPerPixel(rawImage.GetDefaultOutputFormat()) << endl;
//                cout << "Current Pixel Format " << rawImage.GetPixelFormat() << " PIXEL_FORMAT_RAW8: " << PIXEL_FORMAT_RAW8 << endl;
                GetPixelFormat(&rawImage);
                GetPixelFormat2(rawImage.GetDefaultOutputFormat());


                // Convert the raw image
//                error = rawImage.Convert( PIXEL_FORMAT_RAW8, &convertedImage );
                error = rawImage.Convert( PIXEL_FORMAT_BGR, &convertedImage );
//                error = rawImage.Convert(&convertedImage );
                if (error != PGRERROR_OK)
                {
                    PrintError( error );
                     cout << "\nError 6 From camera" << i << "\n";
                    return;
                }

                // Display format of current image.
//                GetPixelFormat(&convertedImage);
                // Create a unique filename

                ostringstream filename;
                filename << "./" << captureName.toStdString().c_str() << "/";
                filename << captureName.toStdString().c_str() << "-camNo" << camNo+1 << "-ImgNo" << ImgNo << "." << captureFormat.toStdString().c_str();  //<< camInfo.serialNumber

                // Save the image. If a file format is not passed in, then the file
                // extension is parsed to attempt to determine the file format.
                error = convertedImage.Save( filename.str().c_str());
//                error = convertedImage.Save( filename.str().c_str(), RAW);

                if (error != PGRERROR_OK)
                {
                    PrintError( error );
                         cout << "\nError 7 From camera" << i << "\n";
                    return;
                }
            }

            // Stop capturing images
           // waitKey(100);
            error = cam[i].StopCapture();
            if (error != PGRERROR_OK)
            {

                PrintError( error );
                 cout << "\nError 8 From camera" << i << "\n";
//                return;
            }


        }
    }

        // Disconnect the cameras
    for (unsigned int i=0; i < numCameras; i++){


        error = cam[i].Disconnect();
        if (error != PGRERROR_OK)
        {
             cout << "\nError 9 From camera" << i << "\n";
            PrintError( error );
            return;
        }
    }

   // waitKey(500);
    destroyWindow("Display window");
    cout << "Done! Press Enter to exit..." << endl;
    // cin.ignore();

    return;
}

