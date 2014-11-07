<<<<<<< HEAD
/**************************************************************************
 *
 * Copyright (c) 2014 Nibirutech, Inc. All Rights Reserved
 * www.Nibirutech.com
 * 
 * @file: lambda.cc
 * @author: Huang Qiyu
 * @email: huangqiyu@chukong-inc.com
 * @date: 11-06-2014 11:33:25
 * @version $Revision$
 *
 **************************************************************************/

#include <iostream> 
#include <functional>

using namespace std; 

auto func(int i) -> function<void()> {

    return [&] {cout << i << endl;};
}

int main() {

    int k;
    
    auto f = [k] {int j = 1+1; return k;};

    //cout << f() << endl;

    auto f1 = func(10);

    f1();

    f1 = func(100);

    f1();

    return 0;
}

