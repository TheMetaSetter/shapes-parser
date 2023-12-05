#include <fstream>
#include <iostream>

#include "Business/ParserFactory.hpp"
#include "Business/RectangleParser.hpp"
#include "Business/SquareParser.hpp"
#include "Business/CircleParser.hpp"
#include "Business/SortingShapesPerformer.hpp"
#include "Business/SortingShapesByAreaStrategy.hpp"

#include "Entity/IShape.hpp"

#include "UI/DisplayShapeStrategy.hpp"
#include "UI/ShapesDisplayer.hpp"

#include "Helper/Utils.hpp"

using std::fstream;
using std::cout, std::endl;

int main()
{
    ParserFactory parserFactory;
    parserFactory.registerWith(new RectangleParser());
    parserFactory.registerWith(new SquareParser());
    parserFactory.registerWith(new CircleParser());

    fstream fin("../Data/shapes.txt");

    vector<IShape*> shapes;
    string line;
    cout << line << endl;
    getline(fin, line);

    int numOfShapes = stoi(line);


    for (int i = 0; i < numOfShapes; i++)
    {
        getline(fin, line);

        // Square: a=12
        vector<string> tokens = Utils::String::split(line, ":");

        // Create parser
        IParsable* parser = parserFactory.create(tokens[0]);

        // Parse the data
        IShape* shape = dynamic_cast<IShape*>(parser->parse(tokens[1]));

        // Add the shape to the vector
        shapes.push_back(shape);
    }

    // Sort the shapes
    SortingShapesPerformer sortingShapesPerformer(new SortingShapesByAreaStrategy());
    sortingShapesPerformer.performSorting(shapes);
    
    // Display the shapes
    ShapesDisplayer shapesDisplayer(new DisplayShapeStrategy());

    shapesDisplayer.displayShapes(shapes);
}