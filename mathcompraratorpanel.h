#ifndef MATHCOMPRARATORPANEL_H
#define MATHCOMPRARATORPANEL_H

#include <panel.h>
#include <QPushButton>
#include <QGraphicsProxyWidget>

enum ComparatorMode {AbiggerThenB, AsmallerThenB, AequalToB};

class MathCompraratorPanel : public Panel
{
public:
    MathCompraratorPanel(int x, int y);
    void initialize() override;
    void setComparatorMode(uint modeCount);
    uint getModeCount();
    void SavePanelToFile(QFile *plik) override;

private:
    Node *InputNode_A;
    Node *InputNode_B;
    Node *OutputNode;

    QPushButton *CompareButton;
    QGraphicsProxyWidget *CompBtn;

    ComparatorMode mode;
    unsigned modeCounter;

    void setNodesNames();
    void updateComparatorMode();
    void updateButtonText();
    void paint(QPainter *painter,
               const QStyleOptionGraphicsItem *option,
               QWidget *widget = nullptr) override;

public slots:
    void changeComparatorMode();

};

#endif // MATHCOMPRARATORPANEL_H
