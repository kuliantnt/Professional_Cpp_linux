//
// Created by lianlian on 17-7-27.
//

#ifndef STL_CONTAINER_DATA_H
#define STL_CONTAINER_DATA_H


class Data {
public:
    explicit Data(int val = 0){
        mVal = val;
    }
    int getVal() const {
        return mVal;
    }
    void setVal(int val){
        mVal = val;
    }
private:
    int mVal;
};


#endif //STL_CONTAINER_DATA_H
