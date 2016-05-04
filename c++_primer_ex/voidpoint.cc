/**************************************************************************
 *
 * Copyright (c) 2015 Cheeray Huang. All Rights Reserved
 *
 * @file: voidpoint.cc
 * @author: Huang Qiyu
 * @email: cheeray.huang@gmail.com
 * @date: 05-04-2016 11:53:00
 * @version $Revision$
 *
 **************************************************************************/


int main() {

    int i;

    void *p = &i;

    int *j = static_cast<int*>(p);

    return 0;
}
