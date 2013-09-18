#ifndef __DP5COMBREGCLIENT_H__
#define __DP5COMBREGCLIENT_H__

#include <vector>
#include <string>   
    
#include <Pairing.h>
#include "dp5params.h"  


class DP5CombinedRegClient : public DP5Params {
public:
    // The constructor consumes the client's BLS private key
    DP5CombinedRegClient(const unsigned char bls_privkey[BLS_PRIVKEY_BYTES],
        const unsigned char prekey[PREKEY_BYTES]);

    // Register yourself as visible. Return 0 on success, in which case msgtosend will be
    // filled with the message to send to the registration server.
    // Return non-zero on error.
    int start_reg(string &msgtosend, 
        unsigned int next_epoch,
        const unsigned char data[DATAPLAIN_BYTES]);
    // Once the above message is sent to the registration server, pass
    // the reply to this function.  Return 0 on success, non-zero on
    // error.
    int complete_reg(const string &replymsg, 
                      unsigned int next_epoch);

private:
    Zr _bls_privkey;
    unsigned char _prekey[PREKEY_BYTES]; 
    const Pairing _pairing;   // FIXME: should be static, no?
};

#endif
