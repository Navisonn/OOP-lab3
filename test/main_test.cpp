#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <sstream>
#include <vector>
#include "../include/Figure.h"
#include "../include/Rhombus.h"
#include "../include/Pentagon.h"
#include "../include/Hexagon.h"
#include "../include/Array.h"

TEST(FigureTest, GeometricCenter) {
    Rhombus r;
    std::vector<Coord> verts = {{0,0}, {1,1}, {2,0}, {1,-1}};
    r = Rhombus(); 
    std::stringstream ss;
    ss << "0 0 1 1 2 0 1 -1";
    ss >> r;
    Coord center = r.geometricCenter();
    EXPECT_DOUBLE_EQ(center.x, 1.0);
    EXPECT_DOUBLE_EQ(center.y, 0.0);
}

TEST(FigureTest, Area) {
    Rhombus r;
    std::stringstream ss;
    ss << "0 0 2 0 2 2 0 2";
    ss >> r;
    double a = r.area();
    EXPECT_DOUBLE_EQ(a, 4.0);
    double cast_a = static_cast<double>(r);
    EXPECT_DOUBLE_EQ(cast_a, 4.0);
}

TEST(FigureTest, Print) {
    Rhombus r;
    std::stringstream ss_in;
    ss_in << "0 0 1 0 1 1 0 1";
    ss_in >> r;
    std::stringstream ss_out;
    ss_out << r;
    EXPECT_EQ(ss_out.str(), "(0,0) (1,0) (1,1) (0,1) ");
}

TEST(FigureTest, Equals) {
    Rhombus r1, r2;
    std::stringstream ss1;
    ss1 << "0 0 1 0 1 1 0 1";
    ss1 >> r1;
    std::stringstream ss2;
    ss2 << "0 0 1 0 1 1 0 1";
    ss2 >> r2;
    EXPECT_TRUE(r1 == r2);
    EXPECT_TRUE(r1.equals(r2));
    std::stringstream ss3;
    ss3 << "0 0 2 0 2 2 0 2";
    ss3 >> r2;
    EXPECT_FALSE(r1 == r2);
    Pentagon p;
    std::stringstream ss_p;
    ss_p << "0 0 1 0 1 1 0 1 0.5 0.5";
    ss_p >> p;
    EXPECT_FALSE(r1 == p);
}

TEST(RhombusTest, Read) {
    Rhombus r;
    std::stringstream ss;
    ss << "0 0 1 1 2 0 1 -1";
    ss >> r;
    const auto& verts = r.getVertices();
    ASSERT_EQ(verts.size(), 4u);
    EXPECT_DOUBLE_EQ(verts[0].x, 0.0);
    EXPECT_DOUBLE_EQ(verts[0].y, 0.0);
    EXPECT_DOUBLE_EQ(verts[1].x, 1.0);
    EXPECT_DOUBLE_EQ(verts[1].y, 1.0);
    EXPECT_DOUBLE_EQ(verts[2].x, 2.0);
    EXPECT_DOUBLE_EQ(verts[2].y, 0.0);
    EXPECT_DOUBLE_EQ(verts[3].x, 1.0);
    EXPECT_DOUBLE_EQ(verts[3].y, -1.0);
}

TEST(PentagonTest, Read) {
    Pentagon p;
    std::stringstream ss;
    ss << "0 0 1 0 1.5 0.5 1 1 0 1";
    ss >> p;
    const auto& verts = p.getVertices();
    ASSERT_EQ(verts.size(), 5u);
}

TEST(HexagonTest, Read) {
    Hexagon h;
    std::stringstream ss;
    ss << "0 0 1 0 1.5 0.5 1 1 0 1 -0.5 0.5";
    ss >> h;
    const auto& verts = h.getVertices();
    ASSERT_EQ(verts.size(), 6u);
}

TEST(ArrayTest, AddAndAccess) {
    Array arr;
    Rhombus* r = new Rhombus();
    std::stringstream ss;
    ss << "0 0 1 0 1 1 0 1";
    ss >> *r;
    arr.add(r);
    ASSERT_EQ(arr.size(), 1u);
    EXPECT_EQ(arr[0], r);
    Pentagon* p = new Pentagon();
    std::stringstream ss_p;
    ss_p << "0 0 1 0 1 1 0 1 0.5 0.5";
    ss_p >> *p;
    arr.add(p);
    ASSERT_EQ(arr.size(), 2u);
}

TEST(ArrayTest, Remove) {
    Array arr;
    Rhombus* r1 = new Rhombus();
    std::stringstream ss1;
    ss1 << "0 0 1 0 1 1 0 1";
    ss1 >> *r1;
    arr.add(r1);
    Rhombus* r2 = new Rhombus();
    std::stringstream ss2;
    ss2 << "2 2 3 2 3 3 2 3";
    ss2 >> *r2;
    arr.add(r2);
    arr.remove(0);
    ASSERT_EQ(arr.size(), 1u);
    std::stringstream ss_out;
    ss_out << *arr[0];
    EXPECT_EQ(ss_out.str(), "(2,2) (3,2) (3,3) (2,3) ");
}

TEST(ArrayTest, TotalArea) {
    Array arr;
    Rhombus* r = new Rhombus();
    std::stringstream ss_r;
    ss_r << "0 0 2 0 2 2 0 2";
    ss_r >> *r;
    arr.add(r); 
    Pentagon* p = new Pentagon();
    Rhombus* r2 = new Rhombus();
    std::stringstream ss_r2;
    ss_r2 << "0 0 1 0 1 1 0 1";
    ss_r2 >> *r2; 
    arr.add(r2);
    double total = 0.0;
    for (size_t i = 0; i < arr.size(); ++i) {
        total += static_cast<double>(*arr[i]);
    }
    EXPECT_DOUBLE_EQ(total, 5.0);
}

TEST(CoordTest, StreamOperators) {
    Coord c;
    std::stringstream ss;
    ss << "3.14 2.718";
    ss >> c;
    EXPECT_DOUBLE_EQ(c.x, 3.14);
    EXPECT_DOUBLE_EQ(c.y, 2.718);
    std::stringstream ss_out;
    ss_out << c;
    EXPECT_EQ(ss_out.str(), "(3.14,2.718)");
}
