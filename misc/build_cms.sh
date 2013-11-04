#!/bin/bash

#versions="RB-8.4.4 RB-8.4.5 RB-9.1.0"
versions="RB-8.4.4"
cubrid_svn_url=http://svn.bds.nhncorp.com/xdbms/cubrid/branches/
cms_svn_url=http://svn.bds.nhncorp.com/xdbms/cubrid-manager/branches/ 
platform=$(uname -i)

function svn_checkout_code()
{
    version=$1
    svn checkout $cubrid_svn_url$version "cubrid-"$version
    svn checkout $cms_svn_url$version"/server" "CMS-"$version 
}

function check_cubrid_build_num()
{
   build_num=$(svn info BUILD_NUMBER | grep "Last Changed Rev: ") 
   build_num=${build_num#'Last Changed Rev: '} 
   svn update -r $build_num
}

function build_cubrid()
{
    #compile cubrid
    cd "cubrid-"$version
    check_cubrid_build_num
    build_ver=$(cat BUILD_NUMBER)
    sh ./autogen.sh 
    if [ -f "Makefile" ];
    then 
        make distclean
    fi 
    ./configure $cubrid_prefix || exit 1
    make || exit 1
    make install || exit 1 
    cd ..
}

function build_CMS()
{
    #compile cms
    cd "CMS-"$version 
    sh ./autogen.sh
    if [ -f "Makefile" ]; 
    then
        make distclean
    fi
    ./configure $cms_prefix --with-cubrid-dir=$HOME/jenkins/cubrid
    make -j || exit 1
    make install || exit 1
}

function package_CMS()
{
    cms_pkg_name="CUBRID_Manager_Server-${version#RB-}.$build_ver-linux-$platform.tar.gz"
    tar -cvzf $cms_pkg_name build
    cp $cms_pkg_name ../../cms_builds/
    cd ../../
}

function get_prefix()
{
    cubrid_prefix="--prefix="$HOME"/jenkins/cubrid/"
    cms_prefix="--prefix="$(pwd)"/CMS-"$version"/build"
    if [ "$platform" = "x86_64" ]; 
    then
        cubrid_prefix=$cubrid_prefix" --enable-64bit" 
        cms_prefix=$cms_prefix" --enable-64bit"
    fi
}

function main()
{
    for version in $versions;
    do
        cd $version
        svn_checkout_code "$version"

        if [ -d "$HOME/jenkins/cubrid/" ]; 
        then
            rm -rf ~/jenkins/cubrid/ 
        fi

        if [ -d "./CMS-"$version"/build" ];
        then
            rm -rf "./CMS-"$version"/build"  
        fi

        mkdir ~/jenkins/cubrid/ 
        mkdir "./CMS-"$version"/build"

        get_prefix
        build_cubrid
        build_CMS
        package_CMS 
    done
}

main

