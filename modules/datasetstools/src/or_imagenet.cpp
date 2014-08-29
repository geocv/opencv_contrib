/*M///////////////////////////////////////////////////////////////////////////////////////
//
//  IMPORTANT: READ BEFORE DOWNLOADING, COPYING, INSTALLING OR USING.
//
//  By downloading, copying, installing or using the software you agree to this license.
//  If you do not agree to this license, do not download, install,
//  copy or use the software.
//
//
//                           License Agreement
//                For Open Source Computer Vision Library
//
// Copyright (C) 2014, Itseez Inc, all rights reserved.
// Third party copyrights are property of their respective owners.
//
// Redistribution and use in source and binary forms, with or without modification,
// are permitted provided that the following conditions are met:
//
//   * Redistribution's of source code must retain the above copyright notice,
//     this list of conditions and the following disclaimer.
//
//   * Redistribution's in binary form must reproduce the above copyright notice,
//     this list of conditions and the following disclaimer in the documentation
//     and/or other materials provided with the distribution.
//
//   * The name of the copyright holders may not be used to endorse or promote products
//     derived from this software without specific prior written permission.
//
// This software is provided by the copyright holders and contributors "as is" and
// any express or implied warranties, including, but not limited to, the implied
// warranties of merchantability and fitness for a particular purpose are disclaimed.
// In no event shall the Itseez Inc or contributors be liable for any direct,
// indirect, incidental, special, exemplary, or consequential damages
// (including, but not limited to, procurement of substitute goods or services;
// loss of use, data, or profits; or business interruption) however caused
// and on any theory of liability, whether in contract, strict liability,
// or tort (including negligence or otherwise) arising in any way out of
// the use of this software, even if advised of the possibility of such damage.
//
//M*/

#include "opencv2/util.hpp"
#include "opencv2/or_imagenet.hpp"

#include <cstdio>
#include <cstdlib> // atoi

#include <fstream>

namespace cv
{
namespace datasetstools
{

using namespace std;

or_imagenet::or_imagenet(std::string &path)
{
    loadDataset(path);
}

void or_imagenet::load(string &path, unsigned int number)
{
    if (number!=0)
    {
        return;
    }

    loadDataset(path);
}

void or_imagenet::loadDataset(string &path)
{
    ifstream infile((path + "fall11_urls.txt").c_str());
    string line;
    while (getline(infile, line))
    {
        vector<string> elems;
        split(line, elems, '\t');

        objectImagenet curr;
        curr.imageUrl = elems[1];

        string id(elems[0]);
        elems.clear();
        split(id, elems, '_');

        curr.wnid = elems[0];
        curr.id2 = atoi(elems[1].c_str());

        wnids.insert(curr.wnid);

        train.push_back(curr);
    }
}

}
}
