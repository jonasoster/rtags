#ifndef RBuild_p_h
#define RBuild_p_h

#include "CursorKey.h"
#include "AtomicString.h"
#include <QList>
#include <QHash>

struct RBuildPrivate
{
    RBuildPrivate() {}
    ~RBuildPrivate() { qDeleteAll(data); }

    struct DataEntry {
        DataEntry() : hasDefinition(false) {}

        bool hasDefinition;
        Cursor cursor;
        Cursor reference;
        QSet<Cursor> references;
    };

    struct Dependencies {
        Path file;
        GccArguments arguments;
        time_t lastModified;
        QHash<Path, time_t> dependencies;
    };
    QHash<QByteArray, DataEntry*> seen;
    QList<DataEntry*> data;
    QList<Dependencies> dependencies;
};

static inline QDataStream &operator<<(QDataStream &ds, const RBuildPrivate::DataEntry &entry)
{
    ds << entry.hasDefinition << entry.cursor << entry.reference << entry.references;
    return ds;
}

static inline QDataStream &operator>>(QDataStream &ds, RBuildPrivate::DataEntry &entry)
{
    ds >> entry.hasDefinition >> entry.cursor >> entry.reference >> entry.references;
    return ds;
}



#endif