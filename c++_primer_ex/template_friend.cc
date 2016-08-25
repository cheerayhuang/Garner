/**************************************************************************
 *
 * Copyright (c) 2015 Cheeray Huang. All Rights Reserved
 *
 * @file: template_friend.cc
 * @author: Huang Qiyu
 * @email: cheeray.huang@gmail.com
 * @date: 08-25-2016 11:13:38
 * @version $Revision$
 *
 **************************************************************************/


template<typename T> class p1;

template <typename T> class C2 {
    friend class p1<T>;
    template <typename X> friend class p2;
    friend class p3;
};

