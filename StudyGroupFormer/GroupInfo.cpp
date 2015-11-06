#include "GroupInfo.h"
#include "ui_groupinfo.h"

#include "HTTPInterface.h"
#include "AppWindow.h"

GroupInfo::GroupInfo(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::GroupInfo)
{
    ui->setupUi(this);
    this->setFixedSize(600, 600);
    displayGroupInfo();

}

void GroupInfo::displayGroupInfo()
{
    //grab the group info
     QJsonObject groupInfo = getStudyGroup("1");

     //parse the info
     QString groupId = QString::number(groupInfo["id"].toInt());
     QString groupDep = groupInfo["department"].toString();
     QString groupNum = QString::number(groupInfo["class_number"].toInt());
     QString groupCreated = groupInfo["created_at"].toString();
     QString groupUpdated = groupInfo["updated_at"].toString();
     QString groupDate = groupInfo["date"].toString();
     QString groupTime = groupInfo["time"].toString();

     ui->lblGID->setText(groupId);
     ui->lblGCName->setText(groupDep + " " + groupNum);
     ui->lblGCreated->setText(groupCreated);
     ui->lblGUpdated->setText(groupUpdated);
     ui->lblGDate->setText(groupDate);
     ui->lblGTime->setText(groupTime);
}

GroupInfo::~GroupInfo()
{
    delete ui;
}
