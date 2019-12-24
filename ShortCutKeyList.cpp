#include "ShortCutKeyList.h"

ShortCutKeyList::ShortCutKeyList(QObject *parent) : QObject(parent)
{

}
ShortCutKey * ShortCutKeyList::getShortCutByID(QString ScID)
{
    foreach (ShortCutKey *indexShortCut, mShortCutKeyList) {
        if (indexShortCut->keyID==ScID)
        {
            return indexShortCut;
        }

    }
    return nullptr;
}
ShortCutKey * ShortCutKeyList::getShortCutByName(QString Scname)
{

    foreach (ShortCutKey *indexShortCut, mShortCutKeyList) {
        if (indexShortCut->KeyName==Scname)
        {
            return indexShortCut;
        }

    }
    return nullptr;
}
//bool ShortCutKeyList::searchShortCutByID(QString mscID)
//{

//}
//bool ShortCutKeyList::searchshortCutByName(QString sCname)
//{

//}
void ShortCutKeyList::addShortCutToList(ShortCutKey *mshortCutKey)
{

    if (getShortCutByID( mshortCutKey->keyID)!=nullptr)
    {
        mShortCutKeyList.append(mshortCutKey);
    }

}
ShortCutKeyList::~ShortCutKeyList()
{
   foreach(ShortCutKey *indexShortCut,mShortCutKeyList)
   {
       delete  indexShortCut;

   }
   mShortCutKeyList.clear();
}
