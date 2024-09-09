#ifndef PLAYING_H
#define PLAYING_H

#include <QWidget>
#include "..\Playing\game.h"
#include "extensions/hexagonlayout.h"
#include <QScrollArea>

#include "extensions/centeredscrollarea.h"

namespace Ui {
class Playing;
}

class Playing : public QWidget
{
    Q_OBJECT

public:
    explicit Playing(bool aiMode,QWidget *parent = nullptr);
    static Playing* instance;
    void addPieceWidgetToPlayerColumn(int playerNum,QWidget* pieceWidget);
    void addWidgetToBoardWidget(Position* position ,QWidget* widget);
    void Iresize();
    ~Playing();

private slots:
    void on_tieBtn_clicked();

private:
    void showEvent(QShowEvent* event) override;
    Ui::Playing *ui;
    Game* mainGame;
    HexagonLayout* boardWidgetLayout;
    QWidget* QSAWidget;
    CenteredScrollArea* csa;
};

#endif // PLAYING_H
