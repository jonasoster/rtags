#ifndef OutputMessage_h
#define OutputMessage_h

#include "ClientMessage.h"
#include <rct/String.h>

class CreateOutputMessage : public ClientMessage
{
public:
    enum { MessageId = CreateOutputId };

    CreateOutputMessage(int level = 0);

    virtual int messageId() const { return MessageId; }

    int level() const;

    String encode() const;
    void fromData(const char *data, int size);

private:
    int mLevel;
};

#endif
