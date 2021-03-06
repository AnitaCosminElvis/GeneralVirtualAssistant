/***************************************************************************
                          aimlparser.h  -  description
                             -------------------
    begin                : mer sep 21 2005
    copyright            : (C) 2005 by houssem bdioui
    email                : houssem.bdioui@gmail.com
 ***************************************************************************/

/***************************************************************************
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 ***************************************************************************/

#ifndef AIMLPARSER_H
#define AIMLPARSER_H

#include <QDomNode>
#include <QMap>
#include <QList>
#include <QStringList>
#include <QRegExp>
#include <QObject>

#define MAX_LIST_LENGTH 50
#define MAX_RECURSION   50

class QTextStream;
class QTcpServer;

/**
  *@author houssem bdioui
  */

struct Node;

struct Leaf
{
    Node *parent;
    QDomNode tmplate;
    QString topic;
    QString that;
    Leaf();
};

struct Node
{
    Node *parent;
    QString word;
    QList<Node*> childs;
    QList<Leaf*> leafs;
    Node();
    ~Node();
    void clear();
    bool match(QStringList::const_iterator, const QStringList&,
               const QString&, const QString&, QStringList &, QStringList &, Leaf *&);
};

class AIMLParser : public QObject
{
    Q_OBJECT
public:
    AIMLParser();
    virtual ~AIMLParser();
    void clear();
    bool loadAiml(const QString&);
    bool loadAIMLSet(const QString &);
    QString getResponse(QString, const bool & = false);
    QString getAIMLSetDirectory() const;
private:
    bool loadSubstitutions(const QString&);
    bool loadVars(const QString&, const bool&);
    bool saveVars(const QString &);
    QString resolveNode(QDomNode*, const QStringList & = QStringList(),
                        const QStringList & = QStringList(), const QStringList & = QStringList());
    void parseCategory(QDomNode*);
    void normalizeString(QString &);
private:
    QMap<QString, QString> parameterValue;
    QMap<QString, QString> botVarValue;
    QList<QRegExp> subOld;
    QStringList subNew;
    QStringList inputList;
    QList<QStringList> thatList;
    Node root;
    int indent;
    QString currentPath;
signals:
    void aboutToLoadAIMLFile(const QString&);
};

#endif
