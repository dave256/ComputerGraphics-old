//
//  DemoRenderer.cpp
//  ComputerGraphics
//
//  Created by David M. Reed on 1/28/20.
//  Copyright © 2020 David M Reed. All rights reserved.
//

#include "DemoRenderer.hpp"

DemoRenderer::DemoRenderer(std::string windowTitle, int width, int height, std::string filename): Renderer(windowTitle, width, height) {
    std::vector<Point3D> pts;

    // draw a blue square in top left corner
    pts.clear();
    for (int y=270; y<540; ++y) {
        for (int x=0; x<270; ++x) {
            pts.push_back(Point3D(float(x), float(y), 0.0));
        }
    }
    addPoints(pts, Color(0, 0, 1));

    // draw a red square over part of the blue square
    pts.clear();
    for (int y=270 + 135 / 2; y<540 - 135 / 2; ++y) {
        for (int x=135 / 2; x<270 - 135 / 2; ++x) {
            pts.push_back(Point3D(float(x), float(y), 0.0));
        }
    }
    addPoints(pts, Color(255, 0, 0));

    pts.clear();
    // draw two green points near right edge of screen near bottom and top
    pts.push_back(Point3D(width - 10, 20));
    pts.push_back(Point3D(width - 10, height - 20));
    addPoints(pts, Color(0, 1, 0), 5);

    // set up transform to translate -1 to 1
    float halfWidth = width / 2.0;
    float halfHeight = height/ 2.0;
    mat4 transform = Translate(halfWidth, halfHeight, 0) * Scale(halfWidth, halfHeight, 1);

    // draw a blue line from bottom left corner to top right corner
    Point3D p1, p2;
    p1.set(-1.0, -1.0);
    p2.set(1.0, 1.0);
    std::vector<Line3D> lines;
    lines.push_back(Line3D(p1, p2));
    addLines(lines, Color(0, 0, 1), transform);

    // draw a white square in middle of screen
    pts.clear();
    pts.push_back(Point3D(halfWidth - 10, halfHeight - 10));
    pts.push_back(Point3D(halfWidth - 10, halfHeight + 10));
    pts.push_back(Point3D(halfWidth + 10, halfHeight + 10));
    pts.push_back(Point3D(halfWidth + 10, halfHeight - 10));
    addPolyLine(pts, Color(1, 1, 1));

    // add three colored points of size 10 near bottom center of screen
    std::vector<ColoredPoint3D> coloredPts;
    coloredPts.clear();
    coloredPts.push_back(ColoredPoint3D( halfWidth - 20,  10.0, 0.0,   1, 0, 0));
    coloredPts.push_back(ColoredPoint3D( halfWidth     ,  10.0, 0.0,   0, 1, 0));
    coloredPts.push_back(ColoredPoint3D( halfWidth + 20,  10.0, 0.0,   0, 0, 1));
    addColoredPoints(coloredPts, 10);
}
