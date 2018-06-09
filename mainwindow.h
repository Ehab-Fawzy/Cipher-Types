#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_CaesarCipher_clicked();

    void on_CaesarDecipher_clicked();

    void on_Clear_clicked();

    void on_AtbashCipher_clicked();


    void on_AtbashDecipher_clicked();

    void on_Rot13Cipher_clicked();

    void on_ROT13Decipher_clicked();

    void on_BaconianCipher_clicked();

    void on_BaconianDecipher_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
