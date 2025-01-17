#ifndef AWARDSDIALOG_H
#define AWARDSDIALOG_H

#include <QDialog>
#include <QSqlQueryModel>
#include <QComboBox>
#include "models/AwardsTableModel.h"
#include "models/SqlListModel.h"

namespace Ui {
class AwardsDialog;
}

class AwardsDialog : public QDialog
{
    Q_OBJECT

public:
    explicit AwardsDialog(QWidget *parent = nullptr);
    ~AwardsDialog();
public slots:
    void refreshTable(int);
    void awardTableDoubleClicked(QModelIndex);

signals:
    void AwardConditionSelected(QString, QString, QString);

private:
    Ui::AwardsDialog *ui;
    AwardsTableModel *detailedViewModel;
    SqlListModel* entityCallsignModel;

    QString getSelectedEntity();
    QString getSelectedAward();
};

#endif // AWARDSDIALOG_H
