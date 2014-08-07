/**************************************************************************
 *
 * Copyright (c) 2014 Nibirutech, Inc. All Rights Reserved
 * www.Nibirutech.com
 * 
 * @file: ex2_33.cpp
 * @author: Huang Qiyu
 * @email: huangqiyu@chukong-inc.com
 * @date: 08-05-2014 08:57:37
 * @version $Revision$
 *
 **************************************************************************/


int main() {
    int i = 0, &r = i;
    auto a = r; 

    const int ci = i, &cr = ci;

    auto b = ci;
    auto c = cr;
    auto d = &i;
    auto e = &ci;
    auto &g = ci;

    a = 42; 
    b = 42;
    c = 42;
    d = 42;
    e = 42;
    g = 42;

    return 0;
}
