//
//  DemoRenderer.hpp
//  ComputerGraphics
//
//  Created by David M. Reed on 1/28/20.
//  Copyright © 2020 David M Reed. All rights reserved.
//

#ifndef DemoRenderer_hpp
#define DemoRenderer_hpp

#include <string>
#include "graphics.hpp"

class DemoRenderer: public Renderer {

public:
    DemoRenderer(std::string windowTitle, int width, int height, std::string filename);
    
    virtual ~DemoRenderer() noexcept {}
};

#endif /* DemoRenderer_hpp */
