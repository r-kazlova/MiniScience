#include <set>
#include <cmath>
#include <gmsh.h>

int main(int argc, char const *argv[]) {
    int n;
    gmsh::initialize();

    gmsh::model::add("Wing");

    try {
        gmsh::merge("C:\\Users\\Risha\\CLionProjects\\MiniScience\\Krylo6.stl");
    } catch (...) {
        gmsh::logger::write("Could not load STL mesh: bye!");
        gmsh::finalize();
        return 0;
    }


    double angle = 10;
    bool forceParametrizablePatches = false;
    bool includeBoundary = true;
    double curveAngle = 180;

    gmsh::model::mesh::classifySurfaces(angle * M_PI / 180., includeBoundary,
                                        forceParametrizablePatches,
                                        curveAngle * M_PI / 180.);

    gmsh::model::mesh::createGeometry();

    std::vector<std::pair<int, int> > s;
    gmsh::model::getEntities(s, 2);
    std::vector<int> sl;
    for (auto surf : s) sl.push_back(surf.second);
    //gmsh::model::mesh::recombine();
    int l = gmsh::model::geo::addSurfaceLoop(sl);
    gmsh::model::geo::addVolume({l});


    bool funny = true;
    int f = gmsh::model::mesh::field::add("MathEval");
    if (funny)
        gmsh::model::mesh::field::setString(f, "F", "5");//"x*x*x*x+1" - пример распределения
    else
        gmsh::model::mesh::field::setString(f, "F", "4");
    gmsh::model::mesh::field::setAsBackgroundMesh(f);
    gmsh::model::geo::synchronize();

    //n = 6;
    //for (int i = 2; i < n + 2; i++) {
    //gmsh::model::mesh::setTransfiniteSurface(i);
//}
    //сеточка прикольная треугольная
    //gmsh::model::mesh::setTransfiniteVolume(1);
    //gmsh::model::mesh::setTransfiniteAutomatic();//сетка квадрат-шмадрат


    //gmsh::model::mesh::setSmoothing(2,4,1);//вроде как уже построеную сетку пытается приблизить ещё лучше к stl,
    // но лучше это делать в окошке "mesh"
    gmsh::model::mesh::generate(3);



    std::set<std::string> args(argv, argv + argc);
    if(!args.count("-nopopup")) gmsh::fltk::run();

    gmsh::finalize();
    return 0;
}
