/**************************************************************************
 *
 * Copyright (c) 2014 Nibirutech, Inc. All Rights Reserved
 * www.Nibirutech.com
 * 
 * @file: ex11_8.cc
 * @author: Huang Qiyu
 * @email: huangqiyu@chukong-inc.com
 * @date: 11-07-2014 14:23:52
 * @version $Revision$
 *
 **************************************************************************/

#include <set> 
#include <iostream> 
#include <iterator>

using namespace std; 

int main() {

    istream_iterator<string> is_iter(cin), eof; 

    set<string> s(is_iter, eof);

    ostream_iterator<string> os_iter(cout, " "); 
    copy(s.begin(), s.end(), os_iter);

    *os_iter++ = "\n";

    return 0;
}



