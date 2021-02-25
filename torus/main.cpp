#include <set>
#include <gmsh.h>

int main(int argc, char **argv) {
    gmsh::initialize(argc, argv);
    gmsh::model::add("tor");
    double lc = 0.5;

    gmsh::model::geo::addPoint(0, 0, 0, lc, 0); //center-center
    gmsh::model::geo::addPoint(0, 0, -2, lc, 1);//outer down
    gmsh::model::geo::addPoint(0, 0, 2, lc, 2);//outer up
    gmsh::model::geo::addPoint(0, 0, 1, lc, 3);//inner down
    gmsh::model::geo::addPoint(0, 0, -1, 4);//inner up

    //outer torus
    for (int i = 1; i < 3; i++) {
        gmsh::model::geo::addPoint(i * (12) - 18, 0, 2, lc, 30 + i);// -6 6
        gmsh::model::geo::addPoint(i * (12) - 18, 0, -2, lc, 10 + i);// -6 6
        gmsh::model::geo::addPoint(i * (16) - 24, 0, 0, lc, 20 + i);// -8 8
        gmsh::model::geo::addPoint(i * (8) - 12, 0, 0, lc, 40 + i);// -4 4
        gmsh::model::geo::addPoint(i * (12) - 18, 0, 0, lc, 50 + i);//-6 6


    }

    gmsh::model::geo::addCircleArc(11, 51, 41, 4);
    gmsh::model::geo::addCircleArc(12, 52, 42, 8);

    gmsh::model::geo::addCircleArc(31, 2, 32, 31);
    gmsh::model::geo::addCircleArc(32, 2, 31, 32);

    gmsh::model::geo::addCircleArc(41, 0, 42, 41);
    gmsh::model::geo::addCircleArc(42, 0, 41, 42);

    gmsh::model::geo::addCircleArc(11, 1, 12, 11);
    gmsh::model::geo::addCircleArc(12, 1, 11, 12);

    gmsh::model::geo::addCircleArc(21, 0, 22, 21);
    gmsh::model::geo::addCircleArc(22, 0, 21, 22);

    for (int i = 1; i < 4; i++) {
        gmsh::model::geo::addCircleArc(10 * i + 1, 51, 10 * i + 11, i);
        gmsh::model::geo::addCircleArc(10 * i + 2, 52, 10 * i + 12, i + 4);
    }


    //inner torus
    for (int i = 1; i < 3; i++) {
        gmsh::model::geo::addPoint(i * (12) - 18, 0, 1, lc, 130 + i);// -6 6
        gmsh::model::geo::addPoint(i * (12) - 18, 0, -1, lc, 110 + i);// -6 6
        gmsh::model::geo::addPoint(i * (10) - 15, 0, 0, lc, 120 + i);// -5 5
        gmsh::model::geo::addPoint(i * (14) - 21, 0, 0, lc, 140 + i);// -7 7
    }

    gmsh::model::geo::addCircleArc(111, 51, 141, 104);
    gmsh::model::geo::addCircleArc(112, 52, 142, 108);

    gmsh::model::geo::addCircleArc(131, 3, 132, 131);
    gmsh::model::geo::addCircleArc(132, 3, 131, 132);

    gmsh::model::geo::addCircleArc(141, 0, 142, 141);
    gmsh::model::geo::addCircleArc(142, 0, 141, 142);

    gmsh::model::geo::addCircleArc(111, 4, 112, 111);
    gmsh::model::geo::addCircleArc(112, 4, 111, 112);

    gmsh::model::geo::addCircleArc(121, 0, 122, 121);
    gmsh::model::geo::addCircleArc(122, 0, 121, 122);

    for (int i = 1; i < 4; i++) {
        gmsh::model::geo::addCircleArc(10 * i + 101, 51, 10 * i + 111, 100 + i);
        gmsh::model::geo::addCircleArc(10 * i + 102, 52, 10 * i + 112, i + 104);
    }


    //loop
    gmsh::model::geo::addCurveLoop({1, -11, -5, 21}, 1);
    gmsh::model::geo::addSurfaceFilling({1}, 1);
    gmsh::model::geo::addCurveLoop({1, 12, -5, -22}, 2);
    gmsh::model::geo::addSurfaceFilling({2}, 2);
    gmsh::model::geo::addCurveLoop({4, 41, -8, -11}, 3);
    gmsh::model::geo::addSurfaceFilling({3}, 3);
    gmsh::model::geo::addCurveLoop({4, -42, -8, 12}, 4);
    gmsh::model::geo::addSurfaceFilling({4}, 4);
    gmsh::model::geo::addCurveLoop({2, -21, -6, 31}, 5);
    gmsh::model::geo::addSurfaceFilling({5}, 5);
    gmsh::model::geo::addCurveLoop({2, 22, -6, -32}, 6);
    gmsh::model::geo::addSurfaceFilling({6}, 6);
    gmsh::model::geo::addCurveLoop({3, 41, -7, -31}, 7);
    gmsh::model::geo::addSurfaceFilling({7}, 7);
    gmsh::model::geo::addCurveLoop({3, -42, -7, 32}, 8);
    gmsh::model::geo::addSurfaceFilling({8}, 8);


    gmsh::model::geo::addCurveLoop({101, -111, -105, 121}, 11);
    gmsh::model::geo::addSurfaceFilling({11}, 11);
    gmsh::model::geo::addCurveLoop({101, 112, -105, -122}, 12);
    gmsh::model::geo::addSurfaceFilling({12}, 12);
    gmsh::model::geo::addCurveLoop({104, 141, -108, -111}, 13);
    gmsh::model::geo::addSurfaceFilling({13}, 13);
    gmsh::model::geo::addCurveLoop({104, -142, -108, 112}, 14);
    gmsh::model::geo::addSurfaceFilling({14}, 14);
    gmsh::model::geo::addCurveLoop({102, -121, -106, 131}, 15);
    gmsh::model::geo::addSurfaceFilling({15}, 15);
    gmsh::model::geo::addCurveLoop({102, 122, -106, -132}, 16);
    gmsh::model::geo::addSurfaceFilling({16}, 16);
    gmsh::model::geo::addCurveLoop({103, 141, -107, -131}, 17);
    gmsh::model::geo::addSurfaceFilling({17}, 17);
    gmsh::model::geo::addCurveLoop({103, -142, -107, 132}, 18);
    gmsh::model::geo::addSurfaceFilling({18}, 18);


    gmsh::model::geo::addSurfaceLoop({1, 2, 3, 4, 5, 6, 7, 8}, 1);
    gmsh::model::geo::addSurfaceLoop({11, 12, 13, 14, 15, 16, 17, 18}, 2);
    gmsh::model::geo::addVolume({1, 2}, 1);


    gmsh::model::geo::synchronize();
    gmsh::model::mesh::generate(3);
    gmsh::write("tor.msh");
    std::set<std::string> args(argv, argv + argc);
    if (!args.count("-nopopup")) gmsh::fltk::run();
    gmsh::finalize();

    return 0;
}