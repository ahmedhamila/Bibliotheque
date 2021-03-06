#ifndef IMAGELABEL_H
#define IMAGELABEL_H

#include <QWidget>
#include <QLabel>
namespace Ui {
class ImageLabel;
}

class ImageLabel : public QWidget
{
    Q_OBJECT

public:
    explicit ImageLabel(QWidget *parent = 0);
    const QPixmap pixmap() const;

public slots:
    void setPixmap(const QPixmap&);

protected:
    void resizeEvent(QResizeEvent *);

private slots:
    void resizeImage();

private:
    QLabel *label;
};

#endif // IMAGELABEL_H
