#ifndef PREPROCESSOR_H
#define PREPROCESSOR_H

#include <rct/Path.h>
#include <rct/List.h>
#include <rct/String.h>
#include <rct/EventReceiver.h>
#include "RTags.h"

class Connection;
class Process;
class Preprocessor : public EventReceiver
{
public:
    Preprocessor(const SourceInformation &args, uint8_t buildIndex, Connection *connection);
    ~Preprocessor();

    void preprocess();

private:
    void onProcessFinished();

private:
    const SourceInformation mArgs;
    const uint8_t mBuildIndex;
    Connection *mConnection;

    Process *mProc;
};

#endif
