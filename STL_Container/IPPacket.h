//
// Created by lianlian on 17-7-24.
//

#pragma once
class IPPacket{
public:
    IPPacket(int id): mID(id){

    }
    int getID()const {
        return mID;
    }
private:
    int mID;
};

