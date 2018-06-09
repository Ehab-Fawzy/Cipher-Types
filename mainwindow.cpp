#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QString>
#include <qmath.h>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

QString Binary( int x ){

    QString output = "";
    while ( x != 0 ){
        int rem = x % 2;
        x /= 2;
        if      ( rem == 0 ){ output = "a" + output; }
        else if ( rem == 1 ){ output = "b" + output; }
    }
    for ( int i = output.length(); i < 7; i++ ){
        output = "a" + output;
    }
    return output;
}

int Decipher( QString x ){
    int pw = 0 , output = 0;
    for ( int i = x.length() - 1; i >= 0; i-- ){
        if ( x.at( i ) == 'b' ){
            output += pow( 2 , pw );
        }
        pw++;
    }
    return output;
}

void MainWindow::on_Clear_clicked()
{
    ui->Input->clear();
    ui->Output->clear();
}

void MainWindow::on_CaesarCipher_clicked()
{
    QString cipher = ui->Input->toPlainText() , output = "" ;
    const int key = 3; int ascii = 0;
    for ( int i = 0; i < cipher.length(); i++ ){
        ascii = 0;
        ascii = cipher.at( i ).toLatin1();
        ascii += key;
        if      ( ascii - key >= 65 && ascii - key <= 90  && ascii < 65 ){ ascii -= 26; }
        else if ( ascii - key >= 97 && ascii - key <= 122 && ascii < 97 ){ ascii -= 26; }
        output += ascii;
    }
    ui->Output->setText( output );
}

void MainWindow::on_CaesarDecipher_clicked()
{
    QString cipher = ui->Input->toPlainText() , output = "" ;
    const int key = 3; int ascii = 0;
    for ( int i = 0; i < cipher.length(); i++ ){
        ascii = 0;
        ascii = cipher.at( i ).toLatin1();
        ascii -= key;
        if      ( ascii + key <= 65 && ascii + key >= 90  && ascii < 65 ){ ascii += 26; }
        else if ( ascii + key <= 97 && ascii + key >= 122 && ascii < 97 ){ ascii += 26; }
        output += ascii;
    }
    ui->Output->setText( output );
}

void MainWindow::on_AtbashCipher_clicked()
{
    int ascii = 0; QString output = "";
    QString cipher = ui->Input->toPlainText();
    for ( int i = 0; i < cipher.length(); i++ ){

        ascii = 0;
        ascii = cipher.at( i ).toLatin1();

        if      ( ascii >= 65 and ascii <= 90  ){
            output += ( 90 - (ascii - 65) );
        }
        else if ( ascii >= 97 and ascii <= 122 ){
            output += ( 122 - (ascii - 97) );
        }
        else{
            output += cipher.at( i );
        }

    }
    ui->Output->setText( output );
}

void MainWindow::on_AtbashDecipher_clicked()
{
    on_AtbashCipher_clicked();
}

void MainWindow::on_Rot13Cipher_clicked()
{
    const int key = 13;
    int ascii = 0; QString output = "";
    QString cipher = ui->Input->toPlainText();
    for ( int i = 0; i < cipher.length(); i++ ){

        ascii = 0;
        ascii = cipher.at( i ).toLatin1();
        if      ( (ascii >= 65 && ascii <= 77) || ( ascii >= 97  && ascii <= 109 ) ){ ascii += key; }
        else if ( (ascii >= 78 && ascii <= 90) || ( ascii >= 110 && ascii <= 122 ) ){ ascii -= key; }
        output += ascii;

    }
    ui->Output->setText( output );
}

void MainWindow::on_ROT13Decipher_clicked()
{
    on_Rot13Cipher_clicked();
}

void MainWindow::on_BaconianCipher_clicked()
{
    int ascii = 0; QString output = "";
    QString cipher = ui->Input->toPlainText();
    for ( int i = 0; i < cipher.length(); i++ ){

        ascii = 0;
        ascii = cipher.at( i ).toLatin1();
        output += Binary( ascii );
    }
    ui->Output->setText( output );
}

void MainWindow::on_BaconianDecipher_clicked()
{
    int ascii = 0; QString output = "" , temp = "" ;
    QString cipher = ui->Input->toPlainText();

    for ( int i = 0; i < cipher.length(); i += 7 ){
        temp = "";
        for ( int j = 0; j < 7; j++ ){ temp += cipher.at( i+j ); }
        ascii   = Decipher( temp );
        output += ascii;
    }
    ui->Output->setText( output );
}
