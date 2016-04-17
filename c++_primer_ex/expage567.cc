/**************************************************************************
 *
 * Copyright (c) 2014 Nibirutech, Inc. All Rights Reserved
 * www.Nibirutech.com
 *
 * @file: expage567.cc
 * @author: Huang Qiyu
 * @email: huangqiyu@chukong-inc.com
 * @date: 03-19-2016 20:27:53
 * @version $Revision$
 *
 **************************************************************************/

#include <iostream>
#include <string>

using namespace std;

class QueryBase {

protected:
    string strExp;

protected:
    virtual ~QueryBase() = default;

    virtual
};

class Query {

public:
    Query(const string& s) : q(make_shared<WordQuery>(s) {}
    ~Query() = default;

private:
    shared_ptr<QueryBase*> q;

};

int main() {
    return 0;
}
