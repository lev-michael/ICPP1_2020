#pragma once
#ifndef ICOMPARABLE_H
#define ICOMPARABLE_H
#include "IObject.h"


class IComparable: IObject {
	virtual int compareTo(IComparable* obj) const = 0;

};

#endif 
