//
// Created by erianliang on 19-7-17.
//

#include <iostream>
#include "idset.h"
using namespace std;

void copySetTo(SetOfID *dest, const SetOfID *src) {
    dest->clear();
    for (auto id : *src) {
        dest->insert(id);
    }
}

SetOfID *setMinus(const SetOfID &a, const SetOfID &b) {
    SetOfID *result = nullptr;
    result = new SetOfID;
    for (auto it: a) {
        if (b.find(it) == b.end()) result->insert(it);
    }
    return result;
}


int setMinusTo(SetOfID *a, const SetOfID &b) {
    SetOfID *r = setMinus(*a, b);
    copySetTo(a, r);
    delete r;
    return a->size();
}

SetOfID *setUnion(const SetOfID &a, const SetOfID &b) {
    SetOfID *result = nullptr;
    result = new SetOfID;

    copySetTo(result, &a);
    for (auto it: b) {
        if (result->find(it) == result->end()) result->insert(it);
    }
    return result;
}

int setUnionTo(SetOfID *a, const SetOfID &b) {
    SetOfID *r = setUnion(*a, b);
    copySetTo(a, r);
    delete r;
    return a->size();
}

SetOfID *setIntersect(const SetOfID &a, const SetOfID &b) {
    SetOfID *result = nullptr;
    result = new SetOfID;
    for (auto it: a) {
        if (b.find(it) != b.end()) result->insert(it);
    }
    return result;
}

int setIntersectTo(SetOfID *a, const SetOfID &b) {
    SetOfID *r = setIntersect(*a, b);
    copySetTo(a, r);
    delete r;
    return a->size();
}
