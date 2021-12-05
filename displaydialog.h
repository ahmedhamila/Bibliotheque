#ifndef DISPLAYDIALOG_H
#define DISPLAYDIALOG_H

#include <QDialog>
#include <QTableView>
#include <QItemDelegate>
#include <QStandardItemModel>
namespace Ui {
class DisplayDialog;
}

class DisplayDialog : public QDialog
{
    Q_OBJECT

public:
    explicit DisplayDialog(QWidget *parent = nullptr);
    ~DisplayDialog();

private:
    Ui::DisplayDialog *ui;
    QStandardItemModel *model;
};

#endif // DISPLAYDIALOG_H
