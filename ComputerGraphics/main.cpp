//
//  main.cpp
//  
//
//  Created by David M. Reed on 2/18/15.
//  Copyright (c) 2015 David Reed. All rights reserved.
//

#include <iostream>
#include <string>

using std::cout;
using std::cin;
using std::cerr;
using std::endl;
using std::string;

#include "graphics.hpp"
#include "DemoRenderer.hpp"

//----------------------------------------------------------------------

int main(int argc, const char * argv[]) {

    string filename;
    if (argc == 2) {
        filename = string(argv[1]);
    }
    else {
        filename = "/path/to/file/on/your/computer/in.txt";
    }

    // create the class
    Renderer *renderer = new DemoRenderer("Demo", 960, 540, filename);

    // and enter the run loop
    renderer->runLoop();
}
